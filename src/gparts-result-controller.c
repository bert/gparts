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

/*! \file gparts-result-controller.c
 */

#include <string.h>

#include "gpartsui.h"

#define GPARTS_RESULT_CONTROLLER_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_RESULT_CONTROLLER,GPartsResultControllerPrivate)

enum
{
    GPARTS_RESULT_CONTROLLER_PROPID_CUSTOMIZE_CTRL = 1,
    GPARTS_RESULT_CONTROLLER_PROPID_DATABASE_MODEL,

    GPARTS_RESULT_CONTROLLER_PROPID_SOURCE,
    GPARTS_RESULT_CONTROLLER_PROPID_TARGET,
    GPARTS_RESULT_CONTROLLER_PROPID_TEMPLATE,
    GPARTS_RESULT_CONTROLLER_PROPID_RESULT_NAME,
    GPARTS_RESULT_CONTROLLER_PROPID_EDIT_ACTION
};

typedef struct _GPartsResultControllerPrivate GPartsResultControllerPrivate;

struct _GPartsResultControllerPrivate
{
    GPartsCustomizeCtrl   *customize_ctrl;
    GPartsUIDatabaseModel *database_model;

    GtkTreeSelection      *selection;
    GObject               *source;
    GtkTreeView           *target;
    gchar                 *template;
    gchar                 *view_name;

    GtkAction             *edit_action;

    gchar                 *sort_column;
    gint                  sort_order;
};

static gchar*
gparts_result_controller_build(GPartsResultController *controller);

static void
gparts_result_controller_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_result_controller_connect_columns(GPartsResultController *controller);

static void
gparts_result_controller_database_controller_notify_cb(GPartsDatabase *database, GParamSpec *pspec, GPartsResultController *controller);

static void
gparts_result_controller_disconnect_columns(GPartsResultController *controller);

static void
gparts_result_controller_dispose(GObject *object);

static void
gparts_result_controller_finalize(GObject *object);

static gchar*
gparts_result_controller_get_field(GPartsController *controller, const gchar *name);

static GHashTable*
gparts_result_controller_get_table(GPartsResultController *controller);

static void
gparts_result_controller_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gparts_result_controller_set_sort_indicators(GPartsResultController *controller);

static void
gparts_result_controller_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gparts_result_controller_set_result(GPartsResultController *query, GPartsDatabaseResult *result);

/**** Signal handlers ****/

static void
gparts_result_controller_changed_cb(GtkTreeSelection *selection, GPartsResultController *controller);

static void
gparts_result_controller_column_clicked_cb(GtkTreeViewColumn *column, gpointer user_data);

static void
gparts_result_controller_database_controller_notify_cb(GPartsDatabase *database, GParamSpec *pspec, GPartsResultController *controller);

static void
gparts_result_controller_edit_columns_cb(gpointer unused, GPartsResultController *controller);

static
gparts_result_controller_notify_focus_cb(GtkWidget *widget, GParamSpec *pspec, GPartsResultController *controller);

static gboolean
gparts_result_controller_popup_menu_cb(GtkWidget *widget, GPartsResultController *controller);

static void
gparts_result_controller_refresh_cb(gpointer unknown, GPartsResultController *controller);

static void
gparts_result_controller_show_cb(GtkWidget *widget, GPartsResultController *controller);

/*  This signal handler responds to changes in this controller's tree view
 *  selection.  It emits the update signal so other controllers monitoring
 *  this controller can update themselves.
 */
static void
gparts_result_controller_changed_cb(GtkTreeSelection *widget, GPartsResultController *controller)
{
    g_signal_emit_by_name(controller, "updated");
}

