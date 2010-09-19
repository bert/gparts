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

/*! \file gparts-controller.h
 *
 *  \brief An interface for GParts' controllers.
 */

#define GPARTS_TYPE_CONTROLLER (gparts_controller_get_type())
#define GPARTS_CONTROLLER(object) (G_TYPE_CHECK_INSTANCE_CAST((object),GPARTS_TYPE_CONTROLLER,GPartsController))
#define GPARTS_IS_CONTROLLER(object) (G_TYPE_CHECK_INSTANCE_TYPE((object),GPARTS_TYPE_CONTROLLER))
#define GPARTS_CONTROLLER_GET_INTERFACE(instance) (G_TYPE_INSTANCE_GET_INTERFACE((instance),GPARTS_TYPE_CONTROLLER,GPartsControllerInterface))

typedef struct _GPartsController GPartsController;
typedef struct _GPartsControllerInterface GPartsControllerInterface;

struct _GPartsControllerInterface
{
    GTypeInterface parent;

    gchar* (*get_field)(GPartsController *controller, const gchar *name);
    GHashTable* (*get_table)(GPartsController *controller);
};

/*! \brief Gets the value of a field.
 *
 *  \param [in] controller The controller containing the data.
 *  \param [in] name The name of the field to get.
 *  \return A NULL terminated string containing the value of the field.  The
 *  caller must free the memory when no longer needed.  This function returns
 *  NULL if it cannot produce a value.
 */
gchar*
gparts_controller_get_field(GPartsController *controller, const gchar *name);

GHashTable*
gparts_controller_get_table(GPartsController *controller);

GType
gparts_controller_get_type(void);

