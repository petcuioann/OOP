#ifndef PATRAT_SERVICE_H
#define PATRAT_SERVICE_H

#include "Patrat.h"
#include "Repository.h"

class PatratService {
private:
    Repository<Patrat> repo;

public:
    // Constructor
    PatratService();

    // Destructor
    ~PatratService();

    // Adaugă un pătrat specificând colțul stânga jos și latura
    bool add(Punct<int> coltStangaJos, double latura);

    // Șterge un pătrat din repository
    bool remove(const Patrat& patrat);

    // Returnează pătratul cu cea mai mare latură
    Patrat getMaxElement() const;

    // Returnează toate pătratele
    Repository<Patrat> getAll() const;

    // Returnează cea mai lungă secvență de pătrate cu latură egală
    Repository<Patrat> getMaxEqualSequence() const;

    // Filtrează pătratele care au colțul stânga jos în cadranul 1 (X > 0 și Y > 0)
    Repository<Patrat> filterByFirstQuadrant() const;
};

#endif
