# Fichier principal.
latexfile = rapportPreliminaire

# Compilateur.
TEX = xelatex


$(latexfile).pdf : $(latexfile).tex
	while ($(TEX) $(latexfile) ; \
	grep -q "Rerun to get cross" $(latexfile).log ) do true ; \
	done

clean:
	rm *.glo *.xdy *.pyg *.aux

look:
	open $(latexfile).pdf