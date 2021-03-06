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

/*! \file geom-line.c
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>
#include <glib-object.h>

#include "geom-angle.h"
#include "geom-bounds.h"
#include "geom-transform.h"

#include "geom-line.h"

void
geom_line_bounds(const GeomLine *line, GeomBounds *bounds)
{
    if (line != NULL)
    {
        geom_bounds_include(bounds, line->x, line->y, 2);
    }
}

GeomLine*
geom_line_copy(const GeomLine *line)
{
    return GEOM_LINE(g_memdup(line, sizeof(GeomLine)));
}

GType
geom_line_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        type = g_boxed_type_register_static(
            "GeomLine",
            (GBoxedCopyFunc) geom_line_copy,
            (GBoxedFreeFunc) geom_line_free
            );
    }

    return type;
}

void
geom_line_free(GeomLine *line)
{
    g_free(line);
}

void
geom_line_init(GeomLine *line)
{
    memset(line, 0, sizeof(GeomLine));
}

gdouble
geom_line_length(const GeomLine *line)
{
    return 0;
}

void
geom_line_reverse(GeomLine *line)
{
}

void
geom_line_rotate(GeomLine *line, gint angle)
{
    if (line != NULL)
    {
        geom_angle_rotate_points(angle, &(line->x[0]), &(line->y[0]), 2);
    }
}

void
geom_line_transform(GeomLine *line, const GeomTransform *transform)
{
    if ((line != NULL) && (transform != NULL))
    {
        geom_transform_point(transform, &(line->x[0]), &(line->y[0]));
        geom_transform_point(transform, &(line->x[1]), &(line->y[1]));
    }
}

#if 0
/*! \brief Transforms multiple line segments
 *
 *  \param transform [in] The transform function.
 *  \param lines [inout] The GArray of LINE to transform.
 */
void geom_transform_lines(GeomTransform *transform, GArray *lines)
{
  gint index;

  g_return_if_fail(transform!=NULL);
  g_return_if_fail(lines!=NULL);

  for (index=0; index<lines->len; index++) {
    LINE *line = &g_array_index(lines, LINE, index);
    geom_transform_line(transform, line);
  }
}
#endif

void
geom_line_translate(GeomLine *line, gint dx, gint dy)
{
    if (line != NULL)
    {
        line->x[0] += dx;
        line->y[0] += dy;
        line->x[1] += dx;
        line->y[1] += dy;
    }
}

