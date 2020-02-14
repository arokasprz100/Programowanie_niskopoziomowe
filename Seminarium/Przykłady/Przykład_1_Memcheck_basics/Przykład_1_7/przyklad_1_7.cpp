/**
 * Arkadiusz Kasprzak
 * Programowanie niskopoziomowe.
 * Narzędzia do debugowania.
 * Przykład 1.6: Valgrind: Memcheck - nakładanie przy kopiowaniu
 * Przykład obrazujący problem wynikający przy użyciu funkcji typu
 * memcpy, gdy obszary źródłowy i docelowy się nakładają
 *
 * Uruchomienie przykładu:
 * make 
 * valgrind --leak-check=full ./przyklad_1_6
 */

#include <iostream>
#include <cstring>

int main() {

	char * stringToBreak = new char[20];

	for (int i = 0; i < 20; ++i) {
		stringToBreak[i] = 'a' + i;
	}

	stringToBreak[19] = '\0';

	std::cout << stringToBreak << std::endl;

	strcpy(stringToBreak, stringToBreak + 5);

	delete [] stringToBreak;

}
