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

/*! \file gparts-login-ctrl.c
 */

#include <string.h>
#include <gtk/gtk.h>

#include "misc-object.h"

#include "gparts-connect-data.h"

#include "gparts-database-result.h"
#include "gparts-database.h"
#include "gparts-database-type.h"
#include "gparts-login-ctrl.h"

#include "gparts-connect-controller.h"

#define GPARTS_LOGIN_CTRL_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_LOGIN_CTRL,GPartsLoginCtrlPrivate)

enum
{
    GPARTS_LOGIN_CTRL_PROPID_DATABASE = 1,

    GPARTS_LOGIN_CTRL_PROPID_CONNECT_ACTION,
    GPARTS_LOGIN_CTRL_PROPID_DISCONNECT_ACTION,
    GPARTS_LOGIN_CTRL_PROPID_DROP_ACTION,
    GPARTS_LOGIN_CTRL_PROPID_REFRESH_ACTION
};

typedef struct _GPartsLoginCtrlPrivate GPartsLoginCtrlPrivate;

struct _GPartsLoginCtrlPrivate
{
    GtkAction      *connect_action;
    GtkAction      *disconnect_action;
    GtkAction      *drop_action;
    GtkAction      *refresh_action;

    GPartsDatabase     *database;
    GPartsDatabaseType *database_type;

    GPartsConnectController *ctrl;
};


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
gparts_login_ctrl_connect_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_connected_cb(GPartsDatabase *database, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_disconnect_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_disconnected_cb(GPartsDatabase *database, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_drop_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_refresh_action_cb(GtkAction *action, GPartsLoginCtrl *login_ctrl);

static void
gparts_login_ctrl_show_cb(GtkWidget *widget, GPartsLoginCtrl *login_ctrl);



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
            GPARTS_TYPE_DATABASE,
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
        GPARTS_LOGIN_CTRL_PROPID_DROP_ACTION,
        g_param_spec_object(
            "drop-action",
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
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);

    if (privat != NULL)
    {
        gboolean success;
        gint flags;

#if 0
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
#endif
    }
}

static void
gparts_login_ctrl_connect_action_cb(GtkAction *action, GPartsLoginCtrl *controller)
{
    gparts_login_ctrl_connect_database(controller);
}

void
gparts_login_ctrl_connect_database(GPartsLoginCtrl *controller)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        gint result = gparts_connect_controller_run(privat->ctrl);

        if (result == GTK_RESPONSE_OK)
        {
            GPartsConnectData *data = gparts_connect_controller_get_connect_data(privat->ctrl);

            if (data != NULL)
            {
                GPartsDatabase *database;
                GError *error = NULL;

                database = g_object_new(g_type_from_name("gparts-mysql-database"), NULL);

                gparts_database_connect(database, data, &error);

                gparts_connect_data_free(data);

                if (error != NULL)
                {
                    GtkWidget *error_dialog = gtk_message_dialog_new(
                        NULL, /* GTK_WINDOW(privat->login_dialog), */
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
                    gparts_login_ctrl_set_database(controller, database);
                }

                g_object_unref(database);
            }
        }
    }

}


static void
gparts_login_ctrl_disconnect_action_cb(GtkAction *action, GPartsLoginCtrl *controller)
{
    gparts_login_ctrl_disconnect_database(controller);
}

void
gparts_login_ctrl_disconnect_database(GPartsLoginCtrl *controller)
{
    gparts_login_ctrl_set_database(controller, NULL);
}

static void
gparts_login_ctrl_connected_cb(GPartsDatabase *database, GPartsLoginCtrl *login_ctrl)
{
}

static void
gparts_login_ctrl_disconnected_cb(GPartsDatabase *database, GPartsLoginCtrl *login_ctrl)
{
}

static void
gparts_login_ctrl_dispose(GObject *object)
{
    gparts_login_ctrl_set_database(GPARTS_LOGIN_CTRL(object), NULL);

    gparts_login_ctrl_set_connect_action(GPARTS_LOGIN_CTRL(object), NULL);
    gparts_login_ctrl_set_disconnect_action(GPARTS_LOGIN_CTRL(object), NULL);
    gparts_login_ctrl_set_drop_action(GPARTS_LOGIN_CTRL(object), NULL);
    gparts_login_ctrl_set_refresh_action(GPARTS_LOGIN_CTRL(object), NULL);

    misc_object_chain_dispose(object);
}

static void
gparts_login_ctrl_drop_action_cb(GtkAction *action, GPartsLoginCtrl *controller)
{
    gparts_login_ctrl_drop_database(controller);
}

