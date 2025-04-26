#include "UI.h"
#include <iostream>

using namespace std;

UI::UI() {}

void UI::afisareMeniu() const {
    cout << "\n===== Meniu Aplicatie =====\n";
    cout << "1. Adaugare cerc\n";
    cout << "2. Stergere cerc\n";
    cout << "3. Afisare lista de cercuri\n";
    cout << "4. Afisare cel mai mare cerc\n";
    cout << "5. Stergere toate cercurile\n";
    cout << "0. Iesire\n";
    cout << ">> Alegeti o optiune: ";
}

void UI::adaugareCerc() {
    double raza;
    cout << ">> Introduceti raza cercului: ";
    cin >> raza;
    service.adaugaCerc(raza);
    cout << "Cerc adaugat cu succes!\n";
}

void UI::stergereCerc() {
    int index;
    cout << ">> Introduceti indexul cercului de sters: ";
    cin >> index;
    service.stergeCerc(index - 1);
}

void UI::afisareCercuri() {
    service.afisareCercuri();
}

void UI::afisareCelMaiMareCerc() {
    try {
        Cerc celMaiMare = service.getCelMaiMareCerc();
        cout << "Cel mai mare cerc are raza: " << celMaiMare.getRaza() << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void UI::stergereToateCercurile() {
    service.golesteRepository();
}

void UI::start() {
    int optiune;
    do {
        afisareMeniu();
        cin >> optiune;
        switch (optiune) {
        case 1: adaugareCerc(); break;
        case 2: stergereCerc(); break;
        case 3: afisareCercuri(); break;
        case 4: afisareCelMaiMareCerc(); break;
        case 5: stergereToateCercurile(); break;
        case 0: cout << "Iesire din aplicatie...\n"; break;
        default: cout << "Optiune invalida! Incercati din nou.\n"; break;
        }
    } while (optiune != 0);
}
