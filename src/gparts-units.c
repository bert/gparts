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

/*! \file gparts-units.c 
 */

#include <math.h>
#include <gtk/gtk.h>

#include "gparts-database-result.h"
#include "gparts-result-model.h"

/*! \file gparts-units.c
 *
 *  \brief Formats numeric data with units of measure.
 *
 *  \par Supported Units
 *  \c AMPS Current.
 *
 *  \c PERCENT A percentage.
 *
 *  \c RESISTOR A resistor's value.
 *
 *  \c VOLTS Voltage.
 */

/*! \todo Below needs to work with all compilers.  The following will work in
 * GCC even without C99 support, but it will issue a warning.
 */
//#ifdef __STDC__VERSION__
//#if __STDC_VERSION__ >= 199901L
#define GPARTS_SYMBOL_MICRO "\u00B5"
#define GPARTS_SYMBOL_OHM   "\u2126"
//#endif
//#else
//#define GPARTS_SYMBOL_MICRO "u"
//#define GPARTS_SYMBOL_OHM   ""
//#endif

typedef struct _GPartsUnitsCellDataFunc GPartsUnitsCellDataFunc;
typedef struct _GPartsUnitsFormat GPartsUnitsFormat;
typedef struct _GPartsUnitsMetricPrefix GPartsUnitsMetricPrefix;
typedef struct _GPartsUnitsPrivate GPartsUnitsPrivate;

/*  \brief Holds some data
 */
struct _GPartsUnitsCellDataFunc
{
    const gchar         *name;
    GtkTreeCellDataFunc func;
    const gchar         *symbol;
};

/*! \brief Junk
 *  \private
 *
 *  \todo Get rid of this table by using math functions to calculate the format.
 */
struct _GPartsUnitsFormat
{
    const gchar *string;
    float       value;
};

/*! \brief Structure for an entry in a lookup table.
 *  \private
 *
 *
 *
 *
 *
 */
struct _GPartsUnitsMetricPrefix
{
    const gchar *prefix;
    const gchar *symbol;
    const gchar *symbol2;
    float       value;
};

/*!
 *  \private
 *
 *
 *
 */
struct _GPartsUnitsPrivate
{
    gint       column;
    const char *symbol;
};

static void
gparts_units_cell_format_generic(GtkTreeViewColumn *column, GtkCellRenderer *cell, GtkTreeModel *model, GtkTreeIter *iter, gpointer data);

static void
gparts_units_cell_format_resistor(GtkTreeViewColumn *column, GtkCellRenderer *cell, GtkTreeModel *model, GtkTreeIter *iter, gpointer data);

static void
gparts_units_cell_format_percent(GtkTreeViewColumn *column, GtkCellRenderer *cell, GtkTreeModel *model, GtkTreeIter *iter, gpointer data);

static const GPartsUnitsCellDataFunc*
gparts_units_find_cell_data_func(const gchar *name);

static const gchar*
gparts_units_find_format(gdouble value);

static const GPartsUnitsMetricPrefix*
gparts_units_find_metric_prefix(gdouble value);

/*
 *
 *
 *
 *  The last entry in the table must have a function pointer of NULL.
 */
static const GPartsUnitsCellDataFunc gparts_units_cell_data_func[] =
{
    { "AMPS",     gparts_units_cell_format_generic,  "A"               },
    { "PERCENT",  gparts_units_cell_format_percent,  NULL              },
    { "RESISTOR", gparts_units_cell_format_resistor, GPARTS_SYMBOL_OHM },
    { "VOLTS",    gparts_units_cell_format_generic,  "V"               },
    { "NONE",     NULL,                              NULL              }
};

/*
 * Three significant digit table.
 *
 */
static const GPartsUnitsFormat gparts_units_format[] =
{
    { "%.0f %s%s", 1000 },
    { "%.0f %s%s",  100 },
    { "%.1f %s%s",   10 },
    { "%.2f %s%s",    1 },
    { "%.0f %s%s",    0 }
};

/*!
 *
 *
 *  \todo Add sentinel to the table.
 */
