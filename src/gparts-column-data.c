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

/*! \file gparts-connect-data.c
 */

#include <glib.h>
#include <glib-object.h>

#include "gparts-column-data.h"

GPartsColumnData*
gparts_column_data_copy(GPartsColumnData *data)
{
    GPartsColumnData *copy = NULL;

    if (data != NULL)
    {
        copy = gparts_column_data_new();

        copy->name = g_strdup(data->name);
        copy->type = data->type;
    }

    return copy;
}

void
gparts_column_data_free(GPartsColumnData *data)
{
    if (data != NULL)
    {
        g_free(data->name);

        g_free(data);
    }
}

GType
gparts_column_data_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        type = g_boxed_type_register_static(
            "GPartsColumnData",
            (GBoxedCopyFunc) gparts_column_data_copy,
            (GBoxedFreeFunc) gparts_column_data_free
            );
    }

    return type;
}

GPartsColumnData*
gparts_column_data_new(void)
{
    return GPARTS_COLUMN_DATA(g_malloc0(sizeof(GPartsColumnData)));
}

