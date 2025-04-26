#ifndef TRIUNGHI_H
#define TRIUNGHI_H

class Triunghi {
private:
    double baza;
    double inaltime;

public:
    // Constructor cu parametri
    Triunghi(double b = 0.0, double h = 0.0);

    // Setteri
    void setBaza(double b);
    void setInaltime(double h);

    // Getteri
    double getBaza() const;
    double getInaltime() const;

    // Destructor
    ~Triunghi();

    // Metoda pentru calculul ariei
    double aria() const;

    // Metoda pentru calculul perimetrului (presupunem un triunghi dreptunghic)
    double perimetru(double latura2, double latura3) const;
};

#endif // TRIUNGHI_H
