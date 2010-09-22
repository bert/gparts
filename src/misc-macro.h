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

/*! \file misc-macro.h
 */

/*! \brief Expand macros found in the given string
 *
 *  The hash table keys are strings containing the macro names and the values
 *  are strings containing the macro values.
 *
 *  When no longer needed, call g_free() on the returned string.
 *
 *  \param [in] regex  The regex used to find and replace macros
 *  \param [in] string A string containing macros to be expanded
 *  \param [in] table  A table of macro names and values.
 *  \return A new string containing the expanded macros
 */
gchar*
misc_macro_expand(const GRegex* regex, const gchar *string, const GHashTable *table);

/*! \brief Finds all the macros in the given string
 *
 *  This function finds all the macros in the given string and adds the
 *  names as hash table keys. New names added to the table are inserted
 *  with the value NULL. If the name already exists in the table, the
 *  data is not overwritten.
 *
 *  \param [in]     regex  The regex used to find and replace macros
 *  \param [in]     string A string containing macros to be expanded
 *  \param [in,out] table  A table of macro names and values.
 */
void
misc_macro_find(const GRegex *regex, const gchar *string, GHashTable *table);

/*! \brief Create the regular expression used to expand macros
 *
 *  Creates a regular expression for macros in the form of $(name).
 *
 *  Macros in the attributes have the form of $(name). Whenever expansion
 *  encounters a $(name), it replaces the macro value.
 *
 *  When no longer needed, call g_regex_unref() on the returned GRegex.
 *
 *  \return The regular expression used for finding and replacing  macros.
 */
GRegex*
misc_macro_new_regex(void);

/*! \brief Create a new hash table suitable for use with this module
 *
 *  Both the key and value are strings.
 *
 *  When no longer needed, call g_hash_table_unref() on the returned GHashTable.
 *
 *  \return A pointer to the newly created hash table
 */
GHashTable*
misc_macro_new_table(void);

