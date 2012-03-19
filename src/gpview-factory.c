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

/*! \file gpview-factory.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "sch.h"
#include "gparts.h"
#include "gpview.h"

#define GPVIEW_FACTORY_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPVIEW_TYPE_FACTORY,GPViewFactoryPrivate))

enum
{
    GPVIEW_FACTORY_DATABASE = 1,
    GPVIEW_FACTORY_UI_MANAGER
};

typedef struct _GPViewFactoryPrivate GPViewFactoryPrivate;

struct _GPViewFactoryPrivate
{
    GPartsDatabase    *database;

    GPViewCompanyCtrl *company_ctrl;
    GPViewPartCtrl    *part_ctrl;
    GPViewSymbolCtrl  *symbol_ctrl;

    GtkUIManager      *ui_manager;
};

static void
gpview_factory_class_init(gpointer g_class, gpointer g_class_data);

static void
gpview_factory_dispose(GObject *object);

static void
gpview_factory_finalize(GObject *object);

static void
gpview_factory_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpview_factory_init(GTypeInstance *instance, gpointer g_class);

static void
gpview_factory_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
gpview_factory_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPViewFactoryPrivate));

    klasse->dispose  = gpview_factory_dispose;
    klasse->finalize = gpview_factory_finalize;

    klasse->get_property = gpview_factory_get_property;
    klasse->set_property = gpview_factory_set_property;

    g_object_class_install_property(
        klasse,
        GPVIEW_FACTORY_DATABASE,
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
        GPVIEW_FACTORY_UI_MANAGER,
        g_param_spec_object(
            "ui-manager",
            "UI Manager",
            "UI Manager",
            GTK_TYPE_UI_MANAGER,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

GPViewCompanyView*
gpview_factory_create_company_view(GPViewFactory *factory)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(factory);
    GPViewCompanyView *view = NULL;

    if (privat != NULL)
    {
        view = gpview_company_view_new_with_controller(privat->company_ctrl);
    }

    return view;
}

GPViewDeviceView*
gpview_factory_create_device_view(GPViewFactory *factory)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(factory);
    GPViewDeviceView *view = NULL;

    if (privat != NULL)
    {
        view = gpview_device_view_new();
    }

    return view;
}


GPViewDocumentView*
gpview_factory_create_document_view(GPViewFactory *factory)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(factory);
    GPViewDocumentView *view = NULL;

    if (privat != NULL)
    {
        view = gpview_document_view_new();
    }

    return view;
}


GPViewFootprintView*
gpview_factory_create_footprint_view(GPViewFactory *factory)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(factory);
    GPViewFootprintView *view = NULL;

    if (privat != NULL)
    {
        view = gpview_footprint_view_new();
    }

    return view;
}


GPViewPackageView*
gpview_factory_create_package_view(GPViewFactory *factory)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(factory);
    GPViewPackageView *view = NULL;

    if (privat != NULL)
    {
        view = gpview_package_view_new();
    }

    return view;
}


GPViewPartView*
gpview_factory_create_part_view(GPViewFactory *factory)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(factory);
    GPViewPartView *view = NULL;

    if (privat != NULL)
    {
        view = gpview_part_view_new_with_controller(privat->part_ctrl);
    }

    return view;
}


GPViewSymbolView*
gpview_factory_create_symbol_view(GPViewFactory *factory)

{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(factory);
    GPViewSymbolView *view = NULL;

    if (privat != NULL)
    {
        view = gpview_symbol_view_new_with_controller(privat->symbol_ctrl);
    }

    return view;
}

static void
gpview_factory_dispose(GObject *object)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(object);

    if (privat != NULL)
    {
        misc_object_unref(privat->database);
        privat->database = NULL;

        misc_object_unref(privat->company_ctrl);
        privat->company_ctrl = NULL;

        misc_object_unref(privat->part_ctrl);
        privat->part_ctrl = NULL;

        misc_object_unref(privat->symbol_ctrl);
        privat->symbol_ctrl = NULL;

        misc_object_unref(privat->ui_manager);
        privat->ui_manager = NULL;
    }

    misc_object_chain_dispose(object);
}

static void
gpview_factory_finalize(GObject *object)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(object);

    if (privat != NULL)
    {
    }

    misc_object_chain_finalize(object);
}


static void
gpview_factory_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(object);

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
gpview_factory_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPViewFactoryClass),    /* class_size */
            NULL,                          /* base_init */
            NULL,                          /* base_finalize */
            gpview_factory_class_init,     /* class_init */
            NULL,                          /* class_finalize */
            NULL,                          /* class_data */
            sizeof(GPViewFactory),         /* instance_size */
            0,                             /* n_preallocs */
            gpview_factory_init,           /* instance_init */
            NULL                           /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPViewFactory",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gpview_factory_init(GTypeInstance *instance, gpointer g_class)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->company_ctrl = gpview_company_ctrl_new();

        privat->part_ctrl = gpview_part_ctrl_new();

        privat->symbol_ctrl = gpview_symbol_ctrl_new();
    }
}

GPViewFactory*
gpview_factory_new()
{
    return GPVIEW_FACTORY(g_object_new(GPVIEW_TYPE_FACTORY, NULL));
}

GPViewFactory*
gpview_factory_new_with_ui_manager(GtkUIManager *manager)
{
    return GPVIEW_FACTORY(g_object_new(
        GPVIEW_TYPE_FACTORY,
        "ui-manager", manager,
        NULL
        ));
}

void
gpview_factory_set_database(GPViewFactory *view, GPartsDatabase *database)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(view);

    g_debug("set_database");

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_object_unref(privat->database);
        }

        privat->database = database;

        if (privat->database != NULL)
        {
            g_object_unref(privat->database);
        }

        gpview_symbol_ctrl_set_database(privat->symbol_ctrl, database);

        g_object_notify(G_OBJECT(view), "database");
    }
}

static void
gpview_factory_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPViewFactory *view = GPVIEW_FACTORY(object);

    if (view != NULL)
    {
        switch (property_id)
        {
            case GPVIEW_FACTORY_DATABASE:
                gpview_factory_set_database(view, g_value_get_object(value));
                break;

            case GPVIEW_FACTORY_UI_MANAGER:
                gpview_factory_set_ui_manager(view, g_value_get_object(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

void
gpview_factory_set_ui_manager(GPViewFactory *factory, GtkUIManager *manager)
{
    GPViewFactoryPrivate *privat = GPVIEW_FACTORY_GET_PRIVATE(factory);

    if (privat != NULL)
    {
        if (privat->ui_manager != NULL)
        {
            g_object_unref(privat->ui_manager);
        }

        privat->ui_manager = manager;

        if (privat->ui_manager != NULL)
        {
            g_object_ref(privat->ui_manager);
        }

        gpview_company_ctrl_set_ui_manager(privat->company_ctrl, manager);
        gpview_part_ctrl_set_ui_manager(privat->part_ctrl, manager);
        gpview_symbol_ctrl_set_ui_manager(privat->symbol_ctrl, manager);

        g_object_notify(G_OBJECT(factory), "ui-manager");
    }
}

