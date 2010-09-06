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

/*! \file schgui-cairo-arc.c
 */

#include <math.h>

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
 
#include "sch.h"

#include "schgui-drawing-cfg.h"

#include "schgui-cairo-draw-item.h"
#include "schgui-cairo-draw-list.h"

#include "schgui-cairo-arc.h"
#include "schgui-cairo-box.h"
#include "schgui-cairo-circle.h"
#include "schgui-cairo-line.h"
#include "schgui-cairo-net.h"
#include "schgui-cairo-pin.h"
#include "schgui-cairo-text.h"

#include "schgui-cairo-factory.h"

//#define SCHGUI_CAIRO_FACTORY_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_CAIRO_FACTORY,SchGUICairoFactoryPrivate))

//typedef struct _SchGUICairoFactoryPrivate SchGUICairoFactoryPrivate;

//struct _SchGUICairoFactoryPrivate
//{
//    double red;
//};


struct _temp_context
{
    SchGUICairoFactory  *factory;
    SchGUIDrawingCfg    *config;
    SchGUICairoDrawList *draw_list;
};

static void
schgui_cairo_factory_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_cairo_factory_create_from_drawing_proc(SchShape *shape, gpointer user_data);


static void
schgui_cairo_factory_class_init(gpointer g_class, gpointer g_class_data)
{
    SchGUICairoFactoryClass *klasse = SCHGUI_CAIRO_FACTORY_CLASS(g_class);
}

SchGUICairoDrawItem*
schgui_cairo_factory_create_from_drawing(SchGUICairoFactory *factory, SchDrawing *drawing, SchGUIDrawingCfg *config)
{
    struct _temp_context user_data;

    user_data.factory   = factory;
    user_data.config    = config;
    user_data.draw_list = NULL;

    sch_drawing_foreach(drawing, schgui_cairo_factory_create_from_drawing_proc, &user_data);

    return SCHGUI_CAIRO_DRAW_ITEM(user_data.draw_list);
}

static void
schgui_cairo_factory_create_from_drawing_proc(SchShape *shape, gpointer user_data)
{
    struct _temp_context *data = (struct _temp_context*) user_data;
    SchGUICairoDrawItem  *item;

    item = schgui_cairo_factory_create_item(data->factory, shape, data->config);

    if (item != NULL)
    {
        if (data->draw_list == NULL)
        {
            data->draw_list = SCHGUI_CAIRO_DRAW_LIST(g_object_new(SCHGUI_TYPE_CAIRO_DRAW_LIST, NULL));
        }

        schgui_cairo_draw_list_append(data->draw_list, item);
    }
}

GType
schgui_cairo_factory_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUICairoFactoryClass),    /* class_size */
            NULL,                               /* base_init */
            NULL,                               /* base_finalize */
            schgui_cairo_factory_class_init,    /* class_init */
            NULL,                               /* class_finalize */
            NULL,                               /* class_data */
            sizeof(SchGUICairoFactory),         /* instance_size */
            0,                                  /* n_preallocs */
            NULL,                               /* instance_init */
            NULL                                /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchGUICairoFactory",
            &tinfo,
            0
            );
    }

    return type;
}

SchGUICairoFactory*
schgui_cairo_factory_new(const SchFactory *shape, SchGUIDrawingCfg *config)
{
    return NULL;
}


/*! \todo Move to a hash table in the class stucture */
SchGUICairoDrawItem*
schgui_cairo_factory_create_item(SchGUICairoFactory *factory, SchShape *shape, SchGUIDrawingCfg *config)
{
    if (SCH_IS_ARC(shape))
    {
        return schgui_cairo_arc_new(SCH_ARC(shape), config);
    }
    else if (SCH_IS_BOX(shape))
    {
        return schgui_cairo_box_new(SCH_BOX(shape), config);
    }
    else if (SCH_IS_BUS(shape))
    {
        return schgui_cairo_bus_new(SCH_BUS(shape), config);
    }
    else if (SCH_IS_CIRCLE(shape))
    {
        return schgui_cairo_circle_new(SCH_CIRCLE(shape), config);
    }
    //else if (SCH_IS_COMPONENT(shape))
   // {
    //    return schgui_cairo_arc_new(shape, config);
   // }
    else if (SCH_IS_LINE(shape))
    {
        return schgui_cairo_line_new(SCH_LINE(shape), config);
    }
    else if (SCH_IS_NET(shape))
    {
        return schgui_cairo_net_new(SCH_NET(shape), config);
    }
    else if (SCH_IS_PIN(shape))
    {
        return schgui_cairo_pin_new(SCH_PIN(shape), config);
    }
    else if (SCH_IS_TEXT(shape))
    {
        return schgui_cairo_text_new(SCH_TEXT(shape), config);
    }
    else
    {
        return NULL;
    }
}

