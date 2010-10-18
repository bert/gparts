/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2010 Edward C. Hennessy
 * Copyright (C) 2010 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpartsui-database-model.h
 *
 *  The presentation model for a database connection. The presentation model
 *  does not contain and domain logic or GUI code.
 */

#define GPARTSUI_TYPE_DATABASE_MODEL (gpartsui_database_model_get_type())
#define GPARTSUI_DATABASE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTSUI_TYPE_DATABASE_MODEL,GPartsUIDatabaseModel))
#define GPARTSUI_DATABASE_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTSUI_TYPE_DATABASE_MODEL,GPartsUIDatabaseModelClass))
#define GPARTSUI_IS_DATABASE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTSUI_TYPE_DATABASE_MODEL))
#define GPARTSUI_IS_DATABASE_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTSUI_TYPE_DATABASE_MODEL))
#define GPARTSUI_DATABASE_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTSUI_TYPE_DATABASE_MODEL,GPartsUIDatabaseModelClass))

struct _GPartsUIDatabaseModel
{
    GObject parent;
};

/*! \private */
struct _GPartsUIDatabaseModelClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpartsui_database_model_get_type(void);

/*! \brief Gets the state of the database connection
 *
 *  This object will send a notify signal for this property's state
 *  changes, allowig the UI to react accordinly.
 *
 *  \param [in] model The database presentation model.
 *  \retval TRUE The database is connected.
 *  \retval FALSE The database is not connected.
 */
gboolean
gpartsui_database_model_get_connected(const GPartsUIDatabaseModel *model);

/*! \brief Get the state for the GUI disconnect widget.
 *
 *  \param [in] model The database presentation model.
 *  \retval TRUE The GUI control to disconnect the database should be enabled.
 *  \retval FALSE The GUI control to disconnect the database should be disabled.
 */
gboolean
gpartsui_database_model_get_disconnect_sensitive(const GPartsUIDatabaseModel *model);

/*! \brief Get the state for the GUI drop widget.
 *
 *  \param [in] model The database presentation model.
 *  \retval TRUE The GUI control to drop the database should be enabled.
 *  \retval FALSE The GUI control to drop the database should be disabled.
 */
gboolean
gpartsui_database_model_get_drop_sensitive(const GPartsUIDatabaseModel *model);

/*! \brief Get the database domain model.
 *
 *  \param [in] model The database presentation model.
 *  \return A pointer to the database domain model. When no longer needed,
 *  call g_object_unref() on the returned pointer.
 */
GPartsDatabase*
gpartsui_database_model_get_database(const GPartsUIDatabaseModel *model);

/*! \brief Disconnect from the current database.
 *
 *  \param [in] model The database presentation model.
 *  \param [out] model The error, if any, using the GError protocol.
 */
void
gpartsui_database_model_disconnect(const GPartsUIDatabaseModel *model, GError **error);

/*! \brief Drop the current database.
 *
 *  Deletes the current database and all the data in it.
 *
 *  \param [in] model The database presentation model.
 *  \param [out] model The error, if any, using the GError protocol.
 */
void
gpartsui_database_model_drop(const GPartsUIDatabaseModel *model, GError **error);

/*! \brief Refresh views to the current database.
 *
 *  \param [in] model The database presentation model.
 */
void
gpartsui_database_model_refresh(const GPartsUIDatabaseModel *model, GError **error);

/*! \brief Set the database domain model.
 *
 *  \param [in] model The database presentation model.
 *  \param [in] database The database domain model.
 */
void
gpartsui_database_model_set_database(GPartsUIDatabaseModel *model,GPartsDatabase* database);


MiscUIActionModel*
gpartsui_database_model_get_disconnect_action_model(const GPartsUIDatabaseModel *model);

MiscUIActionModel*
gpartsui_database_model_get_drop_action_model(const GPartsUIDatabaseModel *model);

MiscUIActionModel*
gpartsui_database_model_get_refresh_action_model(const GPartsUIDatabaseModel *model);

