#include "Medium.h"

using namespace std;

Medium::Medium(string id, string tytul, int rok, int wiek, double cena)
    : id(id), tytul(tytul), rokWydania(rok), ograniczenieWiekowe(wiek), cenaWypozyczenia(cena) {
}

string Medium::getInfo() const {
    return "ID: " + id + " | Tytul: " + tytul + " | Cena: " + to_string(cenaWypozyczenia);
}

string Medium::getTytul() const { return tytul; }
string Medium::getId() const { return id; }