#include <iostream>
#include <iomanip> //dla setw, setprecision, setfill
#include <cmath>    // Dla funkcji matematycznych do wygenerowania liczb

/*

setw(n): Ustawia szerokość pola na n znaków. Działa tylko na najbliższy element. Jeśli tekst jest krótszy, zostanie uzupełniony spacjami.

setfill(c): Zmienia znak wypełniania (domyślnie spację) na wybrany znak c.

setprecision(n): Ustawia dokładność liczb zmiennoprzecinkowych.

fixed: Wymusza zapis z kropką (np. 123.450000). W połączeniu z setprecision(n) ustala liczbę cyfr po przecinku.

scientific: Wymusza zapis naukowy (np. 1.23e+02).

hex / dec / oct: Zmienia system liczbowy wyświetlanej liczby (szesnastkowy, dziesiętny, ósemkowy).

*/


using namespace std;

int main() {
    double liczba = 123.456789;
    int liczba_int = 255;

    // Szerokość i wypełnienie
    cout << "--- Szerokosc i wypelnienie ---" << endl;
    cout << setfill('.');
    cout << setw(15) << "Liczba:" << setw(10) << 100 << endl;
    cout << setw(15) << "Wartosc:" << setw(10) << 20 << endl;

    //Precyzja i format zmiennoprzecinkowy
    cout << "\n--- Precyzja ---" << endl;
    cout << "Domyslnie: " << liczba << endl;
    
    // Ustawiamy na sztywno 2 miejsca po przecinku
    cout << fixed << setprecision(2);
    cout << "Fixed (2):  " << liczba << endl;
    
    cout << scientific << setprecision(3);
    cout << "Scientific: " << liczba << endl;

    //Systemy liczbowe
    cout << "\n--- Systemy liczbowe ---" << endl;
    cout << dec << "Dec: " << liczba_int << endl;
    cout << hex << "Hex: " << liczba_int << endl;
    cout << oct << "Oct: " << liczba_int << endl;


    double x = sqrt(2.0);                     // 1.41421...
    double out = M_PI * 10;                   // 31.4159...
    double t = exp(1.0);                      // 2.71828...
    double out1 = 1.0 / 7.0;                  // 0.14285...
    double t1 = 22.22222;
    double out2 = log(5.0);                   // 1.60943...
    double t2 = 12.345678;
    
    double avg_out = (out + out1 + out2) / 3.0;
    double avg_t = (t + t1 + t2) / 3.0;

    // Nagłówek
    cout << "==================================================" << endl;
    
    // Pierwsza linia (domyślna precyzja)
    cout << "Wynik naszego dzialania: " << x << " jest niepoprawny ale:" << endl;

    // Ustawiamy globalnie format stałoprzecinkowy
    cout << fixed;

    // output: xx.xxx T: x.xxx
    cout << setfill(' '); // Upewniamy się, że wypełniamy spacjami
    cout << setw(12) << "output:"  << setw(9) << setprecision(3) << out 
         << setw(6)  << "T:"       << setw(8) << setprecision(3) << t << endl;

    // output1: x.xxxx T: xx.xxxxx
    cout << setw(12) << "output1:" << setw(9) << setprecision(4) << out1 
         << setw(6)  << "T:"       << setw(10) << setprecision(5) << t1 << endl;

    // output2: x.xxxx T: xx.xxxxxx
    cout << setw(12) << "output2:" << setw(9) << setprecision(4) << out2 
         << setw(6)  << "T:"       << setw(11) << setprecision(6) << t2 << endl;

    // Linia oddzielająca
    cout << setw(6) << "" << setfill('-') << setw(33) << "" << setfill(' ') << endl;

    // average: xx.xxxx T: xx.xxxxxx
    cout << setw(12) << "average:" << setw(9) << setprecision(4) << avg_out 
         << setw(6)  << "T:"       << setw(11) << setprecision(6) << avg_t << endl;

    cout << "==================================================" << endl;

    return 0;
}