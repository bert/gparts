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

#include <gtk/gtk.h>

#include "gparts-database-result.h"
#include "gparts-result-model.h"
#include "gparts-units.h"

#define GPARTS_RESULT_MODEL_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_RESULT_MODEL,GPartsResultModelPrivate)

enum
{
    GPARTS_RESULT_MODEL_PROPID_RESULT = 1
};

typedef struct _GPartsResultModelPrivate GPartsResultModelPrivate;

struct _GPartsResultModelPrivate
{
    GPartsDatabaseResult *result;
    gint                 stamp;
};

static void
gparts_result_model_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_result_model_dispose(GObject *object);

static void
gparts_result_model_finalize(GObject *object);

static GType
gparts_result_model_get_column_type(GtkTreeModel *tree_model, gint index);

static void
gparts_result_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static GtkTreeModelFlags
gparts_result_model_get_flags(GtkTreeModel *tree_model);

static gboolean
gparts_result_model_get_iter(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreePath *path);

static gint
gparts_result_model_get_n_columns(GtkTreeModel *tree_model);

static GtkTreePath*
gparts_result_model_get_path(GtkTreeModel *tree_model, GtkTreeIter *iter);

static void
gparts_result_model_get_value(GtkTreeModel *tree_model, GtkTreeIter *iter, gint column, GValue *value);

static void
gparts_result_model_instance_init(GTypeInstance *instance, gpointer g_class);

/*static*/ gboolean
gparts_result_model_iter_children(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *parent);

static gboolean
gparts_result_model_iter_has_child(GtkTreeModel *tree_model, GtkTreeIter *iter);

static gboolean
gparts_result_model_iter_next(GtkTreeModel *tree_model, GtkTreeIter *iter);

static gint
gparts_result_model_iter_n_children(GtkTreeModel *tree_model, GtkTreeIter *iter);

static gboolean
gparts_result_model_iter_nth_child(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *parent, gint n);

static gboolean
gparts_result_model_iter_parent(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *child);

static void
gparts_result_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gparts_result_model_set_result(GObject *object, GObject *value);

static void
gparts_result_model_tree_model_init(GtkTreeModelIface *iface);

static void
gparts_result_model_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(
        g_class,
        sizeof(GPartsResultModelPrivate)
        );

    object_class->dispose      = gparts_result_model_dispose;
    object_class->finalize     = gparts_result_model_finalize;
    object_class->get_property = gparts_result_model_get_property;
    object_class->set_property = gparts_result_model_set_property;

    g_object_class_install_property(
        object_class,
        GPARTS_RESULT_MODEL_PROPID_RESULT,
        g_param_spec_object(
            "result",
            "",
            "",
            G_TYPE_OBJECT,
            G_PARAM_READWRITE
            )
        );
}

static void
gparts_result_model_dispose(GObject *object)
{
    g_debug("gparts_result_model_dispose()");

    gparts_result_model_set_result(object, NULL);

    GObjectClass *parent_class = g_type_class_peek_parent(GPARTS_RESULT_MODEL_GET_CLASS(object));
    G_OBJECT_CLASS(parent_class)->dispose(object);
}

static void
gparts_result_model_finalize(GObject *object)
{
    g_debug("gparts_result_model_finalize()");

    GObjectClass *parent_class = g_type_class_peek_parent(GPARTS_RESULT_MODEL_GET_CLASS(object));
    G_OBJECT_CLASS(parent_class)->finalize(object);
}

gboolean
gparts_result_model_get_column_index(GPartsResultModel *result_model, const gchar *name, gint *index)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(result_model);

    return gparts_database_result_get_column_index(private->result, name, index);
}

/*! \brief Gets the GType of a given column.
 *
 *  \param [in] tree_model The GPartsResultModel.
 *  \param [in] index      The zero based index of the column.
 *  \return The column's GType.
 */
static GType
gparts_result_model_get_column_type(GtkTreeModel *tree_model, gint index)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(tree_model);

    return gparts_database_result_get_column_type(private->result, index);
}

