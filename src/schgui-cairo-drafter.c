/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2009 Edward C. Hennessy
 * Copyright (C) 2009 gEDA Contributors (see ChangeLog for details)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA
 */

/*! \file schgui-cairo-drafter.c
 */

#include <math.h>
#include <glib-object.h>
#include <gtk/gtk.h>
 
#include "sch.h"

#include "misc-object.h"

#include "schgui-drawing-cfg.h"
#include "schgui-cairo-drafter.h"

#define SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_CAIRO_DRAFTER,SchGUICairoDrafterPrivate))

enum
{
    SCHGUI_CAIRO_DRAFTER_CONFIG = 1,
    SCHGUI_CAIRO_DRAFTER_DRAWING
};

typedef struct _SchGUICairoDrafterPrivate SchGUICairoDrafterPrivate;

struct _SchGUICairoDrafterPrivate
{
    cairo_t *cairo;

    double zoom;
    double tx;
    double ty;

    PangoFontDescription *desc;

    SchGUIDrawingCfg *config;
    SchDrawing       *drawing;
};

static void
schgui_cairo_drafter_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_cairo_drafter_drafter_init(gpointer g_iface, gpointer g_iface_data);

static void
schgui_cairo_drafter_init(GTypeInstance* instance, gpointer g_class);


static int
schgui_cairo_drafter_component_bounds(SchGUICairoDrafter *drafter, SchComponent *shape, GeomBounds *bounds);

static void
schgui_cairo_drafter_dispose(GObject *object);

static void
schgui_cairo_drafter_draw_arc(SchGUICairoDrafter *drafter, const struct _SchArc *shape);


static void
schgui_cairo_drafter_draw_box(SchGUICairoDrafter *drafter, const struct _SchBox *shape);

static void
schgui_cairo_drafter_draw_bus(SchGUICairoDrafter *drafter, const struct _SchBus *shape);

static void
schgui_cairo_drafter_draw_circle(SchGUICairoDrafter *drafter, const struct _SchCircle *shape);

static void
schgui_cairo_drafter_draw_component(SchGUICairoDrafter *drafter, const struct _SchComponent *shape);

static void
schgui_cairo_drafter_draw_line(SchGUICairoDrafter *drafter, const struct _SchLine *shape);

static void
schgui_cairo_drafter_draw_net(SchGUICairoDrafter *drafter, const struct _SchNet *shape);

static void
schgui_cairo_drafter_draw_pin(SchGUICairoDrafter *drafter, const struct _SchPin *shape);

static void
schgui_cairo_drafter_draw_text(SchGUICairoDrafter *drafter, const struct _SchText *shape);

static void
schgui_cairo_drafter_finalize(GObject *object);

static void
schgui_cairo_drafter_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
schgui_cairo_drafter_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);


