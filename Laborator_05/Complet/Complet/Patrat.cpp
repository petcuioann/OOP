#include "Patrat.h"

Patrat::Patrat(double l) {
    latura = l;
}

Patrat::~Patrat() {}

double Patrat::getLatura() const {
    return latura;
}

void Patrat::setLatura(double l) {
    latura = l;
}