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

/*! \file sch-line-style.c
 */

#include <glib.h>
#include <glib-object.h>

#include "sch-line-style.h"

SchLineStyle*
sch_line_style_copy(const SchLineStyle *style)
{
    return SCH_LINE_STYLE(g_memdup(style, sizeof(SchLineStyle)));
}

GType
sch_line_style_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        g_boxed_type_register_static(
            "SchLineStyle",
            (GBoxedCopyFunc) sch_line_style_copy,
            (GBoxedFreeFunc) sch_line_style_free
            );
    }

    return type;
}

void
sch_line_style_free(SchLineStyle *style)
{
    g_free(style);
}

void
sch_line_style_init(SchLineStyle *style)
{
    if (style != NULL)
    {
        style->cap_style   = 0;
        style->dash_style  = 0;
        style->dash_length = -1;
        style->dash_space  = -1;
    }
}


