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

/*! \file gparts-connect-controller.h
 */

#define GPARTS_TYPE_CONNECT_CONTROLLER (gparts_connect_controller_get_type())
#define GPARTS_CONNECT_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_CONNECT_CONTROLLER,GPartsConnectController))
#define GPARTS_CONNECT_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_CONNECT_CONTROLLER,GPartsConnectControllerClass))
#define GPARTS_IS_CONNECT_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_CONNECT_CONTROLLER))
#define GPARTS_IS_CONNECT_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_CONNECT_CONTROLLER))
#define GPARTS_CONNECT_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_CONNECT_CONTROLLER,GPartsConnectControllerClass))

struct _GPartsConnectController
{
    GObject parent;
};

/*! \private */
struct _GPartsConnectControllerClass
{
    GObjectClass parent;
};

/*! \private */
GType
gparts_connect_controller_get_type(void);

/*! \brief Gets the connect data from the dialog
 *
 *  When no longer needed, call gparts_connect_data_free() on the returned pointer.
 *
 *  \param [in] controller The controller.
 *  \return The connect data from the dialog box.
 */
GPartsConnectData*
gparts_connect_controller_get_connect_data(GPartsConnectController *controller);

/*! \brief Gets the currently selected database type
 *
 *
 *  When no longer needed, call g_free() on the returned pointer.
 *
 *  \param [in] controller The controller.
 *  \return A string containg the database type.
 */
gchar*
gparts_connect_controller_get_database_type(GPartsConnectController *controller);

/*! \brief Create a new connect dialog controller.
 *
 *  \return A new connect dialog controller.
 */
GPartsConnectController*
gparts_connect_controller_new(void);

/*! \brief
 *
 *  \param [in] controller
 */
gint
gparts_connect_controller_run(GPartsConnectController* controller);

/*! \brief Sets the connect data
 *
 *  \param [in] controller The controller.
 *  \param [in] data The action that triggers the connect.
 */
void
gparts_connect_controller_set_connect_data(GPartsConnectController *controller, const GPartsConnectData *data);

/*! \brief Sets the database types
 *
 *  \param [in] controller The controller.
 *  \param [in] types A list of database types as a NULL terminated list of
 *  strings. (G_TYPE_STRV)
 */
void
gparts_connect_controller_set_database_types(GPartsConnectController *controller, const gchar **types);

/*! \brief Sets the connect data flags
 *
 *  \param [in] controller The controller.
 *  \param [in] flags The connect data flags.
 */
void
gparts_connect_controller_set_flags(GPartsConnectController *controller, gint flags);

