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

/*! \file schgui-cairo-draw-item.h
 *
 *  \brief An abstract base class for items in a drawing list for Cairo.
 */

#define SCHGUI_TYPE_CAIRO_DRAW_ITEM (schgui_cairo_draw_item_get_type())
#define SCHGUI_CAIRO_DRAW_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_CAIRO_DRAW_ITEM,SchGUICairoDrawItem))
#define SCHGUI_CAIRO_DRAW_ITEM_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_CAIRO_DRAW_ITEM,SchGUICairoDrawItemClass))
#define SCHGUI_IS_CAIRO_DRAW_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_CAIRO_DRAW_ITEM))
#define SCHGUI_IS_CAIRO_DRAW_ITEM_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_CAIRO_DRAW_ITEM))
#define SCHGUI_CAIRO_DRAW_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_CAIRO_DRAW_ITEM,SchGUICairoDrawItemClass))

typedef struct _SchGUICairoDrawItem SchGUICairoDrawItem;
typedef struct _SchGUICairoDrawItemClass SchGUICairoDrawItemClass;

struct _SchGUICairoDrawItem
{
    GObject parent;
};

struct _SchGUICairoDrawItemClass
{
    GObjectClass parent;

    void (*bounds)(SchGUICairoDrawItem *item, cairo_t *cairo, GeomBounds *bounds);
    void (*draw)(SchGUICairoDrawItem *item, cairo_t *cairo);
};

GType
schgui_cairo_draw_item_get_type(void);

/*! \brief Include the bounds of the drawing item
 *
 *  \todo Investigate use of cairo_path_extents().
 *  \todo The bounds should use doubles instead of ints.
 *
 *  \param [in]     item   The drawing item
 *  \param [in]     cairo  The cairo context
 *  \param [in,out] bounds The bounds
 */
void
schgui_cairo_draw_item_bounds(SchGUICairoDrawItem *item, cairo_t *cairo, GeomBounds *bounds);

/*! \brief Draw the drawing item 
 *
 *  \param [in] item  The drawing item
 *  \param [in] cairo The cairo context to draw upon
 */
void
schgui_cairo_draw_item_draw(SchGUICairoDrawItem *item, cairo_t *cairo);

