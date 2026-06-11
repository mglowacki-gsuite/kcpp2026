#include <iostream>
#include <string>

class Robot {
private:
    std::string nazwa;
    int seria;
    double waga;

public:
    // 1. Domyślny konstruktor (standardową inicjalizacją wewnątrz klamerek
    Robot() {
        nazwa = "Model Bazowy"; // standardowe przypisanie
        seria = 1000;
        waga = 15.5;
        std::cout << "[Klasa] Wywolano konstruktor domyslny (standardowy)." << std::endl;
    }

    // 2. Konstruktor z argumentami, inicjalizacja za pomocą listy inicjalizacyjnej
    Robot(std::string n, int s, double w) : nazwa(n), seria(s), waga(w) {
        std::cout << "[Klasa] Wywolano konstruktor z argumentami (lista inicjalizacyjna)." << std::endl;
    }

    // 3. Domyślny destruktor 
    ~Robot() {
        std::cout << "[Klasa] Wywolano domyslny destruktor dla: " << nazwa << std::endl;
    }

    // Metoda do wyswietlenia stanu
    void wyswietl() const {
        std::cout << "-> Robot: " << nazwa << " | Seria: " << seria << " | Waga: " << waga << " kg\n" << std::endl;
    }
};

int main() {

    // Test konstruktora domyślnego
    Robot r1;
    r1.wyswietl();

    // Test konstruktora z argumentami (lista inicjalizacyjna)
    Robot r2("KompilatorX", 2026, 84.2);
    r2.wyswietl();

    std::cout << " dzialanie destruktora" << std::endl;
    return 0;
}