#include "TranzactieService.h"
#include <cstring>

TranzactieService::TranzactieService(Repository<Tranzactie>& r) : repo(r) {}


void TranzactieService::saveState() {
    undoStack.push_back(repo);
}

// CRUD
bool TranzactieService::add(int zi, int suma, const char* tip, const char* descriere) {
    saveState();
    Tranzactie t(zi, suma, tip, descriere);
    return repo.add(t);
}

bool TranzactieService::update(int zi, const char* tip, const char* descriere, int sumaNoua) {
    int size;
    Tranzactie* all = repo.getAll(size);
    for (int i = 0; i < size; ++i) {
        if (all[i].getZi() == zi &&
            strcmp(all[i].getTip(), tip) == 0 &&
            strcmp(all[i].getDescriere(), descriere) == 0) {
            saveState();
            Tranzactie t(zi, sumaNoua, tip, descriere);
            return repo.update(i, t);
        }
    }
    return false;
}

bool TranzactieService::removeByIndex(int index) {
    if (index >= 0 && index < repo.getSize()) {
        saveState();
        return repo.remove(index);
    }
    return false;
}

bool TranzactieService::removeByZi(int zi) {
    bool ok = false;
    int size;
    Tranzactie* all = repo.getAll(size);
    for (int i = size - 1; i >= 0; --i) {
        if (all[i].getZi() == zi) {
            saveState();
            repo.remove(i);
            ok = true;
        }
    }
    return ok;
}

bool TranzactieService::removeByInterval(int ziStart, int ziEnd) {
    bool ok = false;
    int size;
    Tranzactie* all = repo.getAll(size);
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

bool TranzactieService::removeByTip(const char* tip) {
    bool ok = false;
    int size;
    Tranzactie* all = repo.getAll(size);
    for (int i = size - 1; i >= 0; --i) {
        if (strcmp(all[i].getTip(), tip) == 0) {
            saveState();
            repo.remove(i);
            ok = true;
        }
    }
    return ok;
}

// LISTARE
Tranzactie* TranzactieService::getAll(int& size) const {
    return repo.getAll(size);
}

Tranzactie* TranzactieService::getAllByTip(const char* tip, int& sizeOut) const {
    int size;
    Tranzactie* all = repo.getAll(size);
    Tranzactie* filtered = new Tranzactie[size];
    sizeOut = 0;

    for (int i = 0; i < size; ++i) {
        if (strcmp(all[i].getTip(), tip) == 0)
            filtered[sizeOut++] = all[i];
    }
    return filtered;
}

Tranzactie* TranzactieService::getAllBySumCmp(int suma, char op, int& sizeOut) const {
    int size;
    Tranzactie* all = repo.getAll(size);
    Tranzactie* filtered = new Tranzactie[size];
    sizeOut = 0;

    for (int i = 0; i < size; ++i) {
        if ((op == '<' && all[i].getSuma() < suma) ||
            (op == '=' && all[i].getSuma() == suma) ||
            (op == '>' && all[i].getSuma() > suma)) {
            filtered[sizeOut++] = all[i];
        }
    }
    return filtered;
}

// SOLD
int TranzactieService::soldZi(int zi) const {
    int size;
    Tranzactie* all = repo.getAll(size);
    int totalIn = 0, totalOut = 0;

    for (int i = 0; i < size; ++i) {
        if (all[i].getZi() == zi) {
            if (strcmp(all[i].getTip(), "in") == 0)
                totalIn += all[i].getSuma();
            else if (strcmp(all[i].getTip(), "out") == 0)
                totalOut += all[i].getSuma();
        }
    }
    return totalIn - totalOut;
}

// AGREGARE
int TranzactieService::sumaByTip(const char* tip) const {
    int size, suma = 0;
    Tranzactie* all = repo.getAll(size);
    for (int i = 0; i < size; ++i)
        if (strcmp(all[i].getTip(), tip) == 0)
            suma += all[i].getSuma();
    return suma;
}

Tranzactie TranzactieService::maxOutInZi(int zi) const {
    int size;
    Tranzactie* all = repo.getAll(size);
    Tranzactie maxT;
    int maxSuma = -1;

    for (int i = 0; i < size; ++i) {
        if (all[i].getZi() == zi &&
            strcmp(all[i].getTip(), "out") == 0 &&
            all[i].getSuma() > maxSuma) {
            maxSuma = all[i].getSuma();
            maxT = all[i];
        }
    }
    return maxT;
}

// FILTRARE
void TranzactieService::filterByTip(const char* tip) {
    int size;
    Tranzactie* all = repo.getAll(size);
    saveState();

    for (int i = size - 1; i >= 0; --i)
        if (strcmp(all[i].getTip(), tip) != 0)
            repo.remove(i);
}

void TranzactieService::filterByTipAndValLess(const char* tip, int sumaMaxima) {
    int size;
    Tranzactie* all = repo.getAll(size);
    saveState();

    for (int i = size - 1; i >= 0; --i) {
        if (strcmp(all[i].getTip(), tip) != 0 ||
            all[i].getSuma() >= sumaMaxima)
            repo.remove(i);
    }
}

// UNDO
bool TranzactieService::undo() {
    if (undoStack.empty()) {
        return false;
    }
    repo = undoStack.back();
    undoStack.pop_back();
    return true;
}
