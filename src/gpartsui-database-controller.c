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

#include "gpartsui.h"

#define GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTSUI_TYPE_DATABASE_CONTROLLER,GPartsUIDatabaseControllerPrivate)

enum
{
    GPARTSUI_DATABASE_CONTROLLER_PROPID_DATABASE = 1,

    GPARTSUI_DATABASE_CONTROLLER_PROPID_CONNECT_ACTION,
    GPARTSUI_DATABASE_CONTROLLER_PROPID_DISCONNECT_ACTION,
    GPARTSUI_DATABASE_CONTROLLER_PROPID_DROP_ACTION,
    GPARTSUI_DATABASE_CONTROLLER_PROPID_REFRESH_ACTION
};

typedef struct _GPartsUIDatabaseControllerPrivate GPartsUIDatabaseControllerPrivate;

struct _GPartsUIDatabaseControllerPrivate
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
gpartsui_database_controller_class_init(gpointer g_class, gpointer g_class_data);

static void
gpartsui_database_controller_dispose(GObject *object);

static void
gpartsui_database_controller_finalize(GObject *object);

static void
gpartsui_database_controller_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpartsui_database_controller_instance_init(GTypeInstance *instance, gpointer g_class);

static void
gpartsui_database_controller_set_database(GPartsUIDatabaseController *ctrl, GPartsDatabase *database);

static void
gpartsui_database_controller_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gpartsui_database_controller_update_flags(GPartsUIDatabaseController *ctrl);

static void
gpartsui_database_controller_update_valid(GPartsUIDatabaseController *ctrl);

/**** Signal handlers ****/

static void
gpartsui_database_controller_connect_data_changed_cb(GPartsConnectController *connect, GParamSpec *pspec, GPartsUIDatabaseController *ctrl);

static void
gpartsui_database_controller_connect_action_cb(GtkAction *action, GPartsUIDatabaseController *database_controller);

static void
gpartsui_database_controller_connected_cb(GPartsDatabase *database, GPartsUIDatabaseController *database_controller);

static void
gpartsui_database_controller_database_type_changed_cb(GPartsConnectController *connect, GParamSpec *pspec, GPartsUIDatabaseController *login);

static void
gpartsui_database_controller_disconnect_action_cb(GtkAction *action, GPartsUIDatabaseController *database_controller);

static void
gpartsui_database_controller_disconnected_cb(GPartsDatabase *database, GPartsUIDatabaseController *database_controller);

static void
gpartsui_database_controller_drop_action_cb(GtkAction *action, GPartsUIDatabaseController *database_controller);

static void
gpartsui_database_controller_refresh_action_cb(GtkAction *action, GPartsUIDatabaseController *database_controller);



/*! \brief Initialize class data.
 *
 *  \param [in] g_class
 *  \param [in] g_class_data
 */
static void
gpartsui_database_controller_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsUIDatabaseControllerPrivate));

    object_class->dispose  = gpartsui_database_controller_dispose;
    object_class->finalize = gpartsui_database_controller_finalize;

    object_class->get_property = gpartsui_database_controller_get_property;
    object_class->set_property = gpartsui_database_controller_set_property;

    g_object_class_install_property(
        object_class,
        GPARTSUI_DATABASE_CONTROLLER_PROPID_CONNECT_ACTION,
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
        GPARTSUI_DATABASE_CONTROLLER_PROPID_DATABASE,
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
        GPARTSUI_DATABASE_CONTROLLER_PROPID_DISCONNECT_ACTION,
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
        GPARTSUI_DATABASE_CONTROLLER_PROPID_DROP_ACTION,
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
        GPARTSUI_DATABASE_CONTROLLER_PROPID_REFRESH_ACTION,
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
gpartsui_database_controller_connect_action_cb(GtkAction *action, GPartsUIDatabaseController *controller)
{
    gpartsui_database_controller_connect_database(controller);
}

static void
gpartsui_database_controller_connect_data_changed_cb(GPartsConnectController *connect, GParamSpec *pspec, GPartsUIDatabaseController *ctrl)
{
    gpartsui_database_controller_update_valid(ctrl);
}

void
gpartsui_database_controller_connect_database(GPartsUIDatabaseController *controller)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        gint result;

        gchar **type_names = NULL;

        if (privat->database_type != NULL)
        {
            type_names = gparts_database_type_get_type_names(privat->database_type);
        }

        gparts_connect_controller_set_database_types(privat->ctrl, type_names);

        g_strfreev(type_names);

        result = gparts_connect_controller_run(privat->ctrl);

        if (result == GTK_RESPONSE_OK)
        {
            GPartsConnectData *data = gparts_connect_controller_get_connect_data(privat->ctrl);

            if (data != NULL)
            {
                GPartsDatabase *database;
                GError *error = NULL;

                {
                    GPartsDatabaseFactory *factory;
                    gchar *name;

                    name = gparts_connect_controller_get_database_type(privat->ctrl);

                    factory = gparts_database_type_get_factory(privat->database_type, name);
                    g_free(name);

                    //database = g_object_new(g_type_from_name("gparts-sqlite-database"), NULL);
                    database = gparts_database_factory_create_database(factory, NULL);
                    g_object_unref(factory);
                }

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
                    gpartsui_database_controller_set_database(controller, database);
                }

                g_object_unref(database);
            }
        }

        gparts_connect_controller_clear_password(privat->ctrl);
    }

}

