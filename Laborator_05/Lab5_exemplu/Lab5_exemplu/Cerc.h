#ifndef CERC_H
#define CERC_H

class Cerc {
private:
    double raza;

public:
    // Constructor cu parametru
    Cerc(double r = 0.0);

    // Setteri
    void setRaza(double r);

    // Getteri
    double getRaza() const;

    // Destructor
    ~Cerc();

    // Metoda pentru calculul ariei
    double aria() const;

    // Metoda pentru calculul circumferinței
    double circumferinta() const;
};

#endif // CERC_H
