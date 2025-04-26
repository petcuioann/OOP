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
        std::cout << "0. Inapoi\n";
        std::cout << "Alege o optiune: ";
        std::cin >> subChoice;

        switch (subChoice) {
        case 1: {
            double raza;
            std::cout << "Introdu raza cercului: ";
            std::cin >> raza;
            cercService.add(Cerc(raza));
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
            std::cout << "Cercul cu raza maxima: " << maxCerc.getRaza() << "\n";
            break;
        }
        case 4: {
            Repository<Cerc> maxSequence = cercService.getMaxEqualSequence();
            std::cout << "Cea mai lunga secventa de cercuri cu raza egala:\n";
            int size = maxSequence.getSize();
            for (int i = 0; i < size; ++i) {
                std::cout << "Cerc cu raza " << maxSequence.get(i).getRaza() << "\n";
            }
            break;
        }
        case 5: {
            Repository<Cerc> allElem = cercService.getAll();
            std::cout << "Cercurile adaugate sunt:\n";
            for (int i = 0; i < allElem.getSize(); ++i) {
                std::cout << "Cerc cu raza " << allElem.get(i).getRaza() << "\n";
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
		std::cout << "0. Inapoi\n";
		std::cout << "Alege o optiune: ";
		std::cin >> subChoice;
		switch (subChoice) {
		case 1: {
			double lungime, latime;
			std::cout << "Introdu lungimea: ";
			std::cin >> lungime;
			std::cout << "Introdu latimea: ";
			std::cin >> latime;
			dreptunghiService.add(lungime, latime);
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
			std::cout << "Dreptunghiul cu aria maxima: Lungime = " << maxDreptunghi.getLungime()
				<< ", Latime = " << maxDreptunghi.getLatime() << "\n";
			break;
		}
		case 4: {
			int length;
			Dreptunghi* maxSequence = dreptunghiService.getMaxEqualSequence(length);
			if (length > 0) {
				std::cout << "Cea mai lunga secventa de dreptunghiuri cu aria egala:\n";
				for (int i = 0; i < length; ++i) {
					std::cout << "Dreptunghi " << i + 1 << ": Lungime = " << maxSequence[i].getLungime()
						<< ", Latime = " << maxSequence[i].getLatime() << "\n";
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
				std::cout << "Dreptunghi " << i + 1 << ": Lungime = " << allElem[i].getLungime()
					<< ", Latime = " << allElem[i].getLatime() << "\n";
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
            std::cout << "Numarul cu modul maxim: " << maxElement.getRe() << " + " << maxElement.getIm() << "i\n";
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
        std::cout << "0. Inapoi\n";
        std::cout << "Alege o optiune: ";
        std::cin >> subChoice;

        switch (subChoice) {
        case 1: {
            double latura;
            std::cout << "Introdu latura patratului: ";
            std::cin >> latura;
            patratService.add(latura);
            std::cout << "Patrat adaugat!\n";
            break;
        }
        case 2: {
            int index;
            std::cout << "Introdu indexul patratului de sters: ";
            std::cin >> index;
            if (patratService.remove(index)) {
                std::cout << "Patrat sters!\n";
            }
            else {
                std::cout << "Patratul nu a fost gasit!\n";
            }
            break;
        }
        case 3: {
            Patrat maxPatrat = patratService.getMaxElement();
            std::cout << "Patratul cu latura maxima: " << maxPatrat.getLatura() << "\n";
            break;
        }
        case 4: {
            Repository<Patrat> maxSequence = patratService.getMaxEqualSequence();
            std::cout << "Cea mai lunga secventa de patrate cu latura egala:\n";
            int size = maxSequence.getSize();
            for (int i = 0; i < size; ++i) {
                std::cout << "Patrat cu latura " << maxSequence.get(i).getLatura() << "\n";
            }
            break;
        }
        case 5: {
            Repository<Patrat> allElem = patratService.getAll();
            std::cout << "Patratele adaugate sunt:\n";
            for (int i = 0; i < allElem.getSize(); ++i) {
                std::cout << "Patrat cu latura " << allElem.get(i).getLatura() << "\n";
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


void UI::manageTriunghi() {
    int subChoice;
    while (true) {
        std::cout << "\n--- Meniu Triunghi ---\n";
        std::cout << "1. Adauga Triunghi\n";
        std::cout << "2. Sterge Triunghi\n";
        std::cout << "3. Afiseaza Triunghiul cu cel mai mare perimetru\n";
        std::cout << "4. Afiseaza Secventa Maxima de Triunghiuri cu Perimetru Egal\n";
        std::cout << "5. Afiseaza Toate Triunghiurile\n";
        std::cout << "0. Inapoi\n";
        std::cout << "Alege o optiune: ";
        std::cin >> subChoice;

        switch (subChoice) {
        case 1: {
            double a, b, c;
            std::cout << "Introdu latura 1: ";
            std::cin >> a;
            std::cout << "Introdu latura 2: ";
            std::cin >> b;
            std::cout << "Introdu latura 3: ";
            std::cin >> c;
            triunghiService.add(a, b, c);
            std::cout << "Triunghi adaugat!\n";
            break;
        }
        case 2: {
            double a, b, c;
            std::cout << "Introdu latura 1: ";
            std::cin >> a;
            std::cout << "Introdu latura 2: ";
            std::cin >> b;
            std::cout << "Introdu latura 3: ";
            std::cin >> c;
            if (triunghiService.remove(Triunghi(a, b, c))) {
                std::cout << "Triunghi sters!\n";
            }
            else {
                std::cout << "Triunghiul nu a fost gasit!\n";
            }
            break;
        }
        case 3: {
            Triunghi maxTriunghi = triunghiService.getMaxElement();
            std::cout << "Triunghiul cu cel mai mare perimetru: "
                << maxTriunghi.getLatura1() << ", "
                << maxTriunghi.getLatura2() << ", "
                << maxTriunghi.getLatura3()
                << " (Perimetru: "
                << maxTriunghi.getLatura1() + maxTriunghi.getLatura2() + maxTriunghi.getLatura3() << ")\n";
            break;
        }
        case 4: {
            Repository<Triunghi> maxSequence = triunghiService.getMaxEqualSequence();
            std::cout << "Cea mai lunga secventa de triunghiuri cu perimetru egal:\n";
            int size = maxSequence.getSize();
            for (int i = 0; i < size; ++i) {
                std::cout << maxSequence.get(i).getLatura1() << ", "
                    << maxSequence.get(i).getLatura2() << ", "
                    << maxSequence.get(i).getLatura3()
                    << " (Perimetru: "
                    << maxSequence.get(i).getLatura1() + maxSequence.get(i).getLatura2() + maxSequence.get(i).getLatura3() << ")\n";
            }
            break;
        }
        case 5: {
            Repository<Triunghi> allElem = triunghiService.getAll();
            std::cout << "Triunghiurile adaugate sunt:\n";
            for (int i = 0; i < allElem.getSize(); ++i) {
                std::cout << allElem.get(i).getLatura1() << ", "
                    << allElem.get(i).getLatura2() << ", "
                    << allElem.get(i).getLatura3()
                    << " (Perimetru: "
                    << allElem.get(i).getLatura1() + allElem.get(i).getLatura2() + allElem.get(i).getLatura3() << ")\n";
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
