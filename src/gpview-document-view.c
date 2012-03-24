/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2012 Edward C. Hennessy
 * Copyright (C) 2012 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpview-company-view.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "sch.h"
#include "gparts.h"
#include "gpform.h"
#include "gpview.h"

#define GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPVIEW_TYPE_DOCUMENT_VIEW,GPViewDocumentViewPrivate))

enum
{
    GPVIEW_DOCUMENT_VIEW_DOCUMENT_ID = 1,
    GPVIEW_DOCUMENT_VIEW_CONTROLLER,
    GPVIEW_DOCUMENT_VIEW_DATABASE,
    GPVIEW_DOCUMENT_VIEW_RESULT,
    GPVIEW_DOCUMENT_VIEW_WEBSITES
};

typedef struct _GPViewDocumentViewPrivate GPViewDocumentViewPrivate;

struct _GPViewDocumentViewPrivate
{
    GPViewResultAdapter  *adapter;
    GPViewDocumentCtrl   *controller;
    GPartsDatabase       *database;
    GPartsDatabaseResult *result;
    GtkTreeSelection     *selection;
    GtkTreeView          *tree_view;
};

static void
gpview_document_view_activate(GPViewViewInterface *widget);

static void
gpview_document_view_changed_cb(GtkTreeSelection *selection, GPViewDocumentView *view);

static void
gpview_document_view_class_init(gpointer g_class, gpointer g_class_data);

static void
gpview_document_view_deactivate(GPViewViewInterface *widget);

static void
gpview_document_view_dispose(GObject *object);

static void
gpview_document_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpview_document_view_init(GTypeInstance *instance, gpointer g_class);

static void
gpview_document_view_init_view_interface(gpointer iface, gpointer user_data);

static void
gpview_document_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gpview_document_view_set_result(GPViewDocumentView *view, GPartsDatabaseResult *result);

static void
gpview_document_view_update_cb(GObject *unused, GParamSpec *pspec, GPViewDocumentView *view);



static void
gpview_document_view_activate(GPViewViewInterface *widget)
{
    GPViewDocumentView *view = GPVIEW_DOCUMENT_VIEW(widget);

    if (view == NULL)
    {
        g_critical("Unable to obatain an instance from GPViewViewInterface");
    }
    else
    {
        GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(view);

        if (privat == NULL)
        {
            g_critical("Unable to obtain private data for a GPViewDocumentView");
        }
        else if (privat->controller == NULL)
        {
            g_critical("GPViewDocumentView has a NULL controller");
        }
        else
        {
            gpview_document_ctrl_set_current_view(privat->controller, view);
        }
    }
}

static void
gpview_document_view_changed_cb(GtkTreeSelection *selection, GPViewDocumentView *view)
{
    if (view != NULL)
    {
        g_object_notify(G_OBJECT(view), "company-id");
        g_object_notify(G_OBJECT(view), "websites");
    }
}

