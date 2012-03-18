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

/*! \file gparts-category-widget.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "sch.h"
#include "gparts.h"
#include "gpview.h"

enum
{
    GPVIEW_CATEGORY_WIDGET_CREATE_FORM = 1,
    GPVIEW_CATEGORY_WIDGET_DATABASE,
    GPVIEW_CATEGORY_WIDGET_EDIT_FORM,
    GPVIEW_CATEGORY_WIDGET_VIEW_NAME
};

typedef struct _GPViewCategoryWidgetPrivate GPViewCategoryWidgetPrivate;

struct _GPViewCategoryWidgetPrivate
{
    GPartsDatabase      *database;
    GtkTreeSelection    *selection;
    GtkTreeView         *tree_view;
    GPViewCategoryModel *model;
};

#define GPVIEW_CATEGORY_WIDGET_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPVIEW_TYPE_CATEGORY_WIDGET,GPViewCategoryWidgetPrivate)

/**** Private functions ****/

static void
gpview_category_widget_changed_cb(GtkTreeSelection *selection, GPViewCategoryWidget *widget);

static void
gpview_category_widget_class_init(gpointer g_class, gpointer g_class_data);

static void
gpview_category_widget_dispose(GObject *object);

static void
gpview_category_widget_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpview_category_widget_init(GTypeInstance *instance, gpointer g_class);

static void
gpview_category_widget_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gpview_category_widget_update_cb(GObject *unused, GParamSpec *pspec, GPViewCategoryWidget *widget);



static void
gpview_category_widget_changed_cb(GtkTreeSelection *selection, GPViewCategoryWidget *widget)
{
    if (widget != NULL)
    {
        g_object_notify(G_OBJECT(widget), "view-name");
        //g_object_notify(G_OBJECT(widget), "websites");
    }
}


static void
gpview_category_widget_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPViewCategoryWidgetPrivate));

    klasse->dispose  = gpview_category_widget_dispose;

    klasse->get_property = gpview_category_widget_get_property;
    klasse->set_property = gpview_category_widget_set_property;

    g_object_class_install_property(
        klasse,
        GPVIEW_CATEGORY_WIDGET_DATABASE,
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
        GPVIEW_CATEGORY_WIDGET_VIEW_NAME,
        g_param_spec_string(
            "view-name",
            "View Name",
            "View Name",
            NULL,
            G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );
}


static void
gpview_category_widget_dispose(GObject *object)
{
    GPViewCategoryWidgetPrivate *privat = GPVIEW_CATEGORY_WIDGET_GET_PRIVATE(object);

    if (privat != NULL)
    {
        misc_object_unref(privat->database);
    }

    misc_object_chain_dispose(object);
}


GPartsDatabase*
gpview_category_widget_get_database(GPViewCategoryWidget *widget)
{
    GPartsDatabase *database = NULL;
    GPViewCategoryWidgetPrivate *privat = GPVIEW_CATEGORY_WIDGET_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        database = privat->database;
    }

    return database;
}


GType
gpview_category_widget_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPViewCategoryWidgetClass),
            NULL,
            NULL,
            gpview_category_widget_class_init,
            NULL,
            NULL,
            sizeof(GPViewCategoryWidget),
            0,
            gpview_category_widget_init,
            NULL
            };

        type = g_type_register_static(
            GTK_TYPE_SCROLLED_WINDOW,
            "gpview-category-widget",
            &tinfo,
            0
            );
    }

    return type;
}


static void
gpview_category_widget_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPViewCategoryWidget *widget = GPVIEW_CATEGORY_WIDGET(object);

    if (widget != NULL)
    {
        switch (property_id)
        {
            case GPVIEW_CATEGORY_WIDGET_DATABASE:
                g_value_take_object(value, gpview_category_widget_get_database(widget));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}


gchar*
gpview_category_widget_get_view_name(GPViewCategoryWidget *widget)
{
    gchar *name = NULL;
    GPViewCategoryWidgetPrivate *privat = GPVIEW_CATEGORY_WIDGET_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        GtkTreeIter iter;

        if (gtk_tree_selection_get_selected(privat->selection, NULL, &iter))
        {
            name = gpview_category_model_get_field(privat->model, &iter, "ViewName");
        }
    }

    return name;
}

static void
gpview_category_widget_init(GTypeInstance *instance, gpointer g_class)
{
    GPViewCategoryWidgetPrivate *privat = GPVIEW_CATEGORY_WIDGET_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->tree_view = GTK_TREE_VIEW(gtk_tree_view_new());

        gtk_scrolled_window_set_policy(
            GTK_SCROLLED_WINDOW(instance),
            GTK_POLICY_AUTOMATIC,   /* hscrollbar_policy */
            GTK_POLICY_AUTOMATIC    /* vscrollbar_policy */
            );

        gtk_widget_set_size_request(
            GTK_WIDGET(privat->tree_view),
            200,
            480
            );

        gtk_container_add(
            GTK_CONTAINER(instance),
            GTK_WIDGET(privat->tree_view)
            );

        privat->selection = gtk_tree_view_get_selection(privat->tree_view);

        g_signal_connect(
            privat->selection,
            "changed",
            G_CALLBACK(gpview_category_widget_changed_cb),
            instance
            );

        g_signal_connect(
            instance,
            "notify::database",
            G_CALLBACK(gpview_category_widget_update_cb),
            instance
            );
    }
}



GPViewCategoryWidget*
gpview_category_widget_new()
{
    return GPVIEW_CATEGORY_WIDGET(g_object_new(GPVIEW_TYPE_CATEGORY_WIDGET, NULL));
}


void
gpview_category_widget_set_database(GPViewCategoryWidget *widget, GPartsDatabase *database)
{
    GPViewCategoryWidgetPrivate *privat = GPVIEW_CATEGORY_WIDGET_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gpview_category_widget_update_cb),
                widget
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
                G_CALLBACK(gpview_category_widget_update_cb),
                widget
                );
        }

        g_object_notify(G_OBJECT(widget), "database");
    }
}


static void
gpview_category_widget_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPViewCategoryWidget *widget = GPVIEW_CATEGORY_WIDGET(object);

    if (widget != NULL)
    {
        switch (property_id)
        {
            case GPVIEW_CATEGORY_WIDGET_DATABASE:
                gpview_category_widget_set_database(widget, g_value_get_object(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}


static void
gpview_category_widget_update_cb(GObject *unused, GParamSpec *pspec, GPViewCategoryWidget *widget)
{
    GPViewCategoryWidgetPrivate *privat = GPVIEW_CATEGORY_WIDGET_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        misc_object_unref(privat->model);

        privat->model = NULL;

        if (privat->database != NULL)
        {
            privat->model = gpview_category_model_new(privat->database);
        }

        if (privat->model != NULL)
        {
            gpview_category_model_set_columns(privat->model, privat->tree_view);
        }

        gtk_tree_view_set_model(privat->tree_view, GTK_TREE_MODEL(privat->model));
    }
}

