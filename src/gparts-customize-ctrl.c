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

/*! \file gparts-customize-ctrl.c 
 */

#include <gtk/gtk.h>

#include "misc-object.h"

#include "gparts-customize-ctrl.h"
#include "gparts-customize-model.h"

#define GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_CUSTOMIZE_CTRL,GPartsCustomizeCtrlPrivate)

enum
{
    GPARTS_CUSTOMIZE_CTRL_PROPID_CUSTOMIZE_ACTION = 1,
    GPARTS_CUSTOMIZE_CTRL_PROPID_CUSTOMIZE_DIALOG,
    GPARTS_CUSTOMIZE_CTRL_PROPID_TARGET_VIEW,
};

typedef struct _GPartsCustomizeCtrlPrivate GPartsCustomizeCtrlPrivate;

struct _GPartsCustomizeCtrlPrivate
{
    GtkAction   *customize_action;
    GtkDialog   *customize_dialog;
    GtkTreeView *target_view;

    GtkTreeView *view;
};

static GtkDialog*
gparts_customize_ctrl_build_customize_dialog(GPartsCustomizeCtrl *customize_ctrl);

static void
gparts_customize_ctrl_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_customize_ctrl_dispose(GObject *object);

static void
gparts_customize_ctrl_finalize(GObject *object);

static void
gparts_customize_ctrl_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gparts_customize_ctrl_init(GTypeInstance* instance, gpointer g_class);

static void
gparts_customize_ctrl_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gparts_customize_ctrl_update_action(GPartsCustomizeCtrl *customize_ctrl);

/**** Signal handlers ****/

static void
gparts_customize_ctrl_customize_action_cb(GtkAction *action, GPartsCustomizeCtrl *customize_ctrl);

static void
gparts_customize_ctrl_visible_toggled_cb(GtkCellRendererToggle *toggle, gchar *path, GPartsCustomizeCtrl *customize_ctrl);

static GtkDialog*
gparts_customize_ctrl_build_customize_dialog(GPartsCustomizeCtrl *customize_ctrl)
{
    GtkTreeViewColumn *column;
    GtkDialog *dialog;
    GPartsCustomizeCtrlPrivate *privat = GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(customize_ctrl);
    GtkCellRendererToggle *toggle;

    dialog = GTK_DIALOG(gtk_dialog_new_with_buttons(
        "Customize View",
        NULL,
        GTK_DIALOG_MODAL,
        GTK_STOCK_HELP,   GTK_RESPONSE_HELP,
        GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
        GTK_STOCK_OK,     GTK_RESPONSE_OK,
        NULL
        ));

    gtk_dialog_set_alternative_button_order(
        dialog,
        GTK_RESPONSE_HELP,
        GTK_RESPONSE_OK,
        GTK_RESPONSE_CANCEL,
        -1
        );

    gtk_dialog_set_default_response(dialog, GTK_RESPONSE_OK);

    privat->view = GTK_TREE_VIEW(g_object_new(
        GTK_TYPE_TREE_VIEW,
        NULL
        ));

    gtk_widget_show(GTK_WIDGET(privat->view));

    gtk_tree_selection_set_mode(
        gtk_tree_view_get_selection(privat->view),
        GTK_SELECTION_NONE
        );

    gtk_tree_view_set_headers_visible(privat->view, TRUE);

    column = gtk_tree_view_column_new_with_attributes(
        "Column",
        g_object_new(
            GTK_TYPE_CELL_RENDERER_TEXT,
            "sensitive", FALSE,
            NULL
            ),
        "text", 0,
        NULL
        );

    g_object_set(column, "expand", TRUE, NULL);

    gtk_tree_view_append_column(privat->view, column);

    toggle = g_object_new(
        GTK_TYPE_CELL_RENDERER_TOGGLE,
        NULL
        );

    g_signal_connect(
        toggle,
        "toggled",
        G_CALLBACK(gparts_customize_ctrl_visible_toggled_cb),
        customize_ctrl
        );

    gtk_tree_view_insert_column_with_attributes(
        privat->view,
        -1,
        "Visible",
        GTK_CELL_RENDERER(toggle),
        "active", 1,
        NULL
        );

    gtk_container_add(GTK_CONTAINER(gtk_dialog_get_content_area(dialog)), GTK_WIDGET(privat->view));

    return dialog;
}

