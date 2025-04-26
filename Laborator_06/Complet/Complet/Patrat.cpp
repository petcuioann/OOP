#include "Patrat.h"

// Constructor
Patrat::Patrat(Punct<int> colt, double l) : coltStangaJos(colt), latura(l) {}

// Destructor
Patrat::~Patrat() {}

// Getter methods
Punct<int> Patrat::getColtStangaJos() const {
    return coltStangaJos;
}

double Patrat::getLatura() const {
    return latura;
}

// Setter methods
void Patrat::setColtStangaJos(Punct<int> colt) {
    coltStangaJos = colt;
}

void Patrat::setLatura(double l) {
    latura = l;
}
