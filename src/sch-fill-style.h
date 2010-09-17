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

/*! \file sch-fill-style.h
 */

#define SCH_TYPE_FILL_STYLE (sch_fill_style_get_type())
#define SCH_FILL_STYLE(obj) ((SchFillStyle*)obj)

#define SCH_FILL_STYLE_FILL_TYPE_HOLLOW  0
#define SCH_FILL_STYLE_FILL_TYPE_SOLID   1
#define SCH_FILL_STYLE_FILL_TYPE_MESH    2
#define SCH_FILL_STYLE_FILL_TYPE_HATCH   3
#define SCH_FILL_STYLE_FILL_TYPE_VOID    4

typedef struct _SchFillStyle SchFillStyle;

struct _SchFillStyle
{
    int type;
    int width;
    int angle1;
    int pitch1;
    int angle2;
    int pitch2;
};

GType
sch_fill_style_get_type(void);

/*! \brief Make a copy of the SchFillStyle
 *
 *  When no longer needed, the caller must call sch_fill_style_free()
 *  on the returned pointer.
 *
 *  \param [in] style The SchFillStyle to be copied
 *  \return A pointer to the copied SchFillStyle 
 */
SchFillStyle*
sch_fill_style_copy(const SchFillStyle *style);

/*! \brief Free the memory associated with SchFillStyle
 *
 *  When passing in a NULL pointer, this function does nothing.
 *
 *  \param [in] style The SchFillStyle to be freed 
 */
void
sch_fill_style_free(SchFillStyle *style);

/*! \brief Initialize a SchFillStyle to default values
 *
 *  \param [out] style The SchFillStyle to be initialized
 */

void
sch_fill_style_init(SchFillStyle *style);

