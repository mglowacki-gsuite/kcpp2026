#include <iostream>

struct Kontener {
    int dane[5];
};

// Tutaj przekazujemy obiekt przez WARTOSC (kopia)
void zmienIKopiuj(Kontener k) {
    k.dane[0] = 999; // Zmieniamy tylko w lokalnej kopii
    std::cout << "Wewnatrz funkcji (kopia): " << k.dane[0] << std::endl;
}

int main() {
    Kontener mojaTablica = {{1, 2, 3, 4, 5}};

    std::cout << "Przed funkcja: " << mojaTablica.dane[0] << std::endl;
    
    zmienIKopiuj(mojaTablica); // Przekazujemy kopie
    
    std::cout << "Po funkcji (oryginal): " << mojaTablica.dane[0] << std::endl;
    // Wynik nadal bedzie 1, bo funkcja pracowala na kopii!

    return 0;
}