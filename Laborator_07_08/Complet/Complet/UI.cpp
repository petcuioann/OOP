#include "UI.h"
#include <iostream>


#include <cstring>

UI::UI(CheltuialaService& s, TranzactieService& t, CheltuialaApartamentService& u)
    : cheltuialaService(s), tranzactieService(t), cheltuialaApartamentService(u) {
}




void UI::start() {
    while (true) {
        std::cout << "\n=== MENIU PRINCIPAL ===\n";
        std::cout << "1. Cheltuieli Familie\n";
        std::cout << "2. Gestiune Conturi Bancare\n";
        std::cout << "3. Gestiune Apartamente\n";
        std::cout << "0. Iesire\n";
        std::cout << "Optiune: ";

        int opt;
        std::cin >> opt;

        switch (opt) {
        case 1: runCheltuieli(); break;
        case 2: runTranzactii(); break;
        case 3: runApartamente(); break;
        case 0: std::cout << "Iesire din aplicatie.\n"; return;
        default: std::cout << "Optiune invalida.\n";
        }
    }
}

void UI::runCheltuieli() {
    while (true) {
        std::cout << "\n--- Cheltuieli Familie ---\n";
        std::cout << "1. Adauga o cheltuiala pentru ziua curenta (introdu suma si tipul)\n";
        std::cout << "2. Insereaza o cheltuiala pentru o zi specifica (zi, suma, tip)\n";
        std::cout << "3. Sterge o cheltuiala dupa index (pozitia in lista)\n";
        std::cout << "4. Sterge toate cheltuielile efectuate intr-o anumita zi\n";
        std::cout << "5. Sterge toate cheltuielile dintr-un interval de zile (ex: 2 la 10)\n";
        std::cout << "6. Sterge toate cheltuielile de un anumit tip (ex: mancare)\n";
        std::cout << "7. Afiseaza toate cheltuielile curente\n";
        std::cout << "8. Afiseaza cheltuielile de un anumit tip\n";
        std::cout << "9. Afiseaza cheltuielile de un anumit tip care respecta o comparatie cu o suma (>, =, <)\n";
        std::cout << "10. Calculeaza suma totala pentru un anumit tip de cheltuiala\n";
        std::cout << "11. Afiseaza ziua cu cele mai mari cheltuieli totale\n";
        std::cout << "12. Sorteaza toate cheltuielile descrescator dupa zi (de la ultima zi catre prima)\n";
        std::cout << "13. Sorteaza cheltuielile unui anumit tip crescator dupa suma (cele mai mici primele)\n";
        std::cout << "14. Filtrare: pastreaza doar cheltuielile de un anumit tip (elimina restul)\n";
        std::cout << "15. Filtrare: pastreaza doar cheltuielile de un anumit tip care respecta o comparatie cu o suma\n";
        std::cout << "16. Anuleaza ultima operatie efectuata (Undo)\n";
        std::cout << "0. Revenire la meniul principal\n";
        std::cout << "Optiune: ";

        int opt;
        std::cin >> opt;

        switch (opt) {
        case 1: CheltuialaAddUI(); break;
        case 2: CheltuialaInsertUI(); break;
        case 3: CheltuialaDeleteUI(); break;
        case 4: CheltuialaRemoveByDayUI(); break;
        case 5: CheltuialaRemoveByIntervalUI(); break;
        case 6: CheltuialaRemoveByTipUI(); break;
        case 7: CheltuialaListUI(); break;
        case 8: CheltuialaListByTipUI(); break;
        case 9: CheltuialaListByTipAndSumUI(); break;
        case 10: CheltuialaSumByTipUI(); break;
        case 11: CheltuialaZiMaxUI(); break;
        case 12: CheltuialaSortByZiDescUI(); break;
        case 13: CheltuialaSortByTipAndSumAscUI(); break;
        case 14: CheltuialaFilterByTipUI(); break;
        case 15: CheltuialaFilterByTipAndSumUI(); break;
        case 16: CheltuialaUndoUI(); break;
        case 0: return;
        default: std::cout << "Optiune invalida.\n";
        }
    }
}

