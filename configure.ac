AC_INIT([libosmo-asn1-tcap], 0.0.0, [openbsc-devel@lists.openbsc.org])

AM_INIT_AUTOMAKE([dist-bzip2 subdir-objects])

dnl kernel style compile messages
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

dnl checks for programs
AC_PROG_MAKE_SET
AC_PROG_CC
AC_PROG_INSTALL
LT_INIT
AC_PROG_LIBTOOL

AC_CONFIG_MACRO_DIR([m4])

ASN1C_SKELETON_PATH="/usr/share/asn1c"
ASN1C_BIN_PATH="/usr/bin/asn1c"
ASN_MODULE_CFLAGS="-DASN_DISABLE_XER_SUPPORT -DASN_DISABLE_JER_SUPPORT -DASN_DISABLE_OER_SUPPORT -DASN_DISABLE_UPER_SUPPORT -DASN_DISABLE_APER_SUPPORT"
AC_SUBST([ASN1C_SKELETON_PATH])
AC_SUBST([ASN1C_BIN_PATH])
AC_SUBST([ASN_MODULE_CFLAGS])


# The following test is taken from WebKit's webkit.m4
saved_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS -fvisibility=hidden "
AC_MSG_CHECKING([if ${CC} supports -fvisibility=hidden])
AC_COMPILE_IFELSE([char foo;],
      [ AC_MSG_RESULT([yes])
        SYMBOL_VISIBILITY="-fvisibility=hidden"],
        AC_MSG_RESULT([no]))
CFLAGS="$saved_CFLAGS"
AC_SUBST(SYMBOL_VISIBILITY)

AC_ARG_ENABLE(sanitize,
	[AS_HELP_STRING(
		[--enable-sanitize],
		[Compile with address sanitizer enabled],
	)],
	[sanitize=$enableval], [sanitize="no"])
if test x"$sanitize" = x"yes"
then
	CFLAGS="$CFLAGS -fsanitize=address -fsanitize=undefined"
	CPPFLAGS="$CPPFLAGS -fsanitize=address -fsanitize=undefined"
fi

AC_ARG_ENABLE(werror,
	[AS_HELP_STRING(
		[--enable-werror],
		[Turn all compiler warnings into errors]
	)],
	[werror=$enableval], [werror="no"])
if test x"$werror" = x"yes"
then
	WERROR_FLAGS="-Werror"
	WERROR_FLAGS+=" -Werror=implicit-int -Werror=int-conversion -Werror=old-style-definition"
	CFLAGS="$CFLAGS $WERROR_FLAGS"
	CPPFLAGS="$CPPFLAGS $WERROR_FLAGS"
fi

AC_OUTPUT(
        libosmo-asn1-tcap.pc
        src/Makefile
        include/Makefile
        include/osmocom/Makefile
        include/osmocom/tcap/Makefile
        Makefile)
