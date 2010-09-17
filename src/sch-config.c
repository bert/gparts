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

#include "misc-object.h"

#include "sch.h"

#define SCH_CONFIG_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_CONFIG,SchConfigPrivate))

enum
{
    SCH_CONFIG_ATTRIBUTE_PROMOTION = 1,
    SCH_CONFIG_BUBBLE_COLOR,
    SCH_CONFIG_BUBBLE_DIAMETER,
    SCH_CONFIG_BUS_COLOR,
    SCH_CONFIG_FILL_STYLE,
    SCH_CONFIG_GRAPHIC_COLOR,
    SCH_CONFIG_KEEP_INVISIBLE,
    SCH_CONFIG_LINE_STYLE,
    SCH_CONFIG_LINE_WIDTH,
    SCH_CONFIG_NET_COLOR,
    SCH_CONFIG_PIN_COLOR,
    SCH_CONFIG_PIN_LENGTH,
    SCH_CONFIG_PIN_SPACING,
    SCH_CONFIG_PROMOTE_ATTRIBUTES,
    SCH_CONFIG_PROMOTE_INVISIBLE,
    SCH_CONFIG_TEXT_COLOR,
    SCH_CONFIG_TEXT_SIZE
};

typedef struct _SchConfigPrivate SchConfigPrivate;

struct _SchConfigPrivate
{
    SchFillStyle fill_style;
    SchLineStyle line_style;

    gint bubble_color;
    gint bubble_diameter;
    gint bus_color;
    gint graphic_color;
    gint line_width;
    gint net_color;
    gint pin_color;
    gint pin_length;
    gint pin_spacing;
    gint text_color;
    gint text_size;

    gchar **promote_attributes;

    gboolean attribute_promotion;
    gboolean keep_invisible;
    gboolean promote_invisible;
};



static void
sch_config_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_config_dispose(GObject *object);

static void
sch_config_finalize(GObject *object);

static void
sch_config_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_config_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
sch_config_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(SchConfigPrivate));

    klasse->dispose  = sch_config_dispose;
    klasse->finalize = sch_config_finalize;

    klasse->get_property = sch_config_get_property;
    klasse->set_property = sch_config_set_property;

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_ATTRIBUTE_PROMOTION,
        g_param_spec_boolean(
            "attribute-promotion",
            "Attribute Promotion",
            "Attribute Promotion",
            SCH_CONFIG_DEFAULT_ATTRIBUTE_PROMOTION,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_BUBBLE_COLOR,
        g_param_spec_int(
            "bubble-color",
            "Bubble Color",
            "Bubble Color",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_BUBBLE_COLOR,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_BUBBLE_DIAMETER,
        g_param_spec_int(
            "bubble-diameter",
            "Bubble Diameter",
            "Bubble Diameter",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_BUBBLE_DIAMETER,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

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
        SCH_CONFIG_FILL_STYLE,
        g_param_spec_boxed(
            "fill-style",
            "Fill Style",
            "Fill Style",
            SCH_TYPE_FILL_STYLE,
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
        SCH_CONFIG_KEEP_INVISIBLE,
        g_param_spec_boolean(
            "keep-invisible",
            "Keep Invisible",
            "Keep Invisible",
            SCH_CONFIG_DEFAULT_KEEP_INVISIBLE,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_LINE_STYLE,
        g_param_spec_boxed(
            "line-style",
            "Line Style",
            "Line Style",
            SCH_TYPE_LINE_STYLE,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_LINE_WIDTH,
        g_param_spec_int(
            "line-width",
            "Line Width",
            "Line Width",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_LINE_WIDTH,
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
        SCH_CONFIG_PIN_LENGTH,
        g_param_spec_int(
            "pin-length",
            "Pin Length",
            "Pin Length",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_PIN_LENGTH,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_PIN_COLOR,
        g_param_spec_int(
            "pin-spacing",
            "Pin Spacing",
            "Pin Spacing",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_PIN_SPACING,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_PROMOTE_ATTRIBUTES,
        g_param_spec_boxed(
            "always-promote-attributes",
            "always-promote-attributes",
            "always-promote-attributes",
            G_TYPE_STRV,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_PROMOTE_INVISIBLE,
        g_param_spec_boolean(
            "promote-invisible",
            "Promote Invisible",
            "Promote Invisible",
            SCH_CONFIG_DEFAULT_PROMOTE_INVISIBLE,
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

    g_object_class_install_property(
        klasse,
        SCH_CONFIG_TEXT_SIZE,
        g_param_spec_int(
            "text-size",
            "Text Size",
            "Text Size",
            0,
            G_MAXINT,
            SCH_CONFIG_DEFAULT_TEXT_SIZE,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}



static void
sch_config_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}



static void
sch_config_finalize(GObject *object)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_strfreev(privat->promote_attributes);
        privat->promote_attributes = NULL;
    }

    misc_object_chain_finalize(object);
}

gboolean
sch_config_get_attribute_promotion(const SchConfig *config)
{
    gboolean enabled = SCH_CONFIG_DEFAULT_ATTRIBUTE_PROMOTION;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            enabled = privat->attribute_promotion;
        }
    }

    return enabled;
}

gint
sch_config_get_bubble_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_BUBBLE_COLOR;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            color = privat->bubble_color;
        }
    }

    return color;
}

gint
sch_config_get_bubble_diameter(const SchConfig *config)
{
    gint diameter = SCH_CONFIG_DEFAULT_BUBBLE_DIAMETER;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            diameter = privat->bubble_diameter;
        }
    }

    return diameter;
}

gint
sch_config_get_bus_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_BUS_COLOR;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            color = privat->bus_color;
        }
    }

    return color;
}

