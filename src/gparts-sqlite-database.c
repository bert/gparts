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

/*! \file gparts-sqlite-database.c
 */

#include <sqlite3.h>

#include "gparts.h"

#include "gparts-sqlite-result.h"
#include "gparts-sqlite-database.h"

typedef struct _GPartsSQLiteDatabasePrivate GPartsSQLiteDatabasePrivate;

struct _GPartsSQLiteDatabasePrivate
{
    sqlite3* sqlite;
};

#define GPARTS_SQLITE_DATABASE_ERROR (gparts_sqlite_database_error_quark())

#define GPARTS_SQLITE_DATABASE_GET_PRIVATE(database) G_TYPE_INSTANCE_GET_PRIVATE(database,GPARTS_TYPE_SQLITE_DATABASE,GPartsSQLiteDatabasePrivate);

static void
gparts_sqlite_database_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_sqlite_database_connect(GPartsDatabase *database, GPartsConnectData *data, GError **error);

static void
gparts_sqlite_database_disconnect(GPartsDatabase *database, GError **error);

static void
gparts_sqlite_database_dispose(GObject *object);

static GQuark
gparts_sqlite_database_error_quark(void);

static void
gparts_sqlite_database_finalize(GObject *object);

static void
gparts_sqlite_database_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gparts_sqlite_database_instance_init(GTypeInstance *instance, gpointer g_class);

GPartsSQLiteResult*
gparts_sqlite_database_query(GPartsDatabase *database, const gchar *query, GError **error);

static void
gparts_sqlite_database_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

/*! \brief Initialize class data.
 *
 *  \param [in] g_class
 *  \param [in] g_class_data
 */
static void
gparts_sqlite_database_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);
    GPartsDatabaseClass *klasse = GPARTS_DATABASE_CLASS(g_class);

    g_type_class_add_private(
        g_class,
        sizeof(GPartsSQLiteDatabasePrivate)
        );

    object_class->finalize     = gparts_sqlite_database_finalize;
    object_class->get_property = gparts_sqlite_database_get_property;
    object_class->set_property = gparts_sqlite_database_set_property;

    klasse->connect    = gparts_sqlite_database_connect;
    klasse->disconnect = gparts_sqlite_database_disconnect;
    klasse->query      = gparts_sqlite_database_query;

    g_signal_new(
        "database-connected",
        G_TYPE_FROM_CLASS( g_class ),
        G_SIGNAL_RUN_FIRST,
        0,
        NULL,
        NULL,
        g_cclosure_marshal_VOID__VOID,
        G_TYPE_NONE,
        0
        );

    g_signal_new(
        "database-disconnected",
        G_TYPE_FROM_CLASS( g_class ),
        G_SIGNAL_RUN_FIRST,
        0,
        NULL,
        NULL,
        g_cclosure_marshal_VOID__VOID,
        G_TYPE_NONE,
        0
        );
}


/** \brief Connects to the SQLite database.
 *
 *  Connects to an existing SQLite database.
 *
 *  \param [in] database
 *  \param [in] data
 *  \param [in] error
 */
static void
gparts_sqlite_database_connect(GPartsDatabase *database, GPartsConnectData *data, GError **error)
{
    GError *local_error = NULL;
    GPartsSQLiteDatabasePrivate* privat = GPARTS_SQLITE_DATABASE_GET_PRIVATE( database );

    gparts_sqlite_database_disconnect(database, &local_error);

    if (local_error == NULL)
    {
        gint result = sqlite3_open(data->filename, &(privat->sqlite));

        if (result != SQLITE_OK)
        {
            g_set_error(
                &local_error,
                g_quark_from_static_string("gparts-database-error"),
                sqlite3_errcode(privat->sqlite),
                "%s",
                sqlite3_errmsg(privat->sqlite)
                );

            sqlite3_close(privat->sqlite);
            privat->sqlite = NULL;
        }
    }

    if ( local_error == NULL )
    {
        g_signal_emit_by_name(database, "database-connected");
    }
    else
    {
        g_propagate_error(error, local_error);
    }
}

