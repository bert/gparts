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

/*! \file schgui-cairo-drawing.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>

#include "misc-object.h"

#include "schgui.h"

#define SCHGUI_CAIRO_DRAWING_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_DRAWING,SchGUIDrawingPrivate))

enum
{
    SCHGUI_CAIRO_DRAWING_FILE_FORMAT = 1,
};

typedef struct _SchGUIDrawingPrivate SchGUIDrawingPrivate;

struct _SchGUIDrawingPrivate
{
    GSList *shapes;
};

static void
schgui_cairo_drawing_class_init(gpointer g_class, gpointer g_class_data);

static void
schgui_cairo_drawing_dispose(GObject *object);

static void
schgui_cairo_drawing_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
schgui_cairo_drawing_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
schgui_cairo_drawing_init(GTypeInstance *instance, gpointer g_class);


void
schgui_cairo_drawing_append_shape(SchGUIDrawing *drawing, SchShape *shape)
{
    if (shape != NULL)
    {
        SchGUIDrawingPrivate *privat = SCHGUI_CAIRO_DRAWING_GET_PRIVATE(drawing);

        if (privat != NULL)
        {
            SchGUIDrawingClass *klasse = SCHGUI_CAIRO_DRAWING_GET_CLASS(drawing);

            g_object_ref(shape);

            privat->shapes = g_slist_append(privat->shapes, shape);

            if (klasse != NULL)
            {
                g_signal_emit(
                    drawing,
                    klasse->signal_id[SCHGUI_CAIRO_DRAWING_SIGNAL_APPEND],
                    0,
                    shape
                    );
            }
        }
    }
}

gboolean
schgui_cairo_drawing_bounds(SchGUIDrawing *drawing, SchDrafter *drafter, GeomBounds *bounds)
{
    SchGUIDrawingPrivate *privat = SCHGUI_CAIRO_DRAWING_GET_PRIVATE(drawing);
    gboolean success = FALSE;

    if (privat != NULL)
    {
        GSList *node = privat->shapes;

        success = TRUE;
        geom_bounds_init(bounds);

        while (node != NULL)
        {
            GeomBounds temp;

            geom_bounds_init(&temp);
            sch_shape_bounds((SchShape*) node->data, drafter, &temp);

            geom_bounds_union(bounds, bounds, &temp);

            node = g_slist_next(node);
        }
    }

    return success;
}

static void
schgui_cairo_drawing_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);
    SchGUIDrawingClass *klasse = SCHGUI_CAIRO_DRAWING_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(SchGUIDrawingPrivate));

    object_class->get_property = schgui_cairo_drawing_get_property;
    object_class->set_property = schgui_cairo_drawing_set_property;

    object_class->dispose = schgui_cairo_drawing_dispose;

    g_object_class_install_property(
        object_class,
        SCHGUI_CAIRO_DRAWING_FILE_FORMAT,
        g_param_spec_object(
            "file-format",
            "File Format",
            "File Format",
            SCH_TYPE_FILE_FORMAT_2,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    klasse->signal_id[SCHGUI_CAIRO_DRAWING_SIGNAL_APPEND] = g_signal_new(
        "append",
        SCH_TYPE_DRAWING,
        G_SIGNAL_RUN_LAST,
        0,
        NULL,
        NULL,
        g_cclosure_marshal_VOID__POINTER,
        G_TYPE_NONE,
        1,
        SCH_TYPE_SHAPE
        );

    klasse->signal_id[SCHGUI_CAIRO_DRAWING_SIGNAL_PREPEND] = g_signal_new(
        "prepend",
        SCH_TYPE_DRAWING,
        G_SIGNAL_RUN_LAST,
        0,
        NULL,
        NULL,
        g_cclosure_marshal_VOID__POINTER,
        G_TYPE_NONE,
        1,
        SCH_TYPE_SHAPE
        );

}

static void
schgui_cairo_drawing_dispose(GObject *object)
{
    SchGUIDrawingPrivate *privat = SCHGUI_CAIRO_DRAWING_GET_PRIVATE(object);

    if (privat != NULL)
    {
        GSList *node = privat->shapes;

        while (node != NULL)
        {
            g_object_unref(node->data);
            node = g_slist_next(node);
        }

        g_slist_free(privat->shapes);
        privat->shapes = NULL;

        if (privat->file_format != NULL)
        {
            g_object_unref(privat->file_format);
            privat->file_format = NULL;
        }
    }

    misc_object_chain_dispose(object);
}

void
schgui_cairo_drawing_draw(SchGUIDrawing *drawing, SchDrafter *drafter)
{
    SchGUIDrawingPrivate *privat = SCHGUI_CAIRO_DRAWING_GET_PRIVATE(drawing);

    if (privat != NULL)
    {
        GSList *node = privat->shapes;

        while (node != NULL)
        {
            sch_shape_draw(SCH_SHAPE(node->data), drafter);

            node = g_slist_next(node);
        }
    }
}

void
schgui_cairo_drawing_foreach(SchGUIDrawing *drawing, GFunc func, gpointer user_data)
{
    if (func != NULL)
    {
        SchGUIDrawingPrivate *privat = SCHGUI_CAIRO_DRAWING_GET_PRIVATE(drawing);

        if (privat != NULL)
        {
            g_slist_foreach(privat->shapes, func, user_data);
        }
    }
}

void
schgui_cairo_drawing_prepend_shape(SchGUIDrawing *drawing, SchShape *shape)
{
    if (shape != NULL)
    {
        SchGUIDrawingPrivate *privat = SCHGUI_CAIRO_DRAWING_GET_PRIVATE(drawing);

        if (privat != NULL)
        {
            SchGUIDrawingClass *klasse = SCHGUI_CAIRO_DRAWING_GET_CLASS(drawing);

            g_object_ref(shape);

            privat->shapes = g_slist_prepend(privat->shapes, shape);

            if (klasse != NULL)
            {
                g_signal_emit(
                    drawing,
                    klasse->signal_id[SCHGUI_CAIRO_DRAWING_SIGNAL_PREPEND],
                    0,
                    shape
                    );
            }
        }
    }
}

static void
schgui_cairo_drawing_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchGUIDrawingPrivate *privat = SCHGUI_CAIRO_DRAWING_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCHGUI_CAIRO_DRAWING_FILE_FORMAT:
                g_value_set_object(value, privat->file_format);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
schgui_cairo_drawing_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchGUIDrawingClass),    /* class_size */
            NULL,                       /* base_init */
            NULL,                       /* base_finalize */
            schgui_cairo_drawing_class_init,     /* class_init */
            NULL,                       /* class_finalize */
            NULL,                       /* class_data */
            sizeof(SchGUIDrawing),         /* instance_size */
            0,                          /* n_preallocs */
            schgui_cairo_drawing_init,           /* instance_init */
            NULL                        /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchGUIDrawing",
            &tinfo,
            0
            );
    }

    return type;
}

void
schgui_cairo_drawing_set_file_format(SchGUIDrawing *drawing, SchFileFormat2 *format)
{
    SchGUIDrawingPrivate *privat = SCHGUI_CAIRO_DRAWING_GET_PRIVATE(drawing);

    if (privat != NULL)
    {
        if (privat->file_format != NULL)
        {
            g_object_unref(privat->file_format);
        }

        privat->file_format = format;

        if (privat->file_format != NULL)
        {
            g_object_ref(privat->file_format);
        }
    }
}

static void
schgui_cairo_drawing_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    switch (property_id)
    {
        case SCHGUI_CAIRO_DRAWING_FILE_FORMAT:
            schgui_cairo_drawing_set_file_format(SCHGUI_CAIRO_DRAWING(object), SCH_FILE_FORMAT_2(g_value_get_object(value)));
            break; 

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
schgui_cairo_drawing_init(GTypeInstance *instance, gpointer g_class)
{
}

