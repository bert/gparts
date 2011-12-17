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

/*! \file gpdata-tm-column-text.c
 */

#include <glib-object.h>

#include "misc-object.h"

#include "gpdata.h"

#define GPDATA_TM_COLUMN_TEXT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPDATA_TYPE_TM_COLUMN_TEXT,GPDataTMColumnTextPrivate))

enum
{
    GPDATA_TM_COLUMN_TEXT_DIGITS = 1,
    GPDATA_TM_COLUMN_TEXT_NAME,
    GPDATA_TM_COLUMN_TEXT_UNITS
};

typedef struct _GPDataTMColumnTextPrivate GPDataTMColumnTextPrivate;

struct _GPDataTMColumnTextPrivate
{
    gint   digits;
    gchar  *name;
    gchar  *units;
};



static void
gpdata_tm_column_text_class_init(gpointer g_class, gpointer g_class_data);

static void
gpdata_tm_column_text_dispose(GObject *object);

static void
gpdata_tm_column_text_finalize(GObject *object);

static void
gpdata_tm_column_text_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpdata_tm_column_text_init(GTypeInstance *instance, gpointer g_class);

static void
gpdata_tm_column_text_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
gpdata_tm_column_text_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(GPDataTMColumnTextPrivate));

    klasse->dispose  = gpdata_tm_column_text_dispose;
    klasse->finalize = gpdata_tm_column_text_finalize;

    klasse->get_property = gpdata_tm_column_text_get_property;
    klasse->set_property = gpdata_tm_column_text_set_property;

    g_object_class_install_property(
        klasse,
        GPDATA_TM_COLUMN_TEXT_DIGITS,
        g_param_spec_int(
            "digits",
            "Digits",
            "Digits",
            1,
            G_MAXINT,
            3,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPDATA_TM_COLUMN_TEXT_NAME,
        g_param_spec_string(
            "name",
            "Name",
            "Name",
            NULL,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPDATA_TM_COLUMN_TEXT_UNITS,
        g_param_spec_string(
            "units",
            "Units",
            "Units",
            NULL,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpdata_tm_column_text_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}

static void
gpdata_tm_column_text_finalize(GObject *object)
{
    GPDataTMColumnTextPrivate *privat = GPDATA_TM_COLUMN_TEXT_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_free(privat->name);
        privat->name = NULL;

        g_free(privat->units);
        privat->units = NULL;
    }

    misc_object_chain_finalize(object);
}

gint
gpdata_tm_column_text_get_digits(const GPDataTMColumnText *column)
{
    gint digits = 3;
    GPDataTMColumnTextPrivate *privat = GPDATA_TM_COLUMN_TEXT_GET_PRIVATE(column);

    if (privat != NULL)
    {
        digits = privat->digits;
    }

    return digits;
}

gchar*
gpdata_tm_column_text_get_name(const GPDataTMColumnText *column)
{
    GPDataTMColumnTextPrivate *privat = GPDATA_TM_COLUMN_TEXT_GET_PRIVATE(column);
    gchar *name = NULL;

    if (privat != NULL)
    {
        name = g_strdup(privat->name);
    }

    return name;
}

static void
gpdata_tm_column_text_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPDataTMColumnText *column = GPDATA_TM_COLUMN_TEXT(object);

    if (column != NULL)
    {
        switch (property_id)
        {
            case GPDATA_TM_COLUMN_TEXT_DIGITS:
                g_value_set_int(value, gpdata_tm_column_text_get_digits(column));
                break;

            case GPDATA_TM_COLUMN_TEXT_NAME:
                g_value_take_string(value, gpdata_tm_column_text_get_name(column));
                break;

            case GPDATA_TM_COLUMN_TEXT_UNITS:
                g_value_set_string(value, gpdata_tm_column_text_get_units(column));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

gchar*
gpdata_tm_column_text_get_units(const GPDataTMColumnText *column)
{
    GPDataTMColumnTextPrivate *privat = GPDATA_TM_COLUMN_TEXT_GET_PRIVATE(column);
    gchar *units = NULL;

    if (privat != NULL)
    {
        units = g_strdup(privat->units);
    }

    return units;
}

GType
gpdata_tm_column_text_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPDataTMColumnTextClass),     /* class_size */
            NULL,                                 /* base_init */
            NULL,                                 /* base_finalize */
            gpdata_tm_column_text_class_init,    /* class_init */
            NULL,                                 /* class_finalize */
            NULL,                                 /* class_data */
            sizeof(GPDataTMColumnText),          /* instance_size */
            0,                                    /* n_preallocs */
            gpdata_tm_column_text_init,          /* instance_init */
            NULL                                  /* value_table */
            };

        type = g_type_register_static(
            GPDATA_TYPE_TM_COLUMN,
            "GPDataTMColumnText",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gpdata_tm_column_text_init(GTypeInstance *instance, gpointer g_class)
{
    GPDataTMColumnTextPrivate *privat = GPDATA_TM_COLUMN_TEXT_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->digits = 3;
        privat->name   = g_strdup("None");
        privat->units  = NULL;
    }
}

void
gpdata_tm_column_text_set_digits(GPDataTMColumnText *column, gint digits)
{
    GPDataTMColumnTextPrivate *privat = GPDATA_TM_COLUMN_TEXT_GET_PRIVATE(column);

    if (privat != NULL)
    {
        privat->digits = digits;

        g_object_notify(G_OBJECT(column), "digits");
    }
}

void
gpdata_tm_column_text_set_name(GPDataTMColumnText *column, const gchar *name)
{
    GPDataTMColumnTextPrivate *privat = GPDATA_TM_COLUMN_TEXT_GET_PRIVATE(column);

    if (privat != NULL)
    {
        g_free(privat->name);

        privat->name = g_strdup(name);

        g_object_notify(G_OBJECT(column), "name");
    }
}

static void
gpdata_tm_column_text_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPDataTMColumnText *column = GPDATA_TM_COLUMN_TEXT(object);

    if (column != NULL)
    {
        switch (property_id)
        {
            case GPDATA_TM_COLUMN_TEXT_DIGITS:
                gpdata_tm_column_text_set_digits(column, g_value_get_int(value));
                break;

            case GPDATA_TM_COLUMN_TEXT_NAME:
                gpdata_tm_column_text_set_name(column, g_value_get_string(value));
                break;

            case GPDATA_TM_COLUMN_TEXT_UNITS:
                gpdata_tm_column_text_set_units(column, g_value_get_string(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

void
gpdata_tm_column_text_set_units(GPDataTMColumnText *column, const gchar *units)
{
    GPDataTMColumnTextPrivate *privat = GPDATA_TM_COLUMN_TEXT_GET_PRIVATE(column);

    if (privat != NULL)
    {
        g_free(privat->units);

        privat->units = g_strdup(units);

        g_object_notify(G_OBJECT(column), "units");
    }
}

