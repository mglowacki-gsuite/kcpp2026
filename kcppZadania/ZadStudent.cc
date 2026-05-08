#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // dla sort, find_if

using namespace std;

// Struktura przechowująca dane studenta
struct Student {
    string imie;
    string nazwisko;
    int indeks;

    // Przeciążenie operatora wypisywania dla wygody
    void wyswietl() const {
        cout << "Indeks: " << indeks << " | " << nazwisko << " " << imie << endl;
    }
};

// Funkcja pomocnicza do sprawdzania, czy indeks jest unikalny
bool czyIndeksUnikalny(const vector<Student>& baza, int nr) {
    for (const auto& s : baza) {
        if (s.indeks == nr) return false;
    }
    return true;
}

int main() {
    vector<Student> baza;
    int wybor;

    do {
        cout << "\n--- SYSTEM BAZY STUDENTOW ---" << endl;
        cout << "1. Dodaj studenta" << endl;
        cout << "2. Usun studenta (po indeksie)" << endl;
        cout << "3. Wyswietl liste" << endl;
        cout << "4. Sortuj liste (po nazwisku)" << endl;
        cout << "5. Sprawdz, czy student istnieje" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if (wybor == 1) {
            Student nowy;
            cout << "Podaj imie: "; cin >> nowy.imie;
            cout << "Podaj nazwisko: "; cin >> nowy.nazwisko;
            cout << "Podaj nr indeksu: "; cin >> nowy.indeks;

            // Walidacja
            if (nowy.imie.empty() || nowy.nazwisko.empty()) {
                cout << "Blad: Dane nie moga byc puste!" << endl;
            } else if (!czyIndeksUnikalny(baza, nowy.indeks)) {
                cout << "Blad: Student o takim indeksie juz istnieje!" << endl;
            } else {
                baza.push_back(nowy);
                cout << "Dodano studenta." << endl;
            }

        } else if (wybor == 2) {
            int nr;
            cout << "Podaj indeks do usuniecia: "; cin >> nr;
            
            auto it = remove_if(baza.begin(), baza.end(), [nr](const Student& s) {
                return s.indeks == nr;
            });
            
            if (it != baza.end()) {
                baza.erase(it, baza.end());
                cout << "Usunieto studenta." << endl;
            } else {
                cout << "Nie znaleziono studenta o takim indeksie." << endl;
            }

        } else if (wybor == 3) {
            if (baza.empty()) cout << "Baza jest pusta." << endl;
            for (const auto& s : baza) s.wyswietl();

        } else if (wybor == 4) {
            // Sortowanie alfabetyczne po nazwisku
            sort(baza.begin(), baza.end(), [](const Student& a, const Student& b) {
                return a.nazwisko < b.nazwisko;
            });
            cout << "Lista posortowana." << endl;

        } else if (wybor == 5) {
            string szukane;
            cout << "Podaj nazwisko do sprawdzenia: "; cin >> szukane;
            bool znaleziono = false;
            for (const auto& s : baza) {
                if (s.nazwisko == szukane) {
                    cout << "Student istnieje: "; s.wyswietl();
                    znaleziono = true;
                }
            }
            if (!znaleziono) cout << "Nie znaleziono studenta o nazwisku " << szukane << endl;
        }

    } while (wybor != 0);

    return 0;
}