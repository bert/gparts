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

/*! \file sch-line.h
 */

#define SCH_TYPE_LINE (sch_line_get_type())
#define SCH_LINE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_LINE,SchLine))
#define SCH_LINE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_LINE,SchLineClass))
#define SCH_IS_LINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_LINE))
#define SCH_IS_LINE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_LINE))
#define SCH_LINE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_LINE,SchLineClass))

struct _SchLineStyle;

typedef struct _SchLine SchLine;
typedef struct _SchLineClass SchLineClass;

struct _SchLine
{
    SchShape parent;
};

struct _SchLineClass
{
    SchShapeClass parent;
};

GType
sch_line_get_type(void);

void
sch_line_get_color(const SchLine *line, int *index);

void
sch_line_get_line(const SchLine *sline, GeomLine *gline);

void
sch_line_get_line_style(const SchLine *line, struct _SchLineStyle *style);

void
sch_line_get_line_width(const SchLine *line, int *width);

