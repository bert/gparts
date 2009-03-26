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

/*! \file gparts-category-controller.h
 *
 *  \brief A controller for the specialized category model and its GUI view.
 *
 *  GtkTreeViews do not handle multiple changes well.  So, when changes occur
 *  to the model's data, the controller creates an new model and places it in
 *  the GUI view.  The old model gets disposed.
 */

#define GPARTS_TYPE_CATEGORY_CONTROLLER (gparts_category_controller_get_type())
#define GPARTS_CATEGORY_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_CATEGORY_CONTROLLER,GPartsCategoryController))
#define GPARTS_CATEGORY_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_CATEGORY_CONTROLLER,GPartsCategoryControllerClass))
#define GPARTS_IS_CATEGORY_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_CATEGORY_CONTROLLER))
#define GPARTS_IS_CATEGORY_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_CATEGORY_CONTROLLER))
#define GPARTS_CATEGORY_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_CATEGORY_CONTROLLER,GPartsCategoryControllerClass))

typedef struct _GPartsCategoryController GPartsCategoryController;
typedef struct _GPartsCategoryControllerClass GPartsCategoryControllerClass;

struct _GPartsCategoryController
{
    GObject parent;
};

struct _GPartsCategoryControllerClass
{
    GObjectClass parent;
};

GType
gparts_category_controller_get_type(void);

GPartsCategoryController*
gparts_category_controller_new();

/*! \brief Sets the database.
 *
 *  Sets the database to use for subsequent database operations.
 *
 *  \param [in] controller The controller.
 *  \param [in] database The database to use for subsequent operations.
 */
void
gparts_category_controller_set_database(GPartsCategoryController *query, GPartsDatabase *database);

/*! \brief Sets the target view for results from database queries.
 *
 *  \param [in] controller The controller.
 *  \param [in] target A GtkTreeView to place database query results into.
 */
void
gparts_category_controller_set_target(GPartsCategoryController *query, GtkTreeView *target);

