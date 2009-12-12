
#define GSYMVIEW_TYPE (gsymview_get_type())
#define GSYMVIEW(object) (G_TYPE_CHECK_INSTANCE_CAST((object), GSYMVIEW_TYPE, GSymView))

typedef struct _GSymView GSymView;
typedef struct _GSymViewClass GSymViewClass;

struct _GSymView
{
    GObject parent;
};

struct _GSymViewClass
{
    GObjectClass parent;
};

GType gsymview_get_type(void);
GSymView *gsymview_new(void);

