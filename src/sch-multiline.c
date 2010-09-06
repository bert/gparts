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

/*! \file sch_multiline.c
 */

#include <glib.h>
#include <glib-object.h>

#include "sch-multiline.h"

#define SCH_MULTILINE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_MULTILINE,SchMultilinePrivate))

typedef struct _SchMultilinePrivate SchMultilinePrivate;

struct _SchMultilinePrivate
{
    char   *markup;
    char   *plain;
    GArray *strings;
};

static void
sch_multiline_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_multiline_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(SchMultilinePrivate));
}

GType
sch_multiline_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchMultilineClass),    /* class_size */
            NULL,                         /* base_init */
            NULL,                         /* base_finalize */
            sch_multiline_class_init,     /* class_init */
            NULL,                         /* class_finalize */
            NULL,                         /* class_data */
            sizeof(SchMultiline),         /* instance_size */
            0,                            /* n_preallocs */
            NULL,                         /* instance_init */
            NULL                          /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchMultiline",
            &tinfo,
            0
            );
    }

    return type;
}

void
sch_multiline_append(SchMultiline *multiline, const char *string)
{
    if (g_utf8_validate(string, -1, NULL))
    {
        SchMultilinePrivate *privat = SCH_MULTILINE_GET_PRIVATE(multiline);
    
        if (privat != NULL)
        {
            char *temp = g_strdup(string);

            if (privat->strings == NULL)
            {
                privat->strings = g_array_new(TRUE, FALSE, sizeof(char*));
            }

            g_array_append_val(privat->strings, temp);
        }
    }
}

void
sch_multiline_clear(SchMultiline *multiline)
{
}

int
sch_multiline_lines(SchMultiline *multiline)
{
    int lines = 0;
    SchMultilinePrivate *privat = SCH_MULTILINE_GET_PRIVATE(multiline);
    
    if ((privat != NULL) && (privat->strings != NULL))
    {
        lines = privat->strings->len;
    }

    return lines;
}

const char*
sch_multiline_peek_markup(SchMultiline *multiline, int show)
{
    SchMultilinePrivate *privat = SCH_MULTILINE_GET_PRIVATE(multiline);
    const char *string = NULL;

    if (privat != NULL)
    {
        if (privat->markup == NULL)
        {
            const char *temp = sch_multiline_peek_plain(multiline, show);

            if (temp != NULL)
            {
                privat->markup = g_markup_escape_text(temp, -1);
            }
        }

        string = privat->markup;
    }

    return string;
}

const char*
sch_multiline_peek_plain(SchMultiline *multiline, int show)
{
    SchMultilinePrivate *privat = SCH_MULTILINE_GET_PRIVATE(multiline);
    const char *string = NULL;

    if (privat != NULL)
    {
        if (privat->strings != NULL)
        {
            if (privat->plain == NULL)
            {
                privat->plain = g_strjoinv("\n", (char**) privat->strings->data);
            }

            if (show == 1)
            {
                gchar **temp;

                temp = g_strsplit(privat->plain, "=", 2);
                g_free(privat->plain);

                privat->plain = temp[1];
                g_free(temp[0]);
                g_free(temp);
            }
            else if (show == 2)
            {
                gchar **temp;

                temp = g_strsplit(privat->plain, "=", 2);
                g_free(privat->plain);

                privat->plain = temp[0];
                g_free(temp[1]);
                g_free(temp);
           }

            string = privat->plain;
        }
    }

    return string;
}

