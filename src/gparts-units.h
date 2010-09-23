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

/*! \file gparts-units.h
 *
 *  \brief Data type for storing a value with a unit of measure.
 *
 *  The creation functions have the same signature to allow them to be used
 *  in tables of function pointers.
 */

#define GPARTS_TYPE_UNITS (gparts_units_get_type())
#define GPARTS_UNITS(obj) ((GPartsUnits*)obj)

typedef struct _GPartsUnits GPartsUnits;

GType
gparts_units_get_type(void);

/*! \brief Make a copy of the GPartsUnits
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] style The GPartsUnits to be copied
 *  \return A pointer to the copied GPartsUnits
 */
GPartsUnits*
gparts_units_copy(const GPartsUnits *units);

/*! \brief Free the memory associated with GPartsUnits
 *
 *  When passing in a NULL pointer, this function does nothing.
 *
 *  \param [in] style The GPartsUnits to be freed
 */
void
gparts_units_free(GPartsUnits *units);

/*! \brief Create a new value with a measurement in amps.
 *
 *  \param [in] amps The current in amps.
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_amps(gdouble amps);

/*! \brief Create a new value with a measurement in farads.
 *
 *  \param [in] amps The capacitance in farads.
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_farads(gdouble farads);

/*! \brief Create a new value with a measurement in henrys.
 *
 *  \param [in] amps The inductance in henrys.
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_henrys(gdouble henrys);

/*! \brief Create a new value, unitless, but with SI unit prefixes.
 *
 *  \param [in] value The value
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_none(gdouble value);

/*! \brief Create a new value with a measurment in ohms.
 *
 *  \param [in] ohms The resistance in ohms
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_ohms(gdouble ohms);

/*! \brief Create a percentage
 *
 *  \param [in] percent The percentge
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_percent(gdouble percent);

/*! \brief Create a new value with a measurement in volts.
 *
 *  \param [in] volts The voltage in volts
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_volts(gdouble volts);

