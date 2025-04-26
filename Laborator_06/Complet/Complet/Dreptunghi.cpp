#include "Dreptunghi.h"

// Constructor
Dreptunghi::Dreptunghi(Punct<int> colt, double latime, double inaltime)
    : coltStangaJos(colt), latime(latime), inaltime(inaltime) {
}

// Destructor
Dreptunghi::~Dreptunghi() {}

// Getter methods
Punct<int> Dreptunghi::getColtStangaJos() const {
    return coltStangaJos;
}

double Dreptunghi::getLatime() const {
    return latime;
}

double Dreptunghi::getInaltime() const {
    return inaltime;
}

// Setter methods
void Dreptunghi::setColtStangaJos(Punct<int> colt) {
    coltStangaJos = colt;
}

void Dreptunghi::setLatime(double latime) {
    this->latime = latime;
}

void Dreptunghi::setInaltime(double inaltime) {
    this->inaltime = inaltime;
}