gchar*
gparts_result_model_get_field(GPartsResultModel *model, GtkTreeIter *iter, const gchar *name)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(model);
    gchar *result = NULL;

    if (private->result != NULL)
    {
        gint index;
        gboolean success;

        success = gparts_database_result_get_column_index(private->result, name, &index);

        if (success)
        {
            gboolean error = FALSE;
            GString *buffer = g_string_sized_new(10);
            GValue value = {0};

            gparts_database_result_get_field_value(
                private->result,
                GPOINTER_TO_UINT(iter->user_data),
                index,
                &value
                );

            /* TODO The following code needs to go elsewhere or use transformations */

            if(G_IS_VALUE(&value))
            {
                if (G_VALUE_HOLDS_STRING(&value))
                {
                    g_string_printf(buffer, "%s", g_value_get_string(&value));
                }
                else if (G_VALUE_HOLDS_DOUBLE(&value))
                {
                    g_string_printf(buffer, "%f", g_value_get_double(&value));
                }
                else if (G_VALUE_HOLDS_INT(&value))
                {
                    g_string_printf(buffer, "%d", g_value_get_int(&value));
                }
                else
                {
                    error = TRUE;
                }

                result = g_string_free(buffer, error);
             }
        }
    }

    return result;
}

/*! \brief
 *
 *
 *
 *
 */
static void
gparts_result_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(object);

    /* TODO handle case where private is NULL */

    switch ( property_id )
    {
        case GPARTS_RESULT_MODEL_PROPID_RESULT:
            g_value_set_object(value, private->result);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

/*! \brief Gets this model's GtkTreeModelFlags.
 *
 *  \param [in]  tree_model The GPartsResultModel.
 *  \return This model's GtkTreeModelFlags.
 */
static GtkTreeModelFlags
gparts_result_model_get_flags(GtkTreeModel *tree_model)
{
    return GTK_TREE_MODEL_LIST_ONLY;
}


/*! \brief Converts a tree path to a tree iterator.
 *
 *  This function will fail if the path does not refer to a valid node in the
 *  tree model.
 *
 *  \param [in]  tree_model The GPartsResultModel
 *  \param [out] iter       If successful, a GtkTreeIter.  Invalid if unsuccessful.
 *  \param [in]  path       The GtkTreePath to convert to a GtkTreeIter.
 *  \return TRUE if successful and iter is valid.  FALSE if otherwise and the
 *  iter will not be valid.
 */
static gboolean
gparts_result_model_get_iter(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreePath *path)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(tree_model);

    gint index = gtk_tree_path_get_indices(path)[0];

    guint rows = gparts_database_result_get_row_count(private->result);

    if (index < rows)
    {
        iter->stamp = private->stamp;
        iter->user_data = GUINT_TO_POINTER(index);

        return TRUE;
    }

    return FALSE;
}
/*! \brief Returns the number of columns in the tree model.
 *
 *  \param [in] tree_model The GPartsResultModel.
 *  \param [in] tree_model The given tree model.
 *  \return The number of columns in the tree model.
 */
static gint
gparts_result_model_get_n_columns(GtkTreeModel *tree_model)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(tree_model);

    return gparts_database_result_get_column_count(private->result);
}

/*! \brief Converts a GtkTreeIter to a GtkTreePath.
 *
 *  \param [in] tree_model The GPartsResultModel.
 *  \param [in] iter       The iterator to convert to a tree path.
 *  \return A GtkTreePath that refers to the same node as the iterator.
 */
static GtkTreePath*
gparts_result_model_get_path(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(tree_model);

    g_assert(iter != NULL);
    g_assert(iter->stamp == private->stamp);

    GtkTreePath *tree_path = gtk_tree_path_new();

    gtk_tree_path_append_index(tree_path, GPOINTER_TO_INT(iter->user_data));

    return tree_path;
}

/*! \brief Register this class's GType.
 *
 *  \return The GType of this class.
 */
GType
gparts_result_model_get_type( void )
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsResultModelClass),
            NULL,
            NULL,
            gparts_result_model_class_init,
            NULL,
            NULL,
            sizeof(GPartsResultModel),
            0,
            gparts_result_model_instance_init,
            NULL
            };

        static const GInterfaceInfo iinfo = {
            (GInterfaceInitFunc) gparts_result_model_tree_model_init,
            NULL,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "gparts-result-model",
            &tinfo,
            0
            );

        g_type_add_interface_static(
            type,
            GTK_TYPE_TREE_MODEL,
            &iinfo
            );
    }
    return type;
}

/*! \brief Get a value from the tree model.
 *
 *  This function turns invalid values into blanks.  So, an invalid column or
 *  row will still result in a valid GValue.
 *
 *  \param [in]  tree_model The GPartsResultModel.
 *  \param [in]  iter       An iterator referencing the value's row.
 *  \param [in]  column     A zero based index of the value's column.
 *  \param [out] value      The value of the cell as a GValue.
 */
