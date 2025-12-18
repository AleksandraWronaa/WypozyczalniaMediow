#ifndef KLIENT_H
#define KLIENT_H

#include <string>
#include <vector>
#include <memory>
#include "Wypozyczenie.h"
#include "Medium.h"

class Klient {
    std::string id; // UUID
    std::string imie;
    std::string nazwisko;
    std::string numerTelefonu;
    std::string adresZamieszkania;

    // Relacja "posiada"
    std::vector<std::shared_ptr<Wypozyczenie>> historiaWypozyczen;

public:
    Klient(std::string id, std::string im, std::string naz, std::string tel, std::string adr);

    // Zwraca listê (w UML: getHistoriaWypozyczen(): List<Wypozyczenie>)
    std::vector<std::shared_ptr<Wypozyczenie>> getHistoriaWypozyczen();

    void wypozycz(std::shared_ptr<Medium> medium);

    // Helper do wyœwietlania w konsoli
    void pokazStanKonta();
};

#endif