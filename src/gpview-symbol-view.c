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

/*! \file gpview-symbol-view.c
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "schgui.h"
#include "gparts.h"
#include "gpform.h"
#include "gpview.h"

#define GPVIEW_SYMBOL_VIEW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPVIEW_TYPE_SYMBOL_VIEW,GPViewSymbolViewPrivate))

enum
{
    GPVIEW_SYMBOL_VIEW_CONTROLLER = 1,
    GPVIEW_SYMBOL_VIEW_DATABASE,
    GPVIEW_SYMBOL_VIEW_RESULT,
    GPVIEW_SYMBOL_VIEW_SYMBOL_IDS,
    GPVIEW_SYMBOL_VIEW_SYMBOL_NAMES
};

typedef struct _GPViewSymbolViewPrivate GPViewSymbolViewPrivate;

struct _GPViewSymbolViewPrivate
{
    GPViewResultAdapter  *adapter;
    GPViewSymbolCtrl     *controller;
    GPartsDatabase       *database;
    GPartsDatabaseResult *result;
    GtkTreeSelection     *selection;

    SchGUIDrawingView    *drawing_view;
    GtkTreeView          *symbol_view;
};

static void
gpview_symbol_view_activate(GPViewViewInterface *widget);

static void
gpview_symbol_view_class_init(gpointer g_class, gpointer g_class_data);

static void
gpview_symbol_view_deactivate(GPViewViewInterface *widget);

static void
gpview_symbol_view_dispose(GObject *object);

static void
gpview_symbol_view_finalize(GObject *object);

static void
gpview_symbol_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpview_symbol_view_init(GTypeInstance *instance, gpointer g_class);

static void
gpview_symbol_view_init_view_interface(gpointer iface, gpointer user_data);

static void
gpview_symbol_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gpview_symbol_view_set_result(GPViewSymbolView *view, GPartsDatabaseResult *result);

static void
gpview_symbol_view_update_cb(GObject *unused, GParamSpec *pspec, GPViewSymbolView *view);

static void
gpview_symbol_view_update2_cb(GObject *unused, GParamSpec *pspec, GPViewSymbolView *view);



static void
gpview_symbol_view_activate(GPViewViewInterface *widget)
{
    GPViewSymbolView *view = GPVIEW_SYMBOL_VIEW(widget);

    if (view == NULL)
    {
        g_critical("Unable to obatain an instance from GPViewViewInterface");
    }
    else
    {
        GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);

        if (privat == NULL)
        {
            g_critical("Unable to obtain private data for a GPViewSymbolView");
        }
        else if (privat->controller == NULL)
        {
            g_critical("GPViewSymbolView has a NULL controller");
        }
        else
        {
            gpview_symbol_ctrl_set_current_view(privat->controller, view);
        }
    }
}

static void
gpview_symbol_view_changed_cb(GtkTreeSelection *selection, GPViewCompanyView *view)
{
    if (view != NULL)
    {
        g_object_notify(G_OBJECT(view), "symbol-ids");
        g_object_notify(G_OBJECT(view), "symbol-names");
    }
}

static void
gpview_symbol_view_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPViewSymbolViewPrivate));

    klasse->dispose = gpview_symbol_view_dispose;
    klasse->finalize = gpview_symbol_view_finalize;

    klasse->get_property = gpview_symbol_view_get_property;
    klasse->set_property = gpview_symbol_view_set_property;

    g_object_class_install_property(
        klasse,
        GPVIEW_SYMBOL_VIEW_CONTROLLER,
        g_param_spec_object(
            "controller",
            "Controller",
            "Controller",
            GPVIEW_TYPE_SYMBOL_CTRL,
            G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );


    g_object_class_install_property(
        klasse,
        GPVIEW_SYMBOL_VIEW_DATABASE,
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
        GPVIEW_SYMBOL_VIEW_RESULT,
        g_param_spec_object(
            "result",
            "Result",
            "Result",
            GPARTS_TYPE_DATABASE_RESULT,
            G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        GPVIEW_SYMBOL_VIEW_SYMBOL_IDS,
        g_param_spec_boxed(
            "symbol-ids",
            "Symbol IDs",
            "Symbol IDs",
            G_TYPE_STRV,
            G_PARAM_LAX_VALIDATION | G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );

     g_object_class_install_property(
        klasse,
        GPVIEW_SYMBOL_VIEW_SYMBOL_NAMES,
        g_param_spec_boxed(
            "symbol-names",
            "Symbol Names",
            "Symbol Names",
            G_TYPE_STRV,
            G_PARAM_LAX_VALIDATION | G_PARAM_READABLE | G_PARAM_STATIC_STRINGS
            )
        );
}


static void
gpview_symbol_view_deactivate(GPViewViewInterface *widget)
{
    GPViewSymbolView *view = GPVIEW_SYMBOL_VIEW(widget);

    if (view == NULL)
    {
        g_critical("Unable to obatain an instance from GPViewViewInterface");
    }
    else
    {
        GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);

        if (privat == NULL)
        {
            g_critical("Unable to obtain private data for a GPViewSymbolView");
        }
        else if (privat->controller == NULL)
        {
            g_critical("GPViewSymbolView has a NULL controller");
        }
        else
        {
            gpview_symbol_ctrl_set_current_view(privat->controller, NULL);
        }
    }
}


static void
gpview_symbol_view_dispose(GObject *object)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(object);

    if (privat != NULL)
    {
        misc_object_unref(privat->adapter);
        privat->adapter = NULL;

        misc_object_unref(privat->controller);
        privat->controller = NULL;

        misc_object_unref(privat->database);
        privat->database = NULL;

        misc_object_unref(privat->result);
        privat->result = NULL;
    }

    misc_object_chain_dispose(object);
}


static void
gpview_symbol_view_finalize(GObject *object)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(object);

    if (privat != NULL)
    {
        //g_strfreev(privat->symbol_ids);
        //g_strfreev(privat->symbol_names);
    }

    misc_object_chain_finalize(object);
}


GPartsDatabase*
gpview_symbol_view_get_database(GPViewSymbolView *view)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);
    GPartsDatabase *database = NULL;

    if (privat != NULL)
    {
        database = privat->database;

        if (database != NULL)
        {
            g_object_ref(G_OBJECT(database));
        }
    }

    return database;
}


static void
gpview_symbol_view_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPViewSymbolView *view = GPVIEW_SYMBOL_VIEW(object);

    if (view != NULL)
    {
        switch (property_id)
        {
            case GPVIEW_SYMBOL_VIEW_DATABASE:
                g_value_take_object(value, gpview_symbol_view_get_database(view));
                break;

            case GPVIEW_SYMBOL_VIEW_RESULT:
                g_value_take_object(value, gpview_symbol_view_get_result(view));
                break;

            case GPVIEW_SYMBOL_VIEW_SYMBOL_IDS:
                g_value_take_boxed(value, gpview_symbol_view_get_symbol_ids(view));
                break;

            case GPVIEW_SYMBOL_VIEW_SYMBOL_NAMES:
                g_value_take_boxed(value, gpview_symbol_view_get_symbol_names(view));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}


GPartsDatabaseResult*
gpview_symbol_view_get_result(GPViewSymbolView *view)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);
    GPartsDatabaseResult *result = NULL;

    if (privat != NULL)
    {
        result = privat->result;

        if (result != NULL)
        {
            g_object_ref(G_OBJECT(result));
        }
    }

    return result;
}


GStrv
gpview_symbol_view_get_symbol_ids(GPViewSymbolView *view)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);
    GStrv ids = NULL;

    if (privat != NULL)
    {
        gint index;

        if (gpview_result_adapter_get_column_index(privat->adapter, "SymbolID", &index))
        {
            ids = gpview_result_adapter_get_fields(privat->adapter, privat->selection, index);
        }
    }

    return ids;
}


GStrv
gpview_symbol_view_get_symbol_names(GPViewSymbolView *view)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);
    GStrv names = NULL;

    if (privat != NULL)
    {
        gint index;

        if (gpview_result_adapter_get_column_index(privat->adapter, "SymbolName", &index))
        {
            names = gpview_result_adapter_get_fields(privat->adapter, privat->selection, index);
        }
    }

    return names;
}


GType
gpview_symbol_view_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPViewSymbolViewClass),    /* class_size */
            NULL,                             /* base_init */
            NULL,                             /* base_finalize */
            gpview_symbol_view_class_init,    /* class_init */
            NULL,                             /* class_finalize */
            NULL,                             /* class_data */
            sizeof(GPViewSymbolView),         /* instance_size */
            0,                                /* n_preallocs */
            gpview_symbol_view_init,          /* instance_init */
            NULL                              /* value_table */
            };

        static const GInterfaceInfo iinfo = {
            gpview_symbol_view_init_view_interface,    /* interface_init */
            NULL,                                      /* interface_finalize */
            NULL                                       /* interface_data */
            };

        type = g_type_register_static(
            GTK_TYPE_HPANED,
            "GPViewSymbolView",
            &tinfo,
            0
            );

        g_type_add_interface_static(type, GPVIEW_TYPE_VIEW_INTERFACE, &iinfo);
    }

    return type;
}


