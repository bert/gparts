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

/*! \file gpdata-tm-table.h
 */

#define GPDATA_TYPE_TM_TABLE (gpdata_tm_table_get_type())
#define GPDATA_TM_TABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPDATA_TYPE_TM_TABLE,GPDataTMTable))
#define GPDATA_TM_TABLE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPDATA_TYPE_TM_TABLE,GPDataTMTableClass))
#define GPDATA_IS_TM_TABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPDATA_TYPE_TM_TABLE))
#define GPDATA_IS_TM_TABLE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPDATA_TYPE_TM_TABLE))
#define GPDATA_TM_TABLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPDATA_TYPE_TM_TABLE,GPDataTMTableClass))

/*! \extends GObject */
struct _GPDataTMTable
{
    GObject parent;
};

/*! \private */
struct _GPDataTMTableClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpdata_tm_table_get_type(void);

/*! \brief Create a new model for a table
 *
 *  \return A pointer to the new model
 */
GPDataTMTable*
gpdata_tm_table_new(void);

/*! \brief Add a column model to the end of the table model
 *
 *  \public
 *  \memberof _GPDataTMTable
 *
 *  \param [in,out] table  The table model
 *  \param [in]     column The column model
 */
void
gpdata_tm_table_add_column(GPDataTMTable *table, GPDataTMColumn *column);

/*! \brief Get a column model from the table model
 *
 *  \public
 *  \memberof _GPDataTMTable
 *
 *  The caller must use g_object_unref on the returned pointer when no longer
 *  needed.
 *
 *  In the event of a failure, this function returns NULL.
 *
 *  \param [in] table The table model
 *  \param [in] index The zero based index of the column
 *  \return A pointer to the column model [transfer full]
 */
GPDataTMColumn*
gpdata_tm_table_get_column(const GPDataTMTable *table, guint index);

/*! \brief Get the number of column models in the table model
 *
 *  \public
 *  \memberof _GPDataTMTable
 *
 *  In the event of a failure, this function returns 0.
 *
 *  \param [in] table The table model
 *  \return The number of column models in the table model
 */
guint
gpdata_tm_table_get_column_count(const GPDataTMTable *table);

/*! \brief Get the number of rows in the table
 *
 *  \public
 *  \memberof _GPDataTMTable
 *
 *  In the event of a failure, this function returns 0.
 *
 *  \param [in] table The table model
 *  \return The number of rows in the table
 */
guint
gpdata_tm_table_get_row_count(const GPDataTMTable *table);

