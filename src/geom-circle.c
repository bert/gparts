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

/*! \file geom-circle.c
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <glib-object.h>

#include "geom-angle.h"
#include "geom-bounds.h"
#include "geom-transform.h"

#include "geom-circle.h"

/*! \brief Calculate the bounding rectangle of the given circle.
 *
 *  \param [in]  circle
 *  \param [out] bounds
 */
void
geom_circle_bounds(const GeomCircle *circle, GeomBounds *bounds)
{
    if (bounds != NULL)
    {
        if (circle != NULL)
        {
            bounds->min_x = circle->center_x - circle->radius;
            bounds->min_y = circle->center_y - circle->radius;
            bounds->max_x = circle->center_x + circle->radius;
            bounds->max_y = circle->center_y + circle->radius;
        }
        else
        {
            geom_bounds_init(bounds);
        }
    }
}

GeomCircle*
geom_circle_copy(const GeomCircle *circle)
{
    return GEOM_CIRCLE(g_memdup(circle, sizeof(GeomCircle)));
}

GType
geom_circle_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        type = g_boxed_type_register_static(
            "GeomCircle",
            (GBoxedCopyFunc) geom_circle_copy,
            (GBoxedFreeFunc) geom_circle_free
            );
    }

    return type;
}

void
geom_circle_free(GeomCircle *circle)
{
    g_free(circle);
}

void
geom_circle_init(GeomCircle *circle)
{
    memset(circle, 0, sizeof(GeomCircle));
}

void
geom_circle_rotate(GeomCircle *circle, int angle)
{
    if (circle != NULL)
    {
        geom_angle_rotate_points(angle, &(circle->center_x), &(circle->center_y), 1);
    }
}

void
geom_circle_transform(GeomCircle *circle, const GeomTransform *transform)
{
    /*! \todo implement geom_circle_transform */
}

void
geom_circle_translate(GeomCircle *circle, int dx, int dy)
{
    if (circle != NULL)
    {
        circle->center_x += dx;
        circle->center_y += dy;
    }
}

