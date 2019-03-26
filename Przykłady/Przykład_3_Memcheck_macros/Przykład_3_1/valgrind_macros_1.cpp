#include "valgrind/valgrind.h"
#include <iostream>

int main() {

	// RUNNING_ON_VALGRIND macro - zwraca 1 jeśli program został
	// uruchomiony za pomocą Valgrinda. W przeciwnym razie zwraca
	// wartość 0.
	bool isRunningOnValgrind = RUNNING_ON_VALGRIND;
	std::cout <<  std::boolalpha << isRunningOnValgrind << std::endl;

	int numberOfErrors = 0;

	// VALGRIND_COUNT_ERRORS macro - zwraca liczbę znalezionych do tej 
	// pory błędów. Nie działa dla wszystkich narzędzi - działa np. dla
	// Memchecka, ale już np. dla Cachegrinda zawsze zwraca 0, ponieważ
	// Cachegrind nie wyszukuje błędów. 
	numberOfErrors = VALGRIND_COUNT_ERRORS;

	if (isRunningOnValgrind) {
		std::cout << "Number of found errors = " << numberOfErrors << std::endl;
	}

	int * toBeLost = new int();
	delete[] toBeLost; // błąd - nieprawidłowy operator zwalniający pamięć

	// powtórne sprawdzenie po błędzie - zwraca 1
	numberOfErrors = VALGRIND_COUNT_ERRORS;
	if (isRunningOnValgrind) {
		std::cout << "Number of found errors = " << numberOfErrors << std::endl;
	}

	


}