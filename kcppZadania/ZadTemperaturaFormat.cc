#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    // Nagłówek tabeli
    cout << left << setw(10) << "Celsjusz" << setw(12) << "Fahrenheit" << endl;
    cout << left << setw(10) << "-------" << setw(12) << "----------" << endl;

    // Ustawienie formatu dla kolumny Fahrenheit
    cout << fixed << setprecision(2);

    // Pętla od -10 do 10 co 5 stopni
    for (int c = -10; c <= 10; c += 5) {
        double f = c * 9.0 / 5.0 + 32.0;

        // Wypisywanie wartości
        cout << right << setw(5) << c; 
        
        // Druga kolumna z odpowiednim odstępem
        cout << right << setw(12) << f << endl;
    }

    return 0;
}