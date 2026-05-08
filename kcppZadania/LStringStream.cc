#include <iostream>
#include <sstream> 
#include <string>

using namespace std;

int main() {
    // Konwersja i składanie napisu
    stringstream ss;
    string imie = "Jan";
    int wiek = 25;
    double wzrost = 1.85;

    // Wrzucamy dane do strumienia tak jak do cout
    ss << "Uzytkownik: " << imie << ", Wiek: " << wiek << ", Wzrost: " << wzrost << "m";

    // Wyciągamy gotowy napis metodą .str()
    string sformatowanyTekst = ss.str();
    cout << "Wynik skladania: " << sformatowanyTekst << endl;


    // Parsowanie (wyciąganie danych)
    // Czyścimy strumień i ładujemy nowy napis
    ss.str(""); // Czyści zawartość bufora
    ss.clear(); // Czyści flagi błędów
    
    string daneLogowania = "Admin 1234 99.5";
    ss << daneLogowania;

    string login;
    int kod;
    float wynik;

    // Wyciągamy dane ze strumienia tak jak z cin
    ss >> login >> kod >> wynik;

    cout << "\nWynik parsowania:" << endl;
    cout << "Login: " << login << endl;
    cout << "Kod:   " << kod << endl;
    cout << "Wynik: " << wynik << endl;

    return 0;
}