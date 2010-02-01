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

//enum
//{
//};

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
schgui_drawing_cfg_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
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
schgui_drawing_cfg_set_color_by_name(SchGUIDrawingCfg *config, int index, const char *color)
{
    if (index >= 0)
    {
        SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(config);

        if ((privat != NULL) && (privat->colors != NULL))
        {
            int      success;
            GdkColor value1;

            success = gdk_color_parse(color, &value1);

            if (success)
            {
                SchGUIDrawingCfgColor *value2 = g_new(SchGUIDrawingCfgColor, 1);

                value2->red   = (double) value1.red   / 65535.0;
                value2->green = (double) value1.green / 65535.0;
                value2->blue  = (double) value1.blue  / 65535.0;

                g_hash_table_replace(privat->colors, GINT_TO_POINTER(index), value2);
            }
        }
    }
}