static void
schgui_cairo_drafter_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(SchGUICairoDrafterPrivate));

    klasse->dispose  = schgui_cairo_drafter_dispose;
    klasse->finalize = schgui_cairo_drafter_finalize;

    klasse->get_property = schgui_cairo_drafter_get_property;
    klasse->set_property = schgui_cairo_drafter_set_property;

    g_object_class_install_property(
        klasse,
        SCHGUI_CAIRO_DRAFTER_CONFIG,
        g_param_spec_object(
            "config",
            "Configuration",
            "Configuration",
            SCHGUI_TYPE_DRAWING_CFG,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCHGUI_CAIRO_DRAFTER_DRAWING,
        g_param_spec_object(
            "drawing",
            "Drawing",
            "Drawing",
            SCH_TYPE_DRAWING,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
schgui_cairo_drafter_drafter_init(gpointer g_iface, gpointer g_iface_data)
{
    SchDrafterInterface *iface = (SchDrafterInterface*) g_iface;

    iface->draw_arc       = schgui_cairo_drafter_draw_arc;
    iface->draw_box       = schgui_cairo_drafter_draw_box;
    iface->draw_bus       = schgui_cairo_drafter_draw_bus;  
    iface->draw_circle    = schgui_cairo_drafter_draw_circle;
    iface->draw_component = schgui_cairo_drafter_draw_component;
    iface->draw_line      = schgui_cairo_drafter_draw_line;
    iface->draw_net       = schgui_cairo_drafter_draw_net; 
    iface->draw_pin       = schgui_cairo_drafter_draw_pin; 
    iface->draw_text      = schgui_cairo_drafter_draw_text;

    iface->component_bounds = schgui_cairo_drafter_component_bounds;
    iface->text_bounds      = schgui_cairo_drafter_text_bounds;
}

static int
schgui_cairo_drafter_component_bounds(SchGUICairoDrafter *drafter, SchComponent *shape, GeomBounds *bounds)
{
    int        angle;
    SchDrawing *drawing;
    int        mirror;
    int        x;
    int        y;

    sch_component_get_drawing(shape, &drawing);
    sch_drawing_bounds(drawing, drafter, bounds);

    sch_component_get_orientation(shape, &angle, &mirror);

    if (mirror)
    {
        GeomBounds temp = *bounds;

        bounds->min_x = -temp.max_x;
        bounds->max_x = -temp.min_x;
    }

    if (angle == 90 || angle == 270)
    {
        GeomBounds temp = *bounds;

        bounds->min_y = -temp.max_y;
        bounds->max_y = -temp.min_y;
    }


    sch_component_get_insertion_point(shape, &x, &y);
    geom_bounds_translate(bounds, x, y);
}

static void
schgui_cairo_drafter_dispose(GObject *object)
{
    schgui_cairo_drafter_set_config(object, NULL);
    schgui_cairo_drafter_set_drawing(object, NULL);

    misc_object_chain_dispose(object);
}

static void
schgui_cairo_drafter_draw_arc(SchGUICairoDrafter *drafter, const struct _SchArc *shape)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL) && (shape != NULL))
    {
        GeomArc arc;
        int     index;
        int     shape_width;
        double  output_width;
        int     enabled;
        SchGUIDrawingCfgColor color;

        sch_arc_get_color(shape, &index);

        enabled = schgui_drawing_cfg_get_color(privat->config, index, &color);

        if (enabled)
        {
            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);

            sch_arc_get_line_width(shape, &shape_width);
            schgui_drawing_cfg_get_output_line_width(privat->config, shape_width, &output_width);
            cairo_set_line_width(privat->cairo, output_width);

            sch_arc_get_arc(shape, &arc);

            cairo_new_sub_path(privat->cairo);

            if (arc.sweep >= 0)
            {
                cairo_arc(privat->cairo, arc.center_x, arc.center_y, arc.radius, M_PI*arc.start/180, M_PI*(arc.start+arc.sweep)/180);
            }
            else
            {
                cairo_arc_negative(privat->cairo, arc.center_x, arc.center_y, arc.radius, M_PI*arc.start/180, M_PI*(arc.start+arc.sweep)/180);
            }

            cairo_stroke(privat->cairo);
        }
    }
}

static void
schgui_cairo_drafter_draw_box(SchGUICairoDrafter *drafter, const struct _SchBox *shape)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL) && (shape != NULL))
    {
        GeomBox      box;
        int          index;
        int          shape_width;
        double       output_width;
        SchLineStyle line_style;
        SchFillStyle fill_style;
        SchGUIDrawingCfgColor color;
        int          enabled;

        sch_box_get_color(shape, &index);

        enabled = schgui_drawing_cfg_get_color(privat->config, index, &color);

        if (enabled)
        {
            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);

            sch_box_get_fill_style(shape, &fill_style);

            sch_box_get_line_width(shape, &shape_width);
            schgui_drawing_cfg_get_output_line_width(privat->config, shape_width, &output_width);
            cairo_set_line_width(privat->cairo, output_width);

            sch_box_get_box(shape, &box);

            cairo_move_to(privat->cairo, box.corner_x, box.corner_y);
            cairo_line_to(privat->cairo, box.corner_x + box.width, box.corner_y);
            cairo_line_to(privat->cairo, box.corner_x + box.width, box.corner_y + box.height);
            cairo_line_to(privat->cairo, box.corner_x, box.corner_y + box.height);
            cairo_close_path(privat->cairo);

            if (fill_style.type == SCH_FILL_STYLE_FILL_TYPE_SOLID)
            {
                cairo_fill_preserve(privat->cairo);
            }

            cairo_stroke(privat->cairo);
        }
    }
}