static void
gparts_customize_ctrl_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsCustomizeCtrlPrivate));

    object_class->dispose  = gparts_customize_ctrl_dispose;
    object_class->finalize = gparts_customize_ctrl_finalize;

    object_class->get_property = gparts_customize_ctrl_get_property;
    object_class->set_property = gparts_customize_ctrl_set_property;

    g_object_class_install_property(
        object_class,
        GPARTS_CUSTOMIZE_CTRL_PROPID_CUSTOMIZE_ACTION,
        g_param_spec_object(
            "customize-action",
            "",
            "",
            GTK_TYPE_ACTION,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_CUSTOMIZE_CTRL_PROPID_CUSTOMIZE_DIALOG,
        g_param_spec_object(
            "customize-dialog",
            "",
            "",
            GTK_TYPE_DIALOG,
            G_PARAM_READWRITE
            )
        );

    g_object_class_install_property(
        object_class,
        GPARTS_CUSTOMIZE_CTRL_PROPID_TARGET_VIEW,
        g_param_spec_object(
            "target-view",
            "",
            "",
            GTK_TYPE_TREE_VIEW,
            G_PARAM_READWRITE
            )
        );
}

static void
gparts_customize_ctrl_customize_action_cb(GtkAction *action, GPartsCustomizeCtrl *customize_ctrl)
{
    GPartsCustomizeModel *model = NULL;
    GPartsCustomizeCtrlPrivate *privat = GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(customize_ctrl);
    gint result;

    if (privat->view != NULL)
    {
        model = g_object_new(GPARTS_TYPE_CUSTOMIZE_MODEL, "view", privat->target_view, NULL);

        gtk_tree_view_set_model(privat->view, GTK_TREE_MODEL(model));
    }

    result = gtk_dialog_run(privat->customize_dialog);

    gtk_widget_hide(GTK_WIDGET(privat->customize_dialog));
}

static void
gparts_customize_ctrl_dispose(GObject *object)
{
    GPartsCustomizeCtrl *controller = GPARTS_CUSTOMIZE_CTRL(object);

    gparts_customize_ctrl_set_customize_action(controller, NULL);
    gparts_customize_ctrl_set_customize_dialog(controller, NULL);
    gparts_customize_ctrl_set_target_view(controller, NULL);

    misc_object_chain_dispose(object);
}

static void
gparts_customize_ctrl_finalize(GObject *object)
{
    GPartsCustomizeCtrlPrivate *private = GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(object);

    misc_object_chain_finalize(object);
}

static void
gparts_customize_ctrl_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsCustomizeCtrlPrivate *privat = GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(object);

    switch (property_id)
    {
        case GPARTS_CUSTOMIZE_CTRL_PROPID_CUSTOMIZE_ACTION:
            g_value_set_object(value, privat->customize_action);
            break;

        case GPARTS_CUSTOMIZE_CTRL_PROPID_CUSTOMIZE_DIALOG:
            g_value_set_object(value, privat->customize_dialog);
            break;

        case GPARTS_CUSTOMIZE_CTRL_PROPID_TARGET_VIEW:
            g_value_set_object(value, privat->target_view);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

GType
gparts_customize_ctrl_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsCustomizeCtrlClass),    /* class_size */
            NULL,                                /* base_init */
            NULL,                                /* base_finalize */
            gparts_customize_ctrl_class_init,    /* class_init */
            NULL,                                /* class_finalize */
            NULL,                                /* class_data */
            sizeof(GPartsCustomizeCtrl),         /* instance_size */
            0,                                   /* n_preallocs */
            gparts_customize_ctrl_init,          /* instance_init */
            NULL                                 /* value_table */
            };

#if 0
        static const GInterfaceInfo iinfo = {
            gparts_object_list_buildable_init,    /* interface_init */
            NULL,                                 /* interface_finalize */
            NULL                                  /* interface_data */
            };
#endif

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPartsCustomizeCtrl",
            &tinfo,
            0
            );

        /* g_type_add_interface_static(type, GTK_TYPE_BUILDABLE, &iinfo); */
    }

    return type;
}

static void
gparts_customize_ctrl_init(GTypeInstance* instance, gpointer g_class)
{
    GtkDialog *dialog = gparts_customize_ctrl_build_customize_dialog(GPARTS_CUSTOMIZE_CTRL(instance));

    gparts_customize_ctrl_set_customize_dialog(GPARTS_CUSTOMIZE_CTRL(instance), dialog);

    g_object_unref(dialog);
}

