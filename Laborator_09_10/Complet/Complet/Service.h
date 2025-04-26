#ifndef SERVICE_H
#define SERVICE_H

#include "Repo.h"
#include "Produs.h"
#include <vector>
#include <string>
#include <map>

class Service {
private:
    Repo& repo;
    std::map<int, int> monedeDisponibile; // cheie: valoare moneda in bani, valoare: numar bucati

public:
    // Constructor
    Service(Repo& r);

    // CRUD
    void addProdus(const std::string& cod, const std::string& nume, double pret);
    bool updateProdus(const std::string& cod, const std::string& numeNou, double pretNou);
    bool removeProdus(const std::string& cod);
    std::vector<Produs> getAllProduse() const;
    Produs getProdus(const std::string& cod) const;
    bool existsProdus(const std::string& cod) const;
    int count() const;

    // Setări monede disponibile
    void setMonedeDisponibile(const std::map<int, int>& monede);
    std::map<int, int> getMonedeDisponibile() const;

    // Cumpără un produs și returnează restul în bancnote și monede
    std::map<int, int> cumparaProdus(const std::string& cod, double sumaClientului);
};

#endif // SERVICE_H
