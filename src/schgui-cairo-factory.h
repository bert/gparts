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

/*! \file schigui-cairo-factory.h
 */

#define SCHGUI_TYPE_CAIRO_FACTORY (schgui_cairo_factory_get_type())
#define SCHGUI_CAIRO_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_CAIRO_FACTORY,SchGUICairoFactory))
#define SCHGUI_CAIRO_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_CAIRO_FACTORY,SchGUICairoFactoryClass))
#define SCHGUI_IS_CAIRO_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_CAIRO_FACTORY))
#define SCHGUI_IS_CAIRO_FACTORY_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_CAIRO_FACTORY))
#define SCHGUI_CAIRO_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_CAIRO_FACTORY,SchGUICairoFactoryClass))

struct _SchGUICairoFactory
{
    GObject parent;
};

struct _SchGUICairoFactoryClass
{
    GObjectClass parent;

    GHashTable *table;
};

GType
schgui_cairo_factory_get_type(void);

/*! \brief Create a new Cairo item given a schematic drawing.
 *
 *  \param [in] factory The Cairo draw item factory
 *  \param [in] drawing The schematic to build a drawing list from
 *  \param [in] config  The drawing configuration
 *  \return The draw item to draw the schematic on a Cairo context.
 */
SchGUICairoDrawItem*
schgui_cairo_factory_create_from_drawing(SchGUICairoFactory *factory, SchDrawing *drawing);

/*! \brief Create a new Cairo draw item given a schematic shape.
 *
 *  \param [in] factory The Cairo draw item factory
 *  \param [in] shape   The schematic shape to build a drawing list from
 *  \param [in] config  The drawing configuration
 *  \return The draw item to draw the shape on a Cairo context.
 */
SchGUICairoDrawItem*
schgui_cairo_factory_create_from_shape(SchGUICairoFactory *factory, SchShape *shape);

/*! \brief Create a new Cairo draw item factory
 *
 *  \return An instance of a Cairo draw item factory
 */
SchGUICairoFactory*
schgui_cairo_factory_new(SchGUIDrawingCfg *config);

/*! \brief Create a new Cairo draw item factory
 *
 *  \param [in] factory The Cairo draw item factory
 *  \param [in] config  The configuration to use for creating drawing items 
 */
void
schgui_cairo_factory_set_config(SchGUICairoFactory *factory, SchGUIDrawingCfg *config);

