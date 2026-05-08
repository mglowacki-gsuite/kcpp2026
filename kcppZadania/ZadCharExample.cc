#include <iostream>
#include <cstring>
using namespace std;

/**
 * Program demonstracyjny dla operacji na tablicach znaków (C-style strings).
 */
int main() {
    // Inicjalizacja
    char s1[] = "Programowanie";      // Automatyczny rozmiar z terminatorem \0
    char s2[20] = "C++";              // Rozmiar nadmiarowy
    char s3[50];                      // Bufor niezinicjalizowany

    cout << "--- Inicjalizacja i Informacje ---" << endl;
    // strlen() zwraca faktyczną długość tekstu (bez \0)
    // sizeof() zwraca rozmiar całej tablicy w pamięci
    cout << "s1: " << s1 << " | Dlugosc (strlen): " << strlen(s1) 
         << " | Rozmiar (sizeof): " << sizeof(s1) << endl;

    // Kopiowanie (strcpy i strncpy)
    cout << "\n--- Kopiowanie ---" << endl;
    
    // kopiowanie z ograniczeniem znaków
    strncpy(s3, s1, sizeof(s3) - 1);
    s3[sizeof(s3) - 1] = '\0'; // ręcznie dodaje koniec napisu
    cout << "s3 po strncpy (z s1): " << s3 << endl;

    // Łączenie napisów (strcat i strncat) 
    cout << "\n--- Laczenie (Concatenation) ---" << endl;
    
    char powitanie[30] = "Dzien dobry ";
    char imie[] = "Janusz!";
    
    strncat(powitanie, imie, sizeof(powitanie) - strlen(powitanie) - 1);
    cout << "Wynik laczenia: " << powitanie << endl;

    // Porównywanie (strcmp)
    cout << "\n--- Porownywanie ---" << endl;
    
    char haslo[] = "Tajne123";
    char proba[] = "Tajne123";

    // strcmp zwraca 0, jeśli napisy są identyczne
    if (strcmp(haslo, proba) == 0) {
        cout << "Hasla sa identyczne." << endl;
    } else {
        cout << "Hasla roznia sie." << endl;
    }

    // Szukanie w tekście (strstr) ---
    cout << "\n--- Szukanie ---" << endl;
    
    char tekst[] = "Ala ma kota, a kot ma ale.";
    char fraza[] = "kota";
    
    char* wynik = strstr(tekst, fraza); // Zwraca wskaźnik do pierwszego wystąpienia

    if (wynik != nullptr) {
        cout << "Znaleziono fraze '" << fraza << "' na pozycji: " 
             << (wynik - tekst) << endl;
    }

    // Czyszczenie pamięci (memset)
    cout << "\n--- Resetowanie bufora ---" << endl;
    
    memset(s3, 0, sizeof(s3)); // Wypełnia całą tablicę zerami
    cout << "s3 po memset (dlugosc): " << strlen(s3) << endl;

    return 0;
}