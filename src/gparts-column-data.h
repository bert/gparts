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

/*! \file gparts-column-data.h
 */

#define GPARTS_TYPE_COLUMN_DATA (gparts_column_data_get_type())
#define GPARTS_COLUMN_DATA(obj) ((GPartsColumnData*)obj)

typedef struct _GPartsColumnData GPartsColumnData;

struct _GPartsColumnData
{
    gchar *name;
    GType type;
};

/*! \private */
GType
gparts_column_data_get_type(void);

GPartsColumnData*
gparts_column_data_copy(GPartsColumnData *data);

void
gparts_column_data_free(GPartsColumnData *data);

GPartsColumnData*
gparts_column_data_new(void);

