Plik filter.supp zawiera rozwiązanie zadania (wygenerowane filtry).

Polecenie generujące filtry:

valgrind --gen-suppressions=yes ./Zadanie_3

Polecenie aplikujące plik z filtrami:

valgrind --suppressions=filter.supp ./Zadanie_3