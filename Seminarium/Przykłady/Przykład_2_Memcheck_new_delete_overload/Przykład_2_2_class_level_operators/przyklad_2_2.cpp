#include <iostream>

class Point 
{
public:
    static void* operator new(std::size_t sz)
    {
        std::cout << "Calling new for Point." << std::endl;
        ++newCounter;
        return ::operator new(sz);
    }

    static void* operator new[](std::size_t sz)
    {
        std::cout << "Calling new[] for Point." << std::endl;
        ++newArrayCounter;
        return ::operator new(sz);
    }

    static void printCounters() {
        std::cout << "Overloaded new has been used " << newCounter << " times." << std::endl;
        std::cout << "Overloaded new[] has been used " << newArrayCounter << " times." << std::endl;

    }

private:
    static unsigned newCounter;
    static unsigned newArrayCounter;
};

unsigned Point::newCounter = 0;
unsigned Point::newArrayCounter = 0;

int main() {

    Point * testPoint = new Point();

    Point::printCounters();

    return 0;
}