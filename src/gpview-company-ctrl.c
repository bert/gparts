/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2012 Edward C. Hennessy
 * Copyright (C) 2012 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpview-company-ctrl.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "sch.h"
#include "gparts.h"
#include "gpform.h"
#include "gpview.h"

#define GPVIEW_COMPANY_CTRL_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPVIEW_TYPE_COMPANY_CTRL,GPViewCompanyCtrlPrivate))

enum
{
    GPVIEW_COMPANY_CTRL_CURRENT_VIEW = 1,
    GPVIEW_COMPANY_CTRL_DATABASE,
    GPVIEW_COMPANY_CTRL_UI_MANAGER
};

typedef struct _GPViewCompanyCtrlPrivate GPViewCompanyCtrlPrivate;

struct _GPViewCompanyCtrlPrivate
{
    GtkActionGroup    *action_group[3];
    GPartsDatabase    *database;
    GPViewCompanyView *current_view;
    GtkUIManager      *ui_manager;

    GPFormFactory     *form_factory;
};

static void
gpview_company_ctrl_class_init(gpointer g_class, gpointer g_class_data);

static void
gpview_company_ctrl_create_cb(GtkAction *action, GPViewCompanyCtrl *ctrl);

static void
gpview_company_ctrl_delete_cb(GtkAction *action, GPViewCompanyCtrl *ctrl);

static void
gpview_company_ctrl_dispose(GObject *object);

static void
gpview_company_ctrl_edit_cb(GtkAction *action, GPViewCompanyCtrl *ctrl);

static void
gpview_company_ctrl_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpview_company_ctrl_init(GTypeInstance *instance, gpointer g_class);

static void
gpview_company_ctrl_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gpview_company_ctrl_update_0_cb(GObject *unused, GParamSpec *pspec, GPViewCompanyCtrl *ctrl);

static void
gpview_company_ctrl_update_1_cb(GObject *unused, GParamSpec *pspec, GPViewCompanyCtrl *ctrl);

static void
gpview_company_ctrl_update_2_cb(GObject *unused, GParamSpec *pspec, GPViewCompanyCtrl *ctrl);

static void
gpview_company_ctrl_visit_cb(GtkAction *action, GPViewCompanyCtrl *ctrl);



static const GtkActionEntry gpview_company_ctrl_actions_0[] =
{
    {
        "company-create",
        GTK_STOCK_ADD,
        "New Company",
        NULL,
        "New Company",
        G_CALLBACK(gpview_company_ctrl_create_cb)
    },
};


static const GtkActionEntry gpview_company_ctrl_actions_1[] =
{
    {
        "company-edit",
        GTK_STOCK_EDIT,
        "Edit Company",
        NULL,
        "Edit Company",
        G_CALLBACK(gpview_company_ctrl_edit_cb)
    },
    {
        "company-delete",
        GTK_STOCK_REMOVE,
        "Delete Company",
        NULL,
        "Delete Company",
        G_CALLBACK(gpview_company_ctrl_delete_cb)
    }
};

static const GtkActionEntry gpview_company_ctrl_actions_2[] =
{
    {
        "company-visit",
        GTK_STOCK_HOME,
        "Visit Company Website",
        NULL,
        "Visit Company Website",
        G_CALLBACK(gpview_company_ctrl_visit_cb)
    }
};



static void
gpview_company_ctrl_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPViewCompanyCtrlPrivate));

    klasse->dispose = gpview_company_ctrl_dispose;

    klasse->get_property = gpview_company_ctrl_get_property;
    klasse->set_property = gpview_company_ctrl_set_property;

    g_object_class_install_property(
        klasse,
        GPVIEW_COMPANY_CTRL_CURRENT_VIEW,
        g_param_spec_object(
            "current-view",
            "Current View",
            "Current View",
            GPVIEW_TYPE_COMPANY_VIEW,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPVIEW_COMPANY_CTRL_DATABASE,
        g_param_spec_object(
            "database",
            "Database",
            "Database",
            GPARTS_TYPE_DATABASE,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPVIEW_COMPANY_CTRL_UI_MANAGER,
        g_param_spec_object(
            "ui-manager",
            "UI Manager",
            "UI Manager",
            GTK_TYPE_UI_MANAGER,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}


static void
gpview_company_ctrl_create_cb(GtkAction *action, GPViewCompanyCtrl *ctrl)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(ctrl);

    if (privat != NULL)
    {
        GPFormUIDialog *dialog;

        dialog = gpform_factory_create_form(privat->form_factory, "company-add.xml");

        if (dialog != NULL)
        {
            gtk_widget_show_all(GTK_WIDGET(dialog));

            /*gint result =*/ gtk_dialog_run(GTK_DIALOG(dialog));

            gtk_widget_hide(GTK_WIDGET(dialog));
        }
    }
}


static void
gpview_company_ctrl_dispose(GObject *object)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(object);

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_object_unref(privat->database);
        }
    }

    misc_object_chain_dispose(object);
}


