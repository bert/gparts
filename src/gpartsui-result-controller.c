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

/*! \file gpartsui-result-controller.c
 */

#include "gpartsui.h"

#define GPARTSUI_RESULT_CONTROLLER_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTSUI_TYPE_RESULT_CONTROLLER,GPartsUIResultControllerPrivate)

enum
{
    GPARTSUI_RESULT_CONTROLLER_MODEL = 1,
    GPARTSUI_RESULT_CONTROLLER_VIEW,
};

typedef struct _GPartsUIResultControllerPrivate GPartsUIResultControllerPrivate;

struct _GPartsUIResultControllerPrivate
{
    GPartsUIResultModel *model;
    GtkTreeSelection    *selection;
    GtkTreeView         *view;
};


static void
gpartsui_result_controller_class_init(gpointer g_class, gpointer g_class_data);

static void
gpartsui_result_controller_dispose(GObject *object);

static void
gpartsui_result_controller_finalize(GObject *object);

static void
gpartsui_result_controller_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpartsui_result_controller_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gpartsui_result_controller_update_result(GPartsUIResultController *controller);

/**** Signal handlers ****/

static void
gpartsui_result_controller_changed_cb(GtkTreeSelection *selection, GPartsResultController *controller);

static void
gpartsui_result_controller_notify_result_cb(GPartsUIResultModel *model, GParamSpec *param, GPartsUIResultController *controller);



static void
gpartsui_result_controller_changed_cb(GtkTreeSelection *selection, GPartsResultController *controller)
{
    GPartsUIResultControllerPrivate *privat = GPARTSUI_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        GtkTreeIter iter;
        gboolean    success;

        success = gtk_tree_selection_get_selected(privat->selection, NULL, &iter);

        if (success)
        {
            /*! \todo Move iter row extraction somewhere else */

            gpartsui_result_model_set_selected_row(privat->model, GPOINTER_TO_UINT(iter.user_data));
        }
        else
        {
            gpartsui_result_model_set_selected_row(privat->model, G_MAXUINT);
        }
    }
}

static void
gpartsui_result_controller_class_init(gpointer g_class, gpointer g_class_data)
{
    GPartsUIResultControllerClass *klasse = GPARTSUI_RESULT_CONTROLLER_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsUIResultControllerPrivate));

    klasse->parent.dispose  = gpartsui_result_controller_dispose;
    klasse->parent.finalize = gpartsui_result_controller_finalize;

    klasse->parent.get_property = gpartsui_result_controller_get_property;
    klasse->parent.set_property = gpartsui_result_controller_set_property;

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        GPARTSUI_RESULT_CONTROLLER_MODEL,
        g_param_spec_object(
            "model",
            "Model",
            "Model",
            GPARTSUI_TYPE_RESULT_MODEL,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        GPARTSUI_RESULT_CONTROLLER_VIEW,
        g_param_spec_object(
            "view",
            "View",
            "View",
            GTK_TYPE_TREE_VIEW,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpartsui_result_controller_dispose(GObject *object)
{
    GPartsUIResultController *controller = GPARTSUI_RESULT_CONTROLLER(object);

    gpartsui_result_controller_set_model(controller, NULL);
    gpartsui_result_controller_set_view(controller, NULL);

    misc_object_chain_dispose(object);
}

static void
gpartsui_result_controller_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

GPartsUIResultModel*
gpartsui_result_controller_get_model(const GPartsUIResultController *controller)
{
    GPartsUIResultModel *model = NULL;
    GPartsUIResultControllerPrivate *privat = GPARTSUI_RESULT_CONTROLLER_GET_PRIVATE(controller);

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

GtkTreeView*
gpartsui_result_controller_get_view(const GPartsUIResultController *controller)
{
    GtkTreeView *view = NULL;
    GPartsUIResultControllerPrivate *privat = GPARTSUI_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        view = privat->view;

        if (view != NULL)
        {
            g_object_ref(view);
        }
    }

    return view;
}

static void
gpartsui_result_controller_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsUIResultController *controller = GPARTSUI_RESULT_CONTROLLER(object);

    switch (property_id)
    {
        case GPARTSUI_RESULT_CONTROLLER_MODEL:
            g_value_take_object(value, gpartsui_result_controller_get_model(controller));
            break;

        case GPARTSUI_RESULT_CONTROLLER_VIEW:
            g_value_take_object(value, gpartsui_result_controller_get_view(controller));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
gpartsui_result_controller_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsUIResultControllerClass),    /* class_size */
            NULL,                                     /* base_init */
            NULL,                                     /* base_finalize */
            gpartsui_result_controller_class_init,    /* class_init */
            NULL,                                     /* class_finalize */
            NULL,                                     /* class_data */
            sizeof(GPartsUIResultController),         /* instance_size */
            0,                                        /* n_preallocs */
            NULL,                                     /* instance_init */
            NULL                                      /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPartsUIResultController",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gpartsui_result_controller_notify_result_cb(GPartsUIResultModel *model, GParamSpec *param, GPartsUIResultController *controller)
{
    gpartsui_result_controller_update_result(controller);
}



void
gpartsui_result_controller_set_model(GPartsUIResultController *controller, GPartsUIResultModel *model)
{
    GPartsUIResultControllerPrivate *privat = GPARTSUI_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->model != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->model,
                G_CALLBACK(gpartsui_result_controller_notify_result_cb),
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
                "notify::result",
                G_CALLBACK(gpartsui_result_controller_notify_result_cb),
                controller
                );
        }

        gpartsui_result_controller_update_result(controller);

        g_object_notify(G_OBJECT(controller), "model");
    }
}

