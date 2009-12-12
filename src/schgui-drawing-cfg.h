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

/*! \file schgui-drawing-cfg.h
 */

#define SCHGUI_TYPE_DRAWING_CFG (schgui_drawing_cfg_get_type())
#define SCHGUI_DRAWING_CFG(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_DRAWING_CFG,SchGUIDrawingCfg))
#define SCHGUI_DRAWING_CFG_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_DRAWING_CFG,SchGUIDrawingCfgClass))
#define SCHGUI_IS_DRAWING_CFG(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_DRAWING_CFG))
#define SCHGUI_IS_DRAWING_CFG_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_DRAWING_CFG))
#define SCHGUI_DRAWING_CFG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_DRAWING_CFG,SchGUIDrawingCfgClass))

typedef struct _SchGUIDrawingCfg SchGUIDrawingCfg;
typedef struct _SchGUIDrawingCfgClass SchGUIDrawingCfgClass;

struct _SchGUIDrawingCfg
{
    GObject parent;
};

struct _SchGUIDrawingCfgClass
{
    GObjectClass parent;
};

GType
schgui_drawing_cfg_get_type(void);

void
schgui_drawing_cfg_get_bus_line_width(SchGUIDrawingCfg *cfg, double *width);

void
schgui_drawing_cfg_get_display_color(SchGUIDrawingCfg *cfg, int index, double *red, double *green, double *blue);

void
schgui_drawing_cfg_get_net_line_width(SchGUIDrawingCfg *cfg, double *width);

void
schgui_drawing_cfg_get_pin_line_width(SchGUIDrawingCfg *cfg, double *width);

void
schgui_drawing_cfg_get_print_color(SchGUIDrawingCfg *cfg, int index, double *red, double *green, double *blue);

void
schgui_drawing_cfg_get_output_line_width(SchGUIDrawingCfg *cfg, int shape_width, double *output_width);

