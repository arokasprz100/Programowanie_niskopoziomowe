/**

Programowanie niskopoziomowe - laboratorium
Zadanie 3
Poniższy program zawiera sporo błędów związanych
z zarządzaniem pamięcia. Celem jest napisanie pliku
z odpowiednimi filtrami (czyli tzw. suppression file)
w taki sposób, by Memcheck nie wyświetlał błędów
generowanych przez metody klasy ErrorMaker. 

Proszę nie modyfikować tego pliku.

**/

#include <iostream>     // std::cout

const int size = 10;
int x = 20;

class ErrorMaker {
public:
	static void makeError1() {
		int x;
		if (x) {
			x = 55;
		}
	}

	static void makeError2() {
		int * x = new int[size];
		for (int i = 0; i < size; ++i) {
			x[i] = i;
		}
		for (int i = 0; i < size; ++i) {
			std::cout << x[i] << " ";
		}
		std::cout << std::endl;
		delete x; 
	}
	
};

int main() {

	const int size = -1;

	ErrorMaker::makeError1();
	ErrorMaker::makeError2();

	int * tab = static_cast<int*>(malloc(size * sizeof(int)));

	return 0;
}
