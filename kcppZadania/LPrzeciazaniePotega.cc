#include <iostream>
#include <cmath>
// zamienilem int na double, żeby móc zwracać ułamki
double potega(int podstawa, int wykladnik) {
    double wynik = 1.0; 

    if (wykladnik == 0) {
        return 1.0;
    }
    else if (wykladnik > 0) {
        for (int i = 0; i < wykladnik; i++) {
            wynik *= podstawa;
        }
    }
    else { // Wykładnik ujemny
        //Obliczamy potęgę tak, jakby była dodatnia używamy pomocniczej zmiennej, żeby nie zmieniać oryginału
        int dodatniWykladnik = -wykladnik; 
        
        for (int i = 0; i < dodatniWykladnik; i++) {
            wynik *= podstawa;
        }

        // Odwracamy wynik (1 / wynik)
        wynik = 1.0 / wynik;
    }
    
    return wynik;
}

#include <cmath> // Musisz dodać tę bibliotekę na górze pliku

double potega(double podstawa, double wykladnik) {
    //uzylem funkcji (metody) pow z biblioteki cmath, aby móc korzystać również z zmiennoprzecinkowych wykladnikow
    return std::pow(podstawa, wykladnik);

}

int main() {
    std::cout << "2 do 4: " << potega(2, 4) << std::endl;      // 16
    std::cout << "2 do -3: " << potega(2, -3) << std::endl;   // 0.125
    std::cout << "5 do -1: " << potega(5, -1) << std::endl;   // 0.2

    // Wywołanie double (dodajemy kropkę, żeby wymusić typ double)
    std::cout << "Double 2.5^2 = " << potega(2.5, 2.0) << std::endl;
    std::cout << "Double 4.0^0.5 = " << potega(4.0, 0.5) << " (pierwiastek)" << std::endl;
    
    return 0;
}