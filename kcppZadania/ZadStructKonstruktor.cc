#include <iostream>
#include <string>

struct Sensor {
    std::string typ;
    int id;
    double napiecie_pracy;

    // 1. Domyślny konstruktor z inicjalizacją wewnątrz klamer
    Sensor() {
        typ = "Nieznany"; 
        id = 0;
        napiecie_pracy = 5.0;
        std::cout << "[Struktura] Wywolano konstruktor domyslny (standardowy)." << std::endl;
    }

    // 2. Konstruktor z argumentami inicjalizacja za pomocą listy inicjalizacyjnej
    Sensor(std::string t, int i, double np) : typ(t), id(i), napiecie_pracy(np) {
        std::cout << "[Struktura] Wywolano konstruktor z argumentami (lista inicjalizacyjna)." << std::endl;
    }

    // 3. Domyślny destruktor
    ~Sensor() {
        std::cout << "[Struktura] Wywolano domyslny destruktor dla sensora ID: " << id << std::endl;
    }

    // Metoda pomocnicza
    void wyswietl() const {
        std::cout << "-> Sensor: " << typ << " | ID: " << id << " | Napiecie: " << napiecie_pracy << " V\n" << std::endl;
    }
};

int main() {
    
    // Test konstruktora domyślnego
    Sensor s1;
    s1.wyswietl();

    // Test konstruktora z argumentami (lista inicjalizacyjna)
    Sensor s2("Cisnienia", 777, 3.3);
    s2.wyswietl();

    std::cout << "dzialanie destruktora" << std::endl;
    return 0;
}