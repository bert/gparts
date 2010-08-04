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

/*! \file geom-bounds.h
 */

#include <limits.h>
#include <stdlib.h>

#include "geom-bounds.h"

int
geom_bounds_empty(const GeomBounds *bounds)
{
    return (bounds == NULL) || (bounds->min_x > bounds->max_x) || (bounds->min_y > bounds->max_y);
}

void
geom_bounds_expand(GeomBounds *result, const GeomBounds *op, int size)
{
    if (result != NULL)
    {
        if (size > 0)
        {
            if (geom_bounds_empty(op))
            {
                geom_bounds_init(result);
            }
            else
            {
                result->min_x = op->min_x - size;
                result->min_y = op->min_y - size;
                result->max_x = op->max_x + size;
                result->max_y = op->max_y + size;
            }
        }
        else
        {
            result->min_x = op->min_x - size;
            result->min_y = op->min_y - size;
            result->max_x = op->max_x + size;
            result->max_y = op->max_y + size;
        
            if (geom_bounds_empty(op))
            {
                geom_bounds_init(result);
            }
        }
    }
}

void
geom_bounds_include(GeomBounds *bounds, const int x[], const int y[], int size)
{
   if (bounds != NULL)
   {
       int index;

       for (index=0; index<size; index++)
       {
           if (x[index] < bounds->min_x)
           {
               bounds->min_x = x[index];
           }
           
           if (x[index] > bounds->max_x)
           {
               bounds->max_x = x[index];
           }

           if (y[index] < bounds->min_y)
           {
               bounds->min_y = y[index];
           }
           
           if (y[index] > bounds->max_y)
           {
               bounds->max_y = y[index];
           }
       }
   } 
}

void
geom_bounds_init(GeomBounds *bounds)
{
    if (bounds != NULL)
    {
        bounds->min_x = INT_MAX;
        bounds->min_y = INT_MAX;
        bounds->max_x = INT_MIN;
        bounds->max_y = INT_MIN;
    }
}

void
geom_bounds_translate(GeomBounds *bounds, int dx, int dy)
{
    if (!geom_bounds_empty(bounds))
    {
        bounds->min_x += dx;
        bounds->min_y += dy;
        bounds->max_x += dx;
        bounds->max_y += dy;
    }
}

void
geom_bounds_union(GeomBounds *result, const GeomBounds *op1, const GeomBounds *op2)
{
    if (op1->min_x < op2->min_x)
    {
        result->min_x = op1->min_x;
    }
    else
    {
        result->min_x = op2->min_x;
    }
    
    if (op1->max_x > op2->max_x)
    {
        result->max_x = op1->max_x;
    }
    else
    {
        result->max_x = op2->max_x;
    }

    if (op1->min_y < op2->min_y)
    {
        result->min_y = op1->min_y;
    }
    else
    {
        result->min_y = op2->min_y;
    }
    
    if (op1->max_y > op2->max_y)
    {
        result->max_y = op1->max_y;
    }
    else
    {
        result->max_y = op2->max_y;
    }
}

