#include <iostream>

using namespace std;

int main() {
    //Deklaracja i wypełnienie tablicy (1-10)
    int tab[10];
    int* p = tab; // Wskaźnik na początek tablicy

    for (int i = 1; i <= 10; i++) {
        *p = i;   // Wpisz wartość pod aktualny adres
        p++;      // Przesuń wskaźnik na kolejną komórkę
    }

    //Obliczanie sumy za pomocą wskaźników
    p = tab; // Resetujemy wskaźnik na początek
    int suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += *(p + i); // Używamy arytmetyki (bez zmiany p)
    }
    cout << "Suma elementow: " << suma << endl;

    //Znalezienie maksimum
    p = tab;
    int maxVal = *p; // Zakładamy, że pierwszy jest największy
    for (int i = 1; i < 10; i++) {
        if (*(p + i) > maxVal) {
            maxVal = *(p + i);
        }
    }
    cout << "Maksymalny element: " << maxVal << endl;

    //Odwracanie tablicy wyłącznie wskaźnikami
    int* lewy = tab; // Wskaźnik na pierwszy element
    int* prawy = tab + 9; // Wskaźnik na ostatni element (tab + rozmiar - 1)

    while (lewy < prawy) {
        // Zamiana wartości miejscami
        int temp = *lewy;
        *lewy = *prawy;
        *prawy = temp;

        // Zbliżamy wskaźniki do siebie
        lewy++;
        prawy--;
    }

    // Wyświetlenie odwróconej tablicy dla sprawdzenia
    cout << "Odworcona tablica: ";
    p = tab;
    for (int i = 0; i < 10; i++) {
        cout << *(p++) << " ";
    }
    cout << endl;

    return 0;
}