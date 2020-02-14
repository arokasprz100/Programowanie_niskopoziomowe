#include <iostream>

int main() {

	constexpr unsigned tabSize = 10;

	int * tab = new int[tabSize];

	for (unsigned i = 0; i < tabSize; ++i) {
		tab[i] = i + 10;
	}

	free(tab);

	return 0;
}

/*
Ciekawostka: powodem tego obostrzenia jest fakt, iz kompilatory sa zaimplementowane w ten sposob, 
ze przechowuja wielkosc tablicy zaalokowanej za pomocą new[] oraz wskaznik do destruktora elementu 
przechowywanego w tej tablicy tuz przed rzeczywiscie zwroconym wskaznikiem na tablice. delete tak 
nie dziala, co przy pomieszaniu obu operatorów moze prowadzic do problemów ze stertą. 
*/