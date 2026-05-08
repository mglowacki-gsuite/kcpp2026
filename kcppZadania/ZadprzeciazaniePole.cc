#include <iostream>
#include <cmath> // Dla stałej M_PI 
using namespace std;
// 1. Pole kwadratu (jeden argument)
double pole(double bok) {
    return bok * bok;
}

// 2. Pole prostokata (dwa argumenty)
double pole(double a, double b) {
    return a * b;
}

// 3. Pole kola (używamy innego podejścia, np. stałej i promienia). Jeśli przyjmiemy, że promień koła przekazujemy np. jako float, kompilator je rozróżni. 

float pole(float promien) {
    return M_PI * promien * promien;
}

int main() {
    // Kompilator patrzy na argumenty i wybiera odpowiednią funkcję:
    
    cout << "Pole kwadratu (bok 5): " << pole(5.0) << endl;         // Wywoła wersję 1
    cout << "Pole prostokata (4x6): " << pole(4.0, 6.0) << endl;   // Wywoła wersję 2
    cout << "Pole kola (r=3.0f): " << pole(3.0f) << endl;          // Wywoła wersję 3 (float)

    return 0;
}