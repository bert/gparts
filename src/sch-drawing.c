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

/*! \file sch-drawing.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>

#include "sch.h"

#define SCH_DRAWING_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_DRAWING,SchDrawingPrivate))

//enum
//{
//    SCH_DRAWING_X1 = 1,
//};

typedef struct _SchDrawingPrivate SchDrawingPrivate;

struct _SchDrawingPrivate
{
    SchFileFormat2 *file_format;
    GSList         *shapes;
};

static gboolean
sch_drawing_calculate_bounds(SchDrawing *drawing, SchDrafter *drafter, GeomBounds *bounds);

static void
sch_drawing_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_drawing_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_drawing_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
sch_drawing_init(GTypeInstance *instance, gpointer g_class);


void
sch_drawing_add_shape(SchDrawing *drawing, GObject *shape)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(drawing);

    if (shape != NULL)
    {
        g_object_ref(shape);
        privat->shapes = g_slist_append(privat->shapes, shape);
    }
}

gboolean
sch_drawing_bounds(SchDrawing *drawing, SchDrafter *drafter, GeomBounds *bounds)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(drawing);
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
sch_drawing_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(SchDrawingPrivate));

    object_class->get_property = sch_drawing_get_property;
    object_class->set_property = sch_drawing_set_property;
}

void
sch_drawing_draw(SchDrawing *drawing, SchDrafter *drafter)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(drawing);

    if (privat != NULL)
    {
        g_slist_foreach(privat->shapes, sch_shape_draw, drafter);
    }
}

static void
sch_drawing_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(object);

    switch (property_id)
    {
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
sch_drawing_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchDrawingClass),    /* class_size */
            NULL,                       /* base_init */
            NULL,                       /* base_finalize */
            sch_drawing_class_init,     /* class_init */
            NULL,                       /* class_finalize */
            NULL,                       /* class_data */
            sizeof(SchDrawing),         /* instance_size */
            0,                          /* n_preallocs */
            sch_drawing_init,           /* instance_init */
            NULL                        /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchDrawing",
            &tinfo,
            0
            );
    }

    return type;
}

static void
sch_drawing_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(object);

    switch (property_id)
    {
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

static void
sch_drawing_init(GTypeInstance *instance, gpointer g_class)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->file_format = (SchFileFormat2*) g_object_new(SCH_TYPE_FILE_FORMAT_2, NULL);

        g_debug("Assign file format");
    }
}

void
sch_drawing_rotate(SchDrawing *drawing, int angle)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(drawing);

    if (privat != NULL)
    {
        GSList *node = privat->shapes;

        while (node != NULL)
        {
            sch_shape_rotate((SchShape*) node->data, angle);

            node = g_slist_next(node);
        }
    }
}

void
sch_drawing_transform(SchDrawing *drawing, const struct _GeomTransform *transform)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(drawing);

    if (privat != NULL)
    {
        GSList *node = privat->shapes;

        while (node != NULL)
        {
            sch_shape_transform((SchShape*) node->data, transform);

            node = g_slist_next(node);
        }
    }
}

void
sch_drawing_translate(SchDrawing *drawing, int dx, int dy)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(drawing);

    if (privat != NULL)
    {
        GSList *node = privat->shapes;

        while (node != NULL)
        {
            sch_shape_translate((SchShape*) node->data, dx, dy);

            node = g_slist_next(node);
        }
    }
}

void
sch_drawing_write(const SchDrawing *drawing, SchOutputStream *stream)
{
    SchDrawingPrivate *privat = SCH_DRAWING_GET_PRIVATE(drawing);

    if (privat != NULL)
    {
        GSList *node = privat->shapes;

        sch_file_format_2_write_version(privat->file_format, stream, NULL);

        while (node != NULL)
        {
            sch_shape_write(SCH_SHAPE(node->data), privat->file_format, stream, NULL);

            node = g_slist_next(node);
        }
   }
}

