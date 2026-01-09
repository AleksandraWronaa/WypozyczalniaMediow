#include <iostream>
#include <memory>
// Zmiana: Do³¹czamy nag³ówek z konkretnymi klasami (Ksiazka, Gra itd.)
#include "MediaBiblioteka.h" 
#include "Klient.h"

using namespace std;

int main() {
    // 1. Tworzenie mediów - U¿ywamy teraz konkretnych klas "Liœci" z UML

    // Ksiazka Fizyczna: ID, Tytul, Rok, Wiek, Cena, Stan, Lok, Autor, Strony, Oprawa
    auto wiedzmin = make_shared<KsiazkaFizyczna>(
        "UUID-BOOK-001", "Wiedzmin: Krew Elfow", 1994, 18, 15.99,
        5, "A1",
        "Andrzej Sapkowski", 340, TypOprawy::MIEKKA
    );

    // Gra Wirtualna: ID, Tytul, Rok, Wiek, Cena, Rozmiar, URL, Format, Studio, Wymagania
    auto minecraft = make_shared<GraWirtualna>(
        "UUID-GAME-002", "Minecraft", 2011, 7, 49.99,
        500.0, "https://minecraft.net", "EXE",
        "Mojang", "RAM: 4GB, CPU: i3"
    );

    // Film Fizyczny (Dla testu Enuma Wideo)
    auto film = make_shared<FilmFizyczny>(
        "UUID-MOV-003", "Incepcja", 2010, 16, 12.00,
        2, "B5",
        "C. Nolan", 148, NosnikWideo::BLURAY
    );

    // 2. Tworzenie klienta
    Klient jan("UUID-KLIENT-100", "Jan", "Kowalski", "123-456-789", "Kwiatowa 5, Warszawa");

    // 3. Wypo¿yczenia
    jan.wypozycz(wiedzmin);
    jan.wypozycz(minecraft);
    jan.wypozycz(film);

    // 4. Sprawdzenie stanu (Wszystkie aktywne)
    jan.pokazStanKonta();

    // 5. Test metody specyficznej dla wirtualnych
    cout << ">> Link do gry: " << minecraft->generujLink() << endl;

    // 6. Zwrot fizyczny
    // Symulacja: szukamy w historii czegoœ co nie jest wirtualne i zwracamy
    auto historia = jan.getHistoriaWypozyczen();
    for (auto& w : historia) {
        if (!w->getMedium()->isVirtual() && w->czyLicencjaAktywna()) {
            cout << ">> Próba zwrotu: " << w->getMedium()->getTytul() << endl;
            w->zarejestrujZwrot();
        }
    }

    // 7. Sprawdzenie po zwrocie (Fizyczne powinny zniknac ze statusu Aktywne, Wirtualne zostaj¹)
    jan.pokazStanKonta();

    return 0;
}