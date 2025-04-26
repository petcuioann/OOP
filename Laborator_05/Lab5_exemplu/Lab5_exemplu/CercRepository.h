#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Cerc.h"

#define MAX_CERCURI 100  // Limităm repository-ul la 100 de cercuri

class Repository {
private:
    Cerc cercuri[MAX_CERCURI]; // Tablou static de obiecte Cerc
    int nrCercuri; // Numărul actual de cercuri

public:
    Repository(); // Constructor

    void adaugaCerc(const Cerc& c); // Adăugare cerc
    void stergeCerc(int index); // Ștergere cerc
    const Cerc& getCerc(int index) const; // Accesare cerc
    int getNrCercuri() const; // Obținerea numărului de cercuri
    void afiseazaCercuri() const; // Afișare lista de cercuri
    void golesteRepository(); // Șterge toate cercurile
};

#endif // REPOSITORY_H
