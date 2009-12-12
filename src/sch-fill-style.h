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

/*! \file sch-fill-style.h
 */

#define SCH_FILL_STYLE_FILL_TYPE_HOLLOW  0
#define SCH_FILL_STYLE_FILL_TYPE_SOLID   1
#define SCH_FILL_STYLE_FILL_TYPE_MESH    2
#define SCH_FILL_STYLE_FILL_TYPE_HATCH   3
#define SCH_FILL_STYLE_FILL_TYPE_VOID    4

typedef struct _SchFillStyle SchFillStyle;

struct _SchFillStyle
{
    int type;
    int width;
    int angle1;
    int pitch1;
    int angle2;
    int pitch2;
};

void
sch_fill_style_init(SchFillStyle *style);

