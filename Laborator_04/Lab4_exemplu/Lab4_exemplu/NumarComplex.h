#ifndef NUMARCOMPLEX_H
#define NUMARCOMPLEX_H

class NumarComplex {
private:
    double real;
    double imaginar;

public:
    // Constructor cu parametri
    NumarComplex(double r = 0.0, double i = 0.0);

    // Setteri
    void setReal(double r);
    void setImaginar(double i);

    // Getteri
    double getReal() const;
    double getImaginar() const;

    // Destructor
    ~NumarComplex();

    // Metoda pentru afisarea numarului complex
    void afiseaza() const;

    // Metoda pentru adunarea a doua numere complexe
    NumarComplex aduna(const NumarComplex& alt) const;
};

#endif // NUMARCOMPLEX_H
