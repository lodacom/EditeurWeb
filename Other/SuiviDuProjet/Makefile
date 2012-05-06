# Fichier principal.
latexfile = rapportProjet

# Compilateur.
TEX = xelatex


$(latexfile).pdf : $(latexfile).tex
	xelatex --shell-escape $(latexfile).tex
	makeglossaries $(latexfile).glo
	xelatex --shell-escape $(latexfile).tex
	xelatex --shell-escape $(latexfile).tex

clean:
	rm  -f *.glo *.xdy *.pyg *.aux *.glg *.gls *.lof *.toc *.ist $(latexfile).pdf

look:
	open $(latexfile).pdf