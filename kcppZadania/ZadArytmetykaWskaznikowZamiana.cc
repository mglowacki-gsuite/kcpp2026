#include <iostream>

// Funkcja przyjmuje dwa wskaźniki (adresy)
void zamien(int* a, int* b) {
    // Tworzymy zmienną pomocniczą, aby przechować wartość spod adresu 'a'
    int temp = *a; 
    
    // Pod adres 'a' wstawiamy wartość spod adresu 'b'
    *a = *b; 
    
    // Pod adres 'b' wstawiamy naszą zapisaną wcześniej wartość temp
    *b = temp; 
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << "Przed zamiana: x = " << x << ", y = " << y << std::endl;

    // Przekazujemy adresy zmiennych x i y za pomocą operatora &
    zamien(&x, &y);

    std::cout << "Po zamianie:  x = " << x << ", y = " << y << std::endl;

    return 0;
}