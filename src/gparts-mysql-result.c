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
#include <mysql.h>

#include "gparts-database-result.h"
#include "gparts-mysql-result.h"

/*! \file gparts-mysql-result.c
 *
 *  \brief A wrapper for MySQL database results.
 */

typedef struct _GPartsMySQLResultPrivate GPartsMySQLResultPrivate;

struct _GPartsMySQLResultPrivate
{
    MYSQL_RES *result;
};

#define GPARTS_MYSQL_RESULT_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_MYSQL_RESULT, GPartsMySQLResultPrivate)

static void
gparts_mysql_result_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_mysql_result_finalize(GObject *object);

static guint
gparts_mysql_result_get_column_count(GPartsDatabaseResult *result);

static gboolean
gparts_mysql_result_get_column_index(GPartsDatabaseResult *result, const gchar *name, gint *index);

static GType
gparts_mysql_result_get_column_type(GPartsDatabaseResult *result, gint column);

static const gchar*
gparts_mysql_result_get_column_units(GPartsDatabaseResult *result, gint column);

static void
gparts_mysql_result_get_column_value(GPartsDatabaseResult *result, gint column, GValue *value);

static void
gparts_mysql_result_get_field_value(GPartsDatabaseResult *result, gint row, gint column, GValue *value);

static guint
gparts_mysql_result_get_row_count(GPartsDatabaseResult *result);

/*! \brief Initialize class data.
 *
 *  \param [in] g_class
 *  \param [in] g_class_data
 */
static void
gparts_mysql_result_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(
        g_class,
        sizeof(GPartsMySQLResultPrivate)
        );

    object_class->finalize = gparts_mysql_result_finalize;
}

/*! \brief Initialize the GPartsDatabaseResult interface.
 *
 *  \param [in] iface The interface to initialize.
 */
static void
gparts_mysql_result_database_init(GPartsDatabaseResultInterface *iface)
{
    iface->get_column_count = gparts_mysql_result_get_column_count;
    iface->get_column_index = gparts_mysql_result_get_column_index;
    iface->get_column_type  = gparts_mysql_result_get_column_type;
    iface->get_column_units = gparts_mysql_result_get_column_units;
    iface->get_column_value = gparts_mysql_result_get_column_value;
    iface->get_field_value  = gparts_mysql_result_get_field_value;
    iface->get_row_count    = gparts_mysql_result_get_row_count;
}

/*! \brief Deallocate all resources.
 *
 *  This function performs the second and last stage of object destruction.
 *
 *  \param [in] object The object to finalize.
 */
static void
gparts_mysql_result_finalize(GObject *object)
{
    g_debug("gparts_mysql_result_finalize");

    GPartsMySQLResultPrivate *private = GPARTS_MYSQL_RESULT_GET_PRIVATE(object);

    mysql_free_result(private->result);
}

/*! \brief Gets the number of columns in the database result.
 *
 *  \param [in] result The database result.
 *  \return The number of columns in the database result.
 */
static guint
gparts_mysql_result_get_column_count(GPartsDatabaseResult *result)
{
    GPartsMySQLResultPrivate *private = GPARTS_MYSQL_RESULT_GET_PRIVATE(result);

    return mysql_num_fields(private->result);
}

/*! \brief Untested WIP.
 */
static gboolean
gparts_mysql_result_get_column_index(GPartsDatabaseResult *result, const gchar *name, gint *index)
{
    GPartsMySQLResultPrivate *private = GPARTS_MYSQL_RESULT_GET_PRIVATE(result);
    gint index0;

    gint column_count = mysql_num_fields(private->result);

    MYSQL_FIELD *columns = mysql_fetch_fields(private->result);

    for (index0=0; index0<column_count; index0++)
    {
        if (g_strcmp0(columns[index0].name, name) == 0)
        {
            *index = index0;
            return TRUE;
        }
    }

    return FALSE;
}

/*! \brief Gets the type of a column.
 *
 *  With an invalid column index, this function returns G_TYPE_INVALID.
 *
 *  \param [in] result The database result.
 *  \param [in] column The zero-based index of the column.
 *  \return The GType of the fileds in the column.
 */
static GType
gparts_mysql_result_get_column_type(GPartsDatabaseResult *result, gint column)
{
    GPartsMySQLResultPrivate *private = GPARTS_MYSQL_RESULT_GET_PRIVATE(result);
    GType type = G_TYPE_INVALID;

    if (column < mysql_num_fields(private->result))
    {
        MYSQL_FIELD *field = mysql_fetch_field_direct(private->result, column);

        switch (field->type)
        {
            case MYSQL_TYPE_FLOAT:
                type = G_TYPE_DOUBLE;
                break;

            case MYSQL_TYPE_LONG:
                type = G_TYPE_INT;
                break;

            default:
                type = G_TYPE_STRING;
        }
    }

    return type;
}

/*! \brief Gets the units for a column.
 *
 *  \param [in] result The database result.
 *  \param [in] column The zero-based index of the column.
 */
