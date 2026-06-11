#include <iostream>
#include <string>

struct Pojazd {
    std::string marka;
    std::string model;
    std::string kolor;
    int rok_produkcji;
    int ilosc_drzwi;

    // Konstruktor domyślny (standardowy)
    Pojazd() {
        marka = "Nieznana";
        model = "Brak";
        kolor = "Brak";
        rok_produkcji = 0;
        ilosc_drzwi = 0;
    }

    // - czy można stworzyć konstruktor (inicjalizacja wartości poczatkowych - standard, lista inicjalizacyjna)
    // Konstruktor z listą inicjalizacyjną:
    Pojazd(std::string m, std::string mod, std::string k, int rok, int drzwi) 
        : marka(m), model(mod), kolor(k), rok_produkcji(rok), ilosc_drzwi(drzwi) {
    
    }
};

// Obiekt globalny
Pojazd Opel = {"Opel", "Corsa E", "granatowy", 2017, 5};


int main() {
    
    // obiekty lokalne
    // konstuktor z listą inicjalizacyjną:
    Pojazd skoda("Skoda", "Octavia", "szary", 2012, 5);
    
    // Użycie konstruktora domyślnego:
    Pojazd testowy_samochod; 

    std::cout << "Konstruktor domyslny " << std::endl;
    std::cout << "Marka auta testowego: " << testowy_samochod.marka << std::endl;


    std::cout << "Odczyt wartosci] " << std::endl;
    std::cout << "Wybrany pojazd to: " << skoda.marka << " " << skoda.model << std::endl;
    std::cout << "Kolor: " << skoda.kolor << ", Rok: " << skoda.rok_produkcji << std::endl;


    std::cout << "Zmiana wartosci " << std::endl;
    std::cout << "Stary kolor Opla: " << Opel.kolor << std::endl;
    
    Opel.kolor = "czarny metalik"; 
    Opel.rok_produkcji = 2018;     
    
    std::cout << "Nowy kolor Opla: " << Opel.kolor << std::endl;
    std::cout << "Zaktualizowany rok produkcji: " << Opel.rok_produkcji << std::endl;


    std::cout << "\n Kopiowanie struktur " << std::endl;
    Pojazd kopia_skody;
    kopia_skody = skoda; 
    
    std::cout << "Dane skopiowanego auta: " << kopia_skody.marka << " " << kopia_skody.model << std::endl;

    return 0;
}