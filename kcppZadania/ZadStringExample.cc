#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Program demonstracyjny operacji na obiektach klasy std::string.
 * Zawiera realizację zadań dotyczących manipulacji ciągami znaków.
 */
int main() {
    //  Sekcja z przykładu LString.cc 
    string napis1 = "text1";
    string napis2("text2");
    string napis3 = "text3";
    string napis4(10, 'X');

    cout << "Wypisywanie napisow podstawowych:" << endl;
    cout << "napis1: " << napis1 << " | napis2: " << napis2 << endl;
    cout << "napis3: " << napis3 << " | napis4: " << napis4 << endl;

    // Zadanie z zajec
    cout << "\n--- REALIZACJA ZADANIA (Manipulacja stringami) ---" << endl;
    cout << "--------------------------------------------------" << endl;

    string s = "Programowanie obiektowe";
    string s2 = "Informatyka";

    // 1. empty() - Sprawdzenie czy pusty
    cout << "1. Czy string 's' jest pusty? " << (s.empty() ? "TAK" : "NIE") << endl;

    // 2. size() / length() - Długość napisu
    cout << "2. Dlugosc napisu 's': " << s.size() << " znakow (lub " << s.length() << ")" << endl;

    // 3. at() - Bezpieczny dostęp do znaku
    try {
        cout << "3. Znak na indeksie 0 (at): " << s.at(0) << endl;
        // s.at(100); // To wyrzuciłoby błąd (wyjątek), w przeciwieństwie do s[100]
    } catch (const out_of_range& e) {
        cout << "Blad: Wyjscie poza zakres!" << endl;
    }

    // 4. append() - Doklejanie tekstu (zrealizowane przed punktem 5/6 dla sensu tekstu)
    s.append(" jest super!");
    cout << "4. Po append: " << s << endl;

    // 5. find() - Znajdowanie podciągu
    size_t pozycja = s.find("obiektowe");
    if (pozycja != string::npos) {
        cout << "5. Znaleziono 'obiektowe' na pozycji: " << pozycja << endl;
    }

    // 6. substr() - Wycinanie fragmentu (indeks, długość)
    string podciag = s.substr(0, 13);
    cout << "6. Podciag (0, 13): " << podciag << endl;

    // 7. erase() - Usuwanie znaków (indeks, ile znaków)
    s.erase(13, 10); // Usuwa " obiektowe"
    cout << "7. Po erase (usunieto 'obiektowe'): " << s << endl;

    // 8. swap() - Zamiana zawartości
    cout << "8. Przed swap -> s: " << s << " | s2: " << s2 << endl;
    s.swap(s2);
    cout << "   Po swap    -> s: " << s << " | s2: " << s2 << endl;

    // 9. clear() - Czyszczenie wszystkiego
    s2.clear();
    cout << "9. Po clear() na s2, czy s2 jest pusty? " << (s2.empty() ? "TAK" : "NIE") << endl;

    cout << "--------------------------------------------------" << endl;

    return 0;
}