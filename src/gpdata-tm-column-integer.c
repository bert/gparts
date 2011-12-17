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

/*! \file gpdata-tm-column-integer.c
 */

#include <glib-object.h>

#include "misc-object.h"

#include "gpdata.h"

#define GPDATA_TM_COLUMN_INTEGER_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPDATA_TYPE_TM_COLUMN_INTEGER,GPDataTMColumnIntegerPrivate))

enum
{
    GPDATA_TM_COLUMN_INTEGER_MAX = 1,
    GPDATA_TM_COLUMN_INTEGER_MIN,
    GPDATA_TM_COLUMN_INTEGER_NAME
};

typedef struct _GPDataTMColumnIntegerPrivate GPDataTMColumnIntegerPrivate;

struct _GPDataTMColumnIntegerPrivate
{
    gint  imax;
    gint  imin;
    gchar *name;
};



static void
gpdata_tm_column_integer_class_init(gpointer g_class, gpointer g_class_data);

static void
gpdata_tm_column_integer_dispose(GObject *object);

static void
gpdata_tm_column_integer_finalize(GObject *object);

static void
gpdata_tm_column_integer_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpdata_tm_column_integer_init(GTypeInstance *instance, gpointer g_class);

static void
gpdata_tm_column_integer_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
gpdata_tm_column_integer_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(GPDataTMColumnIntegerPrivate));

    klasse->dispose  = gpdata_tm_column_integer_dispose;
    klasse->finalize = gpdata_tm_column_integer_finalize;

    klasse->get_property = gpdata_tm_column_integer_get_property;
    klasse->set_property = gpdata_tm_column_integer_set_property;

    g_object_class_install_property(
        klasse,
        GPDATA_TM_COLUMN_INTEGER_MAX,
        g_param_spec_int(
            "max",
            "Max",
            "Max",
            G_MININT,
            G_MAXINT,
            G_MAXINT,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPDATA_TM_COLUMN_INTEGER_MIN,
        g_param_spec_int(
            "min",
            "Min",
            "Min",
            G_MININT,
            G_MAXINT,
            G_MININT,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPDATA_TM_COLUMN_INTEGER_NAME,
        g_param_spec_string(
            "name",
            "Name",
            "Name",
            NULL,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpdata_tm_column_integer_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}

static void
gpdata_tm_column_integer_finalize(GObject *object)
{
    GPDataTMColumnIntegerPrivate *privat = GPDATA_TM_COLUMN_INTEGER_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_free(privat->name);
        privat->name = NULL;
    }

    misc_object_chain_finalize(object);
}

gint
gpdata_tm_column_integer_get_max(GPDataTMColumnInteger *column)
{
    GPDataTMColumnIntegerPrivate *privat = GPDATA_TM_COLUMN_INTEGER_GET_PRIVATE(column);
    gint value = G_MAXINT;

    if (privat != NULL)
    {
        value = privat->imax;
    }

    return value;
}

gint
gpdata_tm_column_integer_get_min(GPDataTMColumnInteger *column)
{
    GPDataTMColumnIntegerPrivate *privat = GPDATA_TM_COLUMN_INTEGER_GET_PRIVATE(column);
    gint value = G_MININT;

    if (privat != NULL)
    {
        value = privat->imin;
    }

    return value;
}

gchar*
gpdata_tm_column_integer_get_name(const GPDataTMColumnInteger *column)
{
    GPDataTMColumnIntegerPrivate *privat = GPDATA_TM_COLUMN_INTEGER_GET_PRIVATE(column);
    gchar *name = NULL;

    if (privat != NULL)
    {
        name = g_strdup(privat->name);
    }

    return name;
}

static void
gpdata_tm_column_integer_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPDataTMColumnInteger *column = GPDATA_TM_COLUMN_INTEGER(object);

    if (column != NULL)
    {
        switch (property_id)
        {
            case GPDATA_TM_COLUMN_INTEGER_MAX:
                g_value_set_int(value, gpdata_tm_column_integer_get_max(column));
                break;

            case GPDATA_TM_COLUMN_INTEGER_MIN:
                g_value_set_int(value, gpdata_tm_column_integer_get_min(column));
                break;

            case GPDATA_TM_COLUMN_INTEGER_NAME:
                g_value_take_string(value, gpdata_tm_column_integer_get_name(column));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
gpdata_tm_column_integer_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPDataTMColumnIntegerClass),     /* class_size */
            NULL,                                   /* base_init */
            NULL,                                   /* base_finalize */
            gpdata_tm_column_integer_class_init,    /* class_init */
            NULL,                                   /* class_finalize */
            NULL,                                   /* class_data */
            sizeof(GPDataTMColumnInteger),          /* instance_size */
            0,                                      /* n_preallocs */
            gpdata_tm_column_integer_init,          /* instance_init */
            NULL                                    /* value_table */
            };

        type = g_type_register_static(
            GPDATA_TYPE_TM_COLUMN,
            "GPDataTMColumnInteger",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gpdata_tm_column_integer_init(GTypeInstance *instance, gpointer g_class)
{
    GPDataTMColumnIntegerPrivate *privat = GPDATA_TM_COLUMN_INTEGER_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->name = g_strdup("None");
    }
}

void
gpdata_tm_column_integer_set_max(GPDataTMColumnInteger *column, gint value)
{
    GPDataTMColumnIntegerPrivate *privat = GPDATA_TM_COLUMN_INTEGER_GET_PRIVATE(column);

    if (privat != NULL)
    {
        privat->imax = value;

        g_object_notify(G_OBJECT(column), "max");
    }
}

void
gpdata_tm_column_integer_set_min(GPDataTMColumnInteger *column, gint value)
{
    GPDataTMColumnIntegerPrivate *privat = GPDATA_TM_COLUMN_INTEGER_GET_PRIVATE(column);

    if (privat != NULL)
    {
        privat->imin = value;

        g_object_notify(G_OBJECT(column), "min");
    }
}

void
gpdata_tm_column_integer_set_name(GPDataTMColumnInteger *column, const gchar *name)
{
    GPDataTMColumnIntegerPrivate *privat = GPDATA_TM_COLUMN_INTEGER_GET_PRIVATE(column);

    if (privat != NULL)
    {
        g_free(privat->name);

        privat->name = g_strdup(name);

        g_object_notify(G_OBJECT(column), "name");
    }
}

static void
gpdata_tm_column_integer_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPDataTMColumnInteger *column = GPDATA_TM_COLUMN_INTEGER(object);

    if (column != NULL)
    {
        switch (property_id)
        {
            case GPDATA_TM_COLUMN_INTEGER_MAX:
                gpdata_tm_column_integer_set_max(column, g_value_get_int(value));
                break;

            case GPDATA_TM_COLUMN_INTEGER_MIN:
                gpdata_tm_column_integer_set_min(column, g_value_get_int(value));
                break;

            case GPDATA_TM_COLUMN_INTEGER_NAME:
                gpdata_tm_column_integer_set_name(column, g_value_get_string(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