static void
gpview_document_view_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPViewDocumentViewPrivate));

    klasse->dispose = gpview_document_view_dispose;

    klasse->get_property = gpview_document_view_get_property;
    klasse->set_property = gpview_document_view_set_property;

    g_object_class_install_property(
        klasse,
        GPVIEW_DOCUMENT_VIEW_DOCUMENT_ID,
        g_param_spec_string(
            "company-id",
            "Company ID",
            "Company ID",
            NULL,
            G_PARAM_LAX_VALIDATION | G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPVIEW_DOCUMENT_VIEW_CONTROLLER,
        g_param_spec_object(
            "controller",
            "Controller",
            "Controller",
            GPVIEW_TYPE_DOCUMENT_CTRL,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPVIEW_DOCUMENT_VIEW_DATABASE,
        g_param_spec_object(
            "database",
            "Database",
            "Database",
            GPARTS_TYPE_DATABASE,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPVIEW_DOCUMENT_VIEW_RESULT,
        g_param_spec_object(
            "result",
            "Database Result",
            "Database Result",
            GPARTS_TYPE_DATABASE_RESULT,
            G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPVIEW_DOCUMENT_VIEW_WEBSITES,
        g_param_spec_string(
            "websites",
            "Websites",
            "Websites",
            NULL,
            G_PARAM_LAX_VALIDATION | G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpview_document_view_deactivate(GPViewViewInterface *widget)
{
    GPViewDocumentView *view = GPVIEW_DOCUMENT_VIEW(widget);

    if (view == NULL)
    {
        g_critical("Unable to obatain an instance from GPViewViewInterface");
    }
    else
    {
        GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(view);

        if (privat == NULL)
        {
            g_critical("Unable to obtain private data for a GPViewDocumentView");
        }
        else if (privat->controller == NULL)
        {
            g_critical("GPViewDocumentView has a NULL controller");
        }
        else
        {
            gpview_document_ctrl_set_current_view(privat->controller, NULL);
        }
    }
}


static void
gpview_document_view_dispose(GObject *object)
{
    GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(object);

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_object_unref(privat->database);
        }
    }

    misc_object_chain_dispose(object);
}

GStrv
gpview_document_view_get_ids(const GPViewDocumentView *view)
{
    GStrv ids = NULL;

    if (view != NULL)
    {
        GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(view);

        if (privat != NULL)
        {
            gint index;

            if (gpview_result_adapter_get_column_index(privat->adapter, "DocumentID", &index))
            {
                ids = gpview_result_adapter_get_fields(privat->adapter, privat->selection, index);
            }
        }
    }

    return ids;
}


static void
gpview_document_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
gpview_document_view_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPViewDocumentViewClass),    /* class_size */
            NULL,                              /* base_init */
            NULL,                              /* base_finalize */
            gpview_document_view_class_init,    /* class_init */
            NULL,                              /* class_finalize */
            NULL,                              /* class_data */
            sizeof(GPViewDocumentView),         /* instance_size */
            0,                                 /* n_preallocs */
            gpview_document_view_init,          /* instance_init */
            NULL                               /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            gpview_document_view_init_view_interface,    /* interface_init */
            NULL,                                       /* interface_finalize */
            NULL                                        /* interface_data */
            };

        type = g_type_register_static(
            GTK_TYPE_SCROLLED_WINDOW,
            "GPViewDocumentView",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GPVIEW_TYPE_VIEW_INTERFACE, &iinfo);
    }

    return type;
}

GStrv
gpview_document_view_get_websites(GPViewDocumentView *view)
{
    GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(view);
    GStrv websites = NULL;

    if (privat != NULL)
    {
        gint index;

        if (gpview_result_adapter_get_column_index(privat->adapter, "Website", &index))
        {
            websites = gpview_result_adapter_get_fields(privat->adapter, privat->selection, index);
        }
    }

    return websites;
}

static void
gpview_document_view_init(GTypeInstance *instance, gpointer g_class)
{
    GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->tree_view = (GtkTreeView*) gtk_tree_view_new();

        gtk_scrolled_window_set_policy(
            GTK_SCROLLED_WINDOW(instance),
            GTK_POLICY_AUTOMATIC,   /* hscrollbar_policy */
            GTK_POLICY_AUTOMATIC    /* vscrollbar_policy */
            );

        gtk_container_add(
            GTK_CONTAINER(instance),
            GTK_WIDGET(privat->tree_view)
            );

        privat->selection = gtk_tree_view_get_selection(privat->tree_view);

        gtk_tree_selection_set_mode(
            privat->selection,
            GTK_SELECTION_MULTIPLE
            );

        g_signal_connect(
            privat->selection,
            "changed",
            G_CALLBACK(gpview_document_view_changed_cb),
            instance
            );

        g_signal_connect(
            instance,
            "notify::database",
            G_CALLBACK(gpview_document_view_update_cb),
            instance
            );
    }
}

static void
gpview_document_view_init_view_interface(gpointer iface, gpointer user_data)
{
    GPViewViewInterface *iface2 = (GPViewViewInterface*) iface;

    iface2->activate   = gpview_document_view_activate;
    iface2->deactivate = gpview_document_view_deactivate;
}

