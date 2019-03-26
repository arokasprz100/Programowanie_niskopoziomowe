#include <iostream>
#include "overloads.h"

class Point {
public:
	Point(double x = 0.0, double y = 0.0) : 
		x(x), y(y) {}

private:
	double x, y;
};


int main() {
	// calling overloaded global new
	Point* examplePoint = new Point(2, 4);
	int * exampleValue = new int();

	// calling overloaded global delete
	delete examplePoint;
	delete exampleValue;

	// calling overloaded global new[]
	Point* pointArray = new Point[5];
	int * intArray = new int[10];

	// calling overloaded global delete[]
	delete[] pointArray;
	delete[] intArray;

	std::cout << std::endl;

	// Without Valgrind: 2 everywhere
	// With Valgrind: 0 everywhere
	std::cout << "Overloaded global new has been called " << newCounter << " times." << std::endl;
	std::cout << "Overloaded global delete has been called " << deleteCounter << " times." << std::endl;
	std::cout << "Overloaded global new[] has been called " << newArrayCounter << " times." << std::endl;
	std::cout << "Overloaded global delete[] has been called " << deleteArrayCounter << " times." << std::endl;
	std::cout << std::endl;

	return 0;
}