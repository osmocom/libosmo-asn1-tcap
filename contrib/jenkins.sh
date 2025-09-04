#!/bin/sh -ex

base="$PWD"
deps="$base/deps"
inst="$deps/install"
export deps inst

osmo-clean-workspace.sh

mkdir -p "$deps"

verify_value_string_arrays_are_terminated.py $(find . -name "*.[hc]")

export PKG_CONFIG_PATH="$inst/lib/pkgconfig:$PKG_CONFIG_PATH"
export LD_LIBRARY_PATH="$inst/lib"
export PATH="$inst/bin:$PATH"

osmo-build-dep.sh libasn1c

set +x
echo
echo
echo
echo " ========================== libosmo-asn1-tcap =========================="
echo
set -x

autoreconf -fi
./configure --enable-sanitize --enable-werror
$MAKE $PARALLEL_MAKE
$MAKE $PARALLEL_MAKE distcheck

osmo-clean-workspace.sh