/*! \brief Disconnects from the SQLite database.
 *
 *  \param [in]  database The database to disconnect from.
 *  \param [out] error    An error, if any, using the GError protocol.
 */
static void
gparts_sqlite_database_disconnect(GPartsDatabase *database, GError **error)
{
    GPartsSQLiteDatabasePrivate* privat = GPARTS_SQLITE_DATABASE_GET_PRIVATE(database);

    if (privat != NULL)
    {
        sqlite3_close(privat->sqlite);
        privat->sqlite = NULL;

        g_signal_emit_by_name(database, "database-disconnected");
    }
}

/*!
 *
 *
 *
 */
static GQuark
gparts_sqlite_database_error_quark(void)
{
    return g_quark_from_static_string( "gparts-database-sqlite-error" );
}

/*! \brief Free all resources
 *
 *  \param [in] object
 */
static void
gparts_sqlite_database_finalize(GObject *object)
{
    GPartsSQLiteDatabasePrivate* privat = GPARTS_SQLITE_DATABASE_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_debug("gparts_sqlite_database_finalize()");

        sqlite3_close(privat->sqlite);
        privat->sqlite = NULL;
    }

    misc_object_chain_finalize(object);
}

static void
gparts_sqlite_database_get_property( GObject* object, guint property_id, GValue* value, GParamSpec* param_spec )
{
}

GType
gparts_sqlite_database_get_type( void )
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsSQLiteDatabaseClass),
            NULL,
            NULL,
            gparts_sqlite_database_class_init,
            NULL,
            NULL,
            sizeof(GPartsSQLiteDatabase),
            0,
            NULL,
            NULL
            };

        type = g_type_register_static(
            GPARTS_TYPE_DATABASE,
            "gparts-sqlite-database",
            &tinfo,
            0
            );
    }

    return type;
}

/**
 * \brief Creates a new IBIS model.
 */
GPartsSQLiteDatabase* gparts_sqlite_database_new()
{
    return GPARTS_SQLITE_DATABASE(g_object_new(GPARTS_TYPE_SQLITE_DATABASE, NULL));
}

/*! \brief Execute an SQL query to the database.
 *
 *  \param [in]  database The database to query.
 *  \param [in]  query    The SQL query as a string.
 *  \param [out] error    An error, if any, using the GError protocol.
 */
GPartsSQLiteResult*
gparts_sqlite_database_query(GPartsDatabase *database, const gchar *query, GError **error)
{
    sqlite3_stmt *result;
    GPartsSQLiteDatabasePrivate* privat;
    int status;

    g_assert(database != NULL);
    g_assert(query != NULL);

    privat = GPARTS_SQLITE_DATABASE_GET_PRIVATE( database );
    g_assert( privat != NULL );

    if (privat->sqlite == NULL)
    {
        return NULL;
    }

    status = sqlite3_prepare_v2(privat->sqlite, query, -1, &result, NULL);

    if (status != SQLITE_OK)
    {
        g_debug("Database error: %s", sqlite3_errmsg(privat->sqlite));

        g_set_error(
            error,
            g_quark_from_static_string("gparts-database-error"),
            sqlite3_errcode(privat->sqlite),
            "%s",
            sqlite3_errmsg(privat->sqlite)
            );

        return NULL;
    }

    return gparts_sqlite_result_new(result);
}

/**
 * \brief Loads an IBIS model from a file.
 *
 * After loading, the model object emits a "model-changed" signal.
 *
 * @param model
 * @param filename
 * @param error The error, if any, using standard GLib conventions.
 */
static void
gparts_sqlite_database_set_property( GObject* object, guint property_id, const GValue* value, GParamSpec* param_spec )
{
    g_print( "Set property: %d\n", property_id );
}

