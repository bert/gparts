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

#include <stdlib.h>

#include "geom-bounds.h"
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

void
geom_box_translate(GeomBox *box, int dx, int dy)
{
    if (box != NULL)
    {
        box->corner_x += dx;
        box->corner_y += dy;
    }
}

