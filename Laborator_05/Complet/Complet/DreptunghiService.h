#ifndef DREPTUNGHI_SERVICE_H
#define DREPTUNGHI_SERVICE_H

#include "Dreptunghi.h"
#include "Repository.h"

class DreptunghiService {
private:
    Repository<Dreptunghi> repo;

    double getAria(const Dreptunghi& dreptunghi) const;

public:
    // Constructor
    DreptunghiService();

    // Destructor
    ~DreptunghiService();

    // Adaugă un dreptunghi
    bool add(double lungime, double latime);

    // Șterge un dreptunghi la un anumit index
    bool remove(int index);

    // Returnează dreptunghiul cu cea mai mare arie
    Dreptunghi getMax() const;

    // Returnează toate dreptunghiurile
    Dreptunghi* getAll(int& size) const;

    // Returnează cea mai lungă secvență de dreptunghiuri cu aria egală
    Dreptunghi* getMaxEqualSequence(int& length) const;
};

#endif
