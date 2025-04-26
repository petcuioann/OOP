#define _CRT_SECURE_NO_WARNINGS
#include "Tranzactie.h"
#include <cstring>

Tranzactie::Tranzactie() : zi(0), suma(0), tip(nullptr), descriere(nullptr) {
    tip = new char[1]; tip[0] = '\0';
    descriere = new char[1]; descriere[0] = '\0';
}

Tranzactie::Tranzactie(int zi, int suma, const char* tip, const char* descriere)
    : zi(zi), suma(suma) {
    this->tip = new char[strlen(tip) + 1];
    strcpy_s(this->tip, strlen(tip) + 1, tip);

    this->descriere = new char[strlen(descriere) + 1];
    strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
}

Tranzactie::Tranzactie(const Tranzactie& other)
    : zi(other.zi), suma(other.suma) {
    this->tip = new char[strlen(other.tip) + 1];
    strcpy_s(this->tip, strlen(other.tip) + 1, other.tip);

    this->descriere = new char[strlen(other.descriere) + 1];
    strcpy_s(this->descriere, strlen(other.descriere) + 1, other.descriere);
}

Tranzactie& Tranzactie::operator=(const Tranzactie& other) {
    if (this != &other) {
        zi = other.zi;
        suma = other.suma;

        delete[] tip;
        tip = new char[strlen(other.tip) + 1];
        strcpy_s(tip, strlen(other.tip) + 1, other.tip);

        delete[] descriere;
        descriere = new char[strlen(other.descriere) + 1];
        strcpy_s(descriere, strlen(other.descriere) + 1, other.descriere);
    }
    return *this;
}

bool Tranzactie::operator==(const Tranzactie& other) const {
    return zi == other.zi && suma == other.suma &&
        strcmp(tip, other.tip) == 0 &&
        strcmp(descriere, other.descriere) == 0;
}

Tranzactie::~Tranzactie() {
    delete[] tip;
    delete[] descriere;
}

int Tranzactie::getZi() const {
    return zi;
}

int Tranzactie::getSuma() const {
    return suma;
}

const char* Tranzactie::getTip() const {
    return tip;
}

const char* Tranzactie::getDescriere() const {
    return descriere;
}

void Tranzactie::setZi(int zi) {
    this->zi = zi;
}

void Tranzactie::setSuma(int suma) {
    this->suma = suma;
}

void Tranzactie::setTip(const char* tipNou) {
    delete[] tip;
    tip = new char[strlen(tipNou) + 1];
    strcpy_s(tip, strlen(tipNou) + 1, tipNou);
}

void Tranzactie::setDescriere(const char* descriereNoua) {
    delete[] descriere;
    descriere = new char[strlen(descriereNoua) + 1];
    strcpy_s(descriere, strlen(descriereNoua) + 1, descriereNoua);
}