static void
schgui_cairo_drafter_draw_bus(SchGUICairoDrafter *drafter, const struct _SchBus *shape)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL) && (shape != NULL))
    {
        GeomLine line;
        double   width;
        SchGUIDrawingCfgColor color;
        int          enabled;

        enabled = schgui_drawing_cfg_get_color(privat->config, 10, &color);

        if (enabled)
        {
            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);

            schgui_drawing_cfg_get_bus_line_width(privat->config, &width);
            cairo_set_line_width(privat->cairo, width);

            sch_bus_get_line(shape, &line);

            cairo_move_to(privat->cairo, line.x[0], line.y[0]);
            cairo_line_to(privat->cairo, line.x[1], line.y[1]);
            cairo_stroke(privat->cairo);
        }
    }
}

static void
schgui_cairo_drafter_draw_circle(SchGUICairoDrafter *drafter, const struct _SchCircle *shape)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL) && (shape != NULL))
    {
        GeomCircle   circle;
        SchFillStyle fill_style;
        int          index;
        double       output_width;
        int          shape_width;
        SchGUIDrawingCfgColor color;
        int          enabled;

        sch_circle_get_color(shape, &index);

        enabled = schgui_drawing_cfg_get_color(privat->config, index, &color);

        if (enabled)
        {
            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);

            sch_circle_get_fill_style(shape, &fill_style);

            sch_circle_get_line_width(shape, &shape_width);
            schgui_drawing_cfg_get_output_line_width(privat->config, shape_width, &output_width);
            cairo_set_line_width(privat->cairo, output_width);

            sch_circle_get_circle(shape, &circle);

            cairo_new_sub_path(privat->cairo);
            cairo_arc(privat->cairo, circle.center_x, circle.center_y, circle.radius, 0, 2 * M_PI);

            if (fill_style.type == SCH_FILL_STYLE_FILL_TYPE_SOLID)
            {
                cairo_fill_preserve(privat->cairo);
            }

            cairo_stroke(privat->cairo);
        }
    }
}

static void
schgui_cairo_drafter_draw_component(SchGUICairoDrafter *drafter, const struct _SchComponent *shape)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL) && (shape != NULL))
    {
        SchDrawing *drawing;

        sch_component_get_drawing(shape, &drawing);

        if (drawing != NULL)
        {
            int angle;
            int mirror;
            int x;
            int y;

            GeomBounds bounds;

            schgui_cairo_drafter_component_bounds(drafter, shape, &bounds);

            cairo_set_source_rgb(privat->cairo, 1.0, 1.0, 0.0);
            cairo_move_to(privat->cairo, bounds.min_x, bounds.min_y);
            cairo_line_to(privat->cairo, bounds.max_x, bounds.min_y);
            cairo_line_to(privat->cairo, bounds.max_x, bounds.max_y);
            cairo_line_to(privat->cairo, bounds.min_x, bounds.max_y);
            cairo_close_path(privat->cairo);
            cairo_stroke(privat->cairo);
            


            cairo_save(privat->cairo);


            sch_component_get_insertion_point(shape, &x, &y);
            cairo_translate(privat->cairo, x, y);

            sch_component_get_orientation(shape, &angle, &mirror);
            cairo_rotate(privat->cairo, angle * M_PI / 180);
            if (mirror)
            {
                cairo_scale(privat->cairo, -1, 1);
            }

            sch_drawing_draw(drawing, drafter);

            cairo_restore(privat->cairo);
        }
    }
}
 
