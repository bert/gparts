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

/*! \file miscui-action-controller.c
 */

#include "miscui.h"

#define MISCUI_ACTION_CONTROLLER_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,MISCUI_TYPE_ACTION_CONTROLLER,MiscUIActionControllerPrivate)

enum
{
    MISCUI_ACTION_CONTROLLER_ACTION = 1,
    MISCUI_ACTION_CONTROLLER_MODEL
};

typedef struct _MiscUIActionControllerPrivate MiscUIActionControllerPrivate;

struct _MiscUIActionControllerPrivate
{
    GtkAction         *action;
    MiscUIActionModel *model;
};


static void
miscui_action_controller_class_init(gpointer g_class, gpointer g_class_data);

static void
miscui_action_controller_dispose(GObject *object);

static void
miscui_action_controller_finalize(GObject *object);

static void
miscui_action_controller_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
miscui_action_controller_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
miscui_action_controller_update_label(MiscUIActionController *controller);

static void
miscui_action_controller_update_sensitive(MiscUIActionController *controller);

/**** Signal handlers ****/

static void
miscui_action_controller_activate_cb(GtkAction *action, MiscUIActionController *controller);

static void
miscui_action_controller_notify_label_cb(MiscUIActionModel *model, GParamSpec *param, MiscUIActionController *controller);

static void
miscui_action_controller_notify_sensitive_cb(MiscUIActionModel *model, GParamSpec *param, MiscUIActionController *controller);



static void
miscui_action_controller_activate_cb(GtkAction *action, MiscUIActionController *controller)
{
    MiscUIActionControllerPrivate *privat = MISCUI_ACTION_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        GError *error = NULL;

        miscui_action_model_activate(privat->model, &error);

        if (error != NULL)
        {
            /*! \todo Provide a parent widget */

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
miscui_action_controller_class_init(gpointer g_class, gpointer g_class_data)
{
    MiscUIActionControllerClass *klasse = MISCUI_ACTION_CONTROLLER_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(MiscUIActionControllerPrivate));

    klasse->parent.dispose  = miscui_action_controller_dispose;
    klasse->parent.finalize = miscui_action_controller_finalize;

    klasse->parent.get_property = miscui_action_controller_get_property;
    klasse->parent.set_property = miscui_action_controller_set_property;

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        MISCUI_ACTION_CONTROLLER_ACTION,
        g_param_spec_object(
            "action",
            "Action",
            "Action",
            GTK_TYPE_ACTION,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        MISCUI_ACTION_CONTROLLER_MODEL,
        g_param_spec_object(
            "model",
            "Model",
            "Model",
            MISCUI_TYPE_ACTION_MODEL,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
miscui_action_controller_dispose(GObject *object)
{
    MiscUIActionController *controller = MISCUI_ACTION_CONTROLLER(object);

    miscui_action_controller_set_action(controller, NULL);
    miscui_action_controller_set_model(controller, NULL);

    misc_object_chain_dispose(object);
}

static void
miscui_action_controller_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

GtkAction*
miscui_action_controller_get_action(const MiscUIActionController *controller)
{
    GtkAction *action = NULL;
    MiscUIActionControllerPrivate *privat = MISCUI_ACTION_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        action = privat->action;

        if (action != NULL)
        {
            g_object_ref(action);
        }
    }

    return action;
}

MiscUIActionModel*
miscui_action_controller_get_model(const MiscUIActionController *controller)
{
    MiscUIActionModel *model = NULL;
    MiscUIActionControllerPrivate *privat = MISCUI_ACTION_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        model = privat->model;

        if (model != NULL)
        {
            g_object_ref(model);
        }
    }

    return model;
}

static void
miscui_action_controller_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    MiscUIActionController *controller = MISCUI_ACTION_CONTROLLER(object);

    switch (property_id)
    {
        case MISCUI_ACTION_CONTROLLER_ACTION:
            g_value_take_object(value, miscui_action_controller_get_action(controller));
            break;

        case MISCUI_ACTION_CONTROLLER_MODEL:
            g_value_take_object(value, miscui_action_controller_get_model(controller));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
miscui_action_controller_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(MiscUIActionControllerClass),    /* class_size */
            NULL,                                   /* base_init */
            NULL,                                   /* base_finalize */
            miscui_action_controller_class_init,    /* class_init */
            NULL,                                   /* class_finalize */
            NULL,                                   /* class_data */
            sizeof(MiscUIActionController),         /* instance_size */
            0,                                      /* n_preallocs */
            NULL,                                   /* instance_init */
            NULL                                    /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "MiscUIActionController",
            &tinfo,
            0
            );
    }

    return type;
}

