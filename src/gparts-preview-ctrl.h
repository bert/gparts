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

/*! \file gparts-preview-ctrl.h
 */

#define GPARTS_TYPE_PREVIEW_CTRL (gparts_preview_ctrl_get_type())
#define GPARTS_PREVIEW_CTRL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_PREVIEW_CTRL,GPartsPreviewCtrl))
#define GPARTS_PREVIEW_CTRL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_PREVIEW_CTRL,GPartsPreviewCtrlClass))
#define GPARTS_IS_PREVIEW_CTRL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_PREVIEW_CTRL))
#define GPARTS_IS_PREVIEW_CTRL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_PREVIEW_CTRL))
#define GPARTS_PREVIEW_CTRL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_PREVIEW_CTRL,GPartsPreviewCtrlClass))

typedef struct _GPartsPreviewCtrl GPartsPreviewCtrl;
typedef struct _GPartsPreviewCtrlClass GPartsPreviewCtrlClass;

struct _GPartsPreviewCtrl
{
    GObject parent;
};

struct _GPartsPreviewCtrlClass
{
    GObjectClass parent;
};

GType
gparts_preview_ctrl_get_type(void);

GPartsPreviewCtrl*
gparts_preview_ctrl_new();

/*! \brief Sets the action.
 *
 *  Sets the action to copy the symbol to the clipboard.
 *
 *  \param [in] preview_ctrl The controller.
 *  \param [in] database The action to to copy the symbol to the clipboard.
 */
void
gparts_preview_ctrl_set_copy_action(GPartsPreviewCtrl *preview_ctrl, GtkAction *action);

/*! \brief Sets the source view for data used by field expansion.
 *
 *  If this controller does not use field expansion for any operations, then
 *  the source may be set to NULL.
 *
 *  \param [in] preview_ctrl The controller.
 *  \param [in] source
 */
void
gparts_preview_ctrl_set_symbol_source(GPartsPreviewCtrl *preview_ctrl, GtkTreeView *soruce);

void
gparts_preview_ctrl_set_attrib_source(GPartsPreviewCtrl *preview_ctrl, GtkTreeView *attrib_source);

/*! \brief Sets the target view for results from database queries.
 *
 *  \param [in] preview_ctrl The controller.
 *  \param [in] target A GtkTreeView to place database query results into.
 */
void
gparts_preview_ctrl_set_target(GPartsPreviewCtrl *preview_ctrl, GtkDrawingArea *target);

