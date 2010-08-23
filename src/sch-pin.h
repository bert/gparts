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

/*! \file sch-pin.h
 */

#define SCH_TYPE_PIN (sch_pin_get_type())
#define SCH_PIN(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_PIN,SchPin))
#define SCH_PIN_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_PIN,SchPinClass))
#define SCH_IS_PIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_PIN))
#define SCH_IS_PIN_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_PIN))
#define SCH_PIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_PIN,SchPinClass))

typedef struct _SchPin SchPin;
typedef struct _SchPinClass SchPinClass;

struct _SchPin
{
    SchShape parent;
};

struct _SchPinClass
{
    SchShapeClass parent;
};

GType
sch_pin_get_type(void);

void
sch_pin_get_color(const SchPin *shape, int *index);

void
sch_pin_get_line(const SchPin *shape, GeomLine *line);

int
sch_pin_get_x1(const SchPin *shape);

int
sch_pin_get_y1(const SchPin *shape);

int
sch_pin_get_x2(const SchPin *shape);

int
sch_pin_get_y2(const SchPin *shape);

int
sch_pin_get_color_(const SchPin *shape);

int
sch_pin_get_type_(const SchPin *shape);

int
sch_pin_get_end(const SchPin *shape);

/*! \brief Create a pin
 *
 *  \param [in] config The configuration
 *  \return The pin
 */
SchPin*
sch_pin_new(const SchConfig *config);

