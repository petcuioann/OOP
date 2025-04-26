#include "CheltuialaApartamentService.h"
#include <cstring>
#include <algorithm>

CheltuialaApartamentService::CheltuialaApartamentService(Repository<CheltuialaApartament>& r)
    : repo(r) {
}

void CheltuialaApartamentService::saveState() {
    undoStack.push_back(repo);
}

// ====================== CRUD ==========================

bool CheltuialaApartamentService::add(int apartament, int suma, const char* tip) {
    saveState();
    CheltuialaApartament c(apartament, suma, tip);
    return repo.add(c);
}

bool CheltuialaApartamentService::update(int apartament, const char* tip, int sumaNoua) {
    int size;
    CheltuialaApartament* all = repo.getAll(size);
    for (int i = 0; i < size; ++i) {
        if (all[i].getApartament() == apartament && strcmp(all[i].getTip(), tip) == 0) {
            saveState();
            CheltuialaApartament c(apartament, sumaNoua, tip);
            return repo.update(i, c);
        }
    }
    return false;
}

bool CheltuialaApartamentService::removeByIndex(int index) {
    if (index >= 0 && index < repo.getSize()) {
        saveState();
        return repo.remove(index);
    }
    return false;
}

bool CheltuialaApartamentService::removeByApartament(int ap) {
    int size;
    bool ok = false;
    CheltuialaApartament* all = repo.getAll(size);
    for (int i = size - 1; i >= 0; --i)
        if (all[i].getApartament() == ap) {
            saveState();
            repo.remove(i);
            ok = true;
        }
    return ok;
}

bool CheltuialaApartamentService::removeByInterval(int apStart, int apEnd) {
    int size;
    bool ok = false;
    CheltuialaApartament* all = repo.getAll(size);
    for (int i = size - 1; i >= 0; --i) {
        int ap = all[i].getApartament();
        if (ap >= apStart && ap <= apEnd) {
            saveState();
            repo.remove(i);
            ok = true;
        }
    }
    return ok;
}

bool CheltuialaApartamentService::removeByTip(const char* tip) {
    int size;
    bool ok = false;
    CheltuialaApartament* all = repo.getAll(size);
    for (int i = size - 1; i >= 0; --i)
        if (strcmp(all[i].getTip(), tip) == 0) {
            saveState();
            repo.remove(i);
            ok = true;
        }
    return ok;
}

// ====================== ACCES ==========================

CheltuialaApartament* CheltuialaApartamentService::getAll(int& size) const {
    return repo.getAll(size);
}

CheltuialaApartament* CheltuialaApartamentService::getByApartament(int ap, int& sizeOut) const {
    int size;
    CheltuialaApartament* all = repo.getAll(size);
    CheltuialaApartament* result = new CheltuialaApartament[size];
    sizeOut = 0;

    for (int i = 0; i < size; ++i)
        if (all[i].getApartament() == ap)
            result[sizeOut++] = all[i];

    return result;
}

CheltuialaApartament* CheltuialaApartamentService::getBySumaCmp(int suma, char op, int& sizeOut) const {
    int size;
    CheltuialaApartament* all = repo.getAll(size);
    CheltuialaApartament* result = new CheltuialaApartament[size];
    sizeOut = 0;

    for (int i = 0; i < size; ++i) {
        int s = all[i].getSuma();
        if ((op == '<' && s < suma) || (op == '=' && s == suma) || (op == '>' && s > suma))
            result[sizeOut++] = all[i];
    }

    return result;
}

// ====================== ANALIZE ==========================

int CheltuialaApartamentService::sumaByTip(const char* tip) const {
    int size, suma = 0;
    CheltuialaApartament* all = repo.getAll(size);
    for (int i = 0; i < size; ++i)
        if (strcmp(all[i].getTip(), tip) == 0)
            suma += all[i].getSuma();
    return suma;
}

CheltuialaApartament CheltuialaApartamentService::maxInApartament(int ap) const {
    int size;
    CheltuialaApartament* all = repo.getAll(size);
    CheltuialaApartament maxCheltuiala;
    int maxVal = -1;

    for (int i = 0; i < size; ++i) {
        if (all[i].getApartament() == ap && all[i].getSuma() > maxVal) {
            maxVal = all[i].getSuma();
            maxCheltuiala = all[i];
        }
    }
    return maxCheltuiala;
}

CheltuialaApartament* CheltuialaApartamentService::sortByTipDesc(const char* tip, int& sizeOut) const {
    int size;
    CheltuialaApartament* all = repo.getAll(size);
    CheltuialaApartament* result = new CheltuialaApartament[size];
    sizeOut = 0;

    for (int i = 0; i < size; ++i)
        if (strcmp(all[i].getTip(), tip) == 0)
            result[sizeOut++] = all[i];

    for (int i = 0; i < sizeOut - 1; ++i)
        for (int j = i + 1; j < sizeOut; ++j)
            if (result[i].getSuma() < result[j].getSuma())
                std::swap(result[i], result[j]);

    return result;
}

// ====================== FILTRARE ==========================

void CheltuialaApartamentService::filterByTip(const char* tip) {
    int size;
    CheltuialaApartament* all = repo.getAll(size);
    saveState();
    for (int i = size - 1; i >= 0; --i)
        if (strcmp(all[i].getTip(), tip) != 0)
            repo.remove(i);
}

void CheltuialaApartamentService::filterByValLess(int maxSuma) {
    int size;
    CheltuialaApartament* all = repo.getAll(size);
    saveState();
    for (int i = size - 1; i >= 0; --i)
        if (all[i].getSuma() >= maxSuma)
            repo.remove(i);
}

// ====================== UNDO ==========================

bool CheltuialaApartamentService::undo() {
    if (!undoStack.empty()) {
        repo = undoStack.back();
        undoStack.pop_back();
        return true;
    }
    return false;
}
