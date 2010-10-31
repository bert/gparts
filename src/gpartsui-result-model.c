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

/*! \file gpartsui-action-model.c
 */

#include "gpartsui.h"

#define GPARTSUI_RESULT_MODEL_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTSUI_TYPE_RESULT_MODEL,GPartsUIResultModelPrivate)

enum
{
    GPARTSUI_RESULT_MODEL_RESULT = 1,
    GPARTSUI_RESULT_MODEL_SELECTED_ROW
};

typedef struct _GPartsUIResultModelPrivate GPartsUIResultModelPrivate;

struct _GPartsUIResultModelPrivate
{
    GPartsDatabaseResult *result;
    guint                selected_row;
};



static void
gpartsui_result_model_class_init(gpointer g_class, gpointer g_class_data);

static void
gpartsui_result_model_dispose(GObject *object);

static void
gpartsui_result_model_finalize(GObject *object);

static void
gpartsui_result_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpartsui_result_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
gpartsui_result_model_class_init(gpointer g_class, gpointer g_class_data)
{
    GPartsUIResultModelClass *klasse = GPARTSUI_RESULT_MODEL_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsUIResultModelPrivate));

    klasse->parent.dispose  = gpartsui_result_model_dispose;
    klasse->parent.finalize = gpartsui_result_model_finalize;

    klasse->parent.get_property = gpartsui_result_model_get_property;
    klasse->parent.set_property = gpartsui_result_model_set_property;

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        GPARTSUI_RESULT_MODEL_RESULT,
        g_param_spec_object(
            "result",
            "Result",
            "Result",
            GPARTS_TYPE_DATABASE_RESULT,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        G_OBJECT_CLASS(klasse),
        GPARTSUI_RESULT_MODEL_SELECTED_ROW,
        g_param_spec_uint(
            "selected-row",
            "Selected Row",
            "Selected Row",
            0,
            G_MAXUINT,
            G_MAXUINT,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpartsui_result_model_dispose(GObject *object)
{
    gpartsui_result_model_set_result(GPARTSUI_RESULT_MODEL(object), NULL);

    misc_object_chain_dispose(object);
}

static void
gpartsui_result_model_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

GStrv
gpartsui_result_model_get_selected_fields(const GPartsUIResultModel *model, guint column)
{
    GStrv fields = NULL;

    if (model != NULL)
    {
        GPartsUIResultModelPrivate *privat = GPARTSUI_RESULT_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            GPtrArray *temp = g_ptr_array_new();

            g_ptr_array_add(temp, g_strdup("http://www.bourns.com"));

            g_ptr_array_add(temp, NULL);

            fields = g_ptr_array_free(temp, FALSE);
        }
    }

    return fields;
}

static void
gpartsui_result_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsUIResultModel *model = GPARTSUI_RESULT_MODEL(object);

    switch (property_id)
    {
        case GPARTSUI_RESULT_MODEL_RESULT:
            g_value_take_object(value, gpartsui_result_model_get_result(model));
            break;

        case GPARTSUI_RESULT_MODEL_SELECTED_ROW:
            g_value_set_uint(value, gpartsui_result_model_get_selected_row(model));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GPartsDatabaseResult*
gpartsui_result_model_get_result(const GPartsUIResultModel *model)
{
    GPartsUIResultModelPrivate *privat = GPARTSUI_RESULT_MODEL_GET_PRIVATE(model);
    GPartsDatabaseResult *result = NULL;

    if (privat != NULL)
    {
        result = privat->result;

        if (result != NULL)
        {
            g_object_ref(result);
        }
    }

    return result;
}

guint
gpartsui_result_model_get_selected_row(const GPartsUIResultModel *model)
{
    guint selected_row = G_MAXUINT;

    if (model != NULL)
    {
        GPartsUIResultModelPrivate *privat = GPARTSUI_RESULT_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            selected_row = privat->selected_row;
        }
    }

    return selected_row;
}

GType
gpartsui_result_model_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsUIResultModelClass),    /* class_size */
            NULL,                                /* base_init */
            NULL,                                /* base_finalize */
            gpartsui_result_model_class_init,    /* class_init */
            NULL,                                /* class_finalize */
            NULL,                                /* class_data */
            sizeof(GPartsUIResultModel),         /* instance_size */
            0,                                   /* n_preallocs */
            NULL,                                /* instance_init */
            NULL                                 /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPartsUIResultModel",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gpartsui_result_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsUIResultModel *model = GPARTSUI_RESULT_MODEL(object);

    switch (property_id)
    {
        case GPARTSUI_RESULT_MODEL_RESULT:
            gpartsui_result_model_set_result(model, g_value_get_object(value));
            break;

        case GPARTSUI_RESULT_MODEL_SELECTED_ROW:
            gpartsui_result_model_set_selected_row(model, g_value_get_uint(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
gpartsui_result_model_set_result(GPartsUIResultModel *model, GPartsDatabaseResult *result)
{
    GPartsUIResultModelPrivate *privat = GPARTSUI_RESULT_MODEL_GET_PRIVATE(model);

    if (privat != NULL)
    {
        if (privat->result != NULL)
        {
            g_object_unref(privat->result);
        }

        privat->result = result;

        if (privat->result != NULL)
        {
            g_object_ref(privat->result);
        }

        g_object_notify(G_OBJECT(model), "result");
    }
}

void
gpartsui_result_model_set_selected_row(const GPartsUIResultModel *model, guint selected_row)
{
    if (model != NULL)
    {
        GPartsUIResultModelPrivate *privat = GPARTSUI_RESULT_MODEL_GET_PRIVATE(model);

        if (privat != NULL)
        {
            privat->selected_row = selected_row;

            g_object_notify(G_OBJECT(model), "selected-row");
        }
    }
}

