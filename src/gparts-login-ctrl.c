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

#include <string.h>
#include <gtk/gtk.h>

#include "gparts-database-result.h"
#include "gparts-database.h"
#include "gparts-database-type.h"
#include "gparts-login-ctrl.h"

#define GPARTS_LOGIN_CTRL_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_LOGIN_CTRL,GPartsLoginCtrlPrivate)

enum
{
    GPARTS_LOGIN_CTRL_PROPID_DATABASE = 1,

    GPARTS_LOGIN_CTRL_PROPID_CONNECT_ACTION,
    GPARTS_LOGIN_CTRL_PROPID_DISCONNECT_ACTION,
    GPARTS_LOGIN_CTRL_PROPID_REFRESH_ACTION
};

typedef struct _GPartsLoginCtrlPrivate GPartsLoginCtrlPrivate;

struct _GPartsLoginCtrlPrivate
{
    GtkAction      *connect_action;
    GtkAction      *disconnect_action;
    GtkAction      *refresh_action;

    GPartsDatabase     *database;
    GPartsDatabaseType *database_type;

    GtkDialog      *file_dialog;
    GtkDialog      *login_dialog;

    GtkComboBox    *engine_combo;
    GtkEntry       *user_name_entry;
    GtkEntry       *password_entry;
    GtkEntry       *server_entry;
    GtkEntry       *database_entry;
    GtkEntry       *filename_entry;
    GtkButton      *button;
};


static GtkDialog*
gparts_login_ctrl_build_login_dialog(GPartsLoginCtrl *ctrl);

static void
gparts_login_ctrl_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_login_ctrl_dispose(GObject *object);

static void
gparts_login_ctrl_finalize(GObject *object);

static void
gparts_login_ctrl_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gparts_login_ctrl_instance_init(GTypeInstance *instance, gpointer g_class);

static void
gparts_login_ctrl_set_database(GPartsLoginCtrl *ctrl, GPartsDatabase *database);

static void
gparts_login_ctrl_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

/**** Signal handlers ****/

