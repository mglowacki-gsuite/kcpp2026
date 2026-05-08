#include <iostream>

using namespace std;

void Funkcja1() {
    int tab[] = {10, 20, 30};
    int* p = tab;

    cout << "--- Funkcja 1: Analiza operatorow ---" << endl;
    cout << "Start: *p = " << *p << " (adres: " << p << ")" << endl;

    p++;      // Przesuwa wskaźnik na następny element (teraz wskazuje na 20)
    ++p;      // Przesuwa wskaźnik na następny element (teraz wskazuje na 30)
    cout << "Po p++ i ++p: *p = " << *p << endl;

    p = tab;  // Reset na 10
    ++*p;     // Pre-inkrementacja WARTOŚCI: 10 staje się 11
    ++(*p);   // To samo co wyżej: 11 staje się 12
    ++*(p);   // To samo co wyżej: 12 staje się 13
    cout << "Po ++*p, ++(*p), ++*(p): tab[0] = " << tab[0] << endl;

    // Najciekawsze kombinacje:
    int x = *p++; // Bierze wartość (13), a POTEM przesuwa wskaźnik na tab[1]
    cout << "Po x = *p++: x = " << x << ", teraz *p = " << *p << endl;

    (*p)++;       // Zwiększa WARTOŚĆ pod p (20 staje się 21), wskaźnik stoi w miejscu
    cout << "Po (*p)++: tab[1] = " << tab[1] << endl;

    int y = *(p)++; // Bierze wartość (21), a POTEM przesuwa wskaźnik na tab[2]
    cout << "Po y = *(p)++: y = " << y << ", teraz *p = " << *p << endl;

    int z = *++p;   // NAJPIERW przesuwa wskaźnik (poza tablicę!), potem bierze wartość
    // Uwaga: *++p na końcu tablicy to niebezpieczna operacja (UB)
    
    // Reset dla czytelności kolejnych dwóch:
    p = tab;
    int m = *++p;   // Przesuwa na tab[1] (21) i zwraca 21
    int n = *(++p); // Przesuwa na tab[2] (30) i zwraca 30
    cout << "Po *++p: " << m << ", po *(++p): " << n << endl;
}

void Funkcja2() {
    int a = 0, b = 0, c = 0;
    int *p;

    cout << "\n--- Funkcja 2: Sekwencja A, B, C ---" << endl;

    cout << "1.  A, B, C: " << a << "  " << b << "  " << c << endl;

    b = 10;
    cout << "2.  A, B, C: " << a << "  " << b << "  " << c << endl;

    p = &c; *p = 20;
    cout << "3.  A, B, C: " << a << "  " << b << "  " << c << endl;

    p = &b; *p = 30;
    cout << "4.  A, B, C: " << a << "  " << b << "  " << c << endl;

    p = &a; *p = 40;
    cout << "5.  A, B, C: " << a << "  " << b << "  " << c << endl;

    // Używamy błędu adresowania (zakładając układ stosu jak w Zad 3.7)
    // Jeśli b leży 'nad' a:
    *(&a + 1) = 50; 
    cout << "6.  A, B, C: " << a << "  " << b << "  " << c << endl;

    // Jeśli c leży 'nad' b:
    *(&b + 1) = 60;
    cout << "7.  A, B, C: " << a << "  " << b << "  " << c << endl;

    p = &b; *p = 70;
    cout << "8.  A, B, C: " << a << "  " << b << "  " << c << endl;

    p = &a; *p = 80;
    cout << "9.  A, B, C: " << a << "  " << b << "  " << c << endl;

    p = &b; *p = 90;
    cout << "10. A, B, C: " << a << "  " << b << "  " << c << endl;
}

int main() {
    Funkcja1();
    Funkcja2();
    return 0;
}