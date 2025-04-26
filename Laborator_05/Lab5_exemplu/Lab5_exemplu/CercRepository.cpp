#include "CercRepository.h"
#include <iostream>

using namespace std;

Repository::Repository() : nrCercuri(0) {}

void Repository::adaugaCerc(const Cerc& c) {
    if (nrCercuri < MAX_CERCURI) {
        cercuri[nrCercuri] = c;
        nrCercuri++;
    }
    else {
        cout << "Repository plin! Nu se mai pot adauga cercuri.\n";
    }
}

void Repository::stergeCerc(int index) {
    if (index >= 0 && index < nrCercuri) {
        for (int i = index; i < nrCercuri - 1; i++) {
            cercuri[i] = cercuri[i + 1];
        }
        nrCercuri--;
    }
    else {
        cout << "Index invalid! Nu s-a sters niciun cerc.\n";
    }
}

const Cerc& Repository::getCerc(int index) const {
    if (index >= 0 && index < nrCercuri) {
        return cercuri[index];
    }
    else {
        throw std::out_of_range("Index invalid!");
    }
}



int Repository::getNrCercuri() const {
    return nrCercuri;
}

void Repository::afiseazaCercuri() const {
    cout << "Lista de cercuri:\n";
    for (int i = 0; i < nrCercuri; i++) {
        cout << "Cerc " << i + 1 << ": Raza = " << cercuri[i].getRaza()
            << ", Aria = " << cercuri[i].aria()
            << ", Circumferinta = " << cercuri[i].circumferinta() << endl;
    }
}

void Repository::golesteRepository() {
    nrCercuri = 0;
    cout << "Toate cercurile au fost sterse.\n";
}