static void
gpview_company_ctrl_delete_cb(GtkAction *action, GPViewCompanyCtrl *ctrl)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(ctrl);

    if (privat != NULL)
    {
        GPFormUIDialog *dialog;

        dialog = gpform_factory_create_form(privat->form_factory, "company-delete.xml");

        if (dialog != NULL)
        {
            gtk_widget_show_all(GTK_WIDGET(dialog));

            /*gint result =*/ gtk_dialog_run(GTK_DIALOG(dialog));

            gtk_widget_hide(GTK_WIDGET(dialog));
        }
    }
}


static void
gpview_company_ctrl_edit_cb(GtkAction *action, GPViewCompanyCtrl *ctrl)
{
    g_debug("Edit Company");
}


static void
gpview_company_ctrl_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}


GType
gpview_company_ctrl_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPViewCompanyCtrlClass),    /* class_size */
            NULL,                              /* base_init */
            NULL,                              /* base_finalize */
            gpview_company_ctrl_class_init,    /* class_init */
            NULL,                              /* class_finalize */
            NULL,                              /* class_data */
            sizeof(GPViewCompanyCtrl),         /* instance_size */
            0,                                 /* n_preallocs */
            gpview_company_ctrl_init,          /* instance_init */
            NULL                               /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            NULL,                              /* interface_init */
            NULL,                              /* interface_finalize */
            NULL                               /* interface_data */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPViewCompanyCtrl",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GTK_TYPE_BUILDABLE, &iinfo);
    }

    return type;
}


static void
gpview_company_ctrl_init(GTypeInstance *instance, gpointer g_class)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        privat->action_group[0] = gtk_action_group_new("company-action-group-0");

        gtk_action_group_add_actions(
            privat->action_group[0],
            gpview_company_ctrl_actions_0,
            G_N_ELEMENTS(gpview_company_ctrl_actions_0),
            instance
            );

        g_signal_connect(
            GPVIEW_COMPANY_CTRL(instance),
            "notify::database",
            G_CALLBACK(gpview_company_ctrl_update_0_cb),
            GPVIEW_COMPANY_CTRL(instance)
            );

        privat->action_group[1] = gtk_action_group_new("company-action-group-1");

        gtk_action_group_add_actions(
            privat->action_group[1],
            gpview_company_ctrl_actions_1,
            G_N_ELEMENTS(gpview_company_ctrl_actions_1),
            instance
            );

        g_signal_connect(
            GPVIEW_COMPANY_CTRL(instance),
            "notify::current-view",
            G_CALLBACK(gpview_company_ctrl_update_1_cb),
            GPVIEW_COMPANY_CTRL(instance)
            );

        g_signal_connect(
            GPVIEW_COMPANY_CTRL(instance),
            "notify::database",
            G_CALLBACK(gpview_company_ctrl_update_1_cb),
            GPVIEW_COMPANY_CTRL(instance)
            );

        privat->action_group[2] = gtk_action_group_new("company-action-group-2");

        gtk_action_group_add_actions(
            privat->action_group[2],
            gpview_company_ctrl_actions_2,
            G_N_ELEMENTS(gpview_company_ctrl_actions_2),
            instance
            );

        g_signal_connect(
            GPVIEW_COMPANY_CTRL(instance),
            "notify::current-view",
            G_CALLBACK(gpview_company_ctrl_update_2_cb),
            GPVIEW_COMPANY_CTRL(instance)
            );

        g_object_notify(G_OBJECT(instance), "current-view");
        g_object_notify(G_OBJECT(instance), "database");

        privat->form_factory = gpform_factory_new();
    }
}


GPViewCompanyCtrl*
gpview_company_ctrl_new(void)
{
    return GPVIEW_COMPANY_CTRL(g_object_new(GPVIEW_TYPE_COMPANY_CTRL, NULL));
}


GPViewCompanyCtrl*
gpview_company_ctrl_new_with_manager(GtkUIManager *manager)
{
    return GPVIEW_COMPANY_CTRL(g_object_new(
        GPVIEW_TYPE_COMPANY_CTRL,
        "ui-manager", manager,
        NULL
        ));
}


void
gpview_company_ctrl_set_current_view(GPViewCompanyCtrl *ctrl, GPViewCompanyView *view)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(ctrl);

    if (privat != NULL)
    {
        if (privat->current_view != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->current_view,
                G_CALLBACK(gpview_company_ctrl_update_2_cb),
                ctrl
                );

            g_object_unref(privat->current_view);
        }

        privat->current_view = view;

        if (privat->current_view != NULL)
        {
            g_object_ref(privat->current_view);

            g_signal_connect(
                privat->current_view,
                "notify::websites",
                G_CALLBACK(gpview_company_ctrl_update_2_cb),
                ctrl
                );
        }

        g_object_notify(G_OBJECT(ctrl), "current-view");
    }
}


