##
##
## configure.ac for libusbwall in /home/phil/Travail/ECE/usbwall/usbwall-lib
##
## Made by Philippe THIERRY
## Login   <Philippe THIERRY@reseau-libre.net>
##
## Started on  jeu. 19 janv. 2012 20:57:40 CET Philippe THIERRY
## Last update ven. 20 janv. 2012 14:27:36 CET Philippe THIERRY
##


#############################################################################
## Preambule
#############################################################################
AC_INIT([libusbwall], [0.1], [phil@reseau-libre.net], [Philippe THIERRY])
AM_INIT_AUTOMAKE([1.9.5 foreign dist-bzip2 no-dist-gzip foreign])
AC_CONFIG_SRCDIR([src/usbwall_init.c])
AM_CONFIG_HEADER(config.h)
AM_MAINTAINER_MODE

#############################################################################
## Init source language configuration
#############################################################################
AC_LANG([C])

AC_ISC_POSIX
AC_PROG_CC
AM_PROG_CC_STDC
AC_HEADER_STDC


#############################################################################
## Init static and shared lib support
#############################################################################
# support for static lib
AC_PROG_LIBTOOL

# FIXME : add shared lib support
AC_CONFIG_MACRO_DIR([m4])

#############################################################################
## Headers check
#############################################################################
AC_CHECK_HEADER([sys/types.h],,AC_MSG_ERROR([Cannot find sys/types.h ! Check your installation !]))
AC_CHECK_HEADER([ctype.h],,AC_MSG_ERROR([Cannot find ctype.h ! Check your installation !]))
AC_CHECK_HEADER([inttypes.h],,AC_MSG_ERROR([Cannot find inttypes.h ! Check your installation !]))
AC_CHECK_HEADER([errno.h],,AC_MSG_ERROR([Cannot find errno.h ! Check your installation !]))
AC_CHECK_HEADER([sys/stat.h],,AC_MSG_ERROR([Cannot find sys/stat.h ! Check your installation !]))
AC_CHECK_HEADER([fcntl.h],,AC_MSG_ERROR([Cannot find fcntl.h ! Check your installation !]))

#############################################################################
## Libraries check
#############################################################################

#======== pthread
#AC_CHECK_LIB([pthread], [pthread_create], [], [], [])

#======== math
#AC_CHECK_LIB([m], [pow], [], [], [])

#======== Libefence
AC_ARG_WITH(efence, [  --with-efence           Link with electric fence ])
if test "$with_efence" = "yes"
then
	AC_CHECK_LIB(efence, EF_ALIGNMENT, LIBS="${LIBS} -lefence", AC_MSG_ERROR(libefence not found))
        efence="yes";
        EFENCE=1;
else
	efence="no";
fi


#############################################################################
## Third part programs detection
#############################################################################

#======== Checking doxygen
AC_CHECK_PROG([DOXYGEN], [doxygen], [yes], [no])
if test $DOXYGEN = ":"; then
  AC_MSG_WARN([Unable to detect doxygen in your path. You will not be able \
  to generate 42sh developpement documentiation.], 2)
  doxygen="no";
else
  doxygen="yes";
fi

#======== Checking gprof
AC_CHECK_PROG([GPROF], [gprof], [yes], [no])
if test $GPROF = ":"; then
  AC_MSG_WARN([Unable to detect gprof in your path. You will not be able \
  to generate nfhcctl function calls profile.], 2)
  gprof="no";
else
  gprof="yes";
fi

#======== Checking gcov
AC_CHECK_PROG([GCOV], [gcov], [yes], [no])
if test $GCOV = ":"; then
  AC_MSG_WARN([Unable to detect gcov in your path. You will not be able \
  to generate nfhcctl tests coverage.], 2)
  gcov="no";
else
  gcov="yes";
fi

#======== Checking valgrind
AC_CHECK_PROG([VALGRIND], [valgrind], [yes], [no])
if test $VALGRIND = ":"; then
  AC_MSG_WARN([Unable to detect valgrind in your path. You will not be able \
  to generate dynamic memory usage in nfhcctl tests.], 2)
  valgrind="no";
else
  valgrind="yes";
fi

#############################################################################
## Supplementary options
#############################################################################
#======== debug chars
AC_ARG_WITH(debug, [  --with-debug            Activate -g option of gcc and delete -DNDEBUG macro])
if test "$with_debug" = "yes"
then
	debug="yes";
        CFLAGS="$CFLAGS -g";
        DEBUG="";
else
	debug="no";
        DEBUG="-DNDEBUG"
fi

#======== gprof output
AC_ARG_WITH(gprof, [  --with-gprof            Activate gprof profiling during compile])
if test "$with_gprof" = "yes"
then
	if test $gprof = "no"
        then
		gprof="no: Unable to find gprof binary !";
        else
        	CFLAGS="$CFLAGS -pg";
        	GPROF=1
        	gprof="yes"
        fi
else
	gprof="no";
fi

#======== gcov output
AC_ARG_WITH(gcov, [  --with-gcov             Activate gcov test coverage during compile])
if test "$with_gcov" = "yes"
then
	if test $gcov = "no"
        then
		gcov="no: Unable to find gcov binary !";
        else
        	CFLAGS="$CFLAGS -fprofile-arcs -ftest-coverage";
        	GCOV=1
        	gcov="yes"
        fi
else
	gcov="no";
fi


CFLAGS="$CFLAGS \
 -O2 -Wall -Wextra -W -Werror -Wtrigraphs -Wundef -Wswitch -Wunused \
 -Wimplicit -fno-common -Wcast-qual -Wcast-align -Wwrite-strings \
 -Wuninitialized -Winit-self -Wmissing-prototypes -Wpacked -Wnested-externs \
 -Waggregate-return -pedantic -Wshadow -O3 \
 $DEBUG -std=c99";

#############################################################################
## Environment variables activation
#############################################################################

AM_CONDITIONAL(EFENCE, test x$efence = xyes)
AM_CONDITIONAL(GCOV, test x$gcov = xyes)
AM_CONDITIONAL(GPROF, test x$gprof = xyes)

#############################################################################
## Makefile list and finish
#############################################################################

AC_CONFIG_FILES([
Makefile
doc/Makefile
src/Makefile
])

AC_OUTPUT

echo;
echo Configuration completed;
echo;
echo System detected................... `uname -s`;
echo Doxygen found..................... $doxygen;
echo valgrind found.................... $valgrind;
echo Libefence enabled................. $efence;
echo Debug enabled..................... $debug;
echo Gprof activated................... $gprof;
echo Gcov activated.................... $gcov;
echo;
echo Type make to compile;
echo;

