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

/*! \file gpform-ui-image.h
 */

#define GPFORM_TYPE_UI_IMAGE (gpform_ui_image_get_type())
#define GPFORM_UI_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPFORM_TYPE_UI_IMAGE,GPFormUIImage))
#define GPFORM_UI_IMAGE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPFORM_TYPE_UI_IMAGE,GPFormUIImageClass))
#define GPFORM_IS_UI_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPFORM_TYPE_UI_IMAGE))
#define GPFORM_IS_UI_IMAGE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPFORM_TYPE_UI_IMAGE))
#define GPFORM_UI_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPFORM_TYPE_UI_IMAGE,GPFormUIImageClass))

/*! \extends GtkImage
 */
struct _GPFormUIImage
{
    GtkImage parent;
};

/*! \private
 */
struct _GPFormUIImageClass
{
    GtkImageClass parent;
};

/*! \private */
GType
gpform_ui_image_get_type(void);

void
gpform_ui_image_set_from_file(GPFormUIImage *image, const gchar *filename);

