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

/*! \file gpdata-forward.h
 *
 *  \brief Forward declarations
 *
 *  This file contains all typedefs for structures related to GObjects in the
 *  parts manager data model package.
 */

typedef struct _GPDataFactory GPDataFactory;
typedef struct _GPDataFactoryClass GPDataFactoryClass;

typedef struct _GPDataOPBase GPDataOPBase;
typedef struct _GPDataOPBaseClass GPDataOPBaseClass;

typedef struct _GPDataOPBuildable GPDataOPBuildable;
typedef struct _GPDataOPBuildableInterface GPDataOPBuildableInterface;

typedef struct _GPDataTMColumn GPDataTMColumn;
typedef struct _GPDataTMColumnClass GPDataTMColumnClass;

typedef struct _GPDataTMColumnDouble GPDataTMColumnDouble;
typedef struct _GPDataTMColumnDoubleClass GPDataTMColumnDoubleClass;

typedef struct _GPDataTMColumnInteger GPDataTMColumnInteger;
typedef struct _GPDataTMColumnIntegerClass GPDataTMColumnIntegerClass;

typedef struct _GPDataTMColumnText GPDataTMColumnText;
typedef struct _GPDataTMColumnTextClass GPDataTMColumnTextClass;

typedef struct _GPDataTMColumnUnits GPDataTMColumnUnits;
typedef struct _GPDataTMColumnUnitsClass GPDataTMColumnUnitsClass;

typedef struct _GPDataTMTable GPDataTMTable;
typedef struct _GPDataTMTableClass GPDataTMTableClass;

