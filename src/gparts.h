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

/*! \file gparts.h
 */

#include <glib.h>
#include <glib-object.h>

#include "misc-object.h"

/* Boxed types */

#include "gparts-units.h"
#include "gparts-connect-data.h"
#include "gparts-column-data.h"

/* Forward declarations for gparts package */

#include "gparts-forward.h"

/* Based off GObject */

#include "gparts-config.h"
#include "gparts-database.h"
#include "gparts-database-factory.h"
#include "gparts-database-result.h"
#include "gparts-database-type.h"

