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

/*! \file geom-circle.h
 *
 *  \ingroup geom
 */

#define GEOM_TYPE_CIRCLE (geom_circle_get_type())
#define GEOM_CIRCLE(obj) ((GeomCircle*)obj)

typedef struct _GeomCircle GeomCircle;

/*! \brief A boxed type for a circle
 *
 *  \ingroup geom
 */
struct _GeomCircle
{
    gint center_x;
    gint center_y;
    gint radius;
};

/*! \brief Calculate the bounding rectangle of the given circle.
 *
 *  \memberof _GeomCircle
 *
 *  \param [in]  circle
 *  \param [out] bounds
 */
void
geom_circle_bounds(const GeomCircle *circle, GeomBounds *bounds);

/*! \brief Makes a copy of a circle.
 *
 *  \memberof _GeomCircle
 *
 *  \param [in] circle The circle to copy
 *  \return A dynamically allocated copy of the given circle
 */
GeomCircle*
geom_circle_copy(const GeomCircle *circle);

/*! \brief Free a dynamically allocated circle
 *
 *  \memberof _GeomCircle
 *
 *  \param [in] circle The circle to free
 */
void
geom_circle_free(GeomCircle *circle);

/* \private */
GType
geom_circle_get_type(void);

/*! \brief Initialize a circle to default values
 *
 *  \memberof _GeomCircle
 *
 *  \param [out] circle The circle to initialize
 */
void
geom_circle_init(GeomCircle *circle);

/*! \brief Rotate the given circle
 *
 *  \memberof _GeomCircle
 *
 *  \param [in,out] circle The circle to rotate
 *  \param [in]     angle  The angle to rotate in degrees
 */
void
geom_circle_rotate(GeomCircle *circle, gint angle);

/*! \brief Transform the given circle
 *
 *  \memberof _GeomCircle
 *
 *  \param [in,out] circle    The circle to translate
 *  \param [in]     transform The transformation to apply
 */
void
geom_circle_transform(GeomCircle *circle, const GeomTransform *transform);

/*! \brief Translate the given circle
 *
 *  \memberof _GeomCircle
 *
 *  \param [in,out] circle The circle to translate
 *  \param [in]     x      The displacement on the x axis
 *  \param [in]     y      The displacement on the y axis
 */
void
geom_circle_translate(GeomCircle *circle, gint dx, gint dy);

