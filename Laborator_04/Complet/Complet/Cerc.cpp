#include "Cerc.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor cu parametru
Cerc::Cerc(double r) : raza(r) {}

// Setteri
void Cerc::setRaza(double r) {
    raza = r;
}

// Getteri
double Cerc::getRaza() const {
    return raza;
}

// Destructor
Cerc::~Cerc() {
    cout << "Destructorul a fost apelat pentru Cerc cu raza: " << raza << endl;
}

// Metoda pentru calculul ariei
double Cerc::aria() const {
    return std::atan(1) * 4 * raza * raza; // 𝜋 * r^2
}

// Metoda pentru calculul circumferinței
double Cerc::circumferinta() const {
    return 2 * std::atan(1) * 4 * raza; // 2 * 𝜋 * r
}
