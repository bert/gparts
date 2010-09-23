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

/*! \file schgui-drawing-view.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "sch.h"

#include "schgui-drawing-cfg.h"
#include "schgui-cairo-drafter.h"
#include "schgui-drawing-view.h"

#define SCHGUI_DRAWING_VIEW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_DRAWING_VIEW,SchGUIDrawingViewPrivate))

enum
{
    SCHGUI_DRAWING_VIEW_DRAFTER = 1,
    SCHGUI_DRAWING_VIEW_DRAWING,
    SCHGUI_DRAWING_VIEW_EXTENTS
};

typedef struct _SchGUIDrawingViewPrivate SchGUIDrawingViewPrivate;

struct _SchGUIDrawingViewPrivate
{
    SchGUIDrawingCfg   *config;
    int                extents;
    SchGUICairoDrafter *drafter;
    SchDrawing         *drawing;
};

static void
schgui_drawing_view_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_drawing_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
schgui_drawing_view_init(GTypeInstance *instance, gpointer g_class);

static void
schgui_drawing_view_set_config(SchGUIDrawingView *widget, SchGUIDrawingCfg *config);

static void
schgui_drawing_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
schgui_drawing_view_configure_event_cb(GtkWidget *widget, GdkEventConfigure *event, gpointer user_data);

static void
schgui_drawing_view_expose_event_cb(GtkWidget *widget, GdkEventExpose *event, gpointer user_data);

static void
schgui_drawing_view_realize_cb(GtkWidget *widget, gpointer user_data);

/**** Signal Handlers ****/

static void
schgui_drawing_view_bind_drawing(SchDrawing *drawing, SchGUIDrawingView *view);

static void
schgui_drawing_view_bind_shape(SchShape *shape, SchGUIDrawingView *view);

static void
schgui_drawing_view_unbind_drawing(SchDrawing *drawing, SchGUIDrawingView *view);

static void
schgui_drawing_view_unbind_shape(SchShape *shape, SchGUIDrawingView *view);



static void
schgui_drawing_view_append_shape(SchDrawing *drawing, SchShape *shape, SchGUIDrawingView *view)
{
//    g_debug("schgui_drawing_view_append_shape");
}



static void
schgui_drawing_view_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(SchGUIDrawingViewPrivate));

    object_class->get_property = schgui_drawing_view_get_property;
    object_class->set_property = schgui_drawing_view_set_property;

    g_object_class_install_property(
        object_class,
        SCHGUI_DRAWING_VIEW_DRAFTER,
        g_param_spec_object(
            "drafter",
            "Drafter",
            "Drafter",
            G_TYPE_OBJECT,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCHGUI_DRAWING_VIEW_DRAWING,
        g_param_spec_object(
            "drawing",
            "Drawing",
            "Drawing",
            SCH_TYPE_DRAWING,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCHGUI_DRAWING_VIEW_EXTENTS,
        g_param_spec_boolean(
            "extents",
            "Extents",
            "Extents",
            TRUE,
            G_PARAM_LAX_VALIDATION | G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );
}



static void
schgui_drawing_view_bind_drawing(SchDrawing *drawing, SchGUIDrawingView *view)
{
//    g_debug("schgui_drawing_view_bind_drawing");

    if (drawing != NULL)
    {
        sch_drawing_foreach(drawing, schgui_drawing_view_bind_shape, view);
    }
}

static void
schgui_drawing_view_bind_shape(SchShape *shape, SchGUIDrawingView *view)
{
//    g_debug("schgui_drawing_view_bind_shape");
}

static void
schgui_drawing_view_configure_event_cb(GtkWidget *widget, GdkEventConfigure *event, gpointer user_data)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        if (privat->extents)
        {
            schgui_drawing_view_zoom_extents(SCHGUI_DRAWING_VIEW(widget));
        }
    }
}

SchDrawing*
schgui_drawing_view_get_drawing(SchGUIDrawingView *widget)
{
    SchDrawing *drawing = NULL;
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        drawing = privat->drawing;

        if (drawing != NULL)
        {
            g_object_ref(drawing);
        }
    }

    return drawing;
}

static void
schgui_drawing_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCHGUI_DRAWING_VIEW_DRAFTER:
                g_value_set_object(value, privat->drafter);
                break;

            case SCHGUI_DRAWING_VIEW_DRAWING:
                g_value_set_object(value, privat->drawing);
                break;

            case SCHGUI_DRAWING_VIEW_EXTENTS:
                g_value_set_boolean(value, privat->extents);

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

static void
schgui_drawing_view_realize_cb(GtkWidget *widget, gpointer user_data)
{
    GdkColor color;
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        schgui_drawing_cfg_get_background_as_gdk_color(privat->config, &color);
    }
    else
    {
        color.red   = 0;
        color.green = 0;
        color.blue  = 0;
    }

    gtk_widget_modify_bg(widget, GTK_STATE_NORMAL, &color); 
}

/*! \brief
 *
 *
 *
 *
 *
 */