static void
gpview_symbol_view_init(GTypeInstance *instance, gpointer g_class)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        GtkWidget *scrolled;

        privat->symbol_view = GTK_TREE_VIEW(gtk_tree_view_new());

        privat->selection = gtk_tree_view_get_selection(privat->symbol_view);

        gtk_tree_selection_set_mode(
            privat->selection,
            GTK_SELECTION_MULTIPLE
            );

        g_signal_connect(
            privat->selection,
            "changed",
            G_CALLBACK(gpview_symbol_view_changed_cb),
            instance
            );

        scrolled = gtk_scrolled_window_new(
            NULL,    /* hadjustment */
            NULL     /* vadjustment */
            );

        gtk_scrolled_window_set_policy(
            GTK_SCROLLED_WINDOW(scrolled),
            GTK_POLICY_AUTOMATIC,   /* hscrollbar_policy */
            GTK_POLICY_AUTOMATIC    /* vscrollbar_policy */
            );

        gtk_container_add(
            GTK_CONTAINER(scrolled),
            GTK_WIDGET(privat->symbol_view)
            );

        gtk_container_add(
            GTK_CONTAINER(instance),
            GTK_WIDGET(scrolled)
            );

        privat->drawing_view = schgui_drawing_view_new();

        gtk_container_add(
            GTK_CONTAINER(instance),
            GTK_WIDGET(privat->drawing_view)
            );

        /* TODO: Fix default position */

        gtk_paned_set_position(
            GTK_PANED(instance),
            600
            );

        g_signal_connect(
            instance,
            "notify::database",
            G_CALLBACK(gpview_symbol_view_update_cb),
            instance
            );

        g_signal_connect(
            instance,
            "notify::symbol-names",
            G_CALLBACK(gpview_symbol_view_update2_cb),
            instance
            );
    }
}


