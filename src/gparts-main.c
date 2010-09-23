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

/*! \file gparts-main.c
 */

#include <gtk/gtk.h>

#include "gparts.h"

#include "scmcfg-config.h"

#define GPARTS_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object, GPARTS_TYPE, GPartsPrivate)

typedef struct _GPartsPrivate GPartsPrivate;

struct _GPartsPrivate
{
    GtkBuilder       *builder;
    GPartsObjectList *controllers;

    GSList           *controllers2;

    GtkNotebook      *notebook;

    GtkAction        *copy_action;
    GtkAction        *refresh_action;

    GPartsController *current_controller;

    /* A temporary measure to map GtkNotebook pages to their respective
     * GPartsControllers.
     */
    GPartsController *kludge[9];
};

/**** Static methods ****/

static void
gparts_instance_init(GTypeInstance *instance, gpointer g_class);

static void
gparts_dispose(GObject *object);

static void
gparts_finalize(GObject *object);

static void
gparts_set_database(GParts *gparts, GPartsDatabase *database);

static void
gparts_set_notebook(GParts *gparts, GtkNotebook *notebook);

/**** Signal handlers ****/

static void
gparts_action_edit_preferences_cb(GtkWidget* widget, gpointer data);

static void
gparts_set_copy_action(GParts *gparts, GtkAction *action);

static void
gparts_set_current_controller(GParts *gparts, GPartsController *controller);

static void
gparts_set_refresh_action(GParts *gparts, GtkAction *action);

static void
gparts_destroy_cb(GtkWidget* widget, gpointer data);

static void
gparts_switch_page_cb(GtkNotebook *notebook, GtkNotebookPage *page, gint page_no, gpointer user_data);



static void
gparts_append_controller(GParts *gparts, GObject *object)
{
    if (object != NULL)
    {
        GPartsPrivate *privat = GPARTS_GET_PRIVATE(gparts);

        if (privat != NULL)
        {
            if (g_slist_find(privat->controllers2, object) == NULL)
            {
                privat->controllers2 = g_slist_append(privat->controllers2, object);

                g_object_ref(object);
            }
        }
    }
}

static void
gparts_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsPrivate));

    object_class->dispose      = gparts_dispose;
    object_class->finalize     = gparts_finalize;
}

static void
gparts_destroy_cb(GtkWidget* widget, gpointer data)
{
    g_object_unref(G_OBJECT(data));
    gtk_main_quit();
}

static void
gparts_dispose(GObject *object)
{
    GPartsPrivate *privat = GPARTS_GET_PRIVATE(object);

    g_object_unref(privat->builder);
    g_object_unref(privat->controllers);

    misc_object_chain_dispose(object);
}

static void
gparts_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

GType
gparts_get_type( void )
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo info = {
            sizeof(GPartsClass),
            NULL,
            NULL,
            gparts_class_init,
            NULL,
            NULL,
            sizeof(GParts),
            0,
            gparts_instance_init,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gparts",
            &info,
            0
            );
    }

    return type;
}

GParts *gparts_new(void)
{
    return g_object_new(GPARTS_TYPE, NULL);
}

