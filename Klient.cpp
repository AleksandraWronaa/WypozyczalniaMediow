#include "Klient.h"
#include <iostream>

using namespace std;

Klient::Klient(string id, string im, string naz, string tel, string adr)
    : id(id), imie(im), nazwisko(naz), numerTelefonu(tel), adresZamieszkania(adr) {
}

vector<shared_ptr<Wypozyczenie>> Klient::getHistoriaWypozyczen() {
    return historiaWypozyczen;
}

void Klient::wypozycz(shared_ptr<Medium> medium) {
    // Generowanie ID wypozyczenia (UUID)
    string idWyp = "WYP-" + medium->getId() + "-" + to_string(time(nullptr));

    auto noweWypozyczenie = make_shared<Wypozyczenie>(idWyp, medium);
    historiaWypozyczen.push_back(noweWypozyczenie);

    cout << "SUKCES: Klient " << imie << " wypozyczyl: " << medium->getTytul() << endl;
}

void Klient::pokazStanKonta() {
    cout << "\n--- Stan konta: " << imie << " " << nazwisko << " (" << id << ") ---" << endl;
    for (const auto& w : historiaWypozyczen) {
        cout << " - " << w->getMedium()->getTytul()
            << " | Status: " << w->getStatusString() << endl;
    }
    cout << "----------------------------------------------\n" << endl;
}