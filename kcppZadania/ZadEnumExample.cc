#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Scoped enumeration dla miesięcy (C++11)
 * * Używamy enum class, aby uniknąć konfliktów nazw (np. gdyby inny enum 
 * również miał element o nazwie 'Maj').
 */
enum class Miesiac {
    Styczen = 1, // Ustawiamy start na 1, aby odpowiadało kalendarzowi
    Luty,
    Marzec,
    Kwiecien,
    Maj,
    Czerwiec,
    Lipiec,
    Sierpien,
    Wrzesien,
    Pazdziernik,
    Listopad,
    Grudzien
};

/**
 * @brief Funkcja pomocnicza zamieniająca typ enum na czytelny tekst.
 */
string miesiacToString(Miesiac m) {
    switch (m) {
        case Miesiac::Styczen:    return "Styczeń";
        case Miesiac::Luty:       return "Luty";
        case Miesiac::Marzec:     return "Marzec";
        case Miesiac::Kwiecien:   return "Kwiecień";
        case Miesiac::Maj:        return "Maj";
        case Miesiac::Czerwiec:   return "Czerwiec";
        case Miesiac::Lipiec:     return "Lipiec";
        case Miesiac::Sierpien:   return "Sierpień";
        case Miesiac::Wrzesien:   return "Wrzesień";
        case Miesiac::Pazdziernik: return "Październik";
        case Miesiac::Listopad:   return "Listopad";
        case Miesiac::Grudzien:   return "Grudzień";
        default:                  return "Nieznany miesiąc";
    }
}

int main() {
    // Tworzenie zmiennej typu Miesiac
    Miesiac aktualnyMiesiac = Miesiac::Kwiecien;

    cout << "--- Przykład użycia typu Enum (Miesiące) ---" << endl;

    // Przykład 1: Wyświetlenie nazwy za pomocą funkcji pomocniczej
    cout << "Obecnie mamy: " << miesiacToString(aktualnyMiesiac) << endl;

    // Przykład 2: Pobranie wartości liczbowej (wymaga static_cast dla scoped enum)
    cout << "Numer miesiąca w kalendarzu: " << static_cast<int>(aktualnyMiesiac) << endl;

    // Przykład 3: Logika warunkowa
    if (aktualnyMiesiac == Miesiac::Kwiecien) {
        cout << "Wiosna w pełni!" << endl;
    }

    // Przykład 4: Iteracja (pokazanie wartości liczbowych dla wszystkich elementów)
    cout << "\nLista wartości liczbowych dla wybranych miesięcy:" << endl;
    cout << "Styczeń: " << static_cast<int>(Miesiac::Styczen) << endl;
    cout << "Grudzień: " << static_cast<int>(Miesiac::Grudzien) << endl;

    return 0;
}