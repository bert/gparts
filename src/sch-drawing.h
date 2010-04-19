/*! \file sch_drawing.h
 */

#define SCH_TYPE_DRAWING (sch_drawing_get_type())
#define SCH_DRAWING(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_DRAWING,SchDrawing))
#define SCH_DRAWING_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_DRAWING,SchDrawingClass))
#define SCH_IS_DRAWING(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_DRAWING))
#define SCH_IS_DRAWING_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_DRAWING))
#define SCH_DRAWING_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_DRAWING,SchDrawingClass))

struct _GeomTransform;

typedef struct _SchDrawing SchDrawing;
typedef struct _SchDrawingClass SchDrawingClass;

struct _SchDrawing
{
    GObject parent;
};

struct _SchDrawingClass
{
    GObjectClass parent;
};

GType
sch_drawing_get_type(void);

void
sch_drawing_add_shape(SchDrawing *drawing, GObject *shape);

gboolean
sch_drawing_bounds(SchDrawing *drawing, SchDrafter *drafter, GeomBounds *bounds);

void
sch_drawing_draw(SchDrawing *drawing, SchDrafter *drafter);

void
sch_drawing_rotate(SchDrawing *drawing, int angle);

void
sch_drawing_transform(SchDrawing *drawing, const struct _GeomTransform *transform);

void
sch_drawing_translate(SchDrawing *drawing, int dx, int dy);

void
sch_drawing_write(const SchDrawing *drawing, SchOutputStream *stream);

