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

/*! \file gpdata-factory.h
 */

#define GPDATA_TYPE_FACTORY (gpdata_factory_get_type())
#define GPDATA_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPDATA_TYPE_FACTORY,GPDataFactory))
#define GPDATA_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPDATA_TYPE_FACTORY,GPDataFactoryClass))
#define GPDATA_IS_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPDATA_TYPE_FACTORY))
#define GPDATA_IS_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPDATA_TYPE_FACTORY))
#define GPDATA_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPDATA_TYPE_FACTORY,GPDataFactoryClass))

/*! \extends GObject
 */
struct _GPDataFactory
{
    GObject parent;
};

/*! \private
 */
struct _GPDataFactoryClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpdata_factory_get_type(void);

/*! \brief Create a model
 *
 *  \todo Add error checking
 *
 *  \param [in] factory  The factory to create the model
 *  \param [in] filename The XML file describing the model
 *  \return A pointer to the new model
 */
void*
gpdata_factory_create_model(const GPDataFactory *factory, const char *filename);

/*! \brief Get the path to the XML model files
 *
 *  The caller must use g_free when the string is no longer needed.
 *
 *  \param [in,out] factory
 *  \return
 */
gchar*
gpdata_factory_get_xml_path(const GPDataFactory *factory);

/*! \brief Create a new form factory
 *
 *  \return A pointer to the new form factory
 */
GPDataFactory*
gpdata_factory_new(void);

/*! \brief Set the path to the XML model files
 *
 *  \param [in,out] factory
 *  \param [in]     xml_path
 */
void
gpdata_factory_set_xml_path(GPDataFactory *factory, const gchar *xml_path);

