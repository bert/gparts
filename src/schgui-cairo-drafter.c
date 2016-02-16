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

/*! \file schgui-cairo-drafter.c
 */

#include <math.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "schgui.h"


#define SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCHGUI_TYPE_CAIRO_DRAFTER,SchGUICairoDrafterPrivate))

enum
{
    SCHGUI_CAIRO_DRAFTER_CONFIG = 1,
    SCHGUI_CAIRO_DRAFTER_DRAWING
};

typedef struct _SchGUICairoDrafterPrivate SchGUICairoDrafterPrivate;

struct _SchGUICairoDrafterPrivate
{
    double zoom;
    double tx;
    double ty;

    PangoFontDescription *desc;

    SchGUIDrawingCfg   *config;
    SchDrawing         *drawing;
    SchGUICairoFactory *factory;

    SchGUICairoDrawItem *draw_list;
};

static void
schgui_cairo_drafter_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_cairo_drafter_init(GTypeInstance* instance, gpointer g_class);

static void
schgui_cairo_drafter_dispose(GObject *object);

static void
schgui_cairo_drafter_finalize(GObject *object);

static void
schgui_cairo_drafter_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
schgui_cairo_drafter_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
schgui_cairo_drafter_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(SchGUICairoDrafterPrivate));

    klasse->dispose  = schgui_cairo_drafter_dispose;
    klasse->finalize = schgui_cairo_drafter_finalize;

    klasse->get_property = schgui_cairo_drafter_get_property;
    klasse->set_property = schgui_cairo_drafter_set_property;

    g_object_class_install_property(
        klasse,
        SCHGUI_CAIRO_DRAFTER_CONFIG,
        g_param_spec_object(
            "config",
            "Configuration",
            "Configuration",
            SCHGUI_TYPE_DRAWING_CFG,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCHGUI_CAIRO_DRAFTER_DRAWING,
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
schgui_cairo_drafter_dispose(GObject *object)
{
    schgui_cairo_drafter_set_config(SCHGUI_CAIRO_DRAFTER(object), NULL);
    schgui_cairo_drafter_set_drawing(SCHGUI_CAIRO_DRAFTER(object), NULL);

    misc_object_chain_dispose(object);
}

void
schgui_cairo_drafter_draw_grid(SchGUICairoDrafter *drafter)
{
#if 0
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if ((privat != NULL) && (privat->cairo != NULL))
    {
        int      index;
        int      x;
        int      y;
        SchGUIDrawingCfgColor color;
        int          enabled;

        enabled = schgui_drawing_cfg_get_color(privat->config, 22, &color);

        if (enabled)
        {
            cairo_save(privat->cairo);

            cairo_translate(privat->cairo, 0.5, 0.5);

            cairo_set_source_rgb(privat->cairo, color.red, color.green, color.blue);

            cairo_set_line_width(privat->cairo, 3/privat->zoom);
    
            for (x=0; x<17000; x+=100)
            {
                cairo_move_to(privat->cairo, x, 0);
                cairo_line_to(privat->cairo, x, 17000);
                cairo_stroke(privat->cairo);
            }    

            for (y=0; y<17000; y+=100)
            {
                cairo_move_to(privat->cairo, 0, y);
                cairo_line_to(privat->cairo, 17000, y);
                cairo_stroke(privat->cairo);
            }    

            cairo_restore(privat->cairo);
        }
    }
#endif
}

void
schgui_cairo_drafter_draw_to_cairo(SchGUICairoDrafter *drafter, cairo_t *cairo)
{
    if (cairo != NULL)
    {
        SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

        if (privat != NULL)
        {
            cairo_identity_matrix(cairo);
            cairo_scale(cairo, 1, -1);
            cairo_translate(cairo, privat->tx, privat->ty);
            cairo_scale(cairo, privat->zoom, privat->zoom);
            cairo_set_line_width(cairo, 20);

            //    schgui_cairo_drafter_draw_grid(privat->drafter);

            schgui_cairo_draw_item_draw(privat->draw_list, cairo);
        }
    }
}

void
schgui_cairo_drafter_draw_to_widget(SchGUICairoDrafter *drafter, GtkWidget *widget)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        cairo_t *cairo = gdk_cairo_create(widget->window);

        if (cairo != NULL)
        {
            schgui_cairo_drafter_draw_to_cairo(drafter, cairo);

            cairo_destroy(cairo);
        }
    }
}

static void
schgui_cairo_drafter_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

static void
schgui_cairo_drafter_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCHGUI_CAIRO_DRAFTER_CONFIG:
                g_value_set_object(value, privat->config);
                break;

            case SCHGUI_CAIRO_DRAFTER_DRAWING:
                g_value_set_object(value, privat->drawing);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
