AUTOMAKE_OPTIONS = foreign dist-bzip2 1.6
ACLOCAL_AMFLAGS = -I m4

BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

INCLUDES = $(all_includes) -I$(top_srcdir)/include/osmocom/tcap
SUBDIRS = src tests include

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libosmo-asn1-tcap.pc

EXTRA_DIST = \
	     .version \
	     debian \
	     git-version-gen \
	     $(NULL)
