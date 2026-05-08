#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Nagłówek
    cout << "|" << left  << setw(15) << "Nazwa" 
         << "|" << right << setw(8)  << "Cena " 
         << "|" << right << setw(7)  << "Ilosc" << "|" << endl;

    cout << "|---------------|--------|-------|" << endl;

    cout << fixed << setprecision(2);

    // Wiersz 1
    cout << "|" << left  << setw(15) << "Chleb" 
         << "|" << right << setw(8)  << 4.99 
         << "|" << right << setw(7)  << 5 << "|" << endl;

    // Wiersz 2
    cout << "|" << left  << setw(15) << "Mleko" 
         << "|" << right << setw(8)  << 3.20 
         << "|" << right << setw(7)  << 10 << "|" << endl;

    // Wiersz 3
    cout << "|" << left  << setw(15) << "Jajka (10 szt)" 
         << "|" << right << setw(8)  << 8.50 
         << "|" << right << setw(7)  << 3 << "|" << endl;

    return 0;
}