#include "Produs.h"

// Constructori
Produs::Produs() : cod(""), nume(""), pret(0.0) {}

Produs::Produs(const std::string& cod, const std::string& nume, double pret)
    : cod(cod), nume(nume), pret(pret) {
}

Produs::Produs(const Produs& other)
    : cod(other.cod), nume(other.nume), pret(other.pret) {
}

// Operator=
Produs& Produs::operator=(const Produs& other) {
    if (this != &other) {
        cod = other.cod;
        nume = other.nume;
        pret = other.pret;
    }
    return *this;
}

// Operator==
bool Produs::operator==(const Produs& other) const {
    return cod == other.cod && nume == other.nume && pret == other.pret;
}

// Getteri
std::string Produs::getCod() const {
    return cod;
}

std::string Produs::getNume() const {
    return nume;
}

double Produs::getPret() const {
    return pret;
}

// Setteri
void Produs::setCod(const std::string& cod) {
    this->cod = cod;
}

void Produs::setNume(const std::string& nume) {
    this->nume = nume;
}

void Produs::setPret(double pret) {
    this->pret = pret;
}