void
gparts_login_ctrl_drop_database(GPartsLoginCtrl *controller)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(controller);

    if ((privat != NULL) && (privat->database != NULL))
    {
        GError *error = NULL;

        gparts_database_drop(privat->database, &error);

        if (error != NULL)
        {
            GtkWidget *error_dialog = gtk_message_dialog_new(
                NULL, /* GTK_WINDOW(privat->login_dialog), */
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "%s",
                error->message
                );

            gtk_dialog_run(GTK_DIALOG(error_dialog));

            gtk_widget_destroy(error_dialog);

            g_clear_error(&error);
        }
    }
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

    misc_object_chain_finalize(object);
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

    GPartsConnectData connect_data;

    privat->ctrl = gparts_connect_controller_new();

    connect_data.hostname = "localhost"; /* g_get_host_name(); */
    connect_data.username = g_get_user_name();
    connect_data.password = NULL;
    connect_data.database = "GParts";
    connect_data.filename = NULL;

    gparts_connect_controller_set_connect_data(privat->ctrl, &connect_data);


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

            //gtk_action_set_sensitive(privat->disconnect_action, (privat->database != NULL));
            gtk_action_set_sensitive(privat->disconnect_action, TRUE);
        }

        g_object_notify(G_OBJECT(login_ctrl), "disconnect-action");
    }
}

static void
gparts_login_ctrl_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsLoginCtrl *controller = GPARTS_LOGIN_CTRL(object);

    switch (property_id)
    {
        case GPARTS_LOGIN_CTRL_PROPID_CONNECT_ACTION:
            gparts_login_ctrl_set_connect_action(controller, GTK_ACTION(g_value_get_object(value)));
            break;

        case GPARTS_LOGIN_CTRL_PROPID_DISCONNECT_ACTION:
            gparts_login_ctrl_set_disconnect_action(controller, GTK_ACTION(g_value_get_object(value)));
            break;

        case GPARTS_LOGIN_CTRL_PROPID_DROP_ACTION:
            gparts_login_ctrl_set_drop_action(controller, GTK_ACTION(g_value_get_object(value)));
            break;

        case GPARTS_LOGIN_CTRL_PROPID_REFRESH_ACTION:
            gparts_login_ctrl_set_refresh_action(controller, GTK_ACTION(g_value_get_object(value)));
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
            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gparts_login_ctrl_connected_cb),
                ctrl
                );

            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gparts_login_ctrl_disconnected_cb),
                ctrl
                );

            g_object_unref(privat->database);
        }

        privat->database = database;

        if (privat->database != NULL)
        {
            g_object_ref(privat->database);

            g_signal_connect(
                privat->database,
                "database-connected",
                G_CALLBACK(gparts_login_ctrl_connected_cb),
                ctrl
                );

            g_signal_connect(
                privat->database,
                "database-disconnected",
                G_CALLBACK(gparts_login_ctrl_disconnected_cb),
                ctrl
                );
        }

        if (privat->disconnect_action != NULL)
        {
            gtk_action_set_sensitive(privat->disconnect_action, (privat->database != NULL));
        }

        if (privat->drop_action != NULL)
        {
            if (privat->database != NULL)
            {
                gtk_action_set_sensitive(privat->drop_action, gparts_database_droppable(privat->database));
            }
            else
            {
                gtk_action_set_sensitive(privat->drop_action, FALSE);
            }
        }

        if (privat->refresh_action != NULL)
        {
            gtk_action_set_sensitive(privat->refresh_action, (privat->database != NULL));
        }

        g_object_notify(G_OBJECT(ctrl), "database");
    }
}

void
gparts_login_ctrl_set_drop_action(GPartsLoginCtrl *login_ctrl, GtkAction *action)
{
    GPartsLoginCtrlPrivate *privat = GPARTS_LOGIN_CTRL_GET_PRIVATE(login_ctrl);

    if (privat != NULL)
    {
        if (privat->drop_action != action)
        {
            if (privat->drop_action != NULL)
            {
                g_signal_handlers_disconnect_by_func(
                    privat->drop_action,
                    G_CALLBACK(gparts_login_ctrl_drop_action_cb),
                    login_ctrl
                    );

                g_object_unref(privat->drop_action);
            }

            privat->drop_action = action;

            if (privat->drop_action != NULL)
            {
                g_object_ref(privat->drop_action);

                g_signal_connect(
                    privat->drop_action,
                    "activate",
                    G_CALLBACK(gparts_login_ctrl_drop_action_cb),
                    login_ctrl
                    );

//                if (privat->database != NULL)
//                {
//                    gtk_action_set_sensitive(privat->drop_action, gparts_database_droppable(privat->database));
//                }
//                else
//                {
//                    gtk_action_set_sensitive(privat->drop_action, FALSE);
//                }
            }

            g_object_notify(G_OBJECT(login_ctrl), "drop-action");
        }
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

