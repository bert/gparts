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

/*! \file gparts-login-ctrl.h
 */

#define GPARTS_TYPE_LOGIN_CTRL (gparts_login_ctrl_get_type())
#define GPARTS_LOGIN_CTRL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_LOGIN_CTRL,GPartsLoginCtrl))
#define GPARTS_LOGIN_CTRL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_LOGIN_CTRL,GPartsLoginCtrlClass))
#define GPARTS_IS_LOGIN_CTRL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_LOGIN_CTRL))
#define GPARTS_IS_LOGIN_CTRL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_LOGIN_CTRL))
#define GPARTS_LOGIN_CTRL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_LOGIN_CTRL,GPartsLoginCtrlClass))

typedef struct _GPartsLoginCtrl GPartsLoginCtrl;
typedef struct _GPartsLoginCtrlClass GPartsLoginCtrlClass;

struct _GPartsLoginCtrl
{
    GObject parent;
};

/*! \private */
struct _GPartsLoginCtrlClass
{
    GObjectClass parent;
};

/*! \private */
GType
gparts_login_ctrl_get_type(void);

/*! \brief Connects to a database, just as if the user clicked the menu item.
 *
 *  \param [in] controller The controller.
 */
void
gparts_login_ctrl_connect_database(GPartsLoginCtrl *controller);

/*! \brief Disconnect the database, just as if the user clicked the menu item.
 *
 *  \param [in] controller The controller.
 */
void
gparts_login_ctrl_disconnect_database(GPartsLoginCtrl *controller);

/*! \brief Drop the database, just as if the user clicked the menu item.
 *
 *  \param [in] controller The controller.
 */
void
gparts_login_ctrl_drop_database(GPartsLoginCtrl *controller);

/*! \brief Gets the database currently associated with this controller.
 *
 *  \param [in] controller The controller.
 *  \return The database associated with this ctrl.  If no database, then NULL.
 */
GPartsDatabase*
gparts_login_ctrl_get_database(GPartsLoginCtrl *controller);

/*! \brief Sets the action to connect to a database.
 *
 *  \param [in] controller The controller.
 *  \param [in] action The action that triggers the connect.
 */
void
gparts_login_ctrl_set_connect_action(GPartsLoginCtrl *controller, GtkAction *action);

/*! \brief Sets the action to disconnect from the database.
 *
 *  \param [in] controller The controller.
 *  \param [in] action The action that triggers the disconnect.
 */
void
gparts_login_ctrl_set_disconnect_action(GPartsLoginCtrl *controller, GtkAction *action);

/*! \brief Sets the action to drop the database.
 *
 *  \param [in] controller The controller.
 *  \param [in] action The action that triggers the drop.
 */
void
gparts_login_ctrl_set_drop_action(GPartsLoginCtrl *controller, GtkAction *action);


/*! \brief Sets the action to refresh all database views.
 *
 *  \param [in] controller The controller.
 *  \param [in] action The action that triggers the refresh.
 */
void
gparts_login_ctrl_set_refresh_action(GPartsLoginCtrl *controller, GtkAction *action);