void
sch_config_get_fill_style(const SchConfig *config, SchFillStyle *style)
{
    if (style != NULL)
    {
        if (config != NULL) 
        {
            SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

            if (privat != NULL)
            {
                *style = privat->fill_style;
            }
            else
            {
                sch_fill_style_init(style);
            }
        }
        else
        {
            sch_fill_style_init(style);
        }
    }
}

gint
sch_config_get_graphic_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_GRAPHIC_COLOR;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            color = privat->graphic_color;
        }
    }

    return color;
}

gboolean
sch_config_get_keep_invisible(const SchConfig *config)
{
    gboolean enabled = SCH_CONFIG_DEFAULT_KEEP_INVISIBLE;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            enabled = privat->keep_invisible;
        }
    }

    return enabled;
}

void
sch_config_get_line_style(const SchConfig *config, SchLineStyle *style)
{
    if (style != NULL)
    {
        if (config != NULL) 
        {
            SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

            if (privat != NULL)
            {
                *style = privat->line_style;
            }
            else
            {
                sch_line_style_init(style);
            }
        }
        else
        {
            sch_line_style_init(style);
        }
    }
}

gint
sch_config_get_line_width(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_LINE_WIDTH;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            color = privat->line_width;
        }
    }

    return color;
}

gint
sch_config_get_net_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_NET_COLOR;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            color = privat->net_color;
        }
    }

    return color;
}

gint
sch_config_get_pin_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_PIN_COLOR;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            color = privat->pin_color;
        }
    }

    return color;
}

gint
sch_config_get_pin_length(const SchConfig *config)
{
    gint length = SCH_CONFIG_DEFAULT_PIN_LENGTH;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            length = privat->pin_length;
        }
    }

    return length;
}

gint
sch_config_get_pin_spacing(const SchConfig *config)
{
    gint spacing = SCH_CONFIG_DEFAULT_PIN_SPACING;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            spacing = privat->pin_spacing;
        }
    }

    return spacing;
}

gchar**
sch_config_get_promote_attributes(const SchConfig *config)
{
    char **names = NULL;
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        names = g_strdupv(privat->promote_attributes);
    }

    return names;
}

