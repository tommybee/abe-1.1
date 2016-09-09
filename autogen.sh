#!/bin/sh
#
aclocal
automake --foreign --copy -a
autoconf

# Run configure for this platform
#./configure $*
echo "Now you are ready to run ./configure"
