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

/*! \file gparts-postgresql-result.h
 *
 *  \brief A wrapper for PostgreSQL database results.
 */

#define GPARTS_TYPE_POSTGRESQL_RESULT (gparts_postgresql_result_get_type())
#define GPARTS_POSTGRESQL_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_POSTGRESQL_RESULT,GPARTSPostgreSQLResult))
#define GPARTS_POSTGRESQL_RESULT_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_POSTGRESQL_RESULT,GPARTSPostgreSQLResultClass))
#define GPARTS_IS_POSTGRESQL_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_POSTGRESQL_RESULT))
#define GPARTS_IS_POSTGRESQL_RESULT_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_POSTGRESQL_RESULT))
#define GPARTS_POSTGRESQL_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_POSTGRESQL_RESULT,GPARTSPostgreSQLResultClass))

typedef struct _GPartsPostgreSQLResult GPartsPostgreSQLResult;
typedef struct _GPartsPostgreSQLResultClass GPartsPostgreSQLResultClass;

/*! \extends GPartsDatabaseResult */
struct _GPartsPostgreSQLResult
{
    GObject parent;
};

/*! \private */
struct _GPartsPostgreSQLResultClass
{
    GObjectClass parent;
};

/*! \private */
GType
gparts_postgresql_result_get_type(void);

/*! \brief Create a new wrapper around a PostgreSQL result.
 *
 *  When no longer needed, call g_object_unref() on the returned pointer.
 *
 *  \param [in] result The result from the PostgreSQL database query.
 *  \return A pointer to a new GPartsPostgreSQLResult object.
 */
GPartsPostgreSQLResult*
gparts_postgresql_result_new(PQResult *result);

