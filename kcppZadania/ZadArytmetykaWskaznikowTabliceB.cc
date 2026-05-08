#include <iostream>

using namespace std;

int main() {
    const int N = 5;
    float tab1[N], tab2[N], tab3[N];

    // Wskaźniki pomocnicze
    float *p1 = tab1;
    float *p2 = tab2;
    float *p3 = tab3;

    // Wypełnianie pierwszej tablicy przez użytkownika
    cout << "Podaj " << N << " liczb zmiennoprzecinkowych dla tablicy 1:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Element [" << i << "]: ";
        cin >> *(p1 + i); // Zapisujemy bezpośrednio pod adres
    }

    // Wypełnianie tab2 (tab1 * 2) oraz tab3 (tab1 + tab2)
    // Wykorzystamy jedną pętlę i przesunięcia wskaźników
    p1 = tab1; // Resetujemy p1 na początek
    for (int i = 0; i < N; i++) {
        // Obliczamy tab2: wartość z tab1 mnożymy przez 2
        *(p2 + i) = *(p1 + i) * 2.0f;

        // Obliczamy tab3: suma odpowiadających elementów
        *(p3 + i) = *(p1 + i) + *(p2 + i);
    }

    // Wyświetlanie wszystkich trzech tablic
    // użyjemy p++ dla demonstracji innego stylu iteracji
    cout << "\n--- Wyniki (uzywajac wskaznikow) ---" << endl;
    
    // Resetujemy wszystkie wskaźniki na początki tablic
    p1 = tab1; p2 = tab2; p3 = tab3;

    cout << "TAB 1\t\tTAB 2 (x2)\tTAB 3 (Suma)" << endl;
    for (int i = 0; i < N; i++) {
        cout << *p1 << "\t\t" << *p2 << "\t\t" << *p3 << endl;
        
        // Przesuwamy wszystkie trzy "celowniki" o jeden krok w prawo
        p1++; 
        p2++; 
        p3++;
    }

    return 0;
}