#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;


class Automatyka{

    public:
        string wybor_operacji[5] = {"elektryka", "pneumatyka", "mechanika", "hydraulika", "nieznana tematyka"};

        void wybor(std::string tematyka) {
        std::string male = tematyka; // Kopiuje oryginalny tekst
    
        // Transformuje cały napis na małe litery
        transform(male.begin(), male.end(), male.begin(), [](unsigned char c) {
            return tolower(c);
        });

        if (wybor_operacji[0] == male){
            cout << male << endl;
        }

        else if (wybor_operacji[1] == male){
            cout << male << endl;
        }

        else if (wybor_operacji[2] == male){
            cout << male << endl;
        }

        else if (wybor_operacji[3] == male){
            cout << male << endl;
        }

        else{
            cout << wybor_operacji[4] << endl;
        }

    };
        
        int one_phase_voltage = 230;
        int three_phase_voltage = 400;
        int resistance_of_human = 1000;

        void mini_quiz_elektryczny();
        void testuj_funkcje_prywatne();
        void wyswietl_komunikat_inline();

    private:
        int voltage_one_phase = 230;
        void calculate_one_phase_power(int ampers){
            cout << "podaj natezenie pradu w Amperach w celu policzenia mocy odbiornika jednofazowego" << endl;
            cin >> ampers;
            double P = voltage_one_phase * ampers;
            cout << "moc dla odbiornika jednofazowego wynosi: " << P << endl;
        }
        
        void heating_of_conductor(int current, int resistance, int timing);


    protected:
        double rezystancja;
        void wartosc_rezystancji(int natezenie_pradu, int napiecie){
            cout << "Podaj wartosc natezenia pradu w Amperach: ";
            cin >> natezenie_pradu;
            cout << endl << "Podaj wartosc napiecia w Voltach: ";
            cin >> napiecie;
            rezystancja = napiecie / natezenie_pradu;
            cout << endl << "wartosc obliczonej rezystancji to: " << rezystancja;
        }
};


void Automatyka::mini_quiz_elektryczny(){
            int first_question, second_question, third_question;
            int points = 0;
            cout << "Jaka jest wartość dla napięcia jednofazowego?" << endl;
            cin >> first_question;
            if (first_question == one_phase_voltage){
                cout << "brawo! zdowyasz 1 punkt!" <<endl;
                points++;
            }

            cout << "Jaka jest wartość dla napięcia trójfazowego?" << endl;
            cin >> second_question;
            if (second_question == three_phase_voltage){
                cout << "brawo! zdowyasz 1 punkt!" <<endl;
                points++;
            }

            cout << "Jaka jest ogólnie przyjmowana wartość rezystancji (oporu) ciała człowieka?" << endl;
            cin >> third_question;
            if (third_question == resistance_of_human){
                cout << "brawo! zdowyasz 1 punkt!" <<endl;
                points++;
            }

            if (points == 3){
                cout <<"Brawo! zdobyles maksimum punktów (3/3)!" <<endl;
            }
            else{
                cout << "zdobyles" << points <<"/3 punktów" <<endl;;
            }

        };

void Automatyka::heating_of_conductor(int current, int resistance, int timing){
    double Q;
    cout << "Podaj natężenie prądu przewodnika: ";
    cin >> current;
    cout << endl << "Podaj rezystancje prądu przewodnika: ";
    cin >> resistance;
    cout << endl << "Podaj czas przepływu prądu przewodnika (sekundy): ";
    cin >> timing;

    Q = (current * current)*resistance*timing;
    cout << endl << "ilośc wydzielonego ciepła wynosi: " << Q <<endl;
}

void Automatyka::testuj_funkcje_prywatne() {
    cout << "test metod prywatnych" << endl;
    calculate_one_phase_power(16); // Test dla 16 Amperów
    heating_of_conductor(0, 0, 0);  // Test obliczania ciepła
}

inline void Automatyka::wyswietl_komunikat_inline() {
    cout << "Ta funkcja zostala zadeklarowana w klasie, zdefiniowana poza nia" << endl;
}

class Elektrycznosc : public Automatyka{

    public:
        void uruchom_obliczenia_rezystancji() {
            cout << "Uruchomiono z poziomu klasy Elektrycznosc" << endl;
            
            // Wywołujemy metodę z klasy Automatyka
            wartosc_rezystancji(0, 0); 
        }

        
        // Po usuneciu komentarzy z początku poniższych linii, kompilator wyświetli błąd (test dla dziedziczzenia po private)
        // calculate_one_phase_power(10); // <-- BŁĄD! 'calculate_one_phase_power' is a private member of 'Automatyka'
        // cout << voltage_one_phase;    // <-- BŁĄD! 'voltage_one_phase' is a private member of 'Automatyka'

};

int main(){
    //testy klasy
    Automatyka specjalizacja;
    specjalizacja.wybor("elektryka");
    specjalizacja.wybor("pneumatyka");
    specjalizacja.wybor("mechanika");
    specjalizacja.wybor("hydraulika");
    specjalizacja.wybor("Mechanika");
    specjalizacja.wybor("mcos tam");

    Automatyka quiz;
    quiz.mini_quiz_elektryczny();

    Automatyka test;
    test.testuj_funkcje_prywatne();

    specjalizacja.wyswietl_komunikat_inline();

    Elektrycznosc obiektElektro;
    // Wywołujemy publiczną metodę klasy Elektrycznosc, która pod korzysta z chronionej metody klasy Automatyka
    obiektElektro.uruchom_obliczenia_rezystancji();

    return 0;
}