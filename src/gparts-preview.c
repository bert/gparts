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

/*! \file gparts-preview.c
 *
 *  \brief A widget to preview schematic symbols.
 */
#include <gtk/gtk.h>

#include "gparts-preview.h"

typedef struct _GPartsPreviewPrivate GPartsPreviewPrivate;

struct _GPartsPreviewPrivate
{
    gint dummy;
};

#define GPARTS_PREVIEW_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object, GPARTS_TYPE_PREVIEW, GPartsPreviewPrivate)

static void
gparts_preview_instance_init(GTypeInstance* instance, gpointer g_class);

static void
gparts_preview_buildable_init(GtkBuildableIface *iface);

static void
gparts_preview_dispose(GObject* object);

static void
gparts_preview_finalize(GObject* object);

static void
gparts_preview_get_property(GObject* object, guint property_id, GValue* value, GParamSpec* pspec);

static void
gparts_preview_set_buildable_property(GtkBuildable *buildable, GtkBuilder *builder, const gchar *name, const GValue *value);

static void
gparts_preview_set_property(GObject* object, guint property_id, const GValue* value, GParamSpec* pspec);

/*! \brief Initialize class data.
 *
 *  \param [in] g_class
 *  \param [in] g_class_data
 */
static void
gparts_preview_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(
        g_class,
        sizeof(GPartsPreviewPrivate)
        );

    object_class->dispose      = gparts_preview_dispose;
    object_class->finalize     = gparts_preview_finalize;
    object_class->get_property = gparts_preview_get_property;
    object_class->set_property = gparts_preview_set_property;
}

/** \brief Unreference all referenced objects.
 *
 *  This function provides the first stage of object destruction.
 *
 *  \param [in] object The object to dispose.
 */
static void
gparts_preview_dispose(GObject *object)
{
}

/*! \brief Deallocate all resources.
 *
 *  This function performs the second and last stage of object destruction.
 *
 *  \param [in] object The object to finalize.
 */
static void
gparts_preview_finalize(GObject *object)
{
}

/*! \brief
 *
 *
 *
 *
 */
static void
gparts_preview_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsPreviewPrivate *private = GPARTS_PREVIEW_GET_PRIVATE(object);

    /* TODO handle case where private is NULL */

    switch ( property_id )
    {
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

/*! \brief
 *
 *
 *
 *
 */
GType
gparts_preview_get_type( void )
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsPreviewClass),
            NULL,
            NULL,
            gparts_preview_class_init,
            NULL,
            NULL,
            sizeof(GPartsPreview),
            0,
            gparts_preview_instance_init,
            NULL
            };

        static const GInterfaceInfo iinfo = {
            (GInterfaceInitFunc) gparts_preview_buildable_init,
            NULL,
            NULL
            };

        type = g_type_register_static(
            GTK_TYPE_BIN,
            "gparts-preview",
            &tinfo,
            0
            );

        g_type_add_interface_static(
            type,
            GTK_TYPE_BUILDABLE,
            &iinfo
            );
    }

    return type;
}

/*! \brief Initialize instance data.
 *
 *  \param instance
 *  \param g_class
 */
static void
gparts_preview_instance_init(GTypeInstance* instance, gpointer g_class)
{
    GPartsPreviewPrivate *private = GPARTS_PREVIEW_GET_PRIVATE(instance);

//    GdkColor color = { 0, 0, 0, 0 };

//    gtk_widget_modify_bg(
//        instance,
//        GTK_STATE_NORMAL,
//        &color
//        );

//    gtk_widget_modify_fg(
//        instance,
//        GTK_STATE_NORMAL,
//        &color
//        );


//    GtkBin *bin = GTK_BIN(instance);

//    bin = gtk_moz_embed_new();

}

static void
gparts_preview_set_buildable_property(GtkBuildable *buildable, GtkBuilder *builder, const gchar *name, const GValue *value)
{
    {
        GtkBuildableIface *iface = GTK_BUILDABLE_GET_IFACE(buildable);
        GtkBuildableIface *parent = g_type_interface_peek_parent(iface);
        parent->set_buildable_property(buildable, builder, name, value);
    }
}

/*! \brief
 *
 *
 *
 *
 */
static void
gparts_preview_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPartsPreviewPrivate *private = GPARTS_PREVIEW_GET_PRIVATE(object);

    switch ( property_id )
    {
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

/*! \brief
 *
 *
 *
 */
static void
gparts_preview_buildable_init(GtkBuildableIface *iface)
{
    iface->set_buildable_property = gparts_preview_set_buildable_property;
}

