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

typedef struct _GParts GParts;
typedef struct _GPartsClass GPartsClass;

typedef struct _GPartsCategoryController GPartsCategoryController;
typedef struct _GPartsCategoryControllerClass GPartsCategoryControllerClass;

typedef struct _GPartsController GPartsController;
typedef struct _GPartsControllerClass GPartsControllerClass;

typedef struct _GPartsPreviewCtrl GPartsPreviewCtrl;
typedef struct _GPartsPreviewCtrlClass GPartsPreviewCtrlClass;

typedef struct _GPartsResultController GPartsResultController;
typedef struct _GPartsResultControllerClass GPartsResultControllerClass;

typedef struct _GPartsResultModel GPartsResultModel;
typedef struct _GPartsResultModelClass GPartsResultModelClass;

typedef struct _GPartsResultView GPartsResultView;
typedef struct _GPartsResultViewClass GPartsResultViewClass;

