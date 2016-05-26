# $Id: Makefile.am,v 1.34 2007/07/21 13:15:06 jscott Exp $
#
## 	glinegraph toplevel makefile.am

ACLOCAL_AMFLAGS = -I m4

SUBDIRS = src docs/reference

sysconfdir = /etc
datadir = $(prefix)/share
  						
glinegraph_cairodocdir = $(datadir)/doc/glinegraph-cairo
glinegraph_cairodoc_DATA =	README.md \
						COPYING \
						AUTHORS \
						INSTALL \
						NEWS \
						ChangeLog \
						src/glg_cairo.png \
						autogen.sh
						
EXTRA_DIST = 	$(glinegraph_cairodoc_DATA) 

DISTCHECK_CONFIGURE_FLAGS=--enable-gtk-doc

clean-local:
	rm -vf ./*~ 

# Copy all the spec files. Of cource, only one is actually used.
dist-hook:
	for specfile in *.spec; do \
		if test -f $$specfile; then \
			cp -p $$specfile $(distdir); \
		fi \
	done

