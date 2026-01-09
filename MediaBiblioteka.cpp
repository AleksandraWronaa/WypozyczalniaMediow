#include "MediaBiblioteka.h"
#include <iostream>
#include <string>

using namespace std;


// IMPLEMENTACJA FUNKCJI POMOCNICZYCH

string oprawaToString(TypOprawy o) { return (o == TypOprawy::TWARDA) ? "Twarda" : "Miekka"; }

string wideoToString(NosnikWideo n) {
    if (n == NosnikWideo::DVD) return "DVD";
    if (n == NosnikWideo::BLURAY) return "BluRay";
    return "VHS";
}

string audioToString(NosnikAudio n) {
    if (n == NosnikAudio::CD) return "CD";
    if (n == NosnikAudio::WINYL) return "Winyl";
    return "Kaseta";
}

string platformaToString(PlatformaGry p) {
    if (p == PlatformaGry::PC) return "PC";
    if (p == PlatformaGry::PS) return "PS"; // Poprawione z PS5 na PS (zgodnie z Enum)
    if (p == PlatformaGry::XBOX) return "Xbox";
    return "Switch";
}


// IMPLEMENTACJA KLAS KONKRETNYCH


// --- Ksiazki Fizyczne ---
KsiazkaFizyczna::KsiazkaFizyczna(string id, string tytul, int rok, int wiek, double cena,
    int stan, string lokalizacja,
    string autor, int strony, TypOprawy oprawa)
    : MediumFizyczne(id, tytul, rok, wiek, cena, stan, lokalizacja),
    autor(autor), liczbaStron(strony), oprawa(oprawa) {
}

string KsiazkaFizyczna::getInfo() const {
    return MediumFizyczne::getInfo() + " | [KSIAZKA] Autor: " + autor +
        ", Stron: " + to_string(liczbaStron) + ", Oprawa: " + oprawaToString(oprawa);
}

// --- Filmy Fizyczne ---
FilmFizyczny::FilmFizyczny(string id, string tytul, int rok, int wiek, double cena,
    int stan, string lokalizacja,
    string rezyser, int czas, NosnikWideo nosnik)
    : MediumFizyczne(id, tytul, rok, wiek, cena, stan, lokalizacja),
    rezyser(rezyser), czasTrwaniaMin(czas), nosnik(nosnik) {
}

string FilmFizyczny::getInfo() const {
    return MediumFizyczne::getInfo() + " | [FILM] Rezyser: " + rezyser +
        ", Czas: " + to_string(czasTrwaniaMin) + "min, Nosnik: " + wideoToString(nosnik);
}

// --- Muzyka Fizyczna ---
MuzykaFizyczna::MuzykaFizyczna(string id, string tytul, int rok, int wiek, double cena,
    int stan, string lokalizacja,
    string artysta, NosnikAudio nosnik)
    : MediumFizyczne(id, tytul, rok, wiek, cena, stan, lokalizacja),
    artysta(artysta), nosnik(nosnik) {
}

string MuzykaFizyczna::getInfo() const {
    return MediumFizyczne::getInfo() + " | [MUZYKA] Artysta: " + artysta +
        ", Nosnik: " + audioToString(nosnik);
}

// --- Gry Fizyczne ---
GraFizyczna::GraFizyczna(string id, string tytul, int rok, int wiek, double cena,
    int stan, string lokalizacja,
    string studio, PlatformaGry platforma)
    : MediumFizyczne(id, tytul, rok, wiek, cena, stan, lokalizacja),
    studio(studio), platforma(platforma) {
}

string GraFizyczna::getInfo() const {
    return MediumFizyczne::getInfo() + " | [GRA] Studio: " + studio +
        ", Platforma: " + platformaToString(platforma);
}


// IMPLEMENTACJA KLAS WIRTUALNYCH

// --- Ksiazki Wirtualne ---
KsiazkaWirtualna::KsiazkaWirtualna(string id, string tytul, int rok, int wiek, double cena,
    double rozmiar, string url, string format,
    string autor, int strony, bool kindle)
    : MediumWirtualne(id, tytul, rok, wiek, cena, rozmiar, url, format),
    autor(autor), liczbaStron(strony), czyKindleObslugiwany(kindle) {
}

string KsiazkaWirtualna::getInfo() const {
    return MediumWirtualne::getInfo() + " | [EBOOK] Autor: " + autor +
        ", Kindle: " + (czyKindleObslugiwany ? "Tak" : "Nie");
}

// --- Filmy Wirtualne ---
FilmWirtualny::FilmWirtualny(string id, string tytul, int rok, int wiek, double cena,
    double rozmiar, string url, string format,
    string rezyser, int czas, string jakosc)
    : MediumWirtualne(id, tytul, rok, wiek, cena, rozmiar, url, format),
    rezyser(rezyser), czasTrwaniaMin(czas), jakosc(jakosc) {
}

string FilmWirtualny::getInfo() const {
    return MediumWirtualne::getInfo() + " | [VOD] Rezyser: " + rezyser +
        ", Jakosc: " + jakosc;
}

// --- Muzyka Wirtualna ---
MuzykaWirtualna::MuzykaWirtualna(string id, string tytul, int rok, int wiek, double cena,
    double rozmiar, string url, string format,
    string artysta, int bitrate)
    : MediumWirtualne(id, tytul, rok, wiek, cena, rozmiar, url, format),
    artysta(artysta), bitrate(bitrate) {
}

string MuzykaWirtualna::getInfo() const {
    return MediumWirtualne::getInfo() + " | [STREAM] Artysta: " + artysta +
        ", Bitrate: " + to_string(bitrate) + "kbps";
}

// --- Gry Wirtualne ---
GraWirtualna::GraWirtualna(string id, string tytul, int rok, int wiek, double cena,
    double rozmiar, string url, string format,
    string studio, string wymagania)
    : MediumWirtualne(id, tytul, rok, wiek, cena, rozmiar, url, format),
    studio(studio), wymaganiaSprzetowe(wymagania) {
}

string GraWirtualna::getInfo() const {
    return MediumWirtualne::getInfo() + " | [GRA DIGI] Studio: " + studio +
        ", Wymagania: " + wymaganiaSprzetowe;
}