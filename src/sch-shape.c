

#include <glib-object.h>

#include "geom.h"

#include "sch-multiline.h"
#include "sch-shape.h"
#include "sch-text.h"
#include "sch-drafter.h"

gboolean
sch_shape_bounds(SchShape *shape, SchDrafter *drafter, GeomBounds *bounds)
{
    SchShapeInterface *iface;

    //g_debug("Type: %s", g_type_name(shape));

    iface = SCH_SHAPE_GET_INTERFACE(shape);

    if (iface == NULL)
    {
        g_critical("Unable to get SchShapeInterface from parameter");
    }
    else if (iface->bounds == NULL)
    {
        g_critical("SchShapeInterface contains NULL calculate_bounds() function pointer");
    }
    else
    {
        iface->bounds(shape, drafter, bounds);
    }
}

void
sch_shape_draw(SchShape *shape, SchDrafter *drafter)
{
    SchShapeInterface *iface = SCH_SHAPE_GET_INTERFACE(shape);

    if (iface == NULL)
    {
        g_critical("Unable to get SchShapeInterface from parameter");
    }
    else if (iface->draw == NULL)
    {
        g_critical("SchShapeInterface contains NULL draw() function pointer");
    }
    else
    {
        iface->draw(shape, drafter);
    }
}

GType
sch_shape_get_type(void)
{
    static GType type = G_TYPE_INVALID;

    if (type == G_TYPE_INVALID)
    {
        static const GTypeInfo tinfo = {
            sizeof(SchShapeInterface),    /* class_size */
            NULL,                         /* base_init */
            NULL,                         /* base_finalize */
            NULL,                         /* class_init */
            NULL,                         /* class_finalize */
            NULL,                         /* class_data */
            0,                            /* instance_size */
            0,                            /* n_preallocs */
            NULL,                         /* instance_init */
            NULL                          /* value_table */
            };

        type = g_type_register_static(
            G_TYPE_INTERFACE,
            "SchShape",
            &tinfo,
            0
            );
    }

    return type;
}

void
sch_shape_rotate(SchShape *shape, int angle)
{
    SchShapeInterface *iface = SCH_SHAPE_GET_INTERFACE(shape);

    if (iface == NULL)
    {
        g_critical("Unable to get SchShapeInterface from parameter");
    }
    else if (iface->rotate == NULL)
    {
        g_critical("SchShapeInterface contains NULL rotate() function pointer");
    }
    else
    {
        iface->rotate(shape, angle);
    }
}

void
sch_shape_transform(SchShape *shape, const struct _GeomTransform *transform)
{
    SchShapeInterface *iface = SCH_SHAPE_GET_INTERFACE(shape);

    if (iface == NULL)
    {
        g_critical("Unable to get SchShapeInterface from parameter");
    }
    else if (iface->transform == NULL)
    {
        g_critical("SchShapeInterface contains NULL transform() function pointer");
    }
    else
    {
        iface->transform(shape, transform);
    }
}

void
sch_shape_translate(SchShape *shape, int dx, int dy)
{
    SchShapeInterface *iface = SCH_SHAPE_GET_INTERFACE(shape);

    if (iface == NULL)
    {
        g_critical("Unable to get SchShapeInterface from parameter");
    }
    else if (iface->translate == NULL)
    {
        g_critical("SchShapeInterface contains NULL translate() function pointer");
    }
    else
    {
        iface->translate(shape, dx, dy);
    }
}

