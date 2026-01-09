#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H

#include <memory>
#include <ctime>
#include <string>
#include "Medium.h"

class Wypozyczenie {
    std::string idWypozyczenia; // UUID
    time_t dataWypozyczenia;    // DateTime
    time_t oplaconeDo;          // DateTime
    bool czyZwroconoFizycznie;

    std::shared_ptr<Medium> medium;

public:
    Wypozyczenie(std::string id, std::shared_ptr<Medium> m);

    void zarejestrujZwrot();
    bool czyLicencjaAktywna() const;
    void przedluzWypozyczenie(int dni);

    // Gettery pomocnicze
    std::shared_ptr<Medium> getMedium() const;
    std::string getStatusString() const; // Helper do wyœwietlania
};

#endif