void UI::CheltuialaAddUI() {
    int zi = 1, suma;
    char tip[100];
    std::cout << "Suma: "; std::cin >> suma;
    std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 100);
    std::cout << (cheltuialaService.add(zi, suma, tip) ? "Adaugare reusita.\n" : "Eroare.\n");
}

void UI::CheltuialaInsertUI() {
    int zi, suma;
    char tip[100];
    std::cout << "Zi: "; std::cin >> zi;
    std::cout << "Suma: "; std::cin >> suma;
    std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 100);
    std::cout << (cheltuialaService.add(zi, suma, tip) ? "Inserare reusita.\n" : "Eroare.\n");
}

void UI::CheltuialaDeleteUI() {
    int idx;
    std::cout << "Index: "; std::cin >> idx;
    std::cout << (cheltuialaService.removeByIndex(idx) ? "Sters.\n" : "Index invalid.\n");
}

void UI::CheltuialaRemoveByDayUI() {
    int zi;
    std::cout << "Zi: "; std::cin >> zi;
    std::cout << (cheltuialaService.removeByDay(zi) ? "Sters.\n" : "Nimic de sters.\n");
}

void UI::CheltuialaRemoveByIntervalUI() {
    int zi1, zi2;
    std::cout << "De la ziua: "; std::cin >> zi1;
    std::cout << "Pana la ziua: "; std::cin >> zi2;
    std::cout << (cheltuialaService.removeByInterval(zi1, zi2) ? "Stergere realizata.\n" : "Nimic de sters.\n");
}

void UI::CheltuialaRemoveByTipUI() {
    char tip[100];
    std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 100);
    std::cout << (cheltuialaService.removeByTip(tip) ? "Sters.\n" : "Nimic gasit.\n");
}

void UI::CheltuialaListUI() const {
    int size;
    Cheltuiala* l = cheltuialaService.getAll(size);
    for (int i = 0; i < size; ++i)
        std::cout << i << ". Zi: " << l[i].getZi() << ", Suma: " << l[i].getSuma() << ", Tip: " << l[i].getTip() << "\n";
}

void UI::CheltuialaListByTipUI() {
    char tip[100]; std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 100);
    int size;
    Cheltuiala* l = cheltuialaService.getAllByTip(tip, size);
    for (int i = 0; i < size; ++i)
        std::cout << i << ". Zi: " << l[i].getZi() << ", Suma: " << l[i].getSuma() << ", Tip: " << l[i].getTip() << "\n";
    delete[] l;
}

void UI::CheltuialaListByTipAndSumUI() {
    char tip[100]; char op; int suma;
    std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 100);
    std::cout << "Operator (<, =, >): "; std::cin >> op;
    std::cout << "Suma: "; std::cin >> suma;
    int size;
    Cheltuiala* l = cheltuialaService.getAllByTipAndSumCmp(tip, suma, op, size);
    for (int i = 0; i < size; ++i)
        std::cout << i << ". Zi: " << l[i].getZi() << ", Suma: " << l[i].getSuma() << ", Tip: " << l[i].getTip() << "\n";
    delete[] l;
}

void UI::CheltuialaSumByTipUI() {
    char tip[100]; std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 100);
    std::cout << "Total: " << cheltuialaService.sumaByTip(tip) << "\n";
}

void UI::CheltuialaZiMaxUI() {
    std::cout << "Ziua cu cele mai mari cheltuieli: " << cheltuialaService.ziuaCuSumaMaxima() << "\n";
}

void UI::CheltuialaSortByZiDescUI() {
    int size;
    Cheltuiala* l = cheltuialaService.sortByZiDesc(size);
    for (int i = 0; i < size; ++i)
        std::cout << i << ". Zi: " << l[i].getZi() << ", Suma: " << l[i].getSuma() << ", Tip: " << l[i].getTip() << "\n";
    delete[] l;
}

