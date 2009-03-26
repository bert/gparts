



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

