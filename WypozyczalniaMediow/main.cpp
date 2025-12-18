#include <iostream>
#include <memory>
#include "MediumTypy.h"
#include "Klient.h"

using namespace std;

int main() {
    // 1. Tworzenie mediów (Symulacja klas pochodnych, u¿ywamy klas poœrednich jako konkretnych na potrzeby demo)
    // ID jako string (UUID)
    auto ksiazka = make_shared<MediumFizyczne>(
        "UUID-BOOK-001", "Wiedzmin: Krew Elfow", 1994, 18,
        15.99, // Cena
        5,     // Stan magazynowy
        "A1"   // Lokalizacja
    );

    auto gra = make_shared<MediumWirtualne>(
        "UUID-GAME-002", "Minecraft", 2011, 7,
        49.99, // Cena
        500.0, // Rozmiar MB
        "https://store.minecraft.net/download",
        "EXE"
    );

    // 2. Tworzenie klienta
    Klient jan("UUID-KLIENT-100", "Jan", "Kowalski", "123-456-789", "Kwiatowa 5, Warszawa");

    // 3. Wypo¿yczenia
    jan.wypozycz(ksiazka);
    jan.wypozycz(gra);

    // 4. Sprawdzenie stanu (Oba aktywne)
    jan.pokazStanKonta();

    // 5. Test metody wirtualnej generujLink() dla medium wirtualnego
    cout << ">> Link do gry: " << gra->generujLink() << endl;

    // 6. Zwrot fizyczny (Symulacja dzia³ania pracownika na obiekcie Wypozyczenie)
    // Pobieramy historiê, szukamy ksi¹¿ki i zwracamy
    auto historia = jan.getHistoriaWypozyczen();
    for (auto& w : historia) {
        // Jeœli to medium fizyczne i jest aktywne
        if (!w->getMedium()->isVirtual() && w->czyLicencjaAktywna()) {
            w->zarejestrujZwrot();
        }
    }

    // 7. Sprawdzenie po zwrocie
    jan.pokazStanKonta();

    return 0;
}