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

#include "misc-object.h"

#include "gparts-state.h"

#define GPARTS_STATE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPARTS_TYPE_STATE,GPartsStatePrivate))

typedef struct _GPartsStatePrivate GPartsStatePrivate;

struct _GPartsStatePrivate
{
    GKeyFile *state;
};

static void
gparts_state_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_state_dispose(GObject *object);

static void
gparts_state_finalize(GObject *object);

static void
gparts_state_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gparts_state_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);


static void
gparts_state_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(object_class, sizeof(GPartsStatePrivate));

    object_class->dispose  = gparts_state_dispose;
    object_class->finalize = gparts_state_finalize;

    object_class->get_property = gparts_state_get_property;
    object_class->set_property = gparts_state_set_property;
}

static void
gparts_state_dispose(GObject *object)
{
    GPartsStatePrivate *privat = GPARTS_STATE_GET_PRIVATE(object);

    misc_object_chain_dispose(object);
}

static void
gparts_state_finalize(GObject *object)
{
    GPartsStatePrivate *privat = GPARTS_STATE_GET_PRIVATE(object);

    if (privat->state != NULL)
    {
        g_key_file_free(privat->state);
    }

    misc_object_chain_finalize(object);
}

static void
gparts_state_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    switch (property_id)
    {
//        case GPARTS_CATEGORY_MODEL_PROPID_DATABASE:
//            gparts_category_model_set_database(object, value);
//            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
gparts_state_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsStateClass),    /* class_size */
            NULL,                        /* base_init */
            NULL,                        /* base_finalize */
            gparts_state_class_init,     /* class_init */
            NULL,                        /* class_finalize */
            NULL,                        /* class_data */
            sizeof(GPartsState),         /* instance_size */
            0,                           /* n_preallocs */
            NULL,                        /* instance_init */
            NULL                         /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPartsState",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gparts_state_init(GTypeInstance* instance, gpointer g_class)
{
}

static void
gparts_state_load(GPartsState *state, const gchar *filename, GError **error)
{
    GKeyFile *key_file = g_key_file_new();
    GPartsStatePrivate *privat = GPARTS_STATE_GET_PRIVATE(state);
    gboolean success;

    success = g_key_file_load_from_file(key_file, filename, G_KEY_FILE_KEEP_COMMENTS, error);

    if (success)
    {
        if (privat->state != NULL)
        {
            g_key_file_free(privat->state);
        }

        privat->state = key_file;
    }
}

static void
gparts_state_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    switch (property_id)
    {
//        case GPARTS_CATEGORY_MODEL_PROPID_DATABASE:
//            gparts_category_model_set_database(object, value);
//            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

