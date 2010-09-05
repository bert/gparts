/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2010 Edward C. Hennessy
 * Copyright (C) 2010 gEDA Contributors (see ChangeLog for details)
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

/*! \file sch-cairo-shape.h
 */

#define SCH_TYPE_CAIRO_SHAPE (sch_cairo_shape_get_type())
#define SCH_CAIRO_SHAPE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_CAIRO_SHAPE,SchCairoShape))
#define SCH_CAIRO_SHAPE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_CAIRO_SHAPE,SchCairoShapeClass))
#define SCH_IS_CAIRO_SHAPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_CAIRO_SHAPE))
#define SCH_IS_CAIRO_SHAPE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_CAIRO_SHAPE))
#define SCH_CAIRO_SHAPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_CAIRO_SHAPE,SchCairoShapeClass))

typedef struct _SchCairoShape SchCairoShape;
typedef struct _SchCairoShapeClass SchCairoShapeClass;

struct _SchCairoShape
{
    GObject parent;
};

struct _SchCairoShapeClass
{
    GObjectClass parent;

    void (*draw)(const SchCairoShape *shape, cairo_t *cairo);
    void (*update)(SchCairoShape *shape);
};

GType
sch_cairo_shape_get_type(void);

/*! \brief Draws the shape onto the cairo context.
 *
 *  \param [in] shape The shape to draw.
 *  \param [in] cairo The context to draw the shape onto.
 */
void
sch_cairo_shape_draw(const SchCairoShape *shape, cairo_t *cairo);

/*! \brief Update the shape.
 *
 *  \param [in] shape The shape to update.
 */
void
sch_cairo_shape_update(SchCairoShape *shape);

