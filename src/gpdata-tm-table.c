/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2011 Edward C. Hennessy
 * Copyright (C) 2011 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpdata-factory.c
 */

#include <glib-object.h>

#include "misc-object.h"

#include "gpdata.h"

#define GPDATA_TM_TABLE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPDATA_TYPE_TM_TABLE,GPDataTMTablePrivate))

enum
{
    GPDATA_TM_TABLE_COLUMN_COUNT = 1,
    GPDATA_TM_TABLE_COLUMNS,
    GPDATA_TM_TABLE_ROW_COUNT
};

typedef struct _GPDataTMTablePrivate GPDataTMTablePrivate;

struct _GPDataTMTablePrivate
{
    GPtrArray *columns;
};



static void
gpdata_tm_table_class_init(gpointer g_class, gpointer g_class_data);

static void
gpdata_tm_table_dispose(GObject *object);

static void
gpdata_tm_table_finalize(GObject *object);

static void
gpdata_tm_table_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpdata_tm_table_init(GTypeInstance *instance, gpointer g_class);

static void
gpdata_tm_table_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



void
gpdata_tm_table_add_column(GPDataTMTable *table, GPDataTMColumn *column)
{
    if (column != NULL)
    {
        GPDataTMTablePrivate *privat = GPDATA_TM_TABLE_GET_PRIVATE(table);

        if (privat != NULL)
        {
            if (privat->columns != NULL)
            {
                g_object_ref(column);

                g_ptr_array_add(privat->columns, column);

                g_object_notify(G_OBJECT(table), "columns");
                g_object_notify(G_OBJECT(table), "column-count");
            }
        }
    }
}

static void
gpdata_tm_table_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(GPDataTMTablePrivate));

    klasse->dispose  = gpdata_tm_table_dispose;
    klasse->finalize = gpdata_tm_table_finalize;

    klasse->get_property = gpdata_tm_table_get_property;
    klasse->set_property = gpdata_tm_table_set_property;

    g_object_class_install_property(
        klasse,
        GPDATA_TM_TABLE_COLUMN_COUNT,
        g_param_spec_uint(
            "column-count",
            "Column Count",
            "Column Count",
            0,
            G_MAXUINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );

    /* The columns parameter is currently neither readable or writable. The */
    /* property is installed only for the notify::columns signal.           */

    g_object_class_install_property(
        klasse,
        GPDATA_TM_TABLE_COLUMNS,
        g_param_spec_pointer(
            "columns",
            "Columns",
            "Columns",
            G_PARAM_LAX_VALIDATION | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPDATA_TM_TABLE_ROW_COUNT,
        g_param_spec_uint(
            "row-count",
            "Row Count",
            "Row Count",
            0,
            G_MAXUINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpdata_tm_table_dispose(GObject *object)
{
    GPDataTMTablePrivate *privat = GPDATA_TM_TABLE_GET_PRIVATE(object);

    if (privat != NULL)
    {
        if (privat->columns != NULL)
        {
            /* destroying array here to call GDestroyFunc on each element */

            g_ptr_array_free(privat->columns, TRUE);
            privat->columns = NULL;
        }
    }

    misc_object_chain_dispose(object);
}

static void
gpdata_tm_table_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

GPDataTMColumn*
gpdata_tm_table_get_column(const GPDataTMTable *table, guint index)
{
    GPDataTMColumn *column = NULL;
    GPDataTMTablePrivate *privat = GPDATA_TM_TABLE_GET_PRIVATE(table);

    if (privat != NULL)
    {
        if (privat->columns != NULL)
        {
            column = g_ptr_array_index(privat->columns, index);
        }

        if (column != NULL)
        {
            g_object_ref(column);
        }
    }

    return column;
}

guint
gpdata_tm_table_get_column_count(const GPDataTMTable *table)
{
    guint count = 0;
    GPDataTMTablePrivate *privat = GPDATA_TM_TABLE_GET_PRIVATE(table);

    if (privat != NULL)
    {
        if (privat->columns != NULL)
        {
            count = privat->columns->len;
        }
    }

    return count;
}

static void
gpdata_tm_table_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPDataTMTable *table = GPDATA_TM_TABLE(object);

    if (table != NULL)
    {
        switch (property_id)
        {
            case GPDATA_TM_TABLE_COLUMN_COUNT:
                g_value_set_uint(value, gpdata_tm_table_get_column_count(table));
                break;

            case GPDATA_TM_TABLE_ROW_COUNT:
                g_value_set_uint(value, gpdata_tm_table_get_row_count(table));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

guint
gpdata_tm_table_get_row_count(const GPDataTMTable *table)
{
    /* \todo */

    return 10;
}

GType
gpdata_tm_table_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPDataTMTableClass),    /* class_size */
            NULL,                          /* base_init */
            NULL,                          /* base_finalize */
            gpdata_tm_table_class_init,    /* class_init */
            NULL,                          /* class_finalize */
            NULL,                          /* class_data */
            sizeof(GPDataTMTable),         /* instance_size */
            0,                             /* n_preallocs */
            gpdata_tm_table_init,          /* instance_init */
            NULL                           /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            NULL,                              /* interface_init */
            NULL,                              /* interface_finalize */
            NULL                               /* interface_data */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPDataTMTable",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GPDATA_TYPE_OP_BUILDABLE, &iinfo);
    }

    return type;
}

static void
gpdata_tm_table_init(GTypeInstance *instance, gpointer g_class)
{
    GPDataTMTablePrivate *privat = GPDATA_TM_TABLE_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->columns = g_ptr_array_new_with_free_func(g_object_unref);
    }
}

static void
gpdata_tm_table_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPDataTMTable *table = GPDATA_TM_TABLE(object);

    if (table != NULL)
    {
        switch (property_id)
        {
            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

