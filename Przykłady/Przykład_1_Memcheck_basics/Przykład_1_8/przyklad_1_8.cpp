
#include <iostream>

// #define ERROR

int main() {

	int size = -5;

	#ifdef ERROR
		int * tab = new int[size]; // tu nie ma problemu, bo rzuca wyjątek
	#endif

	int * tab2 = static_cast<int*>(malloc(size * sizeof(int)));

	free(tab2);

	return 0;
}