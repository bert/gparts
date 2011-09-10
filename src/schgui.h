/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2011 Edward C. Hennessy
 * Copyright (C) 2011 gEDA Contributors (see ChangeLog for details)
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

/*! \defgroup gpform Parts Manager Forms
 */

/*! \file gpform.h
 */

#include <gtk/gtk.h>

#include "sch.h"
#include "miscgui.h"

#include "schgui-forward.h"

#include "schgui-config.h"

#include "schgui-drawing-cfg.h"
#include "schgui-cairo-drafter.h"
#include "schgui-drawing-view.h"

#include "schgui-cairo-draw-item.h"
#include "schgui-cairo-draw-list.h"

#include "schgui-cairo-arc.h"
#include "schgui-cairo-box.h"
#include "schgui-cairo-bus.h"
#include "schgui-cairo-circle.h"
#include "schgui-cairo-line.h"
#include "schgui-cairo-net.h"
#include "schgui-cairo-path.h"
#include "schgui-cairo-pin.h"
#include "schgui-cairo-text.h"

#include "schgui-cairo-factory.h"

