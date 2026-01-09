#include "MediumTypy.h"

using namespace std;

// MediumFizyczne
MediumFizyczne::MediumFizyczne(string id, string tytul, int rok, int wiek, double cena, int stan, string lokalizacja)
    : Medium(id, tytul, rok, wiek, cena), stanMagazynowy(stan), lokalizacjaWSalonie(lokalizacja) {
    //jeœli stan > 0 to dostêpne
    dostepnosc = (stanMagazynowy > 0);
}

void MediumFizyczne::zmienStanMagazynowy(int ilosc) {
    stanMagazynowy += ilosc;
    dostepnosc = (stanMagazynowy > 0);
}

string MediumFizyczne::getInfo() const {
    return Medium::getInfo() + " [FIZYCZNE] Polka: " + lokalizacjaWSalonie +
        " | Stan: " + to_string(stanMagazynowy);
}

// MediumWirtualne
MediumWirtualne::MediumWirtualne(string id, string tytul, int rok, int wiek, double cena, double rozmiar, string url, string format)
    : Medium(id, tytul, rok, wiek, cena), rozmiarPlikuMB(rozmiar), urlPobrania(url), formatPliku(format) {
}

string MediumWirtualne::generujLink() const {
    return urlPobrania + "?token=SECURE123"; //symulacja generowania linku
}

string MediumWirtualne::getInfo() const {
    return Medium::getInfo() + " [WIRTUALNE] Rozmiar: " + to_string(rozmiarPlikuMB) + "MB";
}