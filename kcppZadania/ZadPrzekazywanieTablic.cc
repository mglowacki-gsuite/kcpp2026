#include <iostream>

// template <int N> mówi kompilatorowi: "N to liczba, którą sam odczytaj z tablicy"
// int (&tab)[N] to referencja do tablicy o konkretnym rozmiarze N
template <int N>
void wypiszTablice(int (&tab)[N]) {
    std::cout << "--- Funkcja rozpoznala rozmiar: " << N << " ---" << std::endl;
    
    for (int i = 0; i < N; i++) {
        std::cout << "Element [" << i << "]: " << tab[i] << std::endl;
    }
}

int main() {
    int malaTablica[] = {10, 20};
    int duzaTablica[] = {1, 2, 3, 4, 5, 6};

    // Wywołujemy tę samą nazwę funkcji dla różnych tablic
    wypiszTablice(malaTablica); // Kompilator tworzy wersję funkcji dla N = 2
    wypiszTablice(duzaTablica); // Kompilator tworzy wersję funkcji dla N = 6

    return 0;
}