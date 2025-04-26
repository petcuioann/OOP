#include "Dreptunghi.h"

Dreptunghi::Dreptunghi(double l, double L) {
    lungime = l;
    latime = L;
}

Dreptunghi::~Dreptunghi() {}

double Dreptunghi::getLungime() const {
    return lungime;
}

double Dreptunghi::getLatime() const {
    return latime;
}

void Dreptunghi::setLungime(double l) {
    lungime = l;
}

void Dreptunghi::setLatime(double L) {
    latime = L;
}