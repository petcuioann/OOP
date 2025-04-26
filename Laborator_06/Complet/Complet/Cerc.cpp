#include "Cerc.h"

// Constructor
Cerc::Cerc(double r, Punct<int> c) : raza(r), centru(c) {}

// Destructor
Cerc::~Cerc() {}

// Getter methods
double Cerc::getRaza() const {
    return raza;
}

Punct<int> Cerc::getCentru() const {
    return centru;
}

// Setter methods
void Cerc::setRaza(double r) {
    raza = r;
}

void Cerc::setCentru(Punct<int> c) {
    centru = c;
}
