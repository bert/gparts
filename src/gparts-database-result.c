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

/*! \file gparts-database-result.c
 */

#include <glib-object.h>

#include "gparts-database-result.h"

static void
gparts_database_result_base_init(gpointer g_class)
{
}

guint
gparts_database_result_get_column_count(GPartsDatabaseResult *result)
{
    gint column_count = 0;
    GPartsDatabaseResultInterface *iface = GPARTS_DATABASE_RESULT_GET_INTERFACE(result);

    if (iface == NULL)
    {
        g_critical("Unable to get GPartsDatabaseResultInteface from parameter");
    }
    else if (iface->get_column_count == NULL)
    {
        g_critical("GPartsDatabaseResultInterface contains NULL get_column_count() function pointer");
    }
    else
    {
        column_count = iface->get_column_count(result);
    }

    return column_count;
}

gboolean
gparts_database_result_get_column_index(GPartsDatabaseResult *result, const gchar *name, gint *index)
{
    gboolean success = FALSE;
    GPartsDatabaseResultInterface *iface = GPARTS_DATABASE_RESULT_GET_INTERFACE(result);

    if (iface == NULL)
    {
        g_critical("Unable to get GPartsDatabaseResultInteface from parameter");
    }
    else if (iface->get_column_index == NULL)
    {
        g_critical("GPartsDatabaseResultInterface contains NULL get_column_index() function pointer");
    }
    else
    {
        success = iface->get_column_index(result, name, index);
    }

    return success;
}

GType
gparts_database_result_get_column_type(GPartsDatabaseResult *result, gint column)
{
    GPartsDatabaseResultInterface *iface = GPARTS_DATABASE_RESULT_GET_INTERFACE(result);
    GType type = G_TYPE_INVALID;

    if (iface == NULL)
    {
        g_critical("Unable to get GPartsDatabaseResultInteface from parameter");
    }
    else if (iface->get_column_count == NULL)
    {
        g_critical("GPartsDatabaseResultInterface contains NULL get_column_type() function pointer");
    }
    else
    {
        type = iface->get_column_type(result, column);
    }

    return type;
}

void
gparts_database_result_get_column_value(GPartsDatabaseResult *result, gint column, GValue *value)
{
    GPartsDatabaseResultInterface *iface = GPARTS_DATABASE_RESULT_GET_INTERFACE(result);

    if (iface == NULL)
    {
        g_critical("Unable to get GPartsDatabaseResultInteface from parameter");
    }
    else if (iface->get_column_value == NULL)
    {
        g_critical("GPartsDatabaseResultInterface contains NULL get_column_value() function pointer");
    }
    else
    {
        iface->get_column_value(result, column, value);
    }
}

void
gparts_database_result_get_field_value(GPartsDatabaseResult *result, gint row, gint column, GValue *value)
{
    GPartsDatabaseResultInterface *iface = GPARTS_DATABASE_RESULT_GET_INTERFACE(result);

    if (iface == NULL)
    {
        g_critical("Unable to get GPartsDatabaseResultInteface from parameter");
    }
    else if (iface->get_field_value == NULL)
    {
        g_critical("GPartsDatabaseResultInterface contains NULL get_field_value() function pointer");
    }
    else
    {
        iface->get_field_value(result, row, column, value);
    }
}

guint
gparts_database_result_get_row_count(GPartsDatabaseResult *result)
{
    GPartsDatabaseResultInterface *iface = GPARTS_DATABASE_RESULT_GET_INTERFACE(result);
    guint row_count = 0;

    if (iface == NULL)
    {
        g_critical("Unable to get GPartsDatabaseResultInteface from parameter");
    }
    else if (iface->get_row_count == NULL)
    {
        g_critical("GPartsDatabaseResultInterface contains NULL get_row_count() function pointer");
    }
    else
    {
        row_count = iface->get_row_count(result);
    }

    return row_count;
}

GType
gparts_database_result_get_type(void)
{
    static GType type = 0;

    if (type == 0)
    {
        static const GTypeInfo info = {
            sizeof(GPartsDatabaseResultInterface),
            gparts_database_result_base_init,
            NULL,
            NULL,
            NULL,
            NULL,
            0,
            0,
            NULL,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_INTERFACE,
            "gparts-database-result",
            &info,
            0
            );
    }

    return type;
}

