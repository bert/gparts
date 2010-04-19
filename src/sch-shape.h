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

/*! \file sch-shape.h
 *
 *  \brief An abstract base class for schematic shapes.
 */

/* typedefs in sch-shape-fwd.h */

struct _SchDrafter;
struct _GeomTransform;

struct _SchShape
{
    GObject parent;
};

struct _SchShapeClass
{
    GObjectClass parent;

    gboolean (*bounds)(SchShape *shape, struct _SchDrafter *drafter, GeomBounds *bounds);
    void (*draw)(SchShape *shape, struct _SchDrafter *drafter);
    void (*rotate)(SchShape *shape, int angle);
    void (*transform)(SchShape *shape, const struct _GeomTransform *transform);
    void (*translate)(SchShape *shape, int dx, int dy);
    void (*write)(SchShape *shape, SchFileFormat2 *format, SchOutputStream *stream, GError *error);
};

GType
sch_shape_get_type(void);

/*! \brief Append an attribute to a shape
 *
 *  \param [in] shape     The shape to receive the attribute.
 *  \param [in] attribute The attribute to append.
 */
void
sch_shape_append_attribute(SchShape *shape, SchShape *attribute);

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

/*! \brief Get the attributes associated with this shape.
 *
 *  The caller must call g_object_unref when the attributes are no longer
 *  needed.
 *
 *  \param [in] shape The shape
 *  \return The shape's attributes, or NULL if none.
 */
SchAttributes*
sch_shape_get_attributes(SchShape *shape);

/*! \brief Set the attributes associated with this shape.
 *
 *  \param [in] shape The shape.
 *  \param [in] attributes The attributes.
 */
void
sch_shape_set_attributes(SchShape *shape, SchAttributes *attributes);

/*! \brief Write the shape to an output stream.
 *
 *  \param [in]  shape  The shape.
 *  \param [in]  format The format to write the shape in.
 *  \param [in]  stream The stream to write the shape to.
 *  \param [out] error  The error, if any, using the GError protocol.
 */
void
sch_shape_write(SchShape *shape, SchFileFormat2 *format, SchOutputStream *stream, GError *error);

