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

/*! \file gparts-login-dialog.c 
 */

#include <gtk/gtk.h>

#include "misc-object.h"

#include "gparts-login-dialog.h"

enum
{
    GPARTS_LOGIN_DIALOG_PROPID_DATABASE = 1,
};

typedef struct _GPartsLoginDialogPrivate GPartsLoginDialogPrivate;

struct _GPartsLoginDialogPrivate
{
    GtkDialog *dialog;
};

#define GPARTS_LOGIN_DIALOG_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_LOGIN_DIALOG,GPartsLoginDialogPrivate)

static void
gparts_login_dialog_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_login_dialog_dispose(GObject *object);

static void
gparts_login_dialog_finalize(GObject *object);

static void
gparts_login_dialog_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gparts_login_dialog_instance_init(GTypeInstance *instance, gpointer g_class);

static void
gparts_login_dialog_set_database(GPartsLoginDialog *controller, GPartsDatabase *database);

static void
gparts_login_dialog_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

/**** Signal handlers ****/

static void
gparts_login_dialog_changed_cb(GtkTreeSelection *selection, GPartsLoginDialog *controller);

static void
gparts_login_dialog_show_cb(GtkWidget *widget, GPartsLoginDialog *controller);

static void
gparts_login_dialog_connect_action_cb(GtkAction *action, GPartsLoginDialog *controller);

static void
gparts_login_dialog_disconnect_action_cb(GtkAction *action, GPartsLoginDialog *controller);

static void
gparts_login_dialog_refresh_action_cb(GtkAction *action, GPartsLoginDialog *controller);

/*! \brief Initialize class data.
 *
 *  \param [in] g_class
 *  \param [in] g_class_data
 */
static void
gparts_login_dialog_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsLoginDialogPrivate));

    object_class->dispose  = gparts_login_dialog_dispose;
    object_class->finalize = gparts_login_dialog_finalize;

    object_class->get_property = gparts_login_dialog_get_property;
    object_class->set_property = gparts_login_dialog_set_property;

    g_object_class_install_property(
        object_class,
        GPARTS_LOGIN_DIALOG_PROPID_CONNECT_ACTION,
        g_param_spec_object(
            "connect-action",
            "",
            "",
            GTK_TYPE_ACTION,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_LOGIN_DIALOG_PROPID_DATABASE,
        g_param_spec_object(
            "database",
            "",
            "",
            G_TYPE_OBJECT,
            G_PARAM_READABLE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_LOGIN_DIALOG_PROPID_DISCONNECT_ACTION,
        g_param_spec_object(
            "disconnect-action",
            "",
            "",
            GTK_TYPE_ACTION,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_LOGIN_DIALOG_PROPID_REFRESH_ACTION,
        g_param_spec_object(
            "refresh-action",
            "",
            "",
            GTK_TYPE_ACTION,
            G_PARAM_READWRITE
            )
        );

    g_signal_new(
        "refresh",
        G_TYPE_FROM_CLASS(g_class),
        G_SIGNAL_RUN_FIRST,
        0,
        NULL,
        NULL,
        g_cclosure_marshal_VOID__VOID,
        G_TYPE_NONE,
        0
        );
}

static void
gparts_login_dialog_changed_cb(GtkTreeSelection *selection, GPartsLoginDialog *controller)
{
    GPartsLoginDialogPrivate *privat = GPARTS_LOGIN_DIALOG_GET_PRIVATE(controller);

    gtk_entry_set_text(privat->server_entry, "localhost");
    gtk_entry_set_text(privat->database_entry, "GParts");
}

static void
gparts_login_dialog_connect_action_cb(GtkAction *action, GPartsLoginDialog *controller)
{
    GPartsLoginDialogPrivate *private = GPARTS_LOGIN_DIALOG_GET_PRIVATE(controller);

    gint result;


    gtk_entry_set_text(private->user_name_entry, g_get_user_name());

    gtk_entry_set_text(private->password_entry, "");

    gtk_combo_box_set_active(private->engine_combo, 0);


    result = gtk_dialog_run(private->login_dialog);
#if 1

    if (result == GTK_RESPONSE_ACCEPT)
    {
        GPartsDatabase *database;
        connect_data data;
        GError *error = NULL;

        data.user_name     = gtk_entry_get_text(private->user_name_entry);
        data.password      = gtk_entry_get_text(private->password_entry);
        data.host_name     = gtk_entry_get_text(private->server_entry);
        data.database_name = gtk_entry_get_text(private->database_entry);

        database = g_object_new(g_type_from_name("gparts-mysql-database"), NULL);

        gparts_database_connect(database, &data, &error);

        if (error != NULL)
        {
            GtkWidget *error_dialog = gtk_message_dialog_new(
                private->login_dialog,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "%s",
                error->message
                );

            gtk_dialog_run(GTK_DIALOG(error_dialog));

            gtk_widget_destroy(error_dialog);

            g_critical("%s", error->message);
            g_clear_error(&error);
        }
        else
        {
            gparts_login_dialog_set_database(controller, database);
        }

        g_object_unref(database);
    }

#endif
    gtk_widget_hide(GTK_WIDGET(private->login_dialog));
}

static void
gparts_login_dialog_disconnect_action_cb(GtkAction *action, GPartsLoginDialog *controller)
{
    gparts_login_dialog_set_database(controller, NULL);
}

static void
gparts_login_dialog_dispose(GObject *object)
{
    gparts_login_dialog_set_database(object, NULL);

    misc_object_chain_dispose(object);
}

/*! \brief Deallocate all resources.
 *
 *  This function performs the second and last stage of object destruction.
 *
 *  \param [in] object The object to finalize.
 */
static void
gparts_login_dialog_finalize(GObject *object)
{
    GPartsLoginDialogPrivate *private = GPARTS_LOGIN_DIALOG_GET_PRIVATE(object);

    g_array_free(private->view_controllers, TRUE);

    misc_object_chain_finalize(object);
}

/*! \brief Gets the GType of the GPartsLoginDialog class.
 *
 *  \return The GType of the GPartsLoginDialog class.
 */
GType
gparts_login_dialog_get_type(void)
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsLoginDialogClass),
            NULL,
            NULL,
            gparts_login_dialog_class_init,
            NULL,
            NULL,
            sizeof(GPartsLoginDialog),
            0,
            gparts_login_dialog_instance_init,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gparts-database-controller",
            &tinfo,
            0
            );
    }
    return type;
}

