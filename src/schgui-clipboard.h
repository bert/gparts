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

/*! \file schgui-clipboard.h
 */

#define SCHGUI_TYPE_CLIPBOARD (schgui_clipboard_get_type())
#define SCHGUI_CLIPBOARD(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_CLIPBOARD,SchGUIClipboard))
#define SCHGUI_CLIPBOARD_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_CLIPBOARD,SchGUIClipboardClass))
#define SCHGUI_IS_CLIPBOARD(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_CLIPBOARD))
#define SCHGUI_IS_CLIPBOARD_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_CLIPBOARD))
#define SCHGUI_CLIPBOARD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_CLIPBOARD,SchGUIClipboardClass))

typedef struct _SchGUIClipboard SchGUIClipboard;
typedef struct _SchGUIClipboardClass SchGUIClipboardClass;

struct _SchGUIClipboard
{
    GObject parent;
};

struct _SchGUIClipboardClass
{
    GObjectClass parent;
};

GType
schgui_clipboard_get_type(void);

SchGUIClipboard*
schgui_clipboard_new(void);

void
schgui_clipboard_copy_drawing(SchGUIClipboard *clipboard, SchDrawing *drawing);

