#include <iostream>
#include <string>
#include <vector>
#include <fstream>// Biblioteka do obsługi plików
using namespace std;

void DemonstracjaWypisywania() {
    // Standardowe wypisywanie na ekran
    cout << "[INFO] Program rozpoczal dzialanie poprawnie." << endl;
    cout << "To jest standardowy strumien wyjsciowy (cout)." << endl;

    // Wypisywanie do strumienia bledow. Wizualnie w konsoli moze wygladac tak samo, ale system operacyjnyrozroznia te dwa kanaly.
    cerr << "[ERROR] To jest komunikat bledu wyslany do cerr!" << endl;
    cerr << "Bledy sa wysylane natychmiastowo, bez buforowania." << endl;
}

int main() {
     DemonstracjaWypisywania();

    // komunikacji z uzytkownikiem przez cin
    string imie;
    cout << "\nPodaj swoje imie: ";
    if (!(cin >> imie)) {
        // Jesli cin zawiedzie, uzywamy cerr do powiadomienia o problemie
        cerr << "[FATAL] Blad odczytu danych z klawiatury!" << endl;
        return 1;
    }

    cout << "Witaj " << imie << "! Twoje dane zostaly przetworzone." << endl;


    string nazwaPliku = "dane.txt";

    // wypisywanie na ekran orazMateusz bledy
    cout << "[cout] Rozpoczynamy zapis do pliku..." << endl;
    cerr << "[cerr] To jest komunikat bledu (jesli plik sie nie otworzy, tu go wypiszemy)." << endl;

    // zapis do pliku (ofstream - Output File Stream)
    ofstream plikWyjsciowy(nazwaPliku);

    if (plikWyjsciowy.is_open()) {
        plikWyjsciowy << "To jest pierwsza linia w pliku.\n";
        plikWyjsciowy << "To jest druga linia.\n";
        plikWyjsciowy << "To jest moje imie: " <<imie <<"\n";
        plikWyjsciowy << 123.45 << " zapis liczby.\n";
        
        plikWyjsciowy.close(); //zamknmiecie pliku po zakonczeniu pracy
        cout << "[cout] Dane zostaly zapisane do: " << nazwaPliku << endl;
    } else {
        cerr << "[cerr] BLAD: Nie udalo sie otworzyc pliku do zapisu!" << endl;
    }

    // odczyt z pliku (ifstream - Input File Stream)
    ifstream plikWejsciowy(nazwaPliku);
    string linia;

    if (plikWejsciowy.is_open()) {
        cout << "\n--- Zawartosc pliku " << nazwaPliku << " ---" << endl;
        
        // Czytamy plik linia po linii
        while (getline(plikWejsciowy, linia)) {
            cout << "Odczytano: " << linia << endl;
        }
        
        plikWejsciowy.close();
    } else {
        cerr << "[cerr] BLAD: Nie udalo sie otworzyc pliku do odczytu!" << endl;
    }

    return 0;
}