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

#include "misc-object.h"

#include "gparts-customize-model.h"

#define GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE(object,GPARTS_TYPE_CUSTOMIZE_MODEL,GPartsCustomizeModelPrivate)

enum
{
    GPARTS_CUSTOMIZE_MODEL_PROPID_VIEW = 1
};

typedef struct _GPartsCustomizeModelPrivate GPartsCustomizeModelPrivate;

struct _GPartsCustomizeModelPrivate
{
    GtkTreeView *view;
    gint        stamp;
};

static void
gparts_customize_model_class_init(gpointer g_class, gpointer g_class_data);

static void
gparts_customize_model_dispose(GObject *object);

static void
gparts_customize_model_finalize(GObject *object);

static GType
gparts_customize_model_get_column_type(GtkTreeModel *tree_model, gint index);

static void
gparts_customize_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

static GtkTreeModelFlags
gparts_customize_model_get_flags(GtkTreeModel *tree_model);

static gboolean
gparts_customize_model_get_iter(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreePath *path);

static gint
gparts_customize_model_get_n_columns(GtkTreeModel *tree_model);

static GtkTreePath*
gparts_customize_model_get_path(GtkTreeModel *tree_model, GtkTreeIter *iter);

static void
gparts_customize_model_get_value(GtkTreeModel *tree_model, GtkTreeIter *iter, gint column, GValue *value);

static void
gparts_customize_model_instance_init(GTypeInstance *instance, gpointer g_class);

/*static*/ gboolean
gparts_customize_model_iter_children(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *parent);

static gboolean
gparts_customize_model_iter_has_child(GtkTreeModel *tree_model, GtkTreeIter *iter);

static gboolean
gparts_customize_model_iter_next(GtkTreeModel *tree_model, GtkTreeIter *iter);

static gint
gparts_customize_model_iter_n_children(GtkTreeModel *tree_model, GtkTreeIter *iter);

static gboolean
gparts_customize_model_iter_nth_child(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *parent, gint n);

static gboolean
gparts_customize_model_iter_parent(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *child);

static void
gparts_customize_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);

static void
gparts_customize_model_set_view(GObject *object, GtkTreeView *value);

static void
gparts_customize_model_tree_model_init(GtkTreeModelIface *iface);

static void
gparts_customize_model_class_init(gpointer g_class, gpointer g_class_data)
{
    GObjectClass* object_class = G_OBJECT_CLASS(g_class);

    g_type_class_add_private(g_class, sizeof(GPartsCustomizeModelPrivate));

    object_class->dispose      = gparts_customize_model_dispose;
    object_class->finalize     = gparts_customize_model_finalize;
    object_class->get_property = gparts_customize_model_get_property;
    object_class->set_property = gparts_customize_model_set_property;

    g_object_class_install_property(
        object_class,
        GPARTS_CUSTOMIZE_MODEL_PROPID_VIEW,
        g_param_spec_object(
            "view",
            "",
            "",
            GTK_TYPE_TREE_VIEW,
            G_PARAM_READWRITE
            )
        );
}

static void
gparts_customize_model_dispose(GObject *object)
{
    g_debug("gparts_customize_model_dispose()");

    gparts_customize_model_set_view(object, NULL);

    //GObjectClass *parent_class = g_type_class_peek_parent(GPARTS_CUSTOMIZE_MODEL_GET_CLASS(object));
    //G_OBJECT_CLASS(parent_class)->dispose(object);
    misc_object_chain_dispose(object);
}

static void
gparts_customize_model_finalize(GObject *object)
{
    g_debug("gparts_customize_model_finalize()");

    //GObjectClass *parent_class = g_type_class_peek_parent(GPARTS_CUSTOMIZE_MODEL_GET_CLASS(object));
    //G_OBJECT_CLASS(parent_class)->finalize(object);
    misc_object_chain_finalize(object);
}

/*! \brief Gets the GType of a given column.
 *
 *  \param [in] tree_model The GPartsCustomizeModel.
 *  \param [in] index      The zero based index of the column.
 *  \return The column's GType.
 */
static GType
gparts_customize_model_get_column_type(GtkTreeModel *tree_model, gint index)
{
    GType type;

    switch (index)
    {
        case 0:
            type = G_TYPE_STRING;
            break;

        case 1:
            type = G_TYPE_BOOLEAN;
            break;

        default:
            type = G_TYPE_INVALID;
    }

    return type;
}

/*! \brief
 *
 *
 *
 *
 */
static void
gparts_customize_model_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
    GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(object);

    /* TODO handle case where private is NULL */

    switch (property_id)
    {
        case GPARTS_CUSTOMIZE_MODEL_PROPID_VIEW:
            g_value_set_object(value, privat->view);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    }
}

/*! \brief Gets this model's GtkTreeModelFlags.
 *
 *  \param [in]  tree_model The GPartsCustomizeModel.
 *  \return This model's GtkTreeModelFlags.
 */
