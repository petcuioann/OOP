#include "NumarComplexService.h"
#include <cmath>

// Constructor
NumarComplexService::NumarComplexService() {}

// Destructor
NumarComplexService::~NumarComplexService() {}

// Add a complex number to the repository
bool NumarComplexService::add(const NumarComplex& numar) {
    return repo.add(numar);
}

// Remove a complex number from the repository
bool NumarComplexService::remove(const NumarComplex& numar) {
    int size = repo.getSize();
    for (int i = 0; i < size; ++i) {
        if (repo.get(i).getRe() == numar.getRe() && repo.get(i).getIm() == numar.getIm()) {
            return repo.remove(i);
        }
    }
    return false;
}

// Get the complex number with the largest modulus
NumarComplex NumarComplexService::getMaxElement() const {
    int size = repo.getSize();
    if (size == 0) return NumarComplex();

    NumarComplex maxNumar = repo.get(0);
    double maxModul = getModul(maxNumar);

    for (int i = 1; i < size; ++i) {
        NumarComplex current = repo.get(i);
        double currentModul = getModul(current);
        if (currentModul > maxModul) {
            maxNumar = current;
            maxModul = currentModul;
        }
    }

    return maxNumar;
}

// Get the longest sequence of complex numbers with equal modulus
Repository<NumarComplex> NumarComplexService::getMaxEqualSequence() const {
    Repository<NumarComplex> longestSequence;
    Repository<NumarComplex> currentSequence;
    int size = repo.getSize();

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

        // Compare the last sequence
        if (currentSequence.getSize() > longestSequence.getSize()) {
            longestSequence = currentSequence;
        }
    }

    return longestSequence;
}

// Get all complex numbers
Repository<NumarComplex> NumarComplexService::getAll() const {
    return repo;
}

// Function to filter complex numbers in quadrant I (Re > 0 && Im > 0)
Repository<NumarComplex> NumarComplexService::filterByFirstQuadrant() const {
    Repository<NumarComplex> result;
    int size = repo.getSize();

    for (int i = 0; i < size; ++i) {
        NumarComplex num = repo.get(i);
        if (num.getRe() > 0 && num.getIm() > 0) {
            result.add(num);
        }
    }
    return result;
}

// Helper method to calculate the modulus of a complex number
double NumarComplexService::getModul(const NumarComplex& numar) const {
    return std::sqrt(std::pow(numar.getRe(), 2) + std::pow(numar.getIm(), 2));
}
