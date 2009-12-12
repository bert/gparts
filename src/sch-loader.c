#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <glib-object.h>

#include "geom.h"

#include "sch-multiline.h"
#include "sch-shape.h"
#include "sch-arc.h"
#include "sch-box.h"
#include "sch-bus.h"
#include "sch-circle.h"
#include "sch-line.h"
#include "sch-net.h"
#include "sch-pin.h"
#include "sch-text.h"
#include "sch-drafter.h"
#include "sch-drawing.h"

#include "sch-component.h"

static const char *directories[] =
{
    "",
    "/home/ehennes/geda/share/gEDA",
    "/home/ehennes/geda/share/gEDA/sym/4000",
    "/home/ehennes/geda/share/gEDA/sym/74",
    "/home/ehennes/geda/share/gEDA/sym/allegro",
    "/home/ehennes/geda/share/gEDA/sym/altera",
    "/home/ehennes/geda/share/gEDA/sym/amphenol",
    "/home/ehennes/geda/share/gEDA/sym/analog",
    "/home/ehennes/geda/share/gEDA/sym/apex",
    "/home/ehennes/geda/share/gEDA/sym/asic",
    "/home/ehennes/geda/share/gEDA/sym/asicpads",
    "/home/ehennes/geda/share/gEDA/sym/bus",
    "/home/ehennes/geda/share/gEDA/sym/cascade",
    "/home/ehennes/geda/share/gEDA/sym/connector",
    "/home/ehennes/geda/share/gEDA/sym/dec",
    "/home/ehennes/geda/share/gEDA/sym/diode",
    "/home/ehennes/geda/share/gEDA/sym/ecl",
    "/home/ehennes/geda/share/gEDA/sym/font",
    "/home/ehennes/geda/share/gEDA/sym/gnetman",
    "/home/ehennes/geda/share/gEDA/sym/idt",
    "/home/ehennes/geda/share/gEDA/sym/IEC417",
    "/home/ehennes/geda/share/gEDA/sym/io",
    "/home/ehennes/geda/share/gEDA/sym/irf",
    "/home/ehennes/geda/share/gEDA/sym/lattice",
    "/home/ehennes/geda/share/gEDA/sym/linear",
    "/home/ehennes/geda/share/gEDA/sym/local",
    "/home/ehennes/geda/share/gEDA/sym/maxim",
    "/home/ehennes/geda/share/gEDA/sym/memory",
    "/home/ehennes/geda/share/gEDA/sym/micro",
    "/home/ehennes/geda/share/gEDA/sym/minicircuits",
    "/home/ehennes/geda/share/gEDA/sym/misc",
    "/home/ehennes/geda/share/gEDA/sym/national",
    "/home/ehennes/geda/share/gEDA/sym/opto",
    "/home/ehennes/geda/share/gEDA/sym/philips",
    "/home/ehennes/geda/share/gEDA/sym/pla",
    "/home/ehennes/geda/share/gEDA/sym/power",
    "/home/ehennes/geda/share/gEDA/sym/radio",
    "/home/ehennes/geda/share/gEDA/sym/relay",
    "/home/ehennes/geda/share/gEDA/sym/rf",
    "/home/ehennes/geda/share/gEDA/sym/spice",
    "/home/ehennes/geda/share/gEDA/sym/st",
    "/home/ehennes/geda/share/gEDA/sym/supervisor",
    "/home/ehennes/geda/share/gEDA/sym/switcap",
    "/home/ehennes/geda/share/gEDA/sym/switch",
    "/home/ehennes/geda/share/gEDA/sym/titleblock",
    "/home/ehennes/geda/share/gEDA/sym/transistor",
    "/home/ehennes/geda/share/gEDA/sym/tube",
    "/home/ehennes/geda/share/gEDA/sym/verilog",
    "/home/ehennes/geda/share/gEDA/sym/vhdl",
    "/home/ehennes/geda/share/gEDA/sym/xilinx",
    NULL
};

struct PARAM
{
    char *name;
    int  dummy;
};

static const struct PARAM arc_params[] =
{
    { NULL,               1 },
    { "center-x",         1 },
    { "center-y",         1 },
    { "radius",           1 },
    { "start",            1 },
    { "sweep",            1 },
    { "color",            1 },
    { "line-width",       3 },
    { "line-cap-style",   3 },
    { "line-dash-style",  3 },
    { "line-dash-length", 3 },
    { "line-dash-space",  3 },
    { NULL,               0 }
};

