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

/*! \file gparts-database-type.h
 *
 *  \brief A database_type for database support modules.
 */

#define GPARTS_DATABASE_TYPE_FLAGS_USES_USERNAME (1 << 0)
#define GPARTS_DATABASE_TYPE_FLAGS_USES_PASSWORD (1 << 1)
#define GPARTS_DATABASE_TYPE_FLAGS_USES_SERVER   (1 << 2)
#define GPARTS_DATABASE_TYPE_FLAGS_USES_DATABASE (1 << 3)
#define GPARTS_DATABASE_TYPE_FLAGS_USES_FILENAME (1 << 4)

#define GPARTS_TYPE_DATABASE_TYPE (gparts_database_type_get_type())
#define GPARTS_DATABASE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_DATABASE_TYPE,GPartsDatabaseType))
#define GPARTS_DATABASE_TYPE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_DATABASE_TYPE,GPartsDatabaseTypeClass))
#define GPARTS_IS_DATABASE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_DATABASE_TYPE))
#define GPARTS_IS_DATABASE_TYPE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_DATABASE_TYPE))
#define GPARTS_DATABASE_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_DATABASE_TYPE,GPartsDatabaseTypeClass))

struct _GPartsDatabaseType
{
    GObject parent;
};

/*! \private */
struct _GPartsDatabaseTypeClass
{
    GObjectClass parent;

    void (*add_factory)(GPartsDatabaseType *database_type, GPartsDatabaseFactory *factory);
};

/*! \private */
GType
gparts_database_type_get_type(void);

/*! \brief Register a database support module
 *
 *  \param [in] database_type The database database_type to store the information.
 *  \param [in] factory
 *
 *  To prevent back-linking, do not call this function from the database
 *  module.  Call this function using the function pointer in the class
 *  structure.
 */
void
gparts_database_type_add_factory(GPartsDatabaseType *database_type, GPartsDatabaseFactory *factory);

/*! \brief Get a database factory by name
 *
 *  The name passed in should match one of the names returned by
 *  gparts_database_type_get_type_names().
 *
 *  When no longer needed, call g_object_unref() on the returned pointer.
 *
 *  \param [in] database_type
 *  \param [in] name          The name of the database factory.
 */
GPartsDatabaseFactory*
gparts_database_type_get_factory(GPartsDatabaseType *database_type, const gchar *name);

/*! \brief Get a list of names for the database factories.
 *
 *  When no longer needed, call g_strfreev() on the returned pointer.
 *
 *  \param [in] database_type
 *  \return A null terminated list of strings.
 */
gchar**
gparts_database_type_get_type_names(GPartsDatabaseType *database_type);

/*! \brief Load and register a database module.
 *
 *  \param [in]  database_type
 *  \param [in]  name          The filename of the module
 *  \param [out] error         The error, if any, using the GError protocol
 */
void
gparts_database_type_load_module(GPartsDatabaseType *database_type, const gchar *name, GError **error);

/*! \brief
 */
GPartsDatabaseType*
gparts_database_type_new();

