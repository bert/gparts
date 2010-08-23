/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2010 Edward C. Hennessy
 * Copyright (C) 2010 gEDA Contributors (see ChangeLog for details)
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

/*! \file sch-config.c
 */

#include <glib.h>
#include <glib-object.h>

#include "sch.h"

#define SCH_CONFIG_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_CONFIG,SchConfigPrivate))

enum
{
    SCH_CONFIG_BUS_COLOR = 1,
    SCH_CONFIG_GRAPHIC_COLOR,
    SCH_CONFIG_NET_COLOR,
    SCH_CONFIG_PIN_COLOR,
    SCH_CONFIG_TEXT_COLOR
};

typedef struct _SchConfigPrivate SchConfigPrivate;

struct _SchConfigPrivate
{
    gint bus_color;
    gint graphic_color;
    gint net_color;
    gint pin_color;
    gint text_color;
};



static void
sch_config_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_config_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_config_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
sch_config_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(SchConfigPrivate));

    klasse->get_property = sch_config_get_property;
    klasse->set_property = sch_config_set_property;

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_BUS_COLOR,
        g_param_spec_int(
            "bus-color",
            "Bus Color",
            "Bus Color",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_BUS_COLOR,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_GRAPHIC_COLOR,
        g_param_spec_int(
            "graphic-color",
            "Graphic Color",
            "Graphic Color",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_GRAPHIC_COLOR,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_NET_COLOR,
        g_param_spec_int(
            "net-color",
            "Net Color",
            "Net Color",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_NET_COLOR,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_PIN_COLOR,
        g_param_spec_int(
            "pin-color",
            "Pin Color",
            "Pin Color",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_PIN_COLOR,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_TEXT_COLOR,
        g_param_spec_int(
            "text-color",
            "Text Color",
            "Text Color",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_TEXT_COLOR,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}



gint
sch_config_get_bus_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_BUS_COLOR;
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        color = privat->bus_color;
    }

    return color;
}



gint
sch_config_get_graphic_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_GRAPHIC_COLOR;
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        color = privat->graphic_color;
    }

    return color;
}



gint
sch_config_get_net_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_NET_COLOR;
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        color = privat->net_color;
    }

    return color;
}



gint
sch_config_get_pin_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_PIN_COLOR;
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        color = privat->pin_color;
    }

    return color;
}



gint
sch_config_get_text_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_TEXT_COLOR;
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        color = privat->text_color;
    }

    return color;
}



static void
sch_config_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCH_CONFIG_BUS_COLOR:
                g_value_set_int(value, privat->bus_color);
                break;

            case SCH_CONFIG_GRAPHIC_COLOR:
                g_value_set_int(value, privat->graphic_color);
                break;

            case SCH_CONFIG_NET_COLOR:
                g_value_set_int(value, privat->net_color);
                break;

            case SCH_CONFIG_PIN_COLOR:
                g_value_set_int(value, privat->pin_color);
                break;

            case SCH_CONFIG_TEXT_COLOR:
                g_value_set_int(value, privat->text_color);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}



GType
sch_config_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchConfigClass),    /* class_size */
            NULL,                      /* base_init */
            NULL,                      /* base_finalize */
            sch_config_class_init,     /* class_init */
            NULL,                      /* class_finalize */
            NULL,                      /* class_data */
            sizeof(SchConfig),         /* instance_size */
            0,                         /* n_preallocs */
            NULL,                      /* instance_init */
            NULL                       /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchConfig",
            &tinfo,
            0
            );
    }

    return type;
}



SchConfig*
sch_config_new(void)
{
    static SchConfig *config = NULL;

    if (config == NULL)
    {
        config = SCH_CONFIG(g_object_new(SCH_TYPE_CONFIG, NULL));
    }

    return config;
}



static void
sch_config_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCH_CONFIG_BUS_COLOR:
                privat->bus_color = g_value_get_int(value);
                break;

            case SCH_CONFIG_GRAPHIC_COLOR:
                privat->graphic_color = g_value_get_int(value);
                break;

            case SCH_CONFIG_NET_COLOR:
                privat->net_color = g_value_get_int(value);
                break;

            case SCH_CONFIG_PIN_COLOR:
                privat->pin_color = g_value_get_int(value);
                break;

            case SCH_CONFIG_TEXT_COLOR:
                privat->text_color = g_value_get_int(value);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

