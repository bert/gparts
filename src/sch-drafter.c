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

/*! \file sch-drafter.c
 */

#include <glib-object.h>

#include "sch-drafter.h"

void
sch_drafter_component_bounds(SchDrafter *drafter, const struct _SchComponent *shape, struct _GeomBounds *bounds)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->component_bounds == NULL)
    {
        g_critical("SchDrafterInterface contains NULL component_bounds() function pointer");
    }
    else
    {
        iface->component_bounds(drafter, shape, bounds);
    }
}

void
sch_drafter_draw_arc(SchDrafter *drafter, const struct _SchArc *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_arc == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_arc() function pointer");
    }
    else
    {
        iface->draw_arc(drafter, shape);
    }
}

void
sch_drafter_draw_box(SchDrafter *drafter, const struct _SchBox *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_box == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_box() function pointer");
    }
    else
    {
        iface->draw_box(drafter, shape);
    }
}

void
sch_drafter_draw_circle(SchDrafter *drafter, const struct _SchCircle *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_circle == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_circle() function pointer");
    }
    else
    {
        iface->draw_circle(drafter, shape);
    }
}

void
sch_drafter_draw_component(SchDrafter *drafter, const struct _SchComponent *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_component == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_component() function pointer");
    }
    else
    {
        iface->draw_component(drafter, shape);
    }
}

void
sch_drafter_draw_bus(SchDrafter *drafter, const struct _SchBus *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_bus == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_bus() function pointer");
    }
    else
    {
        iface->draw_bus(drafter, shape);
    }
}

void
sch_drafter_draw_line(SchDrafter *drafter, const struct _SchLine *line)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_line == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_line() function pointer");
    }
    else
    {
        iface->draw_line(drafter, line);
    }
}

void
sch_drafter_draw_net(SchDrafter *drafter, const struct _SchNet *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_net == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_net() function pointer");
    }
    else
    {
        iface->draw_net(drafter, shape);
    }
}

void
sch_drafter_draw_path(SchDrafter *drafter, const struct _SchPath *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_path == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_path() function pointer");
    }
    else
    {
        iface->draw_path(drafter, shape);
    }
}

void
sch_drafter_draw_picture(SchDrafter *drafter, const struct _SchPicture *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_picture == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_picture() function pointer");
    }
    else
    {
        iface->draw_picture(drafter, shape);
    }
}

void
sch_drafter_draw_pin(SchDrafter *drafter, const struct _SchPin *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_pin == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_pin() function pointer");
    }
    else
    {
        iface->draw_pin(drafter, shape);
    }
}

void
sch_drafter_draw_text(SchDrafter *drafter, const struct _SchText *shape)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->draw_text == NULL)
    {
        g_critical("SchDrafterInterface contains NULL draw_text() function pointer");
    }
    else
    {
        iface->draw_text(drafter, shape);
    }
}

GType
sch_drafter_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchDrafterInterface),    /* class_size */
            NULL,                           /* base_init */
            NULL,                           /* base_finalize */
            NULL,                           /* class_init */
            NULL,                           /* class_finalize */
            NULL,                           /* class_data */
            0,                              /* instance_size */
            0,                              /* n_preallocs */
            NULL,                           /* instance_init */
            NULL                            /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_INTERFACE,
            "SchDrafter",
            &tinfo,
            0
            );
    }

    return type;
}

void
sch_drafter_text_bounds(SchDrafter *drafter, const struct _SchText *shape, struct _GeomBounds *bounds)
{
    SchDrafterInterface *iface = SCH_DRAFTER_GET_INTERFACE(drafter);

    if (iface == NULL)
    {
        g_critical("Unable to get SchDrafterInterface from parameter");
    }
    else if (iface->text_bounds == NULL)
    {
        g_critical("SchDrafterInterface contains NULL text_bounds() function pointer");
    }
    else
    {
        iface->text_bounds(drafter, shape, bounds);
    }
}

