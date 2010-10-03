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

/*! \file gparts-sqlite-result.c
 */

#include <sqlite3.h>

#include "gparts.h"

#include "gparts-sqlite-result.h"

/*! \file gparts-sqlite-result.c
 *
 *  \brief A wrapper for SQLite database results.
 */

typedef struct _GPartsSQLiteResultPrivate GPartsSQLiteResultPrivate;

struct _GPartsSQLiteResultPrivate
{
    GPtrArray    *columns;
    GPtrArray    *rows;
};

#define GPARTS_SQLITE_RESULT_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_SQLITE_RESULT, GPartsSQLiteResultPrivate)

static void
gparts_sqlite_result_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_sqlite_result_finalize(GObject *object);

static guint
gparts_sqlite_result_get_column_count(GPartsDatabaseResult *result);

static gboolean
gparts_sqlite_result_get_column_index(GPartsDatabaseResult *result, const gchar *name, gint *index);

static GType
gparts_sqlite_result_get_column_type(GPartsDatabaseResult *result, gint column);

static void
gparts_sqlite_result_get_column_value(GPartsDatabaseResult *result, gint column, GValue *value);

static void
gparts_sqlite_result_get_field_value(GPartsDatabaseResult *result, gint row, gint column, GValue *value);

static guint
gparts_sqlite_result_get_row_count(GPartsDatabaseResult *result);

static void
gparts_sqlite_result_init(GTypeInstance *instance, gpointer g_class);

static void
gparts_sqlite_result_process_columns(GPartsSQLiteResult *result, sqlite3_stmt *stmt);

static void
gparts_sqlite_result_process_row(GPartsSQLiteResult *result, sqlite3_stmt *stmt);

/*! \brief Initialize class data.
 *
 *  \param [in] g_class
 *  \param [in] g_class_data
 */
static void
gparts_sqlite_result_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);
    GPartsDatabaseResultClass *klasse = GPARTS_DATABASE_RESULT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsSQLiteResultPrivate));

    object_class->finalize = gparts_sqlite_result_finalize;

    klasse->get_column_count = gparts_sqlite_result_get_column_count;
    klasse->get_column_index = gparts_sqlite_result_get_column_index;
    klasse->get_column_type  = gparts_sqlite_result_get_column_type;
    klasse->get_column_value = gparts_sqlite_result_get_column_value;
    klasse->get_field_value  = gparts_sqlite_result_get_field_value;
    klasse->get_row_count    = gparts_sqlite_result_get_row_count;
}

/*! \brief Deallocate all resources.
 *
 *  This function performs the second and last stage of object destruction.
 *
 *  \param [in] object The object to finalize.
 */
static void
gparts_sqlite_result_finalize(GObject *object)
{
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_ptr_array_free(privat->columns, TRUE);
        g_ptr_array_free(privat->rows, TRUE);
    }

    misc_object_chain_finalize(object);
}

/*! \brief Gets the number of columns in the database result.
 *
 *  \param [in] result The database result.
 *  \return The number of columns in the database result.
 */
static guint
gparts_sqlite_result_get_column_count(GPartsDatabaseResult *result)
{
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(result);
    guint column_count = 0;

    if ((privat != NULL) && (privat->columns != NULL))
    {
        column_count = privat->columns->len;
    }

    return column_count;
}

/*! \brief Untested WIP.
 */
