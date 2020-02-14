/**

Programowanie niskopoziomowe - laboratorium
Zadanie 2
Zadanie polega na wykorzystaniu poznanych żądań
klienta (client requests) - czyli specjalnych makr
udostępnianych przez Valgrinda i jego narzędzia.

Należy napisać 4 krótkie funkcje tak, by osiągnąć 
zadane wyjście programu. Pod funkcją main znajdują
się dwa przypadki możliwego wyjścia:
	- jedno, gdy uruchamiamy program bez Valgrinda
	- drugie, gdy uruchamiamy program z jego pomocą
Proszę doprowadzić do sytuacji, by program mógł dać 
oba z poniższych wyjść (oczywiście z dokładnością do
adresów i ścieżek dostępu do plików).

Uwaga! Szczególnie przydatne makra:
 	- VALGRIND_PRINTF_BACKTRACE
 	- VALGRIND_COUNT_ERRORS
 	- RUNNING_ON_VALGRIND
 	- VALGRIND_DO_LEAK_CHECK

**/

#include "valgrind/memcheck.h"
#include <iostream>

void breakMemory() {
}

void printNumberOfErrors() {
}

void printIfTesting() {
}

void performLeakCheck() {

}


int main() {

	printIfTesting();
	performLeakCheck();
	printNumberOfErrors();
	breakMemory();
	printNumberOfErrors();
}

// Output bez Valgrinda:
/*
Normal run.
No errors found
No errors found
*/

// Output z Valgrindem:
/*
==696== Memcheck, a memory error detector
==696== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==696== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==696== Command: ./Zadanie_2
==696==
==696== error calling PR_SET_PTRACER, vgdb might block
We are testing!
==696== LEAK SUMMARY:
==696==    definitely lost: 0 bytes in 0 blocks
==696==    indirectly lost: 0 bytes in 0 blocks
==696==      possibly lost: 0 bytes in 0 blocks
==696==    still reachable: 76,800 bytes in 2 blocks
==696==         suppressed: 0 bytes in 0 blocks
==696== Reachable blocks (those to which a pointer was found) are not shown.
==696== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==696==
No errors found
**696** Here we add some errors   at 0x108BB4: VALGRIND_PRINTF_BACKTRACE(char const*, ...) (valgrind.h:6303)
==696==    by 0x108C04: breakMemory() (main.cpp:29)
==696==    by 0x108E9D: main (main.cpp:64)
==696== Conditional jump or move depends on uninitialised value(s)
==696==    at 0x108C09: breakMemory() (main.cpp:31)
==696==    by 0x108E9D: main (main.cpp:64)
==696==
We have detected 1 memory errors.
==696==
==696== HEAP SUMMARY:
==696==     in use at exit: 0 bytes in 0 blocks
==696==   total heap usage: 2 allocs, 2 frees, 76,800 bytes allocated
==696==
==696== All heap blocks were freed -- no leaks are possible
==696==
==696== For counts of detected and suppressed errors, rerun with: -v
==696== Use --track-origins=yes to see where uninitialised values come from
==696== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/