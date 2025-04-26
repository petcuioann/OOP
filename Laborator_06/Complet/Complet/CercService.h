#ifndef CERC_SERVICE_H
#define CERC_SERVICE_H

#include "Cerc.h"
#include "Repository.h"

class CercService {
private:
    Repository<Cerc> repo;

public:
    // Constructor
    CercService();

    // Destructor
    ~CercService();

    // Adaugă un cerc în repository
    bool add(const Cerc& cerc);

    // Șterge un cerc din repository
    bool remove(const Cerc& cerc);

    // Returnează cercul cu cea mai mare rază
    Cerc getMaxElement() const;

    // Returnează cea mai lungă secvență de cercuri cu rază egală
    Repository<Cerc> getMaxEqualSequence() const;

    // Returnează toate cercurile din repository
    Repository<Cerc> getAll() const;

    // Filtrează cercurile care au centrul în cadranul 1
    Repository<Cerc> filterByFirstQuadrant() const;
};

#endif
