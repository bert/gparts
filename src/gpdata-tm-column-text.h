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

/*! \file gpdata-tm-column-text.h
 */

#define GPDATA_TYPE_TM_COLUMN_TEXT (gpdata_tm_column_text_get_type())
#define GPDATA_TM_COLUMN_TEXT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPDATA_TYPE_TM_COLUMN_TEXT,GPDataTMColumnText))
#define GPDATA_TM_COLUMN_TEXT_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPDATA_TYPE_TM_COLUMN_TEXT,GPDataTMColumnTextClass))
#define GPDATA_IS_TM_COLUMN_TEXT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPDATA_TYPE_TM_COLUMN_TEXT))
#define GPDATA_IS_TM_COLUMN_TEXT_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPDATA_TYPE_TM_COLUMN_TEXT))
#define GPDATA_TM_COLUMN_TEXT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPDATA_TYPE_TM_COLUMN_TEXT,GPDataTMColumnTextClass))

/*! \extends GPDataTMColumn */
struct _GPDataTMColumnText
{
    GPDataTMColumn parent;
};

/*! \private */
struct _GPDataTMColumnTextClass
{
    GPDataTMColumn parent;
};

/*! \private */
GType
gpdata_tm_column_text_get_type(void);

/*! \brief Get the significant digits used for display of this column
 *
 *  \public
 *  \memberof _GPDataTMColumnText
 *
 *  \param [in] column This column
 *  \return The significant digits to display for this column
 */
gint
gpdata_tm_column_text_get_digits(const GPDataTMColumnText *column);

/*! \brief Get the column name
 *
 *  \public
 *  \memberof _GPDataTMColumnText
 *
 *  The database column name
 *
 *  The returned string must be freed by the caller using g_free()
 *
 *  \param [in] column This column
 *  \return The name of the column [transfer full]
 */
gchar*
gpdata_tm_column_text_get_name(const GPDataTMColumnText *column);

/*! \brief Get the units of measure for this column
 *
 *  \public
 *  \memberof _GPDataTMColumnText
 *
 *  \param [in] column This column
 *  \return The units of measure for this column [transfer full]
 */
gchar*
gpdata_tm_column_text_get_units(const GPDataTMColumnText *column);

/*! \brief Set the significant digits used for display of this column
 *
 *  \public
 *  \memberof _GPDataTMColumnText
 *
 *  \param [in,out] column This column
 *  \param [in] digits The significant digits to display for this column
 */
void
gpdata_tm_column_text_set_digits(GPDataTMColumnText *column, gint digits);

/*! \brief Set the column name
 *
 *  \public
 *  \memberof _GPDataTMColumnText
 *
 *  The database column name
 *
 *  \param [in,out] column This column
 *  \param [in] name The name of the column
 */
void
gpdata_tm_column_text_set_name(GPDataTMColumnText *column, const gchar* name);

/*! \brief set the units for measure for this column
 *
 *  \public
 *  \memberof _GPDataTMColumnText
 *
 *  \param [in,out] column This column
 *  \param [in]     units  The units for this column
 */
void
gpdata_tm_column_text_set_units(GPDataTMColumnText *column, const gchar *units);

