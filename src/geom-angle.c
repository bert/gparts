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

/*! \file geom-angle.c
 */

#include <math.h>
#include <stdlib.h>

#include <glib.h>

gint
geom_angle_degrees(gdouble angle)
{
    return 180.0 * angle / M_PI;
}

gint
geom_angle_normalize(gint angle)
{
   if (angle < 0)
   {
       angle = 360 - (-angle % 360);
   }
   else if (angle >= 360)
   {
       angle %= 360;
   }

   return angle;
}

gdouble
geom_angle_radians(gint angle)
{
    return M_PI * angle / 180.0;
}

void
geom_angle_rotate_points(gint angle, gint *x, gint *y, gint n)
{
    gdouble radians = geom_angle_radians(angle);
    gdouble c = cos(radians);
    gdouble s = sin(radians);
    gint    i;

    for (i=0; i<n; i++)
    {
        gint tx = *x;
        gint ty = *y;

        *x = round(tx * c - ty * s);
        *y = round(tx * s + ty * c);

        x++;
        y++;
    }
}

