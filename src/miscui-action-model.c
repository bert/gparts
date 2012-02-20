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

/*! \file miscui-action-model.c
 */

#include "miscui.h"

#define MISCUI_ACTION_MODEL_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,MISCUI_TYPE_ACTION_MODEL,MiscUIActionModelPrivate)

enum
{
    MISCUI_ACTION_MODEL_FUNCTION = 1,
    MISCUI_ACTION_MODEL_LABEL,
    MISCUI_ACTION_MODEL_OBJECT,
    MISCUI_ACTION_MODEL_SENSITIVE
};

typedef struct _MiscUIActionModelPrivate MiscUIActionModelPrivate;

struct _MiscUIActionModelPrivate
{
    MiscUIActivateFunc function;
    gchar              *label;
    GObject            *object;
    gboolean           sensitive;
};



static void
miscui_action_model_class_init(gpointer g_class, gpointer g_class_data);

static void
miscui_action_model_dispose(GObject *object);

static void
miscui_action_model_finalize(GObject *object);

static void
miscui_action_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
miscui_action_model_set_function(MiscUIActionModel *model, MiscUIActivateFunc *function);

static void
miscui_action_model_set_object(MiscUIActionModel *model, GObject *object);

static void
miscui_action_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



void
miscui_action_model_activate(MiscUIActionModel *model, GError **error)
{
    MiscUIActionModelPrivate *privat = MISCUI_ACTION_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        if (privat->function != NULL)
        {
            privat->function(privat->object, error);
        }
    }
}

static void
miscui_action_model_class_init(gpointer g_class, gpointer g_class_data)
{
    MiscUIActionModelClass *klasse = MISCUI_ACTION_MODEL_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(MiscUIActionModelPrivate));

    klasse->parent.dispose  = miscui_action_model_dispose;
    klasse->parent.finalize = miscui_action_model_finalize;

    klasse->parent.get_property = miscui_action_model_get_property;
    klasse->parent.set_property = miscui_action_model_set_property;

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        MISCUI_ACTION_MODEL_FUNCTION,
        g_param_spec_pointer(
            "function",
            "Function",
            "Function",
            G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        MISCUI_ACTION_MODEL_LABEL,
        g_param_spec_string(
            "label",
            "Label",
            "Label",
            NULL,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        MISCUI_ACTION_MODEL_OBJECT,
        g_param_spec_object(
            "object",
            "Object",
            "Object",
            G_TYPE_OBJECT,
            G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        MISCUI_ACTION_MODEL_SENSITIVE,
        g_param_spec_boolean(
            "sensitive",
            "Sensitive",
            "Sensitive",
            FALSE,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
miscui_action_model_dispose(GObject *object)
{
    miscui_action_model_set_object(MISCUI_ACTION_MODEL(object), NULL);

    misc_object_chain_dispose(object);
}

static void
miscui_action_model_finalize(GObject *object)
{
    MiscUIActionModelPrivate *privat = MISCUI_ACTION_MODEL_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_free(privat->label);
        privat->label = NULL;
    }

    misc_object_chain_finalize(object);
}

gchar*
miscui_action_model_get_label(const MiscUIActionModel *model)
{
    gchar *label = NULL;

    if (model != NULL)
    {
        MiscUIActionModelPrivate *privat = MISCUI_ACTION_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            label = g_strdup(privat->label);
        }
    }

    return label;
}

gboolean
miscui_action_model_get_sensitive(const MiscUIActionModel *model)
{
    gboolean sensitive = FALSE;

    if (model != NULL)
    {
        MiscUIActionModelPrivate *privat = MISCUI_ACTION_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            sensitive = privat->sensitive;
        }
    }

    return sensitive;
}

static void
miscui_action_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    MiscUIActionModel *model = MISCUI_ACTION_MODEL(object);

    switch (property_id)
    {
        case MISCUI_ACTION_MODEL_LABEL:
            g_value_take_string(value, miscui_action_model_get_label(model));
            break;

        case MISCUI_ACTION_MODEL_SENSITIVE:
            g_value_set_boolean(value, miscui_action_model_get_sensitive(model));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
miscui_action_model_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(MiscUIActionModelClass),    /* class_size */
            NULL,                              /* base_init */
            NULL,                              /* base_finalize */
            miscui_action_model_class_init,    /* class_init */
            NULL,                              /* class_finalize */
            NULL,                              /* class_data */
            sizeof(MiscUIActionModel),         /* instance_size */
            0,                                 /* n_preallocs */
            NULL,                              /* instance_init */
            NULL                               /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "MiscUIActionModel",
            &tinfo,
            0
            );
    }

    return type;
}

static void
miscui_action_model_set_function(MiscUIActionModel *model, MiscUIActivateFunc *function)
{
    MiscUIActionModelPrivate *privat = MISCUI_ACTION_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        privat->function = function;

        g_object_notify(G_OBJECT(model), "function");
    }
}


void
miscui_action_model_set_label(MiscUIActionModel *model, const gchar *label)
{
    MiscUIActionModelPrivate *privat = MISCUI_ACTION_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        g_free(privat->label);
        privat->label = g_strdup(label);

        g_object_notify(G_OBJECT(model), "label");
    }
}

static void
miscui_action_model_set_object(MiscUIActionModel *model, GObject *object)
{
    MiscUIActionModelPrivate *privat = MISCUI_ACTION_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        if (privat->object != NULL)
        {
            g_object_unref(privat->object);
        }

        privat->object = object;

        if (privat->object != NULL)
        {
            g_object_ref(privat->object);
        }

        g_object_notify(G_OBJECT(model), "object");
    }
}

void
miscui_action_model_set_sensitive(MiscUIActionModel *model, gboolean sensitive)
{
    MiscUIActionModelPrivate *privat = MISCUI_ACTION_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        privat->sensitive = sensitive;

        g_object_notify(G_OBJECT(model), "sensitive");
    }
}

static void
miscui_action_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    MiscUIActionModel *model = MISCUI_ACTION_MODEL(object);

    switch (property_id)
    {
        case MISCUI_ACTION_MODEL_FUNCTION:
            miscui_action_model_set_function(model, g_value_get_pointer(value));
            break;

        case MISCUI_ACTION_MODEL_LABEL:
            miscui_action_model_set_label(model, g_value_get_string(value));
            break;

        case MISCUI_ACTION_MODEL_OBJECT:
            miscui_action_model_set_object(model, g_value_get_object(value));
            break;

        case MISCUI_ACTION_MODEL_SENSITIVE:
            miscui_action_model_set_sensitive(model, g_value_get_boolean(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