void UI::CheltuialaSortByTipAndSumAscUI() {
    char tip[100]; std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 100);
    int size;
    Cheltuiala* l = cheltuialaService.sortByTipAndSumAsc(tip, size);
    for (int i = 0; i < size; ++i)
        std::cout << i << ". Zi: " << l[i].getZi() << ", Suma: " << l[i].getSuma() << ", Tip: " << l[i].getTip() << "\n";
    delete[] l;
}

void UI::CheltuialaFilterByTipUI() {
    char tip[100]; std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 100);
    cheltuialaService.filterByTip(tip);
    std::cout << "Filtrare realizata.\n";
}

void UI::CheltuialaFilterByTipAndSumUI() {
    char tip[100]; char op; int suma;
    std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 100);
    std::cout << "Operator (<, =, >): "; std::cin >> op;
    std::cout << "Suma: "; std::cin >> suma;
    cheltuialaService.filterByTipAndSumCmp(tip, suma, op);
    std::cout << "Filtrare realizata.\n";
}

void UI::CheltuialaUndoUI() {
    std::cout << (cheltuialaService.undo() ? "Undo efectuat.\n" : "Nu mai exista stari anterioare.\n");
}

void UI::runTranzactii() {
    while (true) {
        std::cout << "\n--- Gestiune Conturi Bancare ---\n";
        std::cout << "1. Adauga tranzactie (zi curenta)\n";
        std::cout << "2. Insereaza tranzactie (zi specificata)\n";
        std::cout << "3. Sterge tranzactii dintr-o zi\n";
        std::cout << "4. Sterge tranzactii din interval de zile\n";
        std::cout << "5. Sterge tranzactii dupa tip (in/out)\n";
        std::cout << "6. Inlocuieste suma unei tranzactii (zi + tip + descriere)\n";
        std::cout << "7. Afiseaza toate tranzactiile\n";
        std::cout << "8. Afiseaza tranzactii dupa tip\n";
        std::cout << "9. Afiseaza tranzactii dupa comparatie suma\n";
        std::cout << "10. Sold in ziua Z\n";
        std::cout << "11. Suma totala dupa tip (in/out)\n";
        std::cout << "12. Cea mai mare tranzactie out intr-o zi\n";
        std::cout << "13. Filtrare dupa tip\n";
        std::cout << "14. Filtrare dupa tip si valoare maxima\n";
        std::cout << "15. Undo\n";
        std::cout << "0. Inapoi\n";
        std::cout << "Optiune: ";

        int opt;
        std::cin >> opt;

        switch (opt) {
        case 1: TranzactieAddUI(); break;
        case 2: TranzactieInsertUI(); break;
        case 3: TranzactieDeleteZiUI(); break;
        case 4: TranzactieDeleteIntervalUI(); break;
        case 5: TranzactieDeleteTipUI(); break;
        case 6: TranzactieUpdateUI(); break;
        case 7: TranzactieListUI(); break;
        case 8: TranzactieListByTipUI(); break;
        case 9: TranzactieListBySumCmpUI(); break;
        case 10: TranzactieSoldZiUI(); break;
        case 11: TranzactieSumaTipUI(); break;
        case 12: TranzactieMaxOutZiUI(); break;
        case 13: TranzactieFilterTipUI(); break;
        case 14: TranzactieFilterTipValLessUI(); break;
        case 15: TranzactieUndoUI(); break;
        case 0: return;
        default: std::cout << "Optiune invalida.\n";
        }
    }
}

void UI::TranzactieAddUI() {
    int suma;
    char tip[10], descriere[100];
    std::cout << "Suma: "; std::cin >> suma;
    std::cin.ignore();
    std::cout << "Tip (in/out): "; std::cin.getline(tip, 10);
    std::cout << "Descriere: "; std::cin.getline(descriere, 100);

    time_t now = time(nullptr);
    struct tm now_tm;

    // Using localtime_s for safer time conversion
    if (localtime_s(&now_tm, &now) == 0) {
        int ziCurenta = now_tm.tm_mday;

        if (tranzactieService.add(ziCurenta, suma, tip, descriere))
            std::cout << "Tranzactie adaugata.\n";
        else
            std::cout << "Eroare la adaugare.\n";
    }
    else {
        std::cerr << "Failed to retrieve local time.\n";
    }
}


