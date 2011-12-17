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

/*! \file gpdata-parser-stack.c
 */

#include <glib.h>
#include <glib-object.h>

#include "gpdata-parser-stack.h"

GPDataParserStack*
gpdata_parser_stack_copy(const GPDataParserStack *stack)
{
    return GPDATA_PARSER_STACK(g_memdup(stack, sizeof(GPDataParserStack)));
}

GType
gpdata_parser_stack_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        type = g_boxed_type_register_static(
            "GPDataParserStack",
            (GBoxedCopyFunc) gpdata_parser_stack_copy,
            (GBoxedFreeFunc) gpdata_parser_stack_free
            );
    }

    return type;
}

void
gpdata_parser_stack_free(GPDataParserStack *stack)
{
    g_free(stack);
}

GPDataParserStack*
gpdata_parser_stack_new(void)
{
    GPDataParserStack *stack = (GPDataParserStack*) g_malloc(sizeof(GPDataParserStack));

    return stack;
}

