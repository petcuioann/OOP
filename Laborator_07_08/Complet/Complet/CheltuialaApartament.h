#ifndef CHELTUIALA_APARTAMENT_H
#define CHELTUIALA_APARTAMENT_H

class CheltuialaApartament {
private:
    int apartament;
    int suma;
    char* tip;

public:
    // Constructori
    CheltuialaApartament();
    CheltuialaApartament(int apartament, int suma, const char* tip);
    CheltuialaApartament(const CheltuialaApartament& other);

    // Destructor
    ~CheltuialaApartament();

    // Operator=
    CheltuialaApartament& operator=(const CheltuialaApartament& other);

    // Operator==
    bool operator==(const CheltuialaApartament& other) const;

    // Getteri
    int getApartament() const;
    int getSuma() const;
    const char* getTip() const;

    // Setteri
    void setApartament(int apartament);
    void setSuma(int suma);
    void setTip(const char* tip);
};

#endif
