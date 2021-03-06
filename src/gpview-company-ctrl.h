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

/*! \file gpview-company-view.h
 */

#define GPVIEW_TYPE_COMPANY_CTRL (gpview_company_ctrl_get_type())
#define GPVIEW_COMPANY_CTRL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPVIEW_TYPE_COMPANY_CTRL,GPViewCompanyCtrl))
#define GPVIEW_COMPANY_CTRL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPVIEW_TYPE_COMPANY_CTRL,GPViewCompanyCtrlClass))
#define GPVIEW_IS_COMPANY_CTRL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPVIEW_TYPE_COMPANY_CTRL))
#define GPVIEW_IS_COMPANY_CTRL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPVIEW_TYPE_COMPANY_CTRL))
#define GPVIEW_COMPANY_CTRL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPVIEW_TYPE_COMPANY_CTRL,GPViewCompanyCtrlClass))

/*! \extends GObject */
struct _GPViewCompanyCtrl
{
    GObject parent;
};

/*! \private */
struct _GPViewCompanyCtrlClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpview_company_ctrl_get_type(void);

/*! \brief Create a new company view controller
 *
 *  Use g_object_unref() on the returned pointer when no longer
 *  needed.
 *
 *  \return A new comapny view controller [transfer full]
 */
GPViewCompanyCtrl*
gpview_company_ctrl_new(void);

/*! \brief Create a new company view controller
 *
 *  Use g_object_unref() on the returned pointer when no longer
 *  needed.
 *
 *  \param [in] manager The ui manager
 *  \return A new comapny view controller [transfer full]
 */
GPViewCompanyCtrl*
gpview_company_ctrl_new_with_manager(GtkUIManager *manager);

/*! \brief Get the current view associated with this controller.
 *
 *  Use g_object_unref() on the returned pointer when no longer
 *  needed.
 *
 *  \param [in] ctrl The controller [allow none]
 *  \return The current view associated with this controller. [transfer full]
 */
GPViewCompanyView*
gpview_company_ctrl_get_current_view(const GPViewCompanyCtrl *ctrl);

/*! \brief Set the database for this controller
 *
 *  Use g_object_unref() on the returned pointer when no longer
 *  needed.
 *
 *  \param [in] ctrl The controller.
 *  \param [in] view The database for this controller. [alow none]
 */
GPartsDatabase*
gpview_comapny_ctrl_get_database(const GPViewCompanyCtrl *ctrl, GPartsDatabase *database);

/*! \brief Get the form factory for this controller
 *
 *  Use g_object_unref() on the returned pointer when no longer
 *  needed.
 *
 *  \param [in] ctrl The controller.
 *  \return The form factory for this controller. [transfer full]
 */
GPFormFactory*
gpview_company_ctrl_get_form_factory(const GPViewCompanyCtrl *ctrl);

/*! \brief Get the UI manger associated with this controller.
 *
 *  Use g_object_unref() on the returned pointer when no longer
 *  needed.
 *
 *  \param [in] ctrl The controller [allow none]
 *  \return The UI manager associated with this controller. [transfer full]
 */
GtkUIManager*
gpview_company_ctrl_get_ui_manager(const GPViewCompanyCtrl *ctrl);

/*! \brief Set the current view for this controller
 *
 *  \param [in] ctrl The controller.
 *  \param [in] view The current view for this controller. [alow none]
 */
void
gpview_company_ctrl_set_current_view(GPViewCompanyCtrl *ctrl, GPViewCompanyView *view);

/*! \brief Set the database for this controller
 *
 *  \param [in] ctrl The controller.
 *  \param [in] view The database for this controller. [alow none]
 */
void
gpview_company_ctrl_set_database(GPViewCompanyCtrl *ctrl, GPartsDatabase *database);

/*! \brief Set the form factory for this controller
 *
 *  \param [in] ctrl The controller.
 *  \param [in] factory The form factory for this controller. [alow none]
 */
void
gpview_company_ctrl_set_form_factory(GPViewCompanyCtrl *ctrl, GPFormFactory *factory);

/*! \brief Set UI manager for this controller
 *
 *  \param [in] ctrl The controller.
 *  \param [in] manager The manager for this controller. [allow none]
 */
void
gpview_company_ctrl_set_ui_manager(GPViewCompanyCtrl *view, GtkUIManager *ui_manager);

