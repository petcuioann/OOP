#include "UI.h"
#include <iostream>

void UI::start() {
    int choice;

    while (true) {
        std::cout << "\n----- Meniu -----\n";
        std::cout << "1. Cerc\n";
        std::cout << "2. Dreptunghi\n";
        std::cout << "3. Numar Complex\n";
        std::cout << "4. Patrat\n";
        std::cout << "5. Triunghi\n";
        std::cout << "0. Iesire\n";
        std::cout << "Alege o optiune: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manageCerc();
            break;
        case 2:
			manageDreptunghi();
            break;
        case 3:
            manageNumarComplex();
            break;
        case 4:
			managePatrat();
            break;
        case 5:
			manageTriunghi();
            break;
        case 0:
            std::cout << "Iesire...\n";
            return;
        default:
            std::cout << "Optiune invalida! Incearca din nou.\n";
        }
    }
}



void UI::manageCerc() {
    int subChoice;
    while (true) {
        std::cout << "\n--- Meniu Cerc ---\n";
        std::cout << "1. Adauga Cerc\n";
        std::cout << "2. Sterge Cerc\n";
        std::cout << "3. Afiseaza Cercul cu cea mai mare raza\n";
        std::cout << "4. Afiseaza Secventa Maxima de Cercuri cu Raza Egala\n";
        std::cout << "5. Afiseaza Toate Cercurile\n";
        std::cout << "6. Afiseaza Cercurile din cadranul 1\n";
        std::cout << "0. Inapoi\n";
        std::cout << "Alege o optiune: ";
        std::cin >> subChoice;

        switch (subChoice) {
        case 1: {
            double raza;
            int x, y;
            std::cout << "Introdu raza cercului: ";
            std::cin >> raza;
            std::cout << "Introdu coordonatele centrului (x y): ";
            std::cin >> x >> y;
            cercService.add(Cerc(raza, Punct<int>(x, y))); // Now includes center coordinates
            std::cout << "Cerc adaugat!\n";
            break;
        }
        case 2: {
            double raza;
            std::cout << "Introdu raza cercului de sters: ";
            std::cin >> raza;
            if (cercService.remove(Cerc(raza))) {
                std::cout << "Cerc sters!\n";
            }
            else {
                std::cout << "Cercul nu a fost gasit!\n";
            }
            break;
        }
        case 3: {
            Cerc maxCerc = cercService.getMaxElement();
            std::cout << "Cercul cu raza maxima: " << maxCerc.getRaza() << " si centru ("
                << maxCerc.getCentru().getX() << ", " << maxCerc.getCentru().getY() << ")\n";
            break;
        }
        case 4: {
            Repository<Cerc> maxSequence = cercService.getMaxEqualSequence();
            std::cout << "Cea mai lunga secventa de cercuri cu raza egala:\n";
            int size = maxSequence.getSize();
            for (int i = 0; i < size; ++i) {
                std::cout << "Cerc cu raza " << maxSequence.get(i).getRaza()
                    << " si centru (" << maxSequence.get(i).getCentru().getX()
                    << ", " << maxSequence.get(i).getCentru().getY() << ")\n";
            }
            break;
        }
        case 5: {
            Repository<Cerc> allElem = cercService.getAll();
            std::cout << "Cercurile adaugate sunt:\n";
            for (int i = 0; i < allElem.getSize(); ++i) {
                std::cout << "Cerc cu raza " << allElem.get(i).getRaza()
                    << " si centru (" << allElem.get(i).getCentru().getX()
                    << ", " << allElem.get(i).getCentru().getY() << ")\n";
            }
            break;
        }
        case 6: {
            Repository<Cerc> filteredCercuri = cercService.filterByFirstQuadrant();
            std::cout << "Cercurile care au centrul în cadranul 1:\n";
            for (int i = 0; i < filteredCercuri.getSize(); ++i) {
                std::cout << "Cerc cu raza " << filteredCercuri.get(i).getRaza()
                    << " si centru (" << filteredCercuri.get(i).getCentru().getX()
                    << ", " << filteredCercuri.get(i).getCentru().getY() << ")\n";
            }
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Optiune invalida! Incearca din nou.\n";
        }
    }
}



void UI::manageDreptunghi() {
    int subChoice;
    while (true) {
        std::cout << "\n--- Meniu Dreptunghi ---\n";
        std::cout << "1. Adauga Dreptunghi\n";
        std::cout << "2. Sterge Dreptunghi\n";
        std::cout << "3. Afiseaza Dreptunghiul cu Aria Maxima\n";
        std::cout << "4. Afiseaza Secventa Maxima de Dreptunghiuri cu Aria Egala\n";
        std::cout << "5. Afiseaza Toate Dreptunghiurile\n";
        std::cout << "6. Afiseaza Dreptunghiurile din cadranul 1\n"; // New option
        std::cout << "0. Inapoi\n";
        std::cout << "Alege o optiune: ";
        std::cin >> subChoice;

        switch (subChoice) {
        case 1: {
            int x, y;
            double latime, inaltime;

            std::cout << "Introdu coordonatele coltului stanga jos (x y): ";
            std::cin >> x >> y;
            std::cout << "Introdu latimea: ";
            std::cin >> latime;
            std::cout << "Introdu inaltimea: ";
            std::cin >> inaltime;

            dreptunghiService.add(Punct<int>(x, y), latime, inaltime);
            std::cout << "Dreptunghi adaugat!\n";
            break;
        }
        case 2: {
            int index;
            std::cout << "Introdu indexul dreptunghiului de sters: ";
            std::cin >> index;
            if (dreptunghiService.remove(index)) {
                std::cout << "Dreptunghi sters!\n";
            }
            else {
                std::cout << "Dreptunghiul nu a fost gasit!\n";
            }
            break;
        }
        case 3: {
            Dreptunghi maxDreptunghi = dreptunghiService.getMax();
            std::cout << "Dreptunghiul cu aria maxima: Colt Stanga Jos ("
                << maxDreptunghi.getColtStangaJos().getX() << ", "
                << maxDreptunghi.getColtStangaJos().getY() << "), Latime = "
                << maxDreptunghi.getLatime() << ", Inaltime = "
                << maxDreptunghi.getInaltime() << "\n";
            break;
        }
        case 4: {
            int length;
            Dreptunghi* maxSequence = dreptunghiService.getMaxEqualSequence(length);
            if (length > 0) {
                std::cout << "Cea mai lunga secventa de dreptunghiuri cu aria egala:\n";
                for (int i = 0; i < length; ++i) {
                    std::cout << "Dreptunghi " << i + 1 << ": Colt Stanga Jos ("
                        << maxSequence[i].getColtStangaJos().getX() << ", "
                        << maxSequence[i].getColtStangaJos().getY() << "), Latime = "
                        << maxSequence[i].getLatime() << ", Inaltime = "
                        << maxSequence[i].getInaltime() << "\n";
                }
            }
            else {
                std::cout << "Nu exista secvente de dreptunghiuri cu aria egala.\n";
            }
            break;
        }
        case 5: {
            int size;
            Dreptunghi* allElem = dreptunghiService.getAll(size);
            std::cout << "Dreptunghiurile adaugate sunt:\n";
            for (int i = 0; i < size; ++i) {
                std::cout << "Dreptunghi " << i + 1 << ": Colt Stanga Jos ("
                    << allElem[i].getColtStangaJos().getX() << ", "
                    << allElem[i].getColtStangaJos().getY() << "), Latime = "
                    << allElem[i].getLatime() << ", Inaltime = "
                    << allElem[i].getInaltime() << "\n";
            }
            break;
        }
        case 6: { // New case for filtering rectangles in quadrant 1
            Repository<Dreptunghi> filteredDreptunghi = dreptunghiService.filterByFirstQuadrant();
            std::cout << "Dreptunghiurile care au coltul stanga jos în cadranul 1:\n";
            for (int i = 0; i < filteredDreptunghi.getSize(); ++i) {
                std::cout << "Dreptunghi " << i + 1 << ": Colt Stanga Jos ("
                    << filteredDreptunghi.get(i).getColtStangaJos().getX() << ", "
                    << filteredDreptunghi.get(i).getColtStangaJos().getY() << "), Latime = "
                    << filteredDreptunghi.get(i).getLatime() << ", Inaltime = "
                    << filteredDreptunghi.get(i).getInaltime() << "\n";
            }
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Optiune invalida! Incearca din nou.\n";
        }
    }
}



void UI::manageNumarComplex() {
    int subChoice;
    while (true) {
        std::cout << "\n--- Meniu Numar Complex ---\n";
        std::cout << "1. Adauga Numar Complex\n";
        std::cout << "2. Sterge Numar Complex\n";
        std::cout << "3. Afiseaza Elementul cu Modul Maxim\n";
        std::cout << "4. Afiseaza Secventa Maxima de Module Egale\n";
        std::cout << "5. Afiseaza Toate Numerele Complexe\n";
        std::cout << "6. Afiseaza Numerele Complexe din cadranul 1\n"; // New option
        std::cout << "0. Inapoi\n";
        std::cout << "Alege o optiune: ";
        std::cin >> subChoice;

        switch (subChoice) {
        case 1: {
            double re, im;
            std::cout << "Introdu partea reala: ";
            std::cin >> re;
            std::cout << "Introdu partea imaginara: ";
            std::cin >> im;
            complexService.add(NumarComplex(re, im));
            std::cout << "Numar Complex adaugat!\n";
            break;
        }
        case 2: {
            double re, im;
            std::cout << "Introdu partea reala: ";
            std::cin >> re;
            std::cout << "Introdu partea imaginara: ";
            std::cin >> im;
            if (complexService.remove(NumarComplex(re, im))) {
                std::cout << "Numar Complex sters!\n";
            }
            else {
                std::cout << "Numarul Complex nu a fost gasit!\n";
            }
            break;
        }
        case 3: {
            NumarComplex maxElement = complexService.getMaxElement();
            std::cout << "Numarul cu modul maxim: " << maxElement.getRe() << " + "
                << maxElement.getIm() << "i\n";
            break;
        }
        case 4: {
            Repository<NumarComplex> maxSequence = complexService.getMaxEqualSequence();
            std::cout << "Cea mai lunga secventa de module egale:\n";
            int size = maxSequence.getSize();
            for (int i = 0; i < size; ++i) {
                NumarComplex numar = maxSequence.get(i);
                std::cout << numar.getRe() << " + " << numar.getIm() << "i\n";
            }
            break;
        }
        case 5: {
            Repository<NumarComplex> allElem = complexService.getAll();
            std::cout << "Numerele complexe adaugate sunt:\n";
            for (int i = 0; i < allElem.getSize(); ++i) {
                NumarComplex numar = allElem.get(i);
                std::cout << numar.getRe() << " + " << numar.getIm() << "i\n";
            }
            break;
        }
        case 6: { // New case for filtering complex numbers in quadrant 1
            Repository<NumarComplex> filteredComplex = complexService.filterByFirstQuadrant();
            std::cout << "Numerele complexe care sunt în cadranul 1:\n";
            for (int i = 0; i < filteredComplex.getSize(); ++i) {
                NumarComplex numar = filteredComplex.get(i);
                std::cout << numar.getRe() << " + " << numar.getIm() << "i\n";
            }
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Optiune invalida! Incearca din nou.\n";
        }
    }
}



void UI::managePatrat() {
    int subChoice;
    while (true) {
        std::cout << "\n--- Meniu Patrat ---\n";
        std::cout << "1. Adauga Patrat\n";
        std::cout << "2. Sterge Patrat\n";
        std::cout << "3. Afiseaza Patratul cu cea mai mare latura\n";
        std::cout << "4. Afiseaza Secventa Maxima de Patrate cu Latura Egala\n";
        std::cout << "5. Afiseaza Toate Patratele\n";
        std::cout << "6. Afiseaza Patratele din cadranul 1\n"; // Added new option
        std::cout << "0. Inapoi\n";
        std::cout << "Alege o optiune: ";
        std::cin >> subChoice;

        switch (subChoice) {
        case 1: {
            int x, y;
            double latura;

            std::cout << "Introdu coordonatele coltului stanga jos (x y): ";
            std::cin >> x >> y;
            std::cout << "Introdu latura patratului: ";
            std::cin >> latura;

            patratService.add(Punct<int>(x, y), latura);
            std::cout << "Patrat adaugat!\n";
            break;
        }
        case 2: {
            int x, y;
            double latura;

            std::cout << "Introdu coordonatele coltului stanga jos (x y) ale patratului de sters: ";
            std::cin >> x >> y;
            std::cout << "Introdu latura: ";
            std::cin >> latura;

            if (patratService.remove(Patrat(Punct<int>(x, y), latura))) {
                std::cout << "Patrat sters!\n";
            }
            else {
                std::cout << "Patratul nu a fost gasit!\n";
            }
            break;
        }
        case 3: {
            Patrat maxPatrat = patratService.getMaxElement();
            std::cout << "Patratul cu latura maxima: Colt Stanga Jos ("
                << maxPatrat.getColtStangaJos().getX() << ", "
                << maxPatrat.getColtStangaJos().getY() << "), Latura = "
                << maxPatrat.getLatura() << "\n";
            break;
        }
        case 4: {
            Repository<Patrat> maxSequence = patratService.getMaxEqualSequence();
            std::cout << "Cea mai lunga secventa de patrate cu latura egala:\n";
            int size = maxSequence.getSize();
            for (int i = 0; i < size; ++i) {
                std::cout << "Patrat " << i + 1 << ": Colt Stanga Jos ("
                    << maxSequence.get(i).getColtStangaJos().getX() << ", "
                    << maxSequence.get(i).getColtStangaJos().getY() << "), Latura = "
                    << maxSequence.get(i).getLatura() << "\n";
            }
            break;
        }
        case 5: {
            Repository<Patrat> allElem = patratService.getAll();
            std::cout << "Patratele adaugate sunt:\n";
            for (int i = 0; i < allElem.getSize(); ++i) {
                std::cout << "Patrat " << i + 1 << ": Colt Stanga Jos ("
                    << allElem.get(i).getColtStangaJos().getX() << ", "
                    << allElem.get(i).getColtStangaJos().getY() << "), Latura = "
                    << allElem.get(i).getLatura() << "\n";
            }
            break;
        }
        case 6: { // New case for filtering squares in quadrant 1
            Repository<Patrat> filteredPatrate = patratService.filterByFirstQuadrant();
            std::cout << "Patratele care au coltul stanga jos în cadranul 1:\n";
            for (int i = 0; i < filteredPatrate.getSize(); ++i) {
                std::cout << "Patrat " << i + 1 << ": Colt Stanga Jos ("
                    << filteredPatrate.get(i).getColtStangaJos().getX() << ", "
                    << filteredPatrate.get(i).getColtStangaJos().getY() << "), Latura = "
                    << filteredPatrate.get(i).getLatura() << "\n";
            }
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Optiune invalida! Incearca din nou.\n";
        }
    }
}



#include <iostream>
#include "TriunghiService.h"

void UI::manageTriunghi() {
    int subChoice;
    TriunghiService triunghiService; // Ensure service is instantiated

    while (true) {
        std::cout << "\n--- Meniu Triunghi ---\n";
        std::cout << "1. Adauga Triunghi\n";
        std::cout << "2. Sterge Triunghi\n";
        std::cout << "3. Afiseaza Triunghiul cu cel mai mare perimetru\n";
        std::cout << "4. Afiseaza Secventa Maxima de Triunghiuri cu Perimetru Egal\n";
        std::cout << "5. Afiseaza Toate Triunghiurile\n";
        std::cout << "6. Afiseaza Triunghiurile din cadranul 1\n";
        std::cout << "0. Inapoi\n";
        std::cout << "Alege o optiune: ";
        std::cin >> subChoice;

        // Handle input failures
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (subChoice) {
        case 1: {
            int x1, y1, x2, y2, x3, y3;
            std::cout << "Introdu coordonatele primului punct (x1 y1): ";
            std::cin >> x1 >> y1;
            std::cout << "Introdu coordonatele celui de-al doilea punct (x2 y2): ";
            std::cin >> x2 >> y2;
            std::cout << "Introdu coordonatele celui de-al treilea punct (x3 y3): ";
            std::cin >> x3 >> y3;

            triunghiService.add(Punct<int>(x1, y1), Punct<int>(x2, y2), Punct<int>(x3, y3));
            std::cout << "Triunghi adaugat!\n";
            break;
        }
        case 2: {
            int x1, y1, x2, y2, x3, y3;
            std::cout << "Introdu coordonatele primului punct (x1 y1) ale triunghiului de sters: ";
            std::cin >> x1 >> y1;
            std::cout << "Introdu coordonatele celui de-al doilea punct (x2 y2): ";
            std::cin >> x2 >> y2;
            std::cout << "Introdu coordonatele celui de-al treilea punct (x3 y3): ";
            std::cin >> x3 >> y3;

            if (triunghiService.remove(Triunghi(Punct<int>(x1, y1), Punct<int>(x2, y2), Punct<int>(x3, y3)))) {
                std::cout << "Triunghi sters!\n";
            }
            else {
                std::cout << "Triunghiul nu a fost gasit!\n";
            }
            break;
        }
        case 3: {
            Triunghi maxTriunghi = triunghiService.getMaxElement();
            std::cout << "Triunghiul cu cel mai mare perimetru: Puncte("
                << maxTriunghi.getPunct1().getX() << ", " << maxTriunghi.getPunct1().getY() << "), ("
                << maxTriunghi.getPunct2().getX() << ", " << maxTriunghi.getPunct2().getY() << "), ("
                << maxTriunghi.getPunct3().getX() << ", " << maxTriunghi.getPunct3().getY() << ")\n";
            break;
        }
        case 4: {
            Repository<Triunghi> maxSequence = triunghiService.getMaxEqualSequence();
            std::cout << "Cea mai lunga secventa de triunghiuri cu perimetru egal:\n";
            for (int i = 0; i < maxSequence.getSize(); ++i) {
                std::cout << "Triunghi " << i + 1 << ": Puncte("
                    << maxSequence.get(i).getPunct1().getX() << ", " << maxSequence.get(i).getPunct1().getY() << "), ("
                    << maxSequence.get(i).getPunct2().getX() << ", " << maxSequence.get(i).getPunct2().getY() << "), ("
                    << maxSequence.get(i).getPunct3().getX() << ", " << maxSequence.get(i).getPunct3().getY() << ")\n";
            }
            break;
        }
        case 5: {
            Repository<Triunghi> allElem = triunghiService.getAll();
            std::cout << "Triunghiurile adaugate sunt:\n";
            for (int i = 0; i < allElem.getSize(); ++i) {
                std::cout << "Triunghi " << i + 1 << ": Puncte("
                    << allElem.get(i).getPunct1().getX() << ", " << allElem.get(i).getPunct1().getY() << "), ("
                    << allElem.get(i).getPunct2().getX() << ", " << allElem.get(i).getPunct2().getY() << "), ("
                    << allElem.get(i).getPunct3().getX() << ", " << allElem.get(i).getPunct3().getY() << ")\n";
            }
            break;
        }
        case 6: {
            Repository<Triunghi> filteredTriunghi = triunghiService.filterByFirstQuadrant();
            std::cout << "Triunghiurile care au toate punctele în cadranul 1:\n";
            for (int i = 0; i < filteredTriunghi.getSize(); ++i) {
                std::cout << "Triunghi " << i + 1 << ": Puncte("
                    << filteredTriunghi.get(i).getPunct1().getX() << ", " << filteredTriunghi.get(i).getPunct1().getY() << "), ("
                    << filteredTriunghi.get(i).getPunct2().getX() << ", " << filteredTriunghi.get(i).getPunct2().getY() << "), ("
                    << filteredTriunghi.get(i).getPunct3().getX() << ", " << filteredTriunghi.get(i).getPunct3().getY() << ")\n";
            }
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Optiune invalida! Incearca din nou.\n";
        }
    }
}




