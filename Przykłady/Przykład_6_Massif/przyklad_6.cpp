#include <iostream>

int SIZE = 1000;

int main() {

	int* tab[10];

	for (int i = 0; i < 10; ++i) {
		tab[i] = (int*) malloc(SIZE * sizeof(int));
		SIZE += 1000;
	}

	for (int i = 9; i >=0; --i) {
		free(tab[i]);
	}

	return 0;
}