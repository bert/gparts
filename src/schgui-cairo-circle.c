/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2010 Edward C. Hennessy
 * Copyright (C) 2010 gEDA Contributors (see ChangeLog for details)
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

/*! \file schgui-cairo-circle.c
 */

#include <math.h>

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
 
#include "sch.h"

#include "schgui-drawing-cfg.h"

#include "schgui-cairo-draw-item.h"

#include "schgui-cairo-circle.h"

#define SCHGUI_CAIRO_CIRCLE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_CAIRO_CIRCLE,SchGUICairoCirclePrivate))

typedef struct _SchGUICairoCirclePrivate SchGUICairoCirclePrivate;

struct _SchGUICairoCirclePrivate
{
    double red;
    double green;
    double blue;
    double alpha;

    double center_x;
    double center_y;
    double radius;

    double width;

    int    solid;
    int    visible;
};

static void
schgui_cairo_circle_bounds(SchGUICairoDrawItem *item, cairo_t *cairo, GeomBounds *bounds);

static void
schgui_cairo_circle_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_cairo_circle_draw(SchGUICairoDrawItem *item, cairo_t *cairo);

static void
schgui_cairo_circle_mirror_y(SchGUICairoDrawItem *item);

static void
schgui_cairo_circle_rotate(SchGUICairoDrawItem *item, double dt);

static void
schgui_cairo_circle_translate(SchGUICairoDrawItem *item, double dx, double dy);



static void
schgui_cairo_circle_bounds(SchGUICairoDrawItem *item, cairo_t *cairo, GeomBounds *bounds)
{
    if (bounds != NULL)
    {
        SchGUICairoCirclePrivate *privat = SCHGUI_CAIRO_CIRCLE_GET_PRIVATE(item);

        if (privat != NULL)
        {
            GeomBounds temp;

            temp.min_x = privat->center_x - privat->radius;
            temp.min_y = privat->center_y - privat->radius;
            temp.max_x = privat->center_x + privat->radius;
            temp.max_y = privat->center_y + privat->radius;

            geom_bounds_expand(&temp, &temp, privat->width);

            geom_bounds_union(bounds, bounds, &temp);
        }
    }

}

static void
schgui_cairo_circle_class_init(gpointer g_class, gpointer g_class_data)
{
    SchGUICairoDrawItemClass *klasse = SCHGUI_CAIRO_DRAW_ITEM_CLASS(g_class);

    g_type_class_add_private(G_OBJECT_CLASS(g_class), sizeof(SchGUICairoCirclePrivate));

    klasse->bounds    = schgui_cairo_circle_bounds;
    klasse->draw      = schgui_cairo_circle_draw;
    klasse->mirror_y  = schgui_cairo_circle_mirror_y;
    klasse->rotate    = schgui_cairo_circle_rotate;
    klasse->translate = schgui_cairo_circle_translate;
}

static void
schgui_cairo_circle_draw(SchGUICairoDrawItem *item, cairo_t *cairo)
{
    if (cairo != NULL)
    {
        SchGUICairoCirclePrivate *privat = SCHGUI_CAIRO_CIRCLE_GET_PRIVATE(item);

        if (privat != NULL)
        {
            cairo_set_source_rgba(cairo, privat->red, privat->green, privat->blue, privat->alpha);

            cairo_set_line_width(cairo, privat->width);

            cairo_new_sub_path(cairo);

            cairo_arc(cairo, privat->center_x, privat->center_y, privat->radius, 0, 2 * M_PI);

            if (privat->solid)
            {
                cairo_fill_preserve(cairo);
            }

            cairo_stroke(cairo);
        }
    }
}

GType
schgui_cairo_circle_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUICairoCircleClass),    /* class_size */
            NULL,                              /* base_init */
            NULL,                              /* base_finalize */
            schgui_cairo_circle_class_init,    /* class_init */
            NULL,                              /* class_finalize */
            NULL,                              /* class_data */
            sizeof(SchGUICairoCircle),         /* instance_size */
            0,                                 /* n_preallocs */
            NULL,                              /* instance_init */
            NULL                               /* value_table */
            };

        type = g_type_register_static(
            SCHGUI_TYPE_CAIRO_DRAW_ITEM,
            "SchGUICairoCircle",
            &tinfo,
            0
            );
    }

    return type;
}

static void
schgui_cairo_circle_mirror_y(SchGUICairoDrawItem *item)
{
    SchGUICairoCirclePrivate *privat = SCHGUI_CAIRO_CIRCLE_GET_PRIVATE(item);

    if (privat != NULL)
    {
        privat->center_x = -privat->center_x;
    }
}


SchGUICairoCircle*
schgui_cairo_circle_new(const SchCircle *shape, SchGUIDrawingCfg *config)
{
    SchGUICairoCircle *item = SCHGUI_CAIRO_CIRCLE(g_object_new(SCHGUI_TYPE_CAIRO_CIRCLE, NULL));

    SchGUICairoCirclePrivate *privat = SCHGUI_CAIRO_CIRCLE_GET_PRIVATE(item);

    if (privat != NULL)
    {
        GeomCircle            circle;
        SchGUIDrawingCfgColor color;
        SchFillStyle          fill_style;
        int                   index;
        double                item_width;
        int                   shape_width;

        sch_circle_get_color(shape, &index);

        privat->visible = schgui_drawing_cfg_get_color(config, index, &color);

        privat->red   = color.red;
        privat->green = color.green;
        privat->blue  = color.blue;
        privat->alpha = privat->visible ? 1.0 : 0.0;

        sch_circle_get_line_width(shape, &shape_width);

        schgui_drawing_cfg_get_output_line_width(config, shape_width, &item_width);

        privat->width = item_width;

        sch_circle_get_circle(shape, &circle);

        privat->center_x = circle.center_x;
        privat->center_y = circle.center_y;
        privat->radius   = circle.radius;

        sch_circle_get_fill_style(shape, &fill_style);

        privat->solid = (fill_style.type == SCH_FILL_STYLE_FILL_TYPE_SOLID);
    }

    return item;
}

static void
schgui_cairo_circle_rotate(SchGUICairoDrawItem *item, double dt)
{
    SchGUICairoCirclePrivate *privat = SCHGUI_CAIRO_CIRCLE_GET_PRIVATE(item);

    if (privat != NULL)
    {
        cairo_matrix_t transform;

        cairo_matrix_init_rotate(&transform, dt);

        cairo_matrix_transform_point(&transform, &(privat->center_x), &(privat->center_y));
    }
}

static void
schgui_cairo_circle_translate(SchGUICairoDrawItem *item, double dx, double dy)
{
    SchGUICairoCirclePrivate *privat = SCHGUI_CAIRO_CIRCLE_GET_PRIVATE(item);

    if (privat != NULL)
    {
        privat->center_x += dx;
        privat->center_y += dy;
    }
}

