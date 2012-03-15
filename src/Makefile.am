#
#
#

# we have a bit of a "chicken and egg" problem.  scmcfg-config.c includes
# scmcfg-config.x and so guile-snarf will fail to run and create scmcfg-config.x
# The solution is to ensure that there is at least some file there so if
# the .x file doesn't exist, then create a dummy one.
SUFFIXES = .x
.c.x:
	test -f $@ || touch $@
	$(GUILE_SNARF) -o $@ $< $(AM_CFLAGS) $(GLIB_CFLAGS) $(GTK_CFLAGS) -I.

BUILT_SOURCES = \
	scmcfg-config.x

bin_PROGRAMS = \
	gformtest \
	gparts \
	gsymview

pkgdata_DATA = \
	system-gpartsrc

xmldir = $(pkgdatadir)/xml
xml_DATA = \
	gparts.xml \
	gparts-ui.xml \
	gsymview.xml

# Would like to move common files into a library, but the dynamically loadable
# modules have problems with backlinking? or symbols?

gparts_SOURCES = \
	gparts-category-model.c \
	gparts-category-controller.c \
	gparts-connect-controller.c \
	gparts-controller.c \
	gparts-customize-ctrl.c \
	gparts-customize-model.c \
	gparts-main.c \
	gparts-object-list.c \
	gparts-preview.c \
	gparts-preview-ctrl.c \
	gparts-result-model.c \
	gparts-result-controller.c \
	gparts-result-view.c \
	gparts-state.c \
	gparts-column-data.c \
	gparts-config.c \
	gparts-connect-data.c \
	gparts-database.c \
	gparts-database-factory.c \
	gparts-database-result.c \
	gparts-database-type.c \
	gparts-units.c \
	gpartsui-company-controller.c \
	gpartsui-company-model.c \
	gpartsui-connect-controller.c \
	gpartsui-connect-model.c \
	gpartsui-database-controller.c \
	gpartsui-database-model.c \
	gpartsui-document-controller.c \
	gpartsui-document-model.c \
	gpartsui-result-adapter.c \
	gpartsui-result-controller.c \
	gpartsui-result-model.c \
	gpartsui-view-controller.c \
	miscui-action-controller.c \
	miscui-action-model.c
gparts_CFLAGS = $(AM_CFLAGS) $(GMODULE_CFLAGS) $(GTK_CFLAGS)
gparts_LDADD = $(GMODULE_LIBS) $(GTK_LIBS) -lefence libgeom.la libgpform.la libgpview.la libmisc.la libsch.la libschgui.la libscmcfg.la

#gparts_DEPENDENCIES = $(MYSQL_LDADD) $(POSTGRESQL_LDADD) $(SQLITE_LDADD)

# A small GUI program for testing the drawing loader and drawing view widget.
#
gsymview_SOURCES = \
	gsymview-main.c \
	gparts-column-data.c \
	gparts-config.c \
	gparts-connect-data.c \
	gparts-database.c \
	gparts-database-factory.c \
	gparts-database-result.c \
	gparts-database-type.c \
	gparts-units.c 
gsymview_CFLAGS = $(AM_CFLAGS) $(GTK_CFLAGS) -shared -rdynamic
gsymview_LDADD = $(GTK_LIBS) libgeom.la libmisc.la libsch.la libschgui.la libscmcfg.la

# A small GUI program for testing dialog boxes.
#
gformtest_SOURCES = \
	gformtest-main.c
gformtest_CFLAGS = $(AM_CFLAGS) $(GTK_CFLAGS) -shared -rdynamic $(LIBXML_CFLAGS)
gformtest_LDADD = $(GTK_LIBS) libmisc.la libgpform.la libgpdata.la



noinst_LTLIBRARIES = \
	libgeom.la \
	libgpdata.la \
	libgpform.la \
	libgpview.la \
	libmisc.la \
	libmiscgui.la \
	libsch.la \
	libschgui.la \
	libscmcfg.la

