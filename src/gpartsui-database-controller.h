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

/*! \file gparts-database-controller.h
 */

#define GPARTSUI_TYPE_DATABASE_CONTROLLER (gpartsui_database_controller_get_type())
#define GPARTSUI_DATABASE_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTSUI_TYPE_DATABASE_CONTROLLER,GPartsUIDatabaseController))
#define GPARTSUI_DATABASE_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTSUI_TYPE_DATABASE_CONTROLLER,GPartsUIDatabaseControllerClass))
#define GPARTSUI_IS_DATABASE_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTSUI_TYPE_DATABASE_CONTROLLER))
#define GPARTSUI_IS_DATABASE_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTSUI_TYPE_DATABASE_CONTROLLER))
#define GPARTSUI_DATABASE_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTSUI_TYPE_DATABASE_CONTROLLER,GPartsUIDatabaseControllerClass))

struct _GPartsUIDatabaseController
{
    GObject parent;
};

/*! \private */
struct _GPartsUIDatabaseControllerClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpartsui_database_controller_get_type(void);

/*! \brief Connects to a database, just as if the user clicked the menu item.
 *
 *  \param [in] controller The controller.
 */
void
gpartsui_database_controller_connect_database(GPartsUIDatabaseController *controller);

/*! \brief Disconnect the database, just as if the user clicked the menu item.
 *
 *  \param [in] controller The controller.
 */
void
gpartsui_database_controller_disconnect_database(GPartsUIDatabaseController *controller);

/*! \brief Drop the database, just as if the user clicked the menu item.
 *
 *  \param [in] controller The controller.
 */
void
gpartsui_database_controller_drop_database(GPartsUIDatabaseController *controller);

/*! \brief Gets the database currently associated with this controller.
 *
 *  \param [in] controller The controller.
 *  \return The database associated with this ctrl.  If no database, then NULL.
 */
GPartsDatabase*
gpartsui_database_controller_get_database(GPartsUIDatabaseController *controller);

/*! \brief Sets the action to connect to a database.
 *
 *  \param [in] controller The controller.
 *  \param [in] action The action that triggers the connect.
 */
void
gpartsui_database_controller_set_connect_action(GPartsUIDatabaseController *controller, GtkAction *action);

/*! \brief Sets the action to disconnect from the database.
 *
 *  \param [in] controller The controller.
 *  \param [in] action The action that triggers the disconnect.
 */
void
gpartsui_database_controller_set_disconnect_action(GPartsUIDatabaseController *controller, GtkAction *action);

/*! \brief Sets the action to drop the database.
 *
 *  \param [in] controller The controller.
 *  \param [in] action The action that triggers the drop.
 */
void
gpartsui_database_controller_set_drop_action(GPartsUIDatabaseController *controller, GtkAction *action);


/*! \brief Sets the action to refresh all database views.
 *
 *  \param [in] controller The controller.
 *  \param [in] action The action that triggers the refresh.
 */
void
gpartsui_database_controller_set_refresh_action(GPartsUIDatabaseController *controller, GtkAction *action);

