#ifndef CHELTUIALA_H
#define CHELTUIALA_H

class Cheltuiala {
private:
    int zi;
    int suma;
    char* tip;

public:
    Cheltuiala();  // constructor implicit
    Cheltuiala(int zi, int suma, const char* tip);  // constructor cu parametri
    Cheltuiala(const Cheltuiala& other);  // constructor de copiere
    Cheltuiala& operator=(const Cheltuiala& other);  // operator egal
    bool operator==(const Cheltuiala& other) const;  // comparare

    ~Cheltuiala();  // destructor

    // Getteri
    int getZi() const;
    int getSuma() const;
    const char* getTip() const;

    // Setteri
    void setZi(int zi);
    void setSuma(int suma);
    void setTip(const char* tip);
};

#endif
