#include <iostream>
#include <fstream>
#include <string>

class Kolejka {
private:
    struct Wezel {
        int dana;
        Wezel* nastepny;
        Wezel(int val) : dana(val), nastepny(nullptr) {}
    };

    Wezel* poczatek;
    Wezel* koniec;

public:
    // Konstruktor
    Kolejka() {
        poczatek = nullptr;
        koniec = nullptr;
    }

    // Dekonstruktor
    ~Kolejka() {
        while (poczatek != nullptr) {
            Wezel* temp = poczatek;
            poczatek = poczatek->nastepny;
            delete temp;
        }
    }

    // Sprawdzenie czy kolejka jest pusta
    bool jestPusta() const {
        return poczatek == nullptr;
    }

    // Dodaj (enqueue)
    void dodaj(int liczba) {
        Wezel* nowy = new Wezel(liczba);
        if (koniec == nullptr) {
            poczatek = koniec = nowy;
        } else {
            koniec->nastepny = nowy;
            koniec = nowy;
        }
        std::cout << "Dodano: " << liczba << "\n";
    }

    // Usuñ (dequeue)
    void usun() {
        if (jestPusta()) {
            std::cout << "Kolejka jest pusta, nie ma czego usunac.\n";
            return;
        }
        Wezel* temp = poczatek;
        poczatek = poczatek->nastepny;
        if (poczatek == nullptr) {
            koniec = nullptr;
        }
        std::cout << "Usunieto: " << temp->dana << "\n";
        delete temp;
    }

    // Wypisz
    void wypisz() const {
        if (jestPusta()) {
            std::cout << "Kolejka jest pusta.\n";
            return;
        }
        std::cout << "Stan kolejki: ";
        Wezel* temp = poczatek;
        while (temp != nullptr) {
            std::cout << temp->dana << " ";
            temp = temp->nastepny;
        }
        std::cout << "\n";
    }

    // Wczytaj z pliku "liczby.txt"
    void wczytajZPliku() {
        std::string nazwaPliku = "liczby.txt";
        std::ifstream plik(nazwaPliku);

        if (!plik.is_open()) {
            std::cout << "Blad: Nie udalo sie otworzyc pliku \"" << nazwaPliku << "\"!\n";
            std::cout << "Upewnij sie, ze plik istnieje w tym samym folderze co program.\n";
            return;
        }

        int liczba;
        int licznik = 0;
        while (plik >> liczba) {
            dodaj(liczba);
            licznik++;
        }
        plik.close();
        std::cout << "Wczytano " << licznik << " elementow z pliku \"" << nazwaPliku << "\".\n";
    }

    // Zapisz do pliku "wynik.txt"
    void zapiszDoPliku() const {
        std::string nazwaPliku = "wynik.txt";
        std::ofstream plik(nazwaPliku);

        if (!plik.is_open()) {
            std::cout << "Blad: Nie dalo rady pliku otworzyc\n";
            return;
        }

        Wezel* temp = poczatek;
        while (temp != nullptr) {
            plik << temp->dana << " ";
            temp = temp->nastepny;
        }
        plik.close();
        std::cout << "Zapisano obecna kolejke do pliku \"" << nazwaPliku << "\".\n";
    }

    // Sortowanie b¹belkowe bezpoœrednio na kolejce
    void sortuj() {
        if (jestPusta() || poczatek == koniec) {
            std::cout << "Kolejka jest za krotka do sortowania.\n";
            return;
        }

        bool zamiana;
        Wezel* ptr;
        Wezel* ostatni = nullptr;

        do {
            zamiana = false;
            ptr = poczatek;

            while (ptr->nastepny != ostatni) {
                if (ptr->dana > ptr->nastepny->dana) {
                    int temp = ptr->dana;
                    ptr->dana = ptr->nastepny->dana;
                    ptr->nastepny->dana = temp;
                    zamiana = true;
                }
                ptr = ptr->nastepny;
            }
            ostatni = ptr;
        } while (zamiana);

        std::cout << "Kolejka zostala posortowana rosnaco.\n";
    }
};

int main() {


    Kolejka k;
    int wybor = -1;
    int liczba;

    do {
        std::cout << "\n===============================\n";
        std::cout << "         MENU KOLEJKI          \n";
        std::cout << "===============================\n";
        std::cout << "1. Dodaj element recznie\n";
        std::cout << "2. Usun element (z poczatku)\n";
        std::cout << "3. Wyswietl kolejke\n";
        std::cout << "4. Wczytaj z pliku\n";
        std::cout << "5. Zapisz do pliku\n";
        std::cout << "6. Posortuj kolejke\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz opcje: ";

        if (!(std::cin >> wybor)) {
            std::cout << "Blad odczytu!\n";
            break;
        }

        switch (wybor) {
            case 1:
                std::cout << "Podaj liczbe do dodania: ";
                std::cin >> liczba;
                k.dodaj(liczba);
                break;
            case 2:
                k.usun();
                break;
            case 3:
                k.wypisz();
                break;
            case 4:
                k.wczytajZPliku(); // Na sztywno "liczby.txt"
                break;
            case 5:
                k.zapiszDoPliku(); // Na sztywno "wynik.txt"
                break;
            case 6:
                k.sortuj();
                break;
            case 0:
                std::cout << "Koniec programu.\n";
                break;
            default:
                std::cout << "Niepoprawny wybor. Sprobuj ponownie.\n";
        }
    } while (wybor != 0);

    return 0;
}