static void
gpview_symbol_view_init_view_interface(gpointer iface, gpointer user_data)
{
    GPViewViewInterface *iface2 = (GPViewViewInterface*) iface;

    iface2->activate   = gpview_symbol_view_activate;
    iface2->deactivate = gpview_symbol_view_deactivate;
}


GPViewSymbolView*
gpview_symbol_view_new()
{
    return GPVIEW_SYMBOL_VIEW(g_object_new(GPVIEW_TYPE_SYMBOL_VIEW, NULL));
}

GPViewSymbolView*
gpview_symbol_view_new_with_controller(GPViewSymbolCtrl *ctrl)
{
    return GPVIEW_SYMBOL_VIEW(g_object_new(
        GPVIEW_TYPE_SYMBOL_VIEW,
        "controller", ctrl,
        NULL
        ));
}

void
gpview_symbol_view_set_controller(GPViewSymbolView *view, GPViewSymbolCtrl *ctrl)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);

    if (privat != NULL)
    {
        if (privat->controller != NULL)
        {
            //g_signal_handlers_disconnect_by_func(
            //    privat->database,
            //    G_CALLBACK(gpview_company_view_notify_connected_cb),
            //    view
            //    );

            g_object_unref(privat->controller);
        }

        privat->controller = ctrl;

        if (privat->controller != NULL)
        {
            g_object_ref(privat->controller);

            //g_signal_connect(
            //    privat->database,
            //    "notify::connected",
            //    G_CALLBACK(gpview_company_view_notify_connected_cb),
            //    view
            //    );
        }

        g_object_notify(G_OBJECT(view), "controller");
    }
}


