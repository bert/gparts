/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2011 Edward C. Hennessy
 * Copyright (C) 2011 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpdata-op-buildable.c
 */

#include <glib-object.h>

#include "gpdata.h"

GType
sch_drafter_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPDataOPBuildableInterface),    /* class_size */
            NULL,                                  /* base_init */
            NULL,                                  /* base_finalize */
            NULL,                                  /* class_init */
            NULL,                                  /* class_finalize */
            NULL,                                  /* class_data */
            0,                                     /* instance_size */
            0,                                     /* n_preallocs */
            NULL,                                  /* instance_init */
            NULL                                   /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_INTERFACE,
            "GPDataOPBuildable",
            &tinfo,
            0
            );
    }

    return type;
}

