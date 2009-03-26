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

#include "gparts-database-result.h"
#include "gparts-database.h"

static void
gparts_database_base_init(gpointer g_class)
{
}

void
gparts_database_connect(GPartsDatabase *database, connect_data* data, GError **error)
{
    GPartsDatabaseInterface *iface = GPARTS_DATABASE_GET_INTERFACE(database);

    if (iface == NULL)
    {
        g_critical("Unable to get GPartsDatabaseInteface from parameter");
    }
    else if (iface->connect == NULL)
    {
        g_critical("GPartsDatabaseInterface contains NULL connect() function pointer");
    }
    else
    {
        iface->connect(database, data, error);
    }
}

void
gparts_database_disconnect(GPartsDatabase *database, GError **error)
{
    GPartsDatabaseInterface *iface = GPARTS_DATABASE_GET_INTERFACE(database);

    if (iface == NULL)
    {
        g_critical("Unable to get GPartsDatabaseInteface from parameter");
    }
    else if (iface->disconnect == NULL)
    {
        g_critical("GPartsDatabaseInterface contains NULL disconnect() function pointer");
    }
    else
    {
        iface->disconnect(database, error);
    }
}

GType
gparts_database_get_type(void)
{
    static GType type = 0;

    if (type == 0)
    {
        static const GTypeInfo info = {
            sizeof(GPartsDatabaseInterface),
            gparts_database_base_init,
            NULL,
            NULL,
            NULL,
            NULL,
            0,
            0,
            NULL,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_INTERFACE,
            "gparts-database",
            &info,
            0
            );
    }

    return type;
}

GPartsDatabaseResult*
gparts_database_query(GPartsDatabase *database, const gchar *query, GError **error)
{
    GPartsDatabaseInterface *iface = GPARTS_DATABASE_GET_INTERFACE(database);
    GPartsDatabaseResult* result = NULL;

    if (iface == NULL)
    {
        g_critical("Unable to get GPartsDatabaseInteface from parameter");
    }
    else if (iface->query == NULL)
    {
        g_critical("GPartsDatabaseInterface contains NULL query() function pointer");
    }
    else
    {
        result = iface->query(database, query, error);
    }

    return result;
}

