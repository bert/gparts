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

/*! \file gparts-database.c
 */

#include <glib-object.h>

#include "gparts-connect-data.h"

#include "gparts-database-result.h"
#include "gparts-database.h"

static void
gparts_database_drop_base(GPartsDatabase *database, GError **error);

static gboolean
gparts_database_droppable_base(const GPartsDatabase *database);



static void
gparts_database_base_init(gpointer g_class)
{
}

static void
gparts_database_class_init(gpointer g_class, gpointer g_class_data)
{
    GPartsDatabaseClass *klasse = GPARTS_DATABASE_CLASS(g_class);

    klasse->drop      = gparts_database_drop_base;
    klasse->droppable = gparts_database_droppable_base;
}

void
gparts_database_connect(GPartsDatabase *database, GPartsConnectData* data, GError **error)
{
    if (database != NULL)
    {
        GPartsDatabaseClass *klasse = GPARTS_DATABASE_GET_CLASS(database);

        if (klasse == NULL)
        {
            g_critical("Unable to get GPartsDatabaseClass from parameter");
        }
        else if (klasse->connect == NULL)
        {
            g_critical("GPartsDatabaseClass contains NULL connect() function pointer");
        }
        else
        {
            klasse->connect(database, data, error);
        }
    }
}

void
gparts_database_disconnect(GPartsDatabase *database, GError **error)
{
    if (database != NULL)
    {
        GPartsDatabaseClass *klasse = GPARTS_DATABASE_GET_CLASS(database);

        if (klasse == NULL)
        {
            g_critical("Unable to get GPartsDatabaseClass from parameter");
        }
        else if (klasse->disconnect == NULL)
        {
            g_critical("GPartsDatabaseClass contains NULL disconnect() function pointer");
        }
        else
        {
            klasse->disconnect(database, error);
        }
    }
}

void
gparts_database_drop(GPartsDatabase *database, GError **error)
{
    if (database != NULL)
    {
        GPartsDatabaseClass *klasse = GPARTS_DATABASE_GET_CLASS(database);

        if (klasse == NULL)
        {
            g_critical("Unable to get GPartsDatabaseClass from parameter");
        }
        else if (klasse->drop == NULL)
        {
            g_critical("GPartsDatabaseClass contains NULL drop() function pointer");
        }
        else
        {
            klasse->drop(database, error);
        }
    }
}

static void
gparts_database_drop_base(GPartsDatabase *database, GError **error)
{
    g_set_error(
        error,
        g_quark_from_static_string( "gparts-database-error" ),
        0,
        "%s",
        "Drop database functionality not implemented"
        );
}

gboolean
gparts_database_droppable(const GPartsDatabase *database)
{
    gboolean droppable = FALSE;

    if (database != NULL)
    {
        GPartsDatabaseClass *klasse = GPARTS_DATABASE_GET_CLASS(database);

        if (klasse == NULL)
        {
            g_critical("Unable to get GPartsDatabaseClass from parameter");
        }
        else if (klasse->droppable == NULL)
        {
            g_critical("GPartsDatabaseClass contains NULL droppable() function pointer");
        }
        else
        {
            droppable = klasse->droppable(database);
        }
    }

    return droppable;
}

static gboolean
gparts_database_droppable_base(const GPartsDatabase *database)
{
    return FALSE;
}

GType
gparts_database_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsDatabaseClass),    /* class_size */
            gparts_database_base_init,      /* base_init */
            NULL,                           /* base_finalize */
            gparts_database_class_init,     /* class_init */
            NULL,                           /* class_finalize */
            NULL,                           /* class_data */
            sizeof(GPartsDatabase),         /* instance_size */
            0,                              /* n_preallocs */
            NULL,                           /* instance_init */
            NULL                            /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gparts-database",
            &tinfo,
            G_TYPE_FLAG_ABSTRACT
            );
    }

    return type;
}

GPartsDatabaseResult*
gparts_database_query(GPartsDatabase *database, const gchar *query, GError **error)
{
    GPartsDatabaseResult* result = NULL;

    if (database != NULL)
    {
        GPartsDatabaseClass *klasse = GPARTS_DATABASE_GET_CLASS(database);

        if (klasse == NULL)
        {
            g_critical("Unable to get GPartsDatabaseClass from parameter");
        }
        else if (klasse->query == NULL)
        {
            g_critical("GPartsDatabaseClass contains NULL query() function pointer");
        }
        else
        {
            result = klasse->query(database, query, error);
        }
    }

    return result;
}

