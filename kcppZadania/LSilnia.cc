#include <iostream>
using namespace std;

int main() {
    int n;
    long long sumaSilni = 0;

    cout << "Podaj liczbe n: ";
    cin >> n;

    // 1. Sprawdzenie, czy liczba jest nieujemna
    if (n < 0) {
        cerr << "Blad: Silnia nie jest zdefiniowana dla liczb ujemnych!" << endl;
        return 1; // Konczymy program z kodem bledu
    }

    // 2. Obliczanie sumy silni od 1 do n
    // Zewnetrzna petla przechodzi przez kolejne liczby k = 1, 2, ..., n
    for (int k = 1; k <= n; k++) {
        long long aktualnaSilnia = 1;
        
        // Wewnetrzna petla oblicza silnie dla konkretnego k
        for (int i = 1; i <= k; i++) {
            aktualnaSilnia *= i;
        }
        
        sumaSilni += aktualnaSilnia;
        cout << k << "! = " << aktualnaSilnia << endl; // Opcjonalne: wypisuje kroki
    }

    cout << "------------------------------------" << endl;
    cout << "Suma silni od 1 do " << n << " wynosi: " << sumaSilni << endl;

    return 0;
}