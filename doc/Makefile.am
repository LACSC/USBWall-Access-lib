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
	doxygen $(srcdir)/Doxyfile

clean-local:
	rm -rf latex html usermanual/latex
	$(MAKE) -C usermanual clean

usermanual:
	$(shell if [ $(srcdir) != $(builddir) ]; then rm -rf $(builddir)/usermanual; cp -ru $(srcdir)/usermanual $(builddir); fi;)
	VERSION=$(VERSION) SRCDIR=$(srcdir) BUILDDIR=$(builddir) $(MAKE) -C $(builddir)/usermanual
	(cp $(builddir)/usermanual/libusbwall*.pdf $(builddir))

.PHONY: usermanual

EXTRA_DIST = $(srcdir)/Doxyfile $(srcdir)/usermanual/manual.tex.in $(srcdir)usermanual/Doxyfile $(srcdir)/usermanual/Makefile $(srcdir)/usermanual/titlepage.sty $(srcdir)/usermanual/pictures/ECE_LOGO_FR.png $(srcdir)/usermanual/pictures/usbwall_block_diagram.tex  

CLEANFILES = *~ .*.swp .*.swo output* *.gcov *.gprof
