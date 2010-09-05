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

/*! \file schgui-cairo-drawing.h
 */

#define SCHGUI_TYPE_CAIRO_DRAWING (schgui_cairo_drawing_get_type())
#define SCHGUI_CAIRO_DRAWING(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_CAIRO_DRAWING,SchGUICairoDrawing))
#define SCHGUI_CAIRO_DRAWING_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_CAIRO_DRAWING,SchGUICairoDrawingClass))
#define SCHGUI_IS_CAIRO_DRAWING(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_CAIRO_DRAWING))
#define SCHGUI_IS_CAIRO_DRAWING_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_CAIRO_DRAWING))
#define SCHGUI_CAIRO_DRAWING_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_CAIRO_DRAWING,SchGUICairoDrawingClass))

typedef struct _SchGUICairoDrawing SchGUICairoDrawing;
typedef struct _SchGUICairoDrawingClass SchGUICairoDrawingClass;

struct _SchGUICairoDrawing
{
    GObject parent;
};

struct _SchGUICairoDrawingClass
{
    GObjectClass parent;
};

GType
schgui_cairo_drawing_get_type(void);

/*! \brief Append a shape to the drawing
 *
 *  \param [in] drawing The drawing
 *  \param [in] shape   The shape to append
 */
void
schgui_cairo_drawing_append_shape(SchGUICairoDrawing *drawing, SchShape *shape);

/*! \brief Calculate the drawing bounds 
 *
 *  \param [in]  drawing The drawing
 *  \param [in]  cairo   The cairo context
 *  \param [out] bounds  The bounds of the drawing
 */
void
schgui_cairo_drawing_bounds(SchGUICairoDrawing *drawing, cairo_t *cairo, GeomBounds *bounds);

/*! \brief Draw the drawing
 *
 *  \param [in] drawing The drawing
 *  \param [in] cairo   The cairo context to draw upon
 */
void
schgui_cairo_drawing_draw(SchGUICairoDrawing *drawing, cairo_t *cairo);

/*! \brief Call a function for each shape in the drawing
 *
 *  void func(SchShape *shape, gpointer user_data);
 *
 *  \param [in] The drawing
 *  \param [in] The function to call for each shape in the drawing
 *  \param [in] Additional data to pass to the function
 */
void
schgui_cairo_drawing_foreach(SchGUICairoDrawing *drawing, GFunc func, gpointer user_data);

/*! \brief Create a drawing 
 *
 *  \param [in] drawing The drawing
 *  \return A pointer to the drawing
 */
SchGUICairoDrawing*
schgui_cairo_drawing_new(SchDrawing *drawing);

/*! \brief Prepend a shape to the drawing
 *
 *  \param [in] drawing The drawing
 *  \param [in] shape   The shape to prepend
 */
void
schgui_cairo_drawing_prepend_shape(SchGUICairoDrawing *drawing, SchShape *shape);

