#ifndef PRODUS_H
#define PRODUS_H

#include <string>

class Produs {
private:
    std::string cod;
    std::string nume;
    double pret;

public:
    // Constructori
    Produs();
    Produs(const std::string& cod, const std::string& nume, double pret);
    Produs(const Produs& other);

    // Destructor
    ~Produs() = default;

    // Operator=
    Produs& operator=(const Produs& other);

    // Operator==
    bool operator==(const Produs& other) const;

    // Getteri
    std::string getCod() const;
    std::string getNume() const;
    double getPret() const;

    // Setteri
    void setCod(const std::string& cod);
    void setNume(const std::string& nume);
    void setPret(double pret);
};

#endif // PRODUS_H
