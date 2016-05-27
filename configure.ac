dnl Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([glinegraph-cairo-lib], [0.5.0], [James Scott Jr. skoona@gmail.com], 
        [glinegraph-cairo-lib], [https://github.com/skoona/glinegraph-cairo])

# Put autotools auxiliary files in subdirectories to reduce clutter:
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([foreign])
AM_SILENT_RULES([yes])
AM_MAINTAINER_MODE([enable])

dnl Standard C constructs
AC_GNU_SOURCE
AC_PROG_CC
AC_HEADER_STDC
AC_ISC_POSIX
AC_ENABLE_SHARED
AC_DISABLE_STATIC
AM_PROG_LIBTOOL
AC_PROG_INSTALL
LT_INIT

dnl stricter options -ansi -pedantic
CFLAGS='-g -O2 -Wall -Wextra -Wno-missing-field-initializers -Wno-unused-parameter -Winline -pipe -I/usr/local/include '
AC_SUBST(CFLAGS)


AC_ENABLE_SHARED
AC_DISABLE_STATIC
AM_PROG_LIBTOOL
AC_PROG_INSTALL
LT_INIT

dnl
dnl Gtk API Document Generator
GTK_DOC_CHECK([1.14],[--copy --flavour no-tmpl])

dnl
dnl Check for Gtk+ Libraries
dnl
PKG_CHECK_MODULES(GTK, [[gtk+-3.0 >= 3.10] [glib-2.0 >= 2.40 ]], 
    AC_MSG_RESULT(found), 
    AC_MSG_ERROR([AC_PACKAGE_NAME AC_PACKAGE_VERSION needs GTK3 and GLIB2]) 
)

dnl
dnl put constant on command line and not in a config.h file
dnl AC_CONFIG_HEADER(config.h)

AC_CONFIG_SRCDIR(src/lgcairo.c)
AC_CONFIG_FILES([Makefile src/Makefile docs/reference/Makefile])

AC_OUTPUT
