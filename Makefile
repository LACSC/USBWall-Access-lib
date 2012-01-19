#
# File Makefile for project libusbwall
#
# Made by Philippe THIERRY
# Login   <phil@reseau-libre.net>
#
# Started on  jeu. 19 janv. 2012 20:48:57 CET Philippe THIERRY
# Last update jeu. 19 janv. 2012 20:48:57 CET Philippe THIERRY
#
# Copyright (C) 2009 - Philippe THIERRY
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#
#*
# \file Makefile
#
# Brief documentation on one line
# Detailed documentation
# On multiple lines...
#
# \author Philippe THIERRY
#
# \requirements
# This header is compliant of the following requirements :
# REQ_CODE_QUALITY_130
# REQ_CODE_QUALITY_140
# REQ_CODE_QUALITY_150
#

#############################################################################
## basic macros
#############################################################################
CC          ?= gcc
AR	     = ar
CFLAGS      ?= -Wall -W -Werror -ansi -pedantic
LD           = ld
LDFLAGS	     =
ARFLAGS	     = cr
RM	     = rm
RMFLAGS      = -rf
TAR          = tar
TARFLAGS     = -cjvf
MAKE        ?= make
INSTALL      = install
CTAGS        = ctags -x > tags
DEPEND       = makedepend $(CFLAGS)

#############################################################################
## lint -- static code mistakes detector
#############################################################################
LINT         = splint
LARCH_PATH   = /usr/local/lib
LCLIMPORTDIR = /usr/local/share/splint/imports

#############################################################################
## dist target file
#############################################################################
DISTTARGET   = ../libusbwall.tar.bz2

#############################################################################
## project's source and generated files
#############################################################################
TODEL	     = tags *~ .*.swp

#############################################################################
## rules
#############################################################################

all :
	$(MAKE) -C src all

.PHONY: clean

clean : 
	$(MAKE) -C src clean
	$(MAKE) -C doc clean
	$(RM) $(RMFLAGS) $(OBJS) $(TODEL)

distclean : clean
	$(MAKE) -C src distclean
	$(MAKE) -C doc distclean

dist : distclean
	$(TAR) $(TARFLAGS) $(DISTTARGET) .

check : $(TARGET)
	cd check; $(MAKE) all

install : $(TARGET)
	@echo you must be root to install

