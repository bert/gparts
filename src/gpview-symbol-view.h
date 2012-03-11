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

/*! \file gpview-symbol-view.h
 */

#define GPVIEW_TYPE_SYMBOL_VIEW (gpview_symbol_view_get_type())
#define GPVIEW_SYMBOL_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPVIEW_TYPE_SYMBOL_VIEW,GPViewSymbolView))
#define GPVIEW_SYMBOL_VIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPVIEW_TYPE_SYMBOL_VIEW,GPViewSymbolViewClass))
#define GPVIEW_IS_SYMBOL_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPVIEW_TYPE_SYMBOL_VIEW))
#define GPVIEW_IS_SYMBOL_VIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPVIEW_TYPE_SYMBOL_VIEW))
#define GPVIEW_SYMBOL_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPVIEW_TYPE_SYMBOL_VIEW,GPViewSymbolViewClass))

/*! \extends GtkContainer */
struct _GPViewSymbolView
{
    GtkHPaned parent;
};

/*! \private */
struct _GPViewSymbolViewClass
{
    GtkHPanedClass parent;
};

/*! \private */
GType
gpview_symbol_view_get_type(void);

GPViewSymbolView*
gpview_symbol_view_new();

void
gpview_symbol_view_refresh(GPViewSymbolView *view);

