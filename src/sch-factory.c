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

/*! \file sch-factory.c
 */

#include <glib.h>
#include <glib-object.h>

#include "misc-object.h"

#include "sch-factory.h"

#define SCH_FACTORY_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),SCH_TYPE_FACTORY,SchFactoryPrivate))

enum
{
    SCH_FACTORY_ALWAYS_PROMOTE_ATTRIBUTES = 1,
    SCH_FACTORY_ATTRIBUTE_PROMOTION,
    SCH_FACTORY_KEEP_INVISIBLE,
    SCH_FACTORY_PROMOTE_INVISIBLE
};

typedef struct _SchFactoryPrivate SchFactoryPrivate;

struct _SchFactoryPrivate
{
    gchar    **promote_attributes;
    gboolean attribute_promotion;
    gboolean keep_invisible;
    gboolean promote_invisible;
};


static void
sch_factory_class_init(gpointer g_class, gpointer g_class_data);

static void
sch_factory_dispose(GObject *object);

static void
sch_factory_finalize(GObject *object);

static void
sch_factory_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
sch_factory_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
sch_factory_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(SchFactoryPrivate));

    klasse->dispose  = sch_factory_dispose;
    klasse->finalize = sch_factory_finalize;

    klasse->get_property = sch_factory_get_property;
    klasse->set_property = sch_factory_set_property;

    g_object_class_install_property(
        klasse,
        SCH_FACTORY_ALWAYS_PROMOTE_ATTRIBUTES,
        g_param_spec_boxed(
            "always-promote-attributes",
            "always-promote-attributes",
            "always-promote-attributes",
            G_TYPE_STRV,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_FACTORY_ATTRIBUTE_PROMOTION,
        g_param_spec_boolean(
            "attribute-promotion",
            "attribute-promotion",
            "attribute-promotion",
            TRUE,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_FACTORY_KEEP_INVISIBLE,
        g_param_spec_boolean(
            "keep-invisible",
            "keep-invisible",
            "keep-invisible",
            TRUE,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );

    g_object_class_install_property(
        klasse,
        SCH_FACTORY_PROMOTE_INVISIBLE,
        g_param_spec_boolean(
            "promote-invisible",
            "promote-invisible",
            "promote-invisible",
            FALSE,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

static void
sch_factory_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}

static void
sch_factory_finalize(GObject *object)
{
    SchFactoryPrivate *privat = SCH_FACTORY_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_strfreev(privat->promote_attributes);
    }

    misc_object_chain_finalize(object);
}


SchFactory*
sch_factory_get_default(void)
{
    static SchFactory *factory = NULL;

    if (factory == NULL)
    {
        factory = SCH_FACTORY(g_object_new(SCH_TYPE_FACTORY, NULL));
    }

    return factory;
}

gchar**
sch_factory_get_promote_attributes(GObject *object)
{
    char **names = NULL;
    SchFactoryPrivate *privat = SCH_FACTORY_GET_PRIVATE(object);

    if (privat != NULL)
    {
        names = g_strdupv(privat->promote_attributes);
    }

    return names;
}

static void
sch_factory_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    SchFactoryPrivate *privat = SCH_FACTORY_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCH_FACTORY_ALWAYS_PROMOTE_ATTRIBUTES:
                g_value_take_boxed(value, sch_factory_get_promote_attributes);
                break;

            case SCH_FACTORY_ATTRIBUTE_PROMOTION:
                g_value_set_boolean(value, privat->attribute_promotion);
                break;

            case SCH_FACTORY_KEEP_INVISIBLE:
                g_value_set_boolean(value, privat->keep_invisible);
                break;

            case SCH_FACTORY_PROMOTE_INVISIBLE:
                g_value_set_boolean(value, privat->promote_invisible);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
sch_factory_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchFactoryClass),    /* class_size */
            NULL,                       /* base_init */
            NULL,                       /* base_finalize */
            sch_factory_class_init,     /* class_init */
            NULL,                       /* class_finalize */
            NULL,                       /* class_data */
            sizeof(SchFactory),         /* instance_size */
            0,                          /* n_preallocs */
            NULL,                       /* instance_init */
            NULL                        /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "SchFactory",
            &tinfo,
            0
            );
    }

    return type;
}

void
sch_factory_set_promote_attributes(GObject *object, char **name)
{
    SchFactoryPrivate *privat = SCH_FACTORY_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_strfreev(privat->promote_attributes);

        privat->promote_attributes = g_strdupv(name);
    }
}

static void
sch_factory_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    SchFactoryPrivate *privat = SCH_FACTORY_GET_PRIVATE(object);

    if (privat != NULL)
    {
        switch (property_id)
        {
            case SCH_FACTORY_ALWAYS_PROMOTE_ATTRIBUTES:
                sch_factory_set_promote_attributes(object, g_value_get_boxed(value));
                break;

            case SCH_FACTORY_ATTRIBUTE_PROMOTION:
                privat->attribute_promotion = g_value_get_boolean(value);
                break;

            case SCH_FACTORY_KEEP_INVISIBLE:
                privat->keep_invisible = g_value_get_boolean(value);
                break;

            case SCH_FACTORY_PROMOTE_INVISIBLE:
                privat->promote_invisible = g_value_get_boolean(value);
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

