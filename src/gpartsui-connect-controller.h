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

/*! \file gparts-connect-controller.h
 */

#define GPARTSUI_TYPE_CONNECT_CONTROLLER (gpartsui_connect_controller_get_type())
#define GPARTSUI_CONNECT_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTSUI_TYPE_CONNECT_CONTROLLER,GPartsUIConnectController))
#define GPARTSUI_CONNECT_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTSUI_TYPE_CONNECT_CONTROLLER,GPartsUIConnectControllerClass))
#define GPARTSUI_IS_CONNECT_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTSUI_TYPE_CONNECT_CONTROLLER))
#define GPARTSUI_IS_CONNECT_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTSUI_TYPE_CONNECT_CONTROLLER))
#define GPARTSUI_CONNECT_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTSUI_TYPE_CONNECT_CONTROLLER,GPartsUIConnectControllerClass))

struct _GPartsUIConnectController
{
    GObject parent;
};

/*! \private */
struct _GPartsUIConnectControllerClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpartsui_connect_controller_get_type(void);

/*! \brief Connect to a database
 *
 *  \public
 *  \memberof _GPartsUIConnectController
 *
 *  Connects to a database, just as if the connect action emitted activate.
 *
 *  \param [in] controller This controller.
 */
void
gpartsui_connect_controller_connect(GPartsUIConnectController *controller);

/*! \brief Gets the action to connect to a database
 *
 *  \public
 *  \memberof _GPartsUIConnectController
 *
 *  When no longer needed, call g_object_unref() on the returned pointer.
 *
 *  \param [in] controller This controller.
 *  \return A pointer to the action to connect to a database.
 */
GtkAction*
gpartsui_connect_controller_get_connect_action(const GPartsUIConnectController *controller);

/*! \brief Gets the presentation model
 *
 *  \public
 *  \memberof _GPartsUIConnectController
 *
 *  When no longer needed, call g_object_unref() on the returned pointer.
 *
 *  \param [in] controller This controller.
 *  \return A pointer to the presentation model.
 */
GPartsUIConnectModel*
gpartsui_connect_controller_get_connect_model(const GPartsUIConnectController *controller);


/*! \brief Sets the action to connect to a database
 *
 *  \public
 *  \memberof _GPartsUIConnectController
 *
 *  \param [in] controller This controller.
 *  \param [in] action     The action to initiate the connection.
 */
void
gpartsui_connect_controller_set_connect_action(GPartsUIConnectController *controller, GtkAction *action);

/*! \brief Sets the presentation model
 *
 *  \public
 *  \memberof _GPartsUIConnectController
 *
 *  \param [in] controller This controller.
 *  \param [in] model      The presentation model.
 */
void
gpartsui_connect_controller_set_connect_model(GPartsUIConnectController *controller, GPartsUIConnectModel *model);

