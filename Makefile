# -*- mode: makefile; -*-

EMACS=emacs

all: pdf html

clean::
	git clean -Xf  # remove files ignored by git


README_tangles = README.el \
  lecture-style.sty slide-style.sty org-preamble.sty \
  index.html doc/stylesheets/styles.css doc/stylesheets/org-pygments.css

.SECONDARY: $(README_tangles)
$(README_tangles): README.org
	$(EMACS) --batch \
	  --eval "(require 'org)" \
	  --eval "(org-babel-do-load-languages 'org-babel-load-languages '((sh . t)))" \
	  --eval "(setq org-confirm-babel-evaluate nil)" \
	  --eval "(org-babel-tangle-file \"$<\")"
clean::
	$(RM) $(README_tangles)


SUBDIRS = lectures td slides

lectures_org = $(wildcard lectures/*.org)
td_org = $(wildcard td/*.org)
slides_org = $(wildcard slides/*.org)

lectures_pdf = $(lectures_org:.org=.pdf)
td_pdf = $(td_org:.org=.pdf)
slides_pdf = $(slides_org:.org=.pdf)

files_pdf = $(lectures_pdf) $(td_pdf) $(slides_pdf)

pdf: $(files_pdf)

$(slides_pdf): %.pdf: %.org README.el
	@echo "NOTICE: Exporting $< to PDF..."
	TEXINPUTS=.:..: $(EMACS) --batch --load=$(lastword $^) \
	    --visit "$<" \
	    --funcall cpp-export-slides

$(lectures_pdf): %.pdf: %.org README.el
	@echo "NOTICE: Exporting $< to PDF..."
	TEXINPUTS=.:..: $(EMACS) --batch --load=$(lastword $^) \
	    --visit "$<" \
	    --funcall cpp-export-lectures

$(td_pdf): %.pdf: %.org README.el
	@echo "NOTICE: Exporting $< to PDF..."
	TEXINPUTS=.:..: $(EMACS) --batch --load=$(lastword $^) \
	    --visit "$<" \
	    --funcall cpp-export-classes


html: README.el
	@echo "NOTICE: Generating html documentation..."
	$(EMACS) --batch --load=$(lastword $^) \
	    --visit "README.org" --funcall org-publish-cpp
clean::
	$(RM) -r doc/

gh-pages: html
	find doc -name *~ -delete
	tar czvf /tmp/org-cpp-publish.tar.gz index.html doc
	git checkout gh-pages
	tar xzvf /tmp/org-cpp-publish.tar.gz
	[ -n "$(git status --porcelain)" ] && git commit -am "update doc" && git push
	git checkout master


.PHONY: all pdf html gh-pages clean
