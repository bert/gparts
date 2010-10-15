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
    GPARTSUI_DATABASE_CONTROLLER_PROPID_DATABASE_MODEL = 1,

    GPARTSUI_DATABASE_CONTROLLER_PROPID_DISCONNECT_ACTION,
    GPARTSUI_DATABASE_CONTROLLER_PROPID_DROP_ACTION,
    GPARTSUI_DATABASE_CONTROLLER_PROPID_REFRESH_ACTION
};

typedef struct _GPartsUIDatabaseControllerPrivate GPartsUIDatabaseControllerPrivate;

struct _GPartsUIDatabaseControllerPrivate
{
    GPartsUIDatabaseModel *database_model;

    GtkAction             *disconnect_action;
    GtkAction             *drop_action;
    GtkAction             *refresh_action;
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
gpartsui_database_controller_all_notify_cb(GPartsUIDatabaseModel *model, GParamSpec *param, GPartsUIDatabaseController *controller);

static void
gpartsui_database_controller_disconnect_action_cb(GtkAction *action, GPartsUIDatabaseController *controller);

static void
gpartsui_database_controller_drop_action_cb(GtkAction *action, GPartsUIDatabaseController *controller);

static void
gpartsui_database_controller_refresh_action_cb(GtkAction *action, GPartsUIDatabaseController *controller);

static void
gpartsui_database_controller_update_all_actions(GPartsUIDatabaseController *controller);



static void
gpartsui_database_controller_all_notify_cb(GPartsUIDatabaseModel *model, GParamSpec *param, GPartsUIDatabaseController *controller)
{
    gpartsui_database_controller_update_all_actions(controller);
}

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
        GPARTSUI_DATABASE_CONTROLLER_PROPID_DATABASE_MODEL,
        g_param_spec_object(
            "database-model",
            "Database Model",
            "Database Model",
            GPARTSUI_TYPE_DATABASE_MODEL,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTSUI_DATABASE_CONTROLLER_PROPID_DISCONNECT_ACTION,
        g_param_spec_object(
            "disconnect-action",
            "Disconnect Action",
            "Disconnect Action",
            GTK_TYPE_ACTION,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTSUI_DATABASE_CONTROLLER_PROPID_DROP_ACTION,
        g_param_spec_object(
            "drop-action",
            "Drop Action",
            "Drop Action",
            GTK_TYPE_ACTION,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
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
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

void
gpartsui_database_controller_disconnect(GPartsUIDatabaseController *controller)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if ((privat != NULL) && (privat->database_model != NULL))
    {
        GError *error = NULL;

        gpartsui_database_model_disconnect(privat->database_model, &error);

        if (error != NULL)
        {
            GtkWidget *error_dialog = gtk_message_dialog_new(
                NULL,
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

static void
gpartsui_database_controller_disconnect_action_cb(GtkAction *action, GPartsUIDatabaseController *controller)
{
    gpartsui_database_controller_disconnect(controller);
}

static void
gpartsui_database_controller_dispose(GObject *object)
{
    GPartsUIDatabaseController *controller = GPARTSUI_DATABASE_CONTROLLER(object);

    if (controller != NULL)
    {
        gpartsui_database_controller_set_database_model(controller, NULL);

        gpartsui_database_controller_set_disconnect_action(controller, NULL);
        gpartsui_database_controller_set_drop_action(controller, NULL);
        gpartsui_database_controller_set_refresh_action(controller, NULL);
    }

    misc_object_chain_dispose(object);
}

void
gpartsui_database_controller_drop(GPartsUIDatabaseController *controller)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if ((privat != NULL) && (privat->database_model != NULL))
    {
        GError *error = NULL;

        gpartsui_database_model_drop(privat->database_model, &error);

        if (error != NULL)
        {
            GtkWidget *error_dialog = gtk_message_dialog_new(
                NULL,
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

static void
gpartsui_database_controller_drop_action_cb(GtkAction *action, GPartsUIDatabaseController *controller)
{
    gpartsui_database_controller_drop(controller);
}

static void
gpartsui_database_controller_finalize(GObject *object)
{
    GPartsUIDatabaseControllerPrivate *private = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(object);

    misc_object_chain_finalize(object);
}

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
            "gpartsui-database-controller",
            &tinfo,
            0
            );
    }

    return type;
}

GPartsUIDatabaseModel*
gpartsui_database_controller_get_database_model(GPartsUIDatabaseController *controller)
{
    GPartsUIDatabaseModel *database_model = NULL;
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        database_model = privat->database_model;
    }

    return database_model;
}

static void
gpartsui_database_controller_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(object);

    switch (property_id)
    {
        case GPARTSUI_DATABASE_CONTROLLER_PROPID_DATABASE_MODEL:
            g_value_set_object(value, gpartsui_database_controller_get_database_model(GPARTSUI_DATABASE_CONTROLLER(object)));
            break;

        case GPARTSUI_DATABASE_CONTROLLER_PROPID_DISCONNECT_ACTION:
            g_value_set_object(value, privat->disconnect_action);
            break;

        case GPARTSUI_DATABASE_CONTROLLER_PROPID_DROP_ACTION:
            g_value_set_object(value, privat->drop_action);
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
}

void
gpartsui_database_controller_refresh(GPartsUIDatabaseController *controller)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        gpartsui_database_model_refresh(privat->database_model);
    }
}

static void
gpartsui_database_controller_refresh_action_cb(GtkAction *action, GPartsUIDatabaseController *controller)
{
    gpartsui_database_controller_refresh(controller);
}

void
gpartsui_database_controller_set_disconnect_action(GPartsUIDatabaseController *controller, GtkAction *action)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat->disconnect_action != action)
    {
        if (privat->disconnect_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->disconnect_action,
                G_CALLBACK(gpartsui_database_controller_disconnect_action_cb),
                controller
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
                controller
                );

            gtk_action_set_sensitive(
                privat->disconnect_action,
                gpartsui_database_model_get_disconnect_sensitive(privat->database_model)
                );
        }

        g_object_notify(G_OBJECT(controller), "disconnect-action");
    }
}

static void
gpartsui_database_controller_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsUIDatabaseController *controller = GPARTSUI_DATABASE_CONTROLLER(object);

