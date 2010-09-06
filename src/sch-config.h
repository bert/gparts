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

/*! \file sch-config.h
 */

#define SCH_CONFIG_DEFAULT_BUS_COLOR        10
#define SCH_CONFIG_DEFAULT_GRAPHIC_COLOR     3
#define SCH_CONFIG_DEFAULT_NET_COLOR         4
#define SCH_CONFIG_DEFAULT_PIN_COLOR         1
#define SCH_CONFIG_DEFAULT_TEXT_COLOR        9

#define SCH_CONFIG_DEFAULT_LINE_WIDTH        0

#define SCH_TYPE_CONFIG (sch_config_get_type())
#define SCH_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_CONFIG,SchConfig))
#define SCH_CONFIG_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_CONFIG,SchConfigClass))
#define SCH_IS_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_CONFIG))
#define SCH_IS_CONFIG_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_CONFIG))
#define SCH_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_CONFIG,SchConfigClass))

struct _SchConfig
{
    GObject parent;
};

struct _SchConfigClass
{
    GObjectClass parent;
};

GType
sch_config_get_type(void);

/*! \brief Get the default bus color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for bus objects
 */
gint
sch_config_get_bus_color(const SchConfig *config);

/*! \brief Get the default graphic color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for graphic objects
 */
gint
sch_config_get_graphic_color(const SchConfig *config);

/*! \brief Get the default net color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for net objects
 */
gint
sch_config_get_line_width(const SchConfig *config);

/*! \brief Get the default net color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for net objects
 */
gint
sch_config_get_net_color(const SchConfig *config);

/*! \brief Get the default pin color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for pin objects
 */
gint
sch_config_get_pin_color(const SchConfig *config);

/*! \brief Get the default text color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for text objects
 */
gint
sch_config_get_text_color(const SchConfig *config);

/*! \brief Create a new schematic library configuration
 *
 *  The config object is a singleton. This function will return the same
 *  instance each call.
 *
 *  \return A pointer to the configuration.
 */
SchConfig*
sch_config_new(void);