static gboolean
gparts_sqlite_result_get_column_index(GPartsDatabaseResult *result, const gchar *name, gint *index)
{
    gboolean found = FALSE;
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(result);

    if ((privat != NULL) && (privat->columns != NULL))
    {
        guint i;

        for (i=0; i<privat->columns->len; i++)
        {
            GPartsColumnData *data = (GPartsColumnData*) g_ptr_array_index(privat->columns, i);

            if (g_strcmp0(name, data->name) == 0)
            {
                if (index != 0)
                {
                    *index = i;
                }

                found = TRUE;

                break;
            }
        }
    }

    return found;
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
gparts_sqlite_result_get_column_type(GPartsDatabaseResult *result, gint column)
{
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(result);
    GType type = G_TYPE_INVALID;

    if ((privat != NULL) && (privat->columns != NULL) && (column < privat->columns->len))
    {
        GPartsColumnData *data = (GPartsColumnData*) g_ptr_array_index(privat->columns, column);

        type = data->type;
    }

    return type;
}

#if 0
static GPartsUnits*
gparts_sqlite_result_get_column_in_units(const gchar *name, gdouble value)
{
    /* TODO Temporary code until database gets metadata. */

    typedef GPartsUnits* (*GPartsUnitsNewFunc)(gdouble value);

    struct entry
    {
        const gchar        *name;
        GPartsUnitsNewFunc func;
    };

    static const struct entry table[] =
    {
        { "Capacitance", gparts_units_new_farads  },
        { "PD",          gparts_units_new_watts   },
        { "IC",          gparts_units_new_amps    },
        { "FT",          gparts_units_new_hertz   },
        { "Frequency",   gparts_units_new_hertz   },
        { "Inductance",  gparts_units_new_henrys  },
        { "IF",          gparts_units_new_amps    },
        { "Resistance",  gparts_units_new_ohms    },
        { "Tolerance",   gparts_units_new_pp      },
        { "Stability",   gparts_units_new_pp      },
        { "VBR",         gparts_units_new_volts   },
        { "VZ",          gparts_units_new_volts   },
        { "VF",          gparts_units_new_volts   },
        { "VR",          gparts_units_new_volts   },
        { "VRWM",        gparts_units_new_volts   },
        { "VZ",          gparts_units_new_volts   },
        { "MinTemp",     gparts_units_new_celcius },
        { "MaxTemp",     gparts_units_new_celcius },
        { NULL,          gparts_units_new_none    }
    };

    const struct entry *t = &table[0];
    GPartsUnits *units = NULL;

    while (units == NULL)
    {
        if ((t->name == NULL) || (g_strcmp0(t->name, name) == 0))
        {
            units = t->func(value);
        }
        else
        {
            t++;
        }
    }

    return units;
}
#endif

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
gparts_sqlite_result_get_column_value(GPartsDatabaseResult *result, gint column, GValue *value)
{
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(result);

    if ((privat != NULL) && (privat->columns != NULL) && (column < privat->columns->len))
    {
        GPartsColumnData *data = (GPartsColumnData*) g_ptr_array_index(privat->columns, column);

        g_value_set_string(value, data->name);
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
gparts_sqlite_result_get_field_value(GPartsDatabaseResult *result, gint row, gint column, GValue *value)
{
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(result);

    if ((privat != NULL) && (privat->rows != NULL) && (row < privat->rows->len))
    {
        GValueArray *row_data = (GValueArray*) g_ptr_array_index(privat->rows, row);

        if ((row_data != NULL) && (column < row_data->n_values))
        {
            GValue *field = g_value_array_get_nth(row_data, column);

            if (field != NULL)
            {
                g_value_init(value, G_VALUE_TYPE(field));
                g_value_copy(field, value);
            }
        }
    }
}

/*! \brief Gets the number of rows in the database result.
 *
 *  \param [in] result The database result.
 *  \return The number of rows in the database result.
 */
static guint
gparts_sqlite_result_get_row_count(GPartsDatabaseResult *result)
{
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(result);
    guint row_count = 0;

    if ((privat != NULL) && (privat->rows != NULL))
    {
        row_count = privat->rows->len;
    }

    return row_count;
}

/*! \brief Gets the GType of the GPartsSQLiteResult class.
 *
 *  \return The GType of the GPartsSQLiteResult class.
 */
GType
gparts_sqlite_result_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsSQLiteResultClass),    /* class_size */
            NULL,                               /* base_init */
            NULL,                               /* base_finalize */
            gparts_sqlite_result_class_init,    /* class_init */
            NULL,                               /* class_finalize */
            NULL,                               /* class_data */
            sizeof(GPartsSQLiteResult),         /* instance_size */
            0,                                  /* n_preallocs */
            gparts_sqlite_result_init,          /* instance_init */
            NULL                                /* value_table */
            };

        type = g_type_register_static(
            GPARTS_TYPE_DATABASE_RESULT,
            "gparts-sqlite-result",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gparts_sqlite_result_init(GTypeInstance *instance, gpointer g_class)
{
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->columns = g_ptr_array_new_with_free_func((GDestroyNotify) gparts_column_data_free);
        privat->rows    = g_ptr_array_new_with_free_func((GDestroyNotify) g_value_array_free);
    }
}

/*! \brief Create a new GPartsSQLiteResult
 *
 *  \param [in] result The SQLite result.
 *  \return A new GPartsSQLiteResult.
 */
GPartsSQLiteResult*
gparts_sqlite_result_new(sqlite3_stmt *stmt)
{
    GPartsSQLiteResult *result = NULL;

    if (stmt != NULL)
    {
        gint status;

        result = g_object_new(GPARTS_TYPE_SQLITE_RESULT, NULL);

        status = sqlite3_step(stmt);

        if (status == SQLITE_ROW)
        {
            gparts_sqlite_result_process_columns(result, stmt);
        }

        while (status == SQLITE_ROW)
        {
            gparts_sqlite_result_process_row(result, stmt);

            status = sqlite3_step(stmt);
        }
    }

    return result;
}

static void
gparts_sqlite_result_process_columns(GPartsSQLiteResult *result, sqlite3_stmt *stmt)
{
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(result);

    if (privat != NULL)
    {
        gint columns = sqlite3_column_count(stmt);
        gint index;

        for (index=0; index<columns; index++)
        {
            GPartsColumnData *data = gparts_column_data_new();

            data->name = g_strdup(sqlite3_column_name(stmt, index));

            switch (sqlite3_column_type(stmt, index))
            {
                case SQLITE_FLOAT:
                    data->type = G_TYPE_DOUBLE;
                    break;

                case SQLITE_INTEGER:
                    data->type = G_TYPE_INT64;
                    break;

                case SQLITE_TEXT:
                    data->type = G_TYPE_STRING;
                    break;

                default:
                    data->type = G_TYPE_INVALID;
            }

            g_ptr_array_add(privat->columns, data);
        }
    }
}

static void
gparts_sqlite_result_process_row(GPartsSQLiteResult *result, sqlite3_stmt *stmt)
{
    GPartsSQLiteResultPrivate *privat = GPARTS_SQLITE_RESULT_GET_PRIVATE(result);

    if (privat != NULL)
    {
        gint columns = sqlite3_column_count(stmt);
        gint index;
        GValueArray *row = g_value_array_new(columns);

        for (index=0; index<columns; index++)
        {
            GValue value = {0};

            switch (sqlite3_column_type(stmt, index))
            {
                case SQLITE_FLOAT:
                    g_value_init(&value, G_TYPE_DOUBLE);
                    g_value_set_double(&value, sqlite3_column_double(stmt, index));
                    break;

                case SQLITE_INTEGER:
                    g_value_init(&value, G_TYPE_INT64);
                    g_value_set_int64(&value, sqlite3_column_int64(stmt, index));
                    break;

                case SQLITE_TEXT:
                    g_value_init(&value, G_TYPE_STRING);
                    g_value_set_string(&value, sqlite3_column_text(stmt, index));
                    break;

                default:
                    break;
            }

            g_value_array_append(row, &value);

            g_value_unset(&value);
        }

        g_ptr_array_add(privat->rows, row);
    }
}

