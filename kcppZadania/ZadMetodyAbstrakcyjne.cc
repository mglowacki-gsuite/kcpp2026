#include <iostream>
#include <cmath> // Potrzebne do M_PI (pi) oraz sqrt() 

using namespace std;

class Figura {
public:
    // Czyste funkcje wirtualne (metody abstrakcyjne)
    virtual double obliczPole() = 0;
    virtual double obliczObwod() = 0;

    // Wirtualny destruktor, wymagany, gdy usuwamy obiekty przez wskaźnik klasy bazowej
    virtual ~Figura() {}
};

class Kwadrat : public Figura {
private:
    double a;
public:
    Kwadrat(double bok) : a(bok) {}

    double obliczPole() { return a * a; }
    double obliczObwod() { return 4 * a; }
};

class Trojkat : public Figura {
private:
    double a; // Dla uproszczenia: trójkąt równoboczny
public:
    Trojkat(double bok) : a(bok) {}

    double obliczPole() { return (a * a * sqrt(3)) / 4.0; }
    double obliczObwod() { return 3 * a; }
};

class Prostokat : public Figura {
private:
    double a, b;
public:
    Prostokat(double bokA, double bokB) : a(bokA), b(bokB) {}

    double obliczPole() { return a * b; }
    double obliczObwod() { return 2 * (a + b); }
};

class Kolo : public Figura {
private:
    double r;
public:
    Kolo(double promien) : r(promien) {}

    double obliczPole() { return M_PI * r * r; }
    double obliczObwod() { return 2 * M_PI * r; }

    // Dodatkowa metoda dla klasy Kolo
    double Dystans(double x_metrow) {
        // r = sqrt(Pole / pi)
        return sqrt(x_metrow / M_PI);
    }
};

int main() {
    // Tworzenie obiektów polimorficznych za pomocą wskaźników na podstawie pliku bazowego
    Figura *objKwadrat = new Kwadrat(4.0);
    Figura *objTrojkat = new Trojkat(6.0);
    Figura *objProstokat = new Prostokat(3.0, 5.0);
    
    // Dla koła tworzymy wskaźnik typu Kolo*, aby mieć dostęp do metody Dystans
    Kolo *objKolo = new Kolo(2.5);

    // Wywołania i wyświetlenie wyników
    cout << "Kwadrat (bok 4):" << endl;
    cout << "Pole: " << objKwadrat->obliczPole() << endl;
    cout << "Obwod: " << objKwadrat->obliczObwod() << "\n" << endl;

    cout << "Trojkat rownoboczny (bok 6):" << endl;
    cout << "Pole: " << objTrojkat->obliczPole() << endl;
    cout << "-Obwod: " << objTrojkat->obliczObwod() << "\n" << endl;

    cout << "Prostokat (boki 3x5):" << endl;
    cout << "Pole: " << objProstokat->obliczPole() << endl;
    cout << "Obwod: " << objProstokat->obliczObwod() << "\n" << endl;

    cout << "Kolo (promien 2.5):" << endl;
    cout << "Pole: " << objKolo->obliczPole() << endl;
    cout << "Obwod: " << objKolo->obliczObwod() << "\n" << endl;

   
    cout << "test funkcji dystans dla kola" << endl;
    double x_metrow = 15.0; // Rządowe X metrów kwadratowych na osobę
    double bezpieczny_promien = objKolo->Dystans(x_metrow);

    cout << "Jesli rzad wymaga " << x_metrow << " m^2 na osobe," << endl;
    cout << "to kolejna osoba moze znalezc sie w odleglosci (promieniu): " 
         << bezpieczny_promien << " metra." << endl;

    // Czyszczenie pamięci
    delete objKwadrat;
    delete objTrojkat;
    delete objProstokat;
    delete objKolo;

    return 0;
}