static const struct PARAM box_params[] =
{
    { NULL,               1 },
    { "x",                1 },
    { "y",                1 },
    { "width",            1 },
    { "height",           1 },
    { "color",            1 },
    { "line-width",       3 },
    { "line-cap-style",   3 },
    { "line-dash-style",  3 },
    { "line-dash-length", 3 },
    { "line-dash-space",  3 },
    { "fill-type",        3 },
    { "fill-width",       3 },
    { "fill-angle1",      3 },
    { "fill-pitch1",      3 },
    { "fill-angle2",      3 },
    { "fill-pitch2",      3 },
    { NULL,               0 }
};

static const struct PARAM bus_params[] =
{
    { NULL,               1 },
    { "x1",               1 },
    { "y1",               1 },
    { "x2",               1 },
    { "y2",               1 },
    { "color",            1 },
    { "ripper-dir",       4 },
    { NULL,               0 }
};

static const struct PARAM component_params[] =
{
    { NULL,               1 },
    { "x",                1 },
    { "y",                1 },
    { "selectable",       1 },
    { "angle",            1 },
    { "mirror",           1 },
    { "basename",         4 },
    { NULL,               0 }
};

static const struct PARAM circle_params[] =
{
    { NULL,               1 },
    { "center-x",         1 },
    { "center-y",         1 },
    { "radius",           1 },
    { "color",            1 },
    { "line-width",       3 },
    { "line-cap-style",   3 },
    { "line-dash-style",  3 },
    { "line-dash-length", 3 },
    { "line-dash-space",  3 },
    { "fill-type",        3 },
    { "fill-width",       3 },
    { "fill-angle1",      3 },
    { "fill-pitch1",      3 },
    { "fill-angle2",      3 },
    { "fill-pitch2",      3 },
    { NULL,               0 }
};


static const struct PARAM line_params[] =
{
    { NULL,               1 },
    { "x1",               1 },
    { "y1",               1 },
    { "x2",               1 },
    { "y2",               1 },
    { "color",            1 },
    { "line-width",       3 },
    { "line-cap-style",   3 },
    { "line-dash-style",  3 },
    { "line-dash-length", 3 },
    { "line-dash-space",  3 },
    { NULL,               0 }
};

static const struct PARAM net_params[] =
{
    { NULL,               1 },
    { "x1",               1 },
    { "y1",               1 },
    { "x2",               1 },
    { "y2",               1 },
    { "color",            1 },
    { NULL,               0 }
};


static const struct PARAM pin_params[] =
{
    { NULL,               1 },
    { "x1",               1 },
    { "y1",               1 },
    { "x2",               1 },
    { "y2",               1 },
    { "color",            1 },
    { "pin-type",         4 },
    { "pin-end",          4 },
    { NULL,               0 }
};


static const struct PARAM text_params[] =
{
    { NULL,               1 },
    { "x",                1 },
    { "y",                1 },
    { "color",            1 },
    { "size",             1 },
    { "visibility",       1 },
    { "show-name-value",  1 },
    { "angle",            1 },
    { "alignment",        2 },
    { NULL,               0 }
};

SchDrawing *load2(const gchar *filename, GError **error);


static GObject*
process_arc(FILE *file, gchar **tokens);

static void
process_attributes(FILE *file, gchar **tokens);

static GObject*
process_box(FILE *file, gchar **tokens);

static GObject*
process_bus(FILE *file, gchar **tokens);

static GObject*
process_circle(FILE *file, gchar **tokens);

static GObject*
process_component(FILE *file, gchar **tokens);

static void
process_embedded(FILE *file, SchDrawing *drawing);

static GObject*
process_line(FILE *file, gchar **tokens);

static GObject*
process_net(FILE *file, gchar **tokens);

static GObject*
process_object(FILE *file, gchar **tokens);

static GObject*
process_path(FILE *file, gchar **tokens);

static GObject*
process_picture(FILE *file, gchar **tokens);

static GObject*
process_pin(FILE *file, gchar **tokens);

static GObject*
process_text(FILE *file, gchar **tokens);