static void
gparts_instance_init(GTypeInstance* instance, gpointer g_class)
{
    GtkAction *action;
    GError* error = NULL;
    guint status;
    GPartsPrivate *private = GPARTS_GET_PRIVATE(instance);
    char *datadir = scmcfg_dirs_find_gparts_data();
    char *path;

    GPARTS_TYPE_PREVIEW;
    //GPARTS_TYPE_RESULT_TREE;
    GPARTS_TYPE_OBJECT_LIST;
    GPARTS_TYPE_RESULT_VIEW;

    SCHGUI_TYPE_DRAWING_VIEW;

    private->builder = gtk_builder_new();

    path = g_build_filename(datadir, "xml", "gparts.xml", NULL);
    g_free(datadir);

    status = gtk_builder_add_from_file(
        private->builder,
        path,
        &error
        );

    g_free(path);

    if ( status == 0 )
    {
       g_error( error->message ) ;
    }

    gtk_builder_connect_signals(private->builder, NULL);

    GtkWidget *widget = GTK_WIDGET(gtk_builder_get_object(private->builder, "main"));

    g_signal_connect(
        G_OBJECT(widget),
        "destroy",
        G_CALLBACK(gparts_destroy_cb),
        instance
        );


    private->controllers = GPARTS_OBJECT_LIST(gtk_builder_get_object(private->builder, "controllers"));

    /**** Controllers ****/

    GObject *customize_ctrl = g_object_new(
        GPARTS_TYPE_CUSTOMIZE_CTRL,
        "customize-action", GTK_ACTION(gtk_builder_get_object(private->builder, "view-customize")),
        NULL
        );

    GObject *login_ctrl = g_object_new(
        GPARTS_TYPE_LOGIN_CTRL,
        "connect-action",    GTK_ACTION(gtk_builder_get_object(private->builder, "database-connect")),
        "disconnect-action", GTK_ACTION(gtk_builder_get_object(private->builder, "database-disconnect")),
        "refresh-action",    GTK_ACTION(gtk_builder_get_object(private->builder, "view-refresh")),
        NULL
        );

    /**** "High" level controllers ****/

    GObject *category_controller = g_object_new(
        GPARTS_TYPE_CATEGORY_CONTROLLER,
        "database-controller", login_ctrl,
        "target",              GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "category-view")),
        NULL
        );

    GObject *part_controller = g_object_new(
        GPARTS_TYPE_RESULT_CONTROLLER,
        "customize-ctrl", customize_ctrl,
        "database-ctrl",  login_ctrl,
        "edit-action",    GTK_ACTION(gtk_builder_get_object(private->builder, "view-edit")),
        "source",         category_controller,
        "target",         GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "parts-tree-view")),
        "template",       "SELECT * FROM %s",
        "view-name",      "$(ViewName)",
        NULL
        );

    GObject *symbol_controller = g_object_new(
        GPARTS_TYPE_RESULT_CONTROLLER,
        "customize-ctrl", customize_ctrl,
        "database-ctrl",  login_ctrl,
        "source",              part_controller,
        "target",              GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "symbols-tree-view")),
        "template",            "SELECT * FROM %s WHERE DeviceID = $(DeviceID)",
        "view-name",           "SymbolV",
        NULL
        );

    g_object_new(
        GPARTS_TYPE_RESULT_CONTROLLER,
        "customize-ctrl", customize_ctrl,
        "database-ctrl",  login_ctrl,
        "target",              GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "companies-view")),
        "template",            "SELECT * FROM %s",
        "view-name",           "CompanyV",
        NULL
        );

    g_object_new(
        GPARTS_TYPE_RESULT_CONTROLLER,
        "customize-ctrl", customize_ctrl,
        "database-ctrl",  login_ctrl,
        "target",              GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "devices-view")),
        "template",            "SELECT * FROM %s",
        "view-name",           "DeviceV",
        NULL
        );

    g_object_new(
        GPARTS_TYPE_RESULT_CONTROLLER,
        "customize-ctrl", customize_ctrl,
        "database-ctrl",  login_ctrl,
        "target",              GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "documentation-view")),
        "template",            "SELECT * FROM %s",
        "view-name",           "DocumentV",
        NULL
        );

    g_object_new(
        GPARTS_TYPE_RESULT_CONTROLLER,
        "customize-ctrl", customize_ctrl,
        "database-ctrl",  login_ctrl,
        "target",               GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "footprints-view")),
        "template",             "SELECT * FROM %s",
        "view-name",            "FootprintV",
        NULL
        );

    g_object_new(
        GPARTS_TYPE_RESULT_CONTROLLER,
        "customize-ctrl", customize_ctrl,
        "database-ctrl",  login_ctrl,
        "target",               GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "packages-view")),
        "template",             "SELECT * FROM %s",
        "view-name",            "PackageV",
        NULL
        );

    GObject *symbol_controller2 = g_object_new(
        GPARTS_TYPE_RESULT_CONTROLLER,
        "customize-ctrl", customize_ctrl,
        "database-ctrl",  login_ctrl,
        "target",              GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "symbols-view")),
        "template",            "SELECT * FROM %s",
        "view-name",           "SymbolV",
        NULL
        );

    g_object_new(
        GPARTS_TYPE_RESULT_CONTROLLER,
        "customize-ctrl", customize_ctrl,
        "database-ctrl",  login_ctrl,
        "source",              symbol_controller2,
        "target",              GTK_TREE_VIEW(gtk_builder_get_object(private->builder, "symbol-details-view")),
        "template",            "SELECT * FROM %s WHERE SymbolID = $(SymbolID)",
        "view-name",           "SymbolDetail",
        NULL
        );

    private->kludge[5] = g_object_new(
        GPARTS_TYPE_PREVIEW_CTRL,
        "attrib-source", part_controller,
        "symbol-source", symbol_controller,
        "target",        SCHGUI_DRAWING_VIEW(gtk_builder_get_object(private->builder, "parts-graphic-view")),
        NULL
        );

    g_object_new(
        GPARTS_TYPE_PREVIEW_CTRL,
        "symbol-source", symbol_controller2,
        "target",        SCHGUI_DRAWING_VIEW(gtk_builder_get_object(private->builder, "symbols-graphic-view")),
        NULL
        );

    gparts_set_copy_action(
        GPARTS(instance),
        GTK_ACTION(gtk_builder_get_object(private->builder, "edit-copy"))
        );

    gparts_set_refresh_action(
        GPARTS(instance),
        GTK_ACTION(gtk_builder_get_object(private->builder, "view-refresh"))
        );

    gparts_set_notebook(
        GPARTS(instance),
        GTK_NOTEBOOK(gtk_builder_get_object(private->builder, "notebook"))
        );

        //"customize-dialog", NULL,

    gtk_widget_show(widget);
}