static void
gparts_result_controller_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);
    GPartsControllerClass *klasse = GPARTS_CONTROLLER_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsResultControllerPrivate));

    object_class->dispose  = gparts_result_controller_dispose;
    object_class->finalize = gparts_result_controller_finalize;

    object_class->get_property = gparts_result_controller_get_property;
    object_class->set_property = gparts_result_controller_set_property;

    klasse->get_field = gparts_result_controller_get_field;
    klasse->get_table = gparts_result_controller_get_table;

    g_object_class_install_property(
        object_class,
        GPARTS_RESULT_CONTROLLER_PROPID_DATABASE_MODEL,
        g_param_spec_object(
            "database-model",
            "",
            "",
            GPARTSUI_TYPE_DATABASE_MODEL,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_RESULT_CONTROLLER_PROPID_CUSTOMIZE_CTRL,
        g_param_spec_object(
            "customize-ctrl",
            "",
            "",
            G_TYPE_OBJECT,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_RESULT_CONTROLLER_PROPID_SOURCE,
        g_param_spec_object(
            "source",
            "",
            "",
            G_TYPE_OBJECT,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_RESULT_CONTROLLER_PROPID_TARGET,
        g_param_spec_object(
            "target",
            "",
            "",
            GTK_TYPE_TREE_VIEW,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_RESULT_CONTROLLER_PROPID_TEMPLATE,
        g_param_spec_string(
            "template",
            "",
            "",
            NULL,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_RESULT_CONTROLLER_PROPID_RESULT_NAME,
        g_param_spec_string(
            "view-name",
            "",
            "",
            NULL,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_RESULT_CONTROLLER_PROPID_EDIT_ACTION,
        g_param_spec_object(
            "edit-action",
            "",
            "",
            GTK_TYPE_ACTION,
            G_PARAM_READWRITE
            )
        );


     g_signal_new(
        "updated",
        G_TYPE_FROM_CLASS(object_class),
        G_SIGNAL_RUN_FIRST,
        0,
        NULL,
        NULL,
        g_cclosure_marshal_VOID__VOID,
        G_TYPE_NONE,
        0
        );
}

static void
gparts_result_controller_column_clicked_cb(GtkTreeViewColumn *column, gpointer user_data)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(user_data);

    if (privat->sort_column == NULL)
    {
        privat->sort_column = g_strdup(gtk_tree_view_column_get_title(column));
        privat->sort_order = GTK_SORT_ASCENDING;
    }
    else if (g_strcmp0(privat->sort_column, gtk_tree_view_column_get_title(column)) != 0)
    {
        g_free(privat->sort_column);
        privat->sort_column = g_strdup(gtk_tree_view_column_get_title(column));
        privat->sort_order = GTK_SORT_ASCENDING;
    }
    else if (privat->sort_order == GTK_SORT_ASCENDING)
    {
        privat->sort_order = GTK_SORT_DESCENDING;
    }
    else
    {
        g_free(privat->sort_column);
        privat->sort_column = NULL;
    }

    gparts_result_controller_refresh(user_data);
}

/*  Unsolved Mystery
 *  The column sort indicator and sort order do not appear in the GUI when set
 *  inside this function.
 */
static void
gparts_result_controller_connect_columns(GPartsResultController *controller)
{
    GtkTreeViewColumn *column;
    gint index = 0;
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    column = gtk_tree_view_get_column(privat->target, index++);

    while (column != NULL)
    {
        gtk_tree_view_column_set_clickable(column, TRUE);

        g_signal_connect(
            column,
            "clicked",
            G_CALLBACK(gparts_result_controller_column_clicked_cb),
            controller
            );

        column = gtk_tree_view_get_column(privat->target, index++);
    }
}

static void
gparts_result_controller_database_controller_notify_cb(GPartsDatabase *database, GParamSpec *pspec, GPartsResultController *controller)
{
    gparts_result_controller_refresh(controller);
}

static void
gparts_result_controller_disconnect_columns(GPartsResultController *controller)
{
    GtkTreeViewColumn *column;
    gint index = 0;
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    column = gtk_tree_view_get_column(privat->target, index++);

    while (column != NULL)
    {
        g_signal_handlers_disconnect_by_func(
            column,
            G_CALLBACK(gparts_result_controller_column_clicked_cb),
            controller
            );

        column = gtk_tree_view_get_column(privat->target, index++);
    }
}

static void
gparts_result_controller_dispose(GObject *object)
{
    GPartsResultController *controller = GPARTS_RESULT_CONTROLLER(object);

    gparts_result_controller_set_database_model(controller, NULL);
    gparts_result_controller_set_target(controller, NULL);

    misc_object_chain_dispose(object);
}

/*! \brief Deallocate all resources.
 *
 *  This function performs the second and last stage of object destruction.
 *
 *  \param [in] object The object to finalize.
 */
static void
gparts_result_controller_finalize(GObject *object)
{
    GPartsResultControllerPrivate *private = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(object);

    g_free(private->template);
    g_free(private->view_name);

    misc_object_chain_finalize(object);
}

static gchar*
gparts_result_controller_get_field(GPartsController *controller, const gchar *name)
{
    GtkTreeIter iter;
    GtkTreeModel *model;
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);
    gboolean success;
    gchar *value = NULL;

    success = gtk_tree_selection_get_selected(privat->selection, &model, &iter);

    if (success && GPARTS_IS_RESULT_MODEL(model))
    {
        value = gparts_result_model_get_field(GPARTS_RESULT_MODEL(model), &iter, name);
    }

    return value;
}

static GHashTable*
gparts_result_controller_get_table(GPartsResultController *controller)
{
    GtkTreeViewColumn *column;
    gint index = 0;
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);
    GHashTable *table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);

    column = gtk_tree_view_get_column(privat->target, index++);

    while (column != NULL)
    {
        const gchar *name;
        gchar *value;

        name = g_strdup(gtk_tree_view_column_get_title(column));

        value = gparts_result_controller_get_field(
            controller,
            name
            );

        g_hash_table_insert(table, name, value);

        column = gtk_tree_view_get_column(privat->target, index++);
    }

    return table;
}


GType
gparts_result_controller_get_type(void)
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsResultControllerClass),
            NULL,
            NULL,
            gparts_result_controller_class_init,
            NULL,
            NULL,
            sizeof(GPartsResultController),
            0,
            NULL,
            NULL
            };

        type = g_type_register_static(
            GPARTS_TYPE_CONTROLLER,
            "GpartsResultController",
            &tinfo,
            0
            );
    }

    return type;
}

