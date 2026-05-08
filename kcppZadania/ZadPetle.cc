#include <iostream>

using namespace std;

// (a) Pętla while: pokazuje różnicę między i++ a ++i oraz użycie 'continue'
void funkcjaWhile() {
    cout << "--- Funkcja (a): while ---" << endl;
    
    int i = 0;
    cout << "Inkrementacja i++ (uzycie i, potem zwiekszenie):" << endl;
    while (i < 3) {
        cout << " Wartosc i: " << i++; // Wypisze 0, 1, 2
    }
    
    cout << "\nInkrementacja ++i (zwiekszenie, potem uzycie):" << endl;
    i = 0;
    while (i < 3) {
        cout << " Wartosc i: " << ++i; // Wypisze 1, 2, 3
    }

    cout << "\nUzycie continue (pominiecie liczby 2):" << endl;
    i = 0;
    while (i < 5) {
        i++;
        if (i == 2) continue; // Przeskakuje resztę pętli dla i=2
        cout << " " << i;
    }
    cout << endl << endl;
}

// (b) Pętla do-while: gwarantuje przynajmniej jedno wykonanie
void funkcjaDoWhile() {
    cout << "--- Funkcja (b): do-while ---" << endl;
    
    int i = 10;
    cout << "Warunek (i < 5) jest falszywy na starcie, ale:" << endl;
    do {
        cout << " Wykonano chociaz raz. i = " << i << endl;
        i++;
    } while (i < 5);

    cout << "Uzycie break (wyjscie z petli przy i=3):" << endl;
    i = 0;
    do {
        if (i == 3) break;
        cout << " " << i;
        i++;
    } while (i < 10);
    cout << endl << endl;
}

// (c) Pętla for
void funkcjaFor() {
    cout << "--- Funkcja (c): for ---" << endl;
    
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            cout << " Osiagnieto 5. Przerywam funkcje uzywajac 'return'." << endl;
            return; // Konczy cala funkcje, nie tylko petle
        }
        cout << " " << i;
    }
    // Ten kod nigdy sie nie wykona przez return powyzej
    cout << "To sie nie wyswietli." << endl;
}

int main() {
    funkcjaWhile();
    funkcjaDoWhile();
    funkcjaFor();
    
    return 0;
}