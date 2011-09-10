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

/*! \file sch-box.h
 */

#define SCH_TYPE_BOX (sch_box_get_type())
#define SCH_BOX(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_BOX,SchBox))
#define SCH_BOX_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_BOX,SchBoxClass))
#define SCH_IS_BOX(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_BOX))
#define SCH_IS_BOX_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_BOX))
#define SCH_BOX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_BOX,SchBoxClass))

/*! \extends SchShape
 */
struct _SchBox
{
    SchShape parent;
};

/*! \private
 */
struct _SchBoxClass
{
    SchShapeClass parent;
};

/*! \private */
GType
sch_box_get_type(void);

/*! \brief Get the geometry of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in]  shape The box
 *  \param [out] box   The geometry of the box
 */
void
sch_box_get_box(const SchBox *shape, GeomBox *box);

/*! \brief Get the x coordinate of the corner of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape The box
 *  \return               The x coordinate for the corner of the box
 */
gint
sch_box_get_corner_x(const SchBox *shape);

/*! \brief Get the y coordinate of the corner of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape The box
 *  \return               The y coordinate for the corner of the box
 */
gint
sch_box_get_corner_y(const SchBox *shape);

/*! \brief Get the width of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in] shape The box
 *  \return The width of the box
 */
gint
sch_box_get_width(const SchBox *shape);

/*! \brief Get the height of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in] shape The box
 *  \return           The height of the box
 */
gint
sch_box_get_height(const SchBox *shape);

/*! \brief Get the color of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in] shape The box
 *  \return           The color of the box
 */
gint
sch_box_get_color(const SchBox *shape);

/*! \brief Get the fill style of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in] shape The box
 *  \return           The fill style of the box
 */
SchFillStyle*
sch_box_get_fill_style(const SchBox *shape);

/*! \brief Get the line width of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in] shape The box
 *  \return           The line width of the box
 */
gint
sch_box_get_line_width(const SchBox *shape);

/*! \brief Get the line style used for the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in] shape The box
 *  \return           The line style of the box
 */
SchLineStyle*
sch_box_get_line_style(const SchBox *shape);

/*! \brief Create an instance of a box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in] config The configuration
 *  \return A pointer to a box
 */
SchBox*
sch_box_new(const SchConfig *config);

/*! \brief Set the x coordinate of the corner of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape    The box
 *  \param [in]     corner_x The new x coordinate for the corner of the box
 */
void
sch_box_set_corner_x(SchBox *shape, gint corner_x);

/*! \brief Set the y coordinate of the corner of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape    The box
 *  \param [in]     corner_y The new y coordinate for the corner of the box
 */
void
sch_box_set_corner_y(SchBox *shape, gint corner_y);

/*! \brief Set the width of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape The box
 *  \param [in]     width The new width for the box
 */
void
sch_box_set_width(SchBox *shape, gint width);

/*! \brief Set the height of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape  The box
 *  \param [in]     height The new height for the box
 */
void
sch_box_set_height(SchBox *shape, gint height);

/*! \brief Set the color of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape The box
 *  \param [in]     color The new color for the box
 */
void
sch_box_set_color(SchBox *shape, gint color);

/*! \brief The the line width for the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape      The box
 *  \param [in]     line_width The new line width for the box
 */
void
sch_box_set_line_width(SchBox *shape, gint line_width);

/*! \brief The the line style of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape The box
 *  \param [in]     style The new line style for the box
 */
void
sch_box_set_line_style(SchBox *shape, const SchLineStyle *style);

/*! \brief Set the fill style of the box
 *
 *  \public
 *  \memberof _SchBox
 *
 *  \param [in,out] shape The box
 *  \param [in]     style The new fill style for the box
 */
void
sch_box_set_fill_style(SchBox *shape, const SchFillStyle *style);

