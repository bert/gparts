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

/*! \file gparts-database-result.h
 *
 *  \brief An interface for database results.
 */

#define GPARTS_TYPE_DATABASE_RESULT (gparts_database_result_get_type())
#define GPARTS_DATABASE_RESULT(object) (G_TYPE_CHECK_INSTANCE_CAST((object),GPARTS_TYPE_DATABASE_RESULT,GPartsDatabaseResult))
#define GPARTS_IS_DATABASE_RESULT(object) (G_TYPE_CHECK_INSTANCE_TYPE((object),GPARTS_TYPE_DATABASE_RESULT))
#define GPARTS_DATABASE_RESULT_GET_INTERFACE(instance) (G_TYPE_INSTANCE_GET_INTERFACE((instance),GPARTS_TYPE_DATABASE_RESULT,GPartsDatabaseResultInterface))

typedef struct _GPartsDatabaseResult GPartsDatabaseResult;
typedef struct _GPartsDatabaseResultInterface GPartsDatabaseResultInterface;

struct _GPartsDatabaseResultInterface
{
    GTypeInterface parent;

    guint (*get_column_count)(GPartsDatabaseResult *result);
    gboolean (*get_column_index)(GPartsDatabaseResult *result, const gchar *name, gint *index);
    GType (*get_column_type)(GPartsDatabaseResult *result, gint column);
    const gchar* (*get_column_units)(GPartsDatabaseResult *result, gint column);
    void (*get_column_value)(GPartsDatabaseResult *result, gint column, GValue *value);
    void (*get_field_value)(GPartsDatabaseResult *result, gint row, gint column, GValue *value);
    guint (*get_row_count)(GPartsDatabaseResult *result);
};

/*! \brief Gets the number of columns in the database result.
 *
 *  \param [in] result The database result.
 *  \return The number of columns in the database result.
 */
guint
gparts_database_result_get_column_count(GPartsDatabaseResult *result);

/*! \brief Gets the column index given the column name.
 *
 *  \param [in] result The database result.
 *  \param [in] name The name of the column.
 *  \param [out] index The index of the column.
 *  \retval TRUE Success and the column index was placed in index.
 *  \retval FALSE The column name could not be found.
 */
gboolean
gparts_database_result_get_column_index(GPartsDatabaseResult *result, const gchar *name, gint *index);

/*! \brief Gets the type of a column.
 *
 *  With an invalid column index, this function returns G_TYPE_INVALID.
 *
 *  \param [in] result The database result.
 *  \param [in] column The zero-based index of the column.
 *  \return The GType of the fields in the column.
 */
GType
gparts_database_result_get_column_type(GPartsDatabaseResult *result, gint column);

/*! \brief Gets the units for a column.
 *
 *  \param [in] result The database result.
 *  \param [in] column The zero-based index of the column.
 */
const gchar*
gparts_database_result_get_column_units(GPartsDatabaseResult *result, gint column);

/*! \brief Gets the name of a column.
 *
 *  The value must be previously initialized as a G_TYPE_STRING.  If an error
 *  occurs, the value does not get assigned.
 *
 *  \param [in]  result The database result.
 *  \param [in]  column The zero-based index of the column.
 *  \param [out] value  The name of the column.
 */
void
gparts_database_result_get_column_value(GPartsDatabaseResult *result, gint column, GValue *value);

/*! \brief Gets the value of a field.
 *
 *  This function initializes and sets value to the contents of the field.  The
 *  value parameter must not be initialized (just filled with zeros).  If this
 *  function encounters an error, the value remains unset.
 *
 *  \param [in]  result The database result.
 *  \param [in]  row    The zero based index of the row.
 *  \param [in]  column The zero based index of the column.
 *  \param [out] value  The value of the field.
 */
void
gparts_database_result_get_field_value(GPartsDatabaseResult *result, gint row, gint column, GValue *value);

/*! \brief Gets the number of rows in the database result.
 *
 *  \param [in] result The database result.
 *  \return The number of rows in the database result.
 */
guint
gparts_database_result_get_row_count(GPartsDatabaseResult *result);

GType
gparts_database_result_get_type(void);

