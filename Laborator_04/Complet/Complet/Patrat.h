#ifndef PATRAT_H
#define PATRAT_H

class Patrat {
private:
    double latura;

public:
    // Constructor cu parametru
    Patrat(double l = 0.0);

    // Setteri
    void setLatura(double l);

    // Getteri
    double getLatura() const;

    // Destructor
    ~Patrat();

    // Metoda pentru calculul ariei
    double aria() const;

    // Metoda pentru calculul perimetrului
    double perimetru() const;
};

#endif // PATRAT_H
