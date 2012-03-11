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

/*! \file gpview-view-interface.h
 */

#define GPVIEW_TYPE_VIEW_INTERFACE (gpview_view_interface_get_type())
#define GPVIEW_VIEW_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPVIEW_TYPE_VIEW_INTERFACE,GPViewViewInterface))
#define GPVIEW_IS_VIEW_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPVIEW_TYPE_VIEW_INTERFACE))
#define GPVIEW_VIEW_INTERFACE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE((obj),GPVIEW_TYPE_VIEW_INTERFACE,GPViewViewInterface))

/*! \private
 */
struct _GPViewViewInterface
{
    GTypeInterface parent;

    void (*activate)(GPViewViewInterface *widget);
    void (*deactivate)(GPViewViewInterface *widget);
};

/*! \private */
GType
gpview_view_interface_get_type(void);

void
gpview_view_interface_activate(GPViewViewInterface *widget);

void
gpview_view_interface_deactivate(GPViewViewInterface *widget);

