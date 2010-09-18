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

/*! \file sch-factory.h
 */

#define SCH_TYPE_FACTORY (sch_factory_get_type())
#define SCH_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_FACTORY,SchFactory))
#define SCH_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_FACTORY,SchFactoryClass))
#define SCH_IS_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_FACTORY))
#define SCH_IS_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_FACTORY))
#define SCH_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_FACTORY,SchFactoryClass))

struct _SchFactory
{
    GObject parent;
};

struct _SchFactoryClass
{
    GObjectClass parent;
};

GType
sch_factory_get_type(void);

/*! \brief Get the configuration used by this factory
 *
 *  \param [in] factory
 *  \return A pointer to the configuration.
 */
SchConfig*
sch_factory_get_config(SchFactory *factory);

/*! \brief Create a new schematic shape factory
 *
 *  \param [in] config
 *  \return A pointer to the new factory
 */
SchFactory*
sch_factory_new(SchConfig *config);

/*! \brief Set the configuration for this factory to use
 *
 *  \param [in] factory
 *  \param [in] config
 */
void
sch_factory_set_config(SchFactory *factory, SchConfig *config);

