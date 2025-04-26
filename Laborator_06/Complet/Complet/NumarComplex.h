#pragma once

class NumarComplex {
private:
    double re, im;

public:
    NumarComplex(double r = 0, double i = 0);
    ~NumarComplex();

    double getRe() const;
    double getIm() const;
    void setRe(double r);
    void setIm(double i);
};
