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

/*! \file schgui-drawing-cfg.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gdk/gdk.h>

#include "misc-object.h"

#include "sch-color.h"

#include "schgui-drawing-cfg.h"

#define SCHGUI_DRAWING_CFG_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_DRAWING_CFG,SchGUIDrawingCfgPrivate))

enum
{
    SCHGUI_DRAWING_CFG_BACKGROUND = 1
};

typedef struct _SchGUIDrawingCfgPrivate SchGUIDrawingCfgPrivate;

struct _SchGUIDrawingCfgPrivate
{
    GHashTable *colors;
};

static void
schgui_drawing_cfg_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_drawing_cfg_dispose(GObject *object);

static void
schgui_drawing_cfg_finalize(GObject *object);

static void
schgui_drawing_cfg_get_background(GObject *object, GValue *value);

static void
schgui_drawing_cfg_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
schgui_drawing_cfg_init(GTypeInstance *instance, gpointer g_class);

static void
schgui_drawing_cfg_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);




static void
schgui_drawing_cfg_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(SchGUIDrawingCfgPrivate));

    object_class->dispose  = schgui_drawing_cfg_dispose;
    object_class->finalize = schgui_drawing_cfg_finalize;

    object_class->get_property = schgui_drawing_cfg_get_property;
    object_class->set_property = schgui_drawing_cfg_set_property;

    g_object_class_install_property(
        object_class,
        SCHGUI_DRAWING_CFG_BACKGROUND,
        g_param_spec_boxed(
            "background",
            "Background",
            "Background",
            GDK_TYPE_COLOR,
            G_PARAM_LAX_VALIDATION | G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
schgui_drawing_cfg_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}

static void
schgui_drawing_cfg_finalize(GObject *object)
{
    SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(object);

    if (privat != NULL)
    {
        if (privat->colors != NULL)
        {
            g_hash_table_destroy(privat->colors);
        }
    }

    misc_object_chain_finalize(object);
}

static void
schgui_drawing_cfg_get_background(GObject *object, GValue *value)
{
    if (value != NULL)
    {
        GdkColor color;
        int      enabled = FALSE;

        if (object != NULL)
        {
            enabled = schgui_drawing_cfg_get_color_as_gdk_color(object, 0, &color);
        }

        if (!enabled)
        {
            color.red   = 0;
            color.green = 0;
            color.blue  = 0;
        }

        g_value_set_boxed(value, &color);
    }
}

void
schgui_drawing_cfg_get_background_as_gdk_color(GObject *object, GdkColor *color)
{
    int enabled = FALSE;

    if (object != NULL)
    {
        enabled = schgui_drawing_cfg_get_color_as_gdk_color(object, 0, color);
    }

    if (!enabled)
    {
        color->red   = 0;
        color->green = 0;
        color->blue  = 0;
    }
}
static void
schgui_drawing_cfg_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCHGUI_DRAWING_CFG_BACKGROUND:
                schgui_drawing_cfg_get_background(object, value);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
schgui_drawing_cfg_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUIDrawingCfgClass),    /* class_size */
            NULL,                             /* base_init */
            NULL,                             /* base_finalize */
            schgui_drawing_cfg_class_init,    /* class_init */
            NULL,                             /* class_finalize */
            NULL,                             /* class_data */
            sizeof(SchGUIDrawingCfg),         /* instance_size */
            0,                                /* n_preallocs */
            schgui_drawing_cfg_init,          /* instance_init */
            NULL                              /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchGUIDrawingCfg",
            &tinfo,
            0
            );
    }

    return type;
}

