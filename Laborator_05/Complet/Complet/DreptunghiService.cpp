#include "DreptunghiService.h"

// Constructor
DreptunghiService::DreptunghiService() {}

// Destructor
DreptunghiService::~DreptunghiService() {}

double DreptunghiService::getAria(const Dreptunghi& dreptunghi) const {
    return dreptunghi.getLungime() * dreptunghi.getLatime();
}

bool DreptunghiService::add(double lungime, double latime) {
    return repo.add(Dreptunghi(lungime, latime));
}

bool DreptunghiService::remove(int index) {
    return repo.remove(index);
}

Dreptunghi DreptunghiService::getMax() const {
    int size = repo.getSize();
    if (size == 0) return Dreptunghi(); // Returnează un dreptunghi implicit dacă lista e goală

    Dreptunghi maxElement = repo.get(0);
    double maxAria = getAria(maxElement);

    for (int i = 1; i < size; ++i) {
        Dreptunghi current = repo.get(i);
        double currentAria = getAria(current);
        if (currentAria > maxAria) {
            maxElement = current;
            maxAria = currentAria;
        }
    }

    return maxElement;
}

Dreptunghi* DreptunghiService::getAll(int& size) const {
    return repo.getAll(size);
}

Dreptunghi* DreptunghiService::getMaxEqualSequence(int& length) const {
    int size = repo.getSize();
    if (size == 0) {
        length = 0;
        return nullptr;
    }

    Dreptunghi* longestSequence = nullptr;
    int longestSize = 0;

    Dreptunghi* currentSequence = new Dreptunghi[100];
    int currentSize = 0;

    currentSequence[currentSize++] = repo.get(0);
    double currentAria = getAria(repo.get(0));

    for (int i = 1; i < size; ++i) {
        if (getAria(repo.get(i)) == currentAria) {
            currentSequence[currentSize++] = repo.get(i);
        }
        else {
            if (currentSize > longestSize) {
                delete[] longestSequence;
                longestSequence = new Dreptunghi[currentSize];
                for (int j = 0; j < currentSize; ++j) {
                    longestSequence[j] = currentSequence[j];
                }
                longestSize = currentSize;
            }
            currentSize = 0;
            currentSequence[currentSize++] = repo.get(i);
            currentAria = getAria(repo.get(i));
        }
    }

    // Comparăm ultima secvență
    if (currentSize > longestSize) {
        delete[] longestSequence;
        longestSequence = new Dreptunghi[currentSize];
        for (int j = 0; j < currentSize; ++j) {
            longestSequence[j] = currentSequence[j];
        }
        longestSize = currentSize;
    }

    delete[] currentSequence;
    length = longestSize;
    return longestSequence;
}