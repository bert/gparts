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
typedef struct _SchGUIDrawingCfgColor SchGUIDrawingCfgColor;

struct _SchGUIDrawingCfg
{
    GObject parent;
};

struct _SchGUIDrawingCfgClass
{
    GObjectClass parent;
};

struct _SchGUIDrawingCfgColor
{
    double red;
    double green;
    double blue;
};

GType
schgui_drawing_cfg_get_type(void);

void
schgui_drawing_cfg_get_bus_line_width(SchGUIDrawingCfg *cfg, double *width);

void
schgui_drawing_cfg_get_net_line_width(SchGUIDrawingCfg *cfg, double *width);

void
schgui_drawing_cfg_get_pin_line_width(SchGUIDrawingCfg *cfg, double *width);

void
schgui_drawing_cfg_get_output_line_width(SchGUIDrawingCfg *cfg, int shape_width, double *output_width);

/*! \brief Disable a color index used for drawing schematic shapes
 *
 *  The color index must be a positive integer.
 *
 *  \param [in]  config This configuration
 *  \param [in]  index  The color index of the shape
 */
void
schgui_drawing_cfg_disable_color(SchGUIDrawingCfg *config, int index);

/*! \brief Get the configured background color 
 *
 *  \param [in]  object This configuration
 *  \param [out] color  The color of the background 
 */
void
schgui_drawing_cfg_get_background_as_gdk_color(GObject *object, GdkColor *color);

/*! \brief Get a color used for drawing schematic shapes
 *
 *  \param [in]  config This configuration
 *  \param [in]  index  The color index of the shape
 *  \param [out] color  The color of the shape, when the return value is TRUE
 *  \return TRUE  Shapes of this color index are enabled
 *  \return FALSE Shapes of this color index are disabled
 */
int
schgui_drawing_cfg_get_color(SchGUIDrawingCfg *config, int index, SchGUIDrawingCfgColor *color);

/*! \brief Get a color used for drawing schematic shapes
 *
 *  \param [in]  config This configuration
 *  \param [in]  index  The color index of the shape
 *  \param [out] color  The color of the shape, when the return value is TRUE
 *  \return TRUE  Shapes of this color index are enabled
 *  \return FALSE Shapes of this color index are disabled
 */
int
schgui_drawing_cfg_get_color_as_gdk_color(SchGUIDrawingCfg *config, int index, GdkColor *color);

/*! \brief Get the default configuration for display
 *
 *  Do not free the returned pointer.
 *
 *  \return The default configuration for on-screen graphics.
 */
SchGUIDrawingCfg*
schgui_drawing_cfg_get_default_display(void);

/*! \brief Get the default configuration for print
 *
 *  Do not free the returned pointer.
 *
 *  \return The default configuration for printed graphics.
 */
SchGUIDrawingCfg*
schgui_drawing_cfg_get_default_print(void);

/*! \brief Set a color used for drawing schematic shapes
 *
 *  The color index must be a positive integer.
 *
 *  \param [in]  config This configuration
 *  \param [in]  index  The color index of the shape
 *  \param [out] color  The color for the shape
 */
void
schgui_drawing_cfg_set_color_by_gdk_color(SchGUIDrawingCfg *config, int index, const GdkColor *color);

/*! \brief Set a color used for drawing schematic shapes
 *
 *  The color index must be a positive integer.
 *
 *  \param [in]  config This configuration
 *  \param [in]  index  The color index of the shape
 *  \param [out] color  The name of the color for the shape
 */
void
schgui_drawing_cfg_set_color_by_name(SchGUIDrawingCfg *config, int index, const char *color);