static void
schgui_drawing_cfg_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCHGUI_DRAWING_CFG_BACKGROUND:
                schgui_drawing_cfg_set_color_by_gdk_color(SCHGUI_DRAWING_CFG(object), 0, g_value_get_boxed(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

void
schgui_drawing_cfg_get_bus_line_width(SchGUIDrawingCfg *cfg, double *width)
{
    *width = 20;
}

void
schgui_drawing_cfg_get_net_line_width(SchGUIDrawingCfg *cfg, double *width)
{
    *width = 10;
}

void
schgui_drawing_cfg_get_pin_line_width(SchGUIDrawingCfg *cfg, double *width)
{
    *width = 10;
}

void
schgui_drawing_cfg_get_display_color(SchGUIDrawingCfg *cfg, int index, double *red, double *green, double *blue)
{
    sch_color_get_default(index, red, green, blue);
}

void
schgui_drawing_cfg_get_print_color(SchGUIDrawingCfg *cfg, int index, double *red, double *green, double *blue)
{
    sch_color_get_default(index, red, green, blue);
}

void
schgui_drawing_cfg_get_output_line_width(SchGUIDrawingCfg *cfg, int shape_width, double *output_width)
{
    *output_width = shape_width;

    if (*output_width < 10)
    {
         *output_width = 10;
    }
}

void
schgui_drawing_cfg_disable_color(SchGUIDrawingCfg *config, int index)
{
    SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(config);

    if ((privat != NULL) && (privat->colors != NULL))
    {
        g_hash_table_remove(privat->colors, GINT_TO_POINTER(index));

        if (index == 0)
        {
            g_object_notify(G_OBJECT(config), "background");
        }
    }
}

int
schgui_drawing_cfg_get_color(SchGUIDrawingCfg *config, int index, SchGUIDrawingCfgColor *color)
{
    int enabled = FALSE;

    if (index >= 0)
    {
        SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(config);

        if ((privat != NULL) && (privat->colors != NULL))
        {
            SchGUIDrawingCfgColor *value = g_hash_table_lookup(privat->colors, GINT_TO_POINTER(index));

            if (value != NULL)
            {
                *color = *value;
                enabled = TRUE;
            }
        }
    }

    return enabled;
}

int
schgui_drawing_cfg_get_color_as_gdk_color(SchGUIDrawingCfg *config, int index, GdkColor *color)
{
    int enabled = FALSE;

    if (index >= 0)
    {
        SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(config);

        if ((privat != NULL) && (privat->colors != NULL))
        {
            SchGUIDrawingCfgColor *value = g_hash_table_lookup(privat->colors, GINT_TO_POINTER(index));

            if (value != NULL)
            {
                if (color != NULL)
                {
                    color->red   = (guint16) (65535.0 * value->red);
                    color->green = (guint16) (65535.0 * value->green);
                    color->blue  = (guint16) (65535.0 * value->blue);
                }

                enabled = TRUE;
            }
        }
    }

    return enabled;
}

SchGUIDrawingCfg*
schgui_drawing_cfg_get_default_display(void)
{
    static SchGUIDrawingCfg *config = NULL;

    if (config == NULL)
    {
        config = (SchGUIDrawingCfg*) g_object_new(SCHGUI_TYPE_DRAWING_CFG, NULL);
    }

    return config;
}

SchGUIDrawingCfg*
schgui_drawing_cfg_get_default_print(void)
{
    static SchGUIDrawingCfg *config = NULL;

    if (config == NULL)
    {
        config = (SchGUIDrawingCfg*) g_object_new(SCHGUI_TYPE_DRAWING_CFG, NULL);
    }

    return config;
}


static void
schgui_drawing_cfg_init(GTypeInstance *instance, gpointer g_class)
{
    SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->colors = g_hash_table_new_full(
            g_direct_hash,     /* hash_func          */
            g_direct_equal,    /* key_equal_func     */
            NULL,              /* key_destroy_func   */
            g_free             /* value_destroy_func */
            );
    }
}

void
schgui_drawing_cfg_set_color_by_gdk_color(SchGUIDrawingCfg *config, int index, const GdkColor *color)
{
    if ((index >= 0) && (color != NULL))
    {
        SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(config);

        if ((privat != NULL) && (privat->colors != NULL))
        {
            SchGUIDrawingCfgColor *value = g_new(SchGUIDrawingCfgColor, 1);

            value->red   = (double) color->red   / 65535.0;
            value->green = (double) color->green / 65535.0;
            value->blue  = (double) color->blue  / 65535.0;

            g_hash_table_replace(privat->colors, GINT_TO_POINTER(index), value);

            if (index == 0)
            {
                g_object_notify(G_OBJECT(config), "background");
            }
        }
    }
}

void
schgui_drawing_cfg_set_color_by_name(SchGUIDrawingCfg *config, int index, const char *color)
{
    if ((index >= 0) && (color != NULL))
    {
        SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(config);

        if ((privat != NULL) && (privat->colors != NULL))
        {
            int      success;
            GdkColor value;

            success = gdk_color_parse(color, &value);

            if (success)
            {
                schgui_drawing_cfg_set_color_by_gdk_color(config, index, &value);
            }
        }
    }
}

