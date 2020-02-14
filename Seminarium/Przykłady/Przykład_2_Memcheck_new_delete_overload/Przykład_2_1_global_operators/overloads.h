#ifndef overloads_h
#define overloads_h

static unsigned newCounter = 0;
static unsigned deleteCounter = 0;
static unsigned newArrayCounter = 0;
static unsigned deleteArrayCounter = 0;

// Overloading global new operator
void* operator new(size_t sz)
{
  std::cout<< "Calling user-defined global operator new." << std::endl;
  ++newCounter;
  return malloc(sz);
}

// Overloading global delete operator
void operator delete(void* m)
{
  std::cout << "Calling user-defined global operator delete." << std::endl;
  ++deleteCounter;
  free(m);
}

// Overloading global new[] operator
void* operator new[](size_t sz)
{
  std::cout << "Calling user-defined global operator new[]." << std::endl;
  ++newArrayCounter;
  return malloc(sz);
}

// Overloading global delete[] operator
void operator delete[](void* m)
{
  std::cout << "Calling user-defined global operator delete[]." << std::endl;
  ++deleteArrayCounter;
  free(m);
}



#endif // overloads_h