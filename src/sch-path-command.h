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

/*! \file sch-path-command.h
 *
 *  \brief A boxed type for storing a path command
 */

#define SCH_TYPE_PATH_COMMAND (sch_path_command_get_type())
#define SCH_PATH_COMMAND(obj) ((SchPathCommand*)obj)

typedef enum _SchPathCommandType SchPathCommandType;

typedef union _SchPathCommand SchPathCommand;

typedef struct _SchPathCommandCurveTo SchPathCommandCurveTo;
typedef struct _SchPathCommandLineTo SchPathCommandLineTo;
typedef struct _SchPathCommandMoveTo SchPathCommandMoveTo;

enum _SchPathCommandType
{
    SCH_PATH_COMMAND_INVALID,
    SCH_PATH_COMMAND_CLOSEPATH,
    SCH_PATH_COMMAND_CURVETO_ABS,
    SCH_PATH_COMMAND_CURVETO_REL,
    SCH_PATH_COMMAND_LINETO_ABS,
    SCH_PATH_COMMAND_LINETO_REL,
    SCH_PATH_COMMAND_MOVETO_ABS,
    SCH_PATH_COMMAND_MOVETO_REL
};

struct _SchPathCommandCurveTo
{
    SchPathCommandType type;
    int                x[3];
    int                y[3];
};

struct _SchPathCommandLineTo
{
    SchPathCommandType type;
    int                x;
    int                y;
};

struct _SchPathCommandMoveTo
{
    SchPathCommandType type;
    int                x;
    int                y;
};

union _SchPathCommand
{
    SchPathCommandType    type;
    SchPathCommandCurveTo curveto;
    SchPathCommandLineTo  lineto;
    SchPathCommandMoveTo  moveto;
};

/*! \brief Make a copy of the
 *
 *  \param [in] command The command to be copied
 *  \return A pointer to the copied command
 */
SchPathCommand*
sch_path_command_copy(const SchPathCommand *command);

/*! \brief Free the memory associated with a path command 
 *
 *  \param [in] command The path command to be freed
 */
void
sch_path_command_free(SchPathCommand *command);

/*! \brief Rotate the path command
 *
 *  This function requires calls to sin() and cos(). If the caller is rotating
 *  a number of path commands, performance may be better to use a transform.
 *
 *  \param [in] command The path command to be rotated
 *  \param [in] angle   The angle to rotate, in degrees
 */
void
sch_path_command_rotate(SchPathCommand *command, int angle);

/*! \brief Transform the path command
 *
 *  Ablolute path commands undergo the full transformation. Relative path
 *  commands only undergo scaling and rotation.
 *
 *  \todo May require functionality to force the command to be interpreted as
 *  absolute for the special case of a relative moveto as the first command
 *  in a path.
 *
 *  \param [in] command   The path command to be transformed
 *  \param [in] transform The transformation matrix
 */
void
sch_path_command_transform(SchPathCommand *command, const GeomTransform *transform);

/*! \brief Translate the path command
 *
 *  This function only modifies absolute commands. Relative commands do not
 *  require translation.
 *
 *  \todo May require functionality to force the command to be interpreted as
 *  absolute for the special case of a relative moveto as the first command
 *  in a path.
 *
 *  \param [in] command The path command to be translated
 *  \param [in] dx      The distance to translate on the x axis
 *  \param [in] dy      The distance to translate on the y axis
 */
void
sch_path_command_translate(SchPathCommand *command, int dx, int dy);

