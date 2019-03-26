/**
 * Arkadiusz Kasprzak
 * Programowanie niskopoziomowe.
 * Narzędzia do debugowania.
 * Przykład 1.3: Valgrind: Memcheck - niepoprawne zwalnianie pamięci 
 *
 * Uruchomienie przykładu:
 * make 
 * valgrind --leak-check=full ./przyklad_1_3
 */

#include <cstdlib>
#include <iostream>

#define CORRECT
//#define MEM_ERROR_1
//#define MEM_ERROR_2

int main() {

	int tabSize = 5;

	int * tab = static_cast<int*>(malloc(tabSize * sizeof(int)));

	#ifdef MEM_ERROR_1
	free(tab);
	free(tab);
	#endif // MEM_ERROR_1

	#ifdef MEM_ERROR_2
	free(tab + 1); // ta opcja powoduje przerwanie wykonywania programu
	#endif // MEM_ERROR_2

	#ifdef CORRECT
	free(tab);
	#endif // CORRECT

	std::cout << "End of program." << std::endl;

	return 0;
}
