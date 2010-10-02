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

/*! \file gparts-database-factory.h
 *
 *  \brief An abstract base class for factories that create database interface objects.
 */

#define GPARTS_TYPE_DATABASE_FACTORY (gparts_database_factory_get_type())
#define GPARTS_DATABASE_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_DATABASE_FACTORY,GPartsDatabaseFactory))
#define GPARTS_DATABASE_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_DATABASE_FACTORY,GPartsDatabaseFactoryClass))
#define GPARTS_IS_DATABASE_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_DATABASE_FACTORY))
#define GPARTS_IS_DATABASE_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_DATABASE_FACTORY))
#define GPARTS_DATABASE_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_DATABASE_FACTORY,GPartsDatabaseFactoryClass))

struct _GPartsDatabaseFactory
{
    GObject parent;
};

/*! \private */
struct _GPartsDatabaseFactoryClass
{
    GObjectClass parent;

    GPartsDatabase* (*create_database)(GPartsDatabaseFactory *factory, GError **error);
    gchar* (*get_name)(const GPartsDatabaseFactory *factory);
    gint (*get_flags)(const GPartsDatabaseFactory *factory);
};

/*! \private */
GType
gparts_database_factory_get_type(void);

/*! \brief Create a database interface object
 *
 *  \param [in] factory The factory to create the database.
 *  \return A pointer to the new database interface object.
 */
GPartsDatabase*
gparts_database_factory_create_database(GPartsDatabaseFactory *factory, GError **error);

/*! \brief Get the name of the database for the objects produced.
 *
 *  This function does not return NULL and neither should subclass implementations.
 *  When no longer needed, the caller should free the string uing g_free().
 *
 *  \param [in] factory This factory.
 *  \return A pointer to a string identifying the database.
 */
gchar*
gparts_database_factory_get_name(const GPartsDatabaseFactory *factory);

/*! \brief Get the connect data flags for the database.
 *
 *  These flags indicate which portions of the connect data structure
 *  are used to connect to a database of this type.
 *
 *  \param [in] factory This factory.
 *  \return The connect data flags for the database.
 */
gint
gparts_database_factory_get_flags(const GPartsDatabaseFactory *factory);

