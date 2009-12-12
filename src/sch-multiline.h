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

/*! \file sch_multiline.h
 *
 *  \brief A wrapper for gschem's line.
 */

#define SCH_TYPE_MULTILINE (sch_multiline_get_type())
#define SCH_MULTILINE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_MULTILINE,SchMultiline))
#define SCH_MULTILINE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_MULTILINE,SchMultilineClass))
#define SCH_IS_MULTILINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_MULTILINE))
#define SCH_IS_MULTILINE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_MULTILINE))
#define SCH_MULTILINE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_MULTILINE,SchMultilineClass))

typedef struct _SchMultiline SchMultiline;
typedef struct _SchMultilineClass SchMultilineClass;

struct _SchMultiline
{
    GObject parent;
};

struct _SchMultilineClass
{
    GObjectClass parent;
};

GType
sch_multiline_get_type(void);

void
sch_multiline_append(SchMultiline *multiline, const char *string);

void
sch_multiline_clear(SchMultiline *multiline);

const char*
sch_multiline_peek_markup(SchMultiline *multiline, int show);

const char*
sch_multiline_peek_plain(SchMultiline *multiline, int show);

int
sch_multiline_lines(SchMultiline *multiline);