# TODO libraries in EXTRA_LTLIBRARIES do not seem to work with g_module_open (no .so?)
# Libraries in lib_LTLIBRARIES must be built.  If conditionally not there, then the
# tool complains about the *_SOURCES, etc...
# The database support modules must be both dynamically loadable and conditionally
# build.

lib_LTLIBRARIES = \
	$(MYSQL_LIB) \
	$(POSTGRESQL_LIB) \
	$(SQLITE_LIB)

EXTRA_LTLIBRARIES = \
	libgparts-mysql.la \
	libgparts-postgresql.la \
	libgparts-sqlite.la

#

#libgparts_la_SOURCES = \
#	gparts-column-data.c \
#	gparts-config.c \
#	gparts-connect-data.c \
#	gparts-database.c \
#	gparts-database-factory.c \
#	gparts-database-result.c \
#	gparts-database-type.c \
#	gparts-units.c 
#libgparts_la_CFLAGS = $(AM_CFLAGS) $(GLIB_CFLAGS)
#libgparts_la_LIBADD = 

# A dynamically loadable library providing MySQL support.

libgparts_mysql_la_SOURCES = \
	gparts-mysql-database.c \
	gparts-mysql-factory.c \
	gparts-mysql-module.c \
	gparts-mysql-result.c
libgparts_mysql_la_CFLAGS = $(AM_CFLAGS) $(GLIB_CFLAGS) $(MYSQL_CFLAGS)
libgparts_mysql_la_LIBADD = $(MYSQL_LIBS)
libgparts_mysql_la_LDFLAGS = -rpath '$(libdir)'

# A dynamically loadable library providing PostgreSQL support.

libgparts_postgresql_la_SOURCES = \
	gparts-postgresql-database.c \
	gparts-postgresql-module.c \
	gparts-postgresql-result.c
libgparts_postgresql_la_CFLAGS = $(AM_CFLAGS) $(GLIB_CFLAGS) $(POSTGRESQL_CFLAGS)
libgparts_postgresql_la_LIBADD = $(POSTGRESQL_LIBS)
libgparts_postgresql_la_LDFLAGS = -rpath '$(libdir)'

# A dynamically loadable library providing SQLite support.

libgparts_sqlite_la_SOURCES = \
	gparts-sqlite-database.c \
	gparts-sqlite-factory.c \
	gparts-sqlite-module.c \
	gparts-sqlite-result.c
libgparts_sqlite_la_CFLAGS = $(AM_CFLAGS) $(GLIB_CFLAGS) $(SQLITE_CFLAGS)
libgparts_sqlite_la_LIBADD = $(SQLITE_LIBS)
libgparts_sqlite_la_LDFLAGS = -rpath '$(libdir)'

MOSTLYCLEANFILES = core *~
CLEANFILES = core *~ scmcfg-config.x
DISTCLEANFILES = core *~
MAINTAINERCLEANFILES = core *~ Makefile.in

libsch_la_SOURCES = \
	sch-arc.c \
	sch-attributes.c \
	sch-box.c \
	sch-bus.c \
	sch-circle.c \
	sch-color.c \
	sch-config.c \
	sch-component.c \
	sch-drafter.c \
	sch-drawing.c \
	sch-factory.c \
	sch-file-format-2.c \
	sch-fill-style.c \
	sch-line.c \
	sch-line-style.c \
	sch-loader.c \
	sch-multiline.c \
	sch-net.c \
	sch-output-stream.c \
	sch-path.c \
	sch-path-command.c \
	sch-pin.c \
        sch-shape.c \
	sch-text.c
libsch_la_CFLAGS = -Wall $(AM_CFLAGS) $(GIO_CFLAGS) $(GLIB_CFLAGS)
libsch_la_LIBADD = $(GLIB_LIBS) libgeom.la libmisc.la

