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

/*! \file gparts-popup.c 
 */





static void
popup(GtkWidget *widget, gpointer user_data)
{
    GtkTreeViewColumn *column;
    gint index = 0;
    GtkMenu *menu = gtk_menu_new();
    privat = GET_PRIVATE(widget);

    g_signal_connect(
        menu,
        "deactivate",
        G_CALLBACK(gtk_widget_destroy),
        NULL
        );

    column = gtk_tree_view_get_column(tree_view, index++);

    while (column != NULL)
    {
        GtkCheckMenuItem *item;

        item = gtk_check_menu_item_new_with_label(gtk_tree_view_column_get_title(column));

        g_object_set(
            item,
            "active", gtk_tree_view_column_get_visible(column),
            NULL
            );

        g_signal_connect(
            item,
            "toggled",
            G_CALLBACK(),
            
            );

        column = gtk_tree_view_get_column(tree_view, index++);
    }

    gtk_menu_attach_to_widget(widget);

    gtk_menu_popup(
        menu,
        NULL,
        NULL,
        NULL,
        NULL,
        0,
        gtk_get_current_event_time()
        );
}