schgui_cairo_drafter_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUICairoDrafterClass),      /* class_size */
            NULL,                                 /* base_init */
            NULL,                                 /* base_finalize */
            schgui_cairo_drafter_class_init,      /* class_init */
            NULL,                                 /* class_finalize */
            NULL,                                 /* class_data */
            sizeof(SchGUICairoDrafter),           /* instance_size */
            0,                                    /* n_preallocs */
            schgui_cairo_drafter_init,            /* instance_init */
            NULL                                  /* value_table */
            };

        static const GInterfaceInfo iinfob = {
            NULL,                                 /* interface_init */
            NULL,                                 /* interface_finalize */
            NULL                                  /* interface_data */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchGUICairoDrafter",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GTK_TYPE_BUILDABLE, &iinfob);
    }

    return type;
}

static void
schgui_cairo_drafter_init(GTypeInstance* instance, gpointer g_class)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->desc = pango_font_description_from_string("Sans");
    }
}

void
schgui_cairo_drafter_set_zoom(SchGUICairoDrafter *drafter, double zoom)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        privat->zoom = zoom;
    }
}

void
schgui_cairo_drafter_set_translate(SchGUICairoDrafter *drafter, double tx, double ty)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        privat->tx = tx;
        privat->ty = ty;
    }
}

void
schgui_cairo_drafter_set_config(SchGUICairoDrafter *drafter, SchGUIDrawingCfg *config)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        if (privat->draw_list != NULL)
        {
            g_object_unref(privat->draw_list);
            privat->draw_list = NULL;
        }

        if (privat->factory != NULL)
        {
            g_object_unref(privat->factory);
            privat->factory = NULL;
        }

        if (privat->config != NULL)
        {
            /*! \todo unregister signals to update */
            g_object_unref(privat->config);
        }

        privat->config = config;

        if (privat->config != NULL)
        {
            g_object_ref(privat->config);

            /*! \todo register signals to update */
        }

        privat->factory = schgui_cairo_factory_new(privat->config);

        if ((privat->config != NULL) && (privat->drawing != NULL))
        {
            privat->draw_list = schgui_cairo_factory_create_from_drawing(privat->factory, privat->drawing);
        }
    }
}

void
schgui_cairo_drafter_set_drawing(SchGUICairoDrafter *drafter, SchDrawing *drawing)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        if (privat->drawing != NULL)
        {
            /*! \todo unregister signals to update */

            g_object_unref(privat->drawing);
        }

        privat->drawing = drawing;

        if (privat->drawing != NULL)
        {
            g_object_ref(privat->drawing);

            /*! \todo register signals to update */
        }

        if (privat->draw_list != NULL)
        {
            g_object_unref(privat->draw_list);

            privat->draw_list = NULL;
        }

        if ((privat->config != NULL) && (privat->drawing != NULL))
        {
            privat->draw_list = schgui_cairo_factory_create_from_drawing(privat->factory, privat->drawing);
        }
    }
}

static void
schgui_cairo_drafter_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    switch (property_id)
    {
        case SCHGUI_CAIRO_DRAFTER_CONFIG:
            schgui_cairo_drafter_set_config(SCHGUI_CAIRO_DRAFTER(object), g_value_get_object(value));
            break;

        case SCHGUI_CAIRO_DRAFTER_DRAWING:
            schgui_cairo_drafter_set_drawing(SCHGUI_CAIRO_DRAFTER(object), g_value_get_object(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
schgui_cairo_drafter_zoom_extents(SchGUICairoDrafter *drafter, GtkWidget *widget)
{
    SchGUICairoDrafterPrivate *privat = SCHGUI_CAIRO_DRAFTER_GET_PRIVATE(drafter);

    if (privat != NULL)
    {
        if (privat->draw_list != NULL)
        {
            GeomBounds bounds;
            cairo_t    *cairo;
            int        w;
            int        h;
            double     zx;
            double     zy;

            cairo = gdk_cairo_create(widget->window);
           // schgui_cairo_drafter_begin_drawing(privat->drafter, widget);

            //schgui_cairo_drafter_drawing_bounds1(drafter, privat->drawing, &bounds);

            geom_bounds_init(&bounds);

            schgui_cairo_draw_item_bounds(privat->draw_list, cairo, &bounds);

            if (cairo != NULL)
            {
                cairo_destroy(cairo);
            }

            //g_debug("Min X = %d", bounds.min_x);
            //g_debug("Min Y = %d", bounds.min_y);
            //g_debug("Max X = %d", bounds.max_x);
            //g_debug("Max Y = %d", bounds.max_y);

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

