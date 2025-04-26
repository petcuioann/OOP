#include "NumarComplexService.h"
#include <cmath>

// Constructor
NumarComplexService::NumarComplexService() {}

// Destructor
NumarComplexService::~NumarComplexService() {}

double NumarComplexService::getModul(const NumarComplex& numar) const {
    return std::sqrt(numar.getRe() * numar.getRe() + numar.getIm() * numar.getIm());
}

bool NumarComplexService::add(const NumarComplex& numar) {
    return repo.add(numar);
}

bool NumarComplexService::remove(const NumarComplex& numar) {
    int size = repo.getSize();
    for (int i = 0; i < size; ++i) {
        if (repo.get(i).getRe() == numar.getRe() && repo.get(i).getIm() == numar.getIm()) {
            return repo.remove(i);
        }
    }
    return false; // Dacă nu a fost găsit, returnăm false
}

NumarComplex NumarComplexService::getMaxElement() const {
    int size = repo.getSize();
    if (size == 0) return NumarComplex(); // Returnează un obiect implicit dacă lista e goală

    NumarComplex maxElement = repo.get(0);
    double maxModul = getModul(maxElement);

    for (int i = 1; i < size; ++i) {
        NumarComplex current = repo.get(i);
        double currentModul = getModul(current);
        if (currentModul > maxModul) {
            maxElement = current;
            maxModul = currentModul;
        }
    }

    return maxElement;
}

Repository<NumarComplex> NumarComplexService::getMaxEqualSequence() const {
    int size = repo.getSize();
    if (size == 0) return Repository<NumarComplex>(); // Returnează un repository gol dacă lista e goală

    Repository<NumarComplex> longestSequence;
    Repository<NumarComplex> currentSequence;

    if (size > 0) {
        currentSequence.add(repo.get(0));
        double currentModul = getModul(repo.get(0));

        for (int i = 1; i < size; ++i) {
            if (getModul(repo.get(i)) == currentModul) {
                currentSequence.add(repo.get(i));
            }
            else {
                if (currentSequence.getSize() > longestSequence.getSize()) {
                    longestSequence = currentSequence;
                }
                currentSequence = Repository<NumarComplex>();
                currentSequence.add(repo.get(i));
                currentModul = getModul(repo.get(i));
            }
        }

        // Comparăm ultima secvență
        if (currentSequence.getSize() > longestSequence.getSize()) {
            longestSequence = currentSequence;
        }
    }

    return longestSequence;
}

Repository<NumarComplex> NumarComplexService::getAll() const {
    return repo;
}
