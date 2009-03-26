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

/*! \file gparts-result-controller.h
 *
 *  \brief A controller for syncronizing database views and GUI views.
 *
 *  GtkTreeViews do not handle multiple changes well.  So, when changes occur
 *  to the model's data, the controller creates an new model and places it in
 *  the GUI view.  The old model gets disposed.
 *
 *  \note
 *  When making multiple changes to the properties of this controller, some
 *  combinations of values may produce errors.  To prevent the GUI view from
 *  getting refreshed with properties that are out-of-sync, temporarily set one
 *  of the properties to NULL.  This value will prevent the view from getting
 *  refreshed.  After makeing all the other property changes, set the NULL
 *  property back to a valid value.
 */

#define GPARTS_TYPE_RESULT_CONTROLLER (gparts_result_controller_get_type())
#define GPARTS_RESULT_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_RESULT_CONTROLLER,GPartsResultController))
#define GPARTS_RESULT_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_RESULT_CONTROLLER,GPartsResultControllerClass))
#define GPARTS_IS_RESULT_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_RESULT_CONTROLLER))
#define GPARTS_IS_RESULT_CONTROLLER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_RESULT_CONTROLLER))
#define GPARTS_RESULT_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_RESULT_CONTROLLER,GPartsResultControllerClass))

typedef struct _GPartsResultController GPartsResultController;
typedef struct _GPartsResultControllerClass GPartsResultControllerClass;

struct _GPartsResultController
{
    GObject parent;
};

struct _GPartsResultControllerClass
{
    GObjectClass parent;
};

GType
gparts_result_controller_get_type(void);


void
gparts_result_controller_refresh(GPartsResultController *controller);

void
gparts_result_controller_set_customize_ctrl(GPartsResultController *controller, GPartsCustomizeCtrl *customize_ctrl);

/*! \brief Sets the database.
 *
 *  Sets the database to use for subsequent database operations.
 *
 *  \param [in] controller The controller.
 *  \param [in] database The database to use for subsequent operations.
 */
void
gparts_result_controller_set_database_ctrl(GPartsResultController *controller, GPartsLoginCtrl *database);

/*! \brief Sets the source view for data used by field expansion.
 *
 *  If this controller does not use field expansion for any operations, then
 *  the source may be set to NULL.
 *
 *  \param [in] controller The controller.
 *  \param [in] source
 */
void
gparts_result_controller_set_source(GPartsResultController *controller, GObject *soruce);

/*! \brief Sets the target view for results from database queries.
 *
 *  \param [in] controller The controller.
 *  \param [in] target A GtkTreeView to place database query results into.
 */
void
gparts_result_controller_set_target(GPartsResultController *controller, GtkTreeView *target);

/*! \brief Sets the SQL template string for database queries.
 *
 *  This property contains the SQL statement to execute for database queries.
 *
 *  If the SQL statement depends on data from the selection in another view,
 *  then the source property must be set to the view that contains the data.
 *  The column names of the data must be placed within the statement with
 *  delimiters: $(column_name).
 *
 *  Until the expansion logic gets more sophisticated, the name of the database
 *  view within the statement must be %s, just as the printf format.
 *
 *  \param [in] controller The controller.
 *  \param [in] template The SQL template string.
 */
void
gparts_result_controller_set_template(GPartsResultController *controller, const gchar *template);

/*! \brief Sets the name of the database view.
 *
 *  Sets the name of the database view for this controller's subsequent
 *  database operations.
 *
 *  If the name of the view depends on data from the source selection, then
 *  place the column name in delimiters for field expansion: $(column_name).
 *
 *  \param [in] controller The controller.
 *  \param [in] view_name The name of the view for database operations.
 */
void
gparts_result_controller_set_result_name(GPartsResultController *controller, const gchar *view_name);

