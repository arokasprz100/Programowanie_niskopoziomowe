#include <iostream>

// valgrind --gen-suppressions=yes  ./a.out
// valgrind -v --suppressions=exampleSupp.supp ./a.out

void fun() {

	int y;
	if (y == 0) {
		y = 1;
	}
}

int main() {

	int * x = new int[5];
	x[5] = 5;

	if (x[0] == 5) {
		x[2] = 3;
	}

	fun();

	return 0;
}