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

/*! \file schgui-config.h
 */

#define SCHGUI_TYPE_CONFIG (schgui_config_get_type())
#define SCHGUI_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_CONFIG,SchGUIConfig))
#define SCHGUI_CONFIG_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_CONFIG,SchGUIConfigClass))
#define SCHGUI_IS_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_CONFIG))
#define SCHGUI_IS_CONFIG_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_CONFIG))
#define SCHGUI_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_CONFIG,SchGUIConfigClass))

/*! \extends GObject
 */
struct _SchGUIConfig
{
    GObject parent;
};

/*! \private
 */
struct _SchGUIConfigClass
{
    GObjectClass parent;
};

/*! \private */
GType
schgui_config_get_type(void);

/*! \brief Create a new form config
 *
 *  This class implements a singleton. It will return the same
 *
 *  \return A pointer to the new form config
 */
SchGUIConfig*
schgui_config_new(void);

SchGUIDrawingCfg*
schgui_config_get_config_drawing_display(const SchGUIConfig *config);


SchGUIDrawingCfg*
schgui_config_get_config_drawing_print(const SchGUIConfig *config);
