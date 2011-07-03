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

/*! \file geom-line.h
 *
 *  \ingroup geom
 */

#define GEOM_TYPE_LINE (geom_line_get_type())
#define GEOM_LINE(obj) ((GeomLine*)obj)

typedef struct _GeomLine GeomLine;

/*! \brief A boxed type for a line
 *
 *  \ingroup geom
 */
struct _GeomLine
{
    gint x[2];
    gint y[2];
};

/*! \brief Calculate the bounding rectangle of the given line.
 *
 *  \memberof _GeomLine
 *
 *  \param [in]  line   The line to calculate the bounds of
 *  \param [out] bounds The bounds of the line
 */
void
geom_line_bounds(const GeomLine *line, GeomBounds *bounds);

/*! \brief Makes a copy of a line.
 *
 *  \memberof _GeomLine
 *
 *  \param [in] line The line to copy
 *  \return A dynamically allocated copy of the given line
 */
GeomLine*
geom_line_copy(const GeomLine *line);

/*! \brief Free a dynamically allocated line
 *
 *  \memberof _GeomLine
 *
 *  \param [in] line The line to free
 */
void
geom_line_free(GeomLine *line);

/* \private */
GType
geom_line_get_type(void);

/*! \brief Calculate the bounding rectangle of the given line.
 *
 *  \memberof _GeomLine
 *
 *  Initialize a line where both points reside at the origin.
 *
 *  \param [out] line The initialized line
 */
void
geom_line_init(GeomLine *line);

/*! \brief Calculate the length of the given line.
 *
 *  \memberof _GeomLine
 *
 * \param [in] line The line to calculate the length of.
 * \return The length of the line
 */
gdouble
geom_line_length(const GeomLine *line);

/*! \brief Swap the endpoints of the given line
 *
 *  \memberof _GeomLine
 *
 *  \param [in,out] line The line to swap endpoints
 */
void
geom_line_reverse(GeomLine *line);

/*! \brief Rotate the line about the origin by the given angle
 *
 *  \memberof _GeomLine
 *
 *  \param [in,out] line  The line to rotate about the origin
 *  \param [in]     angle The angle to rotate in degrees
 */
void
geom_line_rotate(GeomLine *line, gint angle);

/*! \brief Rotate the line about the origin by the given angle
 *
 *  \memberof _GeomLine
 *
 *  \param [in,out] line  The line to rotate about the origin
 *  \param [in]     angle The angle to rotate in degrees
 */
void
geom_line_transform(GeomLine *line, const GeomTransform *transform);

/*! \brief Translate the line
 *
 *  \memberof _GeomLine
 *
 *  \param [in,out] line  The line to translate
 *  \param [in]     dx    The displacement on the x axis
 *  \param [in]     dy    The displacement on the y axis
 */
void
geom_line_translate(GeomLine *line, gint dx, gint dy);

