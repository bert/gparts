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

/*! \file gparts-controller.c 
 */

#include <glib-object.h>

#include "gparts-controller.h"

static void
gparts_controller_base_init(gpointer g_class)
{
}

gchar*
gparts_controller_get_field(GPartsController *controller, const gchar *name)
{
    gchar *field = NULL;
    GPartsControllerInterface *iface = GPARTS_CONTROLLER_GET_INTERFACE(controller);

    if (iface == NULL)
    {
    }
    else if (iface->get_field == NULL)
    {
    }
    else
    {
        field = iface->get_field(controller, name);
    }

    return field;
}

GHashTable*
gparts_controller_get_table(GPartsController *controller)
{
    GHashTable *table = NULL;

    if (controller != NULL)
    {
        GPartsControllerInterface *iface = GPARTS_CONTROLLER_GET_INTERFACE(controller);

        if (iface == NULL)
        {
        }
        else if (iface->get_table == NULL)
        {
        }
        else
        {
            table = iface->get_table(controller);
        }
    }

    return table;
}


GType
gparts_controller_get_type(void)
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo info = {
            sizeof(GPartsControllerInterface),
            gparts_controller_base_init,
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
            "gparts-controller",
            &info,
            0
            );
    }

    return type;
}

