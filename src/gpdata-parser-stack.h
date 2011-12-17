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

/*! \file gpdata-parser-stack.h
 *
 *  \ingroup gpdata
 */

#define GPDATA_TYPE_PARSER_STACK (gpdata_parser_stack_get_type())
#define GPDATA_PARSER_STACK(obj) ((GPDataParserStack*)obj)

typedef struct _GPDataParserStack GPDataParserStack;

/*! \brief A boxed type for the style paramters of lines
 *
 *  \ingroup sch
 */
struct _GPDataParserStack
{
    int dummy;
};

/*! \private */
GType
gpdata_parser_stack_get_type(void);

/*! \brief Make a copy of the GPDataParserStack
 *
 *  \memberof _GPDataParserStack
 *
 *  When no longer needed, the caller must call gpdata_parser_stack_free()
 *  on the returned pointer.
 *
 *  \param [in] style The GPDataParserStack to be copied
 *  \return A pointer to the copied GPDataParserStack
 */
GPDataParserStack*
gpdata_parser_stack_copy(const GPDataParserStack *style);

/*! \brief Free the memory associated with GPDataParserStack
 *
 *  \memberof _GPDataParserStack
 *
 *  When passing in a NULL pointer, this function does nothing.
 *
 *  \param [in] style The GPDataParserStack to be freed
 */
void
gpdata_parser_stack_free(GPDataParserStack *style);

/*! \brief Dynamically allocate a GPDataParserStack with default values
 *
 *  \memberof _GPDataParserStack
 *
 *  \return The dynamically allocated GPDataParserStack
 */
GPDataParserStack*
gpdata_parser_stack_new(void);