void
schgui_cairo_drafter_draw_grid(SchGUICairoDrafter *drafter)
{
#if 0
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL))
    {
        int      index;
        int      x;
        int      y;
        SchGUIDrawingCfgColor color;
        int          enabled;

        enabled = schgui_drawing_cfg_get_color(privat->config, 22, &color);

        if (enabled)
        {
            cairo_save(privat->cairo);

            cairo_translate(privat->cairo, 0.5, 0.5);

            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);

            cairo_set_line_width(privat->cairo, 3/privat->zoom);
    
            for (x=0; x<17000; x+=100)
            {
                cairo_move_to(privat->cairo, x, 0);
                cairo_line_to(privat->cairo, x, 17000);
                cairo_stroke(privat->cairo);
            }    

            for (y=0; y<17000; y+=100)
            {
                cairo_move_to(privat->cairo, 0, y);
                cairo_line_to(privat->cairo, 17000, y);
                cairo_stroke(privat->cairo);
            }    

            cairo_restore(privat->cairo);
        }
    }
#endif
}

static void
schgui_cairo_drafter_draw_line(SchGUICairoDrafter *drafter, const struct _SchLine *shape)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL) && (shape != NULL))
    {
        int      index;
        GeomLine line;
        int     shape_width;
        double  output_width;
        SchGUIDrawingCfgColor color;
        int          enabled;

        sch_line_get_color(shape, &index);

        enabled = schgui_drawing_cfg_get_color(privat->config, index, &color);

        if (enabled)
        {
            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);

            sch_line_get_line_width(shape, &shape_width);
            schgui_drawing_cfg_get_output_line_width(privat->config, shape_width, &output_width);
            cairo_set_line_width(privat->cairo, output_width);

            sch_line_get_line(shape, &line);

            cairo_move_to(privat->cairo, line.x[0], line.y[0]);
            cairo_line_to(privat->cairo, line.x[1], line.y[1]);
            cairo_stroke(privat->cairo);
        }
    }
}

static void
schgui_cairo_drafter_draw_net(SchGUICairoDrafter *drafter, const struct _SchNet *shape)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL) && (shape != NULL))
    {
        SchGUIDrawingCfgColor color;
        int                   enabled;
        GeomLine line;
        double   width;

        enabled = schgui_drawing_cfg_get_color(privat->config, 4, &color);

        if (enabled)
        {
            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);

            schgui_drawing_cfg_get_net_line_width(privat->config, &width);
            cairo_set_line_width(privat->cairo, width);

            sch_net_get_line(shape, &line);

            cairo_move_to(privat->cairo, line.x[0], line.y[0]);
            cairo_line_to(privat->cairo, line.x[1], line.y[1]);
            cairo_stroke(privat->cairo);
        }
    }
}

static void
schgui_cairo_drafter_draw_pin(SchGUICairoDrafter *drafter, const struct _SchPin *shape)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL) && (shape != NULL))
    {
        SchGUIDrawingCfgColor color;
        int                   enabled;
        GeomLine              line;
        double                width;

        enabled = schgui_drawing_cfg_get_color(privat->config, 1, &color);

        if (enabled)
        {
            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);

            schgui_drawing_cfg_get_pin_line_width(privat->config, &width);
            cairo_set_line_width(privat->cairo, width);

            sch_pin_get_line(shape, &line);

            cairo_move_to(privat->cairo, line.x[0], line.y[0]);
            cairo_line_to(privat->cairo, line.x[1], line.y[1]);
            cairo_stroke(privat->cairo);
        }
    }
}


#if 1
# define FONT_NAME "Arial"
#else
# define FONT_NAME "Helvetica"
#endif

