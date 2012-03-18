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

/*! \file gpview-category-model.h
 *
 *  \brief Provides a GtkTreeModel for the category view.
 *
 *  Unlike most of the views in GParts, the category view organizes data
 *  in a tree structure.
 */

#define GPVIEW_TYPE_CATEGORY_MODEL (gpview_category_model_get_type())
#define GPVIEW_CATEGORY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPVIEW_TYPE_CATEGORY_MODEL,GPViewCategoryModel))
#define GPVIEW_CATEGORY_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPVIEW_TYPE_CATEGORY_MODEL,GPViewCategoryModelClass))
#define GPVIEW_IS_CATEGORY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPVIEW_TYPE_CATEGORY_MODEL))
#define GPVIEW_IS_CATEGORY_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPVIEW_TYPE_CATEGORY_MODEL))
#define GPVIEW_CATEGORY_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPVIEW_TYPE_CATEGORY_MODEL,GPViewCategoryModelClass))

struct _GPViewCategoryModel
{
    GObject parent;
};

struct _GPViewCategoryModelClass
{
    GObjectClass parent;
};

GType
gpview_category_model_get_type( void );

GPViewCategoryModel*
gpview_category_model_new(GPartsDatabase *database);

/*! \brief TODO Finish
 *
 *  \param [in] model The model containing the field.
 *  \param [in] iter An iterator to the selected row.
 *  \param [in] name The column name of the field.
 *  \return The field value as a string.  This value must be freed when no
 *  longer needed.
 */
gchar*
gpview_category_model_get_field(GPViewCategoryModel *model, GtkTreeIter *iter, const gchar *name);

/*! TODO Finish
 */
void
gpview_category_model_set_columns(GPViewCategoryModel* model, GtkTreeView *tree_view);

