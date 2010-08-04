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

/*! \file gparts-customize-model.h
 */

#define GPARTS_TYPE_CUSTOMIZE_MODEL (gparts_customize_model_get_type())
#define GPARTS_CUSTOMIZE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_CUSTOMIZE_MODEL,GPartsCustomizeModel))
#define GPARTS_CUSTOMIZE_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_CUSTOMIZE_MODEL,GPartsCustomizeModelClass))
#define GPARTS_IS_CUSTOMIZE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_CUSTOMIZE_MODEL))
#define GPARTS_IS_CUSTOMIZE_MODEL_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_CUSTOMIZE_MODEL))
#define GPARTS_CUSTOMIZE_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_CUSTOMIZE_MODEL,GPartsCustomizeModelClass))

typedef struct _GPartsCustomizeModel GPartsCustomizeModel;
typedef struct _GPartsCustomizeModelClass GPartsCustomizeModelClass;

struct _GPartsCustomizeModel
{
    GObject parent;
};

struct _GPartsCustomizeModelClass
{
    GObjectClass parent;
};

GType
gparts_customize_model_get_type(void);

GPartsCustomizeModel*
gparts_customize_model_new(void);

void
gparts_customize_model_set_visible(GPartsCustomizeModel *model, GtkTreeIter *iter, gboolean visible);
