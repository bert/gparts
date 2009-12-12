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

/*! \file sch-arc.c
 */

#include <glib.h>
#include <glib-object.h>

#include "geom.h"

#include "sch-multiline.h"
#include "sch-shape.h"
#include "sch-arc.h"
#include "sch-text.h"
#include "sch-drafter.h"

#define SCH_ARC_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_ARC,SchArcPrivate))

enum
{
    SCH_ARC_CENTER_X = 1,
    SCH_ARC_CENTER_Y,
    SCH_ARC_RADIUS,
    SCH_ARC_START,
    SCH_ARC_SWEEP,
    SCH_ARC_COLOR,
    SCH_ARC_WIDTH,
    SCH_ARC_CAP_STYLE,
    SCH_ARC_DASH_STYLE,
    SCH_ARC_DASH_LENGTH,
    SCH_ARC_DASH_SPACE
};

typedef struct _SchArcPrivate SchArcPrivate;

struct _SchArcPrivate
{
    GeomArc arc;
    gint    color;
    gint    line_width;
    gint    line_cap_style;
    gint    line_dash_style;
    gint    line_dash_length;
    gint    line_dash_space;
};

static gboolean
sch_arc_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds);

static void
sch_arc_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_arc_draw(SchShape *shape, SchDrafter *drafter);

static void
sch_arc_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_arc_schematic_shape_init(gpointer g_iface, gpointer g_iface_data);

static void
sch_arc_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
sch_arc_transform(SchShape *shape, const struct _GeomTransform *transform);

void
sch_arc_translate(SchShape *shape, int dx, int dy);



static gboolean
sch_arc_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds)
{
    SchArcPrivate *privat = SCH_ARC_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        int border = (privat->line_width + 1) / 2;

        geom_arc_bounds(&(privat->arc), bounds);
        geom_bounds_expand(bounds, bounds, border);
    }
    else
    {
        geom_bounds_init(bounds);
    }

    return TRUE;
}

