#include "Triunghi.h"

// Constructor
Triunghi::Triunghi(Punct<int> p1, Punct<int> p2, Punct<int> p3)
    : punct1(p1), punct2(p2), punct3(p3) {
}

// Destructor
Triunghi::~Triunghi() {}

// Getter methods
Punct<int> Triunghi::getPunct1() const {
    return punct1;
}

Punct<int> Triunghi::getPunct2() const {
    return punct2;
}

Punct<int> Triunghi::getPunct3() const {
    return punct3;
}

// Setter methods
void Triunghi::setPunct1(Punct<int> p1) {
    punct1 = p1;
}

void Triunghi::setPunct2(Punct<int> p2) {
    punct2 = p2;
}

void Triunghi::setPunct3(Punct<int> p3) {
    punct3 = p3;
}
