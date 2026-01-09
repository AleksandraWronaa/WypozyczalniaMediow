#ifndef MEDIABIBLIOTEKA_H
#define MEDIABIBLIOTEKA_H

#include "MediumTypy.h"
#include <string>

// ==========================================
// ENUMY (Zgodnie z UML)
// ==========================================
enum class TypOprawy { TWARDA, MIEKKA };
enum class NosnikWideo { DVD, BLURAY, KASETA_VHS };
enum class NosnikAudio { CD, KASETA, WINYL };
enum class PlatformaGry { PC, PS, XBOX, SWITCH };

// Funkcje pomocnicze do konwersji Enum na String
std::string oprawaToString(TypOprawy o);
std::string wideoToString(NosnikWideo n);
std::string audioToString(NosnikAudio n);
std::string platformaToString(PlatformaGry p);

// ==========================================
// KLASY FIZYCZNE (Liœcie)
// ==========================================

class KsiazkaFizyczna : public MediumFizyczne {
    std::string autor;
    int liczbaStron;
    TypOprawy oprawa;
public:
    KsiazkaFizyczna(std::string id, std::string tytul, int rok, int wiek, double cena,
        int stan, std::string lokalizacja,
        std::string autor, int strony, TypOprawy oprawa);
    std::string getInfo() const override;
};

class FilmFizyczny : public MediumFizyczne {
    std::string rezyser;
    int czasTrwaniaMin;
    NosnikWideo nosnik;
public:
    FilmFizyczny(std::string id, std::string tytul, int rok, int wiek, double cena,
        int stan, std::string lokalizacja,
        std::string rezyser, int czas, NosnikWideo nosnik);
    std::string getInfo() const override;
};

class MuzykaFizyczna : public MediumFizyczne {
    std::string artysta;
    NosnikAudio nosnik;
public:
    MuzykaFizyczna(std::string id, std::string tytul, int rok, int wiek, double cena,
        int stan, std::string lokalizacja,
        std::string artysta, NosnikAudio nosnik);
    std::string getInfo() const override;
};

class GraFizyczna : public MediumFizyczne {
    std::string studio;
    PlatformaGry platforma;
public:
    GraFizyczna(std::string id, std::string tytul, int rok, int wiek, double cena,
        int stan, std::string lokalizacja,
        std::string studio, PlatformaGry platforma);
    std::string getInfo() const override;
};

// ==========================================
// KLASY WIRTUALNE (Liœcie)
// ==========================================

class KsiazkaWirtualna : public MediumWirtualne {
    std::string autor;
    int liczbaStron;
    bool czyKindleObslugiwany;
public:
    KsiazkaWirtualna(std::string id, std::string tytul, int rok, int wiek, double cena,
        double rozmiar, std::string url, std::string format,
        std::string autor, int strony, bool kindle);
    std::string getInfo() const override;
};

class FilmWirtualny : public MediumWirtualne {
    std::string rezyser;
    int czasTrwaniaMin;
    std::string jakosc; // np. "4K", "1080p"
public:
    FilmWirtualny(std::string id, std::string tytul, int rok, int wiek, double cena,
        double rozmiar, std::string url, std::string format,
        std::string rezyser, int czas, std::string jakosc);
    std::string getInfo() const override;
};

class MuzykaWirtualna : public MediumWirtualne {
    std::string artysta;
    int bitrate;
public:
    MuzykaWirtualna(std::string id, std::string tytul, int rok, int wiek, double cena,
        double rozmiar, std::string url, std::string format,
        std::string artysta, int bitrate);
    std::string getInfo() const override;
};

class GraWirtualna : public MediumWirtualne {
    std::string studio;
    std::string wymaganiaSprzetowe;
public:
    GraWirtualna(std::string id, std::string tytul, int rok, int wiek, double cena,
        double rozmiar, std::string url, std::string format,
        std::string studio, std::string wymagania);
    std::string getInfo() const override;
};

#endif