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

/*! \file gpdata-op-buildable.h
 */

#define GPDATA_TYPE_OP_BUILDABLE (gpdata_op_buildable_get_type())
#define GPDATA_OP_BUILDABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPDATA_TYPE_OP_BUILDABLE,GPDataOPBuildable))
#define GPDATA_IS_OP_BUILDABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPDATA_TYPE_OP_BUILDABLE))
#define GPDATA_OP_BUILDABLE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE((obj),GPDATA_TYPE_OP_BUILDABLE,GPDataOPBuildableInterface))

struct _GPDataOPBuildableInterface
{
    GTypeInterface parent;
};

GType
gpdata_op_buildable_get_type(void);