static void
gparts_result_controller_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
}

/*! \brief Refresh the view with a new set of data.
 *
 *
 *  \param [in] controller The controller.
 */
void
gparts_result_controller_refresh(GPartsResultController *controller)
{
    GPartsDatabase *database = NULL;
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);
    GPartsDatabaseResult *result = NULL;

    if (privat->database_model != NULL)
    {
        database = gpartsui_database_model_get_database(privat->database_model);
    }

    if (database != NULL &&
        privat->target != NULL &&
        privat->template != NULL &&
        GTK_WIDGET_VISIBLE(privat->target))
    {
        gchar *query = gparts_result_controller_build(controller);

        if (query != NULL)
        {
            result = gparts_database_query(database, query, NULL);
            g_free(query);
        }
    }

    gparts_result_controller_set_result(controller, result);
}

static void
gparts_result_controller_refresh_cb(gpointer unknown, GPartsResultController *controller)
{
    gparts_result_controller_refresh(controller);
}

static
gparts_result_controller_notify_focus_cb(GtkWidget *widget, GParamSpec *pspec, GPartsResultController *controller)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat->customize_ctrl != NULL)
    {
        if (GTK_WIDGET_HAS_FOCUS(widget))
        {
            gparts_customize_ctrl_set_target_view(privat->customize_ctrl, widget);
        }
        else
        {
            gparts_customize_ctrl_set_target_view(privat->customize_ctrl, NULL);
        }
    }
}

