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

/*! \file sch-arc.h
 */

#define SCH_TYPE_ARC (sch_arc_get_type())
#define SCH_ARC(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_ARC,SchArc))
#define SCH_ARC_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_ARC,SchArcClass))
#define SCH_IS_ARC(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_ARC))
#define SCH_IS_ARC_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_ARC))
#define SCH_ARC_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_ARC,SchArcClass))

/*! \extends SchShape
 */
struct _SchArc
{
    SchShape parent;
};

/*! \private
 */
struct _SchArcClass
{
    SchShapeClass parent;
};

/*! \private
 */
GType
sch_arc_get_type(void);

/*! \brief Get the geometry of the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \todo Change the parameter to a return value
 *
 *  \param [in] shape The arc
 */
void
sch_arc_get_arc(const SchArc *shape, GeomArc *arc);

/*! \brief Get the x coordinate of the center of the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in] shape The arc
 */
gint
sch_arc_get_center_x(const SchArc *shape);

/*! \brief Get the y coordinate of the center of the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in] shape The arc
 */
gint
sch_arc_get_center_y(const SchArc *shape);

/*! \brief Get the color of the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in] shape The arc
 */
gint
sch_arc_get_color(const SchArc *shape);

/*! \brief Get the line width for the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in] shape The arc
 */
gint
sch_arc_get_line_width(const SchArc *shape);

/*! \brief Get the radius for the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in] shape The arc
 */
gint
sch_arc_get_radius(const SchArc *shape);

/*! \brief Get the start angle for the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in] shape The arc
 */
gint
sch_arc_get_start(const SchArc *shape);

/*! \brief Get the sweep angle for the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in] shape The arc
 */
gint
sch_arc_get_sweep(const SchArc *shape);

/*!
 *
 *
 *
 *
 */
SchArc*
sch_arc_new(const SchConfig *config);

/*! \brief Set the arc's geometry
 *
 *  \public
 *  \memberof _SchArc
 *
 *  This function emits the following signals:
 *  notify::arc
 *  notify::center-x
 *  notify::center-y
 *  notify::radius
 *  notify::start
 *  notify::sweep
 *
 *  \param [in,out] shape The arc
 *  \param [in]     arc   The new geometry for the arc
 */
void
sch_arc_set_arc(SchArc *shape, const GeomArc *arc);

/*! \brief Set the color of the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in,out] shape The arc
 *  \param [in]     color The color
 */
void
sch_arc_set_color(SchArc *shape, gint color);

/*! \brief Set the y coordinate of the arc's center
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in,out] shape The arc
 *  \param [in]     style The y coordinate of the arc's center
 */
void
sch_arc_set_line_style(SchArc *shape, const SchLineStyle *style);

/*! \brief Set the y coordinate of the arc's center
 *
 *  \public
 *  \memberof _SchArc
 *
 *  \param [in,out] shape The arc
 *  \param [in]     style The y coordinate of the arc's center
 */
void
sch_arc_set_line_width(SchArc *shape, gint line_width);

/*! \brief Set the radius of the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  This function emits the signal notify::arc and notify::radius.
 *
 *  \param [in,out] shape  The arc
 *  \param [in]     radius The radius
 */
void
sch_arc_set_radius(SchArc *shape, gint radius);

/*! \brief Set the starting angle of the arc's sweep
 *
 *  \public
 *  \memberof _SchArc
 *
 *  This function emits the signal notify::arc and notify::start.
 *
 *  \param [in,out] shape The arc
 *  \param [in]     start The starting angle in degrees
 */
void
sch_arc_set_start(SchArc *shape, gint start);

/*! \brief Set the sweep angle of the arc
 *
 *  \public
 *  \memberof _SchArc
 *
 *  This function emits the signal notify::arc and notify::sweep.
 *
 *  \param [in,out] shape The arc
 *  \param [in]     angle The sweep angle in degrees
 */
void
sch_arc_set_sweep(SchArc *shape, gint sweep);

/*! \brief Set the x coordinate of the arc's center
 *
 *  \public
 *  \memberof _SchArc
 *
 *  This function emits the signal notify::arc and notify::center-x.
 *
 *  \param [in,out] shape    The arc
 *  \param [in]     center_x The x coordinate of the arc's center
 */
void
sch_arc_set_center_x(SchArc *shape, gint center_x);

/*! \brief Set the y coordinate of the arc's center
 *
 *  \public
 *  \memberof _SchArc
 *
 *  This function emits the signal notify::arc and notify::center-y.
 *
 *  \param [in,out] shape    The arc
 *  \param [in]     center_y The y coordinate of the arc's center
 */
void
sch_arc_set_center_y(SchArc *shape, gint center_y);

