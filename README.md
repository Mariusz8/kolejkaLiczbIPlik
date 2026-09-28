C++ Kolejka na Listie Wiązanej (Queue Implementation)
Projekt przedstawia implementację struktury danych kolejki (FIFO - First In, First Out) opartej na dynamicznej liście wiązanej w języku C++. Program zawiera interaktywne menu konsolowe, obsługuje operacje na plikach tekstowych oraz implementuje algorytm sortowania bąbelkowego działający bezpośrednio na wskaźnikach węzłów.

🚀 Funkcjonalności
Dodawanie elementu (enqueue) – dodaje nową liczbę na koniec kolejki.

Usuwanie elementu (dequeue) – usuwa element z początku kolejki i zwalnia pamięć.

Wyświetlanie kolejki – wypisuje aktualny stan elementów w kolejce.

Wczytywanie z pliku – automatycznie pobiera liczby z pliku tekstowego liczby.txt na sztywno przypisanego do programu.

Zapis do pliku – zapisuje aktualny stan kolejki do pliku wynik.txt.

Sortowanie bąbelkowe – sortuje elementy rosnąco bezpośrednio na strukturze węzłów (bez używania dodatkowych tablic pomocniczych).

📂 Struktura plików
kolejka.cpp – główny plik źródłowy zawierający kod programu i logikę kolejki.

liczby.txt – plik wejściowy z danymi (liczby oddzielone spacjami lub enterami), z którego program wczytuje elementy.

wynik.txt – plik wyjściowy generowany automatycznie podczas zapisu stanu kolejki.

📥 Wymagania pliku wejściowego (liczby.txt)
Przed uruchomieniem opcji wczytywania z pliku upewnij się, że w tym samym folderze znajduje się plik liczby.txt. Przykład zawartości pliku:

Plaintext
45 12 78 3 23 89 1
(Liczby mogą być oddzielone spacjami, tabulatorami lub znakami nowej linii).

🛠️ Jak skompilować i uruchomić?
W środowisku Code::Blocks / Dev-C++:
Otwórz plik kolejka.cpp w programie.

Kliknij Build & Run (lub naciśnij F9).

W terminalu (kompilator GCC/Clang):
Bash
g++ kolejka.cpp -o kolejka
./kolejka
🧭 Obsługa menu
Po uruchomieniu programu pojawi się interaktywne menu:

Plaintext
===============================
         MENU KOLEJKI          
===============================
1. Dodaj element ręcznie
2. Usuń element (z początku)
3. Wyświetl kolejkę
4. Wczytaj z pliku (liczby.txt)
5. Zapisz do pliku (wynik.txt)
6. Posortuj kolejkę (bąbelkowo)
0. Wyjście
Wybierz opcję:
