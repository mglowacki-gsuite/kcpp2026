#ifndef ZADANIA_H
#define ZADANIA_H

#include "ZadKcpp.h"

// Deklaracje klas dla poszczególnych zadań (dziedziczenie po ZadKcpp)

class Zadanie1 : public ZadKcpp {
public:
    void wykonajZadanie() override;
};

class Zadanie2 : public ZadKcpp {
public:
    void wykonajZadanie() override;
};

class Zadanie3 : public ZadKcpp {
public:
    void wykonajZadanie() override;
};

class Zadanie4 : public ZadKcpp {
public:
    void wykonajZadanie() override;
};

class Zadanie5 : public ZadKcpp {
public:
    void wykonajZadanie() override;
};

class Zadanie6 : public ZadKcpp {
public:
    void wykonajZadanie() override;
};

class Zadanie7 : public ZadKcpp {
public:
    void wykonajZadanie() override;
};

class Zadanie8 : public ZadKcpp {
public:
    void wykonajZadanie() override;
};

class Zadanie9 : public ZadKcpp {
private:
    bool czyParzystaBitowo(int n);
    bool czyParzystaModulo(int n);
    void wyswietlWynikWarunkowy(int n);
public:
    void wykonajZadanie() override;
};

class Zadanie10 : public ZadKcpp {
private:
    void funkcjaWhile();
    void funkcjaDoWhile();
    void funkcjaFor();
public:
    void wykonajZadanie() override;
};

#endif