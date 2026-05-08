#include <iostream>  // Strumienie C++ (cout, cin)
#include <cstdio>    // Funkcje standardowe C (printf, scanf)
#include <string>    // Klasa string C++

using namespace std;

void operacjeC() {
    printf("--- Operacje w stylu C ---\n");
    
    // Deklaracja i inicjalizacja
    int a = 10;
    float b = 3.14159;
    char tekst[50] = "Witaj z C";

    // Wypisywanie (wymaga specyfikatorów formatu %d, %f, %s)
    printf("Liczba int: %d\n", a);
    printf("Liczba float (2 miejsca): %.2f\n", b);
    printf("Tekst: %s\n", tekst);

    // Wczytywanie (wymaga operatora adresu &)
    printf("Podaj nowa liczbe int: ");
    scanf("%d", &a);
    printf("Nowa wartosc: %d\n\n", a);
}

void operacjeCPP() {
    cout << "--- Operacje w stylu C++ ---" << endl;

    // Deklaracja i inicjalizacja (używamy klasy string)
    int a = 10;
    float b = 3.14159;
    string tekst = "Witaj z C++";

    // Wypisywanie (używamy operatora << i manipulatorów)
    cout << "Liczba int: " << a << endl;
    cout << "Liczba float: " << fixed << std::fixed << (float)b << endl; // manipulatory sterują formatem
    cout << "Tekst: " << tekst << endl;

    // Wczytywanie (używamy operatora >>, brak potrzeby &)
    cout << "Podaj nowa liczbe int: ";
    cin >> a;
    cout << "Nowa wartosc: " << a << endl << endl;
}

int main() {
    operacjeC();
    operacjeCPP();

    return 0;
}