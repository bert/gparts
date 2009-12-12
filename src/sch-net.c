/*! \file xxx-schematic-net.c
 *
 *  \brief A wrapper for gschem's net.
 */

#include <glib.h>
#include <glib-object.h>

#include "geom.h"

#include "sch-multiline.h"
#include "sch-shape.h"
#include "sch-net.h"
#include "sch-text.h"
#include "sch-drafter.h"

#define SCH_NET_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_NET,SchNetPrivate))

enum
{
    SCH_NET_X1 = 1,
    SCH_NET_Y1,
    SCH_NET_X2,
    SCH_NET_Y2,
    SCH_NET_COLOR,
    SCH_NET_NET_TYPE,
    SCH_NET_NET_END
};

typedef struct _SchNetPrivate SchNetPrivate;

struct _SchNetPrivate
{
    GeomLine line;
    gint     color;
    gint     net_type;
    gint     net_end;
};

static gboolean
sch_net_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds);

static void
sch_net_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_net_draw(SchShape *shape, SchDrafter *drafter);

static void
sch_net_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_net_schematic_shape_init(gpointer g_iface, gpointer g_iface_data);

static void
sch_net_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static gboolean
sch_net_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds)
{
    SchNetPrivate *privat = SCH_NET_GET_PRIVATE(shape);
    gboolean success = FALSE;

    if (privat != NULL)
    {
        GeomBounds line_bounds;

        geom_bounds_init(&line_bounds);
        geom_line_bounds(&(privat->line), &line_bounds);
        geom_bounds_expand(&line_bounds, &line_bounds, 10);
        geom_bounds_union(bounds, bounds, &line_bounds);

        success = TRUE;
    }

    return success;
}

static void
sch_net_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(SchNetPrivate));

    object_class->get_property = sch_net_get_property;
    object_class->set_property = sch_net_set_property;

    g_object_class_install_property(
        object_class,
        SCH_NET_X1,
        g_param_spec_int(
            "x1",
            "X1",
            "X1",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_NET_Y1,
        g_param_spec_int(
            "y1",
            "Y1",
            "Y1",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_NET_X2,
        g_param_spec_int(
            "x2",
            "X2",
            "X2",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_NET_Y2,
        g_param_spec_int(
            "y2",
            "Y2",
            "Y2",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_NET_COLOR,
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
        SCH_NET_NET_TYPE,
        g_param_spec_int(
            "net-type",
            "Net Type",
            "Net Type",
            0,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_NET_NET_END,
        g_param_spec_int(
            "net-end",
            "Net End",
            "Net End",
            0,
            2,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
sch_net_draw(SchShape *shape, SchDrafter *drafter)
{
    sch_drafter_draw_net(drafter, SCH_NET(shape));
}

static void
sch_net_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchNetPrivate *privat = SCH_NET_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_NET_X1:
            g_value_set_int(value, privat->line.x[0]);
            break;

        case SCH_NET_Y1:
            g_value_set_int(value, privat->line.y[0]);
            break;

        case SCH_NET_X2:
            g_value_set_int(value, privat->line.x[1]);
            break;

        case SCH_NET_Y2:
            g_value_set_int(value, privat->line.y[1]);
            break;

        case SCH_NET_COLOR:
            g_value_set_int(value, privat->color);
            break;

        case SCH_NET_NET_TYPE:
            g_value_set_int(value, privat->net_type);
            break;

        case SCH_NET_NET_END:
            g_value_set_int(value, privat->net_end);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
sch_net_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchNetClass),    /* class_size */
            NULL,                             /* base_init */
            NULL,                             /* base_finalize */
            sch_net_class_init,    /* class_init */
            NULL,                             /* class_finalize */
            NULL,                             /* class_data */
            sizeof(SchNet),         /* instance_size */
            0,                                /* n_preallocs */
            NULL,                             /* instance_init */
            NULL                              /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            sch_net_schematic_shape_init,    /* interface_init */
            NULL,                                       /* interface_finalize */
            NULL                                        /* interface_data */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchNet",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, SCH_TYPE_SHAPE, &iinfo);
    }

    return type;
}

static void
sch_net_schematic_shape_init(gpointer g_iface, gpointer g_iface_data)
{
    SchShapeInterface *iface = (SchShapeInterface*) g_iface;

    iface->bounds = sch_net_bounds;
    iface->draw = sch_net_draw;
}

static void
sch_net_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchNetPrivate *privat = SCH_NET_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_NET_X1:
            privat->line.x[0] = g_value_get_int(value);
            break;

        case SCH_NET_Y1:
            privat->line.y[0] = g_value_get_int(value);
            break;

        case SCH_NET_X2:
            privat->line.x[1] = g_value_get_int(value);
            break;

        case SCH_NET_Y2:
            privat->line.y[1] = g_value_get_int(value);
            break;

        case SCH_NET_COLOR:
            privat->color = g_value_get_int(value);
            break;

        case SCH_NET_NET_TYPE:
            privat->net_type = g_value_get_int(value);
            break;

        case SCH_NET_NET_END:
            privat->net_end = g_value_get_int(value);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
sch_net_get_color(const SchNet *shape, int *index)
{
    SchNetPrivate *privat = SCH_NET_GET_PRIVATE(shape);

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
sch_net_get_line(const SchNet *shape, GeomLine *line)
{
    SchNetPrivate *privat = SCH_NET_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *line = privat->line;
    }

    /* FIXME initialize line to some value in else */
}