static void
gpartsui_database_controller_database_type_changed_cb(GPartsConnectController *connect, GParamSpec *pspec, GPartsUIDatabaseController *controller)
{
    gpartsui_database_controller_update_flags(controller);
    gpartsui_database_controller_update_valid(controller);
}

static void
gpartsui_database_controller_disconnect_action_cb(GtkAction *action, GPartsUIDatabaseController *controller)
{
    gpartsui_database_controller_disconnect_database(controller);
}

void
gpartsui_database_controller_disconnect_database(GPartsUIDatabaseController *controller)
{
    gpartsui_database_controller_set_database(controller, NULL);
}

static void
gpartsui_database_controller_connected_cb(GPartsDatabase *database, GPartsUIDatabaseController *database_controller)
{
}

static void
gpartsui_database_controller_disconnected_cb(GPartsDatabase *database, GPartsUIDatabaseController *database_controller)
{
}

static void
gpartsui_database_controller_dispose(GObject *object)
{
    gpartsui_database_controller_set_database(GPARTSUI_DATABASE_CONTROLLER(object), NULL);

    gpartsui_database_controller_set_connect_action(GPARTSUI_DATABASE_CONTROLLER(object), NULL);
    gpartsui_database_controller_set_disconnect_action(GPARTSUI_DATABASE_CONTROLLER(object), NULL);
    gpartsui_database_controller_set_drop_action(GPARTSUI_DATABASE_CONTROLLER(object), NULL);
    gpartsui_database_controller_set_refresh_action(GPARTSUI_DATABASE_CONTROLLER(object), NULL);

    misc_object_chain_dispose(object);
}

static void
gpartsui_database_controller_drop_action_cb(GtkAction *action, GPartsUIDatabaseController *controller)
{
    gpartsui_database_controller_drop_database(controller);
}

void
gpartsui_database_controller_drop_database(GPartsUIDatabaseController *controller)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

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
gpartsui_database_controller_finalize(GObject *object)
{
    GPartsUIDatabaseControllerPrivate *private = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(object);

    misc_object_chain_finalize(object);
}

/*! \brief Gets the GType of the GPartsUIDatabaseController class.
 *
 *  \return The GType of the GPartsUIDatabaseController class.
 */
GType
gpartsui_database_controller_get_type(void)
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsUIDatabaseControllerClass),
            NULL,
            NULL,
            gpartsui_database_controller_class_init,
            NULL,
            NULL,
            sizeof(GPartsUIDatabaseController),
            0,
            gpartsui_database_controller_instance_init,
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
gpartsui_database_controller_get_database(GPartsUIDatabaseController *database_controller)
{
    GPartsDatabase *database = NULL;
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(database_controller);

    if (privat != NULL)
    {
        database = privat->database;
    }

    return database;
}

