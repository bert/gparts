/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2012 Edward C. Hennessy
 * Copyright (C) 2012 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpview-factory.h
 */

#define GPVIEW_TYPE_FACTORY (gpview_factory_get_type())
#define GPVIEW_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPVIEW_TYPE_FACTORY,GPViewFactory))
#define GPVIEW_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPVIEW_TYPE_FACTORY,GPViewFactoryClass))
#define GPVIEW_IS_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPVIEW_TYPE_FACTORY))
#define GPVIEW_IS_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPVIEW_TYPE_FACTORY))
#define GPVIEW_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPVIEW_TYPE_FACTORY,GPViewFactoryClass))

/*! \extends GObject */
struct _GPViewFactory
{
    GObject parent;
};

/*! \private */
struct _GPViewFactoryClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpview_factory_get_type(void);

GPViewCompanyView*
gpview_factory_create_company_view(GPViewFactory *factory);

GPViewDeviceView*
gpview_factory_create_device_view(GPViewFactory *factory);

GPViewDocumentView*
gpview_factory_create_document_view(GPViewFactory *factory);

GPViewFootprintView*
gpview_factory_create_footprint_view(GPViewFactory *factory);

GPViewPackageView*
gpview_factory_create_package_view(GPViewFactory *factory);

GPViewPartView*
gpview_factory_create_part_view(GPViewFactory *factory);

GPViewSymbolView*
gpview_factory_create_symbol_view(GPViewFactory *factory);

GPViewFactory*
gpview_factory_new(void);

GPViewFactory*
gpview_factory_new_with_ui_manager(GtkUIManager *manager);

void
gpview_factory_set_ui_manager(GPViewFactory *factory, GtkUIManager *manager);