static void
gparts_result_controller_set_edit_action(GPartsResultController *controller, GtkAction *action)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat->edit_action != action)
    {
        if (privat->edit_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->edit_action,
                G_CALLBACK(gparts_result_controller_edit_columns_cb),
                controller
                );

            g_object_unref(privat->edit_action);
        }

        privat->edit_action = action;

        if (privat->edit_action != NULL)
        {
            g_object_ref(privat->edit_action);

            g_signal_connect(
                privat->edit_action,
                "activate",
                G_CALLBACK(gparts_result_controller_edit_columns_cb),
                controller
                );
        }
    }
}

static void
gparts_result_controller_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsResultController *controller = GPARTS_RESULT_CONTROLLER(object);

    switch (property_id)
    {
        case GPARTS_RESULT_CONTROLLER_PROPID_CUSTOMIZE_CTRL:
            gparts_result_controller_set_customize_ctrl(controller, g_value_get_object(value));
            break;

        case GPARTS_RESULT_CONTROLLER_PROPID_DATABASE_MODEL:
            gparts_result_controller_set_database_model(controller, g_value_get_object(value));
            break;

        case GPARTS_RESULT_CONTROLLER_PROPID_SOURCE:
            gparts_result_controller_set_source(controller, g_value_get_object(value));
            break;

        case GPARTS_RESULT_CONTROLLER_PROPID_TARGET:
            gparts_result_controller_set_target(controller, g_value_get_object(value));
            break;

        case GPARTS_RESULT_CONTROLLER_PROPID_TEMPLATE:
            gparts_result_controller_set_template(controller, g_value_get_string(value));
            break;

        case GPARTS_RESULT_CONTROLLER_PROPID_RESULT_NAME:
            gparts_result_controller_set_result_name(controller, g_value_get_string(value));
            break;

        case GPARTS_RESULT_CONTROLLER_PROPID_EDIT_ACTION:
            gparts_result_controller_set_edit_action(controller, g_value_get_object(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

/*! \brief Sets the target view's contents to the database's result.
 *
 *
 *  \param [in] private  The private data for this binding.
 *  \param [in] result   The database result to place in the view.
 */
static void
gparts_result_controller_set_result(GPartsResultController *controller, GPartsDatabaseResult *result)
{
    GtkTreeModel *model = NULL;
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (result != NULL)
    {
        model = GTK_TREE_MODEL(gparts_result_model_new(result));

        gparts_result_controller_disconnect_columns(controller);
        gparts_result_model_set_columns(result, privat->target);
        gparts_result_controller_connect_columns(controller);
    }

    if (privat->target != NULL)
    {
        gtk_tree_view_set_model(privat->target, model);
        gparts_result_controller_set_sort_indicators(controller);
    }

    if (model != NULL)
    {
        g_object_unref(model);
    }

}

static void
gparts_result_controller_set_sort_indicators(GPartsResultController *controller)
{
    GtkTreeViewColumn *column;
    gint index = 0;
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    column = gtk_tree_view_get_column(privat->target, index++);

    while (column != NULL)
    {
        gboolean sort_indicator;

        sort_indicator = FALSE;

        if (privat->sort_column != NULL)
        {
            if (g_strcmp0(privat->sort_column, gtk_tree_view_column_get_title(column)) == 0)
            {
                sort_indicator = TRUE;
                gtk_tree_view_column_set_sort_order(column, privat->sort_order);
            }
        }

        gtk_tree_view_column_set_sort_indicator(column, sort_indicator);

        column = gtk_tree_view_get_column(privat->target, index++);
    }
}

/*  This signal handler updates this controller's view in response to data
 *  changes in the source controller.
 */
static void
gparts_result_controller_updated_cb(GtkTreeSelection *widget, GPartsResultController *controller)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    /* Temporary solution until the result controller stores the sort state of previous views */

    if (privat->sort_column != NULL)
    {
        g_free(privat->sort_column);
        privat->sort_column = NULL;
    }

    gparts_result_controller_refresh(controller);
}

static void
gparts_result_controller_show_cb(GtkWidget *widget, GPartsResultController *controller)
{
    gparts_result_controller_refresh(controller);
}

void
gparts_result_controller_set_customize_ctrl(GPartsResultController *controller, GPartsCustomizeCtrl *customize_ctrl)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat->customize_ctrl != customize_ctrl)
    {
        if (privat->customize_ctrl != NULL)
        {
            g_object_unref(privat->customize_ctrl);
        }

        privat->customize_ctrl = customize_ctrl;

        if (privat->customize_ctrl != NULL)
        {
            g_object_ref(privat->customize_ctrl);
        }

        g_object_notify(G_OBJECT(controller), "customize-ctrl");
    }

}