void UI::TranzactieInsertUI() {
    int zi, suma;
    char tip[10], descriere[100];
    std::cout << "Zi: "; std::cin >> zi;
    std::cout << "Suma: "; std::cin >> suma;
    std::cin.ignore();
    std::cout << "Tip (in/out): "; std::cin.getline(tip, 10);
    std::cout << "Descriere: "; std::cin.getline(descriere, 100);

    if (tranzactieService.add(zi, suma, tip, descriere))
        std::cout << "Tranzactie inserata.\n";
    else
        std::cout << "Eroare la inserare.\n";
}

void UI::TranzactieDeleteZiUI() {
    int zi;
    std::cout << "Zi: "; std::cin >> zi;
    tranzactieService.removeByZi(zi);
    std::cout << "Stergere finalizata.\n";
}

void UI::TranzactieDeleteIntervalUI() {
    int zi1, zi2;
    std::cout << "Interval: "; std::cin >> zi1 >> zi2;
    tranzactieService.removeByInterval(zi1, zi2);
    std::cout << "Tranzactii sterse din interval.\n";
}

void UI::TranzactieDeleteTipUI() {
    char tip[10];
    std::cin.ignore();
    std::cout << "Tip (in/out): "; std::cin.getline(tip, 10);
    tranzactieService.removeByTip(tip);
    std::cout << "Tranzactii sterse dupa tip.\n";
}

void UI::TranzactieUpdateUI() {
    int zi, sumaNoua;
    char tip[10], descriere[100];

    std::cout << "Zi: "; std::cin >> zi;
    std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 10);
    std::cout << "Descriere: "; std::cin.getline(descriere, 100);
    std::cout << "Noua suma: "; std::cin >> sumaNoua;

    if (tranzactieService.update(zi, tip, descriere, sumaNoua))
        std::cout << "Tranzactie actualizata.\n";
    else
        std::cout << "Tranzactie nu a fost gasita.\n";
}

void UI::TranzactieListUI() {
    int size;
    Tranzactie* list = tranzactieService.getAll(size);
    for (int i = 0; i < size; ++i)
        std::cout << i << ". Zi: " << list[i].getZi()
        << ", Suma: " << list[i].getSuma()
        << ", Tip: " << list[i].getTip()
        << ", Descriere: " << list[i].getDescriere() << "\n";
}

void UI::TranzactieListByTipUI() {
    char tip[10];
    std::cin.ignore();
    std::cout << "Tip (in/out): "; std::cin.getline(tip, 10);
    int size;
    Tranzactie* list = tranzactieService.getAllByTip(tip, size);
    for (int i = 0; i < size; ++i)
        std::cout << list[i].getZi() << " " << list[i].getSuma()
        << " " << list[i].getDescriere() << "\n";
    delete[] list;
}

void UI::TranzactieListBySumCmpUI() {
    char op;
    int suma;
    std::cout << "Operator (< = >): "; std::cin >> op;
    std::cout << "Suma: "; std::cin >> suma;

    int size;
    Tranzactie* list = tranzactieService.getAllBySumCmp(suma, op, size);
    for (int i = 0; i < size; ++i)
        std::cout << list[i].getZi() << " " << list[i].getSuma()
        << " " << list[i].getTip() << " "
        << list[i].getDescriere() << "\n";
    delete[] list;
}

void UI::TranzactieSoldZiUI() {
    int zi;
    std::cout << "Zi: "; std::cin >> zi;
    std::cout << "Soldul este: " << tranzactieService.soldZi(zi) << "\n";
}

void UI::TranzactieSumaTipUI() {
    char tip[10];
    std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 10);
    std::cout << "Suma totala: " << tranzactieService.sumaByTip(tip) << "\n";
}

void UI::TranzactieMaxOutZiUI() {
    int zi;
    std::cout << "Zi: "; std::cin >> zi;
    Tranzactie t = tranzactieService.maxOutInZi(zi);
    std::cout << "Max out: " << t.getSuma() << " pentru " << t.getDescriere() << "\n";
}