int
schgui_cairo_drafter_text_bounds(SchGUICairoDrafter *drafter, SchText *text, GeomBounds *bounds)
{
#if 0
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat->cairo != NULL)
    {
        PangoLayout *layout;
        SchMultiline *multiline = sch_text_get_multiline(text);
        PangoRectangle ink_rect, logical_rect;

        int point_size = sch_text_get_size(text);
        float height;

        cairo_save(privat->cairo);
        

        height = point_size * 1000 / 72;

        layout = pango_cairo_create_layout(privat->cairo);
        pango_cairo_context_set_resolution(pango_layout_get_context(layout), 1000);

        g_debug("Zoom: %f", privat->zoom);
        pango_font_description_set_size(privat->desc, point_size * PANGO_SCALE);
        g_debug("Font size: %d", pango_font_description_get_size(privat->desc) / PANGO_SCALE);
        
        pango_layout_set_font_description(layout, privat->desc);

        pango_layout_set_markup(layout, sch_multiline_peek_markup(multiline), -1);

        cairo_scale(privat->cairo, 1, -2);

        pango_layout_get_extents(layout, &ink_rect, &logical_rect);

        //g_debug("X       %d", ink_rect.x / PANGO_SCALE);
        //g_debug("Y       %d", ink_rect.y / PANGO_SCALE);
        //g_debug("Width   %d", ink_rect.width / PANGO_SCALE);
        //g_debug("Height  %d", ink_rect.height / PANGO_SCALE);


     PangoFontMetrics *metrics = pango_context_get_metrics(
            pango_layout_get_context(layout),
            privat->desc,
            NULL
            );


        bounds->min_x = sch_text_get_x(text) + ink_rect.x / PANGO_SCALE;
        bounds->min_y = sch_text_get_y(text) - (ink_rect.y + ink_rect.height) / PANGO_SCALE;
        bounds->max_x = sch_text_get_x(text) + (ink_rect.x + ink_rect.width) / PANGO_SCALE;
        bounds->max_y = sch_text_get_y(text) - ink_rect.y / PANGO_SCALE;

        bounds->min_y += pango_font_metrics_get_ascent(metrics)/(privat->zoom * PANGO_SCALE);
        bounds->max_y += pango_font_metrics_get_ascent(metrics)/(privat->zoom * PANGO_SCALE);

        pango_font_metrics_unref(metrics);

        cairo_restore(privat->cairo);

        g_object_unref(layout);

        return TRUE;
    }
#endif


    geom_bounds_init(bounds);

    return FALSE; 


}


#if 0
static void
schgui_cairo_drafter_draw_pin(SchGUICairoDrafter *drafter, const struct _SchPin *shape)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL) && (shape != NULL))
    {
        GeomLine line;

        cairo_set_line_width(privat->cairo, 10);  /* FIXME make pin width configurable */

        sch_pin_get_line(shape, &line);

        cairo_move_to(privat->cairo, line.x[0], line.y[0]);
        cairo_line_to(privat->cairo, line.x[1], line.y[1]);
        cairo_stroke(privat->cairo);
    }
}
#endif


