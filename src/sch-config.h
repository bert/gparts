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
 *
 *  \brief Stores configuration values for the schematic package
 *
 *  Configuration values include:
 *  - default values for schematic shapes, such as color and line width
 */

#define SCH_CONFIG_DEFAULT_BUBBLE_COLOR       6
#define SCH_CONFIG_DEFAULT_BUS_COLOR         10
#define SCH_CONFIG_DEFAULT_GRAPHIC_COLOR      3
#define SCH_CONFIG_DEFAULT_NET_COLOR          4
#define SCH_CONFIG_DEFAULT_PIN_COLOR          1
#define SCH_CONFIG_DEFAULT_TEXT_COLOR         9

#define SCH_CONFIG_DEFAULT_LINE_WIDTH         0

#define SCH_CONFIG_DEFAULT_BUBBLE_DIAMETER  100
#define SCH_CONFIG_DEFAULT_PIN_LENGTH       300
#define SCH_CONFIG_DEFAULT_PIN_SPACING      400

#define SCH_CONFIG_DEFAULT_TEXT_SIZE         10

#define SCH_CONFIG_DEFAULT_ATTRIBUTE_PROMOTION  FALSE
#define SCH_CONFIG_DEFAULT_KEEP_INVISIBLE       FALSE
#define SCH_CONFIG_DEFAULT_PROMOTE_INVISIBLE    FALSE

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

/*! \brief
 *
 *  \param [in] config The configuration
 *  \return
 */
gboolean
sch_config_get_attribute_promotion(const SchConfig *config);

/*! \brief Get the default bubble color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for bubbles
 */
gint
sch_config_get_bubble_color(const SchConfig *config);

/*! \brief Get the default bubble diameter
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default bubble diameter in mils
 */
gint
sch_config_get_bubble_diameter(const SchConfig *config);

/*! \brief Get the default bus color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for bus objects
 */
gint
sch_config_get_bus_color(const SchConfig *config);

/*! \brief Get the default graphic fill style
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in]  config The configuration
 *  \param [out] style  The default fill style for graphic objects
 */
void
sch_config_get_fill_style(const SchConfig *config, SchFillStyle *style);

/*! \brief Get the default graphic color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for graphic objects
 */
gint
sch_config_get_graphic_color(const SchConfig *config);

/*! \brief
 *
 *  \param [in] config The configuration
 *  \return
 */
gboolean
sch_config_get_keep_invisible(const SchConfig *config);

/*! \brief Get the default graphic line style
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in]  config The configuration
 *  \param [out] style  The default line style for graphic objects
 */
void
sch_config_get_line_style(const SchConfig *config, SchLineStyle *style);

/*! \brief Get the default line width for graphic objects 
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default line width
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

/*! \brief Get the recommended pin length
 *
 *  The recommended length of the pin excludes any bubble or other notation.
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The recommended length for pins
 */
gint
sch_config_get_pin_length(const SchConfig *config);

/*! \brief Get the recommended pin spacing
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The recommended spacing in between pins
 */
gint
sch_config_get_pin_spacing(const SchConfig *config);

/*! \brief Get the names of attributes to promote 
 *
 *  When the list is no longer needed, the caller must call g_strvfree().
 *
 *  \param [in] config The configuration
 *  \return The list of names of attributes for promotion
 */
gchar**
sch_config_get_promote_attributes(const SchConfig *config);

/*! \brief
 *
 *  \param [in] config The configuration
 *  \return
 */
gboolean
sch_config_get_promote_invisible(const SchConfig *config);

/*! \brief Get the default text color index
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default color index for text objects
 */
gint
sch_config_get_text_color(const SchConfig *config);

/*! \brief Get the default text size
 *
 *  If config is NULL, this function will return a default value.
 *
 *  \param [in] config The configuration
 *  \return The default size for text in points
 */
gint
sch_config_get_text_size(const SchConfig *config);

/*! \brief Create a new schematic library configuration
 *
 *  The config object is a singleton. This function will return the same
 *  instance each call.
 *
 *  \return A pointer to the configuration.
 */
SchConfig*
sch_config_new(void);

/*! \brief
 *
 *  \param [in] config The configuration
 *  \return
 */
void
sch_config_set_attribute_promotion(SchConfig *config, gboolean enabled);

/*! \brief Set the default bubble color index
 *
 *  \param [in] config The configuration
 *  \param [in] index  The default color index for bubbles
 */
void
sch_config_set_bubble_color(SchConfig *config, gint index);

/*! \brief Set the default bubble diameter
 *
 *  \param [in] config The configuration
 *  \param [in] index  The default diameter for bubbles
 */
void
sch_config_set_bubble_diameter(SchConfig *config, gint diameter);

/*! \brief Set the default bus color index
 *
 *  \param [in] config The configuration
 *  \param [in] index  The default color index for busses
 */
void
sch_config_set_bus_color(SchConfig *config, gint index);

/*! \brief Set the default graphic fill style 
 *
 *  \param [in] config The configuration
 *  \param [in] style  The default fill style for graphic shapes
 */
void
sch_config_set_fill_style(SchConfig *config, const SchFillStyle *style);

/*! \brief Set the default graphic color index
 *
 *  \param [in] config The configuration
 *  \param [in] index  The default color index for graphic shapes
 */
void
sch_config_set_graphic_color(SchConfig *config, gint index);

/*! \brief
 *
 *  \param [in] config The configuration
 *  \return
 */
void
sch_config_set_keep_invisible(SchConfig *config, gboolean enabled);

/*! \brief Set the default graphic line style 
 *
 *  \param [in] config The configuration
 *  \param [in] style  The default line style for graphic shapes
 */
void
sch_config_set_line_style(SchConfig *config, const SchLineStyle *style);

/*! \brief Set the line width for graphic shapes
 *
 *  \param [in] config The configuration
 *  \param [in] width  The default line width for graphic shapes
 */
void
sch_config_set_line_width(SchConfig *config, gint width);

/*! \brief Set the default net color index
 *
 *  \param [in] config The configuration
 *  \param [in] index  The default color index for nets
 */
void
sch_config_set_net_color(SchConfig *config, gint index);

/*! \brief Set the default pin color index
 *
 *  \param [in] config The configuration
 *  \param [in] index  The default color index for pins
 */
void
sch_config_set_pin_color(SchConfig *config, gint index);

/*! \brief Set the recommended length for pins
 *
 *  \param [in] config The configuration
 *  \param [in] index  The recommended length for pins
 */
void
sch_config_set_pin_length(SchConfig *config, gint length);

/*! \brief Set the recommended spacing for pins
 *
 *  \param [in] config The configuration
 *  \param [in] index  The recommended spacing for pins
 */
void
sch_config_set_pin_spacing(SchConfig *config, gint spacing);

/*! \brief Set the names of attributes to promote 
 *
 *  \param [in] config The configuration
 *  \param [in] name   The names of attributes to promote
 */
void
sch_config_set_promote_attributes(SchConfig *config, gchar **names);

/*! \brief
 *
 *  \param [in] config The configuration
 *  \return
 */
void
sch_config_set_promote_invisible(SchConfig *config, gboolean enabled);

/*! \brief Set the default text color index
 *
 *  \param [in] config The configuration
 *  \param [in] index  The default color index for text shapes
 */
void
sch_config_set_text_color(SchConfig *config, gint index);

/*! \brief Set the default text size
 *
 *  \param [in] config The configuration
 *  \param [in] size   The default text size in points
 */
void
sch_config_set_text_size(SchConfig *config, gint size);

