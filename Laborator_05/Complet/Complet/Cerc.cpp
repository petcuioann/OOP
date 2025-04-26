#include "Cerc.h"

Cerc::Cerc(double r) {
    raza = r;
}

Cerc::~Cerc() {
    // destructor simbolic
}

double Cerc::getRaza() const {
    return raza;
}

void Cerc::setRaza(double r) {
    raza = r;
}
