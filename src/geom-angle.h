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

/*! \file geom-angle.h
 */

/*! \brief Convert an angle from radians to degrees
 *
 * \param [in] angle The angle in radians
 * \return The angle in degrees
 */
int
geom_angle_degrees(double angle);

/*! \brief Normalize an angle to the range of [0,360)
 *
 * \param [in] angle The angle in degrees
 * \return The normalized angle in the range of [0,360) degrees
 */
int
geom_angle_normalize(int angle);

/*! \brief Convert an angle from degrees to radians
 *
 * \param [in] angle The angle in degrees
 * \return The angle in radians 
 */
double
geom_angle_radians(int angle);