static void
gpartsui_database_controller_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(object);

    switch (property_id)
    {
        case GPARTSUI_DATABASE_CONTROLLER_PROPID_CONNECT_ACTION:
            g_value_set_object(value, privat->connect_action);
            break;

        case GPARTSUI_DATABASE_CONTROLLER_PROPID_DATABASE:
            g_value_set_object(value, gpartsui_database_controller_get_database(GPARTSUI_DATABASE_CONTROLLER(object)));
            break;

        case GPARTSUI_DATABASE_CONTROLLER_PROPID_DISCONNECT_ACTION:
            g_value_set_object(value, privat->disconnect_action);
            break;

        case GPARTSUI_DATABASE_CONTROLLER_PROPID_REFRESH_ACTION:
            g_value_set_object(value, privat->refresh_action);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
gpartsui_database_controller_instance_init(GTypeInstance *instance, gpointer g_class)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(instance);

    GPartsConnectData connect_data;

    privat->ctrl = gparts_connect_controller_new();

    g_signal_connect(
        privat->ctrl,
        "notify::connect-data",
        G_CALLBACK(gpartsui_database_controller_connect_data_changed_cb),
        instance
        );

    g_signal_connect(
        privat->ctrl,
        "notify::database-type",
        G_CALLBACK(gpartsui_database_controller_database_type_changed_cb),
        instance
        );

    connect_data.hostname = "localhost"; /* g_get_host_name(); */
    connect_data.username = g_get_user_name();
    connect_data.password = NULL;
    connect_data.database = "GParts";
    connect_data.filename = NULL;

    gparts_connect_controller_set_connect_data(privat->ctrl, &connect_data);

    {
        GPartsConfig *config = gparts_config_new();

        privat->database_type = gparts_config_get_database_types(config);
    }

    /** TODO Move elsewhere */

    //gpartsui_database_type_load_module(privat->database_type, "libgparts-mysql.la", NULL);
    //gpartsui_database_type_load_module(privat->database_type, "libgparts-sqlite.la", NULL);

    /* TODO Test code / Remove before flight */

//    gpartsui_database_type_add_type(
//        privat->database_type,
//        "PostgreSQL",
//        G_TYPE_INVALID,
//        GPARTSUI_DATABASE_TYPE_FLAGS_USES_USERNAME
//        );

//    gpartsui_database_type_add_type(
//        privat->database_type,
//        "SQLite",
//        G_TYPE_INVALID,
//        GPARTSUI_DATABASE_TYPE_FLAGS_USES_FILENAME
//        );
}

static void
gpartsui_database_controller_refresh_action_cb(GtkAction *action, GPartsUIDatabaseController *database_controller)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(database_controller);

    if (privat != NULL && privat->database != NULL)
    {
        g_signal_emit_by_name(database_controller, "refresh");
    }
}

void
gpartsui_database_controller_set_connect_action(GPartsUIDatabaseController *database_controller, GtkAction *action)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(database_controller);

    if (privat->connect_action != action)
    {
        if (privat->connect_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->connect_action,
                G_CALLBACK(gpartsui_database_controller_connect_action_cb),
                database_controller
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
                G_CALLBACK(gpartsui_database_controller_connect_action_cb),
                database_controller
                );
        }

        g_object_notify(G_OBJECT(database_controller), "connect-action");
    }
}

void
gpartsui_database_controller_set_disconnect_action(GPartsUIDatabaseController *database_controller, GtkAction *action)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(database_controller);

    if (privat->disconnect_action != action)
    {
        if (privat->disconnect_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->disconnect_action,
                G_CALLBACK(gpartsui_database_controller_disconnect_action_cb),
                database_controller
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
                G_CALLBACK(gpartsui_database_controller_disconnect_action_cb),
                database_controller
                );

            //gtk_action_set_sensitive(privat->disconnect_action, (privat->database != NULL));
            gtk_action_set_sensitive(privat->disconnect_action, TRUE);
        }

        g_object_notify(G_OBJECT(database_controller), "disconnect-action");
    }
}

