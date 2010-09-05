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

/*! \file sch-box.h
 */

#define SCH_TYPE_BOX (sch_box_get_type())
#define SCH_BOX(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_BOX,SchBox))
#define SCH_BOX_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_BOX,SchBoxClass))
#define SCH_IS_BOX(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_BOX))
#define SCH_IS_BOX_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_BOX))
#define SCH_BOX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_BOX,SchBoxClass))

struct _SchFillStyle;
struct _SchLineStyle;

struct _SchBox
{
    SchShape parent;
};

struct _SchBoxClass
{
    SchShapeClass parent;
};

GType
sch_box_get_type(void);

void
sch_box_get_box(const SchBox *shape, GeomBox *box);

void
sch_box_get_color(const SchBox *shape, int *index);

void
sch_box_get_fill_style(const SchBox *shape, SchFillStyle *style);

void
sch_box_get_line_width(const SchBox *shape, int *width);

void
sch_box_get_line_style(const SchBox *shape, SchLineStyle *style);

/*! \brief Create an instance of a box
 *
 *  \param [in] config The configuration
 *  \return A pointer to a box
 */
SchBox*
sch_box_new(const SchConfig *config);

