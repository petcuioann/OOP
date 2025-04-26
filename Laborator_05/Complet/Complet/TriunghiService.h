#ifndef TRIUNGHI_SERVICE_H
#define TRIUNGHI_SERVICE_H

#include "Triunghi.h"
#include "Repository.h"

class TriunghiService {
private:
    Repository<Triunghi> repo;

public:
    // Constructor
    TriunghiService();

    // Destructor
    ~TriunghiService();

    // Adaugă un triunghi
    bool add(double a, double b, double c);

    // Șterge un triunghi
    bool remove(const Triunghi& triunghi);

    // Returnează triunghiul cu cel mai mare perimetru
    Triunghi getMaxElement() const;

    // Returnează toate triunghiurile
    Repository<Triunghi> getAll() const;

    // Returnează cea mai lungă secvență de triunghiuri cu perimetru egal
    Repository<Triunghi> getMaxEqualSequence() const;
};

#endif
