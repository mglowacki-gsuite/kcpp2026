/*
Czy klasa A w tym samym momencie może być także zaprzyjaźniona z klasą B?
Tak, jak najbardziej może. Choć cytat z GeeksforGeeks słusznie zauważa, że przyjaźń nie jest automatycznie wzajemna (jeśli B jest przyjacielem A, 
to A nie staje się automatycznie przyjacielem B), to nic nie stoi na przeszkodzie, abyśmy tę wzajemność jawnie zadeklarowali.
Jeśli klasa A zadeklaruje, że przyjaźni się z B, a klasa B zadeklaruje, że przyjaźni się z A, 
wtedy obie klasy uzyskają pełny, wzajemny dostęp do swoich sekcji prywatnych (private). 
Wymaga to jedynie zastosowania tzw. deklaracji zapowiadającej (forward declaration), aby kompilator wiedział o istnieniu drugiej klasy.
*/

#include <iostream>
#include <string>

// Deklaracja zapowiadająca 
class KlasaB;


class KlasaA {
private:
    std::string sekretA = "prywatne dane Klasy A";

public:
    // Deklaracja przyjaźni: Klasa B staje się przyjacielem Klasy A
    friend class KlasaB;

    void pokazSekretKlasyB(const KlasaB& obiektB); 
};


class KlasaB {
private:
    std::string sekretB = "prywatne dane Klasy B";

public:
    // Wzajemna przyjaźń: Klasa A staje się przyjacielem Klasy B
    friend class KlasaA;

    // Metoda Klasy B odczytująca prywatne dane Klasy A
    void pokazSekretKlasyA(const KlasaA& obiektA) {
        std::cout << "[Klasa B] Dostep do Klasy A: " << obiektA.sekretA << std::endl;
    }
};

// Definicja metody Klasy A po pełnym zadeklarowaniu Klasy B
void KlasaA::pokazSekretKlasyB(const KlasaB& obiektB) {
    std::cout << "[Klasa A] Dostep do Klasy B: " << obiektB.sekretB << std::endl;
}

int main() {
    std::cout << "Test przyjaźni" << std::endl;

    KlasaA obiektA;
    KlasaB obiektB;

    // Test przyjaźni: Klasa B odczytuje prywatne dane Klasy A
    obiektB.pokazSekretKlasyA(obiektA);

    // Test wzajemnej przyjaźni: Klasa A odczytuje prywatne dane Klasy B
    obiektA.pokazSekretKlasyB(obiektB);

    return 0;
}