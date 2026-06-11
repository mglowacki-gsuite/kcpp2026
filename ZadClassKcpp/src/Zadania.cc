#define _USE_MATH_DEFINES
#include "../include/Zadania.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


// ZADANIE 1: Struktury i konstruktory
struct Z1_Pojazd {
    string marka; string model; string kolor; int rok_produkcji; int ilosc_drzwi;
    Z1_Pojazd() { marka = "Nieznana"; model = "Brak"; kolor = "Brak"; rok_produkcji = 0; ilosc_drzwi = 0; }
    Z1_Pojazd(string m, string mod, string k, int rok, int drzwi) 
        : marka(m), model(mod), kolor(k), rok_produkcji(rok), ilosc_drzwi(drzwi) {}
};

void Zadanie1::wykonajZadanie() {
    cout << "\n--- ZADANIE 1: STRUKTURY ---" << endl;
    Z1_Pojazd Opel("Opel", "Corsa E", "granatowy", 2017, 5);
    Z1_Pojazd skoda("Skoda", "Octavia", "szary", 2012, 5);
    Z1_Pojazd testowy; 

    cout << "Konstruktor domyslny: " << testowy.marka << endl;
    cout << "Pojazd: " << skoda.marka << " " << skoda.model << ", Kolor: " << skoda.kolor << endl;
    
    Opel.kolor = "czarny metalik"; 
    cout << "Nowy kolor Opla: " << Opel.kolor << endl;
    
    Z1_Pojazd kopia = skoda; 
    cout << "Skopiowano: " << kopia.marka << endl;
}


// ZADANIE 2: Klasy Abstrakcyjne (Dawne Zadanie 5.6 - Obowiązkowe)
class Z2_Figura {
public:
    virtual double obliczPole() = 0; virtual double obliczObwod() = 0; virtual ~Z2_Figura() {}
};
class Z2_Kwadrat : public Z2_Figura {
    double a; public: Z2_Kwadrat(double bok) : a(bok) {}
    double obliczPole() override { return a * a; } double obliczObwod() override { return 4 * a; }
};
class Z2_Kolo : public Z2_Figura {
    double r; public: Z2_Kolo(double promien) : r(promien) {}
    double obliczPole() override { return M_PI * r * r; } double obliczObwod() override { return 2 * M_PI * r; }
    double Dystans(double x_metrow) { return sqrt(x_metrow / M_PI); }
};

void Zadanie2::wykonajZadanie() {
    cout << "\n--- ZADANIE 2: POLIMORFIZM I FIGURY ---" << endl;
    Z2_Figura *kwadrat = new Z2_Kwadrat(4.0);
    Z2_Kolo *kolo = new Z2_Kolo(2.5);

    cout << "Kwadrat - Pole: " << kwadrat->obliczPole() << ", Obwod: " << kwadrat->obliczObwod() << endl;
    cout << "Kolo - Pole: " << kolo->obliczPole() << endl;
    
    double x_metrow = 15.0;
    cout << "Dla wymogu " << x_metrow << "m^2/os, dystans wynosi: " << kolo->Dystans(x_metrow) << " metra." << endl;

    delete kwadrat; delete kolo;
}


// ZADANIE 3: Petle i liczby nieparzyste / podzielne przez 7
void Zadanie3::wykonajZadanie() {
    cout << "\n--- ZADANIE 3: PETLE (Nieparzyste i modulo 7) ---" << endl;
    int n; cout << "Podaj liczbe n: "; cin >> n;
    cout << "Liczby nieparzyste: ";
    for (int i = 1; i <= n; i++) if (i % 2 != 0) cout << i << " ";
    cout << "\nLiczby podzielne przez 7: ";
    for (int i = 1; i <= n; i++) if (i % 7 == 0) cout << i << " ";
    cout << endl;
}

// ZADANIE 4: Suma silni
void Zadanie4::wykonajZadanie() {
    cout << "\n--- ZADANIE 4: SUMA SILNI ---" << endl;
    int n; cout << "Podaj liczbe n: "; cin >> n;
    if (n < 0) { cout << "Blad: N ujemne!" << endl; return; }
    
    long long sumaSilni = 0;
    for (int k = 1; k <= n; k++) {
        long long akt = 1;
        for (int i = 1; i <= k; i++) akt *= i;
        sumaSilni += akt;
    }
    cout << "Suma silni do " << n << " wynosi: " << sumaSilni << endl;
}


