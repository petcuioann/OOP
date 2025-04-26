#define _CRT_SECURE_NO_WARNINGS
#include "Cheltuiala.h"
#include <cstring>

Cheltuiala::Cheltuiala() : zi(0), suma(0) {
    tip = new char[1];
    tip[0] = '\0';
}

Cheltuiala::Cheltuiala(int zi, int suma, const char* tip) : zi(zi), suma(suma) {
    this->tip = new char[strlen(tip) + 1];
    strcpy_s(this->tip, strlen(tip) + 1, tip);
}

Cheltuiala::Cheltuiala(const Cheltuiala& other) : zi(other.zi), suma(other.suma) {
    tip = new char[strlen(other.tip) + 1];
    strcpy_s(tip, strlen(other.tip) + 1, other.tip);
}

Cheltuiala& Cheltuiala::operator=(const Cheltuiala& other) {
    if (this != &other) {
        zi = other.zi;
        suma = other.suma;

        if (tip != nullptr)
            delete[] tip;

        tip = new char[strlen(other.tip) + 1];
        strcpy_s(tip, strlen(other.tip) + 1, other.tip);
    }
    return *this;
}

bool Cheltuiala::operator==(const Cheltuiala& other) const {
    return zi == other.zi && suma == other.suma && strcmp(tip, other.tip) == 0;
}

Cheltuiala::~Cheltuiala() {
    delete[] tip;
}

// Getteri
int Cheltuiala::getZi() const {
    return zi;
}

int Cheltuiala::getSuma() const {
    return suma;
}

const char* Cheltuiala::getTip() const {
    return tip;
}

// Setteri
void Cheltuiala::setZi(int zi) {
    this->zi = zi;
}

void Cheltuiala::setSuma(int suma) {
    this->suma = suma;
}

void Cheltuiala::setTip(const char* tip) {
    if (this->tip != nullptr)
        delete[] this->tip;

    this->tip = new char[strlen(tip) + 1];
    strcpy_s(this->tip, strlen(tip) + 1, tip);
}
