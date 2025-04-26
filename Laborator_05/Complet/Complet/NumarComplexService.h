#ifndef NUMAR_COMPLEX_SERVICE_H
#define NUMAR_COMPLEX_SERVICE_H

#include "NumarComplex.h"
#include "Repository.h"

class NumarComplexService {
private:
    Repository<NumarComplex> repo;

    double getModul(const NumarComplex& numar) const;

public:
    // Constructor
    NumarComplexService();

    // Destructor
    ~NumarComplexService();

    // Adaugă un număr complex în repository
    bool add(const NumarComplex& numar);

    // Șterge un număr complex din repository
    bool remove(const NumarComplex& numar);

    // Returnează elementul cu cel mai mare modul
    NumarComplex getMaxElement() const;

    // Returnează cea mai lungă secvență de numere complexe cu modul egal
    Repository<NumarComplex> getMaxEqualSequence() const;

    // Returnează toate elementele din repository
    Repository<NumarComplex> getAll() const;
};

#endif
