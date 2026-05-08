#include <iostream>
#include <string>

// Globalna zmienna pomocnicza dla demonstracji referencji i wskaźnika
int globalnyLicznik = 100;
int globalnaTablica[] = {10, 20, 30};

// 1. Zwracanie przez wartość (kopia)
int zwrocPrzezWartosc() {
    int x = 10;
    return x; // Tworzona jest kopia 'x' i przekazywana do miejsca wywołania
}

// 2. Zwracanie przez referencję
int& zwrocPrzezReferencje() {
    return globalnyLicznik;
}

// 3. Zwracanie przez wskaźnik
int* zwrocPrzezWskaznik() {
    return &globalnyLicznik; // Zwracamy adres zmiennej
}

// 4. Zwracanie tablicy
// W C++ "zwrócenie tablicy" to w praktyce zwrócenie wskaźnika na jej pierwszy element
int* zwrocTablice() {
    return globalnaTablica; 
    // Alternatywnie można zwrócić tablicę dynamiczną (new int[3]), ale wtedy trzeba pamiętać o delete[]
}

int main() {
    // Ad 1.
    int wartosc = zwrocPrzezWartosc();
    std::cout << "1. Wartosc: " << wartosc << std::endl;

    // Ad 2.
    int& ref = zwrocPrzezReferencje();
    ref = 200; // Zmiana 'ref' zmieni też 'globalnyLicznik'
    std::cout << "2. Referencja (globalnyLicznik): " << globalnyLicznik << std::endl;

    // Ad 3.
    int* wsk = zwrocPrzezWskaznik();
    std::cout << "3. Wskaznik (adres): " << wsk << " (wartosc): " << *wsk << std::endl;

    // Ad 4.
    int* tab = zwrocTablice();
    for(int i=0;i<3;i++){
        std::cout << "4. Tablica [" << i << "]: " << tab[i] << std::endl;
    }

    return 0;
}