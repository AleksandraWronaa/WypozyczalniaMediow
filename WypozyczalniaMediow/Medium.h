#ifndef MEDIUM_H
#define MEDIUM_H

#include <string>
#include <iostream>

class Medium {
protected:
    std::string id;
    std::string tytul;
    int rokWydania;
    int ograniczenieWiekowe;
    double cenaWypozyczenia;

public:
    Medium(std::string id, std::string tytul, int rok, int wiek, double cena);
    virtual ~Medium() = default;

    virtual std::string getInfo() const;

    //gettery
    std::string getTytul() const;
    std::string getId() const;

    // Metoda pomocnicza do rozpoznawania typu
    virtual bool isVirtual() const = 0;
};

#endif