#include <iostream>
#include <cstddef> // Biblioteka dla typu ptrdiff_t

int main() {
    // Definiujemy tablicę 10 liczb całkowitych
    int tablica[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Tworzymy dwa wskaźniki wskazujące na różne elementy
    int* ptr1 = &tablica[2]; 
    int* ptr2 = &tablica[7]; 
    // Obliczamy różnicę
    // ptrdiff_t to specjalny typ do przechowywania różnicy wskaźników
    ptrdiff_t roznica = ptr2 - ptr1;

    // Wypisujemy wyniki
    std::cout << "Wskaznik 1 wskazuje na: " << *ptr1 << " (indeks 2)" << std::endl;
    std::cout << "Wskaznik 2 wskazuje na: " << *ptr2 << " (indeks 7)" << std::endl;
    std::cout << "Roznica miedzy wskaznikami (liczba elementow): " << roznica << std::endl;

    // Ciekawostka: różnica ujemna
    std::cout << "Roznica odwrotna (ptr1 - ptr2): " << (ptr1 - ptr2) << std::endl;

    return 0;
}