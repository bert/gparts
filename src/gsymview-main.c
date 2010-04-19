/* gEDA - GPL Electronic Design Automation
 * gsymview - gEDA Parts Manager
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

#include "sch.h"

#include "schgui-drawing-cfg.h"
#include "schgui-cairo-drafter.h"
#include "schgui-drawing-view.h"

#include "schgui-clipboard.h"

#include "gsymview-main.h"

#include "scmcfg-config.h"

#define GSYMVIEW_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object, GSYMVIEW_TYPE, GSymViewPrivate)

typedef struct _GSymViewPrivate GSymViewPrivate;

struct _GSymViewPrivate
{
    GtkBuilder        *builder;

    SchDrawing        *drawing;

    SchGUIClipboard   *clipboard;
    SchGUIDrawingView *drawing_view;
};

/**** Static methods ****/

static void
gsymview_instance_init(GTypeInstance *instance, gpointer g_class);

static void
gsymview_dispose(GObject *object);

static void
gsymview_finalize(GObject *object);

/**** Signal handlers ****/

static void
gsymview_selection_changed_cb(GtkFileChooser *chooser, gpointer user_data);

static void
gsymview_destroy_cb(GtkWidget* widget, gpointer data);





static void
gsymview_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GSymViewPrivate));

    object_class->dispose  = gsymview_dispose;
    object_class->finalize = gsymview_finalize;
}

static void
gsymview_dispose(GObject *object)
{
    GSymViewPrivate *privat = GSYMVIEW_GET_PRIVATE(object);

    if (privat != NULL)
    {
        if (privat->builder != NULL)
        {
            g_object_unref(privat->builder);
            privat->builder = NULL;
        }
    }

    misc_object_chain_dispose(object);
}

static void
gsymview_finalize(GObject *object)
{
    misc_object_chain_finalize(object);
}

GType
gsymview_get_type( void )
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo info = {
            sizeof(GSymViewClass),
            NULL,
            NULL,
            gsymview_class_init,
            NULL,
            NULL,
            sizeof(GSymView),
            0,
            gsymview_instance_init,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gsymview",
            &info,
            0
            );
    }

    return type;
}

GSymView *gsymview_new(void)
{
    return g_object_new(GSYMVIEW_TYPE, NULL);
}

static void
gsymview_copy_cb(GtkWidget* widget, gpointer data)
{
    GSymViewPrivate *privat = GSYMVIEW_GET_PRIVATE(data);

    if ((privat != NULL) && (privat->clipboard != NULL) && (privat->drawing != NULL))
    {
        g_debug("Edit copy");
        
        schgui_clipboard_copy_drawing(privat->clipboard, privat->drawing);
    }
}

static void
gsymview_destroy_cb(GtkWidget* widget, gpointer data)
{
    g_object_unref(G_OBJECT(data));

    gtk_main_quit();
}

static void
gsymview_selection_changed_cb(GtkFileChooser *chooser, gpointer user_data)
{
    GSymViewPrivate *privat = GSYMVIEW_GET_PRIVATE(user_data);

    if (privat != NULL)
    {
        gchar *filename = NULL;

        if (privat->drawing != NULL)
        {
            g_object_unref(privat->drawing);

            privat->drawing = NULL;
        }

        if (chooser != NULL)
        {
            filename = gtk_file_chooser_get_filename(chooser);
        }

        if (filename != NULL)
        {
            SchLoader *loader = sch_loader_get_default();

            privat->drawing = sch_loader_load_drawing(loader, filename, NULL);

            g_free(filename);
        }

        schgui_drawing_view_set_drawing(privat->drawing_view, privat->drawing);
    }
}


static void
gsymview_instance_init(GTypeInstance* instance, gpointer g_class)
{
    GtkAction *action;
    GError* error = NULL;
    guint status;
    GSymViewPrivate *private = GSYMVIEW_GET_PRIVATE(instance);
    SchGUICairoDrafter *drafter;
    char *datadir = scmcfg_dirs_find_gparts_data();
    char *path = g_build_filename(datadir, "xml", "gsymview.xml", NULL);
    g_free(datadir);

    SCHGUI_TYPE_DRAWING_VIEW;

    private->builder = gtk_builder_new();
    private->clipboard = schgui_clipboard_new();


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

    private->drawing_view = G_OBJECT(gtk_builder_get_object(private->builder, "preview-view"));


    GtkWidget *widget = GTK_WIDGET(gtk_builder_get_object(private->builder, "main"));

    g_signal_connect(
        G_OBJECT(gtk_builder_get_object(private->builder, "preview-file")),
        "selection-changed",
        G_CALLBACK(gsymview_selection_changed_cb),
        instance
        );

    g_signal_connect(
        G_OBJECT(gtk_builder_get_object(private->builder, "edit-copy")),
        "activate",
        G_CALLBACK(gsymview_copy_cb),
        instance
        );

    g_signal_connect(
        G_OBJECT(widget),
        "destroy",
        G_CALLBACK(gsymview_destroy_cb),
        instance
        );

    gtk_widget_show(widget);
}

int main(int argc, char* argv[])
{
    GSymView *gsymview;

    g_type_init();
    gtk_init(&argc, &argv);

    scmcfg_config_init();
    scmcfg_config_load();

    gsymview = gsymview_new();

    gtk_main();

    return 0;
}

