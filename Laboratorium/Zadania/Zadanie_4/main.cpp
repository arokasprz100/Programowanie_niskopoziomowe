/**

Programowanie niskopoziomowe - laboratorium
Zadanie 4
Zadanie ma na celu przećwiczenie korzystania z narzędzia
Massif. 
Należy przeprowadzić analizę działania poniższego programu
za pomocą narzędzia Massif. W tym celu należy skompilować
program za pomocą dołączonego pliku makefile a następnie 
wykonać komendę:

valgrind --tool=massif ./Zadanie_4

W ten sposób otrzymamy plik z wynikami analizy, który powinien
nazywać się massif.out.<PID> gdzie <PID> to numer procesu.

Otrzymany plik analizujemy za pomocą ms_print:

ms_print <plik>

Proszę w szczególności zwrócić uwagę na wykres oraz tabelę
tzw. snapshotów. 

Proszę powtórzyć badanie, tym razem dodając do polecenia 
Valgrinda flagę:  --time-unit = ms a następnie --time-unit=B.
Jaka występuje różnica i dlaczego tak jest?


**/

#include <cstdlib>
#include <chrono>
#include <thread>

class SquareMatrix 
{
public:
	SquareMatrix(unsigned size) : m_size(size) {
		m_data = new double* [size];
		for (unsigned i = 0; i < size; ++i) {
			m_data[i] = new double[size];
		}
	}

	void fillWithRandomData() {
		for (unsigned i = 0; i < m_size; ++i) {
			for (unsigned j = 0; j < m_size; ++j) {
				m_data[i][j] = rand() % 100 + 1;
			}
		}
	}

	~SquareMatrix() {
		for (unsigned i = 0; i < m_size; ++i) {
			delete [] m_data[i];
		}
		delete[] m_data;
	}

private:
	double ** m_data;
	unsigned m_size;
};

int main() {

	using namespace std::this_thread; 
    using namespace std::chrono;

	SquareMatrix matrixA(50);
	matrixA.fillWithRandomData();
	SquareMatrix matrixB(100);
	matrixB.fillWithRandomData();

	sleep_for(milliseconds(200));

	SquareMatrix matrixC(50);
	matrixC.fillWithRandomData();

	return 0;
}