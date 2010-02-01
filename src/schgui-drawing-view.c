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

#include "geom.h"

#include "sch-multiline.h"
#include "sch-text.h"
#include "sch-drafter.h"
#include "sch-drawing.h"
#include "sch-line.h"

#include "schgui-drawing-cfg.h"
#include "schgui-cairo-drafter.h"
#include "schgui-drawing-view.h"

#define SCHGUI_DRAWING_VIEW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_DRAWING_VIEW,SchGUIDrawingViewPrivate))

enum
{
    SCHGUI_DRAWING_VIEW_DRAFTER = 1,
    SCHGUI_DRAWING_VIEW_DRAWING
};

typedef struct _SchGUIDrawingViewPrivate SchGUIDrawingViewPrivate;

struct _SchGUIDrawingViewPrivate
{
    SchGUICairoDrafter *drafter;
    SchDrawing         *drawing;

    gdouble            zoom;
    gdouble            tx;
    gdouble            ty;
};

static void
schgui_drawing_view_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_drawing_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
schgui_drawing_view_init(GTypeInstance *instance, gpointer g_class);

static void
schgui_drawing_view_schematic_shape_init(gpointer g_iface, gpointer g_iface_data);

static void
schgui_drawing_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
schgui_drawing_view_configure_event_cb(GtkWidget *widget, GdkEventConfigure *event, gpointer user_data);

static void
schgui_drawing_view_expose_event_cb(GtkWidget *widget, GdkEventExpose *event, gpointer user_data);

static void
schgui_drawing_view_realize_cb(GtkWidget *widget, gpointer user_data);

static void
schgui_drawing_view_unrealize_cb(GtkWidget *widget, gpointer user_data);

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

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

static void
schgui_drawing_view_realize_cb(GtkWidget *widget, gpointer user_data)
{
    double   blue;
    GdkColor color;
    double   green;
    double   red;

    sch_color_get_default(0, &red, &green, &blue);

    color.red   = 65535 * red;
    color.green = 65535 * green;
    color.blue  = 65535 * blue;
   
    gtk_widget_modify_bg(widget, GTK_STATE_NORMAL, &color); 
}

static void
schgui_drawing_view_expose_event_cb(GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        if (privat->drawing != NULL)
        {
            if (privat->drafter != NULL)
            {

                schgui_cairo_drafter_set_zoom(privat->drafter,1 );
                schgui_cairo_drafter_set_translate(privat->drafter, 0, 0);
                schgui_cairo_drafter_begin_drawing(privat->drafter, widget);
                schgui_drawing_view_zoom_extents(widget);
                schgui_cairo_drafter_end_drawing(privat->drafter);

                schgui_cairo_drafter_set_zoom(privat->drafter, privat->zoom);
                schgui_cairo_drafter_set_translate(privat->drafter, privat->tx, privat->ty);
                schgui_cairo_drafter_begin_drawing(privat->drafter, widget);

                schgui_cairo_drafter_draw_grid(privat->drafter);

                sch_drawing_draw(privat->drawing, SCH_DRAFTER(privat->drafter));
    
                schgui_cairo_drafter_end_drawing(privat->drafter);
            }
        }
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
        privat->drafter = SCHGUI_CAIRO_DRAFTER(g_object_new(
            SCHGUI_TYPE_CAIRO_DRAFTER,
            "config", schgui_drawing_cfg_get_default_display(),
            NULL
            ));
    }

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
            /* \todo unregister signals to update */

            g_object_unref(privat->drawing);
        }

        privat->drawing = drawing;

        if (privat->drawing != NULL)
        {
            g_object_ref(privat->drawing);

            /* \todo register signals to update */
        }

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

void
schgui_drawing_view_zoom_extents(SchGUIDrawingView *widget)
{
    SchGUIDrawingViewPrivate *privat = SCHGUI_DRAWING_VIEW_GET_PRIVATE(widget);

    if (privat != NULL)
    {
        if (privat->drawing != NULL)
        {
            if (privat->drafter != NULL)
            {
                GeomBounds bounds;
                int w;
                int h;
                double zx;
                double zy;

               // schgui_cairo_drafter_begin_drawing(privat->drafter, widget);

                sch_drawing_bounds(privat->drawing, privat->drafter, &bounds);

                g_debug("Min X = %d", bounds.min_x);
                g_debug("Min Y = %d", bounds.min_y);
                g_debug("Max X = %d", bounds.max_x);
                g_debug("Max Y = %d", bounds.max_y);

               // schgui_cairo_drafter_end_drawing(privat->drafter);

                gdk_drawable_get_size(gtk_widget_get_window(widget), &w, &h);

                zx = 0.9 * (double)w / (bounds.max_x - bounds.min_x);
                zy = 0.9 * (double)h / (bounds.max_y - bounds.min_y);

                if (zx < zy)
                {
                    privat->zoom = zx;
                }
                else
                {
                    privat->zoom = zy;
                }

                {
                    double m;
                    int    exp;
                    int    numerator;

                    m = frexp(10/privat->zoom, &exp);

                    //if (m < 0.2)
                   // {
                    //    m = 0.1;
                   // }
                   // else if (m < 0.5)
                   // {
                   //     m = 0.2;
                   // }
                   // else if (m < 1.0)
                   // {
                   //     m = 0.5;
                   // }
                   // else
                   // {
                   //     m = 1.0;
                   // }

                    if (m > 0.5)
                    {
                        m = 1.0;
                    }
                    else if (m > 0.2)
                    {
                        m = 0.5;
                    }
                    else if (m > 0.1)
                    {
                        m = 0.2;
                    }
                    else 
                    {
                        m = 0.1;
                    }
                    numerator = privat->zoom * ldexp(m, exp);

                    privat->zoom = numerator / ldexp(m, exp);
                }

                privat->tx = (w - privat->zoom * (bounds.max_x)) / 2   - (privat->zoom * bounds.min_x) / 2;
                privat->ty =  - h - ((privat->zoom * (bounds.max_y + bounds.min_y) ) - h ) / 2;
            }
        }
    }
}