void
gparts_result_controller_set_database_model(GPartsResultController *controller, GPartsUIDatabaseModel *model)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat != NULL)
    {
        if (privat->database_model != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database_model,
                G_CALLBACK(gparts_result_controller_database_controller_notify_cb),
                controller
                );

            g_signal_handlers_disconnect_by_func(
                privat->database_model,
                G_CALLBACK(gparts_result_controller_refresh_cb),
                controller
                );

            g_object_unref(privat->database_model);
        }

        privat->database_model = model;

        if (privat->database_model != NULL)
        {
            g_object_ref(privat->database_model);

            g_signal_connect(
                privat->database_model,
                "notify::connected",
                G_CALLBACK(gparts_result_controller_database_controller_notify_cb),
                controller
                );

            g_signal_connect(
                privat->database_model,
                "notify::database",
                G_CALLBACK(gparts_result_controller_database_controller_notify_cb),
                controller
                );

            g_signal_connect(
                privat->database_model,
                "refresh",
                G_CALLBACK(gparts_result_controller_refresh_cb),
                controller
                );
        }

        g_object_notify(controller, "database-model");

        gparts_result_controller_refresh(controller);
    }
}

void
gparts_result_controller_set_source(GPartsResultController *controller, GObject *source)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat->source != source)
    {
        if (privat->source != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->source,
                G_CALLBACK(gparts_result_controller_updated_cb),
                controller
                );

            g_object_unref(privat->source);
        }

        privat->source = source;

        if (privat->source != NULL)
        {
            g_object_ref(privat->source);

            g_signal_connect(
                privat->source,
                "updated",
                G_CALLBACK(gparts_result_controller_updated_cb),
                controller
                );
        }

        gparts_result_controller_refresh(controller);
    }
}

void
gparts_result_controller_set_target(GPartsResultController *controller, GtkTreeView *target)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (privat->target != target)
    {
        if (privat->selection != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->selection,
                G_CALLBACK(gparts_result_controller_changed_cb),
                controller
                );

            g_object_unref(privat->selection);
        }

        if (privat->target != NULL)
        {
            gparts_result_controller_disconnect_columns(controller);

            g_signal_handlers_disconnect_by_func(
                privat->selection,
                G_CALLBACK(gparts_result_controller_notify_focus_cb),
                controller
                );

            g_signal_handlers_disconnect_by_func(
                privat->target,
                G_CALLBACK(gparts_result_controller_popup_menu_cb),
                controller
                );

            g_signal_handlers_disconnect_by_func(
                privat->target,
                G_CALLBACK(gparts_result_controller_show_cb),
                controller
                );

            g_object_unref(privat->target);
       }

        privat->target = target;

        if (privat->target != NULL)
        {
            g_object_ref(privat->target);

            g_signal_connect(
                privat->target,
                "notify::has-focus",
                G_CALLBACK(gparts_result_controller_notify_focus_cb),
                controller
                );

            g_signal_connect(
                privat->target,
                "popup-menu",
                G_CALLBACK(gparts_result_controller_popup_menu_cb),
                controller
                );

            g_signal_connect(
                privat->target,
                "show",
                G_CALLBACK(gparts_result_controller_show_cb),
                controller
                );

            gparts_result_controller_connect_columns(controller);

            privat->selection = gtk_tree_view_get_selection(privat->target);

            if (privat->selection != NULL)
            {
                g_object_ref(privat->selection);

                g_signal_connect(
                    privat->selection,
                    "changed",
                    G_CALLBACK(gparts_result_controller_changed_cb),
                    controller
                    );
            }
        }

        gparts_result_controller_refresh(controller);
    }
}

