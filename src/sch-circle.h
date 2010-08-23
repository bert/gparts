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

/*! \file sch-circle.h
 */

#define SCH_TYPE_CIRCLE (sch_circle_get_type())
#define SCH_CIRCLE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_CIRCLE,SchCircle))
#define SCH_CIRCLE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_CIRCLE,SchCircleClass))
#define SCH_IS_CIRCLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_CIRCLE))
#define SCH_IS_CIRCLE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_CIRCLE))
#define SCH_CIRCLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_CIRCLE,SchCircleClass))

typedef struct _SchCircle SchCircle;
typedef struct _SchCircleClass SchCircleClass;

struct _SchCircle
{
    SchShape parent;
};

struct _SchCircleClass
{
    SchShapeClass parent;
};

GType
sch_circle_get_type(void);

void
sch_circle_get_circle(const SchCircle *shape, GeomCircle *circle);

void
sch_circle_get_color(const SchCircle *shape, int *index);

void
sch_circle_get_fill_style(const SchCircle *shape, SchFillStyle *style);

void
sch_circle_get_line_width(const SchCircle *shape, int *width);

void
sch_circle_get_line_style(const SchCircle *shape, SchLineStyle *style);

/*! \brief Create a circle
 *
 *  \param [in] config The configuration
 *  \return The circle
 */
SchCircle*
sch_circle_new(const SchConfig *config);

