#pragma once

#include "Punct.h"

class Cerc {
private:
    double raza;
    Punct<int> centru;

public:
    Cerc(double r = 0, Punct<int> c = Punct<int>(0, 0));
    ~Cerc();

    double getRaza() const;
    Punct<int> getCentru() const;

    void setRaza(double r);
    void setCentru(Punct<int> c);
};