static void
gparts_result_model_get_value(GtkTreeModel *tree_model, GtkTreeIter *iter, gint column, GValue *value)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(tree_model);

    g_assert(iter != NULL);
    g_assert(iter->stamp == private->stamp);

    gparts_database_result_get_field_value(
        private->result,
        GPOINTER_TO_UINT(iter->user_data),
        column,
        value
        );

    /* Turn uninitialized values into blanks */

    if (!G_IS_VALUE(value))
    {
        g_value_init(value, G_TYPE_STRING);
    }
}

/*! \brief Initialize instance data.
 *
 *  \param instance
 *  \param g_class
 */
static void
gparts_result_model_instance_init(GTypeInstance* instance, gpointer g_class)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(instance);

    private->stamp = g_random_int();
}

/*! \brief Gets an iterator to a list's first child.
 *
 *  If the parent is NULL, this function gets an iterator to the first node in
 *  the root list.  Since this model does not implement trees, all other cases
 *  return FALSE.
 *
 *  \param [in]  tree_model The GPartsResultModel.
 *  \param [out] iter       If successful, the first child of parent.
 *  \param [in]  parent     The parent node.
 *  \retval TRUE  if successful and iter is valid.
 *  \retval FALSE if otherwise and the iter will not be valid.
 */
/*static*/ gboolean
gparts_result_model_iter_children(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *parent)
{
    if (parent == NULL)
    {
        GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(tree_model);

        iter->stamp = private->stamp;
        iter->user_data = GINT_TO_POINTER(0);

        return TRUE;
    }

    return FALSE;
}

/*! \brief Determines if a node has children.
 *
 *  Since this model only handles lists, this function always returns FALSE.
 *
 *  \param [in]  tree_model Unused.
 *  \param [out] iter       Unused.
 *  \return FALSE, always.
 */
static gboolean
gparts_result_model_iter_has_child(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
    return FALSE;
}

/*! \brief Get the next node in sequence.
 *
 *  \param [in]     tree_model The GPartsResultModel.
 *  \param [in,out] iter       The node on entry.  If successful, the next node.
 *  \return TRUE if successful and iter is valid.  FALSE if otherwise and the
 *  iter will not be valid.
 */
static gboolean
gparts_result_model_iter_next(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
    guint new_position;
    guint old_position;
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(tree_model);

    g_assert(iter != NULL);
    g_assert(iter->stamp == private->stamp);

    old_position = GPOINTER_TO_UINT(iter->user_data);

    new_position = old_position + 1;

    if (new_position > old_position)
    {
        guint rows = gparts_database_result_get_row_count(private->result);

        if (new_position < rows)
        {
            iter->user_data = GUINT_TO_POINTER(new_position);

            return TRUE;
        }
    }

    return FALSE;
}

/*! \brief Returns the number of children a node contains.
 *
 *  Since this model only handles lists, this function returns 0.
 *
 *  \param [in] tree_model The GPartsResultModel.
 *  \param [in] iter       The given node.
 *  \return The number of iter's children.
 */
static gint
gparts_result_model_iter_n_children(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
    gint rows = 0;

    if (iter == NULL)
    {
        GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(tree_model);

        rows = gparts_database_result_get_row_count(private->result);
    }

    return rows;
}

/*! \brief Gets an iterator to a node's nth child.
 *
 *  If the parent is NULL, this function gets an iterator to the nth node in
 *  the root list.  Since this model only implements lists, in all other cases,
 *  this function returns FALSE.
 *
 *  \param [in]  tree_model The GPartsResultModel.
 *  \param [out] iter       If successful, the nth child of the parent node.
 *  \param [in]  parent     The parent node.
 *  \param [in]  n          The zero based index of the child node.
 *  \return TRUE if successful and iter is valid.  FALSE if otherwise and the
 *  iter will not be valid.
 */
static gboolean
gparts_result_model_iter_nth_child(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *parent, gint n)
{
    g_assert(iter != NULL);

    if (parent == NULL)
    {
        GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(tree_model);
        guint rows = gparts_database_result_get_row_count(private->result);

        if (n < rows)
        {
            iter->stamp = private->stamp;
            iter->user_data = GINT_TO_POINTER(n);

            return TRUE;
        }
    }

    return FALSE;
}

/*! \brief Obtains the parent node of a child node.
 *
 *  Since this model only implements lists, this function always returns FALSE.
 *
 *  \param [in]  tree_model The GPartsResultModel.
 *  \param [out] iter       If successful, the parent node.
 *  \param [in]  child      The child node.
 *  \return TRUE if successful and iter is valid.  FALSE if otherwise and the
 *  iter will not be valid.
 */
