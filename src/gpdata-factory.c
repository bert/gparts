/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2011 Edward C. Hennessy
 * Copyright (C) 2011 gEDA Contributors (see ChangeLog for details)
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

/*! \file gpdata-factory.c
 */

#include <glib.h>
#include <glib-object.h>
#include <libxml/xmlreader.h>

#include "misc-object.h"

#include "gpdata.h"

#define GPDATA_FACTORY_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj),GPDATA_TYPE_FACTORY,GPDataFactoryPrivate))

enum
{
    GPDATA_FACTORY_XML_PATH = 1
};

typedef struct _GPDataFactoryPrivate GPDataFactoryPrivate;

struct _GPDataFactoryPrivate
{
    gchar *xml_path;
};



static void
gpdata_factory_class_init(gpointer g_class, gpointer g_class_data);

static void
gpdata_factory_dispose(GObject *object);

static void
gpdata_factory_finalize(GObject *object);

static void
gpdata_factory_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static void
gpdata_factory_init(GTypeInstance *instance, gpointer g_class);

static void
gpdata_factory_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);



static void
gpdata_factory_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass *klasse = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(klasse, sizeof(GPDataFactoryPrivate));

    klasse->dispose  = gpdata_factory_dispose;
    klasse->finalize = gpdata_factory_finalize;

    klasse->get_property = gpdata_factory_get_property;
    klasse->set_property = gpdata_factory_set_property;

    g_object_class_install_property(
        klasse,
        GPDATA_FACTORY_XML_PATH,
        g_param_spec_string(
            "xml-path",
            "XML path",
            "XML path",
            NULL,
            G_PARAM_LAX_VALIDATION | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
            )
        );
}

void*
gpdata_factory_create_model(const GPDataFactory *factory, const gchar *filename)
{
    if (filename != NULL)
    {
        GPDataFactoryPrivate *privat = GPDATA_FACTORY_GET_PRIVATE(factory);

        if (privat != NULL)
        {
            gchar *pathname = NULL;
            xmlTextReaderPtr reader = NULL;

            g_debug("Starting");
            g_debug("xml-path %s", privat->xml_path);
            g_debug("filename %s", filename);

            pathname = g_build_path(
                G_DIR_SEPARATOR_S,
                privat->xml_path,
                filename,
                NULL
                );

            g_debug("pathnam %s", pathname);

            if (pathname != NULL)
            {
                reader = xmlReaderForFile(pathname, NULL, 0);

                g_free(pathname);
            }

            g_debug("reader %p", reader);

            if (reader != NULL)
            {
                gint result = xmlTextReaderRead(reader);

                while (result == 1)
                {
                    g_debug("Node %s (%d)", xmlTextReaderConstName(reader), xmlTextReaderNodeType(reader));
                    g_debug("     %s", xmlTextReaderConstValue(reader));

                    result = xmlTextReaderRead(reader);
                }

                xmlFreeTextReader(reader);
            }
        }
    }
    return NULL;
}

static void
gpdata_factory_dispose(GObject *object)
{
    misc_object_chain_dispose(object);
}

static void
gpdata_factory_finalize(GObject *object)
{
    GPDataFactoryPrivate *privat = GPDATA_FACTORY_GET_PRIVATE(object);

    if (privat != NULL)
    {
        g_free(privat->xml_path);
        privat->xml_path = NULL;
    }

    misc_object_chain_finalize(object);
}

static void
gpdata_factory_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPDataFactory *factory = GPDATA_FACTORY(object);

    if (factory != NULL)
    {
        switch (property_id)
        {
            case GPDATA_FACTORY_XML_PATH:
                g_value_take_string(value, gpdata_factory_get_xml_path(factory));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

GType
gpdata_factory_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(GPDataFactoryClass),    /* class_size */
            NULL,                          /* base_init */
            NULL,                          /* base_finalize */
            gpdata_factory_class_init,     /* class_init */
            NULL,                          /* class_finalize */
            NULL,                          /* class_data */
            sizeof(GPDataFactory),         /* instance_size */
            0,                             /* n_preallocs */
            gpdata_factory_init,           /* instance_init */
            NULL                           /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPDataFactory",
            &tinfo,
            0
            );
    }

    return type;
}

gchar*
gpdata_factory_get_xml_path(const GPDataFactory *factory)
{
    GPDataFactoryPrivate *privat = GPDATA_FACTORY_GET_PRIVATE(factory);
    char *xml_path = NULL;

    if (privat != NULL)
    {
        xml_path = g_strdup(privat->xml_path);
    }

    return xml_path;
}


static void
gpdata_factory_init(GTypeInstance *instance, gpointer g_class)
{
    GPDataFactoryPrivate *privat = GPDATA_FACTORY_GET_PRIVATE(instance);

    if (privat != NULL)
    {
        /* \todo Use install location for deployed version */

        privat->xml_path = g_build_path(
            G_DIR_SEPARATOR_S,
            ".",
            /* DATADIR, */
            /* PACKAGE_NAME, */
            /* "xml", */
            /* "models", */
            NULL
            );
    }
}

GPDataFactory*
gpdata_factory_new(void)
{
    return GPDATA_FACTORY(g_object_new(GPDATA_TYPE_FACTORY, NULL));
}

static void
gpdata_factory_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    GPDataFactory *factory = GPDATA_FACTORY(object);

    if (factory != NULL)
    {
        switch (property_id)
        {
            case GPDATA_FACTORY_XML_PATH:
                gpdata_factory_set_xml_path(factory, g_value_get_string(value));
                break;

            default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        }
    }
}

void
gpdata_factory_set_xml_path(GPDataFactory *factory, const gchar *xml_path)
{
    GPDataFactoryPrivate *privat = GPDATA_FACTORY_GET_PRIVATE(factory);

    if (privat != NULL)
    {
        g_free(privat->xml_path);

        privat->xml_path = g_strdup(xml_path);

        g_object_notify(G_OBJECT(factory), "xml-path");
    }
}

