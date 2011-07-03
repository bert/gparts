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

/*! \file geom-box.h
 */

#include <stdlib.h>
#include <string.h>

#include <glib-object.h>

#include "geom-angle.h"
#include "geom-bounds.h"
#include "geom-transform.h"

#include "geom-box.h"

void
geom_box_bounds(const GeomBox *box, GeomBounds *bounds)
{
    if ((box != NULL) && (bounds != NULL))
    {
        int other_x = box->corner_x + box->width;
        int other_y = box->corner_y + box->height;

        if (box->width < 0)
        {
            if (other_x < bounds->min_x)
            {
                bounds->min_x = other_x;
            }

            if (box->corner_x > bounds->max_x)
            {
                bounds->max_x = box->corner_x;
            }
        }
        else
        {
            if (box->corner_x < bounds->min_x)
            {
                bounds->min_x = box->corner_x;
            }

            if (other_x > bounds->max_x)
            {
                bounds->max_x = other_x;
            }
        }

        if (box->height < 0)
        {
            if (other_y < bounds->min_y)
            {
                bounds->min_y = other_y;
            }

            if (box->corner_y > bounds->max_y)
            {
                bounds->max_y = box->corner_y;
            }
        }
        else
        {
            if (box->corner_y < bounds->min_y)
            {
                bounds->min_y = box->corner_y;
            }

            if (other_y > bounds->max_y)
            {
                bounds->max_y = other_y;
            }
        }
    }
}

GeomBox*
geom_box_copy(const GeomBox *box)
{
    return GEOM_BOX(g_memdup(box, sizeof(GeomBox)));
}

GType
geom_box_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        type = g_boxed_type_register_static(
            "GeomBox",
            (GBoxedCopyFunc) geom_box_copy,
            (GBoxedFreeFunc) geom_box_free
            );
    }

    return type;
}

void
geom_box_free(GeomBox *box)
{
    g_free(box);
}


void
geom_box_init(GeomBox *box)
{
    memset(box, 0, sizeof(GeomBox));
}

void
geom_box_rotate(GeomBox *box, gint angle)
{
    if (box != NULL)
    {
        geom_angle_rotate_points(angle, &(box->corner_x), &(box->corner_y), 1);
        geom_angle_rotate_points(angle, &(box->width), &(box->height), 1);
    }
}

void
geom_box_transform(GeomBox *box, const GeomTransform *transform)
{
    if ((box != NULL) && (transform != NULL))
    {
        /*! \todo implement geom_box_transform */
    }
}

void
geom_box_translate(GeomBox *box, int dx, int dy)
{
    if (box != NULL)
    {
        box->corner_x += dx;
        box->corner_y += dy;
    }
}

