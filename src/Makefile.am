##
## Makefile.am for libusbwall in /home/phil/Travail/ECE/usbwall/usbwall-lib/src
##
## Made by Philippe THIERRY
## Login   <Philippe THIERRY@reseau-libre.net>
##
## Started on  jeu. 19 janv. 2012 21:00:53 CET Philippe THIERRY
## Last update jeu. 19 janv. 2012 21:00:53 CET Philippe THIERRY
##

SUBDIRS = .

lib_LTLIBRARIES = libusbwall.la

AM_CFLAGS = $(CFLAGS)

# default installation dir
instdir = /usr/local/include

libusbwall_la_SOURCES = usbwall_init.c \
                     usbwall_keypass.c \
		     usbwall_infos.c

noinst_HEADERS = usbwall_init.h

inst_HEADERS = libusbwall.h

# options part
if EFENCE
libusbwall_la_LIBADD = $(EFENCEFLAGS)
endif
#

EXTRA_DIST = 

CLEANFILES = *~ .*.swp .*.swo output* *.gcov *.gprof

