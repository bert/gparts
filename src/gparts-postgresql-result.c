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

/*! \file gparts-postgresql-result.c
 */

#include <glib-object.h>
#include <postgresql.h>

#include "gparts-units.h"

#include "gparts-database-result.h"
#include "gparts-postgresql-result.h"

/*! \file gparts-postgresql-result.c
 *
 *  \brief A wrapper for PostgreSQL database results.
 */

typedef struct _GPartsPostgreSQLResultPrivate GPartsPostgreSQLResultPrivate;

struct _GPartsPostgreSQLResultPrivate
{
    PGresult *result;
};

#define GPARTS_POSTGRESQL_RESULT_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_POSTGRESQL_RESULT, GPartsPostgreSQLResultPrivate)

static void
gparts_postgresql_result_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_postgresql_result_finalize(GObject *object);

static guint
gparts_postgresql_result_get_column_count(GPartsDatabaseResult *result);

static gboolean
gparts_postgresql_result_get_column_index(GPartsDatabaseResult *result, const gchar *name, gint *index);

static GType
gparts_postgresql_result_get_column_type(GPartsDatabaseResult *result, gint column);

static void
gparts_postgresql_result_get_column_value(GPartsDatabaseResult *result, gint column, GValue *value);

static void
gparts_postgresql_result_get_field_value(GPartsDatabaseResult *result, gint row, gint column, GValue *value);

static guint
gparts_postgresql_result_get_row_count(GPartsDatabaseResult *result);

/*! \brief Initialize class data.
 *
 *  \param [in] g_class
 *  \param [in] g_class_data
 */
static void
gparts_postgresql_result_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);
    GPartsDatabaseResultClass *klasse = GPARTS_DATABASE_RESULT_CLASS(g_class);

    g_type_class_add_private(
        g_class,
        sizeof(GPartsPostgreSQLResultPrivate)
        );

    object_class->finalize = gparts_postgresql_result_finalize;

    klasse->get_column_count = gparts_postgresql_result_get_column_count;
    klasse->get_column_index = gparts_postgresql_result_get_column_index;
    klasse->get_column_type  = gparts_postgresql_result_get_column_type;
    klasse->get_column_value = gparts_postgresql_result_get_column_value;
    klasse->get_field_value  = gparts_postgresql_result_get_field_value;
    klasse->get_row_count    = gparts_postgresql_result_get_row_count;
}

/*! \brief Deallocate all resources.
 *
 *  This function performs the second and last stage of object destruction.
 *
 *  \param [in] object The object to finalize.
 */
static void
gparts_postgresql_result_finalize(GObject *object)
{
    GPartsPostgreSQLResultPrivate *privat = GPARTS_POSTGRESQL_RESULT_GET_PRIVATE(object);

    if (privat != NULL)
    {
        PQClear(privat->result);
    }

    misc_object_chain_finalize(object);
}

/*! \brief Gets the number of columns in the database result.
 *
 *  \param [in] result The database result.
 *  \return The number of columns in the database result.
 */
static guint
gparts_postgresql_result_get_column_count(GPartsDatabaseResult *result)
{
    guint column_count = 0;
    GPartsPostgreSQLResultPrivate *privat = GPARTS_POSTGRESQL_RESULT_GET_PRIVATE(result);

    if (privat != NULL)
    {
        column_count = PQnfields(privat->result);
    }

    return column_count;
}

/*! \brief Untested WIP.
 */
