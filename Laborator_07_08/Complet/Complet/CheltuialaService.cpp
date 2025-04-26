#include "CheltuialaService.h"
#include <cstring>

CheltuialaService::CheltuialaService(Repository<Cheltuiala>& r) : repo(r) {}

void CheltuialaService::saveState() {
    undoStack.push_back(repo);  // salvează starea curentă
}

bool CheltuialaService::add(int zi, int suma, const char* tip) {
    saveState();
    Cheltuiala c(zi, suma, tip);
    return repo.add(c);
}

bool CheltuialaService::update(int index, int ziNoua, int sumaNoua, const char* tipNou) {
    if (index >= 0 && index < repo.getSize()) {
        saveState();
        Cheltuiala c(ziNoua, sumaNoua, tipNou);
        return repo.update(index, c);
    }
    return false;
}

bool CheltuialaService::removeByIndex(int index) {
    if (index >= 0 && index < repo.getSize()) {
        saveState();
        return repo.remove(index);
    }
    return false;
}

bool CheltuialaService::undo() {
    if (undoStack.empty()) {
        return false;
    }
    repo = undoStack.back();
    undoStack.pop_back();
    return true;
}

Cheltuiala CheltuialaService::get(int index) const {
    return repo.get(index);
}

int CheltuialaService::getSize() const {
    return repo.getSize();
}

Cheltuiala* CheltuialaService::getAll(int& size) const {
    return repo.getAll(size);
}

bool CheltuialaService::removeByDay(int zi) {
    bool ok = false;
    int size;
    Cheltuiala* all = repo.getAll(size);
    for (int i = size - 1; i >= 0; --i) {
        if (all[i].getZi() == zi) {
            saveState();
            repo.remove(i);
            ok = true;
        }
    }
    return ok;
}

bool CheltuialaService::removeByInterval(int ziStart, int ziEnd) {
    bool ok = false;
    int size;
    Cheltuiala* all = repo.getAll(size);
    for (int i = size - 1; i >= 0; --i) {
        int zi = all[i].getZi();
        if (zi >= ziStart && zi <= ziEnd) {
            saveState();
            repo.remove(i);
            ok = true;
        }
    }
    return ok;
}

bool CheltuialaService::removeByTip(const char* tip) {
    bool ok = false;
    int size;
    Cheltuiala* all = repo.getAll(size);
    for (int i = size - 1; i >= 0; --i) {
        if (strcmp(all[i].getTip(), tip) == 0) {
            saveState();
            repo.remove(i);
            ok = true;
        }
    }
    return ok;
}

Cheltuiala* CheltuialaService::getAllByTip(const char* tip, int& outSize) const {
    int size;
    Cheltuiala* all = repo.getAll(size);
    Cheltuiala* filtered = new Cheltuiala[size];
    outSize = 0;

    for (int i = 0; i < size; ++i) {
        if (strcmp(all[i].getTip(), tip) == 0)
            filtered[outSize++] = all[i];
    }
    return filtered;
}

Cheltuiala* CheltuialaService::getAllByTipAndSumCmp(const char* tip, int suma, char op, int& outSize) const {
    int size;
    Cheltuiala* all = repo.getAll(size);
    Cheltuiala* filtered = new Cheltuiala[size];
    outSize = 0;

    for (int i = 0; i < size; ++i) {
        bool matches = strcmp(all[i].getTip(), tip) == 0;
        if (!matches) continue;

        if ((op == '>' && all[i].getSuma() > suma) ||
            (op == '=' && all[i].getSuma() == suma) ||
            (op == '<' && all[i].getSuma() < suma)) {
            filtered[outSize++] = all[i];
        }
    }
    return filtered;
}

int CheltuialaService::sumaByTip(const char* tip) const {
    int size, total = 0;
    Cheltuiala* all = repo.getAll(size);

    for (int i = 0; i < size; ++i) {
        if (strcmp(all[i].getTip(), tip) == 0)
            total += all[i].getSuma();
    }
    return total;
}

int CheltuialaService::ziuaCuSumaMaxima() const {
    int size;
    Cheltuiala* all = repo.getAll(size);
    int totalPeZi[32] = { 0 };

    for (int i = 0; i < size; ++i) {
        totalPeZi[all[i].getZi()] += all[i].getSuma();
    }

    int maxZi = 1, maxSuma = totalPeZi[1];
    for (int zi = 2; zi <= 31; ++zi) {
        if (totalPeZi[zi] > maxSuma) {
            maxSuma = totalPeZi[zi];
            maxZi = zi;
        }
    }
    return maxZi;
}

Cheltuiala* CheltuialaService::sortByZiDesc(int& outSize) const {
    int size;
    Cheltuiala* all = repo.getAll(size);
    Cheltuiala* sorted = new Cheltuiala[size];
    for (int i = 0; i < size; ++i) sorted[i] = all[i];

    for (int i = 0; i < size - 1; ++i)
        for (int j = i + 1; j < size; ++j)
            if (sorted[i].getZi() < sorted[j].getZi())
                std::swap(sorted[i], sorted[j]);

    outSize = size;
    return sorted;
}

Cheltuiala* CheltuialaService::sortByTipAndSumAsc(const char* tip, int& outSize) const {
    int size;
    Cheltuiala* all = repo.getAll(size);
    Cheltuiala* filtered = new Cheltuiala[size];
    outSize = 0;

    for (int i = 0; i < size; ++i)
        if (strcmp(all[i].getTip(), tip) == 0)
            filtered[outSize++] = all[i];

    for (int i = 0; i < outSize - 1; ++i)
        for (int j = i + 1; j < outSize; ++j)
            if (filtered[i].getSuma() > filtered[j].getSuma())
                std::swap(filtered[i], filtered[j]);

    return filtered;
}

void CheltuialaService::filterByTip(const char* tip) {
    int size;
    Cheltuiala* all = repo.getAll(size);
    saveState();

    for (int i = size - 1; i >= 0; --i)
        if (strcmp(all[i].getTip(), tip) != 0)
            repo.remove(i);
}

void CheltuialaService::filterByTipAndSumCmp(const char* tip, int suma, char op) {
    int size;
    Cheltuiala* all = repo.getAll(size);
    saveState();

    for (int i = size - 1; i >= 0; --i) {
        if (strcmp(all[i].getTip(), tip) != 0) {
            repo.remove(i);
        }
        else {
            bool pastreaza = false;
            if (op == '<') pastreaza = all[i].getSuma() < suma;
            else if (op == '=') pastreaza = all[i].getSuma() == suma;
            else if (op == '>') pastreaza = all[i].getSuma() > suma;

            if (!pastreaza) repo.remove(i);
        }
    }
}
