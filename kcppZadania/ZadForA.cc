#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Podaj liczbe n: ";
  cin >> n;

  // Liczby nieparzyste zamiast parzystych
  cout << "Liczby nieparzyste od 1 do " << n << ":" << endl;
  for (int i = 1; i <= n; i++) {
    // Liczba jest nieparzysta, jesli reszta z dzielenia przez 2 jest rozna od 0
    if (i % 2 != 0) {
      cout << i << " ";
    }
  }

  // Liczby podzielne przez 7
  cout << "\nLiczby podzielne przez 7 od 1 do " << n << ":" << endl;
  for (int i = 1; i <= n; i++) {
    // Liczba jest podzielna przez 7, gdy i % 7 daje 0
    if (i % 7 == 0) {
      cout << i << " ";
    }
  }

  cout << endl;
  return 0;
}