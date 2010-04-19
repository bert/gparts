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

/*! \file sch-shape-fwd.h
 *
 *  \brief Forward declarations.
 */

#define SCH_TYPE_SHAPE (sch_shape_get_type())
#define SCH_SHAPE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_SHAPE,SchShape))
#define SCH_SHAPE_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_SHAPE,SchShapeClass))
#define SCH_IS_SHAPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_SHAPE))
#define SCH_IS_SHAPE_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_SHAPE))
#define SCH_SHAPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_SHAPE,SchShapeClass))

typedef struct _SchShape SchShape;
typedef struct _SchShapeClass SchShapeClass;

