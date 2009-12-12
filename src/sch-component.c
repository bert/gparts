/*! \file xxx-schematic-line.c
 *
 *  \brief A wrapper for gschem's line.
 */

#include <glib.h>
#include <glib-object.h>

#include "geom.h"

#include "sch-multiline.h"
#include "sch-shape.h"
#include "sch-box.h"
#include "sch-text.h"
#include "sch-drafter.h"
#include "sch-drawing.h"

#include "sch-fill-style.h"
#include "sch-line-style.h"

#include "sch-component.h"

#define SCH_COMPONENT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_COMPONENT,SchComponentPrivate))

enum
{
    SCH_COMPONENT_X = 1,
    SCH_COMPONENT_Y,
    SCH_COMPONENT_SELECTABLE,
    SCH_COMPONENT_ANGLE,
    SCH_COMPONENT_MIRROR,
    SCH_COMPONENT_BASENAME,
    SCH_COMPONENT_DRAWING
};

typedef struct _SchComponentPrivate SchComponentPrivate;

struct _SchComponentPrivate
{
    int        x;
    int        y;
    int        selectable;
    int        angle;
    int        mirror;
    char       *basename;
    SchDrawing *drawing;
};


static gboolean
sch_component_calculate_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds);

static void
sch_component_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_component_draw(SchShape *shape, SchDrafter *drafter);

static void
sch_component_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_component_schematic_shape_init(gpointer g_iface, gpointer g_iface_data);

static void
sch_component_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);




static gboolean
sch_component_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds)
{
    sch_drafter_component_bounds(drafter, SCH_COMPONENT(shape), bounds);
}

static void
sch_component_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(SchComponentPrivate));

    object_class->get_property = sch_component_get_property;
    object_class->set_property = sch_component_set_property;

    g_object_class_install_property(
        object_class,
        SCH_COMPONENT_X,
        g_param_spec_int(
            "x",
            "X",
            "X",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_COMPONENT_Y,
        g_param_spec_int(
            "y",
            "Y",
            "",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_COMPONENT_SELECTABLE,
        g_param_spec_int(
            "selectable",
            "Selectable",
            "",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_COMPONENT_ANGLE,
        g_param_spec_int(
            "angle",
            "Angle",
            "",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_COMPONENT_MIRROR,
        g_param_spec_int(
            "mirror",
            "Mirror",
            "",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_COMPONENT_BASENAME,
        g_param_spec_string(
            "basename",
            "Basename",
            "",
            NULL,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_COMPONENT_DRAWING,
        g_param_spec_object(
            "drawing",
            "Drawing",
            "",
            SCH_TYPE_DRAWING,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
sch_component_draw(SchShape *shape, SchDrafter *drafter)
{
    sch_drafter_draw_component(drafter, SCH_COMPONENT(shape));
}

static void
sch_component_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchComponentPrivate *privat = SCH_COMPONENT_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_COMPONENT_X:
            g_value_set_int(value, privat->x);
            break;

        case SCH_COMPONENT_Y:
            g_value_set_int(value, privat->y);
            break;

        case SCH_COMPONENT_SELECTABLE:
            g_value_set_int(value, privat->selectable);
            break;

        case SCH_COMPONENT_ANGLE:
            g_value_set_int(value, privat->angle);
            break;

        case SCH_COMPONENT_MIRROR:
            g_value_set_int(value, privat->mirror);
            break;

        case SCH_COMPONENT_BASENAME:
            g_value_set_string(value, privat->basename);
            break;

        case SCH_COMPONENT_DRAWING:
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
sch_component_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchComponentClass),    /* class_size */
            NULL,                            /* base_init */
            NULL,                            /* base_finalize */
            sch_component_class_init,    /* class_init */
            NULL,                            /* class_finalize */
            NULL,                            /* class_data */
            sizeof(SchComponent),         /* instance_size */
            0,                               /* n_preallocs */
            NULL,                            /* instance_init */
            NULL                             /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            sch_component_schematic_shape_init,    /* interface_init */
            NULL,                                      /* interface_finalize */
            NULL                                       /* interface_data */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchComponent",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, SCH_TYPE_SHAPE, &iinfo);
    }

    return type;
}

static void
sch_component_schematic_shape_init(gpointer g_iface, gpointer g_iface_data)
{
    SchShapeInterface *iface = (SchShapeInterface*) g_iface;

    iface->bounds = sch_component_bounds;
    iface->draw = sch_component_draw;
}

static void
sch_component_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchComponentPrivate *privat = SCH_COMPONENT_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_COMPONENT_X:
            privat->x = g_value_get_int(value);
            break;

        case SCH_COMPONENT_Y:
            privat->y = g_value_get_int(value);
            break;

        case SCH_COMPONENT_SELECTABLE:
            privat->selectable = g_value_get_int(value);
            break;

        case SCH_COMPONENT_ANGLE:
            privat->angle = g_value_get_int(value);
            break;

        case SCH_COMPONENT_MIRROR:
            privat->mirror = g_value_get_int(value);
            break;

        case SCH_COMPONENT_BASENAME:
            g_free(privat->basename);
            privat->basename = g_value_dup_string(value);
            break;

        case SCH_COMPONENT_DRAWING:
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
sch_component_get_drawing(const SchComponent *shape, SchDrawing **drawing)
{
    if (drawing != NULL)
    {
        SchComponentPrivate *privat = SCH_COMPONENT_GET_PRIVATE(shape);

        if (privat != NULL)
        {
            *drawing = privat->drawing;
        }
        else
        {
            *drawing = NULL;
        }
    }
}

void
sch_component_set_drawing(SchComponent *shape, SchDrawing *drawing)
{
    SchComponentPrivate *privat = SCH_COMPONENT_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        if (privat->drawing != NULL)
        {
            g_object_unref(privat->drawing);
        }

        privat->drawing = drawing;

        if (privat->drawing != NULL)
        {
            g_object_ref(privat->drawing);
        }
    }
}
void
sch_component_get_insertion_point(const SchComponent *shape, int *x, int *y)
{
    SchComponentPrivate *privat = SCH_COMPONENT_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        if (x != NULL)
        {
            *x = privat->x;
        } 

        if (y != NULL)
        {
            *y = privat->y;
        } 
    }
    else
    {
        if (x != NULL)
        {
            *x = 0;
        } 

        if (y != NULL)
        {
            *y = 0;
        } 
    }
}

void
sch_component_get_orientation(const SchComponent *shape, int *angle, int *mirror)
{
    SchComponentPrivate *privat = SCH_COMPONENT_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *angle  = privat->angle;
        *mirror = privat->mirror;
    }
    else
    {
        *angle = 0;
        *mirror = 0;
    }
}
 
