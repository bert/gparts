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

/*! \file sch-path-command.c
 */

#include <glib.h>
#include <glib-object.h>

#include "sch.h"



SchPathCommand*
sch_path_command_copy(const SchPathCommand *command)
{
    return (SchPathCommand*) g_memdup(command, sizeof(SchPathCommand));
}

GType
sch_path_command_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        g_boxed_type_register_static(
            "SchPathCommand",
            (GBoxedCopyFunc) sch_path_command_copy,
            (GBoxedFreeFunc) sch_path_command_free
            );
    }

    return type;
}

void
sch_path_command_free(SchPathCommand *command)
{
    g_free(command);
}

void
sch_path_command_rotate(SchPathCommand *command, int angle)
{
    /*! \todo Implement */
    if (command != NULL)
    {
        switch (command->type)
        {
            case SCH_PATH_COMMAND_CURVETO_ABS:
            case SCH_PATH_COMMAND_CURVETO_REL:
                break;

            case SCH_PATH_COMMAND_LINETO_ABS:
            case SCH_PATH_COMMAND_LINETO_REL:
                break;

            case SCH_PATH_COMMAND_MOVETO_ABS:
            case SCH_PATH_COMMAND_MOVETO_REL:
                break;

            case SCH_PATH_COMMAND_INVALID:
            case SCH_PATH_COMMAND_CLOSEPATH:
            default:
                break;
        }
    }
}

void
sch_path_command_transform(SchPathCommand *command, const GeomTransform *transform)
{
    /*! \todo Implement */
    if (command != NULL)
    {
        switch (command->type)
        {
            case SCH_PATH_COMMAND_CURVETO_ABS:
                break;

            case SCH_PATH_COMMAND_CURVETO_REL:
                break;

            case SCH_PATH_COMMAND_LINETO_ABS:
                break;

            case SCH_PATH_COMMAND_LINETO_REL:
                break;

            case SCH_PATH_COMMAND_MOVETO_ABS:
                break;

            case SCH_PATH_COMMAND_MOVETO_REL:
                break;

            case SCH_PATH_COMMAND_INVALID:
            case SCH_PATH_COMMAND_CLOSEPATH:
            default:
                break;
        }
    }
}

void
sch_path_command_translate(SchPathCommand *command, int dx, int dy)
{
    if (command != NULL)
    {
        switch (command->type)
        {
            case SCH_PATH_COMMAND_CURVETO_ABS:
                command->curveto.x[0] += dx;
                command->curveto.y[0] += dy;
                command->curveto.x[1] += dx;
                command->curveto.y[1] += dy;
                command->curveto.x[2] += dx;
                command->curveto.y[2] += dy;
                break;

            case SCH_PATH_COMMAND_LINETO_ABS:
                command->lineto.x += dx;
                command->lineto.y += dy;
                break;

            case SCH_PATH_COMMAND_MOVETO_ABS:
                command->moveto.x += dx;
                command->moveto.y += dy;
                break;

            case SCH_PATH_COMMAND_INVALID:
            case SCH_PATH_COMMAND_CLOSEPATH:
            case SCH_PATH_COMMAND_CURVETO_REL:
            case SCH_PATH_COMMAND_LINETO_REL:
            case SCH_PATH_COMMAND_MOVETO_REL:
            default:
                break;
        }
    }
}

