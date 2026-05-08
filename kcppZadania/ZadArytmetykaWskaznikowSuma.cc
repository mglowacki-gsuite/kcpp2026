#include <iostream>


int suma(int *p, int rozmiar){
    int wynik = 0;
    for(int i=0; i < rozmiar; i++){
            wynik += *p;
            p++;
    }
    return wynik;
}

int main() {
    int liczby[] = {1, 2, 3, 4, 5, 10};
    int n = sizeof(liczby) / sizeof(liczby[0]); // Obliczanie rozmiaru tablicy

    // Przekazujemy tablicę (która automatycznie staje się wskaźnikiem)
    int wynikSumy = suma(liczby, n);

    std::cout << "Suma elementow tablicy wynosi: " << wynikSumy << std::endl;

    return 0;
}