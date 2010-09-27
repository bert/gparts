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

#include "gparts-connect-data.h"

GPartsConnectData*
gparts_connect_data_copy(GPartsConnectData *data)
{
    GPartsConnectData *copy = NULL;

    if (data != NULL)
    {
        copy = gparts_connect_data_new();

        copy->hostname = g_strdup(data->hostname);
        copy->username = g_strdup(data->username);
        copy->password = g_strdup(data->password);
        copy->database = g_strdup(data->database);
        copy->filename = g_strdup(data->filename);
    }

    return copy;
}

void
gparts_connect_data_free(GPartsConnectData *data)
{
    if (data != NULL)
    {
        g_free(data->hostname);
        g_free(data->username);
        g_free(data->password);
        g_free(data->database);
        g_free(data->filename);

        g_free(data);
    }
}

GType
gparts_connect_data_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        type = g_boxed_type_register_static(
            "GPartsConnectData",
            (GBoxedCopyFunc) gparts_connect_data_copy,
            (GBoxedFreeFunc) gparts_connect_data_free
            );
    }

    return type;
}

GPartsConnectData*
gparts_connect_data_new(void)
{
    return GPARTS_CONNECT_DATA(g_malloc0(sizeof(GPartsConnectData)));
}

