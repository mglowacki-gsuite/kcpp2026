#include <iostream>
using namespace std;

int main() {
    int rozmiar;
    cout << "Podaj wysokosc figur: ";
    cin >> rozmiar;

    // trojkat rownoramienny
    cout << "\nTrojkat rownoramienny:" << endl;
    for (int i = 1; i <= rozmiar; i++) {
        // Pętla rysująca spacje (wyrównanie do środka)
        for (int j = 1; j <= rozmiar - i; j++) {
            cout << " ";
        }
        // Pętla rysująca gwiazdki
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    // Piramida
    cout << "\nPiramida z liczb:" << endl;
    for (int i = 1; i <= rozmiar; i++) {
        // Pętla rysująca spacje
        for (int j = 1; j <= rozmiar - i; j++) {
            cout << " ";
        }
        // Pętla rysująca liczby (liczba i wypisana i-razy)
        for (int k = 1; k <= i; k++) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}