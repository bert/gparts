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

/*! \file sch-path.c
 */

#include <glib.h>
#include <glib-object.h>

#include "misc-object.h"

#include "sch.h"

#define SCH_PATH_DEFAULT_COLOR      (SCH_CONFIG_DEFAULT_GRAPHIC_COLOR)
#define SCH_PATH_DEFAULT_LINE_WIDTH (SCH_CONFIG_DEFAULT_LINE_WIDTH)

#define SCH_PATH_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_PATH,SchPathPrivate))

enum
{
    SCH_PATH_COLOR = 1,
    SCH_PATH_WIDTH,
    SCH_PATH_CAP_STYLE,
    SCH_PATH_DASH_STYLE,
    SCH_PATH_DASH_LENGTH,
    SCH_PATH_DASH_SPACE,
    SCH_PATH_FILL_TYPE,
    SCH_PATH_FILL_WIDTH,
    SCH_PATH_FILL_ANGLE1,
    SCH_PATH_FILL_PITCH1,
    SCH_PATH_FILL_ANGLE2,
    SCH_PATH_FILL_PITCH2
};

typedef struct _SchPathPrivate SchPathPrivate;

struct _SchPathPrivate
{
    GSList       *commands;
    gint         color;
    gint         line_width;
    SchLineStyle line_style;
    SchFillStyle fill_style;
};



static void
sch_path_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_path_finalize(GObject *object);

static void
sch_path_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_path_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
sch_path_rotate(SchShape *shape, int angle);

static void
sch_path_transform(SchShape *shape, const GeomTransform *transform);

static void
sch_path_translate(SchShape *shape, int dx, int dy);

static void
sch_path_write(SchShape *shape, SchFileFormat2 *format, SchOutputStream *stream, GError **error);



void
sch_path_append(SchPath *path, const SchPathCommand *command)
{
    SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(path);

    if (privat != NULL)
    {
        SchPathCommand *copy = sch_path_command_copy(command);

        if (copy != NULL)
        {
            privat->commands = g_slist_append(privat->commands, copy);
        }
    }
}