static const GPartsUnitsMetricPrefix gparts_units_metric_prefixes[] =
{
    { "yotta",  "Y",                  "Y",  1e24 },
    { "zetta",  "Z",                  "Z",  1e21 },
    { "exa",    "E",                  "E",  1e18 },
    { "peta",   "P",                  "P",  1e15 },
    { "tera",   "T",                  "T",  1e12 },
    { "giga",   "G",                  "G",   1e9 },
    { "mega",   "M",                  "M",   1e6 },
    { "kilo",   "k",                  "k",   1e3 },
    { "",       "",                   "",      1 },
    { "milli",  "m",                  "m",  1e-3 },
    { "micro",  GPARTS_SYMBOL_MICRO,  "u",  1e-6 },
    { "nano",   "n",                  "n",  1e-9 },
    { "pico",   "p",                  "p", 1e-12 },
    { "femto",  "f",                  "f", 1e-15 },
    { "atto",   "a",                  "a", 1e-18 },
    { "zepto",  "z",                  "z", 1e-21 },
    { "yocto",  "y",                  "y", 1e-24 },
    { "",       "",                   "",      0 }
};

/*! \brief Sets the numeric format and units for a GtkTreeViewColumn's cells.
 *  \public
 *
 *  \param [in] column   The tree view column to recieve the format.
 *  \param [in] renderer The cell renerer within the tree view column.
 *  \param [in] index    The tree model's zero based column index of the data.
 *  \param [in] units    The name of the numeric format and units to use.
 */
void
gparts_units_attach_cell_data_func(GtkTreeViewColumn *column, GtkCellRenderer *renderer, gint index, const gchar *units)
{
    GPartsUnitsCellDataFunc *func = gparts_units_find_cell_data_func(units);

    GPartsUnitsPrivate *private = g_new0(GPartsUnitsPrivate,1);

    private->column = index;
    private->symbol = func->symbol;

    gtk_tree_view_column_set_cell_data_func(
        column,
        renderer,
        func->func,
        private,
        g_free
        );
}

/*! \brief Format a cell with a metric value.
 *
 *
 *
 *  \param [in] column The GtkTreeViewColumn.
 *  \param [in] cell   The GtkCellRendererText.
 *  \param [in] model  A GtkTreeModel where the original data resides.
 *  \param [in] iter   A GtkTreeIter for the row being formatted.
 *  \param [in] data   The resitor value's zero based column index, cast into a pointer.
 */
static void
gparts_units_cell_format_generic(GtkTreeViewColumn *column, GtkCellRenderer *cell, GtkTreeModel *model, GtkTreeIter *iter, gpointer data)
{
    GValue value = {0};

    gtk_tree_model_get_value(
        model,
        iter,
        ((GPartsUnitsPrivate*) data)->column,
        &value
        );

    if (G_IS_VALUE(&value) && G_VALUE_HOLDS_DOUBLE(&value))
    {
        double n = g_value_get_double(&value);
        GString *string = g_string_new("");

        const GPartsUnitsMetricPrefix* prefix = gparts_units_find_metric_prefix(n);

        const gchar *format = gparts_units_find_format(n/prefix->value);

        g_string_printf(string, format, n/prefix->value, prefix->symbol, ((GPartsUnitsPrivate*) data)->symbol);

        g_value_unset(&value);
        g_value_init(&value, G_TYPE_STRING);

        g_value_take_string(&value, string->str);
        g_string_free(string, FALSE);

        g_object_set_property(G_OBJECT(cell), "text", &value);
        g_value_unset(&value);
    }
}

/*! \brief Format a cell as a resistor's value.
 *
 *  \param [in] column The GtkTreeViewColumn.
 *  \param [in] cell   The GtkCellRendererText.
 *  \param [in] model  A GtkTreeModel where the original data resides.
 *  \param [in] iter   A GtkTreeIter for the row being formatted.
 *  \param [in] data   The resitor value's zero based column index, cast into a pointer.
 *
 *  \todo Use the resistor's tolerance (the next column) to determine the number
 *  of digits to show.
 */
