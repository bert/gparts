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

/*! \file gparts-company-model.c
 */

#include "gpartsui.h"

#define GPARTSUI_DOCUMENT_MODEL_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTSUI_TYPE_DOCUMENT_MODEL,GPartsUIDocumentModelPrivate)

enum
{
    GPARTSUI_DOCUMENT_MODEL_DOCUMENT_RESULT = 1,
    GPARTSUI_DOCUMENT_MODEL_DATABASE_MODEL
};

typedef struct _GPartsUIDocumentModelPrivate GPartsUIDocumentModelPrivate;

struct _GPartsUIDocumentModelPrivate
{
    GPartsUIDatabaseModel *database_model;
    MiscUIActionModel     *delete_model;
    MiscUIActionModel     *open_website_model;

    GPartsDatabaseResult  *company_result;
};

static void
gpartsui_document_model_class_init(gpointer g_class, gpointer g_class_data);

static void
gpartsui_document_model_dispose(GObject *object);

static void
gpartsui_document_model_finalize(GObject *object);

static void
gpartsui_document_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpartsui_document_model_instance_init(GTypeInstance *instance, gpointer g_class);

static void
gpartsui_document_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gpartsui_document_model_notify_connected_cb(GPartsUIDatabaseModel *database_model, GParamSpec *param, GPartsUIDocumentModel *model);

static void
gpartsui_document_model_notify_selected_row_cb(GPartsUIDatabaseModel *database_model, GParamSpec *param, GPartsUIDocumentModel *model);

static void
gpartsui_document_model_update_result(GPartsUIDocumentModel *model);



static void
gpartsui_document_model_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsUIDocumentModelPrivate));

    klasse->dispose      = gpartsui_document_model_dispose;
    klasse->finalize     = gpartsui_document_model_finalize;
    klasse->get_property = gpartsui_document_model_get_property;
    klasse->set_property = gpartsui_document_model_set_property;

    g_object_class_install_property(
        klasse,
        GPARTSUI_DOCUMENT_MODEL_DOCUMENT_RESULT,
        g_param_spec_object(
            "company-result",
            "Company Result",
            "Company Result",
            GPARTS_TYPE_DATABASE_RESULT,
            G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPARTSUI_DOCUMENT_MODEL_DATABASE_MODEL,
        g_param_spec_object(
            "database-model",
            "Database Model",
            "Database Model",
            GPARTSUI_TYPE_DATABASE_MODEL,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpartsui_document_model_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}

static void
gpartsui_document_model_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

GPartsDatabaseResult*
gpartsui_document_model_get_document_result(const GPartsUIDocumentModel *model)
{
    GPartsDatabaseResult *company_result = NULL;

    if (model != NULL)
    {
        GPartsUIDocumentModelPrivate *privat = GPARTSUI_DOCUMENT_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            company_result = privat->company_result;

            if (company_result != NULL)
            {
                g_object_ref(company_result);
            }
        }
    }

    return company_result;
}

GPartsUIDatabaseModel*
gpartsui_document_model_get_database_model(const GPartsUIDocumentModel *model)
{
    GPartsUIDatabaseModel *database_model = NULL;

    if (model != NULL)
    {
        GPartsUIDocumentModelPrivate *privat = GPARTSUI_DOCUMENT_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            database_model = privat->database_model;

            if (database_model != NULL)
            {
                g_object_ref(database_model);
            }
        }
    }

    return database_model;
}


static void
gpartsui_document_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsUIDocumentModel *model = GPARTSUI_DOCUMENT_MODEL(object);

    if (model != NULL)
    {
        switch ( property_id )
        {
            case GPARTSUI_DOCUMENT_MODEL_DOCUMENT_RESULT:
                g_value_take_object(value, gpartsui_document_model_get_document_result(model));
                break;

            case GPARTSUI_DOCUMENT_MODEL_DATABASE_MODEL:
                g_value_take_object(value, gpartsui_document_model_get_database_model(model));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
gpartsui_document_model_get_type( void )
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsUIDocumentModelClass),
            NULL,
            NULL,
            gpartsui_document_model_class_init,
            NULL,
            NULL,
            sizeof(GPartsUIDocumentModel),
            0,
            gpartsui_document_model_instance_init,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gpartsui-document-model",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gpartsui_document_model_instance_init(GTypeInstance* instance, gpointer g_class)
{
    GPartsUIDocumentModelPrivate *privat = GPARTSUI_DOCUMENT_MODEL_GET_PRIVATE(instance);

    if (privat != NULL)
    {
    }
}

GPartsUIDocumentModel*
gpartsui_document_model_new(void)
{
    return GPARTSUI_DOCUMENT_MODEL(g_object_new(GPARTSUI_TYPE_DOCUMENT_MODEL, NULL));
}

static void
gpartsui_document_model_notify_connected_cb(GPartsUIDatabaseModel *database_model, GParamSpec *param, GPartsUIDocumentModel *model)
{
    gpartsui_document_model_update_result(model);
}

static void
gpartsui_document_model_refresh_cb(GPartsUIDatabaseModel *database_model, GPartsUIDocumentModel *model)
{
    gpartsui_document_model_update_result(model);
}

void
gpartsui_document_model_set_database_model(GPartsUIDocumentModel *model, GPartsUIDatabaseModel *database_model)
{
    GPartsUIDocumentModelPrivate *privat = GPARTSUI_DOCUMENT_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        if (privat->database_model != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database_model,
                G_CALLBACK(gpartsui_document_model_notify_connected_cb),
                model
                );

            g_signal_handlers_disconnect_by_func(
                privat->database_model,
                G_CALLBACK(gpartsui_document_model_refresh_cb),
                model
                );

            g_object_unref(privat->database_model);
        }

        privat->database_model = database_model;

        if (privat->database_model != NULL)
        {
            g_object_unref(privat->database_model);

            g_signal_connect(
                privat->database_model,
                "notify::connected",
                G_CALLBACK(gpartsui_document_model_notify_connected_cb),
                model
                );

            g_signal_connect(
                privat->database_model,
                "refresh",
                G_CALLBACK(gpartsui_document_model_refresh_cb),
                model
                );
        }

        g_object_notify(G_OBJECT(model), "database-model");
    }
}

static void
gpartsui_document_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsUIDocumentModel *model = GPARTSUI_DOCUMENT_MODEL(object);

    if (model != NULL)
    {
        switch ( property_id )
        {
            case GPARTSUI_DOCUMENT_MODEL_DATABASE_MODEL:
                gpartsui_document_model_set_database_model(model, GPARTSUI_DATABASE_MODEL(g_value_get_object(value)));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

static void
gpartsui_document_model_update_result(GPartsUIDocumentModel *model)
{
    GPartsUIDocumentModelPrivate *privat = GPARTSUI_DOCUMENT_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        GPartsDatabase *database;

        if (privat->company_result != NULL)
        {
            g_object_unref(privat->company_result);
            privat->company_result = NULL;
        }

        database = gpartsui_database_model_get_database(privat->database_model);

        if (database != NULL)
        {
            privat->company_result = gparts_database_query(database, "SELECT * FROM DocumentV", NULL);

            g_object_unref(database);
        }

        g_object_notify(G_OBJECT(model), "company-result");
    }
}

