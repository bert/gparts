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

/*! \file schgui-cairo-arc.c
 */

#include <math.h>

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
 
#include "sch.h"

#include "schgui-drawing-cfg.h"

#include "schgui-cairo-draw-item.h"

#include "schgui-cairo-arc.h"

#define SCHGUI_CAIRO_ARC_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_CAIRO_ARC,SchGUICairoArcPrivate))

typedef struct _SchGUICairoArcPrivate SchGUICairoArcPrivate;

struct _SchGUICairoArcPrivate
{
    double red;
    double green;
    double blue;
    double alpha;

    double center_x;
    double center_y;
    double radius;

    double start;
    double sweep;

    double width;

    int    filled;
    int    visible;
};

static void
schgui_cairo_arc_bounds(SchGUICairoDrawItem *item, cairo_t *cairo, GeomBounds *bounds);

static void
schgui_cairo_arc_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_cairo_arc_draw(SchGUICairoDrawItem *item, cairo_t *cairo);

static void
schgui_cairo_arc_mirror_y(SchGUICairoDrawItem *item);

static void
schgui_cairo_arc_rotate(SchGUICairoDrawItem *item, double dt);

static void
schgui_cairo_arc_translate(SchGUICairoDrawItem *item, double dx, double dy);


/*! \todo Calculate proper arc bounds */
static void
schgui_cairo_arc_bounds(SchGUICairoDrawItem *item, cairo_t *cairo, GeomBounds *bounds)
{
    if (bounds != NULL)
    {
        SchGUICairoArcPrivate *privat = SCHGUI_CAIRO_ARC_GET_PRIVATE(item);

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
schgui_cairo_arc_class_init(gpointer g_class, gpointer g_class_data)
{
    SchGUICairoDrawItemClass *klasse = SCHGUI_CAIRO_DRAW_ITEM_CLASS(g_class);

    g_type_class_add_private(G_OBJECT_CLASS(g_class), sizeof(SchGUICairoArcPrivate));

    klasse->bounds    = schgui_cairo_arc_bounds;
    klasse->draw      = schgui_cairo_arc_draw;
    klasse->mirror_y  = schgui_cairo_arc_mirror_y;
    klasse->rotate    = schgui_cairo_arc_rotate;
    klasse->translate = schgui_cairo_arc_translate;
}

static void
schgui_cairo_arc_draw(SchGUICairoDrawItem *item, cairo_t *cairo)
{
    if (cairo != NULL)
    {
        SchGUICairoArcPrivate *privat = SCHGUI_CAIRO_ARC_GET_PRIVATE(item);

        if (privat != NULL)
        {
            cairo_set_source_rgba(cairo, privat->red, privat->green, privat->blue, privat->alpha);

            cairo_set_line_width(cairo, privat->width);

            cairo_new_sub_path(cairo);

            if (privat->sweep > 0)
            {
                cairo_arc(cairo, privat->center_x, privat->center_y, privat->radius, privat->start, privat->start + privat->sweep);
            }
            else
            {
                cairo_arc_negative(cairo, privat->center_x, privat->center_y, privat->radius, privat->start, privat->start + privat->sweep);
            }

            if (privat->filled)
            {
                cairo_fill_preserve(cairo);
            }

            cairo_stroke(cairo);
        }
    }
}

GType
schgui_cairo_arc_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUICairoArcClass),    /* class_size */
            NULL,                           /* base_init */
            NULL,                           /* base_finalize */
            schgui_cairo_arc_class_init,    /* class_init */
            NULL,                           /* class_finalize */
            NULL,                           /* class_data */
            sizeof(SchGUICairoArc),         /* instance_size */
            0,                              /* n_preallocs */
            NULL,                           /* instance_init */
            NULL                            /* value_table */
            };

        type = g_type_register_static(
            SCHGUI_TYPE_CAIRO_DRAW_ITEM,
            "SchGUICairoArc",
            &tinfo,
            0
            );
    }

    return type;
}

static void
schgui_cairo_arc_mirror_y(SchGUICairoDrawItem *item)
{
    SchGUICairoArcPrivate *privat = SCHGUI_CAIRO_ARC_GET_PRIVATE(item);

    if (privat != NULL)
    {
        privat->center_x = -privat->center_x;

        privat->start = privat->start + M_PI; 
    }
}


SchGUICairoArc*
schgui_cairo_arc_new(const SchArc *shape, SchGUIDrawingCfg *config)
{
    SchGUICairoArc *item = SCHGUI_CAIRO_ARC(g_object_new(SCHGUI_TYPE_CAIRO_ARC, NULL));

    SchGUICairoArcPrivate *privat = SCHGUI_CAIRO_ARC_GET_PRIVATE(item);

    if (privat != NULL)
    {
        GeomArc               arc;
        SchGUIDrawingCfgColor color;
        int                   index;
        double                item_width;
        int                   shape_width;

        sch_arc_get_color(shape, &index);

        privat->visible = schgui_drawing_cfg_get_color(config, index, &color);

        privat->red   = color.red;
        privat->green = color.green;
        privat->blue  = color.blue;
        privat->alpha = privat->visible ? 1.0 : 0.0;

        sch_arc_get_line_width(shape, &shape_width);

        schgui_drawing_cfg_get_output_line_width(config, shape_width, &item_width);

        privat->width = item_width;

        sch_arc_get_arc(shape, &arc);

        privat->center_x = arc.center_x;
        privat->center_y = arc.center_y;
        privat->radius   = arc.radius;
        privat->start    = geom_angle_radians(arc.start);
        privat->sweep    = geom_angle_radians(arc.sweep);
    }

    return item;
}

static void
schgui_cairo_arc_rotate(SchGUICairoDrawItem *item, double dt)
{
    SchGUICairoArcPrivate *privat = SCHGUI_CAIRO_ARC_GET_PRIVATE(item);

    if (privat != NULL)
    {
        cairo_matrix_t transform;

        cairo_matrix_init_rotate(&transform, dt);

        cairo_matrix_transform_point(&transform, &(privat->center_x), &(privat->center_y));

        privat->start += dt;
    }
}

static void
schgui_cairo_arc_translate(SchGUICairoDrawItem *item, double dx, double dy)
{
    SchGUICairoArcPrivate *privat = SCHGUI_CAIRO_ARC_GET_PRIVATE(item);

    if (privat != NULL)
    {
        privat->center_x += dx;
        privat->center_y += dy;
    }
}

