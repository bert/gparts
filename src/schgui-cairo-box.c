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

/*! \file schgui-cairo-box.c
 */

#include <math.h>

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "schgui.h"


#define SCHGUI_CAIRO_BOX_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_CAIRO_BOX,SchGUICairoBoxPrivate))

typedef struct _SchGUICairoBoxPrivate SchGUICairoBoxPrivate;

struct _SchGUICairoBoxPrivate
{
    double red;
    double green;
    double blue;
    double alpha;

    double corner_x;
    double corner_y;
    double width;
    double height;

    double line_width;

    int    solid;
    int    visible;
};

static void
schgui_cairo_box_bounds(SchGUICairoDrawItem *item, cairo_t *cairo, GeomBounds *bounds);

static void
schgui_cairo_box_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_cairo_box_draw(SchGUICairoDrawItem *item, cairo_t *cairo);

static void
schgui_cairo_box_mirror_y(SchGUICairoDrawItem *item);

static void
schgui_cairo_box_rotate(SchGUICairoDrawItem *item, double dt);

static void
schgui_cairo_box_translate(SchGUICairoDrawItem *item, double dx, double dy);



static void
schgui_cairo_box_bounds(SchGUICairoDrawItem *item, cairo_t *cairo, GeomBounds *bounds)
{
    if (bounds != NULL)
    {
        SchGUICairoBoxPrivate *privat = SCHGUI_CAIRO_BOX_GET_PRIVATE(item);

        if (privat != NULL)
        {
            GeomBounds temp;

            temp.min_x = privat->corner_x;
            temp.min_y = privat->corner_y;
            temp.max_x = privat->corner_x + privat->width;
            temp.max_y = privat->corner_y + privat->height;

            geom_bounds_expand(&temp, &temp, privat->line_width);

            geom_bounds_union(bounds, bounds, &temp);
        }
    }
}

static void
schgui_cairo_box_class_init(gpointer g_class, gpointer g_class_data)
{
    SchGUICairoDrawItemClass *klasse = SCHGUI_CAIRO_DRAW_ITEM_CLASS(g_class);

    g_type_class_add_private(G_OBJECT_CLASS(g_class), sizeof(SchGUICairoBoxPrivate));

    klasse->bounds    = schgui_cairo_box_bounds;
    klasse->draw      = schgui_cairo_box_draw;
    klasse->mirror_y  = schgui_cairo_box_mirror_y;
    klasse->rotate    = schgui_cairo_box_rotate;
    klasse->translate = schgui_cairo_box_translate;
}

static void
schgui_cairo_box_draw(SchGUICairoDrawItem *item, cairo_t *cairo)
{
    if (cairo != NULL)
    {
        SchGUICairoBoxPrivate *privat = SCHGUI_CAIRO_BOX_GET_PRIVATE(item);

        if (privat != NULL)
        {
            cairo_set_source_rgba(cairo, privat->red, privat->green, privat->blue, privat->alpha);

            cairo_set_line_width(cairo, privat->line_width);

            cairo_move_to(cairo, privat->corner_x, privat->corner_y);
            cairo_line_to(cairo, privat->corner_x + privat->width, privat->corner_y);
            cairo_line_to(cairo, privat->corner_x + privat->width, privat->corner_y + privat->height);
            cairo_line_to(cairo, privat->corner_x, privat->corner_y + privat->height);

            cairo_close_path(cairo);

            if (privat->solid)
            {
                cairo_fill_preserve(cairo);
            }

            cairo_stroke(cairo);
        }
    }
}

static void
schgui_cairo_box_mirror_y(SchGUICairoDrawItem *item)
{
    SchGUICairoBoxPrivate *privat = SCHGUI_CAIRO_BOX_GET_PRIVATE(item);

    if (privat != NULL)
    {
        privat->corner_x = -privat->corner_x - privat->width;
    }
}


GType
schgui_cairo_box_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUICairoBoxClass),    /* class_size */
            NULL,                           /* base_init */
            NULL,                           /* base_finalize */
            schgui_cairo_box_class_init,    /* class_init */
            NULL,                           /* class_finalize */
            NULL,                           /* class_data */
            sizeof(SchGUICairoBox),         /* instance_size */
            0,                              /* n_preallocs */
            NULL,                           /* instance_init */
            NULL                            /* value_table */
            };

        type = g_type_register_static(
            SCHGUI_TYPE_CAIRO_DRAW_ITEM,
            "SchGUICairoBox",
            &tinfo,
            0
            );
    }

    return type;
}

SchGUICairoBox*
schgui_cairo_box_new(const SchBox *shape, SchGUIDrawingCfg *config)
{
    SchGUICairoBox *item = SCHGUI_CAIRO_BOX(g_object_new(SCHGUI_TYPE_CAIRO_BOX, NULL));

    SchGUICairoBoxPrivate *privat = SCHGUI_CAIRO_BOX_GET_PRIVATE(item);

    if (privat != NULL)
    {
        GeomBox       box;
        MiscGUIColor  color;
        SchFillStyle  fill_style;
        int           index;
        double        item_width;
        int           shape_width;

        index = sch_box_get_color(shape);

        privat->visible = schgui_drawing_cfg_get_color(config, index, &color);

        privat->red   = color.red;
        privat->green = color.green;
        privat->blue  = color.blue;
        privat->alpha = privat->visible ? 1.0 : 0.0;

        shape_width = sch_box_get_line_width(shape);

        schgui_drawing_cfg_get_output_line_width(config, shape_width, &item_width);

        privat->line_width = item_width;

        sch_box_get_box(shape, &box);

        privat->corner_x = box.corner_x;
        privat->corner_y = box.corner_y;
        privat->width    = box.width;
        privat->height   = box.height;

        //sch_box_get_fill_style(shape, &fill_style);

        privat->solid = (fill_style.type == SCH_FILL_STYLE_FILL_TYPE_SOLID);
    }

    return item;
}

static void
schgui_cairo_box_rotate(SchGUICairoDrawItem *item, double dt)
{
    SchGUICairoBoxPrivate *privat = SCHGUI_CAIRO_BOX_GET_PRIVATE(item);

    if (privat != NULL)
    {
        /* \todo Implement box rotation */
    }
}

static void
schgui_cairo_box_translate(SchGUICairoDrawItem *item, double dx, double dy)
{
    SchGUICairoBoxPrivate *privat = SCHGUI_CAIRO_BOX_GET_PRIVATE(item);

    if (privat != NULL)
    {
        privat->corner_x += dx;
        privat->corner_y += dy;
    }
}

