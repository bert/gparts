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
 *  This data type can be transformed into strings using g_value_transform().
 *
 *  \todo Implement inches.
 *  \todo Implement a monetary units (for budgetary cost, etc...).
 *  \todo Implement seconds.
 *  \todo Should an \a each units be implemented?
 *
 *  The creation functions have the same signature to allow them to be used
 *  in tables of function pointers.
 */

#define GPARTS_TYPE_UNITS (gparts_units_get_type())
#define GPARTS_UNITS(obj) ((GPartsUnits*)obj)

typedef struct _GPartsUnits GPartsUnits;

/*! \private */
GType
gparts_units_get_type(void);

/*! \brief Make a copy of the GPartsUnits
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] units The GPartsUnits to be copied
 *  \return A pointer to the copied GPartsUnits
 */
GPartsUnits*
gparts_units_copy(const GPartsUnits *units);

/*! \brief Free the memory associated with GPartsUnits
 *
 *  When passing in a NULL pointer, this function does nothing.
 *
 *  \param [in] units The GPartsUnits to be freed
 */
void
gparts_units_free(GPartsUnits *units);

/*! \brief Create a new value with a measurement in amphours.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] amphours The value in amphours.
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_amphours(gdouble amphours);

/*! \brief Create a new value with a measurement in amps.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] amps The current in amps.
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_amps(gdouble amps);

/*! \brief Create a new value with a measurement in Celsius.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] celcius The temperature in Celcius.
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_celcius(gdouble celcius);

/*! \brief Create a new value with a measurement in farads.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] amps The capacitance in farads.
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_farads(gdouble farads);

/*! \brief Create a new value with a measurement in grams.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] grams The value in grams.
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_grams(gdouble grams);

/*! \brief Create a new value with a measurement in Henrys.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] henrys The inductance in Henrys.
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_henrys(gdouble henrys);

/*! \brief Create a new value with a measurement in Hertz.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] hertz The frequency in Hertz
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_hertz(gdouble hertz);

/*! \brief Create a new value with a measurement in meters.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] meters The distance in meters
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_meters(gdouble meters);

/*! \brief Create a new value, unitless, but with SI unit prefixes.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] value The value
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_none(gdouble value);

/*! \brief Create a new value with a measurment in ohms.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] ohms The resistance in ohms
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_ohms(gdouble ohms);

/*! \brief Create a percentage
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] percent The percentge
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_percent(gdouble percent);

/*! \brief Create a new value in parts per notation
 *
 *  Similar to percent, however, the units are:
 *
 *  <table>
 *  <tr><td>%</td><td>Parts per hundred</td></tr>
 *  <tr><td>ppm</td><td>Parts per million</td></tr>
 *  <tr><td>ppb</td><td>Parts per billion</td></tr>
 *  <tr><td>ppt</td><td>Parts per trillion</td></tr>
 *  <tr><td>ppq</td><td>Parts per quadrillion</td></tr>
 *  </table>
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] pp The amount in parts per unit
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_pp(gdouble pp);


/*! \brief Create a new value with a measurement in volts.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] volts The voltage in volts
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_volts(gdouble volts);

/*! \brief Create a new value with a measurement in watts.
 *
 *  When no longer needed, the caller must call gparts_units_free()
 *  on the returned pointer.
 *
 *  \param [in] watts The wattage in watts
 *  \return A pointer to a new GPartsUnits boxed type
 */
GPartsUnits*
gparts_units_new_watts(gdouble watts);

