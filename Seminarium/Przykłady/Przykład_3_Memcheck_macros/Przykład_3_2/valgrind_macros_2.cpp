#include "valgrind/valgrind.h"
#include <iostream>

void thirdLayer() {
	VALGRIND_PRINTF_BACKTRACE("Where are we? ");
}

void secondLayer() {
	thirdLayer();
}

void firstLayer() {
	secondLayer();
}

int main() {

	std::cout << std::endl;

	// VALGRIND_PRINTF_BACKTRACE macro - wypisuje natychmiast
	// stack trace - czyli listę funkcji prowadzacych do aktualnej
	VALGRIND_PRINTF_BACKTRACE("foo");

	std::cout << std::endl;

	// Lepszy przykład na stack trace
	firstLayer();

	std::cout << std::endl;


	const char* message = "Some message";

	// VALGRIND_PRINTF macro - działa podobnie do printf z języka C, 
	// z tym że wypisuje wiadomość tylko gdy uruchamiamy program 
	// za pomocą Valgrinda. Wiadomość trafia do logu. Zwraca ilość 
	// wypisanych znaków.
	VALGRIND_PRINTF("%s", message);

	// co ciekawe, makro to nie zadziala dopoki nie napotka znaku nowej
	// linii, co mozna zaobserwowac po odkomentowaniu ponizszej linii
	// VALGRIND_PRINTF("%s", message);
	std::cout << std::endl;

	return 0;
}