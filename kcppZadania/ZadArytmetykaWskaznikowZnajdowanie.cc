#include <iostream>

int maxElement(int *p, int rozmiar){
        
        int maksimum = 0;
        for(int i=0; i < rozmiar; i++){

            if(*p > maksimum){
                maksimum = *p;
            }
            p++;
        }
        return maksimum;


}


int main() {
    int liczby[] = {1, 2, 3, 4, 5, 10};
    int n = sizeof(liczby) / sizeof(liczby[0]); // Obliczanie rozmiaru tablicy

    // Przekazujemy tablicę (która automatycznie staje się wskaźnikiem)
    int wynikMax = maxElement(liczby, n);

    std::cout << "MaxElement wynosi: " << wynikMax << std::endl;
    int liczby1[] = {10, 5, 4, 3, 2, 1};
    int wynikMax2 = maxElement(liczby1, n);
    std::cout << "MaxElement wynosi: " << wynikMax2 << std::endl;
    return 0;
}