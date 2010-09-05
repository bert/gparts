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

/*! \file sch-cairo-shape.c
 */

#include <glib-object.h>

#include "misc-object.h"

#include "sch.h"


#define SCH_CAIRO_SHAPE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_CAIRO_SHAPE,SchCairoShapePrivate))

enum
{
    SCH_CAIRO_SHAPE_ATTRIBUTES = 1,
};

typedef struct _SchCairoShapePrivate SchCairoShapePrivate;

struct _SchCairoShapePrivate
{
    SchAttributes *attributes;
};


static void
sch_cairo_shape_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_cairo_shape_dispose(GObject *object);

static void
sch_cairo_shape_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_cairo_shape_init(GTypeInstance *instance, gpointer g_class);

static void
sch_cairo_shape_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
sch_cairo_shape_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);
    SchCairoShapeClass *klasse = SCH_CAIRO_SHAPE_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(SchCairoShapePrivate));

    object_class->dispose = sch_cairo_shape_dispose;

    klasse->parent.get_property = sch_cairo_shape_get_property;
    klasse->parent.set_property = sch_cairo_shape_set_property;

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        SCH_CAIRO_SHAPE_ATTRIBUTES,
        g_param_spec_object(
            "attributes",
            "Attributes",
            "Attributes",
            SCH_TYPE_ATTRIBUTES,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}


void
sch_cairo_shape_draw(SchCairoShape *shape, cairo_t *cairo)
{
    SchCairoShapeClass   *klasse = SCH_CAIRO_SHAPE_GET_CLASS(shape);
    SchCairoShapePrivate *privat = SCH_CAIRO_SHAPE_GET_PRIVATE(shape);

    if ((klasse != NULL) && (klasse->draw != NULL))
    {
        klasse->draw(shape, drafter);
    }

    if ((privat != NULL) && (privat->attributes != NULL))
    {
        sch_attributes_draw(privat->attributes, drafter);
    }
}

static void
sch_cairo_shape_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchCairoShapePrivate *privat = SCH_CAIRO_SHAPE_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCH_CAIRO_SHAPE_ATTRIBUTES:
                g_value_set_object(value, privat->attributes);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
sch_cairo_shape_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchCairoShapeClass),    /* class_size */
            NULL,                     /* base_init */
            NULL,                     /* base_finalize */
            sch_cairo_shape_class_init,     /* class_init */
            NULL,                     /* class_finalize */
            NULL,                     /* class_data */
            sizeof(SchCairoShape),         /* instance_size */
            0,                        /* n_preallocs */
            sch_cairo_shape_init,           /* instance_init */
            NULL                      /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchCairoShape",
            &tinfo,
            G_TYPE_FLAG_ABSTRACT
            );
    }

    return type;
}

static void
sch_cairo_shape_init(GTypeInstance *instance, gpointer g_class)
{
    SchCairoShapePrivate *privat;

    privat = SCH_CAIRO_SHAPE_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->attributes = g_object_new(SCH_TYPE_ATTRIBUTES, NULL);
    }
}

void
sch_cairo_shape_rotate(SchCairoShape *shape, int angle)
{
    SchCairoShapeClass *klasse = SCH_CAIRO_SHAPE_GET_CLASS(shape);

    if ((klasse != NULL) && (klasse->rotate != NULL))
    {
        klasse->rotate(shape, angle);
    }
}

static void
sch_cairo_shape_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchCairoShapePrivate *privat = SCH_CAIRO_SHAPE_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCH_CAIRO_SHAPE_ATTRIBUTES:
                sch_cairo_shape_set_attributes(SCH_CAIRO_SHAPE(object), g_value_get_object(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}
 
void
sch_cairo_shape_transform(SchCairoShape *shape, const GeomTransform *transform)
{
    SchCairoShapeClass *klasse = SCH_CAIRO_SHAPE_GET_CLASS(shape);

    if ((klasse != NULL) && (klasse->transform != NULL))
    {
        klasse->transform(shape, transform);
    }
}

void
sch_cairo_shape_translate(SchCairoShape *shape, int dx, int dy)
{
    SchCairoShapeClass *klasse = SCH_CAIRO_SHAPE_GET_CLASS(shape);

    if ((klasse != NULL) && (klasse->translate != NULL))
    {
        klasse->translate(shape, dx, dy);
    }
}

SchAttributes*
sch_cairo_shape_get_attributes(SchCairoShape *shape)
{
    SchAttributes   *attributes = NULL;
    SchCairoShapePrivate *privat = SCH_CAIRO_SHAPE_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        if (privat->attributes != NULL)
        {
            g_object_ref(privat->attributes);
        }

        attributes = privat->attributes;
    }

    return attributes;
}

void
sch_cairo_shape_set_attributes(SchCairoShape *shape, SchAttributes *attributes)
{
    SchCairoShapePrivate *privat = SCH_CAIRO_SHAPE_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        if (privat->attributes != NULL)
        {
            g_object_unref(privat->attributes);
        }

        privat->attributes = attributes;

        if (privat->attributes != NULL)
        {
            g_object_ref(privat->attributes);
        }

        g_object_notify(G_OBJECT(shape), "attributes");
    }
}

void
sch_cairo_shape_write(SchCairoShape *shape, SchFileFormat2 *format, SchOutputStream *stream, GError **error)
{
    SchCairoShapeClass *klasse = SCH_CAIRO_SHAPE_GET_CLASS(shape);

    if ((klasse != NULL) && (klasse->write != NULL))
    {
        klasse->write(shape, format, stream, error);
    }
}

