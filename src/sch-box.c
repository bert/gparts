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

#include "sch-fill-style.h"
#include "sch-line-style.h"

#define SCH_BOX_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_BOX,SchBoxPrivate))

enum
{
    SCH_BOX_X = 1,
    SCH_BOX_Y,
    SCH_BOX_WIDTH,
    SCH_BOX_HEIGHT,
    SCH_BOX_COLOR,
    SCH_BOX_LINE_WIDTH,
    SCH_BOX_CAP_STYLE,
    SCH_BOX_DASH_STYLE,
    SCH_BOX_DASH_LENGTH,
    SCH_BOX_DASH_SPACE,
    SCH_BOX_FILL_TYPE,
    SCH_BOX_FILL_WIDTH,
    SCH_BOX_FILL_ANGLE1,
    SCH_BOX_FILL_PITCH1,
    SCH_BOX_FILL_ANGLE2,
    SCH_BOX_FILL_PITCH2
};

typedef struct _SchBoxPrivate SchBoxPrivate;

struct _SchBoxPrivate
{
    GeomBox      box;
    gint         color;
    gint         line_width;
    SchLineStyle line_style;
    SchFillStyle fill_style;
};

static gboolean
sch_box_calculate_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds);

static void
sch_box_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_box_draw(SchShape *shape, SchDrafter *drafter);

static void
sch_box_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_box_schematic_shape_init(gpointer g_iface, gpointer g_iface_data);

static void
sch_box_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
sch_box_rotate(SchShape *shape, int rotate);

static void
sch_box_transform(SchShape *shape, const struct _GeomTransform *transform);

static void
sch_box_translate(SchShape *shape, int dx, int dy);



static gboolean
sch_box_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds)
{
    SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        int border = (privat->line_width + 1) / 2;

        geom_box_bounds(&(privat->box), bounds);
        geom_bounds_expand(bounds, bounds, border);
    }
    else
    {
        geom_bounds_init(bounds);
    }

    return TRUE;
}

