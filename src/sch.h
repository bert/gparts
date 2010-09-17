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

/*! \file sch.h
 */

#include <stdio.h>

#include <gio/gio.h>

#include "geom.h"

/* Boxed types */

#include "sch-fill-style.h"
#include "sch-line-style.h"
#include "sch-path-command.h"

/* Forward declarations */

#include "sch-forward.h"

#include "sch-config.h"

#include "sch-attributes.h"
#include "sch-multiline.h"

#include "sch-shape.h"

#include "sch-drawing.h"

#include "sch-arc.h"
#include "sch-box.h"
#include "sch-bus.h"
#include "sch-circle.h"
#include "sch-component.h"
#include "sch-line.h"
#include "sch-net.h"
#include "sch-path.h"
#include "sch-picture.h"
#include "sch-pin.h"
#include "sch-text.h"

#include "sch-drafter.h"


#include "sch-factory.h"
#include "sch-loader.h"

#include "sch-file-format-2.h"
#include "sch-output-stream.h"

