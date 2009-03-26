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

#include <glib-object.h>
#include <gmodule.h>

#include "gparts-database-type.h"

#define GPARTS_DATABASE_TYPE_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object, GPARTS_TYPE_DATABASE_TYPE, GPartsDatabaseTypePrivate)

typedef void (*GPartsDatabaseInitFunc)(GPartsDatabaseType *database_type);

typedef struct _GPartsDatabaseTypeNode GPartsDatabaseTypeNode;
typedef struct _GPartsDatabaseTypePrivate GPartsDatabaseTypePrivate;

struct _GPartsDatabaseTypeNode
{
    gchar *name;
    GType type;
    gint  flags;
};

struct _GPartsDatabaseTypePrivate
{
    GArray *modules;
};

static void
gparts_database_type_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_database_type_dispose(GObject *object);

static void
gparts_database_type_finalize(GObject *object);

static void
gparts_database_type_init(GTypeInstance *instance, gpointer g_class);

/**** ****/

void
gparts_database_type_add_type(GPartsDatabaseType *database_type, const gchar *name, GType type, gint flags)
{
    GPartsDatabaseTypeNode node;
    GPartsDatabaseTypePrivate *privat = GPARTS_DATABASE_TYPE_GET_PRIVATE(database_type);

    node.name  = g_strdup(name);
    node.type  = type;
    node.flags = flags;

    g_array_append_val(privat->modules, node);
}

static void
gparts_database_type_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsDatabaseTypePrivate));

    object_class->dispose  = gparts_database_type_dispose;
    object_class->finalize = gparts_database_type_finalize;

    ((GPartsDatabaseTypeClass*)object_class)->add_type = gparts_database_type_add_type;
}

static void
gparts_database_type_dispose(GObject *object)
{
}

static void
gparts_database_type_finalize(GObject *object)
{
    GPartsDatabaseTypePrivate *privat = GPARTS_DATABASE_TYPE_GET_PRIVATE(object);

    g_array_free(privat->modules, TRUE);
}

gboolean
gparts_database_type_get_flags(GPartsDatabaseType *database_type, const gchar *name, gint *flags)
{
    gint index;
    GPartsDatabaseTypePrivate *privat = GPARTS_DATABASE_TYPE_GET_PRIVATE(database_type);

    for (index=0; index<privat->modules->len; index++)
    {
        GPartsDatabaseTypeNode *node = &g_array_index(privat->modules, GPartsDatabaseTypeNode, index);

        if (g_strcmp0(name, node->name) == 0)
        {
            *flags = node->flags;
            return TRUE;
        }
    }

    *flags = 0;
    return FALSE;
}

GType
gparts_database_type_get_type(void)
{
    static GType type = 0;

    if (type == 0)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsDatabaseTypeClass),
            NULL,
            NULL,
            gparts_database_type_class_init,
            NULL,
            NULL,
            sizeof(GPartsDatabaseType),
            0,
            gparts_database_type_init,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPartsDatabaseType",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gparts_database_type_init(GTypeInstance* instance, gpointer g_class)
{
    GPartsDatabaseTypePrivate *privat = GPARTS_DATABASE_TYPE_GET_PRIVATE(instance);

    privat->modules = g_array_new(FALSE, FALSE, sizeof(GPartsDatabaseTypeNode));
}


void
gparts_database_type_load_module(GPartsDatabaseType *database_type, const gchar *name, GError **error)
{
    GModule *module;
    GPartsDatabaseTypePrivate *privat = GPARTS_DATABASE_TYPE_GET_PRIVATE(database_type);

    module = g_module_open(name, G_MODULE_BIND_LOCAL);

    if (module == NULL)
    {
        g_warning("%s", g_module_error());
    }
    else
    {
        GPartsDatabaseInitFunc init_func;
        gboolean success;

        g_array_append_val(privat->modules, module);

        success = g_module_symbol(module, "gparts_database_register", (gpointer*) &init_func);

        if (success == FALSE)
        {
            g_warning("%s", g_module_error());
        }
        else if (init_func == NULL)
        {
            g_warning("%s", g_module_error());
        }
        else
        {
            init_func(database_type);
        }
    }
}

GPartsDatabaseType*
gparts_database_type_new(void)
{
    return g_object_new(GPARTS_TYPE_DATABASE_TYPE, NULL);
}


