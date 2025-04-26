#include "CercService.h"

// Constructor
CercService::CercService() {}

// Destructor
CercService::~CercService() {}

bool CercService::add(const Cerc& cerc) {
    return repo.add(cerc);
}

bool CercService::remove(const Cerc& cerc) {
    int size = repo.getSize();
    for (int i = 0; i < size; ++i) {
        if (repo.get(i).getRaza() == cerc.getRaza()) {
            return repo.remove(i);
        }
    }
    return false; // Dacă nu a fost găsit, returnăm false
}

Cerc CercService::getMaxElement() const {
    int size = repo.getSize();
    if (size == 0) return Cerc(); // Returnează un obiect implicit dacă lista e goală

    Cerc maxElement = repo.get(0);
    double maxRaza = maxElement.getRaza();

    for (int i = 1; i < size; ++i) {
        Cerc current = repo.get(i);
        double currentRaza = current.getRaza();
        if (currentRaza > maxRaza) {
            maxElement = current;
            maxRaza = currentRaza;
        }
    }

    return maxElement;
}

Repository<Cerc> CercService::getMaxEqualSequence() const {
    int size = repo.getSize();
    if (size == 0) return Repository<Cerc>(); // Returnează un repository gol dacă lista e goală

    Repository<Cerc> longestSequence;
    Repository<Cerc> currentSequence;

    if (size > 0) {
        currentSequence.add(repo.get(0));
        double currentRaza = repo.get(0).getRaza();

        for (int i = 1; i < size; ++i) {
            if (repo.get(i).getRaza() == currentRaza) {
                currentSequence.add(repo.get(i));
            }
            else {
                if (currentSequence.getSize() > longestSequence.getSize()) {
                    longestSequence = currentSequence;
                }
                currentSequence = Repository<Cerc>();
                currentSequence.add(repo.get(i));
                currentRaza = repo.get(i).getRaza();
            }
        }

        // Comparăm ultima secvență
        if (currentSequence.getSize() > longestSequence.getSize()) {
            longestSequence = currentSequence;
        }
    }

    return longestSequence;
}

Repository<Cerc> CercService::getAll() const {
    return repo;
}

Repository<Cerc> CercService::filterByFirstQuadrant() const {
    Repository<Cerc> result;
    int size = repo.getSize();
    for (int i = 0; i < size; ++i) {
        Cerc cerc = repo.get(i);
        Punct<int> centru = cerc.getCentru();
        double raza = cerc.getRaza();

        if (centru.getX() - raza > 0 && centru.getY() - raza > 0) {
            result.add(cerc);
        }
    }
    return result;
}