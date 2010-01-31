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

/*! \file scmcfg-dirs.c
 */

#include <config.h>

#include <glib.h>
#include <glib-object.h>

#include "scmcfg-dirs.h"

char*
scmcfg_dirs_find_geda_config(void)
{
    char *ddir = g_getenv("GEDARCDIR");
    char *path = NULL;

    if (ddir != NULL)
    {
        if (g_file_test(ddir, G_FILE_TEST_IS_DIR))
        {
            path = g_strdup(ddir);
        }
    }

    if (path == NULL)
    {
        const char *const *temp = g_get_system_config_dirs();

        while (*temp != NULL)
        {
            path = g_build_filename(*temp, "gEDA", NULL);

            g_debug("Checking path %s", path);

            if (g_file_test(path, G_FILE_TEST_IS_DIR))
            {
                break;
            }

            g_free(path);
            path = NULL;

            temp++;
        }
    }

    if (path == NULL)
    {
        path = scmcfg_dirs_find_geda_data();
    }

    return path;
}

char*
scmcfg_dirs_find_geda_data(void)
{
    char *ddir = g_getenv("GEDADATADIR");
    char *path = NULL;

    if (ddir != NULL)
    {
        if (g_file_test(ddir, G_FILE_TEST_IS_DIR))
        {
            path = g_strdup(ddir);
        }
    }

    if (path == NULL)
    {
        const char *const *temp = g_get_system_data_dirs();

        while (*temp != NULL)
        {
            path = g_build_filename(*temp, "gEDA", NULL);

            g_debug("Checking path %s", path);

            if (g_file_test(path, G_FILE_TEST_IS_DIR))
            {
                break;
            }

            g_free(path);
            path = NULL;

            temp++;
        }
    }

    return path;
}

char*
scmcfg_dirs_find_gparts_data(void)
{
    char *ddir = g_getenv("GPARTSDATADIR");
    char *path = NULL;

    if (ddir != NULL)
    {
        if (g_file_test(ddir, G_FILE_TEST_IS_DIR))
        {
            path = g_strdup(ddir);
        }
    }

    if (path == NULL)
    {
        const char *const *temp = g_get_system_data_dirs();

        while (*temp != NULL)
        {
            path = g_build_filename(*temp, PACKAGE_NAME, NULL);

            g_debug("Checking path %s", path);

            if (g_file_test(path, G_FILE_TEST_IS_DIR))
            {
                break;
            }

            g_free(path);
            path = NULL;

            temp++;
        }
    }

    return path;
}

