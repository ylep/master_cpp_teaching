doc_tex = $(wildcard *.tex)
doc_pdf = $(doc_tex:.tex=.pdf)

all: $(doc_pdf) $(wildcard ../base/*.sty)

%.pdf: %.tex
	../../utils/filepp ../../base/BasePackage.sty.skeleton -o ../../base/BasePackage.sty
	xelatex $< || exit $$?
	xelatex $< || exit $$?

clean:
	for f in $(doc_tex) ; do \
	rm -f $(doc_tex:.tex=.ps) $(doc_tex:.tex=.pdf) $(doc_tex:.tex=.toc) \
	$(doc_tex:.tex=.aux) $(doc_tex:.tex=.log) $(doc_tex:.tex=.blg) \
	$(doc_tex:.tex=.out) $(doc_tex:.tex=.bbl) $(doc_tex:.tex=.fot) \
	$(doc_tex:.tex=.brf) $(doc_tex:.tex=.dvi) tmp.inputs; \
	done ; \
	rm -rf *.aux *~
