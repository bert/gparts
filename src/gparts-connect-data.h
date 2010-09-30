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

/*! \file gparts-connect-data.h
 */

#define GPARTS_TYPE_CONNECT_DATA (gparts_connect_data_get_type())
#define GPARTS_CONNECT_DATA(obj) ((GPartsConnectData*)obj)

typedef struct _GPartsConnectData GPartsConnectData;

struct _GPartsConnectData
{
    gchar *hostname;
    gchar *username;
    gchar *password;
    gchar *database;
    gchar *filename;
};

/*! \private */
GType
gparts_connect_data_get_type(void);

GPartsConnectData*
gparts_connect_data_copy(GPartsConnectData *data);

void
gparts_connect_data_free(GPartsConnectData *data);

GPartsConnectData*
gparts_connect_data_new(void);
