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

/*! \file gparts-database_type.h
 *
 *  \brief A database_type for database support modules.
 */

#define GPARTS_TYPE_DATABASE_TYPE (gparts_database_type_get_type())
#define GPARTS_DATABASE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_DATABASE_TYPE,GPartsDatabaseType))
#define GPARTS_DATABASE_TYPE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_DATABASE_TYPE,GPartsDatabaseTypeClass))
#define GPARTS_IS_DATABASE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_DATABASE_TYPE))
#define GPARTS_IS_DATABASE_TYPE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_DATABASE_TYPE))
#define GPARTS_DATABASE_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_DATABASE_TYPE,GPartsDatabaseTypeClass))

#define GPARTS_DATABASE_TYPE_FLAGS_USES_USERNAME (1 << 0)
#define GPARTS_DATABASE_TYPE_FLAGS_USES_PASSWORD (1 << 1)
#define GPARTS_DATABASE_TYPE_FLAGS_USES_SERVER   (1 << 2)
#define GPARTS_DATABASE_TYPE_FLAGS_USES_DATABASE (1 << 3)
#define GPARTS_DATABASE_TYPE_FLAGS_USES_FILENAME (1 << 4)

typedef struct _GPartsDatabaseType GPartsDatabaseType;
typedef struct _GPartsDatabaseTypeClass GPartsDatabaseTypeClass;

struct _GPartsDatabaseType
{
    GObject parent;
};

struct _GPartsDatabaseTypeClass
{
    GObjectClass parent;

    void (*add_type)(GPartsDatabaseType *database_type, const gchar *name, GType type, gint flags);
};

GType
gparts_database_type_get_type(void);

GPartsDatabaseType*
gparts_database_type_new();

void
gparts_database_type_load_module(GPartsDatabaseType *database_type, const gchar *name, GError **error);

/*! \brief Register a database support module
 *
 *  \param [in] database_type The database database_type to store the information.
 *  \param [in] name The name of the support module.
 *  \param [in] type The GType to instantiate an instance of the module.
 *  \param [in] flags
 *
 *  To prevent back-linking, do not call this function from the database
 *  module.  Call this function using the function pointer in the class
 *  structure.
 */
void
gparts_database_type_add_type(GPartsDatabaseType *database_type, const gchar *name, GType type, gint flags);

gboolean
gparts_database_type_get_flags(GPartsDatabaseType *database_type, const gchar *name, gint *flags);

