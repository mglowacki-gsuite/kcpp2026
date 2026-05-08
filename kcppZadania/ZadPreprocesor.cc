#include <iostream>
#include <string>

using namespace std;

// --- DEFINICJE PREPROCESORA ---
#define WERSJA 2
#define DEBUG_MODE
// (a) Makro jako funkcja
#define KWADRAT(x) ((x) * (x))

// (b) Uzycie # (stringize) i ## (token pasting)
#define NAZWA_ZMIENNEJ(x) #x
#define LACZ(a, b) a##b

int main() {
    // 1. #ifdef i #else
    cout << "--- 1. #ifdef / #else ---" << endl;
    #ifdef DEBUG_MODE
        cout << "Tryb DEBUG jest aktywny." << endl;
    #else
        cout << "Tryb RELEASE (standardowy)." << endl;
    #endif

    // Porownanie: Bez preprocesora (zwykly if)
    bool debugMode = true;
    if (debugMode) cout << "[C++] Tryb debug aktywny." << endl;

    // 2. #ifndef (uzywane czesto w naglowkach)
    cout << "\n--- 2. #ifndef ---" << endl;
    #ifndef POWITANIE
        #define POWITANIE "Witaj przybyszu!"
        cout << POWITANIE << endl;
    #endif

    // 3. Makro (a) vs Funkcja inline
    cout << "\n--- 3. Makro vs Funkcja ---" << endl;
    int liczba = 5;
    cout << "Makro KWADRAT(5): " << KWADRAT(liczba) << endl;

    // Porownanie: Bez preprocesora (funkcja constexpr)
    auto kwadratCpp = [](int x) { return x * x; };
    cout << "Funkcja C++ kwadrat: " << kwadratCpp(5) << endl;

    // 4. Operatory # i ## (b)
    cout << "\n--- 4. Operatory # i ## ---" << endl;
    
    // # zamienia argument makra w napis (string)
    cout << "Nazwa zmiennej to: " << NAZWA_ZMIENNEJ(liczba) << endl;

    // ## laczy dwa tokeny w jedna nazwe
    int MojaZmienna = 100;
    cout << "Polaczona nazwa LACZ: " << LACZ(Moja, Zmienna) << endl;

    // Porownanie: Bez preprocesora
    // W czystym C++ nie da sie pobrac nazwy zmiennej ani generowac nazw 
    // zmiennych w locie tak jak robi to ##. Mozna uzyc std::to_string() 
    // lub mapy dla dynamicznych nazw, ale to zupelnie inne mechanizmy.
    string nazwaStr = "liczba";
    cout << "[C++] Symulacja nazwy: " << nazwaStr << endl;

    return 0;
}