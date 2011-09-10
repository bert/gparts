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

#include "schgui.h"


#define SCHGUI_CAIRO_ARC_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_CAIRO_ARC,SchGUICairoArcPrivate))

typedef struct _SchGUICairoArcPrivate SchGUICairoArcPrivate;

struct _SchGUICairoArcPrivate
{
    MiscGUIColor color;

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

            double radians0 = geom_angle_radians(privat->start);
            double radians1 = geom_angle_radians(privat->start + privat->sweep);

            double x0 = privat->center_x + privat->radius * cos(radians0);
            double y0 = privat->center_y + privat->radius * sin(radians0);

            double x1 = privat->center_x + privat->radius * cos(radians1);
            double y1 = privat->center_y + privat->radius * sin(radians1);

            double start;
            double end;

            if (x0 < x1)
            {
                temp.min_x = floor(x0);
                temp.max_x = ceil(x1);
            }
            else
            {
                temp.min_x = floor(x1);
                temp.max_x = ceil(x0);
            }

            if (y0 < y1)
            {
                temp.min_y = floor(y0);
                temp.max_y = ceil(y1);
            }
            else
            {
                temp.min_y = floor(y1);
                temp.max_y = ceil(y0);
            }

            if (privat->sweep >= 0)
            {
                start = geom_angle_normalize(geom_angle_degrees(privat->start));
                end = start + geom_angle_degrees(privat->sweep);
            }
            else
            {
                start = geom_angle_normalize(geom_angle_degrees(privat->start + privat->sweep));
                end = start - geom_angle_degrees(privat->sweep);
            }

            if (start < 90 && end > 90)
            {
                temp.max_y = ceil(privat->center_y + privat->radius);
            }

            if (start < 180 && end > 180)
            {
                temp.min_x = floor(privat->center_x - privat->radius);
            }

            if (start < 270 && end > 270)
            {
                temp.min_y = floor(privat->center_y - privat->radius);
            }

            if (start < 360 && end > 360)
            {
                temp.max_x = ceil(privat->center_x + privat->radius);
            }

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
            cairo_set_source_rgba(
                cairo,
                privat->color.red,
                privat->color.green,
                privat->color.blue,
                privat->color.alpha
                );

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
        GeomArc      arc;
        MiscGUIColor color;
        int          index;
        double       item_width;
        int          shape_width;

        index = sch_arc_get_color(shape);

        privat->visible = schgui_drawing_cfg_get_color(config, index, &color);

        privat->color.red   = color.red;
        privat->color.green = color.green;
        privat->color.blue  = color.blue;
        privat->color.alpha = privat->visible ? 1.0 : 0.0;

        shape_width = sch_arc_get_line_width(shape);

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