static const gchar*
gparts_mysql_result_get_column_units(GPartsDatabaseResult *result, gint column)
{
    /* TODO Temporary code until database gets metadata. */

    struct entry
    {
        const gchar *name;
        const gchar *units;
    };

    struct entry table[] =
    {
        { "IF",         "AMPS",    },
        { "Resistance", "RESISTOR" },
        { "Tolerance",  "PERCENT"  },
        { "VBR",        "VOLTS"    },
        { "VZ",         "VOLTS"    },
        { "VF",         "VOLTS"    },
        { "VR",         "VOLTS"    },
        { "VRWM",       "VOLTS"    },
        { "VZ",         "VOLTS"    },
        { NULL,         "NONE"     }
    };

    GPartsMySQLResultPrivate *private = GPARTS_MYSQL_RESULT_GET_PRIVATE(result);
    struct entry *t = &table[0];
    const gchar *units = "NONE";

    if (column < mysql_num_fields(private->result))
    {
        MYSQL_FIELD *field = mysql_fetch_field_direct(private->result, column);

        while (t->name != NULL && g_strcmp0(t->name, field->name) != 0)
        {
            t++;
        }

        units = t->units;
    }

    return units;
}


/*! \brief Gets the name of a column.
 *
 *  The value must be previously initialized as a G_TYPE_STRING.  If an error
 *  occurs, the value does not get assigned.
 *
 *  \param [in]  result The database result.
 *  \param [in]  column The zero-based index of the column.
 *  \param [out] value  The name of the column.
 */
static void
gparts_mysql_result_get_column_value(GPartsDatabaseResult *result, gint column, GValue *value)
{
    GPartsMySQLResultPrivate *private = GPARTS_MYSQL_RESULT_GET_PRIVATE(result);

    if (column < mysql_num_fields(private->result))
    {
        MYSQL_FIELD *field = mysql_fetch_field_direct(private->result, column);

        g_value_set_string(value, field->name);
    }
}

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
static void
gparts_mysql_result_get_field_value(GPartsDatabaseResult *result, gint row, gint column, GValue *value)
{
    GPartsMySQLResultPrivate *private;
    MYSQL_ROW data;

    g_return_if_fail(result != NULL);
    g_return_if_fail(column >= 0);
    g_return_if_fail(row >= 0);
    g_return_if_fail(value != NULL);

    private = GPARTS_MYSQL_RESULT_GET_PRIVATE(result);

    g_return_if_fail(column < mysql_num_fields(private->result));

    mysql_data_seek(private->result, row);

    data = mysql_fetch_row(private->result);

    if (data != NULL && data[column] != NULL)
    {
        gulong length = *(mysql_fetch_lengths(private->result) + column);
        gchar *string = g_strndup(data[column], length);
        GType type = gparts_mysql_result_get_column_type(result, column);

        if (type == G_TYPE_DOUBLE)
        {
            g_value_init(value, G_TYPE_DOUBLE);
            g_value_set_double(value, g_ascii_strtod(string, NULL));
            g_free(string);
        }
        else if (type == G_TYPE_INT)
        {
            g_value_init(value, G_TYPE_INT);
            g_value_set_int(value, g_ascii_strtoll(string, NULL, 10));
            g_free(string);
        }
        else
        {
            g_value_init(value, G_TYPE_STRING);
            g_value_take_string(value, string);
        }
    }
}

/*! \brief Gets the number of rows in the database result.
 *
 *  \param [in] result The database result.
 *  \return The number of rows in the database result.
 */
static guint
gparts_mysql_result_get_row_count(GPartsDatabaseResult *result)
{
    GPartsMySQLResultPrivate *private = GPARTS_MYSQL_RESULT_GET_PRIVATE(result);

    return mysql_num_rows(private->result);
}

/*! \brief Gets the GType of the GPartsMySQLResult class.
 *
 *  \return The GType of the GPartsMySQLResult class.
 */
GType
gparts_mysql_result_get_type(void)
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsMySQLResultClass),
            NULL,
            NULL,
            gparts_mysql_result_class_init,
            NULL,
            NULL,
            sizeof(GPartsMySQLResult),
            0,
            NULL,
            NULL
            };

        static const GInterfaceInfo iinfo = {
            (GInterfaceInitFunc) gparts_mysql_result_database_init,
            NULL,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gparts-mysql-result",
            &tinfo,
            0
            );

        g_type_add_interface_static(
            type,
            GPARTS_TYPE_DATABASE_RESULT,
            &iinfo
            );
    }
    return type;
}

/*! \brief Create a new GPartsMySQLResult
 *
 *  \param [in] result The MySQL result.
 *  \return A new GPartsMySQLResult.
 */
GPartsMySQLResult*
gparts_mysql_result_new(MYSQL_RES *result)
{
    GPartsMySQLResult *r = g_object_new(GPARTS_TYPE_MYSQL_RESULT, NULL);

    GPartsMySQLResultPrivate *private = GPARTS_MYSQL_RESULT_GET_PRIVATE(r);

    private->result = result;

    return r;
}

