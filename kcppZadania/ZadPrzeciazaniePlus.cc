#include <iostream>

class Punkt {
public:
    double x, y;

    // Konstruktor
    Punkt(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    // PRZECIĄŻENIE OPERATORA +
    // Zwraca nowy obiekt typu Punkt, przyjmuje inny Punkt jako argument
    Punkt operator+(const Punkt& drugi) {
        Punkt wynik;
        wynik.x = this->x + drugi.x; // dodajemy x do x
        wynik.y = this->y + drugi.y; // dodajemy y do y
        return wynik;
    }
};

int main() {
    Punkt p1(2.0, 3.0);
    Punkt p2(1.0, 4.0);

    Punkt p3 = p1 + p2; 

    std::cout << "Punkt 1: (" << p1.x << ", " << p1.y << ")" << std::endl;
    std::cout << "Punkt 2: (" << p2.x << ", " << p2.y << ")" << std::endl;
    std::cout << "Wynik (+): (" << p3.x << ", " << p3.y << ")" << std::endl;

    return 0;
}