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

/*! \file gparts-postgresql-database.h
 */

#define GPARTS_TYPE_POSTGRESQL_DATABASE (gparts_postgresql_database_get_type())
#define GPARTS_POSTGRESQL_DATABASE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_POSTGRESQL_DATABASE,GPARTSPostgreSQLDatabase))
#define GPARTS_POSTGRESQL_DATABASE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_POSTGRESQL_DATABASE,GPARTSPostgreSQLDatabaseClass))
#define GPARTS_IS_POSTGRESQL_DATABASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_POSTGRESQL_DATABASE))
#define GPARTS_IS_POSTGRESQL_DATABASE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_POSTGRESQL_DATABASE))
#define GPARTS_POSTGRESQL_DATABASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_POSTGRESQL_DATABASE,GPARTSPostgreSQLDatabaseClass))

typedef struct _GPartsPostgreSQLDatabase GPartsPostgreSQLDatabase;
typedef struct _GPartsPostgreSQLDatabaseClass GPartsPostgreSQLDatabaseClass;

struct _GPartsPostgreSQLDatabase
{
    GObject parent;
};

struct _GPartsPostgreSQLDatabaseClass
{
    GObjectClass parent;
};

GType
gparts_postgresql_database_get_type(void);

