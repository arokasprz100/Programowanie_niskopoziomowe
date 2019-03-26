Lista czynności:
make
valgrind --tool=cachegrind ./prog
cg_annotate --auto=yes cachegrind.out.<pid>

Analiza wyjścia z valgrinda:
	- wskazanie linii: warning: L3 cache found, using its data for the LL simulation.
	- najpierw instrukcje (I1, LLi), potem dane (D1, LLd)

Analiza cg_annotate:
	- analiza linia po linii