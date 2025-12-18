#ifndef MEDIUMTYPY_H
#define MEDIUMTYPY_H

#include "Medium.h"

// --- Medium Fizyczne ---
class MediumFizyczne : public Medium {
protected:
    int stanMagazynowy;
    std::string lokalizacjaWSalonie;
    bool dostepnosc;

public:
    MediumFizyczne(std::string id, std::string tytul, int rok, int wiek, double cena,
        int stan, std::string lokalizacja);

    void zmienStanMagazynowy(int ilosc);
    std::string getInfo() const override;
    bool isVirtual() const override { return false; }
};

// --- Medium Wirtualne (dawniej Cyfrowe) ---
class MediumWirtualne : public Medium {
protected:
    double rozmiarPlikuMB;
    std::string urlPobrania;
    std::string formatPliku;

public:
    MediumWirtualne(std::string id, std::string tytul, int rok, int wiek, double cena,
        double rozmiar, std::string url, std::string format);

    std::string generujLink() const;
    std::string getInfo() const override;
    bool isVirtual() const override { return true; }
};

#endif