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

#define GPARTS_TYPE_PREVIEW (gparts_preview_get_type())
#define GPARTS_PREVIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GPARTS_TYPE_PREVIEW,GPartsPreview))
#define GPARTS_PREVIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),GPARTS_TYPE_PREVIEW,GPartsPreviewClass))
#define GPARTS_IS_PREVIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GPARTS_TYPE_PREVIEW))
#define GPARTS_IS_PREVIEW_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),GPARTS_TYPE_PREVIEW))
#define GPARTS_PREVIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),GPARTS_TYPE_PREVIEW,GPartsPreviewClass))

typedef struct _GPartsPreview GPartsPreview;
typedef struct _GPartsPreviewClass GPartsPreviewClass;

struct _GPartsPreview
{
    GtkTreeView parent;
};

struct _GPartsPreviewClass
{
    GtkTreeViewClass parent;
};

GType
gparts_preview_get_type(void);

GPartsPreview*
gparts_preview_new(void);