static void
gpartsui_database_controller_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsUIDatabaseController *controller = GPARTSUI_DATABASE_CONTROLLER(object);

    switch (property_id)
    {
        case GPARTSUI_DATABASE_CONTROLLER_PROPID_CONNECT_ACTION:
            gpartsui_database_controller_set_connect_action(controller, GTK_ACTION(g_value_get_object(value)));
            break;

        case GPARTSUI_DATABASE_CONTROLLER_PROPID_DISCONNECT_ACTION:
            gpartsui_database_controller_set_disconnect_action(controller, GTK_ACTION(g_value_get_object(value)));
            break;

        case GPARTSUI_DATABASE_CONTROLLER_PROPID_DROP_ACTION:
            gpartsui_database_controller_set_drop_action(controller, GTK_ACTION(g_value_get_object(value)));
            break;

        case GPARTSUI_DATABASE_CONTROLLER_PROPID_REFRESH_ACTION:
            gpartsui_database_controller_set_refresh_action(controller, GTK_ACTION(g_value_get_object(value)));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
gpartsui_database_controller_set_database(GPartsUIDatabaseController *ctrl, GPartsDatabase *database)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(ctrl);

    if (privat->database != database)
    {
        if (privat->database != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gpartsui_database_controller_connected_cb),
                ctrl
                );

            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gpartsui_database_controller_disconnected_cb),
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
                G_CALLBACK(gpartsui_database_controller_connected_cb),
                ctrl
                );

            g_signal_connect(
                privat->database,
                "database-disconnected",
                G_CALLBACK(gpartsui_database_controller_disconnected_cb),
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
gpartsui_database_controller_set_drop_action(GPartsUIDatabaseController *database_controller, GtkAction *action)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(database_controller);

    if (privat != NULL)
    {
        if (privat->drop_action != action)
        {
            if (privat->drop_action != NULL)
            {
                g_signal_handlers_disconnect_by_func(
                    privat->drop_action,
                    G_CALLBACK(gpartsui_database_controller_drop_action_cb),
                    database_controller
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
                    G_CALLBACK(gpartsui_database_controller_drop_action_cb),
                    database_controller
                    );

                if (privat->database != NULL)
                {
                    gtk_action_set_sensitive(privat->drop_action, gparts_database_droppable(privat->database));
                }
                else
                {
                    gtk_action_set_sensitive(privat->drop_action, FALSE);
                }
            }

            g_object_notify(G_OBJECT(database_controller), "drop-action");
        }
    }
}

void
gpartsui_database_controller_set_refresh_action(GPartsUIDatabaseController *ctrl, GtkAction *action)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(ctrl);

    if (privat->refresh_action != action)
    {
        if (privat->refresh_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->refresh_action,
                G_CALLBACK(gpartsui_database_controller_refresh_action_cb),
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
                G_CALLBACK(gpartsui_database_controller_refresh_action_cb),
                ctrl
                );

            gtk_action_set_sensitive(privat->refresh_action, (privat->database != NULL));
        }

        g_object_notify(G_OBJECT(ctrl), "refresh-action");
    }
}

static void
gpartsui_database_controller_update_flags(GPartsUIDatabaseController *controller)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        GPartsDatabaseFactory *factory = NULL;
        gint flags = 0;

        if (privat->database_type != NULL)
        {
            gchar *name = gparts_connect_controller_get_database_type(privat->ctrl);

            factory = gparts_database_type_get_factory(privat->database_type, name);
            g_free(name);
        }

        if (factory != NULL)
        {
            GPartsConnectData *data = gparts_connect_controller_get_connect_data(privat->ctrl);

            flags = gparts_database_factory_get_flags(factory);
            gparts_connect_data_free(data);

            g_object_unref(factory);
        }

        gparts_connect_controller_set_flags(privat->ctrl, flags);
    }
}

static void
gpartsui_database_controller_update_valid(GPartsUIDatabaseController *controller)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        GPartsDatabaseFactory *factory = NULL;
        gboolean valid = FALSE;

        if (privat->database_type != NULL)
        {
            gchar *name = gparts_connect_controller_get_database_type(privat->ctrl);

            factory = gparts_database_type_get_factory(privat->database_type, name);
            g_free(name);
        }

        if (factory != NULL)
        {
            GPartsConnectData *data = gparts_connect_controller_get_connect_data(privat->ctrl);

            valid = gparts_database_factory_validate_connect_data(factory, data);
            gparts_connect_data_free(data);

            g_object_unref(factory);
        }

        gparts_connect_controller_set_valid(privat->ctrl, valid);
    }
}