void UI::TranzactieFilterTipUI() {
    char tip[10];
    std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 10);
    tranzactieService.filterByTip(tip);
    std::cout << "Filtrare aplicata.\n";
}

void UI::TranzactieFilterTipValLessUI() {
    char tip[10];
    int val;
    std::cin.ignore();
    std::cout << "Tip: "; std::cin.getline(tip, 10);
    std::cout << "Valoare max: "; std::cin >> val;
    tranzactieService.filterByTipAndValLess(tip, val);
    std::cout << "Filtrare aplicata.\n";
}

void UI::TranzactieUndoUI() {
    if (tranzactieService.undo())
        std::cout << "Undo reusit.\n";
    else
        std::cout << "Nu mai exista stari anterioare.\n";
}


void UI::runApartamente() {
    while (true) {
        std::cout << "\n--- Gestiune Apartamente ---\n";
        std::cout << "1. Adauga cheltuiala\n";
        std::cout << "2. Inlocuire suma cheltuiala (numar ap + tip)\n";
        std::cout << "3. Sterge cheltuiala dupa index\n";
        std::cout << "4. Sterge toate cheltuielile apartamentului\n";
        std::cout << "5. Sterge cheltuielile pe interval [a,b]\n";
        std::cout << "6. Sterge cheltuielile pentru un tip\n";
        std::cout << "7. Afiseaza toate cheltuielile\n";
        std::cout << "8. Afiseaza cheltuielile pentru un apartament\n";
        std::cout << "9. Afiseaza cheltuielile cu comparatie pe suma (<, =, >)\n";
        std::cout << "10. Suma totala pe tip\n";
        std::cout << "11. Cea mai mare cheltuiala pentru un apartament\n";
        std::cout << "12. Sorteaza descrescator cheltuielile pe tip\n";
        std::cout << "13. Filtrare pe tip\n";
        std::cout << "14. Filtrare pe suma < valoare\n";
        std::cout << "15. Undo\n";
        std::cout << "0. Inapoi\n";
        std::cout << "Optiune: ";

        int opt;
        std::cin >> opt;

        switch (opt) {
        case 1: ApartamentAddUI(); break;
        case 2: ApartamentUpdateUI(); break;
        case 3: ApartamentRemoveByIndexUI(); break;
        case 4: ApartamentRemoveByNumarUI(); break;
        case 5: ApartamentRemoveByIntervalUI(); break;
        case 6: ApartamentRemoveByTipUI(); break;
        case 7: ApartamentListUI(); break;
        case 8: ApartamentListByNumarUI(); break;
        case 9: ApartamentListBySumaCmpUI(); break;
        case 10: ApartamentSumaByTipUI(); break;
        case 11: ApartamentMaxInApUI(); break;
        case 12: ApartamentSortByTipDescUI(); break;
        case 13: ApartamentFilterByTipUI(); break;
        case 14: ApartamentFilterByValLessUI(); break;
        case 15: ApartamentUndoUI(); break;
        case 0: return;
        default: std::cout << "Optiune invalida.\n";
        }
    }
}

void UI::ApartamentAddUI() {
    int ap, suma;
    char tip[100];
    std::cout << "Numar apartament: "; std::cin >> ap;
    std::cout << "Tip cheltuiala: "; std::cin >> tip;
    std::cout << "Suma: "; std::cin >> suma;

    if (cheltuialaApartamentService.add(ap, suma, tip))
        std::cout << "Cheltuiala adaugata.\n";
    else
        std::cout << "Eroare la adaugare.\n";
}

void UI::ApartamentUpdateUI() {
    int ap, sumaNoua;
    char tip[100];
    std::cout << "Numar apartament: "; std::cin >> ap;
    std::cout << "Tip: "; std::cin >> tip;
    std::cout << "Noua suma: "; std::cin >> sumaNoua;

    if (cheltuialaApartamentService.update(ap, tip, sumaNoua))
        std::cout << "Cheltuiala actualizata.\n";
    else
        std::cout << "Cheltuiala nu a fost gasita.\n";
}

