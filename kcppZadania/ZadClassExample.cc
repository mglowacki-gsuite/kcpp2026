#include <iostream>
#include <string>

using namespace std;

// DEFINICJA KLASY (wcześniej w KviCar.h)
class KviCar {
public:
    /** Konstruktor domyślny **/
    KviCar();

    /** Destruktor **/
    ~KviCar();

    /** Modyfikatory (Settery) - zdefiniowane wewnątrz klasy **/
    void SetPlate(int rplate) { fPlate = rplate; }
    void SetFakePlate(int fplate) { fFakePlate = fplate; }
    void SetColor(string color) { fColor = color; } // Zmieniono na string dla czytelności

    /** Akcesory (Gettery) - zdefiniowane wewnątrz klasy **/
    int GetPlate() { return fPlate; }
    int GetFakePlate() { return fFakePlate; }
    string GetColor() { return fColor; }

    /** Metoda wypisująca dane **/
    void Print();

private:
    int fPlate;
    int fFakePlate;
    string fColor;
};


// implementowanie metod z pliku KviCar.cc

KviCar::KviCar() {
    fPlate = 0;
    fFakePlate = 0;
    fColor = "Unknown";
    cout << "INFO: Obiekt KviCar został utworzony." << endl;
}

KviCar::~KviCar() {
    cout << "INFO: Obiekt KviCar został usunięty." << endl;
}

void KviCar::Print() {
    cout << "---------------------------------------" << endl;
    cout << "Wszystko o tym samochodzie:" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Nr tablicy:       " << fPlate << endl;
    cout << "Nr fejk tablicy:  " << fFakePlate << endl;
    cout << "Kolor:            " << fColor << endl;
    cout << "---------------------------------------\n" << endl;
}

int main() {
    // 1. Tworzenie obiektu (wywoła konstruktor)
    KviCar mojSamochod;

    // 2. Ustawianie wartości za pomocą setterów
    mojSamochod.SetPlate(12345);
    mojSamochod.SetFakePlate(99999);
    mojSamochod.SetColor("Czerwony");

    // 3. Wyświetlanie informacji
    mojSamochod.Print();

    // 4. Przykład użycia gettera
    cout << "Sprawdzam kolor przez getter: " << mojSamochod.GetColor() << endl;
    cout << endl;

    // Po zakończeniu funkcji main, obiekt 'mojSamochod' wyjdzie poza zakres
    // i automatycznie wywoła się destruktor.
    return 0;
}