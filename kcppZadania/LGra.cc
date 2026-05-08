#include <iostream>
#include <cstdlib>  // dla rand()
#include <ctime>    // dla time()
using namespace std;

int main() {
    srand(time(0));
    int zakres = 100; // Domyślny zakres
    int poziom;

    //Wybór poziomu trudności
    cout << "Wybierz poziom trudnosci:" << endl;
    cout << "1. Latwy (1-50)" << endl;
    cout << "2. Sredni (1-100)" << endl;
    cout << "3. Trudny (1-200)" << endl;
    cout << "Twoj wybor: ";
    cin >> poziom;

    if (poziom == 1) zakres = 50;
    else if (poziom == 3) zakres = 200;
    else zakres = 100;

    int wylosowana = rand() % zakres + 1;
    int proba, licznik = 0;
    const int LIMIT_PROB = 10;
    bool wygrana = false;

    cout << "\nZgadnij liczbe (1-" << zakres << "). Masz " << LIMIT_PROB << " prob!" << endl;

    //Główna pętla gry z limitem prób
    while (licznik < LIMIT_PROB) {
        cout << "Proba " << licznik + 1 << ": ";
        cin >> proba;
        licznik++;

        if (proba < wylosowana) {
            cout << "Za malo!" << endl;
        } else if (proba > wylosowana) {
            cout << "Za duzo!" << endl;
        } else {
            cout << "Brawo! Zgadles w " << licznik << " probach." << endl;
            wygrana = true;
            break;  
        }

        // Informacja o pozostałych próbach
        if (!wygrana && licznik < LIMIT_PROB) {
            cout << "Zostalo Ci " << LIMIT_PROB - licznik << " prob." << endl;
        }
    }

    //Sprawdzenie warunku przegranej
    if (!wygrana) {
        cout << "\nPrzykro mi, wyczerpales limit prob!" << endl;
        cout << "Prawidlowa liczba to: " << wylosowana << endl;
    }

    return 0;
}