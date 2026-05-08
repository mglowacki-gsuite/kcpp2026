#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    int tab[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Adres poczatkowy tablicy: " << tab << endl;
    cout << "Rozmiar typu int: " << sizeof(int) << " bajty" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Indeks\t\tWartosc\t\tAdres (HEX)" << endl;

    // Używamy wskaźnika do przejścia przez całą tablicę "liniowo"
    // Rzutujemy tablicę na wskaźnik do int, aby potraktować ją jak 1D
    int* ptr = &tab[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "[" << i << "][" << j << "]\t\t" 
                 << tab[i][j] << "\t\t" 
                 << &tab[i][j] << endl;
        }
        cout << "--- Koniec wiersza ---" << endl;
    }

    cout << "---------------------------------------------" << endl;
    
    // Demonstracja arytmetyki: skok do konkretnego elementu
    // tab[1][1] (wartość 5) to czwarty element licząc od początku (indeks 4)
    int *srodek = &tab[0][0] + (1 * 3 + 1); 
    cout << "Wartosc wyliczona arytmetycznie tab[1][1]: " << *srodek << endl;

    return 0;
}