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

#define GPARTSUI_TYPE_DOCUMENT_MODEL (gpartsui_document_model_get_type())
#define GPARTSUI_DOCUMENT_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTSUI_TYPE_DOCUMENT_MODEL,GPartsUIDocumentModel))
#define GPARTSUI_DOCUMENT_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTSUI_TYPE_DOCUMENT_MODEL,GPartsUIDocumentModelClass))
#define GPARTSUI_IS_DOCUMENT_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTSUI_TYPE_DOCUMENT_MODEL))
#define GPARTSUI_IS_DOCUMENT_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTSUI_TYPE_DOCUMENT_MODEL))
#define GPARTSUI_DOCUMENT_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTSUI_TYPE_DOCUMENT_MODEL,GPartsUIDocumentModelClass))

struct _GPartsUIDocumentModel
{
    GObject parent;
};

/*! \private */
struct _GPartsUIDocumentModelClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpartsui_document_model_get_type(void);

MiscUIActionModel*
gpartsui_document_model_get_delete_action_model(const GPartsUIDocumentModel *model);

MiscUIActionModel*
gpartsui_document_model_get_open_website_action_model(const GPartsUIDocumentModel *model);

GPartsUIResultModel*
gpartsui_document_model_get_result_model(const GPartsUIDocumentModel *model);

/*! \brief Delete a company from the database.
 *
 *  \param [in] model The company presentation model.
 *  \param [out] model The error, if any, using the GError protocol.
 */
void
gpartsui_document_model_delete(GPartsUIDocumentModel *model, GError **error);

void
gpartsui_document_model_open_website(GPartsUIDocumentModel *model, GError **error);

GPartsDatabaseResult*
gpartsui_document_model_get_document_result(const GPartsUIDocumentModel *model);

void
gpartsui_document_model_set_document_result(GPartsUIDocumentModel *model, GPartsDatabaseResult *result);

