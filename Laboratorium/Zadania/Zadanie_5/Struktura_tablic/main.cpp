/**

Programowanie niskopoziomowe - laboratorium
Zadanie 5 - część 2

Druga część zadania polega na zmianie sposobu 
przechowywania danych - pozwoli to na osiągnięcie
lepszej optymalizacji naszego programu pod względem
użycia pamięci cache.

Należy przepisać oryginalny program zgodnie z podanymi
tu instrukcjami w taki sposób, by zamiast z tablicy
struktur korzystał on z jednej struktury tablic. Każda 
tablica w tej strukturze powinna odpowiadac zmiennej 
z oryginalnej struktury. 

Po wykonaniu poprawek proszę przeprowadzić analizę 
analogiczną do tej z pierwszej cześci zadania
i odpowiedzieć na pytanie, który program jest 
optymalniejszy i dlaczego.

**/

#include <iostream>
#include "BigClass.hpp"

constexpr int ARRAY_SIZE = 20000;

struct Points
{
	double* 	xCoordinates;
	// pozostałe tablice ...
	// UZUPEŁNIJ
};

int main() {

	// utworzenie i alokacja
	Points points;

	points.xCoordinates = new double[ARRAY_SIZE];
	// alokacja pozostałych tablic ...
	// UZUPEŁNIJ


	// inicjalizacja ... 

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		points.xCoordinates[i] = i;
	}

	// UZUPEŁNIJ

	// wykonanie obliczen
	std::cout << "Average coordinates: " << std::endl;
	double sumX = 0.0;
	double sumY = 0.0;
	double sumZ = 0.0;

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		sumX += points.xCoordinates[i];
	}
	
	// reszta obliczeń ... 
	// UZUPEŁNIJ

	std::cout << " - x: " << static_cast<double>(sumX/ARRAY_SIZE) << std::endl;
	std::cout << " - y: " << static_cast<double>(sumY/ARRAY_SIZE) << std::endl;
	std::cout << " - z: " << static_cast<double>(sumZ/ARRAY_SIZE) << std::endl;
}