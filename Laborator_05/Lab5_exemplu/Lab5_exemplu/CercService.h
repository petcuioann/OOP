#ifndef SERVICE_H
#define SERVICE_H

#include "CercRepository.h"

class Service {
private:
    Repository repo;

public:
    Service();

    void adaugaCerc(double raza);
    void stergeCerc(int index);
    void afisareCercuri() const; // Adăugăm această metodă
    void golesteRepository();
    Cerc getCelMaiMareCerc() const;
};

#endif // SERVICE_H