static void
gparts_login_ctrl_changed_cb(GtkTreeSelection *selection, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_clicked_cb(GtkTreeSelection *selection, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_show_cb(GtkWidget *widget, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_connect_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_disconnect_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_refresh_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl);



static GtkDialog*
gparts_login_ctrl_build_login_dialog(GPartsLoginCtrl *login_ctrl)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);

    GtkWidget *content, *entry, *image, *label, *button;
    GtkTable *table;

    privat->login_dialog = GTK_DIALOG(gtk_dialog_new_with_buttons(
        "Connect to a Database",
        NULL,
        GTK_DIALOG_MODAL,
        GTK_STOCK_HELP,    GTK_RESPONSE_HELP,
        GTK_STOCK_CANCEL,  GTK_RESPONSE_CANCEL,
        GTK_STOCK_CONNECT, GTK_RESPONSE_OK,
        NULL
        ));

    gtk_dialog_set_alternative_button_order(
        privat->login_dialog,
        GTK_RESPONSE_HELP,
        GTK_RESPONSE_OK,
        GTK_RESPONSE_CANCEL,
        -1
        );

    gtk_dialog_set_default_response(privat->login_dialog, GTK_RESPONSE_OK);

    gtk_container_set_border_width(GTK_CONTAINER(privat->login_dialog), 5);

    content = privat->login_dialog->vbox; //gtk_dialog_get_content_area(private->login_dialog);

    gtk_box_set_spacing(GTK_BOX(content), 8);

    table = GTK_TABLE(gtk_table_new(6, 4, FALSE));
    gtk_table_set_row_spacings(table, 8);
    gtk_table_set_col_spacings(table, 10);
    GTK_WIDGET_SET_FLAGS(table, GTK_VISIBLE);
    gtk_container_add(GTK_CONTAINER(content), GTK_WIDGET(table));

    image = gtk_image_new_from_stock(GTK_STOCK_DIALOG_AUTHENTICATION, GTK_ICON_SIZE_DIALOG);
    GTK_WIDGET_SET_FLAGS(image, GTK_VISIBLE);
    gtk_misc_set_alignment(GTK_MISC(image), 0, 0);
    gtk_table_attach(table, GTK_WIDGET(image), 0, 1, 0, 6, GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Type");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
    gtk_table_attach(table, GTK_WIDGET(label), 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);

    privat->engine_combo = GTK_COMBO_BOX(gtk_combo_box_new_text());
    GTK_WIDGET_SET_FLAGS(privat->engine_combo, GTK_VISIBLE);
    gtk_table_attach(table, GTK_WIDGET(privat->engine_combo), 2, 3, 0, 1, GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Username");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
    gtk_table_attach(table, GTK_WIDGET(label), 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);

    privat->user_name_entry = GTK_ENTRY(gtk_entry_new());
    GTK_WIDGET_SET_FLAGS(privat->user_name_entry, GTK_VISIBLE);
    gtk_table_attach(table, GTK_WIDGET(privat->user_name_entry), 2, 3, 1, 2, GTK_EXPAND | GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Password");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
    gtk_table_attach(table, label, 1, 2, 2, 3, GTK_FILL, GTK_FILL, 0, 0);

    privat->password_entry = GTK_ENTRY(gtk_entry_new());
    g_object_set(privat->password_entry, "visibility", FALSE,NULL);
    GTK_WIDGET_SET_FLAGS(privat->password_entry, GTK_VISIBLE);
    gtk_table_attach(table, GTK_WIDGET(privat->password_entry), 2, 3, 2, 3, GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Server");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
    gtk_table_attach(table, label, 1, 2, 3, 4, GTK_FILL, GTK_FILL, 0, 0);

    privat->server_entry = GTK_ENTRY(gtk_entry_new());
    GTK_WIDGET_SET_FLAGS(privat->server_entry, GTK_VISIBLE);
    gtk_table_attach(table, GTK_WIDGET(privat->server_entry), 2, 3, 3, 4, GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Database Name");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
    gtk_table_attach(table, label, 1, 2, 4, 5, GTK_FILL, GTK_FILL, 0, 0);

    privat->database_entry = GTK_ENTRY(gtk_entry_new());
    GTK_WIDGET_SET_FLAGS(privat->database_entry, GTK_VISIBLE);
    gtk_table_attach(table, GTK_WIDGET(privat->database_entry), 2, 3, 4, 5, GTK_FILL, GTK_FILL, 0, 0);

    label = gtk_label_new("Filename");
    GTK_WIDGET_SET_FLAGS(label, GTK_VISIBLE);
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
    gtk_table_attach(table, label, 1, 2, 5, 6, GTK_FILL, GTK_FILL, 0, 0);

    privat->filename_entry = GTK_ENTRY(gtk_entry_new());
    GTK_WIDGET_SET_FLAGS(privat->filename_entry, GTK_VISIBLE);
    gtk_table_attach(table, GTK_WIDGET(privat->filename_entry), 2, 3, 5, 6, GTK_FILL, GTK_FILL, 0, 0);

    privat->button = gtk_button_new_with_label("...");
    GTK_WIDGET_SET_FLAGS(privat->button, GTK_VISIBLE);
    gtk_table_attach(table, privat->button, 3, 4, 5, 6, GTK_FILL, GTK_FILL, 0, 0);


    gtk_combo_box_append_text(privat->engine_combo, "MySQL");
    gtk_combo_box_append_text(privat->engine_combo, "PostgreSQL");
    gtk_combo_box_append_text(privat->engine_combo, "SQLite");

    g_signal_connect(
        privat->engine_combo,
        "changed",
        G_CALLBACK(gparts_login_ctrl_changed_cb),
        login_ctrl
        );

    g_signal_connect(
        privat->button,
        "clicked",
        G_CALLBACK(gparts_login_ctrl_clicked_cb),
        login_ctrl
        );

    privat->file_dialog = gtk_file_chooser_dialog_new(
        "Select File",
        privat->login_dialog,
        GTK_FILE_CHOOSER_ACTION_OPEN,
        GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
        GTK_STOCK_OK,     GTK_RESPONSE_OK,
        NULL
        );


    return privat->login_dialog;
}

/*! \brief Initialize class data.
 *
 *  \param [in] g_class
 *  \param [in] g_class_data
 */
static void
gparts_login_ctrl_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsLoginCtrlPrivate));

    object_class->dispose  = gparts_login_ctrl_dispose;
    object_class->finalize = gparts_login_ctrl_finalize;

    object_class->get_property = gparts_login_ctrl_get_property;
    object_class->set_property = gparts_login_ctrl_set_property;

    g_object_class_install_property(
        object_class,
        GPARTS_LOGIN_CTRL_PROPID_CONNECT_ACTION,
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
        GPARTS_LOGIN_CTRL_PROPID_DATABASE,
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
        GPARTS_LOGIN_CTRL_PROPID_DISCONNECT_ACTION,
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
        GPARTS_LOGIN_CTRL_PROPID_REFRESH_ACTION,
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
gparts_login_ctrl_changed_cb(GtkTreeSelection *selection, GPartsLoginCtrl *login_ctrl)
{
    gboolean success;
    gint flags;
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);

    gtk_entry_set_text(privat->server_entry, "localhost");
    gtk_entry_set_text(privat->database_entry, "GParts");

    success = gparts_database_type_get_flags(
        privat->database_type,
        gtk_combo_box_get_active_text(privat->engine_combo),
        &flags
        );

    gtk_widget_set_sensitive(
        GTK_WIDGET(privat->user_name_entry),
        success && (flags & GPARTS_DATABASE_TYPE_FLAGS_USES_USERNAME)
        );

    gtk_widget_set_sensitive(
        GTK_WIDGET(privat->password_entry),
        success && (flags & GPARTS_DATABASE_TYPE_FLAGS_USES_PASSWORD)
        );

    gtk_widget_set_sensitive(
        GTK_WIDGET(privat->server_entry),
        success && (flags & GPARTS_DATABASE_TYPE_FLAGS_USES_SERVER)
        );

    gtk_widget_set_sensitive(
        GTK_WIDGET(privat->database_entry),
        success && (flags & GPARTS_DATABASE_TYPE_FLAGS_USES_DATABASE)
        );

    gtk_widget_set_sensitive(
        GTK_WIDGET(privat->filename_entry),
        success && (flags & GPARTS_DATABASE_TYPE_FLAGS_USES_FILENAME)
        );

    gtk_widget_set_sensitive(
        GTK_WIDGET(privat->button),
        success && (flags & GPARTS_DATABASE_TYPE_FLAGS_USES_FILENAME)
        );
}

static void
gparts_login_ctrl_clicked_cb(GtkTreeSelection *selection, GPartsLoginCtrl *login_ctrl)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);

    if (privat != NULL && privat->file_dialog != NULL)
    {
        gint result = gtk_dialog_run(privat->file_dialog);

        if (result == GTK_RESPONSE_OK)
        {
            gchar *filename = gtk_file_chooser_get_filename(privat->file_dialog);

            gtk_entry_set_text(privat->filename_entry, filename);

            g_free(filename);
        }

        gtk_widget_hide(privat->file_dialog);
    }
}

static void
gparts_login_ctrl_connect_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);
    gint result;

    gtk_entry_set_text(privat->user_name_entry, g_get_user_name());

    gtk_entry_set_text(privat->password_entry, "");

    gtk_combo_box_set_active(privat->engine_combo, 0);


    result = gtk_dialog_run(privat->login_dialog);