static void
process_version(FILE *file, gchar **tokens);

static void
read_file(SchDrawing *drawing, FILE *file, GError **error);

static gchar*
read_line(FILE *file);




static FILE*
open_drawing(const char *filename)
{
    const char **dir = &directories[0];
    FILE *file = NULL;

    while (*dir != NULL)
    {
        gchar *path;

        path = g_strjoin(NULL, *dir, filename, NULL);
        g_debug("Trying %s", path);
        file = fopen(path, "r");
        g_free(path);

        if (file != NULL)
        {
            break;
        }

        path = g_strjoin("/", *dir, filename, NULL);
        g_debug("Trying %s", path);
        file = fopen(path, "r");
        g_free(path);

        if (file != NULL)
        {
            break;
        }

        dir++;
    }

    return file;
}



void
process_params(GObject *object, gchar **token, const struct PARAM paramv[], gint paramc);


static GObject*
process_arc(FILE *file, gchar **tokens)
{
    SchArc *arc;

    //g_debug("Process arc");

    arc = g_object_new(SCH_TYPE_ARC, NULL);

    process_params(G_OBJECT(arc), tokens, arc_params, 13);

    return G_OBJECT(arc);
}

static void
process_attributes(FILE *file, gchar **tokens)
{
    gchar *line = read_line(file);

    //g_debug("Process attributes (begin)");

    while (line != NULL)
    {
        gchar **token = g_strsplit_set(line, " \t", 0);

        g_free(line);
        line = NULL;

        if ((token != NULL) && (*token != NULL))
        {
            switch (**token)
            {
                case '{':
                    /* error */
                    break;

                case '}':
                    break;

                default:
                    g_object_unref(process_object(file, token));
                    line = read_line(file);
            }
        }

        g_strfreev(token);
    }

    //g_debug("Process attributes (end)");
}

static  GObject*
process_box(FILE *file, gchar **tokens)
{
    SchBox *box;

    //g_debug("Process box");

    box = g_object_new(SCH_TYPE_BOX, NULL);

    process_params(G_OBJECT(box), tokens, box_params, 19);

    return G_OBJECT(box);
}

static GObject*
process_bus(FILE *file, gchar **tokens)
{
    SchBus *net;

    //g_debug("Process net");

    net = g_object_new(SCH_TYPE_BUS, NULL);

    process_params(G_OBJECT(net), tokens, bus_params, 8);

    return G_OBJECT(net);

}

static GObject*
process_circle(FILE *file, gchar **tokens)
{
    SchCircle *circle;

    //g_debug("Process circle");

    circle = g_object_new(SCH_TYPE_CIRCLE, NULL);

    process_params(G_OBJECT(circle), tokens, circle_params, 17);

    return G_OBJECT(circle);
}

static GObject*
process_component(FILE *file, gchar **tokens)
{
    SchComponent *component;

    component = g_object_new(SCH_TYPE_COMPONENT, NULL);

    process_params(G_OBJECT(component), tokens, component_params, 8);

    if (tokens != NULL)
    {
        long lines = 1;
        char *tail;
       
        if (g_strv_length(tokens) > 6)
        {
            g_debug( *(tokens + 6) );

            if (strncmp(*(tokens+6), "EMBEDDED", 8) == 0)
            {
                SchDrawing *symbol;
                int x;
                int y;
                int angle;
                int mirror;
                GeomTransform transform;

                symbol = g_object_new(SCH_TYPE_DRAWING, NULL);
                process_embedded(file, symbol);
                //sch_component_get_insertion_point(component, &x, &y);
                //sch_drawing_translate(symbol, -x, -y); 
                //sch_component_get_orientation(component, &angle, &mirror);
                //sch_drawing_rotate(symbol, -angle); 
                
                sch_component_get_insertion_point(component, &x, &y);
                sch_component_get_orientation(component, &angle, &mirror);

                geom_transform_init(&transform);
                geom_transform_translate(&transform, -x, -y); 
                geom_transform_rotate(&transform, -angle);

                sch_drawing_transform(symbol, &transform);

                sch_component_set_drawing(component, symbol);
                g_object_unref(symbol);
            }
            else
            {
                SchDrawing *symbol = load2(*(tokens+6), NULL);;

                sch_component_set_drawing(component, symbol);
                g_object_unref(symbol);
 
            }
        }
    }

    return component;
}