static GtkTreeModelFlags
gparts_customize_model_get_flags(GtkTreeModel *tree_model)
{
    return GTK_TREE_MODEL_LIST_ONLY;
}


/*! \brief Converts a tree path to a tree iterator.
 *
 *  This function will fail if the path does not refer to a valid node in the
 *  tree model.
 *
 *  \param [in]  tree_model The GPartsCustomizeModel
 *  \param [out] iter       If successful, a GtkTreeIter.  Invalid if unsuccessful.
 *  \param [in]  path       The GtkTreePath to convert to a GtkTreeIter.
 *  \return TRUE if successful and iter is valid.  FALSE if otherwise and the
 *  iter will not be valid.
 */
static gboolean
gparts_customize_model_get_iter(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreePath *path)
{
    GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(tree_model);
    gint index = gtk_tree_path_get_indices(path)[0];
    guint rows = gparts_customize_model_iter_n_children(tree_model, NULL);

    if (index < rows)
    {
        iter->stamp = privat->stamp;
        iter->user_data = GUINT_TO_POINTER(index);

        return TRUE;
    }

    return FALSE;
}
/*! \brief Returns the number of columns in the tree model.
 *
 *  \param [in] tree_model The GPartsCustomizeModel.
 *  \param [in] tree_model The given tree model.
 *  \return The number of columns in the tree model.
 */
static gint
gparts_customize_model_get_n_columns(GtkTreeModel *tree_model)
{
    return 2;
}

/*! \brief Converts a GtkTreeIter to a GtkTreePath.
 *
 *  \param [in] tree_model The GPartsCustomizeModel.
 *  \param [in] iter       The iterator to convert to a tree path.
 *  \return A GtkTreePath that refers to the same node as the iterator.
 */