void
gparts_result_controller_set_template(GPartsResultController *controller, const gchar *template)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (g_strcmp0(template, privat->template) != 0)
    {
        g_free(privat->template);
        privat->template = g_strdup(template);

        gparts_result_controller_refresh(controller);
    }
}

void
gparts_result_controller_set_result_name(GPartsResultController *controller, const gchar *view_name)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);

    if (g_strcmp0(view_name, privat->view_name) != 0)
    {
        g_free(privat->view_name);
        privat->view_name = g_strdup(view_name);

        gparts_result_controller_refresh(controller);
    }
}

gchar*
lookup(GPartsResultController *controller, const gchar *name);

gchar*
sub(GPartsResultController *controller, const gchar *template);

static gchar*
gparts_result_controller_build(GPartsResultController *controller)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);
    GString *query = g_string_sized_new(10);

    g_string_printf(query, privat->template, privat->view_name);

    gchar *result = sub(controller, query->str);
    g_string_free(query, TRUE);

    if (result != NULL && privat->sort_column != NULL)
    {
        GString *buffer = g_string_sized_new(10);
        gchar *order = "ASC";

        if (privat->sort_order == GTK_SORT_DESCENDING)
        {
            order = "DESC";
        }

        g_string_append_printf(buffer, "%s ORDER BY %s %s", result, privat->sort_column, order);

        g_free(result);
        result = g_string_free(buffer, FALSE);
    }

    return result;
}

/*! \brief Performs field substitution on a given string.
 *
 * source
 *  $(column_name)
 *
 *  \param [in] template
 *
 */
gchar*
sub(GPartsResultController *controller, const gchar *template)
{
    gboolean error = FALSE;
    GString *result = g_string_sized_new(10);
    gchar *temp;

    temp = strstr(template, "$(");

    while (temp != NULL)
    {
        g_string_append_len(result, template, temp-template);

        template = temp;

        temp = strchr(template, ')');

        if (temp != NULL)
        {
            gchar *name;
            gchar *value;

            template += 2;

            name = g_strndup(template, temp-template);

            value = lookup(controller, name);
            g_free(name);

            if (value != NULL)
            {
                g_string_append(result, value);
                g_free(value);
            }
            else
            {
                error = TRUE;
                break;
            }

            template = temp + 1;

            temp = strstr(template, "$(");
        }
    }

    g_string_append(result, template);

    return g_string_free(result, error);
}

/*! \brief Lookup a field's value from the source model.
 */
gchar*
lookup(GPartsResultController *controller, const gchar *name)
{
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);
    gchar *field = NULL;

    if (privat->source != NULL)
    {
        field = gparts_controller_get_field(privat->source, name);
    }

    return field;
}