void UI::ApartamentRemoveByIndexUI() {
    int index;
    std::cout << "Index: "; std::cin >> index;
    if (cheltuialaApartamentService.removeByIndex(index))
        std::cout << "Cheltuiala stearsa.\n";
    else
        std::cout << "Index invalid.\n";
}

void UI::ApartamentRemoveByNumarUI() {
    int ap;
    std::cout << "Numar apartament: "; std::cin >> ap;
    cheltuialaApartamentService.removeByApartament(ap);
    std::cout << "Stergere finalizata.\n";
}

void UI::ApartamentRemoveByIntervalUI() {
    int a, b;
    std::cout << "Interval [a b]: "; std::cin >> a >> b;
    cheltuialaApartamentService.removeByInterval(a, b);
    std::cout << "Stergere in interval efectuata.\n";
}

void UI::ApartamentRemoveByTipUI() {
    char tip[100];
    std::cout << "Tip: "; std::cin >> tip;
    cheltuialaApartamentService.removeByTip(tip);
    std::cout << "Stergere dupa tip efectuata.\n";
}

void UI::ApartamentListUI() {
    int size;
    CheltuialaApartament* all = cheltuialaApartamentService.getAll(size);
    for (int i = 0; i < size; ++i)
        std::cout << i << ". Ap: " << all[i].getApartament()
        << ", Suma: " << all[i].getSuma()
        << ", Tip: " << all[i].getTip() << "\n";
}

void UI::ApartamentListByNumarUI() {
    int ap;
    std::cout << "Numar apartament: "; std::cin >> ap;
    int size;
    CheltuialaApartament* list = cheltuialaApartamentService.getByApartament(ap, size);
    for (int i = 0; i < size; ++i)
        std::cout << list[i].getApartament() << ", " << list[i].getTip()
        << ": " << list[i].getSuma() << "\n";
    delete[] list;
}

void UI::ApartamentListBySumaCmpUI() {
    char op;
    int suma;
    std::cout << "Operator (<, =, >): "; std::cin >> op;
    std::cout << "Suma: "; std::cin >> suma;

    int size;
    CheltuialaApartament* list = cheltuialaApartamentService.getBySumaCmp(suma, op, size);
    for (int i = 0; i < size; ++i)
        std::cout << list[i].getApartament() << ", " << list[i].getTip()
        << ": " << list[i].getSuma() << "\n";
    delete[] list;
}

void UI::ApartamentSumaByTipUI() {
    char tip[100];
    std::cout << "Tip: "; std::cin >> tip;
    std::cout << "Suma totala: " << cheltuialaApartamentService.sumaByTip(tip) << "\n";
}

void UI::ApartamentMaxInApUI() {
    int ap;
    std::cout << "Apartament: "; std::cin >> ap;
    CheltuialaApartament c = cheltuialaApartamentService.maxInApartament(ap);
    std::cout << "Max: " << c.getTip() << " - " << c.getSuma() << " RON\n";
}

void UI::ApartamentSortByTipDescUI() {
    char tip[100];
    std::cout << "Tip: "; std::cin >> tip;

    int size;
    CheltuialaApartament* list = cheltuialaApartamentService.sortByTipDesc(tip, size);
    for (int i = 0; i < size; ++i)
        std::cout << list[i].getApartament() << ", " << list[i].getSuma() << " RON\n";
    delete[] list;
}

void UI::ApartamentFilterByTipUI() {
    char tip[100];
    std::cout << "Tip: "; std::cin >> tip;
    cheltuialaApartamentService.filterByTip(tip);
    std::cout << "Filtrare aplicata.\n";
}

void UI::ApartamentFilterByValLessUI() {
    int val;
    std::cout << "Valoare maxima: "; std::cin >> val;
    cheltuialaApartamentService.filterByValLess(val);
    std::cout << "Filtrare aplicata.\n";
}

void UI::ApartamentUndoUI() {
    if (cheltuialaApartamentService.undo())
        std::cout << "Undo efectuat cu succes.\n";
    else
        std::cout << "Nu se mai poate face undo.\n";
}
