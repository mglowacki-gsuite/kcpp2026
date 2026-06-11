#ifndef ZADKCPP_H
#define ZADKCPP_H

// Klasa nadrzędna (abstrakcyjna) dla wszystkich zadań
class ZadKcpp {
public:
    virtual void wykonajZadanie() = 0; // Metoda czysto wirtualna
    virtual ~ZadKcpp();                // Wirtualny destruktor
};

#endif