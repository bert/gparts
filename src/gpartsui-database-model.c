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

/*! \file gparts-database-model.c
 */

#include "gpartsui.h"

#define GPARTSUI_DATABASE_MODEL_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTSUI_TYPE_DATABASE_MODEL,GPartsUIDatabaseModelPrivate)

enum
{
    GPARTSUI_DATABASE_MODEL_CONNECTED = 1,
    GPARTSUI_DATABASE_MODEL_DATABASE,
    GPARTSUI_DATABASE_MODEL_DISCONNECT_SENSITIVE,
    GPARTSUI_DATABASE_MODEL_DROP_SENSITIVE,
};

typedef struct _GPartsUIDatabaseModelPrivate GPartsUIDatabaseModelPrivate;

struct _GPartsUIDatabaseModelPrivate
{
    GPartsDatabase *database;

    MiscUIActionModel *disconnect_model;
    MiscUIActionModel *drop_model;
    MiscUIActionModel *refresh_model;
};

static void
gpartsui_database_model_class_init(gpointer g_class, gpointer g_class_data);

static void
gpartsui_database_model_dispose(GObject *object);

static void
gpartsui_database_model_finalize(GObject *object);

static void
gpartsui_database_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpartsui_database_model_instance_init(GTypeInstance *instance, gpointer g_class);

static void
gpartsui_database_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gpartsui_database_model_update_all(GPartsUIDatabaseModel *model);


static void
gpartsui_database_model_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsUIDatabaseModelPrivate));

    klasse->dispose      = gpartsui_database_model_dispose;
    klasse->finalize     = gpartsui_database_model_finalize;
    klasse->get_property = gpartsui_database_model_get_property;
    klasse->set_property = gpartsui_database_model_set_property;

    g_object_class_install_property(
        klasse,
        GPARTSUI_DATABASE_MODEL_CONNECTED,
        g_param_spec_boolean(
            "connected",
            "Connected",
            "Connected",
            FALSE,
            G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPARTSUI_DATABASE_MODEL_DATABASE,
        g_param_spec_object(
            "database",
            "Database",
            "Database",
            GPARTS_TYPE_DATABASE,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
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
gpartsui_database_model_connected_notify_cb(GPartsDatabase *database, GParamSpec *param, GPartsUIDatabaseModel *model)
{
    g_object_notify(G_OBJECT(model), "connected");

    gpartsui_database_model_update_all(model);
}

void
gpartsui_database_model_disconnect(const GPartsUIDatabaseModel *model, GError **error)
{
    GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        gparts_database_disconnect(privat->database, error);
    }
}

static void
gpartsui_database_model_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}

void
gpartsui_database_model_drop(const GPartsUIDatabaseModel *model, GError **error)
{
    GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        gparts_database_drop(privat->database, error);
    }
}

static void
gpartsui_database_model_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

gboolean
gpartsui_database_model_get_connected(const GPartsUIDatabaseModel *model)
{
    gboolean connected = FALSE;

    if (model != NULL)
    {
        GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            connected = gparts_database_connected(privat->database);
        }
    }

    return connected;
}

GPartsDatabase*
gpartsui_database_model_get_database(const GPartsUIDatabaseModel *model)
{
    GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(model);
    GPartsDatabase *database = NULL;

    if (privat != NULL)
    {
        database = privat->database;

        if (database != NULL)
        {
            g_object_ref(database);
        }
    }

    return database;
}

MiscUIActionModel*
gpartsui_database_model_get_disconnect_action_model(const GPartsUIDatabaseModel *model)
{
    MiscUIActionModel *action_model = NULL;

    if (model != NULL)
    {
        GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            action_model = privat->disconnect_model;

            if (action_model != NULL)
            {
                g_object_ref(action_model);
            }
        }
    }

    return action_model;
}

MiscUIActionModel*
gpartsui_database_model_get_drop_action_model(const GPartsUIDatabaseModel *model)
{
    MiscUIActionModel *action_model = NULL;

    if (model != NULL)
    {
        GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            action_model = privat->drop_model;

            if (action_model != NULL)
            {
                g_object_ref(action_model);
            }
        }
    }

    return action_model;
}


