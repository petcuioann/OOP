#include "CercService.h"
#include <iostream>

using namespace std;

Service::Service() {}

void Service::adaugaCerc(double raza) {
    Cerc c(raza);
    repo.adaugaCerc(c);
}

void Service::stergeCerc(int index) {
    repo.stergeCerc(index);
}

void Service::afisareCercuri() const {
    repo.afiseazaCercuri(); // Apelăm funcția din Repository
}

void Service::golesteRepository() {
    repo.golesteRepository();
}

Cerc Service::getCelMaiMareCerc() const {
    if (repo.getNrCercuri() == 0) {
        throw runtime_error("Nu exista cercuri.");
    }

    Cerc maxCerc = repo.getCerc(0);
    for (int i = 1; i < repo.getNrCercuri(); i++) {
        if (repo.getCerc(i).getRaza() > maxCerc.getRaza()) {
            maxCerc = repo.getCerc(i);
        }
    }

    return maxCerc;
}