#if 1

    if (result == GTK_RESPONSE_OK)
    {
        GPartsDatabase *database;
        connect_data data;
        GError *error = NULL;

        data.user_name     = gtk_entry_get_text(privat->user_name_entry);
        data.password      = gtk_entry_get_text(privat->password_entry);
        data.host_name     = gtk_entry_get_text(privat->server_entry);
        data.database_name = gtk_entry_get_text(privat->database_entry);

        database = g_object_new(g_type_from_name("gparts-mysql-database"), NULL);

        gparts_database_connect(database, &data, &error);

        if (error != NULL)
        {
            GtkWidget *error_dialog = gtk_message_dialog_new(
                GTK_WINDOW(privat->login_dialog),
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
            gparts_login_ctrl_set_database(login_ctrl, database);
        }

        g_object_unref(database);
    }

#endif
    gtk_widget_hide(GTK_WIDGET(privat->login_dialog));
}

static void
gparts_login_ctrl_disconnect_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl)
{
    gparts_login_ctrl_set_database(login_ctrl, NULL);
}

static void
gparts_login_ctrl_dispose(GObject *object)
{
    gparts_login_ctrl_set_database(GPARTS_LOGIN_CTRL(object), NULL);
}

/*! \brief Deallocate all resources.
 *
 *  This function performs the second and last stage of object destruction.
 *
 *  \param [in] object The object to finalize.
 */
static void
gparts_login_ctrl_finalize(GObject *object)
{
    GPartsLoginCtrlPrivate *private = GPARTS_LOGIN_CTRL_GET_PRIVATE(object);
}

/*! \brief Gets the GType of the GPartsLoginCtrl class.
 *
 *  \return The GType of the GPartsLoginCtrl class.
 */
GType
gparts_login_ctrl_get_type(void)
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsLoginCtrlClass),
            NULL,
            NULL,
            gparts_login_ctrl_class_init,
            NULL,
            NULL,
            sizeof(GPartsLoginCtrl),
            0,
            gparts_login_ctrl_instance_init,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gparts-database-ctrl",
            &tinfo,
            0
            );
    }
    return type;
}

GPartsDatabase*
gparts_login_ctrl_get_database(GPartsLoginCtrl *login_ctrl)
{
    GPartsDatabase *database = NULL;
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);

    if (privat != NULL)
    {
        database = privat->database;
    }

    return database;
}

