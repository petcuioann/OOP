#define _CRT_SECURE_NO_WARNINGS
#include "CheltuialaApartament.h"
#include <cstring>

CheltuialaApartament::CheltuialaApartament() : apartament(0), suma(0), tip(nullptr) {
    tip = new char[1];
    tip[0] = '\0';
}

CheltuialaApartament::CheltuialaApartament(int apartament, int suma, const char* tip)
    : apartament(apartament), suma(suma) {
    this->tip = new char[strlen(tip) + 1];
    strcpy_s(this->tip, strlen(tip) + 1, tip);
}

CheltuialaApartament::CheltuialaApartament(const CheltuialaApartament& other)
    : apartament(other.apartament), suma(other.suma) {
    this->tip = new char[strlen(other.tip) + 1];
    strcpy_s(this->tip, strlen(other.tip) + 1, other.tip);
}

CheltuialaApartament::~CheltuialaApartament() {
    delete[] tip;
}

CheltuialaApartament& CheltuialaApartament::operator=(const CheltuialaApartament& other) {
    if (this != &other) {
        apartament = other.apartament;
        suma = other.suma;

        delete[] tip;
        tip = new char[strlen(other.tip) + 1];
        strcpy_s(tip, strlen(other.tip) + 1, other.tip);
    }
    return *this;
}

bool CheltuialaApartament::operator==(const CheltuialaApartament& other) const {
    return apartament == other.apartament &&
        suma == other.suma &&
        strcmp(tip, other.tip) == 0;
}

int CheltuialaApartament::getApartament() const {
    return apartament;
}

int CheltuialaApartament::getSuma() const {
    return suma;
}

const char* CheltuialaApartament::getTip() const {
    return tip;
}

void CheltuialaApartament::setApartament(int apartament) {
    this->apartament = apartament;
}

void CheltuialaApartament::setSuma(int suma) {
    this->suma = suma;
}

void CheltuialaApartament::setTip(const char* tipNou) {
    delete[] tip;
    tip = new char[strlen(tipNou) + 1];
    strcpy_s(tip, strlen(tipNou) + 1, tipNou);
}
