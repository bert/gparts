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

/*! \file gparts-controller.c
 */

#include <gtk/gtk.h>

#include "gparts-database-result.h"
#include "gparts-database.h"

#include "gparts.h"


static void
gparts_controller_set_copy_action_base(GPartsController *controller, GtkAction *action);

static void
gparts_controller_set_delete_action_base(GPartsController *controller, GtkAction *action);

static void
gparts_controller_set_edit_action_base(GPartsController *controller, GtkAction *action);

static void
gparts_controller_set_insert_action_base(GPartsController *controller, GtkAction *action);

static void
gparts_controller_set_paste_action_base(GPartsController *controller, GtkAction *action);



static void
gparts_controller_class_init(gpointer g_class, gpointer g_class_data)
{
    GPartsControllerClass *klasse = GPARTS_CONTROLLER_CLASS(g_class);

    klasse->set_copy_action   = gparts_controller_set_copy_action_base;
    klasse->set_delete_action = gparts_controller_set_delete_action_base;
    klasse->set_edit_action   = gparts_controller_set_edit_action_base;
    klasse->set_insert_action = gparts_controller_set_insert_action_base;
    klasse->set_paste_action  = gparts_controller_set_paste_action_base;
}

gchar*
gparts_controller_get_field(GPartsController *controller, const gchar *name)
{
    gchar *field = NULL;

    if (controller != NULL)
    {
        GPartsControllerClass *klasse = GPARTS_CONTROLLER_GET_CLASS(controller);

        if ((klasse != NULL) && (klasse->get_field != NULL))
        {
            field = klasse->get_field(controller, name);
        }
    }

    return field;
}

GHashTable*
gparts_controller_get_table(GPartsController *controller)
{
    GHashTable *table = NULL;

    if (controller != NULL)
    {
        GPartsControllerClass *klasse = GPARTS_CONTROLLER_GET_CLASS(controller);

        if ((klasse != NULL) && (klasse->get_table != NULL))
        {
            table = klasse->get_table(controller);
        }
    }

    return table;
}

GType
gparts_controller_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsControllerClass),    /* class_size */
            NULL,                             /* base_init */
            NULL,                             /* base_finalize */
            gparts_controller_class_init,     /* class_init */
            NULL,                             /* class_finalize */
            NULL,                             /* class_data */
            sizeof(GPartsController),         /* instance_size */
            0,                                /* n_preallocs */
            NULL,                             /* instance_init */
            NULL                              /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPartsController",
            &tinfo,
            G_TYPE_FLAG_ABSTRACT
            );
    }

    return type;
}

void
gparts_controller_set_copy_action(GPartsController *controller, GtkAction *action)
{
    if (controller != NULL)
    {
        GPartsControllerClass *klasse = GPARTS_CONTROLLER_GET_CLASS(controller);

        if ((klasse != NULL) && (klasse->set_copy_action != NULL))
        {
            klasse->set_copy_action(controller, action);
        }
    }
}

static void
gparts_controller_set_copy_action_base(GPartsController *controller, GtkAction *action)
{
    if (action != NULL)
    {
        gtk_action_set_label(action, "_Copy");
        gtk_action_set_sensitive(action, FALSE);
    }
}

void
gparts_controller_set_delete_action(GPartsController *controller, GtkAction *action)
{
    if (controller != NULL)
    {
        GPartsControllerClass *klasse = GPARTS_CONTROLLER_GET_CLASS(controller);

        if ((klasse != NULL) && (klasse->set_delete_action != NULL))
        {
            klasse->set_delete_action(controller, action);
        }
    }
}

static void
gparts_controller_set_delete_action_base(GPartsController *controller, GtkAction *action)
{
    if (action != NULL)
    {
        gtk_action_set_label(action, "Delete");
        gtk_action_set_sensitive(action, FALSE);
    }
}

void
gparts_controller_set_edit_action(GPartsController *controller, GtkAction *action)
{
    if (controller != NULL)
    {
        GPartsControllerClass *klasse = GPARTS_CONTROLLER_GET_CLASS(controller);

        if ((klasse != NULL) && (klasse->set_edit_action != NULL))
        {
            klasse->set_edit_action(controller, action);
        }
    }
}

static void
gparts_controller_set_edit_action_base(GPartsController *controller, GtkAction *action)
{
    if (action != NULL)
    {
        gtk_action_set_label(action, "Edit");
        gtk_action_set_sensitive(action, FALSE);
    }
}


void
gparts_controller_set_insert_action(GPartsController *controller, GtkAction *action)
{
    if (controller != NULL)
    {
        GPartsControllerClass *klasse = GPARTS_CONTROLLER_GET_CLASS(controller);

        if ((klasse != NULL) && (klasse->set_insert_action != NULL))
        {
            klasse->set_insert_action(controller, action);
        }
    }
}

static void
gparts_controller_set_insert_action_base(GPartsController *controller, GtkAction *action)
{
    if (action != NULL)
    {
        gtk_action_set_label(action, "Insert");
        gtk_action_set_sensitive(action, FALSE);
    }
}

void
gparts_controller_set_paste_action(GPartsController *controller, GtkAction *action)
{
    if (controller != NULL)
    {
        GPartsControllerClass *klasse = GPARTS_CONTROLLER_GET_CLASS(controller);

        if ((klasse != NULL) && (klasse->set_paste_action != NULL))
        {
            klasse->set_paste_action(controller, action);
        }
    }
}

static void
gparts_controller_set_paste_action_base(GPartsController *controller, GtkAction *action)
{
    if (action != NULL)
    {
        gtk_action_set_label(action, "_Paste");
        gtk_action_set_sensitive(action, FALSE);
    }
}

