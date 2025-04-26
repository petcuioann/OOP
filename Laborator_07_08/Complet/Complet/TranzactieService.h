#ifndef TRANZACTIESERVICE_H
#define TRANZACTIESERVICE_H

#include "Tranzactie.h"
#include "Repository.h"
#include <vector>

class TranzactieService {
private:
    Repository<Tranzactie>& repo;
    std::vector<Repository<Tranzactie>> undoStack;

    void saveState();

public:
    TranzactieService(Repository<Tranzactie>& r);

    // CRUD
    bool add(int zi, int suma, const char* tip, const char* descriere);
    bool update(int zi, const char* tip, const char* descriere, int sumaNoua);
    bool removeByIndex(int index);
    bool removeByZi(int zi);
    bool removeByInterval(int ziStart, int ziEnd);
    bool removeByTip(const char* tip);

    // Listare
    Tranzactie* getAll(int& size) const;
    Tranzactie* getAllByTip(const char* tip, int& size) const;
    Tranzactie* getAllBySumCmp(int suma, char op, int& size) const;

    // Sold
    int soldZi(int zi) const;

    // Agregare
    int sumaByTip(const char* tip) const;
    Tranzactie maxOutInZi(int zi) const;

    // Filtrare
    void filterByTip(const char* tip);
    void filterByTipAndValLess(const char* tip, int sumaMaxima);

    // Undo
    bool undo();
};

#endif
