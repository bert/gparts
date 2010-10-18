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

/*! \file miscui-action-controller.h
 */

#define MISCUI_TYPE_ACTION_CONTROLLER (miscui_action_controller_get_type())
#define MISCUI_ACTION_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),MISCUI_TYPE_ACTION_CONTROLLER,MiscUIActionController))
#define MISCUI_ACTION_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),MISCUI_TYPE_ACTION_CONTROLLER,MiscUIActionControllerClass))
#define MISCUI_IS_ACTION_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),MISCUI_TYPE_ACTION_CONTROLLER))
#define MISCUI_IS_ACTION_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),MISCUI_TYPE_ACTION_CONTROLLER))
#define MISCUI_ACTION_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),MISCUI_TYPE_ACTION_CONTROLLER,MiscUIActionControllerClass))

struct _MiscUIActionController
{
    GObject parent;
};

/*! \private */
struct _MiscUIActionControllerClass
{
    GObjectClass parent;
};

/*! \private */
GType
miscui_action_controller_get_type(void);

GtkAction*
miscui_action_controller_get_action(const MiscUIActionController *controller);

MiscUIActionModel*
miscui_action_controller_get_model(const MiscUIActionController *controller);

void
miscui_action_controller_set_action(MiscUIActionController *controller, GtkAction *action);

void
miscui_action_controller_set_model(MiscUIActionController *controller, MiscUIActionModel *model);