static void
sch_box_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(SchBoxPrivate));

    object_class->get_property = sch_box_get_property;
    object_class->set_property = sch_box_set_property;

    g_object_class_install_property(
        object_class,
        SCH_BOX_X,
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
        SCH_BOX_Y,
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
        SCH_BOX_WIDTH,
        g_param_spec_int(
            "width",
            "Width",
            "Width",
            0,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_BOX_HEIGHT,
        g_param_spec_int(
            "height",
            "Height",
            "Height",
            0,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_BOX_COLOR,
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
        SCH_BOX_LINE_WIDTH,
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
        SCH_BOX_CAP_STYLE,
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
        SCH_BOX_DASH_STYLE,
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
        SCH_BOX_DASH_LENGTH,
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
        SCH_BOX_DASH_SPACE,
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

    g_object_class_install_property(
        object_class,
        SCH_BOX_FILL_TYPE,
        g_param_spec_int(
            "fill-type",
            "Fill Type",
            "Fill Type",
            -1,
            G_MAXINT,
            -1,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_BOX_FILL_WIDTH,
        g_param_spec_int(
            "fill-width",
            "Fill Width",
            "Fill Width",
            -1,
            G_MAXINT,
            -1,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_BOX_FILL_ANGLE1,
        g_param_spec_int(
            "fill-angle1",
            "Fill Angle 1",
            "Fill Angle 1",
            -1,
            G_MAXINT,
            -1,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_BOX_FILL_PITCH1,
        g_param_spec_int(
            "fill-pitch1",
            "Fill Pitch 1",
            "Fill Pitch 1",
            -1,
            G_MAXINT,
            -1,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_BOX_FILL_ANGLE2,
        g_param_spec_int(
            "fill-angle2",
            "Fill Angle 2",
            "Fill Angle 2",
            -1,
            G_MAXINT,
            -1,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_BOX_FILL_PITCH2,
        g_param_spec_int(
            "fill-pitch2",
            "Fill Pitch 2",
            "Fill Pitch 2",
            -1,
            G_MAXINT,
            -1,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
sch_box_draw(SchShape *shape, SchDrafter *drafter)
{
    sch_drafter_draw_box(drafter, SCH_BOX(shape));
}

static void
sch_box_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_BOX_X:
            g_value_set_int(value, privat->box.corner_x);
            break;

        case SCH_BOX_Y:
            g_value_set_int(value, privat->box.corner_y);
            break;

        case SCH_BOX_WIDTH:
            g_value_set_int(value, privat->box.width);
            break;

        case SCH_BOX_HEIGHT:
            g_value_set_int(value, privat->box.height);
            break;

        case SCH_BOX_COLOR:
            g_value_set_int(value, privat->color);
            break;

        case SCH_BOX_LINE_WIDTH:
            g_value_set_int(value, privat->line_width);
            break;

        case SCH_BOX_CAP_STYLE:
            g_value_set_int(value, privat->line_style.cap_style);
            break;

        case SCH_BOX_DASH_STYLE:
            g_value_set_int(value, privat->line_style.dash_style);
            break;

        case SCH_BOX_DASH_LENGTH:
            g_value_set_int(value, privat->line_style.dash_length);
            break;

        case SCH_BOX_DASH_SPACE:
            g_value_set_int(value, privat->line_style.dash_space);
            break;

        case SCH_BOX_FILL_TYPE:
            g_value_set_int(value, privat->fill_style.type);
            break;

        case SCH_BOX_FILL_WIDTH:
            g_value_set_int(value, privat->fill_style.width);
            break;

        case SCH_BOX_FILL_ANGLE1:
            g_value_set_int(value, privat->fill_style.angle1);
            break;

        case SCH_BOX_FILL_PITCH1:
            g_value_set_int(value, privat->fill_style.pitch1);
            break;

        case SCH_BOX_FILL_ANGLE2:
            g_value_set_int(value, privat->fill_style.angle2);
            break;

        case SCH_BOX_FILL_PITCH2:
            g_value_set_int(value, privat->fill_style.pitch2);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
sch_box_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchBoxClass),    /* class_size */
            NULL,                            /* base_init */
            NULL,                            /* base_finalize */
            sch_box_class_init,    /* class_init */
            NULL,                            /* class_finalize */
            NULL,                            /* class_data */
            sizeof(SchBox),         /* instance_size */
            0,                               /* n_preallocs */
            NULL,                            /* instance_init */
            NULL                             /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            sch_box_schematic_shape_init,    /* interface_init */
            NULL,                                      /* interface_finalize */
            NULL                                       /* interface_data */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchBox",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, SCH_TYPE_SHAPE, &iinfo);
    }

    return type;
}

static void
sch_box_schematic_shape_init(gpointer g_iface, gpointer g_iface_data)
{
    SchShapeInterface *iface = (SchShapeInterface*) g_iface;

    iface->bounds    = sch_box_bounds;
    iface->draw      = sch_box_draw;
    iface->rotate    = sch_box_rotate;
    iface->transform = sch_box_transform;
    iface->translate = sch_box_translate;
}

static void
sch_box_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_BOX_X:
            privat->box.corner_x = g_value_get_int(value);
            break;

        case SCH_BOX_Y:
            privat->box.corner_y = g_value_get_int(value);
            break;

        case SCH_BOX_WIDTH:
            privat->box.width = g_value_get_int(value);
            break;

        case SCH_BOX_HEIGHT:
            privat->box.height = g_value_get_int(value);
            break;

        case SCH_BOX_COLOR:
            privat->color = g_value_get_int(value);
            break;

        case SCH_BOX_LINE_WIDTH:
            privat->line_width = g_value_get_int(value);
            break;

        case SCH_BOX_CAP_STYLE:
            privat->line_style.cap_style = g_value_get_int(value);
            break;

        case SCH_BOX_DASH_STYLE:
            privat->line_style.dash_style = g_value_get_int(value);
            break;

        case SCH_BOX_DASH_LENGTH:
            privat->line_style.dash_length = g_value_get_int(value);
            break;

        case SCH_BOX_DASH_SPACE:
            privat->line_style.dash_space = g_value_get_int(value);
            break;

        case SCH_BOX_FILL_TYPE:
            privat->fill_style.type = g_value_get_int(value);
            break;

        case SCH_BOX_FILL_WIDTH:
            privat->fill_style.width = g_value_get_int(value);
            break;

        case SCH_BOX_FILL_ANGLE1:
            privat->fill_style.angle1 = g_value_get_int(value);
            break;

        case SCH_BOX_FILL_PITCH1:
            privat->fill_style.pitch1 = g_value_get_int(value);
            break;

        case SCH_BOX_FILL_ANGLE2:
            privat->fill_style.angle2 = g_value_get_int(value);
            break;

        case SCH_BOX_FILL_PITCH2:
            privat->fill_style.pitch2 = g_value_get_int(value);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
sch_box_get_color(const SchBox *shape, int *index)
{
    SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(shape);

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
sch_box_get_box(const SchBox *shape, GeomBox *box)
{
    SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *box = privat->box;
    }

    /* FIXME initialize line to some value in else */
}

void
sch_box_get_line_width(const SchBox *shape, int *width)
{
    SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *width = privat->line_width;
    }
    else
    {
        *width = 0; /* FIXME use line default */
    }
}

void
sch_box_get_fill_style(const SchBox *shape, struct _SchFillStyle *style)
{
    if (style != NULL)
    {
        SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(shape);

        if (privat != NULL)
        {
            *style = privat->fill_style;
        }
        else
        {
            sch_fill_style_init(style);
        }
    }
}

void
sch_box_get_line_style(const SchBox *shape, struct _SchLineStyle *style)
{
    if (style != NULL)
    {
        SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(shape);

        if (privat != NULL)
        {
            *style = privat->line_style;
        }
        else
        {
            sch_line_style_init(style);
        }
    }
}

static void
sch_box_translate(SchShape *shape, int dx, int dy)
{
    SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        geom_box_translate(&(privat->box), dx, dy);
    }
}

static void
sch_box_transform(SchShape *shape, const struct _GeomTransform *transform)
{
    SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        geom_transform_point(transform, &(privat->box.corner_x), &(privat->box.corner_y));
    }
}

static void
sch_box_rotate(SchShape *shape, int angle)
{
    SchBoxPrivate *privat = SCH_BOX_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        angle = geom_angle_normalize(angle);

        if (angle == 90)
        {
            GeomBox temp = privat->box;

            privat->box.corner_x = temp.corner_x - temp.height;
            privat->box.corner_y = temp.corner_y; 
            privat->box.width    = temp.height;
            privat->box.height   = temp.width;
        }
        else if (angle == 270)
        {
            GeomBox temp = privat->box;

            privat->box.corner_x =  temp.corner_y;
            privat->box.corner_y = -temp.corner_x - temp.width; 
            privat->box.width    =  temp.height;
            privat->box.height   =  temp.width;
        }
   
    }
}

