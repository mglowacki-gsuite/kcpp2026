#include <iostream>

// Funkcja kopiuje dane z tablicy 'zrodlo' do 'cel'
void kopiujTablice(int* zrodlo, int* cel, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        // Kopiujemy wartość ze źródła i przypisujemy do celu
        *cel = *zrodlo;

        // Przesuwamy oba wskaźniki na kolejne elementy
        zrodlo++;
        cel++;
    }
}

// Funkcja pomocnicza do wypisywania
void wypisz(int* tab, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        std::cout << *(tab + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int N = 5;
    int tablicaA[N] = {10, 20, 30, 40, 50};
    int tablicaB[N]; // Pusta tablica docelowa

    std::cout << "Tablica A (zrodlo): ";
    wypisz(tablicaA, N);

    // Wywołujemy kopiowanie
    kopiujTablice(tablicaA, tablicaB, N);

    std::cout << "Tablica B (kopia):  ";
    wypisz(tablicaB, N);

    return 0;
}