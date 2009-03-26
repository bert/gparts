
#define GPARTS_TYPE (gparts_get_type())
#define GPARTS(object) (G_TYPE_CHECK_INSTANCE_CAST((object), GPARTS_TYPE, GParts))

typedef struct _GParts GParts;
typedef struct _GPartsClass GPartsClass;

struct _GParts
{
    GObject parent;
};

struct _GPartsClass
{
    GObjectClass parent;
};

GType gparts_get_type(void);
GParts *gparts_new(void);

