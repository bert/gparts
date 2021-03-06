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

/*! \file gparts-sqlite-module.c
 */

#include <gmodule.h>
#include <sqlite3.h>

#include "gparts.h"

#include "gparts-sqlite-result.h"
#include "gparts-sqlite-database.h"
#include "gparts-sqlite-factory.h"

const gchar*
g_module_check_init(GModule *module)
{
    g_module_make_resident(module);

    GPARTS_TYPE_SQLITE_DATABASE;
    GPARTS_TYPE_SQLITE_FACTORY;
    GPARTS_TYPE_SQLITE_RESULT;

    return NULL;
}

void
gparts_database_register(GPartsDatabaseType *database_type)
{
    GPartsDatabaseTypeClass *database_type_class = GPARTS_DATABASE_TYPE_GET_CLASS(database_type);

    if (database_type_class != NULL && database_type_class->add_factory != NULL)
    {
        database_type_class->add_factory(
            database_type,
            GPARTS_DATABASE_FACTORY(gparts_sqlite_factory_new())
            );
    }
    else
    {
        g_critical("Unable to register SQLite database module");
    }
}

