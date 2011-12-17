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

#define GPDATA_TM_COLUMN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPDATA_TYPE_TM_COLUMN,GPDataTMColumnPrivate))

enum
{
    GPDATA_TM_COLUMN_TITLE = 1,
    GPDATA_TM_COLUMN_XALIGN
};

typedef struct _GPDataTMColumnPrivate GPDataTMColumnPrivate;

struct _GPDataTMColumnPrivate
{
    gchar  *title;
    gfloat xalign;
};



static void
gpdata_tm_column_class_init(gpointer g_class, gpointer g_class_data);

static void
gpdata_tm_column_dispose(GObject *object);

static void
gpdata_tm_column_finalize(GObject *object);

static void
gpdata_tm_column_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpdata_tm_column_init(GTypeInstance *instance, gpointer g_class);

static void
gpdata_tm_column_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
gpdata_tm_column_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(GPDataTMColumnPrivate));

    klasse->dispose  = gpdata_tm_column_dispose;
    klasse->finalize = gpdata_tm_column_finalize;

    klasse->get_property = gpdata_tm_column_get_property;
    klasse->set_property = gpdata_tm_column_set_property;

    g_object_class_install_property(
        klasse,
        GPDATA_TM_COLUMN_TITLE,
        g_param_spec_string(
            "title",
            "Title",
            "Title",
            NULL,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPDATA_TM_COLUMN_XALIGN,
        g_param_spec_float(
            "xalign",
            "XAlign",
            "XAlign",
            0.0,
            1.0,
            0.0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpdata_tm_column_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}

static void
gpdata_tm_column_finalize(GObject *object)
{
    GPDataTMColumnPrivate *privat = GPDATA_TM_COLUMN_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_free(privat->title);
        privat->title = NULL;
    }

    misc_object_chain_finalize(object);
}

static void
gpdata_tm_column_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPDataTMColumn *column = GPDATA_TM_COLUMN(object);

    if (column != NULL)
    {
        switch (property_id)
        {
            case GPDATA_TM_COLUMN_TITLE:
                g_value_take_string(value, gpdata_tm_column_get_title(column));
                break;

            case GPDATA_TM_COLUMN_XALIGN:
                g_value_set_float(value, gpdata_tm_column_get_xalign(column));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

gchar*
gpdata_tm_column_get_title(const GPDataTMColumn *column)
{
    GPDataTMColumnPrivate *privat = GPDATA_TM_COLUMN_GET_PRIVATE(column);
    gchar *title = NULL;

    if (privat != NULL)
    {
        title = g_strdup(privat->title);
    }

    return title;
}

gfloat
gpdata_tm_column_get_xalign(const GPDataTMColumn *column)
{
    GPDataTMColumnPrivate *privat = GPDATA_TM_COLUMN_GET_PRIVATE(column);
    gfloat xalign = 0.0;

    if (privat != NULL)
    {
        xalign = privat->xalign;
    }

    return xalign;
}

GType
gpdata_tm_column_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPDataTMColumnClass),    /* class_size */
            NULL,                           /* base_init */
            NULL,                           /* base_finalize */
            gpdata_tm_column_class_init,    /* class_init */
            NULL,                           /* class_finalize */
            NULL,                           /* class_data */
            sizeof(GPDataTMColumn),         /* instance_size */
            0,                              /* n_preallocs */
            gpdata_tm_column_init,          /* instance_init */
            NULL                            /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            NULL,                              /* interface_init */
            NULL,                              /* interface_finalize */
            NULL                               /* interface_data */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPDataTMColumn",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GPDATA_TYPE_OP_BUILDABLE, &iinfo);
    }

    return type;
}

static void
gpdata_tm_column_init(GTypeInstance *instance, gpointer g_class)
{
    GPDataTMColumnPrivate *privat = GPDATA_TM_COLUMN_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->title  = g_strdup("None");
        privat->xalign = 0.0;
    }
}

static void
gpdata_tm_column_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPDataTMColumn *column = GPDATA_TM_COLUMN(object);

    if (column != NULL)
    {
        switch (property_id)
        {
            case GPDATA_TM_COLUMN_TITLE:
                gpdata_tm_column_set_title(column, g_value_get_string(value));
                break;

            case GPDATA_TM_COLUMN_XALIGN:
                gpdata_tm_column_set_xalign(column, g_value_get_float(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

void
gpdata_tm_column_set_title(GPDataTMColumn *column, const gchar *title)
{
    GPDataTMColumnPrivate *privat = GPDATA_TM_COLUMN_GET_PRIVATE(column);

    if (privat != NULL)
    {
        g_free(privat->title);

        privat->title = g_strdup(title);

        g_object_notify(G_OBJECT(column), "title");
    }
}

void
gpdata_tm_column_set_xalign(GPDataTMColumn *column, gfloat xalign)
{
    GPDataTMColumnPrivate *privat = GPDATA_TM_COLUMN_GET_PRIVATE(column);

    if (privat != NULL)
    {
        privat->xalign = xalign;

        g_object_notify(G_OBJECT(column), "xalign");
    }
}

