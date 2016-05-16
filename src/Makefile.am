# $Id$ 
#
# 	lgcairo source level makefile.am for widget version

AM_CPPFLAGS = $(CFLAGS) $(RPM_OPT_FLAGS) 

bin_PROGRAMS = lgcairo

lgcairo_SOURCES = lgcairo.c glg_cairo.c glg_cairo.h
lgcairo_CFLAGS  = @CFLAGS@ @GTK_CFLAGS@
lgcairo_LDADD   = @GTK_LIBS@ -lm



clean-local:
	rm -vf ./*~ ./*.o ${bin_PROGRAMS}

