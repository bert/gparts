#
#
#

bin_PROGRAMS = gparts
gparts_SOURCES = \
	gparts-category-model.c \
	gparts-category-controller.c \
	gparts-controller.c \
	gparts-customize-ctrl.c \
	gparts-customize-model.c \
	gparts-database.c \
	gparts-database-result.c \
	gparts-database-type.c \
	gparts-login-ctrl.c \
	gparts-main.c \
	gparts-object-list.c \
	gparts-preview.c \
	gparts-preview-ctrl.c \
	gparts-result-model.c \
	gparts-result-controller.c \
	gparts-result-view.c \
	gparts-state.c \
	gparts-units.c
gparts_CFLAGS = $(AM_CFLAGS) $(GMODULE_CFLAGS) $(GTK_CFLAGS)
gparts_LDADD = $(GMODULE_LIBS) $(GTK_LIBS)
#gparts_DEPENDENCIES = $(MYSQL_LDADD) $(POSTGRESQL_LDADD) $(SQLITE_LDADD)

# TODO libraries in EXTRA_LTLIBRARIES do not seem to work with g_module_open (no .so?)
# Libraries in lib_LTLIBRARIES must be built.  If conditionally not there, then the
# tool complains about the *_SOURCES, etc...
# The database support modules must be both dynamically loadable and conditionally
# build.

lib_LTLIBRARIES = \
	libgparts-mysql.la

EXTRA_LTLIBRARIES = \
	libgparts-postgresql.la \
	libgparts-sqlite.la

# A dynamically loadable library providing MySQL support.

libgparts_mysql_la_SOURCES = \
	gparts-mysql-database.c \
	gparts-mysql-module.c \
	gparts-mysql-result.c
libgparts_mysql_la_CFLAGS = $(AM_CFLAGS) $(GLIB_CFLAGS) $(MYSQL_CFLAGS)
libgparts_mysql_la_LIBADD = $(MYSQL_LIBS)

# A dynamically loadable library providing PostgreSQL support.

libgparts_postgresql_la_SOURCES = \
	gparts-postgresql-database.c \
	gparts-postgresql-module.c \
	gparts-postgresql-result.c
libgparts_postgresql_la_CFLAGS = $(AM_CFLAGS) $(GLIB_CFLAGS) $(POSTGRESQL_CFLAGS)
libgparts_postgresql_la_LIBADD = $(POSTGRESQL_LIBS)

# A dynamically loadable library providing SQLite support.

libgparts_sqlite_la_SOURCES = \
	gparts-sqlite-database.c \
	gparts-sqlite-module.c \
	gparts-sqlite-result.c
libgparts_sqlite_la_CFLAGS = $(AM_CFLAGS) $(GLIB_CFLAGS) $(SQLITE_CFLAGS)
libgparts_sqlite_la_LIBADD = $(SQLITE_LIBS)

MOSTLYCLEANFILES = core *~
CLEANFILES = core *~
DISTCLEANFILES = core *~
MAINTAINERCLEANFILES = core *~ Makefile.in

