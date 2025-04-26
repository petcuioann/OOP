#ifndef CHELTUIALA_APARTAMENT_SERVICE_H
#define CHELTUIALA_APARTAMENT_SERVICE_H

#include "CheltuialaApartament.h"
#include "Repository.h"
#include <vector>

class CheltuialaApartamentService {
private:
    Repository<CheltuialaApartament>& repo;
    std::vector<Repository<CheltuialaApartament>> undoStack;

    void saveState();

public:
    CheltuialaApartamentService(Repository<CheltuialaApartament>& r);

    // CRUD
    bool add(int apartament, int suma, const char* tip);
    bool update(int apartament, const char* tip, int sumaNoua);
    bool removeByIndex(int index);
    bool removeByApartament(int ap);
    bool removeByInterval(int apStart, int apEnd);
    bool removeByTip(const char* tip);

    // Acces
    CheltuialaApartament* getAll(int& size) const;
    CheltuialaApartament* getByApartament(int apartament, int& sizeOut) const;
    CheltuialaApartament* getBySumaCmp(int suma, char op, int& sizeOut) const;

    // Analize
    int sumaByTip(const char* tip) const;
    CheltuialaApartament maxInApartament(int ap) const;
    CheltuialaApartament* sortByTipDesc(const char* tip, int& sizeOut) const;

    // Filtrări
    void filterByTip(const char* tip);
    void filterByValLess(int maxSuma);

    // Undo
    bool undo();
};

#endif
