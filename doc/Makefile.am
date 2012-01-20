##
## Makefile.am for libusbwall in /home/phil/Travail/ECE/usbwall/usbwall-lib/doc
##
## Made by Philippe THIERRY
## Login   <Philippe THIERRY@reseau-libre.net>
##
## Started on  jeu. 19 janv. 2012 21:03:54 CET Philippe THIERRY
## Last update jeu. 19 janv. 2012 21:03:54 CET Philippe THIERRY
##

SUBDIRS =  .

all: doc-am usermanual

doc-am:
	doxygen Doxyfile

usermanual:
	VERSION=$(VERSION) $(MAKE) -C usermanual

.PHONY: usermanual

EXTRA_DIST = 

CLEANFILES = *~ .*.swp .*.swo output* *.gcov *.gprof

