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

/*! \file gparts-result-view.c 
 */

#include <string.h>
#include <gtk/gtk.h>

#include "misc-object.h"

#include "gparts-database-result.h"
#include "gparts-database.h"
#include "gparts-result-model.h"
#include "gparts-result-view.h"

#define GPARTS_RESULT_VIEW_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_RESULT_VIEW,GPartsResultViewPrivate)

enum
{
    GPARTS_RESULT_VIEW_PROPID_DATABASE_CONTROLLER = 1,
    GPARTS_RESULT_VIEW_PROPID_SOURCE,
    GPARTS_RESULT_VIEW_PROPID_TARGET,
    GPARTS_RESULT_VIEW_PROPID_TEMPLATE,
    GPARTS_RESULT_VIEW_PROPID_RESULT_NAME
};

typedef struct _GPartsResultViewPrivate GPartsResultViewPrivate;

struct _GPartsResultViewPrivate
{
    gint                     sort_order;
};

static gchar*
gparts_result_view_build(GPartsResultView *controller);

static void
gparts_result_view_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_result_view_connect_columns(GPartsResultView *controller);

static void
gparts_result_view_database_controller_notify_cb(GPartsDatabase *database, GParamSpec *pspec, GPartsResultView *controller);

static void
gparts_result_view_disconnect_columns(GPartsResultView *controller);

static void
gparts_result_view_dispose(GObject *object);

static void
gparts_result_view_finalize(GObject *object);

static void
gparts_result_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gparts_result_view_set_sort_indicators(GPartsResultView *controller);

static void
gparts_result_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gparts_result_view_set_result(GPartsResultView *query, GPartsDatabaseResult *result);

/**** Signal handlers ****/

static void
gparts_result_view_changed_cb(GtkTreeSelection *selection, GPartsResultView *controller);

static void
gparts_result_view_column_clicked_cb(GtkTreeViewColumn *column, gpointer user_data);

static void
gparts_result_view_database_controller_notify_cb(GPartsDatabase *database, GParamSpec *pspec, GPartsResultView *controller);

static void
gparts_result_view_refresh_cb(gpointer unknown, GPartsResultView *controller);

static void
gparts_result_view_show_cb(GtkWidget *widget, GPartsResultView *controller);

/*  This signal handler responds to changes in this controller's tree view
 *  selection.  It emits the update signal so other controllers monitoring
 *  this controller can update themselves.
 */
static void
gparts_result_view_changed_cb(GtkTreeSelection *widget, GPartsResultView *controller)
{
    g_signal_emit_by_name(controller, "updated");
}

static void
gparts_result_view_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsResultViewPrivate));

    object_class->dispose  = gparts_result_view_dispose;
    object_class->finalize = gparts_result_view_finalize;

//    object_class->get_property = gparts_result_view_get_property;
//    object_class->set_property = gparts_result_view_set_property;
}

static void
gparts_result_view_column_clicked_cb(GtkTreeViewColumn *column, gpointer user_data)
{
}

#if 0
/*  Unsolved Mystery
 *  The column sort indicator and sort order do not appear in the GUI when set
 *  inside this function.
 */
static void
gparts_result_view_connect_columns(GPartsResultView *controller)
{
    GtkTreeViewColumn *column;
    gint index = 0;
    GPartsResultViewPrivate *privat = GPARTS_RESULT_VIEW_GET_PRIVATE(controller);

    column = gtk_tree_view_get_column(privat->target, index++);

    while (column != NULL)
    {
        gtk_tree_view_column_set_clickable(column, TRUE);

        g_signal_connect(
            column,
            "clicked",
            G_CALLBACK(gparts_result_view_column_clicked_cb),
            controller
            );

        column = gtk_tree_view_get_column(privat->target, index++);
    }
}

static void
gparts_result_view_disconnect_columns(GPartsResultView *controller)
{
    GtkTreeViewColumn *column;
    gint index = 0;
    GPartsResultViewPrivate *privat = GPARTS_RESULT_VIEW_GET_PRIVATE(controller);

    column = gtk_tree_view_get_column(privat->target, index++);

    while (column != NULL)
    {
        g_signal_handlers_disconnect_by_func(
            column,
            G_CALLBACK(gparts_result_view_column_clicked_cb),
            controller
            );

        column = gtk_tree_view_get_column(privat->target, index++);
    }
}

#endif
static void
gparts_result_view_dispose(GObject *object)
{
//    GPartsResultView *controller = GPARTS_RESULT_VIEW(object);

   // gparts_result_view_set_database_controller(controller, NULL);
   // gparts_result_view_set_target(controller, NULL);

    misc_object_chain_dispose(object);
}

/*! \brief Deallocate all resources.
 *
 *  This function performs the second and last stage of object destruction.
 *
 *  \param [in] object The object to finalize.
 */
static void
gparts_result_view_finalize(GObject *object)
{
//    GPartsResultViewPrivate *private = GPARTS_RESULT_VIEW_GET_PRIVATE(object);

//    g_free(private->template);
//    g_free(private->view_name);

    misc_object_chain_finalize(object);
}

#if 0
static gchar*
gparts_result_view_get_field(GPartsController *controller, const gchar *name)
{
    GtkTreeIter iter;
    GtkTreeModel *model;
    GPartsResultViewPrivate *privat = GPARTS_RESULT_VIEW_GET_PRIVATE(controller);
    gboolean success;
    gchar *value = NULL;

    success = gtk_tree_selection_get_selected(privat->selection, &model, &iter);

    if (success && GPARTS_IS_RESULT_MODEL(model))
    {
        value = gparts_result_model_get_field(GPARTS_RESULT_MODEL(model), &iter, name);
    }

    return value;
}
#endif

GType
gparts_result_view_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsResultViewClass),    /* class_size */
            NULL,                             /* base_init */
            NULL,                             /* base_finalize */
            gparts_result_view_class_init,    /* class_init */
            NULL,                             /* class_finalize */
            NULL,                             /* class_data */
            sizeof(GPartsResultView),         /* instance_size */
            0,                                /* n_preallocs */
            NULL,                             /* instance_init */
            NULL                              /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            NULL,                                 /* interface_init */
            NULL,                                 /* interface_finalize */
            NULL                                  /* interface_data */
            };

        type = g_type_register_static(
            GTK_TYPE_TREE_VIEW,
            "GPartsResultView",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GTK_TYPE_BUILDABLE, &iinfo);
    }

    return type;
}
#if 0
static void
gparts_result_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
}

static void
gparts_result_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
}
#endif
