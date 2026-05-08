#include <iostream>
#include <cmath>

using namespace std;

/**
 * Funkcja pakuje tablicę zer i jedynek do jednej liczby.
 * Założenie: tablica ma 8 elementów.
 */
unsigned char pakujBity(int tab[]) {
    unsigned char wynik = 0; // Zaczynamy od samych zer (00000000)

    for (int i = 0; i < 8; i++) {
        if (tab[i] == 1) {
            // Przesuwamy jedynkę o 'i' pozycji w lewo 
            // i dodajemy do wyniku operatorem OR (|)
            wynik = wynik | (1 << i);
        }
    }
    return wynik;
}

int main() {
    // Przykładowa tablica (reprezentacja liczby 13: 1*1 + 0*2 + 1*4 + 1*8 = 13)
    // Kolejność: od najmłodszego bitu (indeks 0) do najstarszego (indeks 7)
    int dane[8] = {1, 0, 1, 1, 0, 0, 0, 0};

    cout << "Tablica wejsciowa: ";
    for(int i = 0; i < 8; i++) cout << dane[i] << " ";
    cout << endl;

    unsigned char liczba = pakujBity(dane);

    // Wyświetlamy jako int, bo unsigned char wypisze znak ASCII
    cout << "Wynikowa liczba (dziesietnie): " << (int)liczba << endl;

    return 0;
}