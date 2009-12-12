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

/*! \file sch_shape.h
 *
 *  \brief An interface for schematic shapes.
 */

#define SCH_TYPE_SHAPE (sch_shape_get_type())
#define SCH_SHAPE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_SHAPE,SchShape))
#define SCH_IS_SHAPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_SHAPE))
#define SCH_SHAPE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE((obj),SCH_TYPE_SHAPE,SchShapeInterface))

struct _GeomTransform;
struct _SchDrafter;

typedef struct _SchShape SchShape;
typedef struct _SchShapeInterface SchShapeInterface;

struct _SchShapeInterface
{
    GTypeInterface parent;

    gboolean (*bounds)(SchShape *shape, struct _SchDrafter *drafter, GeomBounds *bounds);
    void (*draw)(SchShape *shape, struct _SchDrafter *drafter);
    void (*rotate)(SchShape *shape, int angle);
    void (*transform)(SchShape *shape, const struct _GeomTransform *transform);
    void (*translate)(SchShape *shape, int dx, int dy);
};

GType
sch_shape_get_type(void);

/*! \brief Calculate the bounds of a schematic shape
 *
 *  \param [in] shape The shape for the bounds calculation.
 *  \param [in] drafter Context specific data for the calcualtion.
 *  \param [out] bounds If successful, the bounds of the shape.
 *  \retval FALSE The function was unable to calculate the bounds.
 *  \retval TRUE The function calcualted the bounds successfully.
 */
gboolean
sch_shape_bounds(SchShape *shape, struct _SchDrafter *drafter, GeomBounds *bounds);

/*! \brief Draws the shape.
 *
 *  \param [in] shape The shape to draw.
 *  \param [in] drafter The strategy to draw the shape.
 */
void
sch_shape_draw(SchShape *shape, struct _SchDrafter *drafter);

void
sch_shape_rotate(SchShape *shape, int angle);

void
sch_shape_transform(SchShape *shape, const struct _GeomTransform *transform);

void
sch_shape_translate(SchShape *shape, int dx, int dy);

