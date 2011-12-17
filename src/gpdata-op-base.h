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

/*! \file gpdata-op-base.h
 */

#define GPDATA_TYPE_OP_BASE (gpdata_op_base_get_type())
#define GPDATA_OP_BASE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPDATA_TYPE_OP_BASE,GPDataOPBase))
#define GPDATA_OP_BASE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPDATA_TYPE_OP_BASE,GPDataOPBaseClass))
#define GPDATA_IS_OP_BASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPDATA_TYPE_OP_BASE))
#define GPDATA_IS_OP_BASE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPDATA_TYPE_OP_BASE))
#define GPDATA_OP_BASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPDATA_TYPE_OP_BASE,GPDataOPBaseClass))

/*! \extends GObject
 */
struct _GPDataOPBase
{
    GObject parent;
};

/*! \private
 */
struct _GPDataOPBaseClass
{
    GObjectClass parent;

    void (*check)(GPDataOPBase *base, xmlTextReader *reader, GError **error);
    void (*parse)(GPDataOPBase *base, xmlTextReader *reader, GPDataOPBuildable *object, GError **error);
};

/*! \private */
GType
gpdata_op_base_get_type(void);

/*! \brief Check if the xmlTextReader is in the correct state for parsing
 *
 *  \param [in,out] base
 *  \param [in,out] reader
 *  \param [in,out] error
 */
void
gpdata_op_base_check(GPDataOPBase *base, xmlTextReader *reader, GError **error);

/*! \brief Get the XML element name
 *
 *  \param [in,out] base
 *  \return The name of the XML element [transfer full]
 */
gchar*
gpdata_op_base_get_xml_name(const GPDataOPBase *base);

/*! \brief Parse the object from the xmlTextReader
 *
 *  \param [in,out] base
 *  \param [in,out] reader
 *  \param [in,out] object
 *  \param [in,out] error
 */
void
gpdata_op_base_parse(GPDataOPBase *base, xmlTextReader *reader, GPDataOPBuildable *object, GError **error);

/*! \brief Set the XML element name
 *
 *  \param [in,out] base
 *  \param [in]     name
 */
void
gpdata_op_base_set_xml_name(GPDataOPBase *base, const gchar *name);