libschgui_la_SOURCES = \
	schgui-cairo-arc.c \
	schgui-cairo-box.c \
	schgui-cairo-bus.c \
	schgui-cairo-circle.c \
	schgui-cairo-drafter.c \
	schgui-cairo-draw-item.c \
	schgui-cairo-draw-list.c \
	schgui-cairo-factory.c \
	schgui-cairo-line.c \
	schgui-cairo-net.c \
	schgui-cairo-path.c \
	schgui-cairo-pin.c \
	schgui-cairo-text.c \
	schgui-clipboard.c \
	schgui-config.c \
	schgui-drawing-cfg.c \
	schgui-drawing-view.c
libschgui_la_CFLAGS = -Wall $(AM_CFLAGS) $(GTK_CFLAGS)
libschgui_la_LIBADD = $(GTK_LIBS) libsch.la libmiscgui.la

#
# This library contains boxed types for working with geometric shapes.
#
libgeom_la_SOURCES = \
	geom-angle.c \
	geom-arc.c \
	geom-bounds.c \
	geom-box.c \
	geom-circle.c \
	geom-line.c \
	geom-transform.c
libgeom_la_CFLAGS = -Wall $(AM_CFLAGS) $(GLIB_CFLAGS)
libgeom_la_LIBADD = $(GLIB_LIBS)

#
# This library contains code for data models
#
libgpdata_la_SOURCES = \
	gpdata-factory.c \
	gpdata-op-base.c \
	gpdata-op-buildable.c \
	gpdata-parser-stack.c \
	gpdata-tm-column.c \
	gpdata-tm-column-double.c \
	gpdata-tm-column-integer.c \
	gpdata-tm-column-text.c \
	gpdata-tm-column-units.c \
        gpdata-tm-table.c
libgpdata_la_CFLAGS = -Wall $(AM_CFLAGS) $(GLIB_CFLAGS) $(LIBXML_CFLAGS)
libgpdata_la_LIBADD = $(GLIB_LIBS) $(LIBXML_LIBS) libmisc.la


#
# This library contains UI elements for views.
#
libgpview_la_SOURCES = \
	gpview-company-ctrl.c \
	gpview-company-view.c \
	gpview-device-view.c \
	gpview-document-view.c \
	gpview-footprint-view.c \
	gpview-package-view.c \
	gpview-factory.c \
	gpview-result-adapter.c \
	gpview-symbol-view.c \
	gpview-view-interface.c
libgpview_la_CFLAGS = -Wall $(AM_CFLAGS) $(GTK_CFLAGS)
libgpview_la_LIBADD = $(GTK_LIBS) libmisc.la libgpform.la


#
# This library contains UI elements for data entry.
#
libgpform_la_SOURCES = \
	gpform-factory.c \
	gpform-pm-dialog.c \
	gpform-ui-combo.c \
	gpform-ui-dialog.c \
	gpform-ui-entry.c \
	gpform-ui-image.c \
	gpform-ui-label.c \
	gpform-ui-widget.c
libgpform_la_CFLAGS = -Wall $(AM_CFLAGS) $(GTK_CFLAGS)
libgpform_la_LIBADD = $(GTK_LIBS) libmisc.la

#
# This library contains miscellaneous funtionality that could
# be used by both command line and GUI applications.
#
libmisc_la_SOURCES = \
	misc-macro.c \
	misc-object.c
libmisc_la_CFLAGS = -Wall $(AM_CFLAGS) $(GLIB_CFLAGS)
libmisc_la_LIBADD = $(GLIB_LIBS)

#
# This library contains miscellaneous funtionality that would
# generally be used by GUI applications.
#
libmiscgui_la_SOURCES = \
	miscgui-color.c
libmiscgui_la_CFLAGS = -Wall $(AM_CFLAGS) $(GTK_CFLAGS)
libmiscgui_la_LIBADD = $(GTK_LIBS)

#
# This library contains functionality to configure all other modules from
# scheme configuration files.
#
libscmcfg_la_SOURCES = \
	scmcfg-config.c \
	scmcfg-dirs.c
libscmcfg_la_CFLAGS = -Wall -DDATADIR=\"$(datadir)\" $(AM_CFLAGS) $(GTK_CFLAGS) $(GUILE_CFLAGS)
libscmcfg_la_LIBADD = $(GTK_LIBS) $(GUILE_LIBS)

