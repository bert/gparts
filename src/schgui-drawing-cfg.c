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

#include "sch-color.h"

#include "schgui-drawing-cfg.h"

#define SCHGUI_DRAWING_CFG_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_DRAWING_CFG,SchGUIDrawingCfgPrivate))

//enum
//{
//};

typedef struct _SchGUIDrawingCfgPrivate SchGUIDrawingCfgPrivate;

struct _SchGUIDrawingCfgPrivate
{
};

static void
schgui_drawing_cfg_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_drawing_cfg_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
schgui_drawing_cfg_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);




static void
schgui_drawing_cfg_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(SchGUIDrawingCfgPrivate));

    object_class->get_property = schgui_drawing_cfg_get_property;
    object_class->set_property = schgui_drawing_cfg_set_property;
}

static void
schgui_drawing_cfg_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchGUIDrawingCfgPrivate *privat = SCHGUI_DRAWING_CFG_GET_PRIVATE(object);

    switch (property_id)
    {
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
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
            NULL,                             /* instance_init */
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

    switch (property_id)
    {
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
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