// ZADANIE 5: Sumowanie wartosci dodatnich
void Zadanie5::wykonajZadanie() {
    cout << "\n--- ZADANIE 5: SUMA DODATNICH (0 konczy) ---" << endl;
    int liczba, suma = 0, licznik = 0;
    cout << "Podaj liczbe: "; cin >> liczba;
    while (liczba != 0) {
        if (liczba > 0) { suma += liczba; licznik++; } 
        else { cout << "Pominieto: ujemna." << endl; }
        cin >> liczba;
    }
    cout << "Suma: " << suma << " | Ilosc liczb: " << licznik << endl;
}


// ZADANIE 6: Zgadnij liczbe (Gra)
void Zadanie6::wykonajZadanie() {
    cout << "\n--- ZADANIE 6: ZGADNIJ LICZBE ---" << endl;
    srand(time(0));
    int poziom, zakres = 100;
    cout << "1. Latwy (50) | 2. Sredni (100) | 3. Trudny (200): "; cin >> poziom;
    if (poziom == 1) zakres = 50; else if (poziom == 3) zakres = 200;
    
    int wylosowana = rand() % zakres + 1, proba, licznik = 0;
    while (licznik < 10) {
        cout << "Proba " << ++licznik << ": "; cin >> proba;
        if (proba == wylosowana) { cout << "Wygrana!" << endl; return; }
        cout << (proba < wylosowana ? "Za malo!" : "Za duzo!") << endl;
    }
    cout << "Przegrana. Liczba to: " << wylosowana << endl;
}


// ZADANIE 7: Celsjusz na Fahrenheit
void Zadanie7::wykonajZadanie() {
    cout << "\n--- ZADANIE 7: TEMPERATURY ---" << endl;
    cout << left << setw(10) << "Celsjusz" << setw(12) << "Fahrenheit" << endl;
    cout << fixed << setprecision(2);
    for (int c = -10; c <= 10; c += 5) {
        cout << right << setw(5) << c << setw(12) << (c * 9.0 / 5.0 + 32.0) << endl;
    }
}


// ZADANIE 8: Formatowanie stalych matematycznych
void Zadanie8::wykonajZadanie() {
    cout << "\n--- ZADANIE 8: FORMATOWANIE ---" << endl;
    double PI = 3.141592;
    cout << left << setw(15) << "Stala" << setw(20) << "Domyslnie" << setw(20) << "Naukowa" << endl;
    cout << left << setw(15) << "PI";
    cout.unsetf(ios::floatfield); cout << setw(20) << setprecision(6) << PI;
    cout << scientific << setw(20) << setprecision(6) << PI << endl;
}


// ZADANIE 9: Operacje bitowe
bool Zadanie9::czyParzystaBitowo(int n) { return !(n & 1); }
bool Zadanie9::czyParzystaModulo(int n) { return (n % 2 == 0); }
void Zadanie9::wyswietlWynikWarunkowy(int n) { cout << (n % 2 == 0 ? "Parzysta" : "Nieparzysta") << endl; }

void Zadanie9::wykonajZadanie() {
    cout << "\n--- ZADANIE 9: PARZYSTOSC (Bity i Modulo) ---" << endl;
    int liczba; cout << "Podaj liczbe: "; cin >> liczba;
    cout << "Bitowo: " << (czyParzystaBitowo(liczba) ? "Tak" : "Nie") << endl;
    cout << "Modulo: " << (czyParzystaModulo(liczba) ? "Tak" : "Nie") << endl;
    cout << "Ternary: "; wyswietlWynikWarunkowy(liczba);
}


// ZADANIE 10: Petle i instrukcje skoku
void Zadanie10::funkcjaWhile() { cout << "Uruchomiono While..." << endl; }
void Zadanie10::funkcjaDoWhile() { cout << "Uruchomiono Do-While..." << endl; }
void Zadanie10::funkcjaFor() { cout << "Uruchomiono For..." << endl; }

void Zadanie10::wykonajZadanie() {
    cout << "\n--- ZADANIE 10: ZAAWANSOWANE PETLE ---" << endl;
    funkcjaWhile(); funkcjaDoWhile(); funkcjaFor();
    cout << "Podfunkcje wywolane pomyslnie." << endl;
}