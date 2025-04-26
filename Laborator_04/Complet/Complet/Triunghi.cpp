#include "Triunghi.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor cu parametri
Triunghi::Triunghi(double b, double h) : baza(b), inaltime(h) {}

// Setteri
void Triunghi::setBaza(double b) {
    baza = b;
}

void Triunghi::setInaltime(double h) {
    inaltime = h;
}

// Getteri
double Triunghi::getBaza() const {
    return baza;
}

double Triunghi::getInaltime() const {
    return inaltime;
}

// Destructor
Triunghi::~Triunghi() {
    cout << "Destructorul a fost apelat pentru Triunghi cu baza: " << baza << " si inaltime: " << inaltime << endl;
}

// Metoda pentru calculul ariei
double Triunghi::aria() const {
    return 0.5 * baza * inaltime;
}

// Metoda pentru calculul perimetrului
double Triunghi::perimetru(double latura2, double latura3) const {
    // Presupunem un triunghi dreptunghic
    double ipotenusa = sqrt(latura2 * latura2 + latura3 * latura3);
    return latura2 + latura3 + ipotenusa;
}
