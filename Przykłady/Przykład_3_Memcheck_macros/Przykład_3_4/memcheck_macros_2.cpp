#include "valgrind/memcheck.h"
#include <iostream>

//#define ERROR_CHOICE

int main() {

	#ifdef ERROR_CHOICE

	int * pointerInt = new int[2];
	pointerInt[0] = 1;
	pointerInt[1] = 2;

	// VALGRIND_CHECK_MEM_IS_ADDRESSABLE - sprawdza, czy mamy dostęp
	// (odczyt/zapis) do danego obszaru pamięci - czyli w naszym
	// przypadku czy pamięć została zaalokowana
	unsigned long addressable 
		= VALGRIND_CHECK_MEM_IS_ADDRESSABLE(pointerInt, 2 * sizeof(int));

	std::cout << "Where are we now? __1__" << std::endl;

	double * pointerDouble;
	addressable = VALGRIND_CHECK_MEM_IS_ADDRESSABLE(pointerDouble, sizeof(double));

	delete [] pointerInt;

	#else

	std::cout << "Where are we now? __2__" << std::endl;

	int * secondPointer = (int*) malloc(2 * sizeof(int));

	// VALGRIND_CHECK_MEM_IS_DEFINED - sprawdza, czy wartości w pamięci
	// są zdefiniowana - czyli czy zostały zainicjalizowane
	VALGRIND_CHECK_MEM_IS_DEFINED(secondPointer, 2 * sizeof(int));

	// VALGRIND_MAKE_MEM_DEFINED - sprawia, że Memcheck widzi obszar
	// pamięci jako taki ze zdefiniowanymi danymi
	VALGRIND_MAKE_MEM_DEFINED(secondPointer, 2 * sizeof(int));

	VALGRIND_CHECK_MEM_IS_DEFINED(secondPointer, 2 * sizeof(int));

	free(secondPointer);

	#endif

	return 0;
}