gboolean
sch_config_get_promote_invisible(const SchConfig *config)
{
    gboolean enabled = SCH_CONFIG_DEFAULT_PROMOTE_INVISIBLE;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            enabled = privat->promote_invisible;
        }
    }

    return enabled;
}


gint
sch_config_get_text_color(const SchConfig *config)
{
    gint color = SCH_CONFIG_DEFAULT_TEXT_COLOR;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            color = privat->text_color;
        }
    }

    return color;
}

gint
sch_config_get_text_size(const SchConfig *config)
{
    gint size = SCH_CONFIG_DEFAULT_TEXT_SIZE;

    if (config != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            size = privat->text_size;
        }
    }

    return size;
}


static void
sch_config_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCH_CONFIG_ATTRIBUTE_PROMOTION:
                g_value_set_boolean(value, privat->attribute_promotion);
                break;

            case SCH_CONFIG_BUBBLE_COLOR:
                g_value_set_int(value, privat->bubble_color);
                break;

            case SCH_CONFIG_BUBBLE_DIAMETER:
                g_value_set_int(value, privat->bubble_diameter);
                break;

            case SCH_CONFIG_BUS_COLOR:
                g_value_set_int(value, privat->bus_color);
                break;

            case SCH_CONFIG_FILL_STYLE:
                g_value_set_boxed(value, &(privat->fill_style));
                break;

            case SCH_CONFIG_GRAPHIC_COLOR:
                g_value_set_int(value, privat->graphic_color);
                break;

            case SCH_CONFIG_KEEP_INVISIBLE:
                g_value_set_boolean(value, privat->keep_invisible);
                break;

            case SCH_CONFIG_LINE_STYLE:
                g_value_set_boxed(value, &(privat->line_style));
                break;

            case SCH_CONFIG_LINE_WIDTH:
                g_value_set_int(value, privat->line_width);
                break;

            case SCH_CONFIG_NET_COLOR:
                g_value_set_int(value, privat->net_color);
                break;

            case SCH_CONFIG_PIN_COLOR:
                g_value_set_int(value, privat->pin_color);
                break;

            case SCH_CONFIG_PIN_LENGTH:
                g_value_set_int(value, privat->pin_length);
                break;

            case SCH_CONFIG_PIN_SPACING:
                g_value_set_int(value, privat->pin_spacing);
                break;

            case SCH_CONFIG_PROMOTE_INVISIBLE:
                g_value_set_boolean(value, privat->promote_invisible);
                break;

            case SCH_CONFIG_TEXT_COLOR:
                g_value_set_int(value, privat->text_color);
                break;

            case SCH_CONFIG_TEXT_SIZE:
                g_value_set_int(value, privat->text_size);
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
    SchConfig *config = SCH_CONFIG(object);

    switch (property_id)
    {
        case SCH_CONFIG_ATTRIBUTE_PROMOTION:
            sch_config_set_attribute_promotion(config, g_value_get_boolean(value));
            break;

        case SCH_CONFIG_BUBBLE_COLOR:
            sch_config_set_bubble_color(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_BUBBLE_DIAMETER:
            sch_config_set_bubble_diameter(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_BUS_COLOR:
            sch_config_set_bus_color(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_FILL_STYLE:
            sch_config_set_fill_style(config, SCH_FILL_STYLE(g_value_get_boxed(value)));
            break;

        case SCH_CONFIG_GRAPHIC_COLOR:
            sch_config_set_graphic_color(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_KEEP_INVISIBLE:
            sch_config_set_keep_invisible(config, g_value_get_boolean(value));
            break;

        case SCH_CONFIG_LINE_STYLE:
            sch_config_set_line_style(config, SCH_LINE_STYLE(g_value_get_boxed(value)));
            break;

        case SCH_CONFIG_LINE_WIDTH:
            sch_config_set_line_width(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_NET_COLOR:
            sch_config_set_net_color(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_PIN_COLOR:
            sch_config_set_pin_color(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_PIN_LENGTH:
            sch_config_set_pin_length(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_PIN_SPACING:
            sch_config_set_pin_spacing(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_PROMOTE_INVISIBLE:
            sch_config_set_promote_invisible(config, g_value_get_boolean(value));
            break;

        case SCH_CONFIG_TEXT_COLOR:
            sch_config_set_text_color(config, g_value_get_int(value));
            break;

        case SCH_CONFIG_TEXT_SIZE:
            sch_config_set_text_size(config, g_value_get_int(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
sch_config_set_attribute_promotion(SchConfig *config, gboolean enabled)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->attribute_promotion = enabled;

        g_object_notify(G_OBJECT(config), "attribute-promotion");
    }
}

void
sch_config_set_bubble_color(SchConfig *config, gint index)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->bubble_color = index;

        g_object_notify(G_OBJECT(config), "bubble-color");
    }
}

void
sch_config_set_bubble_diameter(SchConfig *config, gint diameter)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->bubble_diameter = diameter;

        g_object_notify(G_OBJECT(config), "bubble-diameter");
    }
}

void
sch_config_set_bus_color(SchConfig *config, gint index)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->bus_color = index;

        g_object_notify(G_OBJECT(config), "bus-color");
    }
}

void
sch_config_set_fill_style(SchConfig *config, const SchFillStyle *style)
{
    if (style != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            privat->fill_style = *style;

            g_object_notify(G_OBJECT(config), "fill-style");
        }
    }
}

void
sch_config_set_graphic_color(SchConfig *config, gint index)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->graphic_color = index;

        g_object_notify(G_OBJECT(config), "graphic-color");
    }
}

void
sch_config_set_keep_invisible(SchConfig *config, gboolean enabled)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->keep_invisible = enabled;

        g_object_notify(G_OBJECT(config), "keep-invisible");
    }
}

