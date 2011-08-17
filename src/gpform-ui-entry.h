/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2011 Edward C. Hennessy
 * Copyright (C) 2011 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpform-ui-entry.h
 */

#define GPFORM_TYPE_UI_ENTRY (gpform_ui_entry_get_type())
#define GPFORM_UI_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPFORM_TYPE_UI_ENTRY,GPFormUIEntry))
#define GPFORM_UI_ENTRY_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPFORM_TYPE_UI_ENTRY,GPFormUIEntryClass))
#define GPFORM_IS_UI_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPFORM_TYPE_UI_ENTRY))
#define GPFORM_IS_UI_ENTRY_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPFORM_TYPE_UI_ENTRY))
#define GPFORM_UI_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPFORM_TYPE_UI_ENTRY,GPFormUIEntryClass))

/*! \extends GtkEntry
 */
struct _GPFormUIEntry
{
    GtkEntry parent;
};

/*! \private
 */
struct _GPFormUIEntryClass
{
    GtkEntryClass parent;
};

/*! \private */
GType
gpform_ui_entry_get_type(void);

/*! \brief Get the label used when no model exists
 *
 *  The caller must free the string using g_free() when no longer needed
 *
 *  \param [in] label The label
 *  \return The default label
 */
char*
gpform_ui_entry_get_default_label(const GPFormUIEntry *label);

/*! \brief Get the model name
 *
 *  The caller must free the string using g_free() when no longer needed
 *
 *  \param [in] label The label
 *  \return The model name
 */
char*
gpform_ui_entry_get_model_name(const GPFormUIEntry *label);

/*! \brief Set the label used when no model exists
 *
 *  \param [in,out] label The label
 *  \param [in] default_label The default label
 */
void
gpform_ui_entry_set_default_label(GPFormUIEntry *label, const char *default_label);

/*! \brief Set the model name
 *
 *  \param [in,out] label The label
 *  \param [in] name The model name
 */
void
gpform_ui_entry_set_model_name(GPFormUIEntry *label, const char *name);

