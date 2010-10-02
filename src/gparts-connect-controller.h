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

/*! \brief Clears the password entry widget
 *
 *  \public
 *  \memberof _GPartsConnectController
 *
 *  \param [in] controller This controller.
 */
void
gparts_connect_controller_clear_password(GPartsConnectController *controller);

/*! \brief Gets the connect-data from the dialog
 *
 *  \public
 *  \memberof _GPartsConnectController
 *
 *  When no longer needed, call gparts_connect_data_free() on the returned pointer.
 *
 *  \param [in] controller This controller.
 *  \return The connect-data from the dialog box.
 */
GPartsConnectData*
gparts_connect_controller_get_connect_data(GPartsConnectController *controller);

/*! \brief Gets the currently selected database type
 *
 *  \public
 *  \memberof _GPartsConnectController
 *
 *  The return value will be one of the strings in the database-types property.
 *
 *  When no longer needed, call g_free() on the returned pointer.
 *
 *  \param [in] controller This controller.
 *  \return A string containg the current database type.
 */
gchar*
gparts_connect_controller_get_database_type(GPartsConnectController *controller);

/*! \brief Create a new connect dialog controller.
 *
 *  \public
 *  \memberof _GPartsConnectController
 *
 *  \return A new connect dialog controller.
 */
GPartsConnectController*
gparts_connect_controller_new(void);

/*! \brief Run the modal dialog
 *
 *  \public
 *  \memberof _GPartsConnectController
 *
 *  \param [in] controller This controller.
 *  \retval GTK_RESPONSE_CANCEL The user cancelled the operation
 *  \retval GTK_RESPONSE_HELP   The user clicked the help button
 *  \retval GTK_RESPONSE_NONE   Dialog was destroyed
 *  \retval GTK_RESPONSE_OK     The user clicked the ok button
 */
gint
gparts_connect_controller_run(GPartsConnectController* controller);

/*! \brief Sets the connect-data
 *
 *  \public
 *  \memberof _GPartsConnectController
 *
 *  Populates all the UI widgets with fields from the connect-data.
 *
 *  \param [in] controller The controller.
 *  \param [in] data The connect-data.
 */
void
gparts_connect_controller_set_connect_data(GPartsConnectController *controller, const GPartsConnectData *data);

/*! \brief Sets the list of database types
 *
 *  \public
 *  \memberof _GPartsConnectController
 *
 *  \param [in] controller The controller.
 *  \param [in] types A NULL terminated list of database type names.
 */
void
gparts_connect_controller_set_database_types(GPartsConnectController *controller, const GStrv types);

/*! \brief Sets the connect-data flags
 *
 *  \public
 *  \memberof _GPartsConnectController
 *
 *  These flags indicate which fields in the connect-data property are used.
 *  This controller will enable and disable the widgets associated with data
 *  entry for each field. If the field is used, then this function enables
 *  the widget. If the field is not used, then this function disables the
 *  widget.
 *
 *  An external mechanism should monitor this controller's properties. When
 *  state changes occur, the external mechanism should set the connect-data
 *  flags appropriately.
 *
 *  \param [in] controller This controller.
 *  \param [in] flags The connect-data flags.
 */
void
gparts_connect_controller_set_flags(GPartsConnectController *controller, gint flags);

/*! \brief Sets the state of the connect data as valid or invalid.
 *
 *  \public
 *  \memberof _GPartsConnectController
 *
 *  This function either enables or disables the dialog box "OK" button. With
 *  invalid data, the UI prevents the user from proceeding with the operation.
 *  With valid data, the UI allows the user to proceed with the operation.
 *
 *  An external mechanism should monitor the connect-data property for state
 *  changes. When state changes occur, the external mechanism should validate
 *  the connect-data and then set this property accordingly.
 *
 *  \param [in] controller This controller.
 *  \param [in] valid Indicates the connect-data property is valid or invalid.
 */
void
gparts_connect_controller_set_valid(GPartsConnectController *controller, gboolean valid);