static void
gparts_units_cell_format_resistor(GtkTreeViewColumn *column, GtkCellRenderer *cell, GtkTreeModel *model, GtkTreeIter *iter, gpointer data)
{
    GValue value = {0};

    gtk_tree_model_get_value(
        model,
        iter,
        ((GPartsUnitsPrivate*) data)->column,
        &value
        );

    if (G_IS_VALUE(&value) && G_VALUE_HOLDS_DOUBLE(&value))
    {
        double n = g_value_get_double(&value);
        GString *string = g_string_new("");

        const GPartsUnitsMetricPrefix* prefix = gparts_units_find_metric_prefix(n);

        const gchar *format = gparts_units_find_format(n/prefix->value);

        g_string_printf(string, format, n/prefix->value, prefix->symbol, GPARTS_SYMBOL_OHM);

        g_value_unset(&value);
        g_value_init(&value, G_TYPE_STRING);

        g_value_take_string(&value, string->str);
        g_string_free(string, FALSE);

        g_object_set_property(G_OBJECT(cell), "text", &value);
        g_value_unset(&value);
    }
}

/*! \brief Format a cell as a percentage.
 *
 *  \param [in] column The GtkTreeViewColumn.
 *  \param [in] cell   The GtkCellRendererText.
 *  \param [in] model  A GtkTreeModel where the original data resides.
 *  \param [in] iter   A GtkTreeIter for the row being formatted.
 *  \param [in] data   The model's zero based column index, cast into a pointer.
 *
 *  \todo FIXME With a fractional percent, this function will only display the most
 *  significant digit.  So, "0.15%" becomes "0.1%."  This function should make
 *  an attempt to display all digits, without displaying additional trailing
 *  zeros.
 */
static void
gparts_units_cell_format_percent(GtkTreeViewColumn *column, GtkCellRenderer *cell, GtkTreeModel *model, GtkTreeIter *iter, gpointer data)
{
    GValue value = {0};

    gtk_tree_model_get_value(
        model,
        iter,
        ((GPartsUnitsPrivate*) data)->column,
        &value
        );

    if (G_IS_VALUE(&value) && G_VALUE_HOLDS_DOUBLE(&value))
    {
        gint    digits = 0;
        gdouble percent = g_value_get_double(&value) * 100;
        GString *string = g_string_new("");

        if (percent != 0)
        {
            digits = ceil(-log10(fabs(percent)));

            if (digits < 0)
            {
                digits = 0;
            }
        }

        g_string_printf(string, "%.*f %%", digits, percent);

        g_value_unset(&value);
        g_value_init(&value, G_TYPE_STRING);

        g_value_take_string(&value, string->str);
        g_string_free(string, FALSE);

        g_object_set_property(G_OBJECT(cell), "text", &value);
        g_value_unset(&value);
    }
}

/*! \brief Finds the format data using the format name.
 *
 *  \param [in] name
 *  \return A pointer to a GPartsUnitsCellDataFunc.  This function does not
 *  return NULL.
 */
static const GPartsUnitsCellDataFunc*
gparts_units_find_cell_data_func(const gchar *name)
{
    GPartsUnitsCellDataFunc *func = &gparts_units_cell_data_func[0];

    while (func->func != NULL && g_strcmp0(name, func->name) != 0)
    {
        func++;
    }

    return func;
}

/* \todo Get rid of this function by using math functions to calculate the format.
 */
static const gchar*
gparts_units_find_format(gdouble value)
{
    const GPartsUnitsFormat *format = &gparts_units_format[0];

    while (fabs(value) < format->value)
    {
        format++;
    }

    return format->string;
}

/*! \brief Finds the right metric prefix for a given value.
 *
 *  \param [in] value The value in prefix-less units.
 *  \return A pointer to a GPartsUnitsMetricPrefix.  This function does not
 *  return NULL.
 */
static const GPartsUnitsMetricPrefix*
gparts_units_find_metric_prefix(gdouble value)
{
    const GPartsUnitsMetricPrefix *prefix = &gparts_units_metric_prefixes[0];

    while (fabs(value) < prefix->value)
    {
        prefix++;
    }

    return prefix;
}

