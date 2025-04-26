#include "NumarComplex.h"
#include <iostream>
using namespace std;

// Constructor cu parametri
NumarComplex::NumarComplex(double r, double i) : real(r), imaginar(i) {}

// Setteri
void NumarComplex::setReal(double r) {
    real = r;
}

void NumarComplex::setImaginar(double i) {
    imaginar = i;
}

// Getteri
double NumarComplex::getReal() const {
    return real;
}

double NumarComplex::getImaginar() const {
    return imaginar;
}

// Destructor
NumarComplex::~NumarComplex() {
    cout << "Destructorul a fost apelat pentru NumarComplex: "
        << real << " + " << imaginar << "i" << endl;
}

// Metoda pentru afisarea numarului complex
void NumarComplex::afiseaza() const {
    cout << real << " + " << imaginar << "i" << endl;
}

// Metoda pentru adunarea a doua numere complexe
NumarComplex NumarComplex::aduna(const NumarComplex& alt) const {
    return NumarComplex(real + alt.real, imaginar + alt.imaginar);
}
