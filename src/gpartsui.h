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

/*! \file gparts-main.h
 *
 *  \brief Application controller for gEDA Part Manager.
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "misc-object.h"

#include "miscui.h"

#include "sch.h"

#include "schgui-drawing-cfg.h"
#include "schgui-cairo-drafter.h"
#include "schgui-drawing-view.h"

#include "gparts.h"

/* Boxed types */


/* Forward declarations for gparts package */

#include "gpartsui-forward.h"

#include "gparts-controller.h"

#include "gparts-category-controller.h"
#include "gparts-category-model.h"
#include "gparts-connect-controller.h"
#include "gparts-customize-ctrl.h"


#include "gpartsui-view-controller.h"


#include "gparts-main.h"

#include "gparts-object-list.h"

#include "gparts-preview.h"
#include "gparts-preview-ctrl.h"

#include "gparts-result-controller.h"
#include "gparts-result-model.h"
#include "gparts-result-view.h"

#include "gpartsui-company-controller.h"
#include "gpartsui-company-model.h"

#include "gpartsui-connect-controller.h"
#include "gpartsui-connect-model.h"

#include "gpartsui-database-controller.h"
#include "gpartsui-database-model.h"

#include "gpartsui-document-controller.h"
#include "gpartsui-document-model.h"

#include "gpartsui-result-adapter.h"
#include "gpartsui-result-controller.h"
#include "gpartsui-result-model.h"

