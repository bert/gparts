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

/*! \file schgui-cairo-net.h
 */

#define SCHGUI_TYPE_CAIRO_NET (schgui_cairo_net_get_type())
#define SCHGUI_CAIRO_NET(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_CAIRO_NET,SchGUICairoNet))
#define SCHGUI_CAIRO_NET_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_CAIRO_NET,SchGUICairoNetClass))
#define SCHGUI_IS_CAIRO_NET(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_CAIRO_NET))
#define SCHGUI_IS_CAIRO_NET_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_CAIRO_NET))
#define SCHGUI_CAIRO_NET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_CAIRO_NET,SchGUICairoNetClass))

typedef struct _SchGUICairoNet SchGUICairoNet;
typedef struct _SchGUICairoNetClass SchGUICairoNetClass;

struct _SchGUICairoNet
{
    SchGUICairoDrawItem parent;
};

struct _SchGUICairoNetClass
{
    SchGUICairoDrawItemClass parent;
};

GType
schgui_cairo_net_get_type(void);

SchGUICairoNet*
schgui_cairo_net_new(const SchNet *shape, SchGUIDrawingCfg *config);

