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

/*! \file gpdata-tm-column.h
 */

#define GPDATA_TYPE_TM_COLUMN (gpdata_tm_column_get_type())
#define GPDATA_TM_COLUMN(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPDATA_TYPE_TM_COLUMN,GPDataTMColumn))
#define GPDATA_TM_COLUMN_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPDATA_TYPE_TM_COLUMN,GPDataTMColumnClass))
#define GPDATA_IS_TM_COLUMN(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPDATA_TYPE_TM_COLUMN))
#define GPDATA_IS_TM_COLUMN_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPDATA_TYPE_TM_COLUMN))
#define GPDATA_TM_COLUMN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPDATA_TYPE_TM_COLUMN,GPDataTMColumnClass))

/*! \extends GObject */
struct _GPDataTMColumn
{
    GObject parent;
};

/*! \private */
struct _GPDataTMColumnClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpdata_tm_column_get_type(void);

/*! \brief Get the column name as it appears in the UI
 *
 *  The returned string must be freed by the caller using g_free()
 *
 *  \param [in] column This column
 *  \return The name of the column at is appears in the UI [transfer full]
 */
gchar*
gpdata_tm_column_get_name(const GPDataTMColumn *column);

/*! \brief Get the horizontal alignment of column cells
 *
 *  \param [in] column This column
 *  \return The horizontal alignment of column cells
 */
gfloat
gpdata_tm_column_get_xalign(const GPDataTMColumn *column);

/*! \brief Set the column name as it appears in the UI
 *
 *  \param [in,out] column This column
 *  \param [in] name The name of the column at is appears in the UI
 */
void
gpdata_tm_column_set_name(GPDataTMColumn *column, const gchar* name);

/*! \brief set the horizontal alignment of column cells
 *
 *  \param [in,out] column This column
 *  \param [in]     xalign The horizontal alignment of column cells
 */
void
gpdata_tm_column_set_xalign(GPDataTMColumn *column, gfloat xalign);

