#
# Makefile for textemplate in /cygdrive/z/Programs/msysgit/msysgit/home/phil/dev/latex_utils/doc
#
# Made by t0090690
# Login   <t0090690@fr.thalesgroup.com>
#
# Started on  Wed Nov 18 14:29:46 2009 t0090690
# Last update Wed Nov 18 14:29:46 2009 t0090690
#


#############################################################################
## basic macros
#############################################################################

LATEX=pdflatex
LATEXOPT=-shell-escape
BIBTEX=bibtex
PDFVIEWER?=acroread

DOXYGEN=doxygen
DOXYFILE=Doxyfile

VERSION ?= 0.0
SRCDIR ?= .
BUILDDIR ?= .

RM=rm
RMFLAGS=-rf
MAKE=make

#############################################################################
## project's source and generated files
#############################################################################
TARGET	     = libusbwall_usermanual-$(VERSION)
SOURCE	     = manual.tex
SOURCE_PREFIX= manual
OBJS	     = $(SOURCE:.tex=.aux) $(SOURCE:.tex=.log) $(SOURCE:.tex=.out) $(SOURCE:.tex=.toc) \
               $(SOURCE:.tex=.ist) $(SOURCE:.tex=.glo) $(SOURCE:.tex=.idx) $(SOURCE:.tex=.lof) $(SOURCE) \
               $(SOURCE:.tex=.brf) $(SOURCE:.tex=.bmt) $(SOURCE:.tex=.ind) $(SOURCE:.tex=.ilg) $(SOURCE:.tex=.maf) \
	       $(SOURCE:.tex=.lot) *.ps *.mlf* *.mlt* *.mtc* $(SOURCE_PREFIX)-fig*.tex *.log $(SOURCE_PREFIX)-fig*.pdf tmp.inputs
TODEL	     = tags *~ .*.swp doxygen.sty

#############################################################################
## rules
#############################################################################

all : pdf 

help :
	@echo "- all 		: this help message"
	@echo "- pdf		: compile the document"
	@echo "- view		: display the compiled document if present"
	@echo "- clean		: cleanup temporary files"
	@echo "- distclean 	: cleanup all files but sources"
	@echo "- install	: install the document"

images:
	if [ ! -d images ]; then mkdir images; fi; for file in *-fig*.ps; do convert -trim +repage $$file images/$${file%%.ps}.png; done

pdf : prepare
	$(LATEX) $(LATEXOPT) $(LATEXOPT) $(SOURCE)
#	$(BIBTEX) $(SOURCE_PREFIX)
	makeindex $(SOURCE:.tex=.idx)
	while [ `cat $(SOURCE:.tex=.log) | grep 'may have changed.' | wc -l` -ge 1 ]; do $(LATEX) $(LATEXOPT) $(LATEXOPT) $(SOURCE); done
	mv $(SOURCE:.tex=.pdf) $(TARGET).pdf

prepare:
	$(shell cat $(SOURCE).in | sed -re 's:@VERSION@:$(VERSION):' > $(SOURCE); \
  	  cat Doxyfile.in | sed -re 's:@SRCDIR@:$(SRCDIR)/usermanual:' > Doxyfile;)
	  (doxygen Doxyfile; cp latex/doxygen.sty .;)

clean : 
	$(RM) $(RMFLAGS) $(OBJS) $(TODEL)

distclean : clean
	$(RM) $(RMFLAGS) $(TARGET).pdf

view:
	if [ ! -f $(TARGET) ]; then make all; fi
	$(PDFVIEWER) $(TARGET).pdf
