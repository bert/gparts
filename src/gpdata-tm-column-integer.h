/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2011 Edward C. Hennessy
 * Copyright (C) 2011 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpdata-tm-column-integer.h
 */

#define GPDATA_TYPE_TM_COLUMN_INTEGER (gpdata_tm_column_integer_get_type())
#define GPDATA_TM_COLUMN_INTEGER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPDATA_TYPE_TM_COLUMN_INTEGER,GPDataTMColumnInteger))
#define GPDATA_TM_COLUMN_INTEGER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPDATA_TYPE_TM_COLUMN_INTEGER,GPDataTMColumnIntegerClass))
#define GPDATA_IS_TM_COLUMN_INTEGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPDATA_TYPE_TM_COLUMN_INTEGER))
#define GPDATA_IS_TM_COLUMN_INTEGER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPDATA_TYPE_TM_COLUMN_INTEGER))
#define GPDATA_TM_COLUMN_INTEGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPDATA_TYPE_TM_COLUMN_INTEGER,GPDataTMColumnIntegerClass))

/*! \extends GPDataTMColumn */
struct _GPDataTMColumnInteger
{
    GPDataTMColumn parent;
};

/*! \private */
struct _GPDataTMColumnIntegerClass
{
    GPDataTMColumn parent;
};

/*! \private */
GType
gpdata_tm_column_integer_get_type(void);

gint
gpdata_tm_column_integer_get_max(GPDataTMColumnInteger *column);

gint
gpdata_tm_column_integer_get_min(GPDataTMColumnInteger *column);


/*! \brief Get the column name
 *
 *  \public
 *  \memberof _GPDataTMColumnInteger
 *
 *  The database column name
 *
 *  The returned string must be freed by the caller using g_free()
 *
 *  \param [in] column This column
 *  \return The name of the column [transfer full]
 */
gchar*
gpdata_tm_column_integer_get_name(const GPDataTMColumnInteger *column);

void
gpdata_tm_column_integer_set_max(GPDataTMColumnInteger *column, gint value);

void
gpdata_tm_column_integer_set_min(GPDataTMColumnInteger *column, gint value);

/*! \brief Set the column name
 *
 *  \public
 *  \memberof _GPDataTMColumnInteger
 *
 *  The database column name
 *
 *  \param [in,out] column This column
 *  \param [in] name The name of the column
 */
void
gpdata_tm_column_integer_set_name(GPDataTMColumnInteger *column, const gchar* name);


