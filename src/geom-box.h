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

/*! \file geom-box.h
 *
 *  \ingroup geom
 */

#define GEOM_TYPE_BOX (geom_box_get_type())
#define GEOM_BOX(obj) ((GeomBox*)obj)

typedef struct _GeomBox GeomBox;

/*! \brief A boxed type for a box (a rectangle)
 *
 *  \ingroup geom
 */
struct _GeomBox
{
    gint corner_x;
    gint corner_y;
    gint width;
    gint height;
};

/*! \brief Calculate the bounding rectangle of the given box.
 *
 *  \memberof _GeomBox
 *
 *  \param [in]  box
 *  \param [out] bounds
 */
void
geom_box_bounds(const GeomBox *box, GeomBounds *bounds);

/*! \brief Makes a copy of a box.
 *
 *  \memberof _GeomBox
 *
 *  \param [in] box The box to copy
 *  \return A dynamically allocated copy of the given box
 */
GeomBox*
geom_box_copy(const GeomBox *box);

/*! \brief Free a dynamically allocated box
 *
 *  \memberof _GeomBox
 *
 *  \param [in] box The box to free
 */
void
geom_box_free(GeomBox *box);

/* \private */
GType
geom_box_get_type(void);

/*! \brief  Initialize a box with default values
 *
 *  \memberof _GeomBox
 *
 *  \param [out] box The box to initialize
 */
void
geom_box_init(GeomBox *box);

/*! \brief Rotate a box
 *
 *  \memberof _GeomBox
 *
 *  Boxes cannot be rotated by arbitrary angles. Angles other
 *  than 0, 90, 180, and 270 will produce poor results.
 *
 *  \param [in,out] box   The box to rotate
 *  \param [in]     angle The angle to rotate in degrees
 */
void
geom_box_rotate(GeomBox *box, gint angle);

/*! \brief Transform a box
 *
 *  \memberof _GeomBox
 *
 *  Boxes cannot be rotated by arbitrary angles. Angles other
 *  than 0, 90, 180, and 270 will produce poor results.
 *
 *  \param [in,out] box       The box to transform
 *  \param [in]     transform The transformation to apply
 */
void
geom_box_transform(GeomBox *box, const GeomTransform *transform);

/*! \brief Translate a box
 *
 *  \memberof _GeomBox
 *
 *  \param [in,out] box The box to translate
 *  \paran [in]     x   The displacement along the x axis
 *  \param [in]     y   The displacement along the y axis
 */
void
geom_box_translate(GeomBox *box, gint dx, gint dy);