static void
miscui_action_controller_notify_label_cb(MiscUIActionModel *model, GParamSpec *param, MiscUIActionController *controller)
{
    miscui_action_controller_update_label(controller);
}

static void
miscui_action_controller_notify_sensitive_cb(MiscUIActionModel *model, GParamSpec *param, MiscUIActionController *controller)
{
    miscui_action_controller_update_sensitive(controller);
}

void
miscui_action_controller_set_action(MiscUIActionController *controller, GtkAction *action)
{
    MiscUIActionControllerPrivate *privat = MISCUI_ACTION_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->action,
                G_CALLBACK(miscui_action_controller_activate_cb),
                controller
                );

            g_object_unref(privat->action);
        }

        privat->action = action;

        if (privat->action != NULL)
        {
            g_object_ref(privat->action);

            g_signal_connect(
                privat->action,
                "activate",
                G_CALLBACK(miscui_action_controller_activate_cb),
                controller
                );
        }

        miscui_action_controller_update_label(controller);
        miscui_action_controller_update_sensitive(controller);

        g_object_notify(G_OBJECT(controller), "action");
    }
}

void
miscui_action_controller_set_model(MiscUIActionController *controller, MiscUIActionModel *model)
{
    MiscUIActionControllerPrivate *privat = MISCUI_ACTION_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->model != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->model,
                G_CALLBACK(miscui_action_controller_notify_label_cb),
                controller
                );

            g_signal_handlers_disconnect_by_func(
                privat->model,
                G_CALLBACK(miscui_action_controller_notify_sensitive_cb),
                controller
                );

            g_object_unref(privat->model);
        }

        privat->model = model;

        if (privat->model != NULL)
        {
            g_object_ref(privat->model);

            g_signal_connect(
                privat->model,
                "notify::label",
                G_CALLBACK(miscui_action_controller_notify_label_cb),
                controller
                );

            g_signal_connect(
                privat->model,
                "notify::sensitive",
                G_CALLBACK(miscui_action_controller_notify_sensitive_cb),
                controller
                );
        }

        miscui_action_controller_update_label(controller);
        miscui_action_controller_update_sensitive(controller);

        g_object_notify(G_OBJECT(controller), "model");
    }
}

static void
miscui_action_controller_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    MiscUIActionController *controller = MISCUI_ACTION_CONTROLLER(object);

    switch (property_id)
    {
        case MISCUI_ACTION_CONTROLLER_ACTION:
            miscui_action_controller_set_action(controller, GTK_ACTION(g_value_get_object(value)));
            break;

        case MISCUI_ACTION_CONTROLLER_MODEL:
            miscui_action_controller_set_model(controller, MISCUI_ACTION_MODEL(g_value_get_object(value)));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
miscui_action_controller_update_label(MiscUIActionController *controller)
{
    MiscUIActionControllerPrivate *privat = MISCUI_ACTION_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->action != NULL)
        {
            gchar *label = miscui_action_model_get_label(privat->model);

            if (label != NULL)
            {
                gtk_action_set_label(
                    privat->action,
                    label
                    );

                g_free(label);
            }
            else
            {
                /*! \todo Provide some default label */
            }
        }
    }
}

static void
miscui_action_controller_update_sensitive(MiscUIActionController *controller)
{
    MiscUIActionControllerPrivate *privat = MISCUI_ACTION_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->action != NULL)
        {
            gboolean sensitive = miscui_action_model_get_sensitive(privat->model);

            gtk_action_set_sensitive(
                privat->action,
                sensitive
                );
        }
    }
}