static void
gparts_result_controller_edit_columns_cb(gpointer unused, GPartsResultController *controller)
{
    GtkTreeViewColumn *column;
    GtkDialog *dialog = GTK_DIALOG(gtk_dialog_new());
    gint index = 0;
    GtkListStore *model;
    GtkTreeView *list;
    GPartsResultControllerPrivate *privat = GPARTS_RESULT_CONTROLLER_GET_PRIVATE(controller);
    gint result;
    GtkCellRenderer *renderer;

    model = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_BOOLEAN);

    column = gtk_tree_view_get_column(privat->target, index++);

    while (column != NULL)
    {
        GtkTreeIter iter;

        gtk_list_store_append(model, &iter);

        gtk_list_store_set(
            model,
            &iter,
            0, g_strdup(gtk_tree_view_column_get_title(column)),
            1, gtk_tree_view_column_get_visible(column),
            -1
            );

        column = gtk_tree_view_get_column(privat->target, index++);
    }

    list = gtk_tree_view_new_with_model(model);
    gtk_tree_selection_set_mode(gtk_tree_view_get_selection(list), GTK_SELECTION_NONE);
    g_object_unref(model);

    column = gtk_tree_view_column_new();
    gtk_tree_view_column_set_title(column, "Column");
    gtk_tree_view_append_column(list, column);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(column, renderer, TRUE);
    gtk_tree_view_column_add_attribute(column, renderer, "text", 0);

    column = gtk_tree_view_column_new();
    gtk_tree_view_column_set_title(column, "Visible");
    gtk_tree_view_append_column(list, column);
    renderer = gtk_cell_renderer_toggle_new();
    gtk_tree_view_column_pack_start(column, renderer, FALSE);
    gtk_tree_view_column_add_attribute(column, renderer, "active", 1);

    gtk_widget_show(list);

    gtk_tree_view_append_column(list, column);

    gtk_container_add(gtk_dialog_get_content_area(dialog), list);

    gtk_dialog_add_buttons(
        dialog,
        GTK_STOCK_HELP,   GTK_RESPONSE_HELP,
        GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
        GTK_STOCK_OK,     GTK_RESPONSE_OK,
        NULL
        );

    result = gtk_dialog_run(dialog);

    switch (result)
    {
        case GTK_RESPONSE_OK:
            g_debug("OK");
            break;

        case GTK_RESPONSE_HELP:
            g_debug("Help");
            break;

        case GTK_RESPONSE_CANCEL:
        case GTK_RESPONSE_DELETE_EVENT:
        default:
            g_debug("Cancel");
    }

    gtk_widget_destroy(dialog);
}

static void
debug_test(gpointer unused, gpointer unused2)
{
    g_debug("Testing  Did it work?");
}

static gboolean
gparts_result_controller_popup_menu_cb(GtkWidget *widget, GPartsResultController *controller)
{
    GtkMenu *menu = GTK_MENU(gtk_menu_new());

    gtk_menu_attach_to_widget(menu, widget, NULL);

    GtkWidget *w = gtk_menu_item_new_with_label("Visible Columns");

    gtk_widget_show(w);

    gtk_menu_shell_append(menu, w);

    g_signal_connect(
        G_OBJECT(w),
        "activate",
        G_CALLBACK(gparts_result_controller_edit_columns_cb),
        controller
        );

    gtk_menu_popup(
        menu,
        NULL,
        NULL,
        NULL,
        NULL,
        0,
        gtk_get_current_event_time()
        );

    return TRUE;
}

#if 0
    if (privat->target != NULL)
    {
        GtkMenu *sub = gtk_menu_new();
        gint index = 0;
        GtkTreeViewColumn *column;

        column = gtk_tree_view_get_column(privat->target, index++);

        while (column != NULL)
        {
            GtkCheckMenuItem *item2;

            item2 = gtk_check_menu_item_new_with_label(gtk_tree_view_column_get_title(column));

            g_signal_connect(
                item2,
                "toggled",
                G_CALLBACK(gparts_result_controller_toggled_cb),
                column
                );

            g_object_set(
                item2,
                "active", gtk_tree_view_column_get_visible(column),
                NULL
                );

            gtk_menu_shell_append(sub, item2);

            gtk_widget_show(item2);

            column = gtk_tree_view_get_column(privat->target, index++);
        }

        gtk_menu_item_set_submenu(item, sub);
    }
#endif


