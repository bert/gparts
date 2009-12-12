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

/*! \file geom-arc.h
 */

typedef struct _GeomArc GeomArc;

struct _GeomArc
{
    int center_x;
    int center_y;
    int radius;
    int start;
    int sweep;
};

/*! \brief Calculate the bounding rectangle of the given arc.
 *
 *  \param [in]  arc
 *  \param [out] bounds
 */
void
geom_arc_bounds(const GeomArc *arc, GeomBounds *bounds);

/*! \brief Translate the arc by the given vector.
 *
 *  \param [in,out] arc
 *  \param [in]     dx
 *  \param [in]     dy
 */
void
geom_arc_translate(GeomArc *arc, int dx, int dy);