void
gparts_customize_ctrl_set_customize_action(GPartsCustomizeCtrl *customize_ctrl, GtkAction *action)
{
    GPartsCustomizeCtrlPrivate *privat = GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(customize_ctrl);

    if (privat->customize_action != action)
    {
        if (privat->customize_action != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->customize_action,
                G_CALLBACK(gparts_customize_ctrl_customize_action_cb),
                customize_ctrl
                );

            g_object_unref(privat->customize_action);
        }

        privat->customize_action = action;

        if (privat->customize_action != NULL)
        {
            g_object_ref(privat->customize_action);

            g_signal_connect(
                privat->customize_action,
                "activate",
                G_CALLBACK(gparts_customize_ctrl_customize_action_cb),
                customize_ctrl
                );
        }

        g_object_notify(G_OBJECT(customize_ctrl), "customize-action");

        gparts_customize_ctrl_update_action(customize_ctrl);
    }
}

void
gparts_customize_ctrl_set_customize_dialog(GPartsCustomizeCtrl *customize_ctrl, GtkDialog *dialog)
{
    GPartsCustomizeCtrlPrivate *privat = GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(customize_ctrl);

    if (privat->customize_dialog != dialog)
    {
        if (privat->customize_dialog != NULL)
        {
            g_object_unref(privat->customize_dialog);
        }

        privat->customize_dialog = dialog;

        if (privat->customize_dialog != NULL)
        {
            g_object_ref(privat->customize_dialog);
        }

        g_object_notify(G_OBJECT(customize_ctrl), "customize-dialog");
    }
}

static void
gparts_customize_ctrl_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsCustomizeCtrl *customize_ctrl = GPARTS_CUSTOMIZE_CTRL(object);

    switch (property_id)
    {
        case GPARTS_CUSTOMIZE_CTRL_PROPID_CUSTOMIZE_ACTION:
            gparts_customize_ctrl_set_customize_action(customize_ctrl, g_value_get_object(value));
            break;

        case GPARTS_CUSTOMIZE_CTRL_PROPID_CUSTOMIZE_DIALOG:
            gparts_customize_ctrl_set_customize_dialog(customize_ctrl, g_value_get_object(value));
            break;

        case GPARTS_CUSTOMIZE_CTRL_PROPID_TARGET_VIEW:
            gparts_customize_ctrl_set_target_view(customize_ctrl, g_value_get_object(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

void
gparts_customize_ctrl_set_target_view(GPartsCustomizeCtrl *customize_ctrl, GtkTreeView *view)
{
    GPartsCustomizeCtrlPrivate *privat = GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(customize_ctrl);

    if (privat->target_view != view)
    {
        if (privat->target_view != NULL)
        {
            g_object_unref(privat->target_view);
        }

        privat->target_view = view;

        if (privat->target_view != NULL)
        {
            g_object_ref(privat->target_view);
        }

        g_object_notify(G_OBJECT(customize_ctrl), "target-view");

        gparts_customize_ctrl_update_action(customize_ctrl);
    }
}

static void
gparts_customize_ctrl_update_action(GPartsCustomizeCtrl *customize_ctrl)
{
    GPartsCustomizeCtrlPrivate *privat = GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(customize_ctrl);

    if (privat != NULL && privat->customize_action != NULL)
    {
        gboolean sensitive = FALSE;

        if (privat->target_view != NULL)
        {
            GtkTreeModel *model = gtk_tree_view_get_model(privat->target_view);

            sensitive = (model != NULL);
        }

        gtk_action_set_sensitive(privat->customize_action, sensitive);
    }
}

static void
gparts_customize_ctrl_visible_toggled_cb(GtkCellRendererToggle *toggle, gchar *path, GPartsCustomizeCtrl *customize_ctrl)
{
    GPartsCustomizeCtrlPrivate *privat = GPARTS_CUSTOMIZE_CTRL_GET_PRIVATE(customize_ctrl);

    if (privat->view != NULL)
    {
        GtkTreeModel *model = gtk_tree_view_get_model(privat->view);

        if (GPARTS_IS_CUSTOMIZE_MODEL(model))
        {
            gboolean active = gtk_cell_renderer_toggle_get_active(toggle);
            GtkTreeIter iter;

            GtkTreePath *tpath = gtk_tree_path_new_from_string(path);

            if (gtk_tree_model_get_iter(model, &iter, tpath))
            {
                gparts_customize_model_set_visible(
                    GPARTS_CUSTOMIZE_MODEL(model),
                    &iter,
                    !active
                    );
            }
        }
    }
}