static void
process_embedded(FILE *file, SchDrawing *drawing)
{
    gchar *line = read_line(file);

    while (line != NULL)
    {
        gchar **token = g_strsplit_set(line, " \t", 0);
        g_free(line);

        if (*token != NULL)
        {
            if (**token != ']')
            {
                GObject *object;

                switch (**token)
                {
                    case '{':
                        process_attributes(file, token);
                        break;

                    default:
                        //g_debug("Process object (begin)");
                        object = process_object(file, token);
                        if (object != NULL)
                        {
                            sch_drawing_add_shape(drawing, object);
                            g_object_unref(object);
                        }
                        //g_debug("Process object (end)");
                }

                line = read_line(file);
            }
            else
            {
                line = NULL;
            }
        }

        g_strfreev(token);
    }
}


static GObject*
process_line(FILE *file, gchar **tokens)
{
    SchLine *line;

    //g_debug("Process line");

    line = g_object_new(SCH_TYPE_LINE, NULL);

    process_params(G_OBJECT(line), tokens, line_params, 12);

    return G_OBJECT(line);
}

static  GObject*
process_net(FILE *file, gchar **tokens)
{
     SchNet *net;

    //g_debug("Process net");

    net = g_object_new(SCH_TYPE_NET, NULL);

    process_params(G_OBJECT(net), tokens, net_params, 7);

    return G_OBJECT(net);

}

static GObject*
process_object(FILE *file, gchar **tokens)
{
    GObject *object;

    if (*tokens != NULL)
    {
        switch (**tokens)
        {
            case 'A':
                object = process_arc(file, tokens);
                break;

            case 'B':
                object = process_box(file, tokens);
                break;

            case 'C':
                object = process_component(file, tokens);
                break;

            case 'G':
                object = process_picture(file, tokens);
                break;

            case 'H':
                object = process_path(file, tokens);
                break;

            case 'L':
                object = process_line(file, tokens);
                break;

            case 'N':
                object = process_net(file, tokens);
                break;

            case 'P':
                object = process_pin(file, tokens);
                break;

            case 'T':
                object = process_text(file, tokens);
                break;

            case 'U':
                object = process_bus(file, tokens);
                break;

            case 'V':
                object = process_circle(file, tokens);
                break;

            default:
                object = NULL;
                g_debug("Unknown object type %c", **tokens);
                break;
        }
    }

    return object;
}

static  GObject*
process_path(FILE *file, gchar **tokens)
{
    //g_debug("Process path");
    if ((tokens != NULL) && (g_strv_length(tokens) > 13))
    {
        long lines;
        char *tail;
        
        lines = strtol(*(tokens + 13), &tail, 10);

        if (*(tokens + 13) == tail)
        {
            /* invalid */
        }
        else if (lines < 1 || lines > 999)
        {
            /* out of range */
        }
        else
        {
            long index;

            for (index=0; index<lines; index++)
            {
                gchar *line = read_line(file);
                g_free(line);    
            }
        }
    }


    return NULL;
}

static GObject*
process_picture(FILE *file, gchar **tokens)
{
    //g_debug("Process picture");

    return NULL;
}

static GObject*
process_pin(FILE *file, gchar **tokens)
{
    SchPin *pin;

    //g_debug("Process pin");

    pin = g_object_new(SCH_TYPE_PIN, NULL);

    process_params(G_OBJECT(pin), tokens, pin_params, 9);

    return G_OBJECT(pin);
}

static GObject*
process_text(FILE *file, gchar **tokens)
{
    SchText *text;

    //g_debug("Process text");

    text = g_object_new(SCH_TYPE_TEXT, NULL);

    process_params(G_OBJECT(text), tokens, text_params, 10);

    if (tokens != NULL)
    {
        long lines = 1;
        char *tail;
       
        if (g_strv_length(tokens) > 9)
        {
            lines = strtol(*(tokens + 9), &tail, 10);

            if (*(tokens + 9) == tail)
            {
                /* invalid */
            }
            else if (lines < 1 || lines > 999)
            {
                /* out of range */
            }
        }
        
        {
            long index;
            SchMultiline *multiline = g_object_new(SCH_TYPE_MULTILINE, NULL);

            for (index=0; index<lines; index++)
            {
                gchar *line = read_line(file);
                sch_multiline_append(multiline, line);
                g_free(line);    
            }

            sch_text_set_multiline(text, multiline);
            g_object_unref(multiline);
        }
    }

    return G_OBJECT(text);
}

