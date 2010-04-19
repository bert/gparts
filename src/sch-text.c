/*! \file xxx-schematic-line.c
 *
 *  \brief A wrapper for gschem's line.
 */

#include <glib.h>
#include <glib-object.h>

#include "sch.h"


#define SCH_TEXT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_TEXT,SchTextPrivate))


enum
{
    SCH_TEXT_X = 1,
    SCH_TEXT_Y,
    SCH_TEXT_COLOR,
    SCH_TEXT_SIZE,
    SCH_TEXT_VISIBILITY,
    SCH_TEXT_SHOW_NAME_VALUE,
    SCH_TEXT_ANGLE,
    SCH_TEXT_ALIGNMENT,
    SCH_TEXT_NUM_LINES
};

typedef struct _SchTextPrivate SchTextPrivate;

struct _SchTextPrivate
{
    gint x;
    gint y;
    gint color;
    gint size;
    gint visibility;
    gint show_name_value;
    gint angle;
    gint alignment;

    SchMultiline *multiline;
};

static gboolean
sch_text_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds);

static void
sch_text_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_text_draw(SchShape *shape, SchDrafter *drafter);

static void
sch_text_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_text_schematic_shape_init(gpointer g_iface, gpointer g_iface_data);

static void
sch_text_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

void
sch_text_rotate(SchShape *shape, int angle);

static void
sch_text_transform(SchShape *shape, const struct _GeomTransform *transform);

void
sch_text_translate(SchShape *shape, int dx, int dy);

static void
sch_text_write(SchShape *shape, SchFileFormat2 *format, SchOutputStream *stream, GError **error);

static gboolean
sch_text_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds)
{
    sch_drafter_text_bounds(drafter, SCH_TEXT(shape), bounds);

    return FALSE;
}