static void
gpartsui_database_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsUIDatabaseModel *model = GPARTSUI_DATABASE_MODEL(object);

    if (model != NULL)
    {
        switch ( property_id )
        {
            case GPARTSUI_DATABASE_MODEL_CONNECTED:
                g_value_set_boolean(value, gpartsui_database_model_get_connected(model));
                break;

            case GPARTSUI_DATABASE_MODEL_DATABASE:
                g_value_take_object(value, gpartsui_database_model_get_database(model));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

MiscUIActionModel*
gpartsui_database_model_get_refresh_action_model(const GPartsUIDatabaseModel *model)
{
    MiscUIActionModel *action_model = NULL;

    if (model != NULL)
    {
        GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            action_model = privat->refresh_model;

            if (action_model != NULL)
            {
                g_object_ref(action_model);
            }
        }
    }

    return action_model;
}

GType
gpartsui_database_model_get_type( void )
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsUIDatabaseModelClass),
            NULL,
            NULL,
            gpartsui_database_model_class_init,
            NULL,
            NULL,
            sizeof(GPartsUIDatabaseModel),
            0,
            gpartsui_database_model_instance_init,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gpartsui-database-model",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gpartsui_database_model_instance_init(GTypeInstance* instance, gpointer g_class)
{
    GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->disconnect_model = MISCUI_ACTION_MODEL(g_object_new(
            MISCUI_TYPE_ACTION_MODEL,
            "function",  gpartsui_database_model_disconnect,
            "label",     "Disconnect",
            "object",    instance,
            "sensitive", FALSE,
            NULL
            ));

        privat->drop_model = MISCUI_ACTION_MODEL(g_object_new(
            MISCUI_TYPE_ACTION_MODEL,
            "function",  gpartsui_database_model_drop,
            "label",     "Drop",
            "object",    instance,
            "sensitive", FALSE,
            NULL
            ));

        privat->refresh_model = MISCUI_ACTION_MODEL(g_object_new(
            MISCUI_TYPE_ACTION_MODEL,
            "function",  gpartsui_database_model_refresh,
            "label",     "Refresh",
            "object",    instance,
            "sensitive", FALSE,
            NULL
            ));
    }
}

GPartsUIDatabaseModel*
gpartsui_database_model_new(void)
{
    return GPARTSUI_DATABASE_MODEL(g_object_new(GPARTSUI_TYPE_DATABASE_MODEL, NULL));
}

void
gpartsui_database_model_refresh(const GPartsUIDatabaseModel *model, GError **error)
{
    g_signal_emit_by_name(model, "refresh");
}

void
gpartsui_database_model_set_database(GPartsUIDatabaseModel *model, GPartsDatabase *database)
{
    GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gpartsui_database_model_connected_notify_cb),
                model
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
                G_CALLBACK(gpartsui_database_model_connected_notify_cb),
                model
                );
        }

        g_object_notify(G_OBJECT(model), "database");
        g_object_notify(G_OBJECT(model), "connected");

        gpartsui_database_model_update_all(model);
    }
}

static void
gpartsui_database_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsUIDatabaseModel *model = GPARTSUI_DATABASE_MODEL(object);

    if (model != NULL)
    {
        switch ( property_id )
        {
            case GPARTSUI_DATABASE_MODEL_DATABASE:
                gpartsui_database_model_set_database(model, g_value_get_object(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

static void
gpartsui_database_model_update_all(GPartsUIDatabaseModel *model)
{
    GPartsUIDatabaseModelPrivate *privat = GPARTSUI_DATABASE_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        gboolean connected = gparts_database_connected(privat->database);

        miscui_action_model_set_sensitive(
            privat->disconnect_model,
            connected
            );

        miscui_action_model_set_sensitive(
            privat->drop_model,
            connected
            );

        miscui_action_model_set_sensitive(
            privat->refresh_model,
            connected
            );
    }
}