void
gpview_company_ctrl_set_database(GPViewCompanyCtrl *ctrl, GPartsDatabase *database)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(ctrl);

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gpview_company_ctrl_update_1_cb),
                ctrl
                );

            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gpview_company_ctrl_update_0_cb),
                ctrl
                );

            g_object_unref(privat->database);
        }

        privat->database = database;

        if (privat->database != NULL)
        {
            g_object_ref(privat->database);

            g_signal_connect(
                privat->database,
                "notify::connected",
                G_CALLBACK(gpview_company_ctrl_update_0_cb),
                ctrl
                );

            g_signal_connect(
                privat->database,
                "notify::connected",
                G_CALLBACK(gpview_company_ctrl_update_1_cb),
                ctrl
                );
        }

        g_object_notify(G_OBJECT(ctrl), "database");
    }
}


static void
gpview_company_ctrl_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPViewCompanyCtrl *view = GPVIEW_COMPANY_CTRL(object);

    if (view != NULL)
    {
        switch (property_id)
        {
            case GPVIEW_COMPANY_CTRL_CURRENT_VIEW:
                gpview_company_ctrl_set_current_view(view, g_value_get_object(value));
                break;

            case GPVIEW_COMPANY_CTRL_DATABASE:
                gpview_company_ctrl_set_database(view, g_value_get_object(value));
                break;

            case GPVIEW_COMPANY_CTRL_UI_MANAGER:
                gpview_company_ctrl_set_ui_manager(view, g_value_get_object(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}


void
gpview_company_ctrl_set_ui_manager(GPViewCompanyCtrl *ctrl, GtkUIManager *ui_manager)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(ctrl);

    if (privat != NULL)
    {
        if (privat->ui_manager != NULL)
        {
            gtk_ui_manager_remove_action_group(
                privat->ui_manager,
                privat->action_group[2]
                );

            gtk_ui_manager_remove_action_group(
                privat->ui_manager,
                privat->action_group[1]
                );

            gtk_ui_manager_remove_action_group(
                privat->ui_manager,
                privat->action_group[0]
                );

            g_object_unref(privat->ui_manager);
        }

        privat->ui_manager = ui_manager;

        if (privat->ui_manager != NULL)
        {
            g_object_ref(privat->ui_manager);

            gtk_ui_manager_insert_action_group(
                privat->ui_manager,
                privat->action_group[0],
                0
                );

            gtk_ui_manager_insert_action_group(
                privat->ui_manager,
                privat->action_group[1],
                0
                );

            gtk_ui_manager_insert_action_group(
                privat->ui_manager,
                privat->action_group[2],
                0
                );
        }

        g_object_notify(G_OBJECT(ctrl), "ui-manager");
    }
}


static void
gpview_company_ctrl_update_0_cb(GObject *unused, GParamSpec *pspec, GPViewCompanyCtrl *ctrl)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(ctrl);

    if (privat != NULL)
    {
        gtk_action_group_set_sensitive(
            privat->action_group[0],
            gparts_database_connected(privat->database)
            );
    }
}


static void
gpview_company_ctrl_update_1_cb(GObject *unused, GParamSpec *pspec, GPViewCompanyCtrl *ctrl)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(ctrl);

    if (privat != NULL)
    {
        gboolean visible = (privat->current_view != NULL);
        gboolean sensitive = visible && gparts_database_connected(privat->database);

        gtk_action_group_set_sensitive(
            privat->action_group[1],
            sensitive
            );

        gtk_action_group_set_visible(
            privat->action_group[1],
            visible
            );
    }
}


static void
gpview_company_ctrl_update_2_cb(GObject *unused, GParamSpec *pspec, GPViewCompanyCtrl *ctrl)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(ctrl);

    if (privat != NULL)
    {
        gboolean visible = (privat->current_view != NULL);
        GStrv websites = gpview_company_view_get_websites(privat->current_view);
        gboolean sensitive = visible && (websites != NULL) && (g_strv_length(websites) > 0);

        g_strfreev(websites);

        gtk_action_group_set_sensitive(
            privat->action_group[2],
            sensitive
            );

        gtk_action_group_set_visible(
            privat->action_group[2],
            visible
            );
    }
}

/* This function sends "failed to create drawable" to the terminal. It
 * seems to be caused by gnome-open and a URL to a website.
 */
static void
gpview_company_ctrl_visit_cb(GtkAction *action, GPViewCompanyCtrl *ctrl)
{
    GPViewCompanyCtrlPrivate *privat = GPVIEW_COMPANY_CTRL_GET_PRIVATE(ctrl);

    if (privat != NULL)
    {
        GStrv websites = gpview_company_view_get_websites(privat->current_view);

        if (websites != NULL)
        {
            GString *command = g_string_new(NULL);
            gchar **temp = websites;

            while (*temp != NULL)
            {
                g_string_printf(
                    command,
                    "gnome-open %s",
                    *temp++
                    );

                g_debug("Command line: %s", command->str);

                g_spawn_command_line_async(command->str, NULL);
            }

            g_string_free(command, TRUE);
            g_strfreev(websites);
        }
    }
}

