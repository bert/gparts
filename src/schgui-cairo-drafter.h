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

/*! \file schgui_cairo_drafter.h
 *
 *  \brief A wrapper for gschem's line.
 */

#define SCHGUI_TYPE_CAIRO_DRAFTER (schgui_cairo_drafter_get_type())
#define SCHGUI_CAIRO_DRAFTER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_CAIRO_DRAFTER,SchGUICairoDrafter))
#define SCHGUI_CAIRO_DRAFTER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_CAIRO_DRAFTER,SchGUICairoDrafterClass))
#define SCHGUI_IS_CAIRO_DRAFTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_CAIRO_DRAFTER))
#define SCHGUI_IS_CAIRO_DRAFTER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_CAIRO_DRAFTER))
#define SCHGUI_CAIRO_DRAFTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_CAIRO_DRAFTER,SchGUICairoDrafterClass))

typedef struct _SchGUICairoDrafter SchGUICairoDrafter;
typedef struct _SchGUICairoDrafterClass SchGUICairoDrafterClass;

struct _SchGUICairoDrafter
{
    GObject parent;
};

struct _SchGUICairoDrafterClass
{
    GObjectClass parent;
};

GType
schgui_cairo_drafter_get_type(void);

void
schgui_cairo_drafter_set_zoom(SchGUICairoDrafter *drafter, double zoom);

int
schgui_cairo_drafter_text_bounds(SchGUICairoDrafter *drafter, SchText *text, GeomBounds *bounds);

void
schgui_cairo_drafter_draw_grid(SchGUICairoDrafter *drafter);

void
schgui_cairo_drafter_draw_to_cairo(SchGUICairoDrafter *drafter, cairo_t *cairo);

void
schgui_cairo_drafter_draw_to_widget(SchGUICairoDrafter *drafter, GtkWidget *widget);

void
schgui_cairo_drafter_set_config(SchGUICairoDrafter *drafter, SchGUIDrawingCfg *config);

void
schgui_cairo_drafter_set_drawing(SchGUICairoDrafter *drafter, SchDrawing *drawing);

void
schgui_cairo_drafter_zoom_extents(SchGUICairoDrafter *drafter, GtkWidget *widget);

