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

/*! \file gpform-factory.h
 */

#define GPFORM_TYPE_FACTORY (gpform_factory_get_type())
#define GPFORM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPFORM_TYPE_FACTORY,GPFormFactory))
#define GPFORM_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPFORM_TYPE_FACTORY,GPFormFactoryClass))
#define GPFORM_IS_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPFORM_TYPE_FACTORY))
#define GPFORM_IS_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPFORM_TYPE_FACTORY))
#define GPFORM_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPFORM_TYPE_FACTORY,GPFormFactoryClass))

/*! \extends GObject
 */
struct _GPFormFactory
{
    GObject parent;
};

/*! \private
 */
struct _GPFormFactoryClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpform_factory_get_type(void);

/*! \brief Create a dialog box for data entry
 *
 *  This function creates a brand new instance of the dialog each time
 *  it is called.
 *
 *  \todo Add error checking
 *
 *  \param [in] factory  The factory to create the dialog
 *  \param [in] filename The XML file describing the UI
 *  \return A pointer to the new dialog box
 */
GPFormUIDialog*
gpform_factory_create_form(const GPFormFactory *factory, const char *filename);

/*! \brief Get the id for the UI object
 *
 *  The caller must use g_free when the string is no longer needed.
 *
 *  \param [in,out] factory
 *  \return
 */
char*
gpform_factory_get_form_id(const GPFormFactory *factory);

/*! \brief Get the path to the image files
 *
 *  The caller must use g_free when the string is no longer needed.
 *
 *  \param [in,out] factory
 *  \return
 */
char*
gpform_factory_get_image_path(const GPFormFactory *factory);


/*! \brief Get the path to the XML UI files
 *
 *  The caller must use g_free when the string is no longer needed.
 *
 *  \param [in,out] factory
 *  \return
 */
char*
gpform_factory_get_xml_path(const GPFormFactory *factory);

/*! \brief Create a new form factory
 *
 *  \return A pointer to the new form factory
 */
GPFormFactory*
gpform_factory_new(void);

/*! \brief Set the id for the UI object
 *
 *  \param [in,out] factory
 *  \param [in]     form_id
 */
void
gpform_factory_set_form_id(GPFormFactory *factory, const char *form_id);

/*! \brief Set the path to the image files
 *
 *  \param [in,out] factory
 *  \param [in]     image_path
 */
void
gpform_factory_set_image_path(GPFormFactory *factory, const char *image_path);

/*! \brief Set the path to the XML UI files
 *
 *  \param [in,out] factory
 *  \param [in]     xml_path
 */
void
gpform_factory_set_xml_path(GPFormFactory *factory, const char *xml_path);