static void
sch_text_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);
    SchTextClass *klasse = SCH_TEXT_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(SchTextPrivate));

    object_class->get_property = sch_text_get_property;
    object_class->set_property = sch_text_set_property;

    klasse->parent.bounds    = sch_text_bounds;
    klasse->parent.draw      = sch_text_draw;
    klasse->parent.rotate    = sch_text_rotate;
    klasse->parent.transform = sch_text_transform;
    klasse->parent.translate = sch_text_translate;
    klasse->parent.write     = sch_text_write;

    g_object_class_install_property(
        object_class,
        SCH_TEXT_X,
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
        SCH_TEXT_Y,
        g_param_spec_int(
            "y",
            "Y",
            "Y",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_TEXT_COLOR,
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
        SCH_TEXT_SIZE,
        g_param_spec_int(
            "size",
            "Size",
            "Size",
            0,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_TEXT_VISIBILITY,
        g_param_spec_int(
            "visibility",
            "Visibility",
            "Visibility",
            0,
            1,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_TEXT_SHOW_NAME_VALUE,
        g_param_spec_int(
            "show-name-value",
            "Show Name Value",
            "Show Name Value",
            0,
            2,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_TEXT_ANGLE,
        g_param_spec_int(
            "angle",
            "Angle",
            "Angle",
            G_MININT,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_TEXT_ALIGNMENT,
        g_param_spec_int(
            "alignment",
            "Alignment",
            "Alignment",
            0,
            8,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        object_class,
        SCH_TEXT_NUM_LINES,
        g_param_spec_int(
            "num-lines",
            "Num Lines",
            "Num Lines",
            0,
            G_MAXINT,
            0,
            G_PARAM_LAX_VALIDATION | G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
sch_text_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_TEXT_X:
            g_value_set_int(value, privat->x);
            break;

        case SCH_TEXT_Y:
            g_value_set_int(value, privat->y);
            break;

        case SCH_TEXT_COLOR:
            g_value_set_int(value, privat->color);
            break;

        case SCH_TEXT_SIZE:
            g_value_set_int(value, privat->size);
            break;

        case SCH_TEXT_VISIBILITY:
            g_value_set_int(value, privat->visibility);
            break;

        case SCH_TEXT_SHOW_NAME_VALUE:
            g_value_set_int(value, privat->show_name_value);
            break;

        case SCH_TEXT_ANGLE:
            g_value_set_int(value, privat->angle);
            break;

        case SCH_TEXT_ALIGNMENT:
            g_value_set_int(value, privat->alignment);
            break;

        case SCH_TEXT_NUM_LINES:
            g_value_set_int(value, sch_multiline_lines(privat->multiline));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
sch_text_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchTextClass),    /* class_size */
            NULL,                    /* base_init */
            NULL,                    /* base_finalize */
            sch_text_class_init,     /* class_init */
            NULL,                    /* class_finalize */
            NULL,                    /* class_data */
            sizeof(SchText),         /* instance_size */
            0,                       /* n_preallocs */
            NULL,                    /* instance_init */
            NULL                     /* value_table */
            };

        type = g_type_register_static(
            SCH_TYPE_SHAPE,
            "SchText",
            &tinfo,
            0
            );
    }

    return type;
}

int
sch_text_get_x(SchText *text)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(text);
    int x;

    if (privat != NULL)
    {
        x = privat->x;
    }

    return x;
}

int
sch_text_get_y(SchText *text)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(text);
    int y;

    if (privat != NULL)
    {
        y = privat->y;
    }

    return y;
}

static void
sch_text_draw(SchShape *shape, SchDrafter *drafter)
{
//    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(shape);

    sch_drafter_draw_text(drafter, SCH_TEXT(shape));
}

static void
sch_text_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(object);

    switch (property_id)
    {
        case SCH_TEXT_X:
            privat->x = g_value_get_int(value);
            break;

        case SCH_TEXT_Y:
            privat->y = g_value_get_int(value);
            break;

        case SCH_TEXT_COLOR:
            privat->color = g_value_get_int(value);
            break;

        case SCH_TEXT_SIZE:
            privat->size = g_value_get_int(value);
            break;

        case SCH_TEXT_VISIBILITY:
            privat->visibility = g_value_get_int(value);
            break;

        case SCH_TEXT_SHOW_NAME_VALUE:
            privat->show_name_value = g_value_get_int(value);
            break;

        case SCH_TEXT_ANGLE:
            privat->angle = g_value_get_int(value);
            break;

        case SCH_TEXT_ALIGNMENT:
            privat->alignment = g_value_get_int(value);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

SchMultiline*
sch_text_get_multiline(SchText *text)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(text);
    SchMultiline *multiline = NULL;

    if (privat != NULL)
    {
        multiline = privat->multiline;
    }

    return multiline;
}

void
sch_text_set_multiline(SchText *text, SchMultiline *multiline)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(text);

    if (privat != NULL)
    {
        if (privat->multiline != NULL)
        {
            g_object_unref(privat->multiline);
        }

        privat->multiline = multiline;

        if (privat->multiline != NULL)
        {
            g_object_ref(privat->multiline);
        }
    }
}

int
sch_text_get_size(SchText *text)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(text);

    if (privat != NULL)
    {
        return privat->size;
    }

    return 0;
}

int
sch_text_get_angle(SchText *text)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(text);

    if (privat != NULL)
    {
        return privat->angle;
    }

    return 0;
}

int
sch_text_get_alignment(SchText *text)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(text);

    if (privat != NULL)
    {
        return privat->alignment;
    }

    return 0;
}

void
sch_text_get_color(const SchText *shape, int *index)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(shape);

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
sch_text_get_show(const SchText *shape, int *show)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *show = privat->show_name_value;
    }
    else
    {
        *show = 0; /* FIXME use line default */
    }
}

void
sch_text_get_visible(const SchText *shape, int *visible)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        *visible = privat->visibility;
    }
    else
    {
        *visible = 1; /* FIXME use line default */
    }
}

void
sch_text_rotate(SchShape *shape, int angle)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(shape);

    if (privat != NULL)
    { 
        double   radians = geom_angle_radians(angle);
        int tx = privat->x;
        int ty = privat->y;

        privat->x = round(tx * cos(radians) - ty * sin(radians));
        privat->y = round(tx * sin(radians) + ty * cos(radians));

        privat->angle += angle;
    }
}

static void
sch_text_transform(SchShape *shape, const struct _GeomTransform *transform)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        geom_transform_point(transform, &(privat->x), &(privat->y));
    }
}

void
sch_text_translate(SchShape *shape, int dx, int dy)
{
    SchTextPrivate *privat = SCH_TEXT_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        privat->x += dx;
        privat->y += dy;
    }
}

static void
sch_text_write(SchShape *shape, SchFileFormat2 *format, SchOutputStream *stream, GError **error)
{
    sch_file_format_2_write_text(format, stream, SCH_TEXT(shape), error);
}

