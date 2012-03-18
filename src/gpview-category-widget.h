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

/*! \file gparts-category-widget.h
 */

#define GPVIEW_TYPE_CATEGORY_WIDGET (gpview_category_widget_get_type())
#define GPVIEW_CATEGORY_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPVIEW_TYPE_CATEGORY_WIDGET,GPViewCategoryWidget))
#define GPVIEW_CATEGORY_WIDGET_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPVIEW_TYPE_CATEGORY_WIDGET,GPViewCategoryWidgetClass))
#define GPVIEW_IS_CATEGORY_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPVIEW_TYPE_CATEGORY_WIDGET))
#define GPVIEW_IS_CATEGORY_WIDGET_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPVIEW_TYPE_CATEGORY_WIDGET))
#define GPVIEW_CATEGORY_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPVIEW_TYPE_CATEGORY_WIDGET,GPViewCategoryWidgetClass))

/*! \extends GtkScrolledWindow */
struct _GPViewCategoryWidget
{
    GtkScrolledWindow parent;
};

/*! \private */
struct _GPViewCategoryWidgetClass
{
    GtkScrolledWindowClass parent;
};

GType
gpview_category_widget_get_type(void);

GPViewCategoryWidget*
gpview_category_widget_new();


gchar*
gpview_category_widget_get_view_name(GPViewCategoryWidget *widget);

GPartsDatabase*
gpview_category_widget_get_database(GPViewCategoryWidget *widget);

/*! \brief Sets the database.
 *
 *  Sets the database to use for subsequent database operations.
 *
 *  \param [in] controller The controller.
 *  \param [in] database The database to use for subsequent operations.
 */
void
gpview_category_widget_set_database(GPViewCategoryWidget *widget, GPartsDatabase *database);

