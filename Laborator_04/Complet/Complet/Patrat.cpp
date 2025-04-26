#include "Patrat.h"
#include <iostream>
using namespace std;

// Constructor cu parametru
Patrat::Patrat(double l) : latura(l) {}

// Setteri
void Patrat::setLatura(double l) {
    latura = l;
}

// Getteri
double Patrat::getLatura() const {
    return latura;
}

// Destructor
Patrat::~Patrat() {
    cout << "Destructorul a fost apelat pentru Patrat cu latura: " << latura << endl;
}

// Metoda pentru calculul ariei
double Patrat::aria() const {
    return latura * latura;
}

// Metoda pentru calculul perimetrului
double Patrat::perimetru() const {
    return 4 * latura;
}
