#include <iostream>
#include "include/Zadania.h"

using namespace std;

void wyswietlMenu() {
    cout << "\n=======================================================" << endl;
    cout << " MENU ZADAN C++" << endl;
    cout << "=======================================================" << endl;
    cout << " Sekcja A: Podstawy i Struktury" << endl;
    cout << "  1 - Zadanie 1: Pojazdy (Struktury i Konstruktory)" << endl;
    cout << "  2 - Zadanie 2: Figury (Polimorfizm i Metody Abstrakcyjne) [OBOWIAZKOWE 5.6]" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << " Sekcja B: Petle" << endl;
    cout << "  3 - Zadanie 3: Liczby nieparzyste i podzielne przez 7" << endl;
    cout << "  4 - Zadanie 4: Obliczanie sumy silni do N" << endl;
    cout << "  5 - Zadanie 5: Sumowanie liczb dodatnich (0 konczy)" << endl;
    cout << "  6 - Zadanie 6: Gra 'Zgadnij wylosowana liczbe'" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << " Sekcja C: Formatowanie i Operatory" << endl;
    cout << "  7 - Zadanie 7: Tabela konwersji Celsjusz -> Fahrenheit" << endl;
    cout << "  8 - Zadanie 8: Formatowanie stalych matematycznych" << endl;
    cout << "  9 - Zadanie 9: Sprawdzanie parzystosci (operacje bitowe)" << endl;
    cout << "  10 - Zadanie 10: Test zachowania petli while, do-while, for" << endl;
    cout << "=======================================================" << endl;
    cout << "  0 - Wyjscie z programu" << endl;
    cout << "=======================================================" << endl;
    cout << "Wybierz numer zadania: ";
}

int main() {
    int wybor;
    
    do {
        wyswietlMenu();
        cin >> wybor;

        // Sprawdza, czy użytkownik wpisał tekst zamiast liczby
        if (cin.fail()) {
            cin.clear(); // Resetuje stan błędu strumienia cin
            cin.ignore(10000, '\n'); // Czysci bufor, odrzucając wpisany tekst
            wybor = -1; // Ustawiamy na -1, żeby switch przeszedł do "default"
        }

        // Tworzenie wskaźnika na klase bazowa, aby uzyc polimorfizmu do wywolania
        ZadKcpp* zadanieDoWykonania = nullptr;

        switch (wybor) {
            case 1:  zadanieDoWykonania = new Zadanie1(); break;
            case 2:  zadanieDoWykonania = new Zadanie2(); break;
            case 3:  zadanieDoWykonania = new Zadanie3(); break;
            case 4:  zadanieDoWykonania = new Zadanie4(); break;
            case 5:  zadanieDoWykonania = new Zadanie5(); break;
            case 6:  zadanieDoWykonania = new Zadanie6(); break;
            case 7:  zadanieDoWykonania = new Zadanie7(); break;
            case 8:  zadanieDoWykonania = new Zadanie8(); break;
            case 9:  zadanieDoWykonania = new Zadanie9(); break;
            case 10: zadanieDoWykonania = new Zadanie10(); break;
            case 0:  cout << "Zakończono program. Do zobaczenia!" << endl; break;
            default: cout << "Nieprawidłowa wartość. Wpisz ponownie z zakresu 0-10 (0 kończy działanie programu)" << endl;
        }

        // Jezeli utworzono obiekt zadania, uruchamia je, a nastepnie zwalnia pamiec
        if (zadanieDoWykonania != nullptr) {
            zadanieDoWykonania->wykonajZadanie();
            delete zadanieDoWykonania;
        }

    } while (wybor != 0);

    return 0;
}