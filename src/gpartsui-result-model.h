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

/*! \file gpartsui-result-model.h
 */

#define GPARTSUI_TYPE_RESULT_MODEL (gpartsui_result_model_get_type())
#define GPARTSUI_RESULT_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTSUI_TYPE_RESULT_MODEL,GPartsUIResultModel))
#define GPARTSUI_RESULT_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTSUI_TYPE_RESULT_MODEL,GPartsUIResultModelClass))
#define GPARTSUI_IS_RESULT_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTSUI_TYPE_RESULT_MODEL))
#define GPARTSUI_IS_RESULT_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTSUI_TYPE_RESULT_MODEL))
#define GPARTSUI_RESULT_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTSUI_TYPE_RESULT_MODEL,GPartsUIResultModelClass))

struct _GPartsUIResultModel
{
    GObject parent;
};

/*! \private */
struct _GPartsUIResultModelClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpartsui_result_model_get_type(void);

/*! \brief Get the database result associated with this presentation model.
 *
 *  \public
 *  \memberof _GPartsUIResultModel
 *
 *  \param [in] model The presentation model.
 *  \return The database result.
 */
GPartsDatabaseResult*
gpartsui_result_model_get_result(const GPartsUIResultModel *model);

guint
gpartsui_result_model_get_selected_row(const GPartsUIResultModel *model);

/*! \brief Set the database result associated with this presentation model.
 *
 *  \public
 *  \memberof _GPartsUIResultModel
 *
 *  \param [in] model  The presentation model.
 *  \param [in] result The database result.
 */
void
gpartsui_result_model_set_result(GPartsUIResultModel *model, GPartsDatabaseResult *result);

void
gpartsui_result_model_set_selected_row(const GPartsUIResultModel *model, guint selected);

/*! \brief Get the selected fields
 *
 *  \public
 *  \memberof _GPartsUIResultModel
 *
 *  \param [in] model The presentation model.
 *  \return A NULL terminated list of the selected fields.
 */
GStrv
gpartsui_result_model_get_selected_fields(const GPartsUIResultModel *model, guint column);

