/*! \file schgui_cairo_drafter.h
 *
 *  \brief A wrapper for gschem's line.
 */

#define SCHGUI_TYPE_CAIRO_DRAFTER (schgui_cairo_drafter_get_type())
#define SCHGUI_CAIRO_DRAFTER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCHGUI_TYPE_CAIRO_DRAFTER,SchGUICairoDrafter))
#define SCHGUI_CAIRO_DRAFTER_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCHGUI_TYPE_CAIRO_DRAFTER,SchGUICairoDrafterClass))
#define SCHGUI_IS_CAIRO_DRAFTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCHGUI_TYPE_CAIRO_DRAFTER))
#define SCHGUI_IS_CAIRO_DRAFTER_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCHGUI_TYPE_CAIRO_DRAFTER))
#define SCHGUI_CAIRO_DRAFTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCHGUI_TYPE_CAIRO_DRAFTER,SchGUICairoDrafterClass))

typedef struct _SchGUICairoDrafter SchGUICairoDrafter;
typedef struct _SchGUICairoDrafterClass SchGUICairoDrafterClass;

struct _SchGUICairoDrafter
{
    GObject parent;
};

struct _SchGUICairoDrafterClass
{
    GObjectClass parent;
};

GType
schgui_cairo_drafter_get_type(void);

void
schgui_cairo_drafter_begin_drawing(SchGUICairoDrafter *drafter, GtkWidget *widget);

void
schgui_cairo_drafter_end_drawing(SchGUICairoDrafter *drafter);

void
schgui_cairo_drafter_set_zoom(SchGUICairoDrafter *drafter, double zoom);

int
schgui_cairo_drafter_text_bounds(SchGUICairoDrafter *drafter, SchText *text, GeomBounds *bounds);

void
schgui_cairo_drafter_draw_grid(SchGUICairoDrafter *drafter);

