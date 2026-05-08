/**
 * Wyjaśnienie kierunku adresowania:
 * W architekturze systemów x86/x64 stos (miejsce gdzie lądują zmienne lokalne a, b, c) 
 * rośnie zazwyczaj w dół pamięci. 
 * Oznacza to, że pierwsza zmienna (a) ma najwyższy adres, a kolejne (b, c) coraz niższe.
 * * Dlatego w tym programie:
 * 1. &a + 1 przesuwa nas pod adres WYŻSZY (tam gdzie w pamięci "wcześniej" leżało b).
 * 2. &c - 1 przesuwa nas pod adres NIŻSZY.
 * * UWAGA: To zachowanie zależy od kompilatora i optymalizacji. Kompilator może 
 * ułożyć zmienne w innej kolejności, jeśli uzna to za wydajniejsze.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;

// Pomocnicza funkcja do konwersji (zastępuje brakujące LConversion.h)
unsigned long hextodec(string hex) {
    unsigned long result = 0;
    for (unsigned int i = 0; i < hex.length(); i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            result += (hex[i] - '0') * pow(16, hex.length() - i - 1);
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result += (hex[i] - 'A' + 10) * pow(16, hex.length() - i - 1);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result += (hex[i] - 'a' + 10) * pow(16, hex.length() - i - 1);
        }
    }
    return result;
}

int main() {
    int a = 0, b = 0, c = 0;
    
    // Używamy uintptr_t zamiast unsigned long
    uintptr_t addr_a = reinterpret_cast<uintptr_t>(&a);
    uintptr_t addr_b = reinterpret_cast<uintptr_t>(&b);
    uintptr_t addr_c = reinterpret_cast<uintptr_t>(&c);

    cout << "Adres A: " << &a << " dec: " << addr_a << endl;
    cout << "Adres B: " << &b << " dec: " << addr_b << endl;
    cout << "Adres C: " << &c << " dec: " << addr_c << endl;

    // ... reszta kodu ...
    return 0;
}