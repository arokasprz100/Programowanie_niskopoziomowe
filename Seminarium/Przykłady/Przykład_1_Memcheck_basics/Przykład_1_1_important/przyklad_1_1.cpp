/**
 * Arkadiusz Kasprzak
 * Programowanie niskopoziomowe.
 * Narzędzia do debugowania.
 * Przykład 1.1: Valgrind: illegal read/write in Memcheck
 * Przykład obrazujący jeden z podstawowych błędów, jakie może 
 * wykryć Memcheck - nieuprawniony dostęp do pamięci.
 *
 * Uruchomienie przykładu:
 * make 
 * valgrind --leak-check=full ./przyklad_1_1
 */

#include <vector> // std::vector

int main() {

	std::vector<int> testVector { 1, 2, 3, 4, 5 };
  	testVector[5] = 6; // Invalid write of size 4

  	int tempValue = testVector[5]; // Invalid read of size 4
}

/**
 * Jak to działa?
 * Każdy bajt(!) w pamięci (ale nie w CPU), ma skorelowany ze sobą 
 * tzw. A bit (valid-address bit). Wskazuje on, czy program może
 * pisać lub czytać z tego miejsca w pamięci. 
 * Uwaga: A-bit nie wskazuje, czy dane w pamięci są poprawne (np. czy
 * wartość jest zdefiniowana)
 * Za każdym razem, gdy program odczytuje lub zapisuje pamięć, Memcheck
 * sprawdza A bit związany z adresem. Jeśli wskazuje on, że adres nie 
 * jest poprawny (nie mamy prawa wykonać danej operacji), to pojawia się
 * error. 
 * Odczyt i zapis pamięci nie modyfikuje A-bitów, jedynie je sprawdza.
 * W momencie użycia malloc/new A-bity związane z zaalokowanym obszarem
 * (i tylko z nim!) są ustawiane, by wskazywać możliwość dostępu.
 * Przy zwalnianiu pamięci bity te są ustawiane tak, by wskazywać brak
 * możliwości dostępu. 
 */