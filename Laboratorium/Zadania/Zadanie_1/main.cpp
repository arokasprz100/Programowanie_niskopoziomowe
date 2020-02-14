/**

Programowanie niskopoziomowe - laboratorium
Zadanie 1
Poniższy program stanowi prostą implementacją listy połączonej
(linked list). Implementacja ta zawiera kilka błędów związanych
z zarządzaniem pamięcią.
Celem zadania jest wykrycie tych błędów za pomocą narzedzia 
Memcheck, a następnie wyeliminowanie ich tak, by program 
działał poprawnie, a wyjście odpowiadało oczekiwanemu (podane
na dole pliku).
Dołączone pliki można modyfikować, natomiast proszę nie stosować
rozwiązania polegającego na zastąpieniu funkcji main() samym
wypisywaniem.

**/

#include "LinkedList.hpp"

int main()
{
	LinkedList list;

	int value;
	list.addNewNode(value);
	list.addNewNode(value + 10);
	list.addNewNode(value + 20);
	list.addNewNode(value + 30);
	list.addNewNode(value + 40);
	list.print();

	list.popBack();
	list.print();

	list.removeAll();
	list.addNewNode(value + 10);
	list.print();
}

/*
==== Creating linked list ====
[ 0 10 20 30 40 ]
[ 0 10 20 30 ]
[ 10 ]
==== Destroying linked list ====
*/