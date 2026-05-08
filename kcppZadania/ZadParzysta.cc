#include <iostream>

using namespace std;

// (a) Sprawdzanie z wykorzystaniem operacji bitowych (&)
// Zasada działania:
// Liczba parzysta w zapisie binarnym zawsze ma 0 na najmłodszym bicie.
// Liczba nieparzysta zawsze ma 1 na najmłodszym bicie.
/*
   Przykład dla liczby 5 (nieparzysta):
   5 binarnie: 00000101
   1 binarnie: 00000001
   -------------------- (&)
   Wynik:      00000001  (1 czyli TRUE)

   Przykład dla liczby 6 (parzysta):
   6 binarnie: 00000110
   1 binarnie: 00000001
   -------------------- (&)
   Wynik:      00000000  (0 czyli FALSE)
*/
bool czyParzystaBitowo(int n) {
    return !(n & 1); 
}

// (b) Sprawdzanie za pomocą modulo (%)
bool czyParzystaModulo(int n) {
    if (n % 2 == 0) return true;
    else return false;
}

// (c) Sprawdzanie z użyciem operatora warunkowego
void wyswietlWynikWarunkowy(int n) {
    // (warunek ? wartosc_jesli_prawda : wartosc_jesli_falsz)
    cout << "Liczba " << n << " jest " << (n % 2 == 0 ? "Parzysta" : "Nieparzysta") << endl;
}

int main() {
    int liczba;
    cout << "Podaj liczbe calkowita: ";
    cin >> liczba;

    cout << "--- Wyniki ---" << endl;
    
    // Test funkcji (a)
    cout << "(a) Bitowo: " << (czyParzystaBitowo(liczba) ? "Parzysta" : "Nieparzysta") << endl;

    // Test funkcji (b)
    cout << "(b) Modulo: " << (czyParzystaModulo(liczba) ? "Parzysta" : "Nieparzysta") << endl;

    // Test funkcji (c)
    cout << "(c) Operator warunkowy: ";
    wyswietlWynikWarunkowy(liczba);

    return 0;
}