static void
gparts_copy_action_cb(GtkAction *action, gpointer user_data)
{
    GPartsPrivate *privat = GPARTS_GET_PRIVATE(user_data);

    if (privat != NULL)
    {
    }
}

static void
gparts_refresh_action_cb(GtkAction *action, gpointer user_data)
{
    GPartsPrivate *privat = GPARTS_GET_PRIVATE(user_data);

    if (privat != NULL)
    {
    }
}

static void
gparts_page_added_cb(GtkNotebook *notebook, GtkWidget *child, gint page_no, gpointer user_data)
{
    g_debug("Page added %d", page_no);
}

static void
gparts_page_removed_cb(GtkNotebook *notebook, GtkWidget *child, gint page_no, gpointer user_data)
{
    g_debug("Page removed %d", page_no);
}

static void
gparts_set_copy_action(GParts *gparts, GtkAction *action)
{
    GPartsPrivate *privat = GPARTS_GET_PRIVATE(gparts);

    if (privat != NULL)
    {
        if (privat->copy_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->copy_action,
                G_CALLBACK(gparts_copy_action_cb),
                gparts
                );

            g_object_unref(privat->copy_action);
        }

        privat->copy_action = action;

        if (privat->copy_action != NULL)
        {
            g_object_ref(privat->copy_action);

            g_signal_connect(
                privat->copy_action,
                "activate",
                G_CALLBACK(gparts_copy_action_cb),
                gparts
                );
        }

        if (privat->current_controller != NULL)
        {
            gparts_controller_set_copy_action(privat->current_controller, privat->copy_action);
        }
        else
        {
            gtk_action_set_label(privat->copy_action, "_Copy");
            gtk_action_set_sensitive(privat->copy_action, FALSE);
        }

        /* g_object_notify(G_OBJECT(gparts), "copy-action"); */
    }
}