void
sch_config_set_line_style(SchConfig *config, const SchLineStyle *style)
{
    if (style != NULL)
    {
        SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

        if (privat != NULL)
        {
            privat->line_style = *style;

            g_object_notify(G_OBJECT(config), "line-style");
        }
    }
}

void
sch_config_set_line_width(SchConfig *config, gint width)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->line_width = width;

        g_object_notify(G_OBJECT(config), "line-width");
    }
}

void
sch_config_set_net_color(SchConfig *config, gint index)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->net_color = index;

        g_object_notify(G_OBJECT(config), "net-color");
    }
}

void
sch_config_set_pin_color(SchConfig *config, gint index)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->pin_color = index;

        g_object_notify(G_OBJECT(config), "pin-color");
    }
}

void
sch_config_set_pin_length(SchConfig *config, gint length)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->pin_length = length;

        g_object_notify(G_OBJECT(config), "pin-length");
    }
}

void
sch_config_set_pin_spacing(SchConfig *config, gint spacing)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->pin_spacing = spacing;

        g_object_notify(G_OBJECT(config), "pin-spacing");
    }
}

void
sch_config_set_promote_attributes(SchConfig *config, char **name)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        g_strfreev(privat->promote_attributes);

        privat->promote_attributes = g_strdupv(name);
    }
}

void
sch_config_set_promote_invisible(SchConfig *config, gboolean enabled)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->promote_invisible = enabled;

        g_object_notify(G_OBJECT(config), "promote-invisible");
    }
}

void
sch_config_set_text_color(SchConfig *config, gint index)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->text_color = index;

        g_object_notify(G_OBJECT(config), "text-color");
    }
}

void
sch_config_set_text_size(SchConfig *config, gint size)
{
    SchConfigPrivate *privat = SCH_CONFIG_GET_PRIVATE(config);

    if (privat != NULL)
    {
        privat->text_size = size;

        g_object_notify(G_OBJECT(config), "text-size");
    }
}

