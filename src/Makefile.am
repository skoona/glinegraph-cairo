# 	lgcairo source level makefile.am for widget library version

ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = $(CFLAGS)

lib_LTLIBRARIES = libglinegraph.la
libglinegraph_la_SOURCES = glg_cairo.c glg_cairo.h
libglinegraph_la_CFLAGS  = @CFLAGS@ @GTK_CFLAGS@ -shared -fPIC
libglinegraph_la_LDFLAGS = -version-info 0:5:0 -shared -fPIC


bin_PROGRAMS = lgcairo
lgcairo_SOURCES = lgcairo.c glg_cairo.h
lgcairo_CFLAGS  = @CFLAGS@ @GTK_CFLAGS@
lgcairo_LDADD   = -L$(abs_builddir)/.libs/ @GTK_LIBS@ -lm libglinegraph.la


clean-local:
	rm -vf ./*~ ./*.o $(bin_PROGRAMS) $(lib_LTLIBRARIES)

