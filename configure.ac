dnl 	glinegraph-cairo toplevel configure.in
dnl     code level serial-0021-
AC_PREREQ([2.69])

AC_INIT([glinegraph-cairo], [0.4.0], [James Scott Jr. skoona@users.sourceforge.net], [glinegraph-cairo])

AM_INIT_AUTOMAKE([foreign])
AM_SILENT_RULES([yes])
AM_MAINTAINER_MODE

dnl Standard C constructs
AC_PROG_CC
AC_HEADER_STDC
AC_ISC_POSIX

dnl
dnl stricter options -ansi -pedantic
CFLAGS="-Wall -g -DGSEAL_ENABLE"
AC_SUBST(CFLAGS)
AC_SUBST(CPPFLAGS)
AC_SUBST(LDFLAGS)

dnl
dnl Gtk API Document Generator
GTK_DOC_CHECK(1.0)

dnl
dnl Check for Gtk+ Libraries
dnl
PKG_CHECK_MODULES(GTK, [gtk+-2.0 >= 2.24], AC_MSG_RESULT(found), AC_MSG_ERROR([AC_PACKAGE_NAME AC_PACKAGE_VERSION needs GTK]) )

dnl
dnl put constant on command line and not in a config.h file
dnl AC_CONFIG_HEADER(config.h) dnl

AC_PREFIX_DEFAULT(/usr/local)
AC_CONFIG_SRCDIR(src/lgcairo.c)

AC_CONFIG_FILES([Makefile src/Makefile docs/reference/Makefile])

AC_OUTPUT