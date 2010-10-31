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

/*! \file gpartsui-company-controller.h
 */

#define GPARTSUI_TYPE_COMPANY_CONTROLLER (gpartsui_company_controller_get_type())
#define GPARTSUI_COMPANY_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTSUI_TYPE_COMPANY_CONTROLLER,GPartsUICompanyController))
#define GPARTSUI_COMPANY_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTSUI_TYPE_COMPANY_CONTROLLER,GPartsUICompanyControllerClass))
#define GPARTSUI_IS_COMPANY_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTSUI_TYPE_COMPANY_CONTROLLER))
#define GPARTSUI_IS_COMPANY_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTSUI_TYPE_COMPANY_CONTROLLER))
#define GPARTSUI_COMPANY_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTSUI_TYPE_COMPANY_CONTROLLER,GPartsUICompanyControllerClass))

struct _GPartsUICompanyController
{
    GPartsController parent;
};

/*! \private */
struct _GPartsUICompanyControllerClass
{
    GPartsControllerClass parent;
};

/*! \private */
GType
gpartsui_company_controller_get_type(void);

GPartsUICompanyModel*
gpartsui_company_controller_get_company_model(const GPartsUICompanyController *controller);

GtkTreeView*
gpartsui_company_controller_get_company_view(const GPartsUICompanyController *controller);

/*! \brief Open websites for the selected companies
 *
 */
void
gpartsui_company_controller_open_website(const GPartsUICompanyController *controller);

void
gpartsui_company_controller_set_company_model(GPartsUICompanyController *controller, GPartsUICompanyModel *model);

void
gpartsui_company_controller_set_company_view(GPartsUICompanyController *controller, GtkTreeView *view);

