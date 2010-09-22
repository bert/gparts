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

/*! \file sch-bus.h
 */

#define SCH_TYPE_BUS (sch_bus_get_type())
#define SCH_BUS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_BUS,SchBus))
#define SCH_BUS_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_BUS,SchBusClass))
#define SCH_IS_BUS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_BUS))
#define SCH_IS_BUS_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_BUS))
#define SCH_BUS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_BUS,SchBusClass))

/*! \extends SchShape
 */
struct _SchBus
{
    SchShape parent;
};

/*! \private
 */
struct _SchBusClass
{
    SchShapeClass parent;
};

GType
sch_bus_get_type(void);

void
sch_bus_get_color(const SchBus *shape, int *index);

void
sch_bus_get_line(const SchBus *shape, GeomLine *line);

/*! \brief Create an instance of a bus
 *
 *  \param [in] config The configuration
 *  \return A pointer to a bus
 */
SchBus*
sch_bus_new(const SchConfig *config);

