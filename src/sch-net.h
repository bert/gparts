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

/*! \file sch-net.h
 */

#define SCH_TYPE_NET (sch_net_get_type())
#define SCH_NET(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_NET,SchNet))
#define SCH_NET_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_NET,SchNetClass))
#define SCH_IS_NET(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_NET))
#define SCH_IS_NET_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_NET))
#define SCH_NET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_NET,SchNetClass))

typedef struct _SchNet SchNet;
typedef struct _SchNetClass SchNetClass;

struct _SchNet
{
    GObject parent;
};

struct _SchNetClass
{
    GObjectClass parent;
};

GType
sch_net_get_type(void);

void
sch_net_get_color(const SchNet *shape, int *index);

void
sch_net_get_line(const SchNet *shape, GeomLine *line);