static gboolean
gparts_postgresql_result_get_column_index(GPartsDatabaseResult *result, const gchar *name, gint *index)
{
    GPartsPostgreSQLResultPrivate *privat = GPARTS_POSTGRESQL_RESULT_GET_PRIVATE(result);
    gboolean success = FALSE;

    if (privat != NULL)
    {
        gint index0 = PQfnumber(privat->result, name);

        if (index0 >= 0)
        {
            if (index != NULL)
            {
                *index = index0;
            }

            success = TRUE;
        }
    }

    return success;
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
gparts_postgresql_result_get_column_type(GPartsDatabaseResult *result, gint column)
{
    GPartsPostgreSQLResultPrivate *privat = GPARTS_POSTGRESQL_RESULT_GET_PRIVATE(result);
    GType type = G_TYPE_INVALID;

    if (privat != NULL)
    {
        Oid o = PQftype(privat->result, column);

        switch (field->type)
        {
#if 0
            case POSTGRESQL_TYPE_FLOAT:
                type = GPARTS_TYPE_UNITS;
                break;

            case POSTGRESQL_TYPE_LONG:
                type = G_TYPE_INT;
                break;
#endif
            default:
                type = G_TYPE_STRING;
            }
    }

    return type;
}

static GPartsUnits*
gparts_postgresql_result_get_column_in_units(const gchar *name, gdouble value)
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
gparts_postgresql_result_get_column_value(GPartsDatabaseResult *result, gint column, GValue *value)
{
    GPartsPostgreSQLResultPrivate *privat = GPARTS_POSTGRESQL_RESULT_GET_PRIVATE(result);

    if (privat != NULL)
    {
        if (column < postgresql_num_fields(privat->result))
        {
            const char* name = PQfname(privat->result, column);

            g_value_take_string(value, g_strdup(name));
        }
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
gparts_postgresql_result_get_field_value(GPartsDatabaseResult *result, gint row, gint column, GValue *value)
{
    GPartsPostgreSQLResultPrivate *private;
    char* data;

    g_return_if_fail(result != NULL);
    g_return_if_fail(column >= 0);
    g_return_if_fail(row >= 0);
    g_return_if_fail(value != NULL);

    private = GPARTS_POSTGRESQL_RESULT_GET_PRIVATE(result);

    g_return_if_fail(column < postgresql_num_fields(private->result));

    data = PQgetvalue(private->result, row, column);

    if (data != NULL)
    {
        gulong length = *(postgresql_fetch_lengths(private->result) + column);
        gchar *string = g_strndup(data[column], length);
        GType type = gparts_postgresql_result_get_column_type(result, column);

        if (type == G_TYPE_DOUBLE)
        {
            g_value_init(value, G_TYPE_DOUBLE);
            g_value_set_double(value, g_ascii_strtod(string, NULL));
            g_free(string);
        }
        else if (type == GPARTS_TYPE_UNITS)
        {
            POSTGRESQL_FIELD *field = postgresql_fetch_field_direct(private->result, column);
            g_value_init(value, GPARTS_TYPE_UNITS);
            g_value_take_boxed(
                value,
                gparts_postgresql_result_get_column_in_units(
                    field->name,
                    g_ascii_strtod(string, NULL)
                    )
                );
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
gparts_postgresql_result_get_row_count(GPartsDatabaseResult *result)
{
    GPartsPostgreSQLResultPrivate *privat = GPARTS_POSTGRESQL_RESULT_GET_PRIVATE(result);
    guint row_count = 0;

    if (privat != NULL)
    {
        row_count = PQntuples(privat->result);
    }

    return row_count;
}

/*! \brief Gets the GType of the GPartsPostgreSQLResult class.
 *
 *  \return The GType of the GPartsPostgreSQLResult class.
 */
GType
gparts_postgresql_result_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsPostgreSQLResultClass),
            NULL,
            NULL,
            gparts_postgresql_result_class_init,
            NULL,
            NULL,
            sizeof(GPartsPostgreSQLResult),
            0,
            NULL,
            NULL
            };

        type = g_type_register_static(
            GPARTS_TYPE_DATABASE_RESULT,
            "gparts-postgresql-result",
            &tinfo,
            0
            );
    }

    return type;
}

/*! \brief Create a new GPartsPostgreSQLResult
 *
 *  \param [in] result The PostgreSQL result.
 *  \return A new GPartsPostgreSQLResult.
 */
GPartsPostgreSQLResult*
gparts_postgresql_result_new(PGresult *result)
{
    GPartsPostgreSQLResult *r = g_object_new(GPARTS_TYPE_POSTGRESQL_RESULT, NULL);

    GPartsPostgreSQLResultPrivate *private = GPARTS_POSTGRESQL_RESULT_GET_PRIVATE(r);

    private->result = result;

    return r;
}

