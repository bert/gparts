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

/*! \file sch-drafter-fwd.h
 */

#define SCH_TYPE_DRAFTER (sch_drafter_get_type())
#define SCH_DRAFTER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_DRAFTER,SchDrafter))
#define SCH_IS_DRAFTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_DRAFTER))
#define SCH_DRAFTER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE((obj),SCH_TYPE_DRAFTER,SchDrafterInterface))

typedef struct _SchDrafter SchDrafter;
typedef struct _SchDrafterInterface SchDrafterInterface;

