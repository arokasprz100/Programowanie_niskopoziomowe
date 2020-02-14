#include <iostream>

int main(int argc, char* argv[]) {

	int * exampleVec = static_cast<int*>(malloc(4 * sizeof(int)));


	if (argc == 2) {
		std::cout << "Invalid number of input params" << std::endl;
		exit(exampleVec[0]); // syscall
	}

	for (int i = 0; i < 4; ++i) {
		exampleVec[i] = i;
	}

	free(exampleVec);

}