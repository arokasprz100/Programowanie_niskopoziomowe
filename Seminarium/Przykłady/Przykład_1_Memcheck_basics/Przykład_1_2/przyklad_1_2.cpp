/**
 * Arkadiusz Kasprzak
 * Programowanie niskopoziomowe.
 * Narzędzia do debugowania.
 * Przykład 1.2: Valgrind: Memcheck - użycie niezainicjalizowanych zmiennych
 * Przykład obrazujący kolejny podstawowy błąd, jaki może zostać
 * wykryty za pomocą Memchecka. 
 *
 * Uruchomienie przykładu:
 * make 
 * valgrind --leak-check=full ./przyklad_1_2
 */

#include <iostream> // std::cout, std::endl

class InvalidPoint {
public:
	int x;
	int y;
};

int main() {

	InvalidPoint testPoint;
	testPoint.x = 5;

	int invalidY = testPoint.y; 

	// UWAGA: na tym etapie nie ma jeszcze żadnych błędów w Memchecku.
	// W programie można kopiować niezainicjalizowane dane bez ograniczeń 
	// i nie będzie to skutkowało blędem w Memchecku. Dopiero gdy program
	// spróbuje skorzystać z niezainicjalizowanej wartości w taki sposób,
	// że może to wpłynąć na jego zachowanie, np. na output, to pojawi się
	// błąd. 

	if (invalidY == 0) {
		std::cout << "Współrzędna Y równa 0." << std::endl;
	}

}