static void
schgui_cairo_drafter_draw_text(SchGUICairoDrafter *drafter, const struct _SchText *text)
{
    if (text != NULL)
    {
        int visible;

        sch_text_get_visible(text, &visible);

        if (visible)
        {

    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat->cairo != NULL)
    {
        PangoLayout *layout;
        SchMultiline *multiline = sch_text_get_multiline(text);
        int point_size = sch_text_get_size(text);
        float height;
        int alignment;
        cairo_font_options_t *options;
        PangoContext *context;
        int baseline;
        PangoLayoutIter *iter;
        int index;
        int show;
        SchGUIDrawingCfgColor color;
        int          enabled;

        sch_text_get_color(text, &index);

        enabled = schgui_drawing_cfg_get_color(privat->config, index, &color);

        if (enabled)
        {
            if (0) /* show ink rect */
            {
                GeomBounds bounds;
                int        success;

                success = schgui_cairo_drafter_text_bounds(drafter, text, &bounds);

                if (success)
                {
                    cairo_set_source_rgb(privat->cairo, 1.0, 0, 0);
                
                    cairo_move_to(privat->cairo, bounds.min_x, bounds.min_y);
                    cairo_line_to(privat->cairo, bounds.max_x, bounds.min_y);
                
                    cairo_stroke(privat->cairo);

                    cairo_set_source_rgb(privat->cairo, 0.75, 0, 0);
                
                    cairo_move_to(privat->cairo, bounds.max_x, bounds.min_y);
                    cairo_line_to(privat->cairo, bounds.max_x, bounds.max_y);
                    cairo_line_to(privat->cairo, bounds.min_x, bounds.max_y);
                    cairo_line_to(privat->cairo, bounds.min_x, bounds.min_y);
                    //cairo_close_path(privat->cairo);

                    cairo_stroke(privat->cairo);
                
                    cairo_set_source_rgb(privat->cairo, 0, 0, 0);
                }

                cairo_set_source_rgb(privat->cairo, 0, 0, 1.0);
                cairo_new_sub_path(privat->cairo);
                cairo_arc(privat->cairo, sch_text_get_x(text), sch_text_get_y(text), 10, 0, 2 * M_PI);
                cairo_stroke(privat->cairo);
                cairo_set_source_rgb(privat->cairo, 0, 0, 0);
            }

            cairo_save(privat->cairo);
   
            height = 1000 * point_size / 72;

            layout = pango_cairo_create_layout(privat->cairo);
            pango_cairo_context_set_resolution(pango_layout_get_context(layout), 936);

//  context = pango_layout_get_context(layout);
//  options = cairo_font_options_create ();
//  cairo_font_options_set_hint_metrics (options, CAIRO_HINT_METRICS_OFF);
//  cairo_font_options_set_hint_style (options, CAIRO_HINT_STYLE_MEDIUM);
//  pango_cairo_context_set_font_options (context, options);
//  cairo_font_options_destroy (options);


            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);


            pango_font_description_set_size(privat->desc, point_size * PANGO_SCALE );
            pango_layout_set_spacing(layout, 40000);
        
            pango_layout_set_font_description(layout, privat->desc);

            sch_text_get_show(text, &show);
            pango_layout_set_markup(layout, sch_multiline_peek_markup(multiline, show), -1);


            PangoFontMetrics *metrics = pango_context_get_metrics(
                pango_layout_get_context(layout),
                privat->desc,
                NULL
                );

        
            cairo_move_to(privat->cairo, sch_text_get_x(text), sch_text_get_y(text));
        
            cairo_rotate(privat->cairo, M_PI * sch_text_get_angle(text) / 180);

            cairo_scale(privat->cairo, 1, -1);

            baseline = pango_layout_get_baseline(layout); 

            alignment = sch_text_get_alignment(text);
#if 1
            switch (alignment)
            {
                case 2:
                case 5:
                case 8: 
                /* upper */
                //cairo_rel_move_to(privat->cairo, 0, -pango_font_metrics_get_ascent(metrics)/(privat->zoom * PANGO_SCALE));
                //cairo_rel_move_to(privat->cairo, 0, height);
                break;

                case 1:
                case 4:
                case 7:
                    /* center */
                    cairo_rel_move_to(privat->cairo, 0, -pango_font_metrics_get_ascent(metrics)/(privat->zoom * PANGO_SCALE));
                    cairo_rel_move_to(privat->cairo, 0, height);
                    cairo_rel_move_to(privat->cairo, 0, -pango_font_metrics_get_ascent(metrics) * sch_multiline_lines(multiline)/(2 * privat->zoom * PANGO_SCALE));
                    cairo_rel_move_to(privat->cairo, 0, -pango_font_metrics_get_descent(metrics) * (sch_multiline_lines(multiline) - 1)/(2 * privat->zoom * PANGO_SCALE));
                    break;

                case 0:
                case 3:
                case 6:
                default:
                    /* lower */
                    //cairo_rel_move_to(privat->cairo, 0, -pango_font_metrics_get_ascent(metrics) * sch_multiline_lines(multiline)/(privat->zoom * PANGO_SCALE));
                    //cairo_rel_move_to(privat->cairo, 0, -pango_font_metrics_get_descent(metrics) * (sch_multiline_lines(multiline)-1)/(privat->zoom * PANGO_SCALE));
                    //cairo_rel_move_to(privat->cairo, 0, -pango_layout_get_spacing(layout) * (sch_multiline_lines(multiline)-1)/ PANGO_SCALE);
                    iter = pango_layout_get_iter(layout);
                    while (!pango_layout_iter_at_last_line(iter))
                    {
                        pango_layout_iter_next_line(iter);
                    }
                    cairo_rel_move_to(privat->cairo, 0, -pango_layout_iter_get_baseline(iter) / PANGO_SCALE);
                    pango_layout_iter_free(iter);
            }
#endif

            //g_debug("Ascent:    %d", pango_font_metrics_get_ascent(metrics));
            //g_debug("Descent:   %d", pango_font_metrics_get_descent(metrics));
            //g_debug("Spacing:   %d", pango_layout_get_spacing(layout));
            //g_debug("Font size: %d", pango_font_description_get_size(privat->desc));
            //g_debug("Baseline   %d", pango_layout_get_baseline(layout));            

            pango_font_metrics_unref(metrics);

            pango_cairo_show_layout(privat->cairo, layout);

            cairo_restore(privat->cairo);

            g_object_unref(layout);
        }
    }
}
}
 
}

