#include "Wypozyczenie.h"
#include "Utils.h"

using namespace std;

Wypozyczenie::Wypozyczenie(string id, shared_ptr<Medium> m)
    : idWypozyczenia(id), medium(m) {

    dataWypozyczenia = time(nullptr);
    czyZwroconoFizycznie = false;

    // Logika z notatki UML: Domyœlnie oplaconeDo = data + 10 dni (dla wirtualnych istotne)
    // 10 dni * 24h * 3600s
    oplaconeDo = dataWypozyczenia + (10 * 24 * 3600);
}

void Wypozyczenie::zarejestrujZwrot() {
    if (!medium->isVirtual()) {
        czyZwroconoFizycznie = true;
        cout << ">> [SYSTEM] Zwrot fizyczny zarejestrowany." << endl;
    }
    else {
        cout << ">> [SYSTEM] To medium wirtualne - nie wymaga zwrotu fizycznego." << endl;
    }
}

// Zgodnie z ¿ó³t¹ notatk¹ na diagramie UML
bool Wypozyczenie::czyLicencjaAktywna() const {
    if (medium->isVirtual()) {
        // 1. Jeœli Wirtualne: sprawdza czy data dzisiejsza < oplaconeDo
        return time(nullptr) < oplaconeDo;
    }
    else {
        // 2. Jeœli Fizyczne: sprawdza czyZwroconoFizycznie == false
        return !czyZwroconoFizycznie;
    }
}

void Wypozyczenie::przedluzWypozyczenie(int dni) {
    oplaconeDo += (dni * 24 * 3600);
    cout << ">> [SYSTEM] Przedluzono waznosc wypozyczenia o " << dni << " dni." << endl;
}

shared_ptr<Medium> Wypozyczenie::getMedium() const { return medium; }

string Wypozyczenie::getStatusString() const {
    if (czyLicencjaAktywna()) {
        if (medium->isVirtual()) return "AKTYWNE (Oplacone do: " + dataNaString(oplaconeDo) + ")";
        else return "AKTYWNE (Uzytkownik posiada fizycznie)";
    }
    return "ZAKONCZONE / NIEAKTYWNE";
}