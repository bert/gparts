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

/*! \file gpform-ui-label.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "misc-object.h"

#include "gpform.h"

#define GPFORM_UI_COMBO_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPFORM_TYPE_UI_COMBO,GPFormUIComboPrivate))

enum
{
    GPFORM_UI_COMBO_MODEL_NAME = 1
};

typedef struct _GPFormUIComboPrivate GPFormUIComboPrivate;

struct _GPFormUIComboPrivate
{
    gchar *model_name;
};



static void
gpform_ui_combo_class_init(gpointer g_class, gpointer g_class_data);

static void
gpform_ui_combo_dispose(GObject *object);

static void
gpform_ui_combo_finalize(GObject *object);

static void
gpform_ui_combo_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpform_ui_combo_init(GTypeInstance *instance, gpointer g_class);

static void
gpform_ui_combo_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
gpform_ui_combo_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(GPFormUIComboPrivate));

    klasse->dispose  = gpform_ui_combo_dispose;
    klasse->finalize = gpform_ui_combo_finalize;

    klasse->get_property = gpform_ui_combo_get_property;
    klasse->set_property = gpform_ui_combo_set_property;

    g_object_class_install_property(
        klasse,
        GPFORM_UI_COMBO_MODEL_NAME,
        g_param_spec_string(
            "model-name",
            "Model Name",
            "Model Name",
            NULL,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
gpform_ui_combo_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}

static void
gpform_ui_combo_finalize(GObject *object)
{
    GPFormUIComboPrivate *privat = GPFORM_UI_COMBO_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_free(privat->model_name);
        privat->model_name = NULL;
    }

    misc_object_chain_finalize(object);
}

gchar*
gpform_ui_combo_get_model_name(const GPFormUICombo *label)
{
    gchar *model_name = NULL;
    GPFormUIComboPrivate *privat = GPFORM_UI_COMBO_GET_PRIVATE(label);

    if (privat != NULL)
    {
        model_name = g_strdup(privat->model_name);
    }

    return model_name;
}

static void
gpform_ui_combo_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPFormUICombo *label = GPFORM_UI_COMBO(object);

    if (label != NULL)
    {
        switch (property_id)
        {
            case GPFORM_UI_COMBO_MODEL_NAME:
                g_value_take_string(value, gpform_ui_combo_get_model_name(label));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
gpform_ui_combo_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPFormUIComboClass),    /* class_size */
            NULL,                          /* base_init */
            NULL,                          /* base_finalize */
            gpform_ui_combo_class_init,    /* class_init */
            NULL,                          /* class_finalize */
            NULL,                          /* class_data */
            sizeof(GPFormUICombo),         /* instance_size */
            0,                             /* n_preallocs */
            gpform_ui_combo_init,          /* instance_init */
            NULL                           /* value_table */
            };

        type = g_type_register_static(
            GTK_TYPE_COMBO_BOX,
            "GPFormUICombo",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gpform_ui_combo_init(GTypeInstance *instance, gpointer g_class)
{
    GPFormUIComboPrivate *privat = GPFORM_UI_COMBO_GET_PRIVATE(instance);

    if (privat != NULL)
    {
    }
}

GPFormUICombo*
gpform_ui_combo_new(void)
{
    return GPFORM_UI_COMBO(g_object_new(GPFORM_TYPE_UI_COMBO, NULL));
}

void
gpform_ui_combo_set_model_name(GPFormUICombo *label, const gchar *model_name)
{
    GPFormUIComboPrivate *privat = GPFORM_UI_COMBO_GET_PRIVATE(label);

    if (privat != NULL)
    {
        g_free(privat->model_name);

        privat->model_name = g_strdup(model_name);

        g_object_notify(G_OBJECT(label), "model-name");
    }
}

static void
gpform_ui_combo_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPFormUICombo *label = GPFORM_UI_COMBO(object);

    if (label != NULL)
    {
        switch (property_id)
        {
            case GPFORM_UI_COMBO_MODEL_NAME:
                gpform_ui_combo_set_model_name(label, g_value_get_string(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