void
gpview_symbol_view_set_database(GPViewSymbolView *view, GPartsDatabase *database)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);

    g_debug("set_database");

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            g_signal_handlers_disconnect_by_func(
                privat->database,
                G_CALLBACK(gpview_symbol_view_update_cb),
                view
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
                G_CALLBACK(gpview_symbol_view_update_cb),
                view
                );
        }

        g_object_notify(G_OBJECT(view), "database");
    }
}


static void
gpview_symbol_view_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPViewSymbolView *view = GPVIEW_SYMBOL_VIEW(object);

    if (view != NULL)
    {
        switch (property_id)
        {
            case GPVIEW_SYMBOL_VIEW_CONTROLLER:
                gpview_symbol_view_set_controller(view, g_value_get_object(value));
                break;

            case GPVIEW_SYMBOL_VIEW_DATABASE:
                gpview_symbol_view_set_database(view, g_value_get_object(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}


static void
gpview_symbol_view_set_result(GPViewSymbolView *view, GPartsDatabaseResult *result)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);

    if (privat != NULL)
    {
        if (privat->adapter != NULL)
        {
            g_object_unref(privat->adapter);
        }

        if (privat->result != NULL)
        {
            g_object_unref(privat->result);
        }

        privat->adapter = NULL;
        privat->result = result;

        if (privat->result != NULL)
        {
            g_object_ref(privat->result);

            privat->adapter = gpview_result_adapter_new(privat->result);

            if (privat->adapter != NULL)
            {
                gpview_result_adapter_adjust_columns(privat->adapter, privat->symbol_view);
            }

            gtk_tree_view_set_model(privat->symbol_view, GTK_TREE_MODEL(privat->adapter));

            if (privat->adapter != NULL)
            {
                gint index;

                if (gpview_result_adapter_get_column_index(privat->adapter, "SymbolName", &index))
                {
                    gtk_tree_view_set_search_column(privat->symbol_view, index);
                }
            }
        }

        g_object_notify(G_OBJECT(view), "symbol-ids");
        g_object_notify(G_OBJECT(view), "symbol-names");
        g_object_notify(G_OBJECT(view), "result");
    }
}


static void
gpview_symbol_view_update_cb(GObject *unused, GParamSpec *pspec, GPViewSymbolView *view)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);

    if (privat != NULL)
    {
        if (privat->database != NULL)
        {
            GPartsDatabaseResult *result;

            result = gparts_database_query(privat->database, "SELECT * FROM SymbolV", NULL);

            gpview_symbol_view_set_result(view, result);

            if (result != NULL)
            {
                g_object_unref(G_OBJECT(result));
            }
        }
    }
}

static void
gpview_symbol_view_update2_cb(GObject *unused, GParamSpec *pspec, GPViewSymbolView *view)
{
    GPViewSymbolViewPrivate *privat = GPVIEW_SYMBOL_VIEW_GET_PRIVATE(view);

    if (privat != NULL)
    {
        SchDrawing   *drawing = NULL;
        GStrv names = gpview_symbol_view_get_symbol_names(view);

        if ((names != NULL) && (g_strv_length(names) == 1))
        {
            SchComponent *component = NULL;
            SchLoader    *loader = sch_loader_get_default();
            SchDrawing   *symbol = NULL;

            if (loader != NULL)
            {
                symbol = sch_loader_load_symbol(loader, *names, NULL);
            }

            component = sch_component_instantiate(sch_config_new(), symbol);
            misc_object_unref(symbol);

            if (component != NULL)
            {
                drawing = sch_drawing_new();
                sch_drawing_append_shape(drawing, SCH_SHAPE(component));
                g_object_unref(component);
            }
        }

        schgui_drawing_view_set_drawing(privat->drawing_view, drawing);
        misc_object_unref(drawing);
        g_strfreev(names);
    }
}

