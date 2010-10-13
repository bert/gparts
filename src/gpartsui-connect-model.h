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

/*! \file gpartsui-connect-model.h
 *
 *  A presentation model for the transient data needed to connect to a
 *  database. The presentation model does not include and GUI or domain
 *  logic.
 */

#define GPARTSUI_TYPE_CONNECT_MODEL (gpartsui_connect_model_get_type())
#define GPARTSUI_CONNECT_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTSUI_TYPE_CONNECT_MODEL,GPartsUIConnectModel))
#define GPARTSUI_CONNECT_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTSUI_TYPE_CONNECT_MODEL,GPartsUIConnectModelClass))
#define GPARTSUI_IS_CONNECT_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTSUI_TYPE_CONNECT_MODEL))
#define GPARTSUI_IS_CONNECT_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTSUI_TYPE_CONNECT_MODEL))
#define GPARTSUI_CONNECT_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTSUI_TYPE_CONNECT_MODEL,GPartsUIConnectModelClass))

struct _GPartsUIConnectModel
{
    GObject parent;
};

/*! \private */
struct _GPartsUIConnectModelClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpartsui_connect_model_get_type(void);

/*! \brief Connect to the database
 *
 *  \param [in] model
 *  \param [out] error The error, if any, using the GError protocol.
 */
void
gpartsui_connect_model_connect(GPartsUIConnectModel *model, GError **error);

/*! \brief Get the current database presentation model.
 *
 *  When no longer needed, call g_object_unref() with the returned pointer.
 *
 *  \param [in] model
 *  \return A pointer to the database presentation model.
 */
GPartsUIDatabaseModel*
gpartsui_connect_model_get_database_model(const GPartsUIConnectModel *model);

/*! \brief Get the current database name.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
    \return A string containing the name of the database to connect to.
 */
gchar*
gpartsui_connect_model_get_database_name(const GPartsUIConnectModel *model);

/*! \brief Get the validity of the current database name.
 *
 *  \param [in] model
 *  \retval TRUE The current database name is valid.
 *  \retval FALSE The current database name is invalid.
 */
gboolean
gpartsui_connect_model_get_database_name_valid(const GPartsUIConnectModel *model);

/*! \brief Get the current database type.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
 *  \return A NULL terminated list of strings with the available database
 *  types.
 */
gchar*
gpartsui_connect_model_get_database_type(const GPartsUIConnectModel *model);

/*! \brief Get a list of the available database types.
 *
 *  When no longer needed, call g_strfreev() with the returned pointer.
 *
 *  \param [in] model
 *  \return A NULL terminated list of strings with the available database
 *  types.
 */
GStrv
gpartsui_connect_model_get_database_types(const GPartsUIConnectModel *model);

/*! \brief Get the current filename.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
 *  \return  A string containing the name of the database to open.
 */
gchar*
gpartsui_connect_model_get_filename(const GPartsUIConnectModel *model);

/*! \brief Get the validity of the current filename.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
 *  \retval TRUE The current database name is valid.
 *  \retval FALSE The current database name is invalid.
 */
gboolean
gpartsui_connect_model_get_filename_valid(const GPartsUIConnectModel *model);

/*! \brief Get the current hostname.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
 *  \return A sting continaing the host name of the database to
 *  connect to.
 */
gchar*
gpartsui_connect_model_get_hostname(const GPartsUIConnectModel *model);

/*! \brief Get the validity of the current hostname.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
 *  \retval TRUE The current database name is valid.
 *  \retval FALSE The current database name is invalid.
 */
gboolean
gpartsui_connect_model_get_hostname_valid(const GPartsUIConnectModel *model);

/*! \brief Get the current password.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
 *  \return  A string containing the password used to connect to
 *  the database.
 */
gchar*
gpartsui_connect_model_get_password(const GPartsUIConnectModel *model);

/*! \brief Get the validity of the current password.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
 *  \retval TRUE The current database name is valid.
 *  \retval FALSE The current database name is invalid.
 */
gboolean
gpartsui_connect_model_get_password_valid(const GPartsUIConnectModel *model);

/*! \brief Get the current username.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
 *  \return  A string containing the username used to connect to
 *  the database.
 */
gchar*
gpartsui_connect_model_get_username(const GPartsUIConnectModel *model);

/*! \brief Get the validity of the current username.
 *
 *  When no longer needed, call g_free() with the returned pointer.
 *
 *  \param [in] model
 *  \retval TRUE The current database name is valid.
 *  \retval FALSE The current database name is invalid.
 */
gboolean
gpartsui_connect_model_get_username_valid(const GPartsUIConnectModel *model);

/*! \brief Set database presentation model.
 *
 *  \param [in] cmodel The database connect presentation model.
 *  \param [in] dmodel The database presentation model.
 */
void
gpartsui_connect_model_set_database_model(GPartsUIConnectModel *cmodel, GPartsUIDatabaseModel *dmodel);

/*! \brief Set the current database type.
 *
 *  \param [in] model
 *  \param [in] name  The name of the current database type.
 */
void
gpartsui_connect_model_set_database_type(GPartsUIConnectModel *model, const gchar *name);

/*! \brief Set the filename for loading a file based database
 *
 *  \param [in] model
 *  \param [in] filename The filename to load the database from.
 */
void
gpartsui_connect_model_set_filename(GPartsUIConnectModel *model, const gchar *filename);


/*! \brief Set the hostname for connecting to the database
 *
 *  \param [in] model
 *  \param [in] hostname The hostname to use to connect to the database.
 */
void
gpartsui_connect_model_set_hostname(GPartsUIConnectModel *model, const gchar *hostname);

/*! \brief Set the password for connecting to the database
 *
 *  \param [in] model
 *  \param [in] password The password to use to connect to the database.
 */
void
gpartsui_connect_model_set_password(GPartsUIConnectModel *model, const gchar *password);

/*! \brief Set the username for connecting to the database
 *
 *  \param [in] model
 *  \param [in] username The username to use to connect to the database.
 */
void
gpartsui_connect_model_set_username(GPartsUIConnectModel *model, const gchar *username);