GPViewDocumentView*
gpview_document_view_new()
{
    return GPVIEW_DOCUMENT_VIEW(g_object_new(GPVIEW_TYPE_DOCUMENT_VIEW, NULL));
}

GPViewDocumentView*
gpview_document_view_new_with_controller(GPViewDocumentCtrl *ctrl)
{
    return GPVIEW_DOCUMENT_VIEW(g_object_new(
        GPVIEW_TYPE_DOCUMENT_VIEW,
        "controller", ctrl,
        NULL
        ));
}

void
gpview_document_view_set_controller(GPViewDocumentView *view, GPViewDocumentCtrl *ctrl)
{
    GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(view);

    if (privat != NULL)
    {
        if (privat->controller != NULL)
        {
            //g_signal_handlers_disconnect_by_func(
            //    privat->database,
            //    G_CALLBACK(gpview_document_view_notify_connected_cb),
            //    view
            //    );

            g_object_unref(privat->controller);
        }

        privat->controller = ctrl;

        if (privat->controller != NULL)
        {
            g_object_ref(privat->controller);

            //g_signal_connect(
            //    privat->database,
            //    "notify::connected",
            //    G_CALLBACK(gpview_document_view_notify_connected_cb),
            //    view
            //    );
        }

        g_object_notify(G_OBJECT(view), "controller");
    }
}

void
gpview_document_view_set_database(GPViewDocumentView *view, GPartsDatabase *database)
{
    GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(view);

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gpview_document_view_update_cb),
                view
                );

            g_object_unref(privat->database);
        }

        privat->database = database;

        if (privat->database != NULL)
        {
            g_object_ref(privat->database);

            g_signal_connect(
                privat->database,
                "notify::connected",
                G_CALLBACK(gpview_document_view_update_cb),
                view
                );
        }

        g_object_notify(G_OBJECT(view), "database");
    }
}

static void
gpview_document_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPViewDocumentView *view = GPVIEW_DOCUMENT_VIEW(object);

    if (view != NULL)
    {
        switch (property_id)
        {
            case GPVIEW_DOCUMENT_VIEW_CONTROLLER:
                gpview_document_view_set_controller(view, g_value_get_object(value));
                break;

            case GPVIEW_DOCUMENT_VIEW_DATABASE:
                gpview_document_view_set_database(view, g_value_get_object(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

static void
gpview_document_view_set_result(GPViewDocumentView *view, GPartsDatabaseResult *result)
{
    GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(view);

    if (privat != NULL)
    {
        if (privat->adapter != NULL)
        {
            g_object_unref(privat->adapter);
        }

        if (privat->result != NULL)
        {
            g_object_unref(privat->result);
        }

        privat->adapter = NULL;
        privat->result = result;

        if (privat->result != NULL)
        {
            g_object_ref(privat->result);

            privat->adapter = gpview_result_adapter_new(privat->result);

            if (privat->adapter != NULL)
            {
                gpview_result_adapter_adjust_columns(privat->adapter, privat->tree_view);
            }

            gtk_tree_view_set_model(privat->tree_view, GTK_TREE_MODEL(privat->adapter));
        }

        g_object_notify(G_OBJECT(view), "company-id");
        g_object_notify(G_OBJECT(view), "result");
        g_object_notify(G_OBJECT(view), "websites");
    }
}

static void
gpview_document_view_update_cb(GObject *unused, GParamSpec *pspec, GPViewDocumentView *view)
{
    GPViewDocumentViewPrivate *privat = GPVIEW_DOCUMENT_VIEW_GET_PRIVATE(view);

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            GPartsDatabaseResult *result;

            result = gparts_database_query(privat->database, "SELECT * FROM DocumentV", NULL);

            gpview_document_view_set_result(view, result);

            if (result != NULL)
            {
                g_object_unref(G_OBJECT(result));
            }
        }
    }

}

