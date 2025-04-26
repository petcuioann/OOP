#include "NumarComplex.h"

NumarComplex::NumarComplex(double r, double i) {
    re = r;
    im = i;
}

NumarComplex::~NumarComplex() {}

double NumarComplex::getRe() const {
    return re;
}

double NumarComplex::getIm() const {
    return im;
}

void NumarComplex::setRe(double r) {
    re = r;
}

void NumarComplex::setIm(double i) {
    im = i;
}