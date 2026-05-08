#include <iostream>
using namespace std;

int main() {
    int liczba, suma = 0;
    int licznik = 0; // Zmienna do zliczania wprowadzonych wartości

    cout << "Wprowadzaj liczby dodatnie (0 konczy program):" << endl;
    cin >> liczba;

    while (liczba != 0) {
        // Sprawdzanie, czy liczba jest dodatnia
        if (liczba > 0) {
            suma += liczba;
            licznik++; // Zwiekszamy licznik tylko dla liczb dodatnich
        } else {
            // Komunikat dla liczb ujemnych
            cout << "Pominieto: Liczba " << liczba << " nie jest dodatnia!" << endl;
        }

        // Pobranie kolejnej liczby
        cin >> liczba;
    }

    cout << "------------------------------------" << endl;
    cout << "Suma dodatnich liczb: " << suma << endl;
    cout << "Liczba wprowadzonych (dodatnich) wartosci: " << licznik << endl;

    return 0;
}