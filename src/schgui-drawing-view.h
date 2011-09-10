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

/*! \file schgui-drawing-view.h
 */

#define SCHGUI_TYPE_DRAWING_VIEW (schgui_drawing_view_get_type())
#define SCHGUI_DRAWING_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_DRAWING_VIEW,SchGUIDrawingView))
#define SCHGUI_DRAWING_VIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_DRAWING_VIEW,SchGUIDrawingViewClass))
#define SCHGUI_IS_DRAWING_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_DRAWING_VIEW))
#define SCHGUI_IS_DRAWING_VIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_DRAWING_VIEW))
#define SCHGUI_DRAWING_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_DRAWING_VIEW,SchGUIDrawingViewClass))

/*! \extends GtkBin */
struct _SchGUIDrawingView
{
    GtkBin parent;
};

/*! \private */
struct _SchGUIDrawingViewClass
{
    GtkBinClass parent;
};

/*! \private */
GType
schgui_drawing_view_get_type(void);

/*! \brief Get the configuration for this view
 *
 *  \public
 *  \memberof _SchGUIDrawingView
 *
 *  \param [in] widget This widget.
 *  \return The drawing
 */
SchGUIConfig*
schgui_drawing_view_get_config(SchGUIDrawingView *widget);

/*! \brief Get the drawing shown in this view
 *
 *  \public
 *  \memberof _SchGUIDrawingView
 *
 *  \param [in] widget This widget.
 *  \return The drawing
 */
SchDrawing*
schgui_drawing_view_get_drawing(SchGUIDrawingView *widget);

/*! \brief Set the contents of the window to a new drawing.
 *
 *  \public
 *  \memberof _SchGUIDrawingView
 *
 *  \param [in] widget This widget.
 *  \param [in] drawing The new drawing to show in the window.
 */
void
schgui_drawing_view_set_drawing(SchGUIDrawingView *widget, SchDrawing *drawing);

/*! \brief Enlarges the drawing to fit the widget.
 *
 *  \public
 *  \memberof _SchGUIDrawingView
 *
 *  \param [in] widget This widget.
 */
void
schgui_drawing_view_zoom_extents(SchGUIDrawingView *widget);

