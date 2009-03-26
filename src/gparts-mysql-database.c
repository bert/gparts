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

#include <glib-object.h>
#include <gmodule.h>
#include <mysql.h>

#include "gparts-database-result.h"
#include "gparts-database.h"
#include "gparts-mysql-result.h"
#include "gparts-mysql-database.h"

typedef struct _GPartsMySQLDatabasePrivate GPartsMySQLDatabasePrivate;

struct _GPartsMySQLDatabasePrivate
{
    MYSQL* mysql;
};

#define GPARTS_MYSQL_DATABASE_ERROR (gparts_mysql_database_error_quark())

#define GPARTS_MYSQL_DATABASE_GET_PRIVATE(database) G_TYPE_INSTANCE_GET_PRIVATE(database,GPARTS_TYPE_MYSQL_DATABASE,GPartsMySQLDatabasePrivate);

static void
gparts_mysql_database_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_mysql_database_connect(GPartsDatabase *database, connect_data *data, GError **error);

static void
gparts_mysql_database_database_init(GPartsDatabaseInterface *iface);

static void
gparts_mysql_database_disconnect(GPartsDatabase *database, GError **error);

static void
gparts_mysql_database_dispose(GObject *object);

static GQuark
gparts_mysql_database_error_quark(void);

static void
gparts_mysql_database_finalize(GObject *object);

static void
gparts_mysql_database_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gparts_mysql_database_instance_init(GTypeInstance *instance, gpointer g_class);

GPartsMySQLResult*
gparts_mysql_database_query(GPartsDatabase *database, const gchar *query, GError **error);

static void
gparts_mysql_database_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

/*! \brief Initialize class data.
 *
 *  \param [in] g_class
 *  \param [in] g_class_data
 */
static void
gparts_mysql_database_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(
        g_class,
        sizeof(GPartsMySQLDatabasePrivate)
        );

    object_class->finalize     = gparts_mysql_database_finalize;
    object_class->get_property = gparts_mysql_database_get_property;
    object_class->set_property = gparts_mysql_database_set_property;

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


/** \brief Connects to the MySQL database.
 *
 *  Connects to an existing MySQL database.
 *
 *  \param [in] database
 *  \param [in] data
 *  \param [in] error
 */
static void
gparts_mysql_database_connect(GPartsDatabase *database, connect_data *data, GError **error)
{
    GError *local_error = NULL;
    GPartsMySQLDatabasePrivate* private;

    g_assert( database != NULL );
    private = GPARTS_MYSQL_DATABASE_GET_PRIVATE( database );
    g_assert( private != NULL );

    gparts_mysql_database_disconnect(database, &local_error);

    if ( local_error == NULL )
    {
        MYSQL* result;

        private->mysql = mysql_init( NULL );

        result = mysql_real_connect(
            private->mysql,
            data->host_name,
            data->user_name,
            data->password,
            data->database_name,
            0,
            NULL,
            CLIENT_MULTI_STATEMENTS | CLIENT_MULTI_RESULTS
            );

        if ( private->mysql != result )
        {
            g_set_error(
                &local_error,
                GPARTS_MYSQL_DATABASE_ERROR,
                mysql_errno( private->mysql ),
                "%s",
                mysql_error( private->mysql )
                );
        }
    }

    if ( local_error == NULL )
    {
        g_signal_emit_by_name( database, "database-connected" );
    }
    else
    {
        g_propagate_error( error, local_error );
    }
}

/*! \brief
 *
 *  \param [in] iface
 */
static void
gparts_mysql_database_database_init(GPartsDatabaseInterface *iface)
{
    iface->connect    = gparts_mysql_database_connect;
    iface->disconnect = gparts_mysql_database_disconnect;
    iface->query      = gparts_mysql_database_query;
}

/*! \brief Disconnects from the MySQL database.
 *
 *  \param [in]  database The database to disconnect from.
 *  \param [out] error    An error, if any, using the GError protocol.
 */
static void
gparts_mysql_database_disconnect(GPartsDatabase *database, GError **error)
{
    GPartsMySQLDatabasePrivate* private;

    g_assert(database != NULL);

    private = GPARTS_MYSQL_DATABASE_GET_PRIVATE(database);
    g_assert(private != NULL);

    if (private->mysql != NULL)
    {
        mysql_close(private->mysql);

        private->mysql = NULL;

        g_signal_emit_by_name(database, "database-disconnected");
    }
}

/*!
 *
 *
 *
 */
static GQuark
gparts_mysql_database_error_quark(void)
{
    return g_quark_from_static_string( "gparts-database-mysql-error" );
}

/*! \brief Free all resources
 *
 *  \param [in] object
 */
static void
gparts_mysql_database_finalize(GObject *object)
{
    g_debug("gparts_mysql_database_finalize()");

    
}

static void
gparts_mysql_database_get_property( GObject* object, guint property_id, GValue* value, GParamSpec* param_spec )
{
}

GType
gparts_mysql_database_get_type( void )
{
    static GType type = 0;

    if (type == 0)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsMySQLDatabaseClass),
            NULL,
            NULL,
            gparts_mysql_database_class_init,
            NULL,
            NULL,
            sizeof(GPartsMySQLDatabase),
            0,
            NULL,
            NULL
            };

        static const GInterfaceInfo iinfo = {
            (GInterfaceInitFunc) gparts_mysql_database_database_init,
            NULL,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gparts-mysql-database",
            &tinfo,
            0
            );

        if (type != G_TYPE_INVALID)
        {
            g_type_add_interface_static(
                type,
                GPARTS_TYPE_DATABASE,
                &iinfo
                );
        }
    }

    return type;
}

/**
 * \brief Creates a new IBIS model.
 */
GPartsMySQLDatabase* gparts_mysql_database_new()
{
    return GPARTS_MYSQL_DATABASE(g_object_new(GPARTS_TYPE_MYSQL_DATABASE, NULL));
}

/*! \brief Execute an SQL query to the database.
 *
 *  \param [in]  database The database to query.
 *  \param [in]  query    The SQL query as a string.
 *  \param [out] error    An error, if any, using the GError protocol.
 */
GPartsMySQLResult*
gparts_mysql_database_query(GPartsDatabase *database, const gchar *query, GError **error)
{
    MYSQL_RES *result;
    GPartsMySQLDatabasePrivate* private;
    int status;

    g_assert(database != NULL);
    g_assert(query != NULL);

    private = GPARTS_MYSQL_DATABASE_GET_PRIVATE( database );
    g_assert( private != NULL );

    if (private->mysql == NULL)
    {
        return NULL;
    }

    status = mysql_query(private->mysql, query);

    if ( status != 0 )
    {
        g_debug("Database error: %s", mysql_error(private->mysql));

        g_set_error(
            error,
            GPARTS_MYSQL_DATABASE_ERROR,
            mysql_errno(private->mysql),
            "%s",
            mysql_error(private->mysql)
            );

        return NULL;
    }

    result = mysql_store_result(private->mysql);

    if ( result == NULL )
    {
        g_debug("Database error: %s", mysql_error(private->mysql));

        g_set_error(
            error,
            GPARTS_MYSQL_DATABASE_ERROR,
            mysql_errno(private->mysql),
            "%s",
            mysql_error(private->mysql)
            );

        return NULL;
    }

    return gparts_mysql_result_new(result);
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
gparts_mysql_database_set_property( GObject* object, guint property_id, const GValue* value, GParamSpec* param_spec )
{
    g_print( "Set property: %d\n", property_id );
}

