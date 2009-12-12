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

#include <math.h>
#include <glib.h>
#include "geom-transform.h"

/*! \brief Combines two transformations
 *
 *  Combines two matricies using matrix multiplication: a*b.
 *
 *  \param result [out] The resulting transformation.  If either operand is
 *  NULL, the contents of the result remain unaltered.
 *  \param a [in] The second operand.
 *  \param b [in] The second operand.
 */
void
geom_transform_combine(GeomTransform *result, const GeomTransform *a, const GeomTransform *b)
{
  g_return_if_fail(result!=NULL);
  g_return_if_fail(a!=NULL);
  g_return_if_fail(b!=NULL);

  result->m[0][0] = a->m[0][0] * b->m[0][0] + a->m[0][1] * b->m[1][0];
  result->m[0][1] = a->m[0][0] * b->m[0][1] + a->m[0][1] * b->m[1][1];
  result->m[0][2] = a->m[0][0] * b->m[0][2] + a->m[0][1] * b->m[1][2] + a->m[0][2];
  result->m[1][0] = a->m[1][0] * b->m[0][0] + a->m[1][1] * b->m[1][0];
  result->m[1][1] = a->m[1][0] * b->m[0][1] + a->m[1][1] * b->m[1][1];
  result->m[1][2] = a->m[1][0] * b->m[0][2] + a->m[1][1] * b->m[1][2] + a->m[1][2];
}

/*! \brief Initialize a transform with the identity matrix.
 *
 *  \param transform [out] The transform to initialize with the identity matrix.
 */
void geom_transform_init(GeomTransform *transform)
{
  g_return_if_fail(transform!=NULL);

  transform->m[0][0] = 1;
  transform->m[0][1] = 0;
  transform->m[0][2] = 0;
  transform->m[1][0] = 0;
  transform->m[1][1] = 1;
  transform->m[1][2] = 0;
}

/*! \brief Calculates the inverse transform
 *
 *  \param transform [in] The given matrix
 *  \param inverse [out] The inverse of the given matrix.
 */
void
geom_transform_invert(const GeomTransform *transform, GeomTransform *inverse)
{
  gdouble d;

  g_return_if_fail(transform!=NULL);
  g_return_if_fail(inverse!=NULL);

  d = transform->m[0][0]*transform->m[1][1] - transform->m[1][0]*transform->m[0][1];

  inverse->m[0][0] =  transform->m[1][1] / d;
  inverse->m[0][1] = -transform->m[0][1] / d;
  inverse->m[0][2] =  ( transform->m[0][1]*transform->m[1][2] - transform->m[1][1]*transform->m[0][2] ) / d;
  inverse->m[1][0] = -transform->m[1][0] / d;
  inverse->m[1][1] =  transform->m[0][0] / d;
  inverse->m[1][2] = -( transform->m[0][0]*transform->m[1][2] - transform->m[1][0]*transform->m[0][2] ) / d;
}

/*! \brief Transforms a point
 *
 *  \param x [in,out] The x coordinate to transform.
 *  \param y [in,out] The y coordinate to transform.
 *  \param transform [in] The transform function.
 */
void
geom_transform_point(const GeomTransform *transform, gint *x, gint *y)
{
  gdouble tx;
  gdouble ty;

  g_return_if_fail(transform!=NULL);
  g_return_if_fail(x!=NULL);
  g_return_if_fail(y!=NULL);

  tx = *x;
  ty = *y;

  *x = round(transform->m[0][0] * tx + transform->m[0][1] * ty + transform->m[0][2]);
  *y = round(transform->m[1][0] * tx + transform->m[1][1] * ty + transform->m[1][2]);
}

#if 0
/*! \brief Transforms a polyline or polygon
 *
 *  \param transform [in] The transform function.
 *  \param points [in,out] The GArray of sPOINT to transform.
 */
void geom_transform_points(GeomTransform *transform, GArray *points)
{
  gint index;

  g_return_if_fail(transform!=NULL);
  g_return_if_fail(points!=NULL);

  for (index=0; index<points->len; index++) {
    sPOINT *point = &g_array_index(points, sPOINT, index);
    geom_transform_point(transform, &(point->x), &(point->y));
  }
}
#endif

/*! \brief Adds a rotation to the transformation
 *
 *  \param transform [in,out] The given matrix
 *  \param angle [in] The angle to rotate
 */
void
geom_transform_rotate(GeomTransform *transform, gdouble angle)
{
  gdouble r = G_PI*angle/180.0;
  gdouble c = cos(r);
  gdouble s = sin(r);
  GeomTransform temp;

  g_return_if_fail(transform!=NULL);

  temp = *transform;

  transform->m[0][0] = temp.m[0][0] *  c + temp.m[0][1] * s;
  transform->m[0][1] = temp.m[0][0] * -s + temp.m[0][1] * c;
  transform->m[1][0] = temp.m[1][0] *  c + temp.m[1][1] * s;
  transform->m[1][1] = temp.m[1][0] * -s + temp.m[1][1] * c;
}

/*! \brief Adds a scaling to the transformation
 *
 *  \param transform [in,out] The given matrix
 *  \param factor [in] The amount to scale the transform.  This parameter must
 *  not be zero, or the matrix becomes singular.
 */
void
geom_transform_scale(GeomTransform *transform, gdouble factor)
{
  g_return_if_fail(transform!=NULL);
  g_return_if_fail(factor!=0);

  transform->m[0][0] *= factor;
  transform->m[0][1] *= factor;
  transform->m[1][0] *= factor;
  transform->m[1][1] *= factor;
}

/*! \brief Adds a translation to the transformation
 *
 *  \param transform [in,out] The given matrix.
 *  \param dx [in] The amount to translate on the x axis.
 *  \param dy [in] The amount to translate on the y axis.
 */
void
geom_transform_translate(GeomTransform *transform, gdouble dx, gdouble dy)
{
  g_return_if_fail(transform!=NULL);

  transform->m[0][2] += dx;
  transform->m[1][2] += dy;
}

