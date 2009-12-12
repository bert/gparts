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

/*! \file schgui_drawing_view.h
 */

#define SCHGUI_TYPE_DRAWING_VIEW (schgui_drawing_view_get_type())
#define SCHGUI_DRAWING_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_DRAWING_VIEW,SchGUIDrawingView))
#define SCHGUI_DRAWING_VIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_DRAWING_VIEW,SchGUIDrawingViewClass))
#define SCHGUI_IS_DRAWING_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_DRAWING_VIEW))
#define SCHGUI_IS_DRAWING_VIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_DRAWING_VIEW))
#define SCHGUI_DRAWING_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_DRAWING_VIEW,SchGUIDrawingViewClass))

typedef struct _SchGUIDrawingView SchGUIDrawingView;
typedef struct _SchGUIDrawingViewClass SchGUIDrawingViewClass;

struct _SchGUIDrawingView
{
    GtkBin parent;
};

struct _SchGUIDrawingViewClass
{
    GtkBinClass parent;
};

GType
schgui_drawing_view_get_type(void);

void
schgui_drawing_view_set_drafter(SchGUIDrawingView *widget, SchGUICairoDrafter *drafter);

void
schgui_drawing_view_set_drawing(SchGUIDrawingView *widget, SchDrawing *drawing);

void
schgui_drawing_view_zoom_extents(SchGUIDrawingView *widget);

