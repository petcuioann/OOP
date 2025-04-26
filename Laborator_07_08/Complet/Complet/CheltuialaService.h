#ifndef CHELTUIALASERVICE_H
#define CHELTUIALASERVICE_H

#include "Cheltuiala.h"
#include "Repository.h"
#include <vector>

class CheltuialaService {
private:
    Repository<Cheltuiala>& repo;
    std::vector<Repository<Cheltuiala>> undoStack;

    void saveState();

public:
    CheltuialaService(Repository<Cheltuiala>& r);

    bool add(int zi, int suma, const char* tip);
    bool update(int index, int ziNoua, int sumaNoua, const char* tipNou);
    bool removeByIndex(int index);
    bool undo();

    Cheltuiala get(int index) const;
    int getSize() const;
    Cheltuiala* getAll(int& size) const;

    bool removeByDay(int zi);
    bool removeByInterval(int ziStart, int ziEnd);
    bool removeByTip(const char* tip);

    // listări
    Cheltuiala* getAllByTip(const char* tip, int& outSize) const;
    Cheltuiala* getAllByTipAndSumCmp(const char* tip, int suma, char op, int& outSize) const;

    // agregări
    int sumaByTip(const char* tip) const;
    int ziuaCuSumaMaxima() const;

    // sortări
    Cheltuiala* sortByZiDesc(int& outSize) const;
    Cheltuiala* sortByTipAndSumAsc(const char* tip, int& outSize) const;

    // filtrări destructive
    void filterByTip(const char* tip);
    void filterByTipAndSumCmp(const char* tip, int suma, char op);


};

#endif // CHELTUIALASERVICE_H
