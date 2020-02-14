#include "valgrind/memcheck.h"
#include <iostream>

int main() {

	bool isRunningOnValgrind = RUNNING_ON_VALGRIND;

	int a; // niezainicjalizowana zmienna

	// VALGRIND_CHECK_VALUE_IS_DEFINED - sprawdza czy Memcheck
	// uważa podaną wartość (lvalue) za niezainicjalizowaną. 
	// Wypisuje wiadomość z błędem jeśli tak. Nie zwraca nic. 
	VALGRIND_CHECK_VALUE_IS_DEFINED(a);

	// VALGRIND_DO_LEAK_CHECK - wykonuje pełne sprawdzenie 
	// obecności wycieków pamięci w tym momencie. Użyteczne,
	// możemy sprawdzać co pewien czas, co może być pomocne
	// w określeniu, gdzie pojawia się wyciek. 
	VALGRIND_DO_LEAK_CHECK;

	std::cout << "Here" << std::endl;

	int * toBeLost = new int();
	toBeLost = nullptr;

	std::cout << "Leak check after making mistake" << std::endl;
	VALGRIND_DO_LEAK_CHECK;

	return 0;
}