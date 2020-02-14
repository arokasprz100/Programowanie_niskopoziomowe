#include <iostream>

// Overloading global new operator
void* operator new(size_t sz)
{
  std::cout<< "Calling user-defined global operator new." << std::endl;
  return malloc(sz);
}

// Overloading global delete operator
void operator delete(void* m)
{
  std::cout << "Calling user-defined global operator delete." << std::endl;
}

int main() {

	int * a = new int();
	delete a;
	return 0;
}