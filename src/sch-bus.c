/*! \file xxx-schematic-bus.c
 *
 *  \brief A wrapper for gschem's bus.
 */

#include <glib.h>
#include <glib-object.h>

#include "sch.h"


#define SCH_BUS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_BUS,SchBusPrivate))

enum
{
    SCH_BUS_X1 = 1,
    SCH_BUS_Y1,
    SCH_BUS_X2,
    SCH_BUS_Y2,
    SCH_BUS_COLOR,
    SCH_BUS_BUS_TYPE,
    SCH_BUS_BUS_END
};

typedef struct _SchBusPrivate SchBusPrivate;

struct _SchBusPrivate
{
    GeomLine line;
    gint     color;
    gint     bus_type;
    gint     bus_end;
};

static gboolean
sch_bus_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds);

static void
sch_bus_draw(SchShape *shape, SchDrafter *drafter);

static void
sch_bus_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_bus_schematic_shape_init(gpointer g_iface, gpointer g_iface_data);

static void
sch_bus_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static gboolean
sch_bus_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds)
{
    SchBusPrivate *privat = SCH_BUS_GET_PRIVATE(shape);
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
sch_bus_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);
    SchBusClass *klasse = SCH_BUS_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(SchBusPrivate));

    object_class->get_property = sch_bus_get_property;
    object_class->set_property = sch_bus_set_property;

    klasse->parent.bounds = sch_bus_bounds;
    klasse->parent.draw   = sch_bus_draw;

    g_object_class_install_property(
        object_class,
        SCH_BUS_X1,
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
        SCH_BUS_Y1,
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
        SCH_BUS_X2,
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
        SCH_BUS_Y2,
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
        SCH_BUS_COLOR,
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
        SCH_BUS_BUS_TYPE,
        g_param_spec_int(
            "bus-type",
            "Bus Type",
            "Bus Type",
            0,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_BUS_BUS_END,
        g_param_spec_int(
            "bus-end",
            "Bus End",
            "Bus End",
            0,
            2,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
sch_bus_draw(SchShape *shape, SchDrafter *drafter)
{
    sch_drafter_draw_bus(drafter, SCH_BUS(shape));
}

static void
sch_bus_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchBusPrivate *privat = SCH_BUS_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_BUS_X1:
            g_value_set_int(value, privat->line.x[0]);
            break;

        case SCH_BUS_Y1:
            g_value_set_int(value, privat->line.y[0]);
            break;

        case SCH_BUS_X2:
            g_value_set_int(value, privat->line.x[1]);
            break;

        case SCH_BUS_Y2:
            g_value_set_int(value, privat->line.y[1]);
            break;

        case SCH_BUS_COLOR:
            g_value_set_int(value, privat->color);
            break;

        case SCH_BUS_BUS_TYPE:
            g_value_set_int(value, privat->bus_type);
            break;

        case SCH_BUS_BUS_END:
            g_value_set_int(value, privat->bus_end);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
sch_bus_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchBusClass),    /* class_size */
            NULL,                   /* base_init */
            NULL,                   /* base_finalize */
            sch_bus_class_init,     /* class_init */
            NULL,                   /* class_finalize */
            NULL,                   /* class_data */
            sizeof(SchBus),         /* instance_size */
            0,                      /* n_preallocs */
            NULL,                   /* instance_init */
            NULL                    /* value_table */
            };

        type = g_type_register_static(
            SCH_TYPE_SHAPE,
            "SchBus",
            &tinfo,
            0
            );
    }

    return type;
}

static void
sch_bus_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchBusPrivate *privat = SCH_BUS_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_BUS_X1:
            privat->line.x[0] = g_value_get_int(value);
            break;

        case SCH_BUS_Y1:
            privat->line.y[0] = g_value_get_int(value);
            break;

        case SCH_BUS_X2:
            privat->line.x[1] = g_value_get_int(value);
            break;

        case SCH_BUS_Y2:
            privat->line.y[1] = g_value_get_int(value);
            break;

        case SCH_BUS_COLOR:
            privat->color = g_value_get_int(value);
            break;

        case SCH_BUS_BUS_TYPE:
            privat->bus_type = g_value_get_int(value);
            break;

        case SCH_BUS_BUS_END:
            privat->bus_end = g_value_get_int(value);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
sch_bus_get_color(const SchBus *shape, int *index)
{
    SchBusPrivate *privat = SCH_BUS_GET_PRIVATE(shape);

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
sch_bus_get_line(const SchBus *shape, GeomLine *line)
{
    SchBusPrivate *privat = SCH_BUS_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *line = privat->line;
    }

    /* FIXME initialize line to some value in else */
}

static void
sch_bus_write(SchShape *shape, SchFileFormat2 *format, SchOutputStream *stream, GError **error)
{
    sch_file_format_2_write_bus(format, stream, SCH_BUS(shape), error);
}