static void
sch_path_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse  = G_OBJECT_CLASS(g_class);
    SchPathClass *klasse1 = SCH_PATH_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(SchPathPrivate));

    klasse->finalize = sch_path_finalize;

    klasse->get_property = sch_path_get_property;
    klasse->set_property = sch_path_set_property;

    klasse1->parent.rotate    = sch_path_rotate;
    klasse1->parent.transform = sch_path_transform;
    klasse1->parent.translate = sch_path_translate;
    klasse1->parent.write     = sch_path_write;

    g_object_class_install_property(
        klasse,
        SCH_PATH_COLOR,
        g_param_spec_int(
            "color",
            "Color",
            "Color",
            0,
            G_MAXINT,
            SCH_PATH_DEFAULT_COLOR,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_PATH_WIDTH,
        g_param_spec_int(
            "line-width",
            "Line Width",
            "Line Width",
            0,
            G_MAXINT,
            SCH_PATH_DEFAULT_LINE_WIDTH,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_PATH_CAP_STYLE,
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
        klasse,
        SCH_PATH_DASH_STYLE,
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
        klasse,
        SCH_PATH_DASH_LENGTH,
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
        klasse,
        SCH_PATH_DASH_SPACE,
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
        klasse,
        SCH_PATH_FILL_TYPE,
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
        klasse,
        SCH_PATH_FILL_WIDTH,
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
        klasse,
        SCH_PATH_FILL_ANGLE1,
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
        klasse,
        SCH_PATH_FILL_PITCH1,
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
        klasse,
        SCH_PATH_FILL_ANGLE2,
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
        klasse,
        SCH_PATH_FILL_PITCH2,
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

int
sch_path_count(const SchPath *path)
{
    int count;
    SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(path);

    if (privat != NULL)
    {
        count = g_slist_length(privat->commands);
    }

    return count;
}

static void
sch_path_finalize(GObject *object)
{
    SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(object);

    if (privat != NULL)
    {
        GSList *node = privat->commands;

        while (node != NULL)
        {
            sch_path_command_free(SCH_PATH_COMMAND(node->data));

            node = g_slist_next(node);
        }

        g_slist_free(privat->commands);

        privat->commands = NULL;
    }

    misc_object_chain_finalize(object);
}

void
sch_path_foreach(SchPath *path, GFunc func, gpointer user_data)
{
    if (func != NULL)
    {
        SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(path);

        if (privat != NULL)
        {
            GSList *node = privat->commands;

            while (node != NULL)
            {
                func(node->data, user_data);

                node = g_slist_next(node);
            }
        }
    }

}

void
sch_path_get_fill_style(const SchPath *path, SchFillStyle *style)
{
    if (style != NULL)
    {
        SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(path);

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

static void
sch_path_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCH_PATH_COLOR:
                g_value_set_int(value, privat->color);
                break;

            case SCH_PATH_WIDTH:
                g_value_set_int(value, privat->line_width);
                break;

            case SCH_PATH_CAP_STYLE:
                g_value_set_int(value, privat->line_style.cap_style);
                break;

            case SCH_PATH_DASH_STYLE:
                g_value_set_int(value, privat->line_style.dash_style);
                break;

            case SCH_PATH_DASH_LENGTH:
                g_value_set_int(value, privat->line_style.dash_length);
                break;

            case SCH_PATH_DASH_SPACE:
                g_value_set_int(value, privat->line_style.dash_space);
                break;

            case SCH_PATH_FILL_TYPE:
                g_value_set_int(value, privat->fill_style.type);
                break;

            case SCH_PATH_FILL_WIDTH:
                g_value_set_int(value, privat->fill_style.width);
                break;

            case SCH_PATH_FILL_ANGLE1:
                g_value_set_int(value, privat->fill_style.angle1);
                break;

            case SCH_PATH_FILL_PITCH1:
                g_value_set_int(value, privat->fill_style.pitch1);
                break;

            case SCH_PATH_FILL_ANGLE2:
                g_value_set_int(value, privat->fill_style.angle2);
                break;

            case SCH_PATH_FILL_PITCH2:
                g_value_set_int(value, privat->fill_style.pitch2);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
sch_path_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchPathClass),    /* class_size */
            NULL,                    /* base_init */
            NULL,                    /* base_finalize */
            sch_path_class_init,     /* class_init */
            NULL,                    /* class_finalize */
            NULL,                    /* class_data */
            sizeof(SchPath),         /* instance_size */
            0,                       /* n_preallocs */
            NULL,                    /* instance_init */
            NULL                     /* value_table */
            };

        type = g_type_register_static(
            SCH_TYPE_SHAPE,
            "SchPath",
            &tinfo,
            0
            );
    }

    return type;
}

static void
sch_path_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCH_PATH_COLOR:
                privat->color = g_value_get_int(value);
                break;

            case SCH_PATH_WIDTH:
                privat->line_width = g_value_get_int(value);
                break;

            case SCH_PATH_CAP_STYLE:
                privat->line_style.cap_style = g_value_get_int(value);
                break;

            case SCH_PATH_DASH_STYLE:
                privat->line_style.dash_style = g_value_get_int(value);
                break;

            case SCH_PATH_DASH_LENGTH:
                privat->line_style.dash_length = g_value_get_int(value);
                break;

            case SCH_PATH_DASH_SPACE:
                privat->line_style.dash_space = g_value_get_int(value);
                break;

            case SCH_PATH_FILL_TYPE:
                privat->fill_style.type = g_value_get_int(value);
                break;

            case SCH_PATH_FILL_WIDTH:
                privat->fill_style.width = g_value_get_int(value);
                break;

            case SCH_PATH_FILL_ANGLE1:
                privat->fill_style.angle1 = g_value_get_int(value);
                break;

            case SCH_PATH_FILL_PITCH1:
                privat->fill_style.pitch1 = g_value_get_int(value);
                break;

            case SCH_PATH_FILL_ANGLE2:
                privat->fill_style.angle2 = g_value_get_int(value);
                break;

            case SCH_PATH_FILL_PITCH2:
                privat->fill_style.pitch2 = g_value_get_int(value);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

int
sch_path_get_color(const SchPath *path)
{
    int color = SCH_PATH_DEFAULT_COLOR;
    SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(path);

    if (privat != NULL)
    {
        color = privat->color;
    }

    return color;
}

void
sch_path_get_line_style(const SchPath *shape, SchLineStyle *style)
{
    if (style != NULL)
    {
        SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(shape);

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

int
sch_path_get_line_width(const SchPath *path)
{
    int line_width = SCH_PATH_DEFAULT_LINE_WIDTH;
    SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(path);

    if (privat != NULL)
    {
        line_width = privat->line_width;
    }

    return line_width;
}

SchPath*
sch_path_new(const SchConfig *config)
{
    return SCH_PATH(g_object_new(
        SCH_TYPE_PATH,
        "color",      sch_config_get_graphic_color(config),
        "line-width", sch_config_get_line_width(config),
        NULL
        ));
}

/*! \todo May be faster to create a transform than have each command call
 *  sin() and cos().
 */
static void
sch_path_rotate(SchShape *shape, int angle)
{
    SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        GSList *node = privat->commands;

        while (node != NULL)
        {
            sch_path_command_rotate(SCH_PATH_COMMAND(node->data), angle);

            node = g_slist_next(node);
        }
    }
}


static void
sch_path_transform(SchShape *shape, const GeomTransform *transform)
{
    if (transform != NULL)
    {
        SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(shape);

        if (privat != NULL)
        {
            GSList *node = privat->commands;

            while (node != NULL)
            {
                sch_path_command_transform(SCH_PATH_COMMAND(node->data), transform);

                node = g_slist_next(node);
            }
        }
    }
}



static void
sch_path_translate(SchShape *shape, int dx, int dy)
{
    SchPathPrivate *privat = SCH_PATH_GET_PRIVATE(shape);

    if (privat != NULL)
    {
        GSList *node = privat->commands;

        while (node != NULL)
        {
            sch_path_command_translate(SCH_PATH_COMMAND(node->data), dx, dy);

            node = g_slist_next(node);
        }
    }
}

static void
sch_path_write(SchShape *shape, SchFileFormat2 *format, SchOutputStream *stream, GError **error)
{
    sch_file_format_2_write_path(format, stream, SCH_PATH(shape), error);
}

