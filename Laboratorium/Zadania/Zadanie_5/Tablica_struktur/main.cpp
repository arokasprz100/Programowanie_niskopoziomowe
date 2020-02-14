/**

Programowanie niskopoziomowe - laboratorium
Zadanie 5
Zadanie ma na celu naukę korzystania z narzędzia
Cachegrind, a dokładniej - naukę interpretacji 
zwracanych przez nie wyników.

Poniższy fragment kodu napisanego w C++ jest 
nieoptymalny ze względu na korzystanie z pamięci
Cache - występuje w nim wiele tzw. cache miss. 
Są to sytuacje, gdy procesor musi pobrać dane
z pamięci RAM, gdyż nie znajdują się one w cache.

Zadanie polega na wykonaniu analizy poniższego
programu za pomocą narzędzia Cachegrind oraz 
zmodyfikowaniu go, by polepszyć jego wydajność
w korzystaniu z pamieci cache.

Pierwszym krokiem jest kompilacja programu za pomocą
dołączonego pliku makefile. Następnie należy użyć 
Cachegrinda do przeprowadzenia analizy:

valgrind --tool=cachegrind <program>

Proszę wstępnie przeanalizować wyniki otrzymane na ekranie.
Następnie proszę wyświetlić wyniki analizy w postaci
szczegółowej:

cg_annotate --auto=yes <plik_wygenerowany_przez_cachegrind>

Proszę przeanalizować wyjście i zwrócić uwage, które linie
programu najmocniej wpływają na wydajność. 

Następnie proszę przejść do pliku main w katalogu 
"Struktura_tablic" i wykonać polecenia tam zawarte. 

**/

#include <iostream>
#include "BigClass.hpp"

constexpr int ARRAY_SIZE = 20000;

struct Point3D
{
	double 		x;
	double 		y;
	double 		z;
	BigClass	additionalData;
};

int main() {

	// utworzenie tablicy
	Point3D* points = new Point3D[ARRAY_SIZE];

	// inicjalizacja
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		points[i].x = i;
		points[i].y = i;
		points[i].z = i;
	}

	// wykonanie obliczen
	std::cout << "Average coordinates: " << std::endl;
	double sumX = 0.0;
	double sumY = 0.0;
	double sumZ = 0.0;
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		sumX += points[i].x;
		sumY += points[i].y;
		sumZ += points[i].z;
	}
	std::cout << " - x: " << static_cast<double>(sumX/ARRAY_SIZE) << std::endl;
	std::cout << " - y: " << static_cast<double>(sumY/ARRAY_SIZE) << std::endl;
	std::cout << " - z: " << static_cast<double>(sumZ/ARRAY_SIZE) << std::endl;



}