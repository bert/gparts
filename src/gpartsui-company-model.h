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

/*! \file gpartsui-company-model.h
 */

#define GPARTSUI_TYPE_COMPANY_MODEL (gpartsui_company_model_get_type())
#define GPARTSUI_COMPANY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTSUI_TYPE_COMPANY_MODEL,GPartsUICompanyModel))
#define GPARTSUI_COMPANY_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTSUI_TYPE_COMPANY_MODEL,GPartsUICompanyModelClass))
#define GPARTSUI_IS_COMPANY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTSUI_TYPE_COMPANY_MODEL))
#define GPARTSUI_IS_COMPANY_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTSUI_TYPE_COMPANY_MODEL))
#define GPARTSUI_COMPANY_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTSUI_TYPE_COMPANY_MODEL,GPartsUICompanyModelClass))

struct _GPartsUICompanyModel
{
    GObject parent;
};

/*! \private */
struct _GPartsUICompanyModelClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpartsui_company_model_get_type(void);

MiscUIActionModel*
gpartsui_company_model_get_delete_action_model(const GPartsUICompanyModel *model);

MiscUIActionModel*
gpartsui_company_model_get_open_website_action_model(const GPartsUICompanyModel *model);

GPartsUIResultModel*
gpartsui_company_model_get_result_model(const GPartsUICompanyModel *model);

/*! \brief Delete a company from the database.
 *
 *  \param [in] model The company presentation model.
 *  \param [out] model The error, if any, using the GError protocol.
 */
void
gpartsui_company_model_delete(GPartsUICompanyModel *model, GError **error);

void
gpartsui_company_model_open_website(GPartsUICompanyModel *model, GError **error);

GPartsDatabaseResult*
gpartsui_company_model_get_company_result(const GPartsUICompanyModel *model);

void
gpartsui_company_model_set_company_result(GPartsUICompanyModel *model, GPartsDatabaseResult *result);