static void
gpartsui_result_controller_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsUIResultController *controller = GPARTSUI_RESULT_CONTROLLER(object);

    switch (property_id)
    {
        case GPARTSUI_RESULT_CONTROLLER_MODEL:
            gpartsui_result_controller_set_model(controller, GPARTSUI_RESULT_MODEL(g_value_get_object(value)));
            break;

        case GPARTSUI_RESULT_CONTROLLER_VIEW:
            gpartsui_result_controller_set_view(controller, GTK_TREE_VIEW(g_value_get_object(value)));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
gpartsui_result_controller_set_view(GPartsUIResultController *controller, GtkTreeView *view)
{
    GPartsUIResultControllerPrivate *privat = GPARTSUI_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->selection != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->selection,
                G_CALLBACK(gpartsui_result_controller_changed_cb),
                controller
                );

            g_object_unref(privat->selection);
        }

        if (privat->view != NULL)
        {
            g_object_unref(privat->view);
        }

        privat->selection = NULL;
        privat->view      = view;

        if (privat->view != NULL)
        {
            g_object_ref(privat->view);

            privat->selection = gtk_tree_view_get_selection(privat->view);
        }

        if (privat->selection != NULL)
        {
            g_object_ref(privat->selection);

            g_signal_connect(
                privat->selection,
                "changed",
                G_CALLBACK(gpartsui_result_controller_changed_cb),
                controller
                );
        }

        gpartsui_result_controller_update_result(controller);

        g_object_notify(G_OBJECT(controller), "view");
    }
}

static void
gpartsui_result_controller_update_result(GPartsUIResultController *controller)
{
    GPartsUIResultControllerPrivate *privat = GPARTSUI_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->view != NULL)
        {
            GtkTreeModel *adapter = NULL;
            GPartsDatabaseResult *result = gpartsui_result_model_get_result(privat->model);

            if (result != NULL)
            {
                adapter = GTK_TREE_MODEL(gparts_result_model_new(result));

                gparts_result_model_set_columns(result, privat->view);

                g_object_unref(result);
            }

            gtk_tree_view_set_model(privat->view, adapter);

            if (adapter != NULL)
            {
                g_object_unref(adapter);
            }
        }
    }
}

