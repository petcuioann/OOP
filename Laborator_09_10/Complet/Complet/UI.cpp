#include "UI.h"
#include <iostream>

UI::UI(Service& s) : service(s) {}

void UI::addUI() {
    std::string cod, nume;
    double pret;
    std::cout << "Cod: "; std::cin >> cod;
    std::cout << "Nume: "; std::cin >> nume;
    std::cout << "Pret: "; std::cin >> pret;

    try {
        service.addProdus(cod, nume, pret);
        std::cout << "Produs adaugat cu succes.\n";
    }
    catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}

void UI::removeUI() {
    std::string cod;
    std::cout << "Cod: "; std::cin >> cod;

    if (service.removeProdus(cod))
        std::cout << "Produs sters.\n";
    else
        std::cout << "Produsul nu a fost gasit.\n";
}

void UI::updateUI() {
    std::string cod, numeNou;
    double pretNou;
    std::cout << "Cod: "; std::cin >> cod;
    std::cout << "Nume nou: "; std::cin >> numeNou;
    std::cout << "Pret nou: "; std::cin >> pretNou;

    if (service.updateProdus(cod, numeNou, pretNou))
        std::cout << "Produs actualizat.\n";
    else
        std::cout << "Produsul nu a fost gasit.\n";
}

void UI::listUI() {
    std::vector<Produs> produse = service.getAllProduse();
    if (produse.empty()) {
        std::cout << "Nu exista produse.\n";
        return;
    }

    std::cout << "\nLista produse:\n";
    for (const auto& p : produse) {
        std::cout << "Cod: " << p.getCod()
            << ", Nume: " << p.getNume()
            << ", Pret: " << p.getPret() << " lei\n";
    }
}

void UI::cumparaProdusUI() {
    std::string cod;
    double suma;
    std::cout << "Cod produs: "; std::cin >> cod;
    std::cout << "Suma introdusa (lei): "; std::cin >> suma;

    try {
        std::map<int, int> rest = service.cumparaProdus(cod, suma);
        std::cout << "Produs achizitionat cu succes!\n";
        if (rest.empty()) {
            std::cout << "Nu exista rest.\n";
        }
        else {
            std::cout << "Restul oferit:\n";
            for (auto it = rest.begin(); it != rest.end(); ++it) {
                if (it->first >= 100)  // 1 leu sau mai mare
                    std::cout << it->second << " bancnota(e) de " << it->first / 100 << " lei\n";
                else
                    std::cout << it->second << " moneda(e) de " << it->first << " bani\n";
            }
        }
    }
    catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}

void UI::setMonedeUI() {
    int m100, m50, m10, m5, m1, b50, b10, b1;
    std::cout << "Nr bancnote 100 lei: "; std::cin >> m100;
    std::cout << "Nr bancnote 50 lei: "; std::cin >> m50;
    std::cout << "Nr bancnote 10 lei: "; std::cin >> m10;
    std::cout << "Nr bancnote 5 lei: "; std::cin >> m5;
    std::cout << "Nr bancnote 1 leu: "; std::cin >> m1;
    std::cout << "Nr monede 50 bani: "; std::cin >> b50;
    std::cout << "Nr monede 10 bani: "; std::cin >> b10;
    std::cout << "Nr monede 1 ban: "; std::cin >> b1;

    std::map<int, int> monede = {
        {10000, m100},
        {5000, m50},
        {1000, m10},
        {500, m5},
        {100, m1},
        {50, b50},
        {10, b10},
        {1, b1}
    };

    service.setMonedeDisponibile(monede);
    std::cout << "Monede setate cu succes!\n";
}

void UI::start() {
    while (true) {
        std::cout << "\n--- Meniu Tonomat ---\n";
        std::cout << "1. Adauga produs\n";
        std::cout << "2. Sterge produs\n";
        std::cout << "3. Modifica produs\n";
        std::cout << "4. Afiseaza toate produsele\n";
        std::cout << "5. Cumpara produs\n";
        std::cout << "6. Seteaza monede disponibile\n";
        std::cout << "0. Iesire\n";
        std::cout << "Optiune: ";

        int opt;
        std::cin >> opt;

        switch (opt) {
        case 1: addUI(); break;
        case 2: removeUI(); break;
        case 3: updateUI(); break;
        case 4: listUI(); break;
        case 5: cumparaProdusUI(); break;
        case 6: setMonedeUI(); break;
        case 0: std::cout << "La revedere!\n"; return;
        default: std::cout << "Optiune invalida!\n";
        }
    }
}
