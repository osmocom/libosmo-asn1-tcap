AM_CPPFLAGS = $(all_includes) -I$(top_srcdir)/include -I$(top_srcdir)/src
AM_CFLAGS = -Wall
AM_LDFLAGS = -no-install

LDADD = $(top_builddir)/src/libosmo-asn1-tcap.la

check_PROGRAMS = \
	tcap_parse_test \
	$(NULL)

EXTRA_DIST = \
	tcap_parse_test.ok \
	$(NULL)

tcap_parse_test_SOURCES = tcap_parse_test.c
