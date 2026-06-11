/*

Unia to specyficzna struktura, w której wszystkie pola dzielą ten sam obszar w pamięci RAM.
Rozmiar unii jest równy rozmiarowi jej największego elementu.
Zapisanie wartości do jednego pola automatycznie nadpisuje (częściowo lub w całości) zawartość pozostałych pól.

*/

#include <iostream>

// Deklaracja unii
union MojaUnia {
    int liczba_int;      // Zajmuje najczęściej 4 bajty
    double liczba_double; // Zajmuje najczęściej 8 bajtów
    char znak;           // Zajmuje 1 bajt
};

int main() {
    // Deklaracja i definicja obiektu unii
    MojaUnia u;

    std::cout << "Rozmiar w pamięcii (Unii)" << std::endl;
    std::cout << "Rozmiar int: " << sizeof(int) << " bajty" << std::endl;
    std::cout << "Rozmiar double: " << sizeof(double) << " bajtow" << std::endl;
    std::cout << "Rozmiar char: " << sizeof(char) << " bajt" << std::endl;
    // Rozmiar unii to rozmiar najwiekszego typu (double = 8 bajtów)
    std::cout << "Rozmiar calej unii u: " << sizeof(u) << " bajtow (wspolny obszar!)" << std::endl;

    
    std::cout << " prawidłowe wywolanie/odczyt (jeden typ na raz)" << std::endl;
   
    
    // Zapisujemy int i od razu go odczytujemy
    u.liczba_int = 42;
    std::cout << "Zapisano int = 42. Odczyt u.liczba_int: " << u.liczba_int << std::endl;

    // Zapisujemy char i od razu go odczytujemy
    u.znak = 'A';
    std::cout << "Zapisano char = 'A'. Odczyt u.znak: " << u.znak << std::endl;
    
    
    std::cout << " zagrożenia i błędy (Undefined Behavior)" << std::endl;

    // 1. Zapisujemy wartosc do pola double
    u.liczba_double = 12345.6789;
    std::cout << "1. Zapisano poprawnie u.liczba_double = " << u.liczba_double << std::endl;

    // 2. Blad/Niebezpieczenstwo - probujemy odczytac dane przez inny typ!
    // W pamieci RAM leza bajty liczby double, ale program zinterpretuje je jako liczbe int.
    std::cout << "2. bład, Probujemy odczytac ten sam obszar jako int: " << u.liczba_int << std::endl;
    std::cout << "   (Otrzymujemy losowa, poniewaz ukradlismy tylko fragment bajtow double)" << std::endl;

    // 3: Nadpisanie pamieci
    // Zapisanie czegokolwiek do pola 'znak' niszczy wartosc 'liczba_double', 
    // poniewaz 'znak' zajmuje pierwszy bajt tego samego obszaru pamięci.
    u.znak = 'X';
    std::cout << "\n 3. Zapisano u.znak = 'X'." << std::endl;
    std::cout << "   błąd Co sie stalo z u.liczba_double? Wynik: " << u.liczba_double << std::endl;
    std::cout << "   (Wartosc double zostala bezpowrotnie uszkodzona przez nadpisanie jej fragmentu)" << std::endl;

    return 0;
}