static gboolean
gparts_result_model_iter_parent(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *child)
{
    return FALSE;
}

/*! \brief Creates a new GPartsResultModel.
 *
 *  \return A new GPartsResultModel.
 */
GPartsResultModel *
gparts_result_model_new(void)
{
    return g_object_new(GPARTS_TYPE_RESULT_MODEL, NULL);
}

/*! \brief Adjusts the GtkTreeView's columns to match the database result.
 *
 *
 *
 *  \param [in] result
 *  \param [in] tree_view
 */
void
gparts_result_model_set_columns(GPartsDatabaseResult *result, GtkTreeView *tree_view)
{
    gint columns;
    GtkTreeViewColumn *column;
    gint index;
    GValue value = {0};

    columns = gparts_database_result_get_column_count(result);

    g_value_init(&value, G_TYPE_STRING);

    for(index=0; index<columns; index++)
    {
        GList *list;

        column = gtk_tree_view_get_column(tree_view, index);

        if (column == NULL)
        {
            GtkCellRenderer *renderer = gtk_cell_renderer_text_new();

            column = gtk_tree_view_column_new();

            g_object_set(
                column,
                "resizable", TRUE,
                "reorderable", TRUE,
                "sizing", GTK_TREE_VIEW_COLUMN_GROW_ONLY,
                NULL
                );

            gtk_tree_view_column_pack_start(column, renderer, TRUE);

            gtk_tree_view_column_add_attribute(column, renderer, "text", index);

            gtk_tree_view_append_column(tree_view, column);

        }

        list = gtk_tree_view_column_get_cell_renderers(column);

        if (list != NULL)
        {
            GList *node = g_list_first(list);

            while (node != NULL)
            {
                GType type = gparts_database_result_get_column_type(result, index);

                if (type == G_TYPE_STRING)
                {
                    g_object_set(G_OBJECT(node->data), "xalign", 0.0, NULL );
                }
                else
                {
                    g_object_set(G_OBJECT(node->data), "xalign", 1.0, NULL );
                }

                gparts_units_attach_cell_data_func(
                    column,
                    GTK_CELL_RENDERER(node->data),
                    index,
                    gparts_database_result_get_column_units(result, index)
                    );

                node = g_list_next(node);
            }
        }

        g_list_free(list);

        gparts_database_result_get_column_value(result, index, &value);
        g_object_set_property(G_OBJECT(column), "title", &value);

    }

    g_value_unset(&value);

    /* Delete any additional columns */

    column = gtk_tree_view_get_column(tree_view, columns);

    while(column != NULL)
    {
        gtk_tree_view_remove_column(tree_view, column);

        column = gtk_tree_view_get_column(tree_view, columns);
    }
}

/*! \brief
 *
 *
 *
 *
 */
static void
gparts_result_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    switch ( property_id )
    {
        case GPARTS_RESULT_MODEL_PROPID_RESULT:
            gparts_result_model_set_result(object, g_value_get_object(value));
            break;

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
static void
gparts_result_model_set_result(GObject *object, GObject *value)
{
    GPartsResultModelPrivate *private = GPARTS_RESULT_MODEL_GET_PRIVATE(object);

    if (private->result != NULL)
    {
        g_object_unref(private->result);
    }

    private->result = GPARTS_DATABASE_RESULT(value);

    if (private->result != NULL)
    {
        g_object_ref(private->result);
    }
}

/*! \brief Initialize the tree model interface.
 *
 *  \param [in] iface A pointer to the tree model interface.
 */
static void
gparts_result_model_tree_model_init(GtkTreeModelIface *iface)
{
    iface->get_flags       = gparts_result_model_get_flags;
    iface->get_n_columns   = gparts_result_model_get_n_columns;
    iface->get_column_type = gparts_result_model_get_column_type;
    iface->get_iter        = gparts_result_model_get_iter;
    iface->get_path        = gparts_result_model_get_path;
    iface->get_value       = gparts_result_model_get_value;
    iface->iter_next       = gparts_result_model_iter_next;
    iface->iter_children   = gparts_result_model_iter_children;
    iface->iter_has_child  = gparts_result_model_iter_has_child;
    iface->iter_n_children = gparts_result_model_iter_n_children;
    iface->iter_nth_child  = gparts_result_model_iter_nth_child;
    iface->iter_parent     = gparts_result_model_iter_parent;
}

