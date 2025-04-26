#include "Service.h"
#include <stdexcept>
#include <vector>
#include <cmath>  // pentru round()

Service::Service(Repo& r) : repo(r) {}

// CRUD
void Service::addProdus(const std::string& cod, const std::string& nume, double pret) {
    if (!repo.exists(cod)) {
        Produs p(cod, nume, pret);
        repo.addItem(p);
    }
    else {
        throw std::runtime_error("Produsul exista deja!");
    }
}

bool Service::updateProdus(const std::string& cod, const std::string& numeNou, double pretNou) {
    Produs pNou(cod, numeNou, pretNou);
    return repo.update(cod, pNou);
}

bool Service::removeProdus(const std::string& cod) {
    return repo.remove(cod);
}

std::vector<Produs> Service::getAllProduse() const {
    return repo.getAll();
}

Produs Service::getProdus(const std::string& cod) const {
    return repo.getByCod(cod);
}

bool Service::existsProdus(const std::string& cod) const {
    return repo.exists(cod);
}

int Service::count() const {
    return repo.size();
}

// Setări monede disponibile
void Service::setMonedeDisponibile(const std::map<int, int>& monede) {
    monedeDisponibile = monede;
}

std::map<int, int> Service::getMonedeDisponibile() const {
    return monedeDisponibile;
}

// Cumpărare produs
std::map<int, int> Service::cumparaProdus(const std::string& cod, double sumaClientului) {
    if (!repo.exists(cod))
        throw std::runtime_error("Produsul nu exista!");

    Produs produs = repo.getByCod(cod);
    double pretProdus = produs.getPret();

    if (sumaClientului < pretProdus)
        throw std::runtime_error("Fonduri insuficiente pentru achizitie!");

    int restBani = static_cast<int>(round((sumaClientului - pretProdus) * 100));

    std::map<int, int> restReturnat;
    std::map<int, int> copieMonede = monedeDisponibile; // Copie ca să nu stricăm originalul până suntem siguri

    std::vector<int> valoriDisponibile = { 10000, 5000, 1000, 500, 100, 50, 10, 1 }; // bani

    for (int val : valoriDisponibile) {
        while (restBani >= val && copieMonede[val] > 0) {
            restBani -= val;
            copieMonede[val]--;
            restReturnat[val]++;
        }
    }

    if (restBani > 0)
        throw std::runtime_error("Nu se poate oferi restul in monedele disponibile.");

    monedeDisponibile = copieMonede;  // Confirmăm modificarea stocului
    return restReturnat;
}

