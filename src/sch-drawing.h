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

/*! \file sch_drawing.h
 */

#define SCH_TYPE_DRAWING (sch_drawing_get_type())
#define SCH_DRAWING(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_DRAWING,SchDrawing))
#define SCH_DRAWING_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_DRAWING,SchDrawingClass))
#define SCH_IS_DRAWING(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_DRAWING))
#define SCH_IS_DRAWING_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_DRAWING))
#define SCH_DRAWING_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_DRAWING,SchDrawingClass))

enum
{
    SCH_DRAWING_SIGNAL_APPEND,
    SCH_DRAWING_SIGNAL_PREPEND,
    SCH_DRAWING_SIGNAL_COUNT
};

struct _SchDrawing
{
    GObject parent;
};

struct _SchDrawingClass
{
    GObjectClass parent;

    guint signal_id[SCH_DRAWING_SIGNAL_COUNT];
};

GType
sch_drawing_get_type(void);

/*! \brief Append a shape to the drawing
 *
 *  After appending the shape, the drawing emits the "append" signal.
 *
 *  \param [in] drawing The drawing
 *  \param [in] shape   The shape to append
 */
void
sch_drawing_append_shape(SchDrawing *drawing, SchShape *shape);

/*! \brief Call a function for each shape in the drawing
 *
 *  void func(SchShape *shape, gpointer user_data);
 *
 *  \param [in] The drawing
 *  \param [in] The function to call for each shape in the drawing
 *  \param [in] Additional data to pass to the function
 */
void
sch_drawing_foreach(SchDrawing *drawing, GFunc func, gpointer user_data);

/*! \brief Get the basename of the drawing
 *
 *  When no longer needed, call g_free() on the returned pointer.
 *
 *  \param [in] The drawing
 *  \return The basename of the drawing
 */
char*
sch_drawing_get_basename(const SchDrawing *drawing);

/*! \brief Get the filename of the drawing
 *
 *  When no longer needed, call g_free() on the returned pointer.
 *
 *  \param [in] The drawing
 *  \return The filename of the drawing
 */
char*
sch_drawing_get_filename(const SchDrawing *drawing);

/*! \brief Create a new, empty drawing
 *
 *  \return The drawing
 */
SchDrawing*
sch_drawing_new(void);

/*! \brief Prepend a shape to the drawing
 *
 *  After prepending the shape, the drawing emits the "prepend" signal.
 *
 *  \param [in] drawing The drawing
 *  \param [in] shape   The shape to prepend
 */
void
sch_drawing_prepend_shape(SchDrawing *drawing, SchShape *shape);

/*! \brief Rotate the drawing
 *
 *  Rotate all shapes in the drawing.
 *
 *  \param [in] drawing The drawing
 *  \param [in] angle   The ange to rotate the drawing.
 */
void
sch_drawing_rotate(SchDrawing *drawing, int angle);

/*! \brief Set the drawing's file format
 *
 *  \param [in] drawing The drawing
 *  \param [in] format  The file format for this drawing
 */
void
sch_drawing_set_file_format(SchDrawing *drawing, SchFileFormat2 *format);

/*! \brief Set the filename of the drawing
 *
 *  \param [in] The drawing
 *  \param [in] The filename of the drawing
 */
void
sch_drawing_set_filename(const SchDrawing *drawing, const char *filename);

/*! \brief Transform the drawing
 *
 *  Transform all shapes in the drawing.
 *
 *  \param [in] drawing   The drawing
 *  \param [in] transform The transformation to perform on the drawing
 */
void
sch_drawing_transform(SchDrawing *drawing, const GeomTransform *transform);

/*! \brief Translate the drawing
 *
 *  Translate all shapes in the drawing.
 *
 *  \param [in] drawing The drawing
 *  \param [in] dx      The offset to translate on the x axis
 *  \param [in] dy      The offset to translate on the y axis
 */
void
sch_drawing_translate(SchDrawing *drawing, int dx, int dy);

/*! \brief Write the drawing to an output stream
 *
 *  \param [in] drawing The drawing
 *  \param [in] stream  The output stream
 */
void
sch_drawing_write(const SchDrawing *drawing, SchOutputStream *stream);