static GtkTreePath*
gparts_customize_model_get_path(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
    GPartsCustomizeModelPrivate *private = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(tree_model);

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
gparts_customize_model_get_type( void )
{
    static GType type = 0;

    if ( type == 0 )
    {
        static const GTypeInfo tinfo = {
            sizeof(GPartsCustomizeModelClass),
            NULL,
            NULL,
            gparts_customize_model_class_init,
            NULL,
            NULL,
            sizeof(GPartsCustomizeModel),
            0,
            gparts_customize_model_instance_init,
            NULL
            };

        static const GInterfaceInfo iinfo = {
            (GInterfaceInitFunc) gparts_customize_model_tree_model_init,
            NULL,
            NULL
            };

        type = g_type_register_static(
            G_TYPE_OBJECT,
            "GPartsCustomizeModel",
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
 *  \param [in]  tree_model The GPartsCustomizeModel.
 *  \param [in]  iter       An iterator referencing the value's row.
 *  \param [in]  column     A zero based index of the value's column.
 *  \param [out] value      The value of the cell as a GValue.
 */
static void
gparts_customize_model_get_value(GtkTreeModel *tree_model, GtkTreeIter *iter, gint column, GValue *value)
{
    GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(tree_model);

    g_assert(iter != NULL);
    g_assert(iter->stamp == privat->stamp);

    if (privat->view != NULL)
    {
        GtkTreeViewColumn *view_column;

        view_column = gtk_tree_view_get_column(privat->view, GPOINTER_TO_INT(iter->user_data));

        if (view_column != NULL)
        {
            switch (column)
            {
                case 0:
                    g_value_init(value, G_TYPE_STRING);
                    g_value_set_string(value, gtk_tree_view_column_get_title(view_column));
                    break;

                case 1:
                    g_value_init(value, G_TYPE_BOOLEAN);
                    g_value_set_boolean(value, gtk_tree_view_column_get_visible(view_column));
                    break;

//                default:
            }
        }
    }

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
gparts_customize_model_instance_init(GTypeInstance* instance, gpointer g_class)
{
    GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(instance);

    privat->stamp = g_random_int();
}

/*! \brief Gets an iterator to a list's first child.
 *
 *  If the parent is NULL, this function gets an iterator to the first node in
 *  the root list.  Since this model does not implement trees, all other cases
 *  return FALSE.
 *
 *  \param [in]  tree_model The GPartsCustomizeModel.
 *  \param [out] iter       If successful, the first child of parent.
 *  \param [in]  parent     The parent node.
 *  \retval TRUE  if successful and iter is valid.
 *  \retval FALSE if otherwise and the iter will not be valid.
 */
/*static*/ gboolean
gparts_customize_model_iter_children(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *parent)
{
    if (parent == NULL)
    {
        GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(tree_model);

        iter->stamp = privat->stamp;
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
gparts_customize_model_iter_has_child(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
    return FALSE;
}

/*! \brief Get the next node in sequence.
 *
 *  \param [in]     tree_model The GPartsCustomizeModel.
 *  \param [in,out] iter       The node on entry.  If successful, the next node.
 *  \return TRUE if successful and iter is valid.  FALSE if otherwise and the
 *  iter will not be valid.
 */
static gboolean
gparts_customize_model_iter_next(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
    gint new_position;
    gint old_position;
    GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(tree_model);

    g_assert(iter != NULL);
    g_assert(iter->stamp == privat->stamp);

    old_position = GPOINTER_TO_UINT(iter->user_data);

    new_position = old_position + 1;

    if (new_position > old_position)
    {
        gint rows = gparts_customize_model_iter_n_children(tree_model, NULL);

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
 *  \param [in] tree_model The GPartsCustomizeModel.
 *  \param [in] iter       The given node.
 *  \return The number of iter's children.
 */
static gint
gparts_customize_model_iter_n_children(GtkTreeModel *tree_model, GtkTreeIter *iter)
{
    gint rows = 0;

    if (iter == NULL)
    {
        GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(tree_model);

        if (privat->view != NULL)
        {
            GList *list = gtk_tree_view_get_columns(privat->view);

            rows = g_list_length(list);

            g_list_free(list);
        }
    }

    return rows;
}

/*! \brief Gets an iterator to a node's nth child.
 *
 *  If the parent is NULL, this function gets an iterator to the nth node in
 *  the root list.  Since this model only implements lists, in all other cases,
 *  this function returns FALSE.
 *
 *  \param [in]  tree_model The GPartsCustomizeModel.
 *  \param [out] iter       If successful, the nth child of the parent node.
 *  \param [in]  parent     The parent node.
 *  \param [in]  n          The zero based index of the child node.
 *  \return TRUE if successful and iter is valid.  FALSE if otherwise and the
 *  iter will not be valid.
 */
static gboolean
gparts_customize_model_iter_nth_child(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *parent, gint n)
{
    g_assert(iter != NULL);

    if (parent == NULL)
    {
        GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(tree_model);
        guint rows = gparts_customize_model_iter_n_children(tree_model, NULL);

        if (n < rows)
        {
            iter->stamp = privat->stamp;
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
 *  \param [in]  tree_model The GPartsCustomizeModel.
 *  \param [out] iter       If successful, the parent node.
 *  \param [in]  child      The child node.
 *  \return TRUE if successful and iter is valid.  FALSE if otherwise and the
 *  iter will not be valid.
 */
static gboolean
gparts_customize_model_iter_parent(GtkTreeModel *tree_model, GtkTreeIter *iter, GtkTreeIter *child)
{
    return FALSE;
}

GPartsCustomizeModel *
gparts_customize_model_new(void)
{
    return g_object_new(GPARTS_TYPE_CUSTOMIZE_MODEL, NULL);
}

static void
gparts_customize_model_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
    switch (property_id)
    {
        case GPARTS_CUSTOMIZE_MODEL_PROPID_VIEW:
            gparts_customize_model_set_view(object, g_value_get_object(value));
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
gparts_customize_model_set_view(GObject *object, GtkTreeView *view)
{
    GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(object);

    if (privat->view != NULL)
    {
        g_object_unref(privat->view);
    }

    privat->view = view;

    if (privat->view != NULL)
    {
        g_object_ref(privat->view);
    }
}

void
gparts_customize_model_set_visible(GPartsCustomizeModel *model, GtkTreeIter *iter, gboolean visible)
{
    GPartsCustomizeModelPrivate *privat = GPARTS_CUSTOMIZE_MODEL_GET_PRIVATE(model);
    GtkTreeViewColumn *view_column;

    view_column = gtk_tree_view_get_column(privat->view, GPOINTER_TO_INT(iter->user_data));

    if (view_column != NULL)
    {
        gtk_tree_view_column_set_visible(view_column, visible);
    }
}

/*! \brief Initialize the tree model interface.
 *
 *  \param [in] iface A pointer to the tree model interface.
 */
static void
gparts_customize_model_tree_model_init(GtkTreeModelIface *iface)
{
    iface->get_flags       = gparts_customize_model_get_flags;
    iface->get_n_columns   = gparts_customize_model_get_n_columns;
    iface->get_column_type = gparts_customize_model_get_column_type;
    iface->get_iter        = gparts_customize_model_get_iter;
    iface->get_path        = gparts_customize_model_get_path;
    iface->get_value       = gparts_customize_model_get_value;
    iface->iter_next       = gparts_customize_model_iter_next;
    iface->iter_children   = gparts_customize_model_iter_children;
    iface->iter_has_child  = gparts_customize_model_iter_has_child;
    iface->iter_n_children = gparts_customize_model_iter_n_children;
    iface->iter_nth_child  = gparts_customize_model_iter_nth_child;
    iface->iter_parent     = gparts_customize_model_iter_parent;
}