static void
schgui_drawing_view_expose_event_cb(GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if ((privat != NULL) && (privat->drafter != NULL))
    {
        schgui_cairo_drafter_draw_to_widget(privat->drafter, widget);
    }
}

GType
schgui_drawing_view_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUIDrawingViewClass),    /* class_size */
            NULL,                              /* base_init */
            NULL,                              /* base_finalize */
            schgui_drawing_view_class_init,    /* class_init */
            NULL,                              /* class_finalize */
            NULL,                              /* class_data */
            sizeof(SchGUIDrawingView),         /* instance_size */
            0,                                 /* n_preallocs */
            schgui_drawing_view_init,          /* instance_init */
            NULL                               /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            NULL,                              /* interface_init */
            NULL,                              /* interface_finalize */
            NULL                               /* interface_data */
            };

        type = g_type_register_static(
            GTK_TYPE_DRAWING_AREA,
            "SchGUIDrawingView",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GTK_TYPE_BUILDABLE, &iinfo);
    }

    return type;
}

static void
schgui_drawing_view_init(GTypeInstance *instance, gpointer g_class)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        schgui_drawing_view_set_config(
            instance,
            schgui_drawing_cfg_get_default_display()
            );

        privat->drafter = SCHGUI_CAIRO_DRAFTER(
            g_object_new(
                SCHGUI_TYPE_CAIRO_DRAFTER,
                "config", privat->config,
                NULL
                )
            );
    }

    g_signal_connect(
        G_OBJECT(instance),
        "configure-event",
        G_CALLBACK(schgui_drawing_view_configure_event_cb),
        instance
        );

    g_signal_connect(
        G_OBJECT(instance),
        "expose-event",
        G_CALLBACK(schgui_drawing_view_expose_event_cb),
        instance
        );

    g_signal_connect(
        G_OBJECT(instance),
        "realize",
        G_CALLBACK(schgui_drawing_view_realize_cb),
        instance
        );
}

static void
schgui_drawing_view_set_config(SchGUIDrawingView *widget, SchGUIDrawingCfg *config)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        if (privat->config != NULL)
        {
            g_object_unref(privat->config);
        }

        privat->config = config;

        if (privat->config != NULL)
        {
            g_object_ref(privat->config);
        }

        gtk_widget_queue_draw(GTK_WIDGET(widget));
    }
}


void
schgui_drawing_view_set_drafter(SchGUIDrawingView *widget, SchGUICairoDrafter *drafter)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        if (privat->drafter != NULL)
        {
            g_object_unref(privat->drafter);
        }

        privat->drafter = drafter;

        if (privat->drafter != NULL)
        {
            g_object_ref(privat->drafter);
        }

        gtk_widget_queue_draw(GTK_WIDGET(widget));
    }
}


void
schgui_drawing_view_set_drawing(SchGUIDrawingView *widget, SchDrawing *drawing)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        if (privat->drawing != NULL)
        {
            schgui_drawing_view_unbind_drawing(drawing, widget);

            g_object_unref(privat->drawing);
        }

        privat->drawing = drawing;

        if (privat->drawing != NULL)
        {
            g_object_ref(privat->drawing);

            schgui_drawing_view_bind_drawing(drawing, widget);
        }

        if (privat->drafter != NULL)
        {
            schgui_cairo_drafter_set_drawing(privat->drafter, privat->drawing);

            schgui_drawing_view_zoom_extents(widget);
        }

        g_object_notify(G_OBJECT(widget), "drawing");

        gtk_widget_queue_draw(GTK_WIDGET(widget));
    }
}

static void
schgui_drawing_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    switch (property_id)
    {
        case SCHGUI_DRAWING_VIEW_DRAFTER:
            schgui_drawing_view_set_drafter(SCHGUI_DRAWING_VIEW(object), g_value_get_object(value));
            break;

        case SCHGUI_DRAWING_VIEW_DRAWING:
            schgui_drawing_view_set_drawing(SCHGUI_DRAWING_VIEW(object), g_value_get_object(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
schgui_drawing_view_unbind_drawing(SchDrawing *drawing, SchGUIDrawingView *view)
{
//    g_debug("schgui_drawing_view_unbind_drawing");

    if (drawing != NULL)
    {
        sch_drawing_foreach(drawing, schgui_drawing_view_unbind_shape, view);
    }
}

static void
schgui_drawing_view_unbind_shape(SchShape *shape, SchGUIDrawingView *view)
{
//    g_debug("schgui_drawing_view_unbind_shape");
}


void
schgui_drawing_view_zoom_extents(SchGUIDrawingView *widget)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if ((privat != NULL) && (privat->drafter != NULL))
    {
        schgui_cairo_drafter_zoom_extents(privat->drafter, GTK_WIDGET(widget));

        privat->extents = TRUE;
        g_object_notify(G_OBJECT(widget), "extents"); 

        gtk_widget_queue_draw(GTK_WIDGET(widget));
    }
}

