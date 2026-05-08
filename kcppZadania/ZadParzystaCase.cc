#include <iostream>

using namespace std;

// (a) Funkcja bitowa
bool czyParzystaBitowo(int n) {
    return !(n & 1); 
}

// (b) Funkcja modulo
bool czyParzystaModulo(int n) {
    return (n % 2 == 0);
}

// (c) Funkcja z operatorem warunkowym
void wyswietlWynikWarunkowy(int n) {
    cout << "Wynik Warunkowy: Liczba jest " << (n % 2 == 0 ? "parzysta" : "nieparzysta") << endl;
}

int main() {
    int liczba, wybor;

    cout << "Podaj liczbe do sprawdzenia: ";
    cin >> liczba;

    cout << "\n--- WYBIERZ METODE SPRAWDZENIA ---" << endl;
    cout << "1. Metoda bitowa (&)" << endl;
    cout << "2. Metoda modulo (%)" << endl;
    cout << "3. Operator warunkowy (?:)" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;

    cout << "----------------------------------" << endl;

    // Instrukcja switch do obsługi menu
    switch (wybor) {
        case 1:
            cout << "Metoda bitowa: ";
            if (czyParzystaBitowo(liczba)) cout << "Liczba parzysta" << endl;
            else cout << "Liczba nieparzysta" << endl;
            break;

        case 2:
            cout << "Metoda modulo: ";
            if (czyParzystaModulo(liczba)) cout << "Liczba parzysta" << endl;
            else cout << "Liczba nieparzysta" << endl;
            break;

        case 3:
            wyswietlWynikWarunkowy(liczba);
            break;

        default:
            cerr << "Blad: Niepoprawny wybor z menu!" << endl;
            break;
    }

    return 0;
}