static void
process_version(FILE *file, gchar **tokens)
{
    //g_debug("Process version");
}



/*! \brief Reads a line from a file
 */
static gchar*
read_line(FILE *file)
{
    gchar *result = NULL;

    if (!feof(file))
    {
        gint c = fgetc(file);
        GString *line = g_string_sized_new(10);

        while (!ferror(file) && !feof(file) && (c != '\n'))
        {
            g_string_append_c(line, c);
            c = fgetc(file);
        }

        result = g_string_free(line, ferror(file));
    }

    return result;
}


static void
read_file(SchDrawing *drawing, FILE *file, GError **error)
{
    gchar *line = read_line(file);

    while (line != NULL)
    {
        //g_debug("Hello inside read file");

        gchar **token = g_strsplit_set(line, " \t", 0);
        g_free(line);

        if (*token != NULL)
        {
            GObject *object;

            switch (**token)
            {
                case 'v':
                    process_version(file, token);
                    break;

                case '{':
                    process_attributes(file, token);
                    break;

                case '}':
                    /* error */
                    break;

                default:
                    //g_debug("Process object (begin)");
                    object = process_object(file, token);
                    if (object != NULL)
                    {
                        sch_drawing_add_shape(drawing, object);
                        g_object_unref(object);
                    }
                    //g_debug("Process object (end)");
            }
        }

        g_strfreev(token);
        line = read_line(file);
    }
}


SchDrawing *load2(const gchar *filename, GError **error)
{
    SchDrawing *drawing = NULL;
    FILE       *file;

    //g_debug("Loader 1");

    file = open_drawing(filename);

    //file = fopen(filename, "r");
    //g_debug("Loader 2");

    if (file != NULL)
    {
        drawing = g_object_new(SCH_TYPE_DRAWING, NULL);

        //g_debug("Loader 3");

        read_file(drawing, file, error);

        //g_debug("Loader 4");

        fclose(file);
    }
    else
    {
        //g_set_error(
        //    error,
        //    GPARTS_MYSQL_DATABASE_ERROR,
        //    mysql_errno( private->mysql ),
        //    "%s",
        //    mysql_error( private->mysql )
        //    );

        g_debug("Could not open '%s'", filename);
    }

    return drawing;
}



void
set_value(GValue *value, const char *string)
{
    if (G_VALUE_TYPE(value) == G_TYPE_STRING)
    {
        g_value_set_string(value, string);
    }
    else if (G_VALUE_TYPE(value) == G_TYPE_INT)
    {
        long number;
        char *tail;
        
        number = strtol(string, &tail, 10);
        g_value_set_int(value, number);

        //if (*(tokens + 9) == tail)
       // {
       //     /* invalid */
        //}
        //else
       // {
       //     g_value_set_int(value, number);
       // }
    }
    else
    {
        g_warning("Unknown type");
    }
}

void
process_params(GObject *object, gchar **token, const struct PARAM paramv[], gint paramc)
{
    GObjectClass *object_class = G_OBJECT_GET_CLASS(object);

    if (object_class != NULL)
    {
        gint index;

        for (index=0; index<paramc; index++)
        {
            const char *name = paramv[index].name;

            if (name != NULL)
            {
                GParamSpec *pspec = g_object_class_find_property(object_class, name);
                GValue value = {0};

                if (pspec == NULL)
                {
                    g_warning("    Unknown property %s", name);
                    continue;
                }

                if ((pspec->flags & G_PARAM_WRITABLE) == 0)
                {
                    g_warning("    Property not writable %s", name);
                    continue;
                }

                if (token[index] == NULL)
                {
                    g_warning("    Not enough parameters");
                    break;
                }

                g_value_init(&value, G_PARAM_SPEC_VALUE_TYPE(pspec));
                set_value(&value, token[index]);

                //g_debug("    Assigning parameter %s", name);

                g_object_set_property(object, name, &value);
                g_value_unset(&value);
            }
        }
    }
}