static void
sch_arc_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(SchArcPrivate));

    object_class->get_property = sch_arc_get_property;
    object_class->set_property = sch_arc_set_property;

    g_object_class_install_property(
        object_class,
        SCH_ARC_CENTER_X,
        g_param_spec_int(
            "center-x",
            "Center X",
            "Center X",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_ARC_CENTER_Y,
        g_param_spec_int(
            "center-y",
            "Center X",
            "Center Y",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_ARC_RADIUS,
        g_param_spec_int(
            "radius",
            "Radius",
            "Radius",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_ARC_START,
        g_param_spec_int(
            "start",
            "Start",
            "Start",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_ARC_SWEEP,
        g_param_spec_int(
            "sweep",
            "Sweep",
            "Sweep",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );


    g_object_class_install_property(
        object_class,
        SCH_ARC_COLOR,
        g_param_spec_int(
            "color",
            "Color",
            "Color",
            0, /*COLOR_MIN,*/
            31, /*COLOR_MAX,*/
            3, /*COLOR_GRAPHIC,*/
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_ARC_WIDTH,
        g_param_spec_int(
            "line-width",
            "Line Width",
            "Line Width",
            0,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_ARC_CAP_STYLE,
        g_param_spec_int(
            "line-cap-style",
            "Line Cap Style",
            "Line Cap Style",
            0,
            2,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_ARC_DASH_STYLE,
        g_param_spec_int(
            "line-dash-style",
            "Line dash Style",
            "Line dash Style",
            0,
            4,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_ARC_DASH_LENGTH,
        g_param_spec_int(
            "line-dash-length",
            "Line Dash Length",
            "Line Dash Length",
            -1,
            G_MAXINT,
            -1,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_ARC_DASH_SPACE,
        g_param_spec_int(
            "line-dash-space",
            "Line Dash Space",
            "Line Dash Space",
            -1,
            G_MAXINT,
            -1,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
sch_arc_draw(SchShape *shape, SchDrafter *drafter)
{
    sch_drafter_draw_arc(drafter, SCH_ARC(shape));
}

static void
sch_arc_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchArcPrivate *privat = SCH_ARC_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_ARC_CENTER_X:
            g_value_set_int(value, privat->arc.center_x);
            break;

        case SCH_ARC_CENTER_Y:
            g_value_set_int(value, privat->arc.center_y);
            break;

        case SCH_ARC_RADIUS:
            g_value_set_int(value, privat->arc.radius);
            break;

        case SCH_ARC_START:
            g_value_set_int(value, privat->arc.start);
            break;

        case SCH_ARC_SWEEP:
            g_value_set_int(value, privat->arc.sweep);
            break;

        case SCH_ARC_COLOR:
            g_value_set_int(value, privat->color);
            break;

        case SCH_ARC_WIDTH:
            g_value_set_int(value, privat->line_width);
            break;

        case SCH_ARC_CAP_STYLE:
            g_value_set_int(value, privat->line_cap_style);
            break;

        case SCH_ARC_DASH_STYLE:
            g_value_set_int(value, privat->line_dash_style);
            break;

        case SCH_ARC_DASH_LENGTH:
            g_value_set_int(value, privat->line_dash_length);
            break;

        case SCH_ARC_DASH_SPACE:
            g_value_set_int(value, privat->line_dash_space);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
sch_arc_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchArcClass),    /* class_size */
            NULL,                             /* base_init */
            NULL,                             /* base_finalize */
            sch_arc_class_init,    /* class_init */
            NULL,                             /* class_finalize */
            NULL,                             /* class_data */
            sizeof(SchArc),         /* instance_size */
            0,                                /* n_preallocs */
            NULL,                             /* instance_init */
            NULL                              /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            sch_arc_schematic_shape_init,    /* interface_init */
            NULL,                                       /* interface_finalize */
            NULL                                        /* interface_data */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchArc",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, SCH_TYPE_SHAPE, &iinfo);
    }

    return type;
}

static void
sch_arc_schematic_shape_init(gpointer g_iface, gpointer g_iface_data)
{
    SchShapeInterface *iface = (SchShapeInterface*) g_iface;

    iface->bounds = sch_arc_bounds;
    iface->draw = sch_arc_draw;
    iface->transform = sch_arc_transform;
    iface->translate = sch_arc_translate;
}

static void
sch_arc_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchArcPrivate *privat = SCH_ARC_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_ARC_CENTER_X:
            privat->arc.center_x = g_value_get_int(value);
            break;

        case SCH_ARC_CENTER_Y:
            privat->arc.center_y = g_value_get_int(value);
            break;

        case SCH_ARC_RADIUS:
            privat->arc.radius = g_value_get_int(value);
            break;

        case SCH_ARC_START:
            privat->arc.start = g_value_get_int(value);
            break;

        case SCH_ARC_SWEEP:
            privat->arc.sweep = g_value_get_int(value);
            break;

        case SCH_ARC_COLOR:
            privat->color = g_value_get_int(value);
            break;

        case SCH_ARC_WIDTH:
            privat->line_width = g_value_get_int(value);
            break;

        case SCH_ARC_CAP_STYLE:
            privat->line_cap_style = g_value_get_int(value);
            break;

        case SCH_ARC_DASH_STYLE:
            privat->line_dash_style = g_value_get_int(value);
            break;

        case SCH_ARC_DASH_LENGTH:
            privat->line_dash_length = g_value_get_int(value);
            break;

        case SCH_ARC_DASH_SPACE:
            privat->line_dash_space = g_value_get_int(value);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
sch_arc_get_color(const SchArc *shape, int *index)
{
    SchArcPrivate *privat = SCH_ARC_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *index = privat->color;
    }
    else
    {
        *index = 0; /* FIXME use line default */
    }
}

void
sch_arc_get_arc(const SchArc *shape, GeomArc *arc)
{
    SchArcPrivate *privat = SCH_ARC_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *arc = privat->arc;
    }

    /* FIXME initialize line to some value in else */
}

void
sch_arc_get_line_width(const SchArc *shape, int *width)
{
    SchArcPrivate *privat = SCH_ARC_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *width = privat->line_width;
    }
    else
    {
        *width = 0; /* FIXME use line default */
    }
}

static void
sch_arc_transform(SchShape *shape, const struct _GeomTransform *transform)
{
    SchArcPrivate *privat = SCH_ARC_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        geom_transform_point(transform, &(privat->arc.center_x), &(privat->arc.center_y));
    }
}


void
sch_arc_translate(SchShape *shape, int dx, int dy)
{
    SchArcPrivate *privat = SCH_ARC_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        geom_arc_translate(&(privat->arc), dx, dy);
    }
}
