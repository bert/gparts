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

/*! \file sch-line-style.h
 */

#define SCH_TYPE_LINE_STYLE (sch_line_style_get_type())
#define SCH_LINE_STYLE(obj) ((SchLineStyle*)obj)

typedef struct _SchLineStyle SchLineStyle;

struct _SchLineStyle
{
    int cap_style;
    int dash_style;
    int dash_length;
    int dash_space;
};

GType
sch_line_style_get_type(void);

/*! \brief Make a copy of the SchLineStyle
 *
 *  When no longer needed, the caller must call sch_line_style_free()
 *  on the returned pointer.
 *
 *  \param [in] style The SchLineStyle to be copied
 *  \return A pointer to the copied SchLineStyle 
 */
SchLineStyle*
sch_line_style_copy(const SchLineStyle *style);

/*! \brief Free the memory associated with SchLineStyle
 *
 *  When passing in a NULL pointer, this function does nothing.
 *
 *  \param [in] style The SchLineStyle to be freed 
 */
void
sch_line_style_free(SchLineStyle *style);

/*! \brief Initialize a SchLineStyle to default values
 *
 *  \param [out] style The SchLineStyle to be initialized
 */
void
sch_line_style_init(SchLineStyle *style);