static void
gparts_set_refresh_action(GParts *gparts, GtkAction *action)
{
    GPartsPrivate *privat = GPARTS_GET_PRIVATE(gparts);

    if (privat != NULL)
    {
        if (privat->refresh_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->refresh_action,
                G_CALLBACK(gparts_refresh_action_cb),
                gparts
                );

            g_object_unref(privat->refresh_action);
        }

        privat->refresh_action = action;

        if (privat->refresh_action != NULL)
        {
            g_object_ref(privat->refresh_action);

            g_signal_connect(
                privat->refresh_action,
                "activate",
                G_CALLBACK(gparts_refresh_action_cb),
                gparts
                );
        }

        if (privat->current_controller != NULL)
        {
            gparts_controller_set_refresh_action(privat->current_controller, privat->refresh_action);
        }
        else
        {
            gtk_action_set_sensitive(privat->refresh_action, FALSE);
        }

        /* g_object_notify(G_OBJECT(gparts), "copy-action"); */
    }

}


static void
gparts_set_current_controller(GParts *gparts, GPartsController *controller)
{
    GPartsPrivate *privat = GPARTS_GET_PRIVATE(gparts);

    if (privat != NULL)
    {
        if (privat->current_controller != NULL)
        {
            gparts_controller_set_copy_action(privat->current_controller, NULL);

            g_object_unref(privat->current_controller);
        }

        privat->current_controller = controller;

        if (privat->current_controller != NULL)
        {
            g_object_ref(privat->current_controller);

            gparts_controller_set_copy_action(privat->current_controller, privat->copy_action);
        }
        else
        {
            gtk_action_set_label(privat->copy_action, "_Copy");
            gtk_action_set_sensitive(privat->copy_action, FALSE);
        }
    }
}

static void
gparts_set_notebook(GParts *gparts, GtkNotebook *notebook)
{
    GPartsPrivate *privat = GPARTS_GET_PRIVATE(gparts);

    if (privat != NULL)
    {
        if (privat->notebook != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->notebook,
                G_CALLBACK(gparts_page_added_cb),
                gparts
                );

            g_signal_handlers_disconnect_by_func(
                privat->notebook,
                G_CALLBACK(gparts_page_removed_cb),
                gparts
                );

            g_signal_handlers_disconnect_by_func(
                privat->notebook,
                G_CALLBACK(gparts_switch_page_cb),
                gparts
                );

            g_object_unref(privat->notebook);
        }

        privat->notebook = notebook;

        if (privat->notebook != NULL)
        {
            g_object_ref(privat->notebook);

            g_signal_connect(
                privat->notebook,
                "page-added",
                G_CALLBACK(gparts_page_added_cb),
                gparts
                );

            g_signal_connect(
                privat->notebook,
                "page-removed",
                G_CALLBACK(gparts_page_removed_cb),
                gparts
                );

            g_signal_connect(
                privat->notebook,
                "switch-page",
                G_CALLBACK(gparts_switch_page_cb),
                gparts
                );
        }

        /* g_object_notify(G_OBJECT(gparts), "notebook"); */
    }
}

static void
gparts_switch_page_cb(GtkNotebook *notebook, GtkNotebookPage *page, gint page_no, gpointer user_data)
{
    GPartsPrivate *privat = GPARTS_GET_PRIVATE(user_data);

    if (privat != NULL)
    {
        g_debug("Switch page %d", page_no);

        gparts_set_current_controller(GPARTS(user_data), privat->kludge[page_no]);
    }
}

int main(int argc, char* argv[])
{
    GParts *gparts;

    g_type_init();
    gtk_init(&argc, &argv);

    scmcfg_config_init();
    scmcfg_config_load();

    gparts = gparts_new();

    gtk_main();

    return 0;
}

