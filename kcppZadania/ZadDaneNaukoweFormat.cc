#include <iostream>
#include <iomanip>
#include <cmath> // Dla M_PI

using namespace std;

int main() {
    // Definicje stałych
    const double PI = 3.141592653589793;
    const double E = 2.718281828459045;
    const double PHI = 1.618033988749895;

    // Nagłówki - wyrównanie "na oko" spacjami wewnątrz setw, aby były na środku
    cout << left << setw(15) << "Stala" 
         << setw(20) << "Wartosc (domyslnie)" 
         << setw(20) << "Notacja stala" 
         << setw(20) << "Notacja naukowa" << endl;
    
    cout << left << setw(15) << "--------" 
         << setw(20) << "-----------------" 
         << setw(20) << "-------------" 
         << setw(20) << "--------------" << endl;

    // Funkcja pomocnicza do wypisania jednego wiersza
    auto wypiszWiersz = [](string nazwa, double wartosc) {
        cout << left << setw(15) << nazwa;

        // 1. Format domyślny (resetujemy flagi)
        cout.unsetf(ios::floatfield); 
        cout << setw(20) << setprecision(6) << wartosc;

        // 2. Notacja stała (fixed)
        cout << fixed << setw(20) << setprecision(6) << wartosc;

        // 3. Notacja naukowa (scientific)
        cout << scientific << setw(20) << setprecision(6) << wartosc;
        
        cout << endl;
    };

    // Wypisujemy dane
    wypiszWiersz("Pi", PI);
    wypiszWiersz("e", E);
    wypiszWiersz("Zloty podzial", PHI);

    return 0;
}