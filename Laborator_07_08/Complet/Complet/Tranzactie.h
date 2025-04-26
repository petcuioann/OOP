#ifndef TRANZACTIE_H
#define TRANZACTIE_H

class Tranzactie {
private:
    int zi;
    int suma;
    char* tip;
    char* descriere;

public:
    Tranzactie();
    Tranzactie(int zi, int suma, const char* tip, const char* descriere);
    Tranzactie(const Tranzactie& other);
    Tranzactie& operator=(const Tranzactie& other);
    bool operator==(const Tranzactie& other) const;
    ~Tranzactie();

    int getZi() const;
    int getSuma() const;
    const char* getTip() const;
    const char* getDescriere() const;

    void setZi(int zi);
    void setSuma(int suma);
    void setTip(const char* tip);
    void setDescriere(const char* descriere);
};

#endif
