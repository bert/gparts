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

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
 
#include "sch.h"

#include "schgui-cairo-draw-item.h"

void
schgui_cairo_draw_item_bounds(SchGUICairoDrawItem *item, cairo_t *cairo, GeomBounds *bounds)
{
    SchGUICairoDrawItemClass *klasse = SCHGUI_CAIRO_DRAW_ITEM_GET_CLASS(item);

    if ((klasse != NULL) && (klasse->draw != NULL))
    {
        klasse->bounds(item, cairo, bounds);
    }

}

void
schgui_cairo_draw_item_draw(SchGUICairoDrawItem *item, cairo_t *cairo)
{
    if (item != NULL)
    {
        SchGUICairoDrawItemClass *klasse = SCHGUI_CAIRO_DRAW_ITEM_GET_CLASS(item);

        if ((klasse != NULL) && (klasse->draw != NULL))
        {
            klasse->draw(item, cairo);
        }
    }
}

GType
schgui_cairo_draw_item_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUICairoDrawItemClass),    /* class_size */
            NULL,                                /* base_init */
            NULL,                                /* base_finalize */
            NULL,                                /* class_init */
            NULL,                                /* class_finalize */
            NULL,                                /* class_data */
            sizeof(SchGUICairoDrawItem),         /* instance_size */
            0,                                   /* n_preallocs */
            NULL,                                /* instance_init */
            NULL                                 /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchGUICairoDrawItem",
            &tinfo,
            G_TYPE_FLAG_ABSTRACT
            );
    }

    return type;
}

void
schgui_cairo_draw_item_rotate(SchGUICairoDrawItem *item, double dt)
{
    if (item != NULL)
    {
        SchGUICairoDrawItemClass *klasse = SCHGUI_CAIRO_DRAW_ITEM_GET_CLASS(item);

        if ((klasse != NULL) && (klasse->rotate != NULL))
        {
            klasse->rotate(item, dt);
        }
    }
}

void
schgui_cairo_draw_item_translate(SchGUICairoDrawItem *item, double dx, double dy)
{
    if (item != NULL)
    {
        SchGUICairoDrawItemClass *klasse = SCHGUI_CAIRO_DRAW_ITEM_GET_CLASS(item);

        if ((klasse != NULL) && (klasse->translate != NULL))
        {
            klasse->translate(item, dx, dy);
        }
    }
}

