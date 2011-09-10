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

/*! \file gpform-pm-dialog.h
 */

#define GPFORM_TYPE_PM_DIALOG (gpform_pm_dialog_get_type())
#define GPFORM_PM_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPFORM_TYPE_PM_DIALOG,GPFormUIDialog))
#define GPFORM_PM_DIALOG_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPFORM_TYPE_PM_DIALOG,GPFormUIDialogClass))
#define GPFORM_IS_PM_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPFORM_TYPE_PM_DIALOG))
#define GPFORM_IS_PM_DIALOG_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPFORM_TYPE_PM_DIALOG))
#define GPFORM_PM_DIALOG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPFORM_TYPE_PM_DIALOG,GPFormUIDialogClass))

/*! \extends GObject
 */
struct _GPFormPMDialog
{
    GObject parent;
};

/*! \private
 */
struct _GPFormPMDialogClass
{
    GObjectClass parent;
};

/*! \private */
GType
gpform_pm_dialog_get_type(void);

