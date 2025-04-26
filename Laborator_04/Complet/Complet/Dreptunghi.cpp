#include "Dreptunghi.h"
#include <iostream>
using namespace std;

// Constructor cu parametri
Dreptunghi::Dreptunghi(double l, double a) : lungime(l), latime(a) {}

// Setteri
void Dreptunghi::setLungime(double l) {
    lungime = l;
}

void Dreptunghi::setLatime(double a) {
    latime = a;
}

// Getteri
double Dreptunghi::getLungime() const {
    return lungime;
}

double Dreptunghi::getLatime() const {
    return latime;
}

// Destructor
Dreptunghi::~Dreptunghi() {
    cout << "Destructorul a fost apelat pentru Dreptunghi cu lungime: " << lungime << " si latime: " << latime << endl;
}

// Metoda pentru calculul ariei
double Dreptunghi::aria() const {
    return lungime * latime;
}

// Metoda pentru calculul perimetrului
double Dreptunghi::perimetru() const {
    return 2 * (lungime + latime);
}
