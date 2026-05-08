#include <iostream>

void przesun(int* tab, int rozmiar) {
    if (rozmiar <= 1) return; // Nic do przesuwania

    // Zapamiętujemy ostatni element
    // Używamy arytmetyki wskaźników, by trafic na ostatni element
    int ostatni = *(tab + rozmiar - 1);

    // Przesuwamy elementy w prawo, idąc od końca
    // p wskazuje na ostatni element
    int* p = tab + rozmiar - 1; 
    
    while (p > tab) {
        *p = *(p - 1); // Wstaw w bieżące miejsce wartość z sąsiada po lewej
        p--;           // Idź w lewo
    }

    //Wstaw zapamiętany ostatni element na sam początek
    *tab = ostatni;
}

void wypisz(int* tab, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        std::cout << *(tab + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int liczby[] = {1, 2, 3, 4, 5, 10};
    int n = sizeof(liczby) / sizeof(liczby[0]);

    std::cout << "Przed: ";
    wypisz(liczby, n);

    przesun(liczby, n);

    std::cout << "Po:    ";
    wypisz(liczby, n);

    return 0;
}