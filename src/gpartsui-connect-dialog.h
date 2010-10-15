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

#define GPARTS_TYPE_CONNECT_CONTROLLER (gpartsui_connect_dialog_get_type())
#define GPARTS_CONNECT_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_CONNECT_CONTROLLER,GPartsUIConnectDialog))
#define GPARTS_CONNECT_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_CONNECT_CONTROLLER,GPartsUIConnectDialogClass))
#define GPARTS_IS_CONNECT_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_CONNECT_CONTROLLER))
#define GPARTS_IS_CONNECT_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_CONNECT_CONTROLLER))
#define GPARTS_CONNECT_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_CONNECT_CONTROLLER,GPartsUIConnectDialogClass))

struct _GPartsUIConnectDialog
{
    GObject parent;
};

/*! \private */
struct _GPartsUIConnectDialogClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpartsui_connect_dialog_get_type(void);

/*! \brief Clears the password entry widget
 *
 *  \public
 *  \memberof _GPartsUIConnectDialog
 *
 *  \param [in] controller This controller.
 */
void
gpartsui_connect_dialog_clear_password(GPartsUIConnectDialog *controller);

/*! \brief Gets the connect-data from the dialog
 *
 *  \public
 *  \memberof _GPartsUIConnectDialog
 *
 *  When no longer needed, call gparts_connect_data_free() on the returned pointer.
 *
 *  \param [in] controller This controller.
 *  \return The connect-data from the dialog box.
 */
GPartsConnectData*
gpartsui_connect_dialog_get_connect_data(GPartsUIConnectDialog *controller);

/*! \brief Gets the currently selected database type
 *
 *  \public
 *  \memberof _GPartsUIConnectDialog
 *
 *  The return value will be one of the strings in the database-types property.
 *
 *  When no longer needed, call g_free() on the returned pointer.
 *
 *  \param [in] controller This controller.
 *  \return A string containg the current database type.
 */
gchar*
gpartsui_connect_dialog_get_database_type(GPartsUIConnectDialog *controller);

/*! \brief Create a new connect dialog controller.
 *
 *  \public
 *  \memberof _GPartsUIConnectDialog
 *
 *  \return A new connect dialog controller.
 */
GPartsUIConnectDialog*
gpartsui_connect_dialog_new(void);

/*! \brief Run the modal dialog
 *
 *  \public
 *  \memberof _GPartsUIConnectDialog
 *
 *  \param [in] controller This controller.
 *  \retval GTK_RESPONSE_CANCEL The user cancelled the operation
 *  \retval GTK_RESPONSE_HELP   The user clicked the help button
 *  \retval GTK_RESPONSE_NONE   Dialog was destroyed
 *  \retval GTK_RESPONSE_OK     The user clicked the ok button
 */
gint
gpartsui_connect_dialog_run(GPartsUIConnectDialog* controller);

/*! \brief Sets the connect-data
 *
 *  \public
 *  \memberof _GPartsUIConnectDialog
 *
 *  Populates all the UI widgets with fields from the connect-data.
 *
 *  \param [in] controller The controller.
 *  \param [in] data The connect-data.
 */
void
gpartsui_connect_dialog_set_connect_data(GPartsUIConnectDialog *controller, const GPartsConnectData *data);

/*! \brief Sets the list of database types
 *
 *  \public
 *  \memberof _GPartsUIConnectDialog
 *
 *  \param [in] controller The controller.
 *  \param [in] types A NULL terminated list of database type names.
 */
void
gpartsui_connect_dialog_set_database_types(GPartsUIConnectDialog *controller, const GStrv types);

/*! \brief Sets the connect-data flags
 *
 *  \public
 *  \memberof _GPartsUIConnectDialog
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
gpartsui_connect_dialog_set_flags(GPartsUIConnectDialog *controller, gint flags);

/*! \brief Sets the state of the connect data as valid or invalid.
 *
 *  \public
 *  \memberof _GPartsUIConnectDialog
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
gpartsui_connect_dialog_set_valid(GPartsUIConnectDialog *controller, gboolean valid);