static void
gparts_login_ctrl_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(object);

    switch (property_id)
    {
        case GPARTS_LOGIN_CTRL_PROPID_CONNECT_ACTION:
            g_value_set_object(value, privat->connect_action);
            break;

        case GPARTS_LOGIN_CTRL_PROPID_DATABASE:
            g_value_set_object(value, gparts_login_ctrl_get_database(GPARTS_LOGIN_CTRL(object)));
            break;

        case GPARTS_LOGIN_CTRL_PROPID_DISCONNECT_ACTION:
            g_value_set_object(value, privat->disconnect_action);
            break;

        case GPARTS_LOGIN_CTRL_PROPID_REFRESH_ACTION:
            g_value_set_object(value, privat->refresh_action);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
gparts_login_ctrl_instance_init(GTypeInstance *instance, gpointer g_class)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(instance);

    privat->login_dialog = gparts_login_ctrl_build_login_dialog(GPARTS_LOGIN_CTRL(instance));
    privat->database_type = gparts_database_type_new();

    /** TODO Move elsewhere */

    gparts_database_type_load_module(privat->database_type, "libgparts-mysql.la", NULL);

    /* TODO Test code / Remove before flight */

    gparts_database_type_add_type(
        privat->database_type,
        "PostgreSQL",
        G_TYPE_INVALID,
        GPARTS_DATABASE_TYPE_FLAGS_USES_USERNAME
        );

    gparts_database_type_add_type(
        privat->database_type,
        "SQLite",
        G_TYPE_INVALID,
        GPARTS_DATABASE_TYPE_FLAGS_USES_FILENAME
        );
}

static void
gparts_login_ctrl_refresh_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);

    if (privat != NULL && privat->database != NULL)
    {
        g_signal_emit_by_name(login_ctrl, "refresh");
    }
}

void
gparts_login_ctrl_set_connect_action(GPartsLoginCtrl *login_ctrl, GtkAction *action)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);

    if (privat->connect_action != action)
    {
        if (privat->connect_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->connect_action,
                G_CALLBACK(gparts_login_ctrl_connect_action_cb),
                login_ctrl
                );

            g_object_unref(privat->connect_action);
        }

        privat->connect_action = action;

        if (privat->connect_action != NULL)
        {
            g_object_ref(privat->connect_action);

            g_signal_connect(
                privat->connect_action,
                "activate",
                G_CALLBACK(gparts_login_ctrl_connect_action_cb),
                login_ctrl
                );
        }

        g_object_notify(G_OBJECT(login_ctrl), "connect-action");
    }
}

void
gparts_login_ctrl_set_disconnect_action(GPartsLoginCtrl *login_ctrl, GtkAction *action)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);

    if (privat->disconnect_action != action)
    {
        if (privat->disconnect_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->disconnect_action,
                G_CALLBACK(gparts_login_ctrl_disconnect_action_cb),
                login_ctrl
                );

            g_object_unref(privat->disconnect_action);
        }

        privat->disconnect_action = action;

        if (privat->disconnect_action != NULL)
        {
            g_object_ref(privat->disconnect_action);

            g_signal_connect(
                privat->disconnect_action,
                "activate",
                G_CALLBACK(gparts_login_ctrl_disconnect_action_cb),
                login_ctrl
                );

            gtk_action_set_sensitive(privat->disconnect_action, (privat->database != NULL));
        }

        g_object_notify(G_OBJECT(login_ctrl), "disconnect-action");
    }
}

static void
gparts_login_ctrl_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsLoginCtrl *login_ctrl = GPARTS_LOGIN_CTRL(object);

    switch (property_id)
    {
        case GPARTS_LOGIN_CTRL_PROPID_CONNECT_ACTION:
            gparts_login_ctrl_set_connect_action(login_ctrl, g_value_get_object(value));
            break;

        case GPARTS_LOGIN_CTRL_PROPID_DISCONNECT_ACTION:
            gparts_login_ctrl_set_disconnect_action(login_ctrl, g_value_get_object(value));
            break;

        case GPARTS_LOGIN_CTRL_PROPID_REFRESH_ACTION:
            gparts_login_ctrl_set_refresh_action(login_ctrl, g_value_get_object(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
gparts_login_ctrl_set_database(GPartsLoginCtrl *ctrl, GPartsDatabase *database)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(ctrl);

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

        g_object_notify(G_OBJECT(ctrl), "database");
    }
}

void
gparts_login_ctrl_set_refresh_action(GPartsLoginCtrl *ctrl, GtkAction *action)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(ctrl);

    if (privat->refresh_action != action)
    {
        if (privat->refresh_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->refresh_action,
                G_CALLBACK(gparts_login_ctrl_refresh_action_cb),
                ctrl
                );

            g_object_unref(privat->refresh_action);
        }

        privat->refresh_action = action;

        if (privat->refresh_action != NULL)
        {
            g_object_ref(privat->refresh_action);

            g_signal_connect(
                privat->refresh_action,
                "activate",
                G_CALLBACK(gparts_login_ctrl_refresh_action_cb),
                ctrl
                );

            gtk_action_set_sensitive(privat->refresh_action, (privat->database != NULL));
        }

        g_object_notify(G_OBJECT(ctrl), "refresh-action");
    }
}

