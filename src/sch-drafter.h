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

/*! \file sch-drafter.h
 */

#define SCH_TYPE_DRAFTER (sch_drafter_get_type())
#define SCH_DRAFTER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_DRAFTER,SchDrafter))
#define SCH_IS_DRAFTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_DRAFTER))
#define SCH_DRAFTER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE((obj),SCH_TYPE_DRAFTER,SchDrafterInterface))

struct _SchDrafterInterface
{
    GTypeInterface parent;

    void (*draw_arc)(SchDrafter *drafter, const SchArc *shape);
    void (*draw_box)(SchDrafter *drafter, const SchBox *shape);
    void (*draw_bus)(SchDrafter *drafter, const SchBus *shape);
    void (*draw_circle)(SchDrafter *drafter, const SchCircle *shape);
    void (*draw_component)(SchDrafter *drafter, const SchComponent *shape);
    void (*draw_line)(SchDrafter *drafter, const SchLine *shape);
    void (*draw_net)(SchDrafter *drafter, const SchNet *shape);
    /* void (*draw_path)(SchDrafter *drafter, const SchPath *shape); */
    void (*draw_picture)(SchDrafter *drafter, const SchPicture *shape);
    void (*draw_pin)(SchDrafter *drafter, const SchPin *shape);
    void (*draw_text)(SchDrafter *drafter, const SchText *shape);

    void (*component_bounds)(SchDrafter *drafter, const struct _SchComponent *shape, struct _GeomBounds *bounds);
    void (*text_bounds)(SchDrafter *drafter, const struct _SchText *shape, struct _GeomBounds *bounds);
};

GType
sch_drafter_get_type(void);


void
sch_drafter_draw_arc(SchDrafter *drafter, const SchArc *shape);

void
sch_drafter_draw_box(SchDrafter *drafter, const SchBox *shape);

void
sch_drafter_draw_bus(SchDrafter *drafter, const SchBus *shape);

void
sch_drafter_draw_circle(SchDrafter *drafter, const SchCircle *shape);

void
sch_drafter_draw_component(SchDrafter *drafter, const SchComponent *shape);

void
sch_drafter_draw_line(SchDrafter *drafter, const SchLine *shape);

void
sch_drafter_draw_net(SchDrafter *drafter, const SchNet *shape);

/*
void
sch_drafter_draw_path(SchDrafter *drafter, const SchPath *shape);
*/

void
sch_drafter_draw_picture(SchDrafter *drafter, const SchPicture *shape);

void
sch_drafter_draw_pin(SchDrafter *drafter, const SchPin *shape);

void
sch_drafter_draw_text(SchDrafter *drafter, const SchText *shape);

void
sch_drafter_component_bounds(SchDrafter *drafter, const struct _SchComponent *shape, struct _GeomBounds *bounds);

void
sch_drafter_text_bounds(SchDrafter *drafter, const struct _SchText *shape, struct _GeomBounds *bounds);

