AC_INIT([gparts],[0.0])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CC

AC_PROG_CC_C_O
AM_PROG_LIBTOOL

##  Checking for programs

AC_PATH_PROG([DOXYGEN], 'doxygen')
if test $DOXYGEN; then :; else
    AC_MSG_WARN([Unable to locate doxygen.  Documentation will not be created.])
fi

AC_PATH_PROG([PKG_CONFIG],'pkg-config')
if test $PKG_CONFIG; then :; else
    AC_MSG_ERROR([Unable to locate pkg-config.  Make sure pkg-config is installed and in the path.])
fi

##  GIO
##
GIO_VERSION=`$PKG_CONFIG gio-2.0 --modversion`
GIO_CFLAGS=`$PKG_CONFIG gio-2.0 --cflags`
GIO_LIBS=`$PKG_CONFIG gio-2.0 --libs`
AC_SUBST(GIO_CFLAGS)
AC_SUBST(GIO_LIBS)


##  GLIB
##
##  GTK's CFLAGS and LIBS includes GLib's, so including them is redundant.
##
GLIB_VERSION=`$PKG_CONFIG glib-2.0 --modversion`
GLIB_CFLAGS=`$PKG_CONFIG glib-2.0 --cflags`
GLIB_LIBS=`$PKG_CONFIG glib-2.0 --libs`
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)

##  GModule
##
##  GModule is needed to dynamically load database interfaces.
##
GMODULE_VERSION=`$PKG_CONFIG gmodule-2.0 --modversion`
GMODULE_CFLAGS=`$PKG_CONFIG gmodule-2.0 --cflags`
GMODULE_LIBS=`$PKG_CONFIG gmodule-2.0 --libs`
AC_SUBST(GMODULE_CFLAGS)
AC_SUBST(GMODULE_LIBS)

##  GTK
##
GTK_VERSION=`$PKG_CONFIG gtk+-2.0 --modversion`
GTK_CFLAGS=`$PKG_CONFIG gtk+-2.0 --cflags`
GTK_LIBS=`$PKG_CONFIG gtk+-2.0 --libs`
AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

##  Guile
##
AX_CHECK_GUILE([1.8.0])

AC_PATH_PROG([GUILE_SNARF], [guile-snarf], [notfound])
if test "X$GUILE_SNARF" = "Xnotfound" ; then
	AC_MSG_ERROR([Unable to locate guile-snarf.  Make sure guile is installed and guile-snarf is in the path])
fi

##  MySQL
##
##  Building the interface library for MySQL is optional.
##
AC_PATH_PROG([MYSQL_CONFIG],'mysql_config')
if test $MYSQL_CONFIG; then
    MYSQL_VERSION=`$MYSQL_CONFIG --version`
    MYSQL_CFLAGS=`$MYSQL_CONFIG --cflags`
    MYSQL_LIBS=`$MYSQL_CONFIG --libs`
    MYSQL_LDADD='libgparts-mysql.la'
else
    AC_MSG_WARN([Unable to locate mysql_config.  Make sure MySQL development libraries are installed and mysql_config is in the path.])
fi
AC_SUBST(MYSQL_CFLAGS)
AC_SUBST(MYSQL_LIBS)
AC_SUBST(MYSQL_LDADD)

##  PostgreSQL
##
##  Building the interface library for PostgreSQL is optional.
##
AC_PATH_PROG([POSTGRESQL_CONFIG],'pg_config')
if test $POSTGRESQL_CONFIG; then
    POSTGRESQL_VERSION=`$POSTGRESQL_CONFIG --version`
    POSTGRESQL_CFLAGS=`$POSTGRESQL_CONFIG --cflags`
    POSTGRESQL_LIBS=`$POSTGRESQL_CONFIG --libs`
#    PG_LDADD='libgparts-postgresql.la'
else
    AC_MSG_WARN([Unable to locate pg_config.  Make sure PostgreSQL development libraries are installed and pg_config is in the path.])
fi
AC_SUBST(POSTGRESQL_CFLAGS)
AC_SUBST(POSTGRESQL_LIBS)
AC_SUBST(POSTGRESQL_LDADD)

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
    Makefile
    src/Makefile
    ])
AC_OUTPUT

AC_MSG_RESULT([
****************** SUMMARY FOR gparts CONFIGURATION ******************

    GIO
        Installed Version        $GIO_VERSION

    GLib
        Installed Version        $GLIB_VERSION

    GModule
        Installed Version        $GMODULE_VERSION

    GTK
        Installed Version        $GTK_VERSION

    Guile
        Installed Version        $GUILE_VERSION

    MySQL
        Installed Version        $MYSQL_VERSION

    PostgreSQL
        Installed Version        $POSTGRESQL_VERSION
])
