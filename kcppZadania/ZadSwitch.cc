/*

Czy da się to zrobić bezpośrednio?
Nie bezpośrednio. W C++ instrukcja switch może operować wyłącznie na typach całkowitych (np. int, char, enum). 
Obiekt klasy std::string nie jest typem całkowitym, więc kod typu switch(slowo) wyrzuci błąd kompilacji.

Aby to obejść, programiści stosują jedną z trzech metod:

Drabinę if-else if.

Mapowanie słów na liczby (np. używając std::map lub funkcji mieszającej).

Zamianę słowa na typ wyliczeniowy enum.

*/

#include <iostream>
#include <string>

using namespace std;

// Definiujemy typ wyliczeniowy (enum), który switch akceptuje bez problemu
enum Metoda {
    BITOWO,
    MODULO,
    WARUNKOWY,
    NIEZNANA
};

// Funkcja pomocnicza zamieniająca string na kod liczbowy z enuma
Metoda stringToEnum(string s) {
    if (s == "bitowo")     return BITOWO;
    if (s == "modulo")     return MODULO;
    if (s == "warunkowy")  return WARUNKOWY;
    return NIEZNANA;
}

int main() {
    int liczba;
    string wybor;

    cout << "Podaj liczbe: ";
    cin >> liczba;

    cout << "Wpisz metode (bitowo/modulo/warunkowy): ";
    cin >> wybor;

    // Tutaj realizujemy wymaganie zadania: uzywamy switch!
    // switch operuje na liczbach (enum), ktore dostarcza funkcja pomocnicza
    switch (stringToEnum(wybor)) {
        case BITOWO:
            cout << "Wynik (bitowo): " << (!(liczba & 1) ? "parzysta" : "nieparzysta") << endl;
            break;

        case MODULO:
            cout << "Wynik (modulo): " << (liczba % 2 == 0 ? "parzysta" : "nieparzysta") << endl;
            break;

        case WARUNKOWY:
            cout << "Wynik (warunkowy): " << (liczba % 2 == 0 ? "parzysta" : "nieparzysta") << endl;
            break;

        case NIEZNANA:
        default:
            cerr << "Blad: Niepoprawne slowo" << endl;
            break;
    }

    return 0;
}