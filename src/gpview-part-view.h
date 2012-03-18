/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2012 Edward C. Hennessy
 * Copyright (C) 2012 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpview-part-view.h
 */

#define GPVIEW_TYPE_PART_VIEW (gpview_part_view_get_type())
#define GPVIEW_PART_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPVIEW_TYPE_PART_VIEW,GPViewPartView))
#define GPVIEW_PART_VIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPVIEW_TYPE_PART_VIEW,GPViewPartViewClass))
#define GPVIEW_IS_PART_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPVIEW_TYPE_PART_VIEW))
#define GPVIEW_IS_PART_VIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPVIEW_TYPE_PART_VIEW))
#define GPVIEW_PART_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPVIEW_TYPE_PART_VIEW,GPViewPartViewClass))

/*! \extends GtkHPaned */
struct _GPViewPartView
{
    GtkHPaned parent;
};

/*! \private */
struct _GPViewPartViewClass
{
    GtkHPanedClass parent;
};

/*! \private */
GType
gpview_part_view_get_type(void);

GPViewPartView*
gpview_part_view_new_with_controller(GPViewPartCtrl *ctrl);

void
gpview_part_view_set_controller(GPViewPartView *view, GPViewPartCtrl *ctrl);

/*! \brief Gets the name of the form used to create a new part
 *
 *  Use g_free on the returned pointer when no longer needed.
 *
 *  \param [in] view This view
 *  \return The name of the form used to create a new part of this
 *  category. This function may return NULL.
 */
gchar*
gpview_part_view_get_create_form(const GPViewPartView *view);

/*! \brief Gets the name of the form used to edit an existing part
 *
 *  Use g_free on the returned pointer when no longer needed.
 *
 *  \param [in] view This view
 *  \return The name of the form used to edit an existing part of this
 *  category. This function may return NULL.
 */
gchar*
gpview_part_view_get_edit_form(const GPViewPartView *view);

/*! \brief Gets the drawing for the currently selected part.
 *
 *  The part view instantiates the currently selected part and
 *  places it in a drawing. The contents of this drawing can
 *  be cut and paste into a schematic.
 *
 *  Use g_object_unref on the returned pointer when no longer needed.
 *
 *  \param [in] view This view
 *  \return A pointer to the drawing.
 */
SchDrawing*
gpview_part_view_get_drawing(const GPViewPartView *view);

GPViewPartView*
gpview_part_view_new(void);

