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

#include "geom-angle.h"
#include "geom-bounds.h"
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
        double     radians = geom_angle_radians(angle);
        GeomCircle temp = *circle;

        circle->center_x = round(temp.center_x * cos(radians) - temp.center_y * sin(radians));
        circle->center_y = round(temp.center_x * sin(radians) + temp.center_y * cos(radians));

        circle->center_x = round(temp.center_x * cos(radians) - temp.center_y * sin(radians));
        circle->center_y = round(temp.center_x * sin(radians) + temp.center_y * cos(radians));
    }
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

