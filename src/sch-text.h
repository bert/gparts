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

/*! \file sch_schematic_text.h
 */

#define SCH_TYPE_TEXT (sch_text_get_type())
#define SCH_TEXT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_TEXT,SchText))
#define SCH_TEXT_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_TEXT,SchTextClass))
#define SCH_IS_TEXT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_TEXT))
#define SCH_IS_TEXT_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_TEXT))
#define SCH_TEXT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_TEXT,SchTextClass))

struct _SchText
{
    SchShape parent;
};

struct _SchTextClass
{
    SchShapeClass parent;
};

GType
sch_text_get_type(void);

int
sch_text_get_x(SchText *text);

int
sch_text_get_y(SchText *text);

int
sch_text_get_size(SchText *text);

int
sch_text_get_angle(SchText *text);

SchMultiline*
sch_text_get_multiline(SchText *text);

void
sch_text_set_multiline(SchText *text, SchMultiline *multiline);

int
sch_text_get_alignment(SchText *text);

void
sch_text_get_color(const SchText *shape, int *index);

void
sch_text_get_show(const SchText *shape, int *show);

void
sch_text_get_visible(const SchText *shape, int *visible);

/*! \brief Create a text object
 *
 *  \param [in] config The configuration
 *  \return The text object
 */
SchText*
sch_text_new(const SchConfig *config);