void
schgui_cairo_drafter_draw_to_widget(SchGUICairoDrafter *drafter, GtkWidget *widget)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        //schgui_cairo_drafter_set_zoom(drafter,1 );
        //schgui_cairo_drafter_set_translate(drafter, 0, 0);

        //schgui_cairo_drafter_set_zoom(drafter, privat->zoom);
        //schgui_cairo_drafter_set_translate(privat->drafter, privat->tx, privat->ty);

        privat->cairo = gdk_cairo_create(widget->window);
        // cairo_scale(privat->cairo, privat->zoom, -privat->zoom);
        cairo_identity_matrix(privat->cairo);
        //cairo_translate(privat->cairo, 0, 480);
        cairo_scale(privat->cairo, 1, -1);
        cairo_translate(privat->cairo, privat->tx, privat->ty);
        cairo_scale(privat->cairo, privat->zoom, privat->zoom);
        cairo_set_line_width(privat->cairo, 20);

            //    schgui_cairo_drafter_draw_grid(privat->drafter);

        sch_drawing_draw(privat->drawing, SCH_DRAFTER(drafter));
        
        cairo_destroy(privat->cairo);
        privat->cairo = NULL;
    }
}

static void
schgui_cairo_drafter_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

static void
schgui_cairo_drafter_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCHGUI_CAIRO_DRAFTER_CONFIG:
                g_value_set_object(value, privat->config);
                break;

            case SCHGUI_CAIRO_DRAFTER_DRAWING:
                g_value_set_object(value, privat->drawing);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}


GType
schgui_cairo_drafter_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUICairoDrafterClass),      /* class_size */
            NULL,                                 /* base_init */
            NULL,                                 /* base_finalize */
            schgui_cairo_drafter_class_init,      /* class_init */
            NULL,                                 /* class_finalize */
            NULL,                                 /* class_data */
            sizeof(SchGUICairoDrafter),           /* instance_size */
            0,                                    /* n_preallocs */
            schgui_cairo_drafter_init,            /* instance_init */
            NULL                                  /* value_table */
            };

        static const GInterfaceInfo iinfob = {
            NULL,                                 /* interface_init */
            NULL,                                 /* interface_finalize */
            NULL                                  /* interface_data */
            };

        static const GInterfaceInfo iinfod = {
            schgui_cairo_drafter_drafter_init,    /* interface_init */
            NULL,                                 /* interface_finalize */
            NULL                                  /* interface_data */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchGUICairoDrafter",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GTK_TYPE_BUILDABLE, &iinfob);
        g_type_add_interface_static(type, SCH_TYPE_DRAFTER, &iinfod);
    }

    return type;
}

