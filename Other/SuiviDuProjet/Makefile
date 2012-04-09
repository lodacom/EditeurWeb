# Fichier principal.
latexfile = rapportProjet

# Compilateur.
TEX = xelatex


$(latexfile).pdf : $(latexfile).tex
	xelatex $(latexfile).tex
	makeglossaries $(latexfile).glo
	xelatex $(latexfile).tex
	xelatex $(latexfile).tex

clean:
	rm  -f *.glo *.xdy *.pyg *.aux *.glg *.gls *.lof *.toc *.ist

look:
	open $(latexfile).pdf