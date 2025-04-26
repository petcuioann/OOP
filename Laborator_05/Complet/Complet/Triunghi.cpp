#include "Triunghi.h"

Triunghi::Triunghi(double x, double y, double z) {
    a = x; b = y; c = z;
}

Triunghi::~Triunghi() {}

double Triunghi::getLatura1() const {
    return a;
}

double Triunghi::getLatura2() const {
    return b;
}

double Triunghi::getLatura3() const {
    return c;
}

void Triunghi::setLatura1(double x) {
    a = x;
}

void Triunghi::setLatura2(double y) {
    b = y;
}

void Triunghi::setLatura3(double z) {
    c = z;
}
