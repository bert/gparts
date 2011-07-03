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
 *
 *  \ingroup geom
 */

#define GEOM_TYPE_BOUNDS (geom_bounds_get_type())
#define GEOM_BOUNDS(obj) ((GeomBounds*)obj)

typedef struct _GeomBounds GeomBounds;

/*! \brief A boxed type for the bounds of a geometric shape
 *
 *  \ingroup geom
 */
struct _GeomBounds
{
    int min_x;
    int min_y;
    int max_x;
    int max_y;
};

/*! \brief Determines if a point lies within the given bounds.
 *
 *  \memberof _GeomBounds
 *
 *  \param [in] bounds The bounds to test.
 *  \param [in] x The x coordinate of the given point.
 *  \param [in] y The y coordinate of the given point.
 *  \return Zero The given bounds does not contain the given point.
 *  \return Non-zero The given bounds contains given the point.
 */
int
geom_bounds_contains(const GeomBounds *bounds, int x, int y);

/*! \brief Makes a copy of a bounds.
 *
 *  \memberof _GeomBounds
 *
 *  \param [in] bounds The bounds to copy
 *  \return A dynamically allocated copy of the given bounds
 */
GeomBounds*
geom_bounds_copy(const GeomBounds *bounds);

/*! \brief Determines if a given bounds contains no points.
 *
 *  \memberof _GeomBounds
 *
 *  \param [in] The bounds to check
 *  \return TRUE  if the bounds contains a point
 *  \return FALSE if the bounds does not contain a point
 */
int
geom_bounds_empty(const GeomBounds *bounds);

/*! \brief
 *
 *  \memberof _GeomBounds
 *
 *  \param []
 */
void
geom_bounds_expand(GeomBounds *result, const GeomBounds *op, int size);

/*! \brief Free a dynamically allocated bounds
 *
 *  \memberof _GeomBounds
 *
 *  \param [in] bounds The bounds to free
 */
void
geom_bounds_free(GeomBounds *bounds);

/* \private */
GType
geom_bounds_get_type(void);

/*! \brief
 *
 *  \memberof _GeomBounds
 *
 *  \param []
 */
void
geom_bounds_include(GeomBounds *bounds, const int x[], const int y[], int size);

/*! \brief Initialize a bounds to empty.
 *
 *  \memberof _GeomBounds
 *
 *  \param [out] The bounds to initialize.
 */
void
geom_bounds_init(GeomBounds *bounds);

/*! \brief
 *
 *  \memberof _GeomBounds
 *
 *  \param [in,out] bounds The bounds to translate
 *  \param [in]     dx     The displacement on the y axis
 *  \param [in]     dy     The displacement on the x axis
 */
void
geom_bounds_translate(GeomBounds *bounds, int dx, int dy);

/*! \brief
 *
 *  \memberof _GeomBounds
 *
 *  \param []
 */
void
geom_bounds_union(GeomBounds *result, const GeomBounds *op1, const GeomBounds *op2);

