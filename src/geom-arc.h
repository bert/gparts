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
 *
 *  \ingroup geom
 */

#define GEOM_TYPE_ARC (geom_arc_get_type())
#define GEOM_ARC(obj) ((GeomArc*)obj)

typedef struct _GeomArc GeomArc;

/*! \brief A boxed type for an arc
 *
 *  \ingroup geom
 */
struct _GeomArc
{
    gint center_x;
    gint center_y;
    gint radius;
    gint start;
    gint sweep;
};

/*! \brief Calculate the bounding rectangle of the given arc.
 *
 *  \memberof _GeomArc
 *
 *  \param [in]  arc
 *  \param [out] bounds
 */
void
geom_arc_bounds(const GeomArc *arc, GeomBounds *bounds);

/*! \brief Makes a copy of an arc.
 *
 *  \memberof _GeomArc
 *
 *  \param [in] arc The arc to copy
 *  \return A dynamically allocated copy of the given arc
 */
GeomArc*
geom_arc_copy(const GeomArc *arc);

/*! \brief Free a dynamically allocated arc
 *
 *  \memberof _GeomArc
 *
 *  \param [in] arc The arc to free
 */
void
geom_arc_free(GeomArc *arc);

/* \private */
GType
geom_arc_get_type(void);

/*! \brief Initialize an arc
 *
 *  \memberof _GeomArc
 *
 *  \param [out] The arc to initialize
 */
void
geom_arc_init(GeomArc *arc);

/*! \brief Rotate the arc
 *
 *  \memberof _GeomArc
 *
 *  \param [in,out] arc   The arc to transform
 *  \param [in]     angle The angle to rotate in degrees
 */
void
geom_arc_rotate(GeomArc *arc, gint angle);


/*! \brief Transform the arc using the given transformation.
 *
 *  \memberof _GeomArc
 *
 *  Arcs will not scale correctly unless the x and y scale
 *  factors match.
 *
 *  \param [in,out] arc The arc to transform
 *  \param [in]     transform The transformation to apply
 */
void
geom_arc_transform(GeomArc *arc, const GeomTransform *transform);

/*! \brief Translate the arc by the given vector.
 *
 *  \memberof _GeomArc
 *
 *  \param [in,out] arc The arc to translate
 *  \param [in]     dx  The displacement along the x axis
 *  \param [in]     dy  The displacement along the y axis
 */
void
geom_arc_translate(GeomArc *arc, gint dx, gint dy);

