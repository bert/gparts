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

/*! \file sch-component.h
 */

#define SCH_TYPE_COMPONENT (sch_component_get_type())
#define SCH_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_COMPONENT,SchComponent))
#define SCH_COMPONENT_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_COMPONENT,SchComponentClass))
#define SCH_IS_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_COMPONENT))
#define SCH_IS_COMPONENT_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_COMPONENT))
#define SCH_COMPONENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_COMPONENT,SchComponentClass))

typedef struct _SchComponent SchComponent;
typedef struct _SchComponentClass SchComponentClass;

struct _SchComponent
{
    GObject parent;
};

struct _SchComponentClass
{
    GObjectClass parent;
};

GType
sch_component_get_type(void);

void
sch_component_get_drawing(const SchComponent *shape, SchDrawing **drawing);

void
sch_component_set_drawing(SchComponent *shape, SchDrawing *drawing);

void
sch_component_get_insertion_point(const SchComponent *shape, int *x, int *y);

void
sch_component_get_orientation(const SchComponent *shape, int *angle, int *mirror);

