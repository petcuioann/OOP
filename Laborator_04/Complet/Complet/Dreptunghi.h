#ifndef DREPTUNGGHI_H
#define DREPTUNGGHI_H

class Dreptunghi {
private:
    double lungime;
    double latime;

public:
    // Constructor cu parametri
    Dreptunghi(double l = 0.0, double a = 0.0);

    // Setteri
    void setLungime(double l);
    void setLatime(double a);

    // Getteri
    double getLungime() const;
    double getLatime() const;

    // Destructor
    ~Dreptunghi();

    // Metoda pentru calculul ariei
    double aria() const;

    // Metoda pentru calculul perimetrului
    double perimetru() const;
};

#endif // DREPTUNGGHI_H