void
schgui_cairo_drafter_set_zoom(SchGUICairoDrafter *drafter, double zoom)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        privat->zoom = zoom;
    }
}
void
schgui_cairo_drafter_set_translate(SchGUICairoDrafter *drafter, double tx, double ty)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        privat->tx = tx;
        privat->ty = ty;
    }
}

static void
schgui_cairo_drafter_init(GTypeInstance* instance, gpointer g_class)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->desc = pango_font_description_from_string("Sans");
    }
}

void
schgui_cairo_drafter_set_config(SchGUICairoDrafter *drafter, SchGUIDrawingCfg *config)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        if (privat->config != NULL)
        {
            /* \todo unregister signals to update */

            g_object_unref(privat->config);
        }

        privat->config = config;

        if (privat->config != NULL)
        {
            g_object_ref(privat->config);

            /* \todo register signals to update */
        }
    }
}

void
schgui_cairo_drafter_set_drawing(SchGUICairoDrafter *drafter, SchDrawing *drawing)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        if (privat->drawing != NULL)
        {
            /* \todo unregister signals to update */

            g_object_unref(privat->drawing);
        }

        privat->drawing = drawing;

        if (privat->drawing != NULL)
        {
            g_object_ref(privat->drawing);

            /* \todo register signals to update */
        }
    }
}

static void
schgui_cairo_drafter_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    switch (property_id)
    {
        case SCHGUI_CAIRO_DRAFTER_CONFIG:
            schgui_cairo_drafter_set_config(SCHGUI_CAIRO_DRAFTER(object), g_value_get_object(value));
            break;

        case SCHGUI_CAIRO_DRAFTER_DRAWING:
            schgui_cairo_drafter_set_drawing(SCHGUI_CAIRO_DRAFTER(object), g_value_get_object(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
schgui_cairo_drafter_zoom_extents(SchGUICairoDrafter *drafter, GtkWidget *widget)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        if (privat->drawing != NULL)
        {
            GeomBounds bounds;
            int w;
            int h;
            double zx;
            double zy;

           // schgui_cairo_drafter_begin_drawing(privat->drafter, widget);

            sch_drawing_bounds(privat->drawing, drafter, &bounds);

            g_debug("Min X = %d", bounds.min_x);
            g_debug("Min Y = %d", bounds.min_y);
            g_debug("Max X = %d", bounds.max_x);
            g_debug("Max Y = %d", bounds.max_y);

           // schgui_cairo_drafter_end_drawing(privat->drafter);

            gdk_drawable_get_size(gtk_widget_get_window(widget), &w, &h);

            zx = 0.9 * (double)w / (bounds.max_x - bounds.min_x);
            zy = 0.9 * (double)h / (bounds.max_y - bounds.min_y);

            if (zx < zy)
            {
                privat->zoom = zx;
            }
            else
            {
                privat->zoom = zy;
            }

            {
                double m;
                int    exp;
                int    numerator;

                m = frexp(10/privat->zoom, &exp);

                                   // {
                    //    m = 0.1;
                   // }
                   // else if (m < 0.5)
                   // {
                   //     m = 0.2;
                   // }
                   // else if (m < 1.0)
                   // {
                   //     m = 0.5;
                   // }
                   // else
                   // {
                   //     m = 1.0;
                   // }

                if (m > 0.5)
                {
                    m = 1.0;
                }
                else if (m > 0.2)
                {
                    m = 0.5;
                }
                else if (m > 0.1)
                {
                    m = 0.2;
                }
                else 
                {
                        m = 0.1;
                }
                numerator = privat->zoom * ldexp(m, exp);

                privat->zoom = numerator / ldexp(m, exp);
            }

            privat->tx = (w - privat->zoom * (bounds.max_x)) / 2   - (privat->zoom * bounds.min_x) / 2;
            privat->ty =  - h - ((privat->zoom * (bounds.max_y + bounds.min_y) ) - h ) / 2;
        }
    }
}

