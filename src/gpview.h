/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2012 Edward C. Hennessy
 * Copyright (C) 2012 gEDA Contributors (see ChangeLog for details)
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

/*! \defgroup gpview Parts Manager Views
 */

/*! \file gpview.h
 */

#include <gtk/gtk.h>

#include "gpview-forward.h"

#include "gpview-category-model.h"
#include "gpview-category-widget.h"
#include "gpview-company-ctrl.h"
#include "gpview-company-view.h"
#include "gpview-device-view.h"
#include "gpview-document-view.h"
#include "gpview-footprint-view.h"
#include "gpview-package-view.h"
#include "gpview-part-ctrl.h"
#include "gpview-part-view.h"
#include "gpview-factory.h"
#include "gpview-result-adapter.h"
#include "gpview-symbol-view.h"
#include "gpview-view-interface.h"