GPartsDatabase*
gparts_login_dialog_get_database(GPartsLoginDialog *controller)
{
    GPartsDatabase *database = NULL;
    GPartsLoginDialogPrivate *privat = GPARTS_LOGIN_DIALOG_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        database = privat->database;
    }

    return database;
}

static void
gparts_login_dialog_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsLoginDialogPrivate *privat = GPARTS_LOGIN_DIALOG_GET_PRIVATE(object);

    switch (property_id)
    {
        case GPARTS_LOGIN_DIALOG_PROPID_CONNECT_ACTION:
            g_value_set_object(value, privat->connect_action);
            break;

        case GPARTS_LOGIN_DIALOG_PROPID_DATABASE:
            g_value_set_object(value, gparts_login_dialog_get_database(object));
            break;

        case GPARTS_LOGIN_DIALOG_PROPID_DISCONNECT_ACTION:
            g_value_set_object(value, privat->disconnect_action);
            break;

        case GPARTS_LOGIN_DIALOG_PROPID_REFRESH_ACTION:
            g_value_set_object(value, privat->refresh_action);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
gparts_login_dialog_instance_init(GTypeInstance *instance, gpointer g_class)
{
    GPartsLoginDialogPrivate *privat = GPARTS_LOGIN_DIALOG_GET_PRIVATE(instance);

    privat->dialog = gtk_dialog_new_with_buttons(
        "Connect to a Database",
        NULL,
        GTK_DIALOG_MODAL,
        GTK_STOCK_HELP,    GTK_RESPONSE_HELP,
        GTK_STOCK_CANCEL,  GTK_RESPONSE_CANCEL,
        GTK_STOCK_CONNECT, GTK_RESPONSE_ACCEPT,
        NULL
        );

    gtk_dialog_set_default_response(private->login_dialog, GTK_RESPONSE_OK);

    content = private->login_dialog->vbox; //gtk_dialog_get_content_area(private->login_dialog);

    table = gtk_table_new(6, 3, FALSE);
    GTK_WIDGET_SET_FLAGS(table, GTK_VISIBLE);
    gtk_container_add(GTK_CONTAINER(content), table);

    image = gtk_image_new_from_stock(GTK_STOCK_DIALOG_AUTHENTICATION, GTK_ICON_SIZE_DIALOG);
    GTK_WIDGET_SET_FLAGS(image, GTK_VISIBLE);
    gtk_table_attach(table, image, 0, 1, 0, 6, GTK_FILL, GTK_SHRINK, 0, 0);

    label = gtk_label_new("Engine");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_table_attach(table, label, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);

    private->engine_combo = gtk_combo_box_new_text();
    GTK_WIDGET_SET_FLAGS(private->engine_combo, GTK_VISIBLE);
    gtk_table_attach(table, private->engine_combo, 2, 3, 0, 1, GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Username");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_table_attach(table, label, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);

    private->user_name_entry = gtk_entry_new();
    GTK_WIDGET_SET_FLAGS(private->user_name_entry, GTK_VISIBLE);
    gtk_table_attach(table, private->user_name_entry, 2, 3, 1, 2, GTK_EXPAND | GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Password");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_table_attach(table, label, 1, 2, 2, 3, GTK_FILL, GTK_FILL, 0, 0);

    private->password_entry = gtk_entry_new();
    g_object_set(private->password_entry, "visibility", FALSE,NULL);
    GTK_WIDGET_SET_FLAGS(private->password_entry, GTK_VISIBLE);
    gtk_table_attach(table, private->password_entry, 2, 3, 2, 3, GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Server");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_table_attach(table, label, 1, 2, 3, 4, GTK_FILL, GTK_FILL, 0, 0);

    private->server_entry = gtk_entry_new();
    GTK_WIDGET_SET_FLAGS(private->server_entry, GTK_VISIBLE);
    gtk_table_attach(table, private->server_entry, 2, 3, 3, 4, GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Database");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_table_attach(table, label, 1, 2, 4, 5, GTK_FILL, GTK_FILL, 0, 0);

    private->database_entry = gtk_entry_new();
    GTK_WIDGET_SET_FLAGS(private->database_entry, GTK_VISIBLE);
    gtk_table_attach(table, private->database_entry, 2, 3, 4, 5, GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Filename");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_table_attach(table, label, 1, 2, 5, 6, GTK_FILL, GTK_FILL, 0, 0);

    private->filename_entry = gtk_entry_new();
    GTK_WIDGET_SET_FLAGS(private->filename_entry, GTK_VISIBLE);
    gtk_table_attach(table, private->filename_entry, 2, 3, 5, 6, GTK_FILL, GTK_FILL, 0, 0);

    gtk_combo_box_append_text(private->engine_combo, "MySQL");
    gtk_combo_box_append_text(private->engine_combo, "PostgreSQL");
    gtk_combo_box_append_text(private->engine_combo, "SQLite");

    g_signal_connect(
        private->engine_combo,
        "changed",
        G_CALLBACK(gparts_login_dialog_changed_cb),
        instance
        );
}

static void
gparts_login_dialog_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    switch (property_id)
    {
        case GPARTS_LOGIN_DIALOG_PROPID_REFRESH_ACTION:
            gparts_login_dialog_set_refresh_action(object, g_value_get_object(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
gparts_login_dialog_set_database(GPartsLoginDialog *controller, GPartsDatabase *database)
{
    GPartsLoginDialogPrivate *privat = GPARTS_LOGIN_DIALOG_GET_PRIVATE(controller);

    if (privat->database != database)
    {
        if (privat->database != NULL)
        {
            g_object_unref(privat->database);
        }

        privat->database = database;

        if (privat->database != NULL)
        {
            g_object_ref(privat->database);
        }

        if (privat->disconnect_action != NULL)
        {
            gtk_action_set_sensitive(privat->disconnect_action, (privat->database != NULL));
        }

        if (privat->refresh_action != NULL)
        {
            gtk_action_set_sensitive(privat->refresh_action, (privat->database != NULL));
        }

        g_object_notify(G_OBJECT(controller), "database");
    }
}

