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

/*! \file gpview-symbol-view.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "gparts.h"
#include "gpview.h"
#include "schgui.h"

#define GPVIEW_SYMBOL_VIEW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPVIEW_TYPE_SYMBOL_VIEW,GPViewSymbolViewPrivate))

enum
{
    GPVIEW_SYMBOL_VIEW_DATABASE = 1,
};

typedef struct _GPViewSymbolViewPrivate GPViewSymbolViewPrivate;

struct _GPViewSymbolViewPrivate
{
    GPartsDatabase       *database;
    GPartsDatabaseResult *result;

    SchGUIDrawingView    *drawing_view;
    GtkTreeView          *symbol_view;
};

static void
gpview_symbol_view_activate(GPViewViewInterface *widget);

static void
gpview_symbol_view_class_init(gpointer g_class, gpointer g_class_data);

static void
gpview_symbol_view_deactivate(GPViewViewInterface *widget);

static void
gpview_symbol_view_dispose(GObject *object);

static void
gpview_symbol_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpview_symbol_view_init(GTypeInstance *instance, gpointer g_class);

static void
gpview_symbol_view_init_view_interface(gpointer iface, gpointer user_data);

static void
gpview_symbol_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gpview_symbol_view_notify_connected_cb(GPartsDatabase *database, GParamSpec *param, GPViewSymbolView *view);



static void
gpview_symbol_view_activate(GPViewViewInterface *widget)
{
    GPViewSymbolView *view = GPVIEW_SYMBOL_VIEW(widget);

    if (view == NULL)
    {
        g_critical("Unable to");
    }
    else
    {
        g_debug("Activate");
    }
}

static void
gpview_symbol_view_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPViewSymbolViewPrivate));

    klasse->dispose = gpview_symbol_view_dispose;

    klasse->get_property = gpview_symbol_view_get_property;
    klasse->set_property = gpview_symbol_view_set_property;

    g_object_class_install_property(
        klasse,
        GPVIEW_SYMBOL_VIEW_DATABASE,
        g_param_spec_object(
            "database",
            "Database",
            "Database",
            GPARTS_TYPE_DATABASE,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpview_symbol_view_deactivate(GPViewViewInterface *widget)
{
    GPViewSymbolView *view = GPVIEW_SYMBOL_VIEW(widget);

    if (view == NULL)
    {
        g_critical("Unable to");
    }
    else
    {
        g_debug("Dectivate");
    }
}


static void
gpview_symbol_view_dispose(GObject *object)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(object);

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_object_unref(privat->database);
        }
    }

    misc_object_chain_dispose(object);
}

static void
gpview_symbol_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(object);

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
gpview_symbol_view_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPViewSymbolViewClass),    /* class_size */
            NULL,                             /* base_init */
            NULL,                             /* base_finalize */
            gpview_symbol_view_class_init,    /* class_init */
            NULL,                             /* class_finalize */
            NULL,                             /* class_data */
            sizeof(GPViewSymbolView),         /* instance_size */
            0,                                /* n_preallocs */
            gpview_symbol_view_init,          /* instance_init */
            NULL                              /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            gpview_symbol_view_init_view_interface,    /* interface_init */
            NULL,                                      /* interface_finalize */
            NULL                                       /* interface_data */
            };

        type = g_type_register_static(
            GTK_TYPE_HPANED,
            "GPViewSymbolView",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GPVIEW_TYPE_VIEW_INTERFACE, &iinfo);
    }

    return type;
}

static void
gpview_symbol_view_init(GTypeInstance *instance, gpointer g_class)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        GtkWidget *scrolled;

        privat->symbol_view = (GtkTreeView*) gtk_tree_view_new();

        scrolled = gtk_scrolled_window_new(
            NULL,    /* hadjustment */
            NULL     /* vadjustment */
            );

        gtk_scrolled_window_set_policy(
            GTK_SCROLLED_WINDOW(scrolled),
            GTK_POLICY_AUTOMATIC,   /* hscrollbar_policy */
            GTK_POLICY_AUTOMATIC    /* vscrollbar_policy */
            );

        gtk_container_add(
            GTK_CONTAINER(scrolled),
            GTK_WIDGET(privat->symbol_view)
            );

        gtk_container_add(
            GTK_CONTAINER(instance),
            GTK_WIDGET(scrolled)
            );

        privat->drawing_view = schgui_drawing_view_new();

        gtk_container_add(
            GTK_CONTAINER(instance),
            GTK_WIDGET(privat->drawing_view)
            );
    }
}

static void
gpview_symbol_view_init_view_interface(gpointer iface, gpointer user_data)
{
    GPViewViewInterface *iface2 = (GPViewViewInterface*) iface;

    if (iface2 == NULL)
    {
    }
    else
    {
        iface2->activate   = gpview_symbol_view_activate;
        iface2->deactivate = gpview_symbol_view_deactivate;
    }
}

GPViewSymbolView*
gpview_symbol_view_new()
{
    return (GPViewSymbolView*) g_object_new(GPVIEW_TYPE_SYMBOL_VIEW, NULL);
}

static void
gpview_symbol_view_notify_connected_cb(GPartsDatabase *database, GParamSpec *param, GPViewSymbolView *view)
{
    gpview_symbol_view_refresh(view);
}

void
gpview_symbol_view_refresh(GPViewSymbolView *view)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);

    g_debug("gpview_symbol_view_refresh");

    if (privat != NULL)
    {
        if (privat->result != NULL)
        {
            g_object_unref(privat->result);
            privat->result = NULL;
        }

        if (privat->database != NULL)
        {
            GPViewResultAdapter *model = NULL;

            privat->result = gparts_database_query(privat->database, "SELECT * FROM SymbolV", NULL);

            if (privat->result != NULL)
            {
                model = gpview_result_adapter_new(privat->result);
            }

            if (model != NULL)
            {
                gpview_result_adapter_adjust_columns(model, privat->symbol_view);
            }

            gtk_tree_view_set_model(privat->symbol_view, GTK_TREE_MODEL(model));
        }
    }
}

void
gpview_symbol_view_set_database(GPViewSymbolView *view, GPartsDatabase *database)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);

    g_debug("set_database");

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gpview_symbol_view_notify_connected_cb),
                view
                );

            g_object_unref(privat->database);
        }

        privat->database = database;

        if (privat->database != NULL)
        {
            g_object_unref(privat->database);

            g_signal_connect(
                privat->database,
                "notify::connected",
                G_CALLBACK(gpview_symbol_view_notify_connected_cb),
                view
                );
        }

        g_object_notify(G_OBJECT(view), "database");

        gpview_symbol_view_refresh(view);
    }
}

static void
gpview_symbol_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPViewSymbolView *view = GPVIEW_SYMBOL_VIEW(object);

    if (view != NULL)
    {
        switch (property_id)
        {
            case GPVIEW_SYMBOL_VIEW_DATABASE:
                gpview_symbol_view_set_database(view, g_value_get_object(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

