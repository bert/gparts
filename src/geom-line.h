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

/*! \file geom-line.h
 */

struct _GeomTransform;

typedef struct _GeomLine GeomLine;

struct _GeomLine
{
    int x[2];
    int y[2];
};

/*! \brief Calculate the bounding rectangle of the given line.
 *
 *  \param [in]  line
 *  \param [out] bounds
 */
void
geom_line_bounds(const GeomLine *line, GeomBounds *bounds);

void
geom_line_init(GeomLine *line);

/*! \brief Calculate the length of the given line.
 *
 * \param [in] line
 */
double
geom_line_length(const GeomLine *line);

/*! \brief Swap the endpoints of the given line
 */
void
geom_line_reverse(GeomLine *line);

void
geom_line_rotate(GeomLine *line, int angle);

void
geom_line_transform(GeomLine *line, const struct _GeomTransform *transform);

void
geom_line_translate(GeomLine *line, int dx, int dy);

