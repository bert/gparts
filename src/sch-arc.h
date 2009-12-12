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

/*! \file sch-arc.h
 */

#define SCH_TYPE_ARC (sch_arc_get_type())
#define SCH_ARC(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_ARC,SchArc))
#define SCH_ARC_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_ARC,SchArcClass))
#define SCH_IS_ARC(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_ARC))
#define SCH_IS_ARC_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_ARC))
#define SCH_ARC_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_ARC,SchArcClass))

typedef struct _SchArc SchArc;
typedef struct _SchArcClass SchArcClass;

struct _SchArc
{
    GObject parent;
};

struct _SchArcClass
{
    GObjectClass parent;
};

GType
sch_arc_get_type(void);

void
sch_arc_get_arc(const SchArc *shape, GeomArc *arc);

void
sch_arc_get_color(const SchArc *shape, int *index);

void
sch_arc_get_line_width(const SchArc *shape, int *width);