    switch (property_id)
    {
        case GPARTSUI_DATABASE_CONTROLLER_PROPID_DATABASE_MODEL:
            gpartsui_database_controller_set_database_model(controller, GPARTSUI_DATABASE_MODEL(g_value_get_object(value)));
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

void
gpartsui_database_controller_set_database_model(GPartsUIDatabaseController *controller, GPartsUIDatabaseModel *model)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->database_model != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database_model,
                G_CALLBACK(gpartsui_database_controller_all_notify_cb),
                controller
                );

            g_object_unref(privat->database_model);
        }

        privat->database_model = model;

        if (privat->database_model != NULL)
        {
            g_object_ref(privat->database_model);

            g_signal_connect(
                privat->database_model,
                "notify",
                G_CALLBACK(gpartsui_database_controller_all_notify_cb),
                controller
                );
        }

        gpartsui_database_controller_update_all_actions(controller);

        g_object_notify(G_OBJECT(controller), "database-model");
    }
}

void
gpartsui_database_controller_set_drop_action(GPartsUIDatabaseController *controller, GtkAction *action)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->drop_action != action)
        {
            if (privat->drop_action != NULL)
            {
                g_signal_handlers_disconnect_by_func(
                    privat->drop_action,
                    G_CALLBACK(gpartsui_database_controller_drop_action_cb),
                    controller
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
                    controller
                    );

            gtk_action_set_sensitive(
                privat->drop_action,
                gpartsui_database_model_get_drop_sensitive(privat->database_model)
                );
            }

            g_object_notify(G_OBJECT(controller), "drop-action");
        }
    }
}

void
gpartsui_database_controller_set_refresh_action(GPartsUIDatabaseController *controller, GtkAction *action)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat->refresh_action != action)
    {
        if (privat->refresh_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->refresh_action,
                G_CALLBACK(gpartsui_database_controller_refresh_action_cb),
                controller
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
                controller
                );

            gtk_action_set_sensitive(
                privat->refresh_action,
                gpartsui_database_model_get_refresh_sensitive(privat->database_model)
                );
        }

        g_object_notify(G_OBJECT(controller), "refresh-action");
    }
}

static void
gpartsui_database_controller_update_all_actions(GPartsUIDatabaseController *controller)
{
    GPartsUIDatabaseControllerPrivate *privat = GPARTSUI_DATABASE_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->disconnect_action != NULL)
        {
            gtk_action_set_sensitive(
                privat->disconnect_action,
                gpartsui_database_model_get_disconnect_sensitive(privat->database_model)
                );
        }

        if (privat->drop_action != NULL)
        {
            gtk_action_set_sensitive(
                privat->drop_action,
                gpartsui_database_model_get_drop_sensitive(privat->database_model)
                );
        }

        if (privat->refresh_action != NULL)
        {
            gtk_action_set_sensitive(
                privat->refresh_action,
                gpartsui_database_model_get_refresh_sensitive(privat->database_model)
                );
        }
    }
}

