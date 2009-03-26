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

/*! \file gparts-object-list.h
 *
 *  \brief Stores a buildable list of GObjects
 */

#define GPARTS_TYPE_OBJECT_LIST (gparts_object_list_get_type())
#define GPARTS_OBJECT_LIST(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_OBJECT_LIST,GPartsObjectList))
#define GPARTS_OBJECT_LIST_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_OBJECT_LIST,GPartsObjectListClass))
#define GPARTS_IS_OBJECT_LIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_OBJECT_LIST))
#define GPARTS_IS_OBJECT_LIST_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_OBJECT_LIST))
#define GPARTS_OBJECT_LIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_OBJECT_LIST,GPartsObjectListClass))

typedef struct _GPartsObjectList GPartsObjectList;
typedef struct _GPartsObjectListClass GPartsObjectListClass;

struct _GPartsObjectList
{
    GObject parent;
};

struct _GPartsObjectListClass
{
    GObjectClass parent;
};

GType
gparts_object_list_get_type(void);

