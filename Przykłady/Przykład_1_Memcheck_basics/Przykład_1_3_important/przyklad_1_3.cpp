/**
 * Przykład obrazujący, że Memcheck wykrywa niezainicjalizowane
 * wartości z precyzją pojedynczych bitów. Polega to na tym, że
 * każdy bit danych w rejestrach i pamięci jest śledzony (shadow)
 * za pomocą innego bitu, który wskazuje, czy ma on zdefiniowaną
 * wartość. 
 * Każda operacja wpływająca na wartość jest wzbogacana, za pomocą
 * instrumentacji, o dodatkowy kod modyfikujący bit sledzący (shadow
 * bit). Memcheck wykorzystuje właśnie te tzw. shadow bits do wykrycia
 * użyć niezdefiniowanych wartości.
 * Przykład na podstawie: http://valgrind.org/docs/memcheck2005.pdf
 */

#include <iostream>

template <int size>
class BitArray 
{
public:
	BitArray() {
		m_data = static_cast<uint8_t*>(malloc(size * sizeof(uint8_t)));
	}

	void print() const {
		for (int i = 0; i < size * 8; ++i) {
			printf("%d", (1 & (m_data[i/8] >> (i % 8))));
		}
		printf("\n");
	}

	int getValue(int index) {
		return m_data[index];
	}

	void setBit(int i) {
		m_data[i/8] |= (1 << (i % 8));
	}

	~BitArray() {
		if (m_data) free(m_data);
	}

private:
	uint8_t * m_data;
};

int main() {

	BitArray<2> testArray;

	for (int i = 0; i < 2 * 7 + 1; ++i) { // nie inicjujemy całej
		testArray.setBit(i);
	}

	//testArray.print(); // pokazać print

	if (testArray.getValue(1)) {
		printf("Not equal to 0"); // oraz dostęp do wartości
	}

	return 0;
}

/**
 * Jak to działa?
 * - każdy bit danych zarządzany przez program (zarówno w rejestrach
 *	jak i w pamięci) jest śledzony (shadowed) przez metadane w postaci
 *	innego bitu. Ten drugi bit to tzw. V bit (validity bit). Każdy V bit
 *	wskazuje, czy bit, który śledzi ma aktualnie poprawnie zdefiniowaną
 * 	wartość.
 * - każda operacja, która tworzy wartość jest śledzona przez inną 
 *	operację (shadow operation), która oblicza V bity wyjścia operacji,
 *	na podstawie V bitów wejścia i samej operacji.
 *	- Memcheck może nie zwrócić błędu związanego z niezdefiniowaną 
 *	wartością, jeśli nie jest on niebezpieczny (np. wartość ta nie jest
 * 	używana, nie wpływa więc na wykonanie programu)
 */