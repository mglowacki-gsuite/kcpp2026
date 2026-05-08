#include <iostream>

using namespace std;

// (Funkcja prezentująca podstawowe działania matematyczne
void OperatoryArytmetyczne() {
    int a = 10;
    int b = 3;

    cout << "--- (1) Operatory Arytmetyczne ---" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "Suma (a + b):        " << a + b << endl;
    cout << "Roznica (a - b):     " << a - b << endl;
    cout << "Iloczyn (a * b):     " << a * b << endl;
    cout << "Iloraz (a / b):      " << a / b << " (dzielenie calkowite!)" << endl;
    cout << "Modulo (a % b):      " << a % b << " (reszta z dzielenia)" << endl;
    cout << endl;
}

// Funkcja prezentująca skrócone operacje zapisu
void OperatoryPrzypisania() {
    int x = 10;
    cout << "--- (2) Operatory Przypisania ---" << endl;
    cout << "Startowe x = " << x << endl;

    x += 5;  // To samo co: x = x + 5
    cout << "Po x += 5:   " << x << endl;

    x -= 2;  // To samo co: x = x - 2
    cout << "Po x -= 2:   " << x << endl;

    x *= 3;  // To samo co: x = x * 3
    cout << "Po x *= 3:   " << x << endl;

    x /= 4;  // To samo co: x = x / 4
    cout << "Po x /= 4:   " << x << endl;

    x %= 3;  // To samo co: x = x % 3
    cout << "Po x %= 3:   " << x << endl;
    cout << endl;
}

int main() {
    OperatoryArytmetyczne();
    OperatoryPrzypisania();

    return 0;
}