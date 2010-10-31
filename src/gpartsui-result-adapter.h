/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2010 Edward C. Hennessy
 * Copyright (C) 2010 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpartsui-result-adapter.h
 */

#define GPARTSUI_TYPE_RESULT_ADAPTER (gpartsui_result_adapter_get_type())
#define GPARTSUI_RESULT_ADAPTER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTSUI_TYPE_RESULT_ADAPTER,GPartsUIResultAdapter))
#define GPARTSUI_RESULT_ADAPTER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTSUI_TYPE_RESULT_ADAPTER,GPartsUIResultAdapterClass))
#define GPARTSUI_IS_RESULT_ADAPTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTSUI_TYPE_RESULT_ADAPTER))
#define GPARTSUI_IS_RESULT_ADAPTER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTSUI_TYPE_RESULT_ADAPTER))
#define GPARTSUI_RESULT_ADAPTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTSUI_TYPE_RESULT_ADAPTER,GPartsUIResultAdapterClass))

struct _GPartsUIResultAdapter
{
    GObject parent;
};

/*! \private */
struct _GPartsUIResultAdapterClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpartsui_result_adapter_get_type(void);

/*! \brief Adjust the GtkTreeView's columns to match this adapter's.
 *
 *  \public
 *  \memberof _GPartsUIResultAdapter
 *
 *  \param [in]     adapter
 *  \param [in,out] view
 */
void
gpartsui_result_adapter_adjust_columns(const GPartsUIResultAdapter *adapter, GtkTreeView *view);

/*! \brief Get the index of a column, given the name
 *
 *  \param [in]  adapter
 *  \param [in]  name
 *  \param [out] index
 *  \retval TRUE
 *  \retval FALSE
 */
gboolean
gpartsui_result_adapter_get_column_index(GPartsUIResultAdapter *adapter, const gchar *name, gint *index);


GStrv
gpartsui_result_adapter_get_fields(const GPartsUIResultAdapter *adapter, GtkTreeSelection *selection, gint index);

/*! \brief Get the database result
 *
 *  \param [in] adapter
 *  \return
 */
GPartsDatabaseResult*
gpartsui_result_adapter_get_result(const GPartsUIResultAdapter *adapter);

/*! \brief Create a new adapter
 *
 * \param [in] result
 * \return
 */
GPartsUIResultAdapter*
gpartsui_result_adapter_new(GPartsDatabaseResult *result);

