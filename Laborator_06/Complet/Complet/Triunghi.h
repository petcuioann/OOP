#pragma once

#include "Punct.h"

class Triunghi {
private:
    Punct<int> punct1, punct2, punct3; // Three vertices of the triangle

public:
    // Constructor
    Triunghi(Punct<int> p1 = Punct<int>(0, 0), Punct<int> p2 = Punct<int>(0, 0), Punct<int> p3 = Punct<int>(0, 0));

    // Destructor
    ~Triunghi();

    // Getter methods
    Punct<int> getPunct1() const;
    Punct<int> getPunct2() const;
    Punct<int> getPunct3() const;

    // Setter methods
    void setPunct1(Punct<int> p1);
    void setPunct2(Punct<int> p2);
    void setPunct3(Punct<int> p3);
};
