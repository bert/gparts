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

/*! \file gparts-customize-ctrl.h
 */

#define GPARTS_TYPE_CUSTOMIZE_CTRL (gparts_customize_ctrl_get_type())
#define GPARTS_CUSTOMIZE_CTRL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_CUSTOMIZE_CTRL,GPartsCustomizeCtrl))
#define GPARTS_CUSTOMIZE_CTRL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_CUSTOMIZE_CTRL,GPartsCustomizeCtrlClass))
#define GPARTS_IS_CUSTOMIZE_CTRL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_CUSTOMIZE_CTRL))
#define GPARTS_IS_CUSTOMIZE_CTRL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_CUSTOMIZE_CTRL))
#define GPARTS_CUSTOMIZE_CTRL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_CUSTOMIZE_CTRL,GPartsCustomizeCtrlClass))

typedef struct _GPartsCustomizeCtrl GPartsCustomizeCtrl;
typedef struct _GPartsCustomizeCtrlClass GPartsCustomizeCtrlClass;

struct _GPartsCustomizeCtrl
{
    GObject parent;
};

struct _GPartsCustomizeCtrlClass
{
    GObjectClass parent;
};

GType
gparts_customize_ctrl_get_type(void);

/*! \brief Sets the action to initiate customization.
 *
 *  \param [in] controller The controller.
 *  \param [in] action The action to initiate customization.
 */
void
gparts_customize_ctrl_set_customize_action(GPartsCustomizeCtrl *customize_ctrl, GtkAction *action);

/*! \brief Sets the dialog for customization.
 *
 *  \param [in] controller The controller.
 *  \param [in] dialog The dialog to perform customization.
 */
void
gparts_customize_ctrl_set_customize_dialog(GPartsCustomizeCtrl *customize_ctrl, GtkDialog *dialog);

/*! \brief Sets the target view for customization.
 *
 *  \param [in] controller The controller.
 *  \param [in] target A GtkTreeView to customize.
 */
void
gparts_customize_ctrl_set_target_view(GPartsCustomizeCtrl *customize_ctrl, GtkTreeView *view);

