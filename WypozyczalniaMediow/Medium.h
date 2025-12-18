#ifndef MEDIUM_H
#define MEDIUM_H

#include <string>
#include <iostream>

class Medium {
protected:
    std::string id;             // UUID w UML
    std::string tytul;
    int rokWydania;
    int ograniczenieWiekowe;
    double cenaWypozyczenia;    // Decimal w UML

public:
    Medium(std::string id, std::string tytul, int rok, int wiek, double cena);
    virtual ~Medium() = default;

    virtual std::string getInfo() const;

    // Metody dostêpowe (gettery) potrzebne do logiki, mimo ¿e UML pokazuje tylko publiczne API
    std::string getTytul() const;
    std::string getId() const;

    // Metoda pomocnicza do rozpoznawania typu (zastêpuje pure virtual czyCyfrowe dla zgodnoœci z logik¹ UML)
    virtual bool isVirtual() const = 0;
};

#endif