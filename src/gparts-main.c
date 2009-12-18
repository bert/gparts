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

#include <gtk/gtk.h>

#include "misc-object.h"

#include "gparts-main.h"
#include "gparts-database-result.h"
#include "gparts-database.h"
#include "gparts-result-model.h"
#include "gparts-category-model.h"
#include "gparts-preview.h"

#include "gparts-mysql-database.h"

#include "gparts-customize-ctrl.h"
#include "gparts-login-ctrl.h"

#include "gparts-result-controller.h"
#include "gparts-category-controller.h"
#include "gparts-object-list.h"
#include "gparts-result-view.h"

#define GPARTS_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object, GPARTS_TYPE, GPartsPrivate)

typedef struct _GPartsPrivate GPartsPrivate;

struct _GPartsPrivate
{
    GtkBuilder       *builder;
    GPartsObjectList *controllers;
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

/**** Signal handlers ****/

static void
gparts_action_edit_preferences_cb(GtkWidget* widget, gpointer data);

static void
gparts_destroy_cb(GtkWidget* widget, gpointer data);

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

    GPARTS_TYPE_PREVIEW;
    //GPARTS_TYPE_RESULT_TREE;
    GPARTS_TYPE_OBJECT_LIST;
    GPARTS_TYPE_RESULT_VIEW;

    private->builder = gtk_builder_new();

    status = gtk_builder_add_from_file(
        private->builder,
        "gparts.xml",
        &error
        );

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

        //"customize-dialog", NULL,

    gtk_widget_show(widget);
}

int main(int argc, char* argv[])
{
    GParts *gparts;

    g_type_init();
    gtk_init(&argc, &argv);

    gparts = gparts_new();

    gtk_main();

    return 0;
}
