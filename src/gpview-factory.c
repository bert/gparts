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

#include "gparts.h"
#include "gpview.h"

#define GPVIEW_FACTORY_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPVIEW_TYPE_FACTORY,GPViewFactoryPrivate))

enum
{
    GPVIEW_FACTORY_DATABASE = 1,
};

typedef struct _GPViewFactoryPrivate GPViewFactoryPrivate;

struct _GPViewFactoryPrivate
{
    GPartsDatabase *database;
};

static void
gpview_factory_class_init(gpointer g_class, gpointer g_class_data);

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
}

GPViewCompanyView*
gpview_factory_create_company_view(GPViewFactory *factory)
{
    GPViewCompanyView *view = gpview_company_view_new();

    return view;
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
    }
}

GPViewFactory*
gpview_factory_new()
{
    return (GPViewFactory*) g_object_new(GPVIEW_TYPE_FACTORY, NULL);
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

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

