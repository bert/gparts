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

/*! \file geom-transform.h
 */

typedef struct _GeomTransform GeomTransform;

struct _GeomTransform
{
    gdouble m[2][3];    /* m[row][column] */
};

/*! \brief Combines two transformations
 *
 *  Combines two matricies using matrix multiplication: a*b.
 *
 *  \param result [out] The resulting transformation.  If either operand is
 *  NULL, the contents of the result remain unaltered.
 *  \param a      [in]  The first operand.
 *  \param b      [in]  The second operand.
 */
void
geom_transform_combine(GeomTransform *result, const GeomTransform *a, const GeomTransform *b);

/*! \brief Initialize a transform with the identity matrix.
 *
 *  \param transform [out] The transform to initialize with the identity matrix.
 */
void
geom_transform_init(GeomTransform *transform);

/*! \brief Calculates the inverse transform
 *
 *  \param transform [in]  The given matrix
 *  \param inverse   [out] The inverse of the given matrix.
 */
void
geom_transform_invert(const GeomTransform *transform, GeomTransform *inverse);

/*! \brief Transforms a point
 *
 *  \param transform [in]     The transform function.
 *  \param x         [in,out] The x coordinate to transform.
 *  \param y         [in,out] The y coordinate to transform.
 */
void
geom_transform_point(const GeomTransform *transform, gint *x, gint *y);

/*! \brief Adds a rotation to the transformation
 *
 *  \param transform [in,out] The given matrix
 *  \param angle     [in]     The angle to rotate
 */
void
geom_transform_rotate(GeomTransform *transform, gdouble angle);

/*! \brief Adds a scaling to the transformation
 *
 *  \param transform [in,out] The given matrix
 *  \param factor    [in]     The amount to scale the transform.  This
 *  parameter must not be zero, or the matrix becomes singular.
 */
void
geom_transform_scale(GeomTransform *transform, gdouble factor);

/*! \brief Adds a translation to the transformation
 *
 *  \param transform [in,out] The given matrix.
 *  \param dx        [in]     The amount to translate on the x axis.
 *  \param dy        [in]     The amount to translate on the y axis.
 */
void
geom_transform_translate(GeomTransform *transform, gdouble dx, gdouble dy);

