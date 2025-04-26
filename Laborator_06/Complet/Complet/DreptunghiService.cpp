#include "DreptunghiService.h"

// Constructor
DreptunghiService::DreptunghiService() {}

// Destructor
DreptunghiService::~DreptunghiService() {}

// Add a rectangle to the repository
bool DreptunghiService::add(Punct<int> coltStangaJos, double latime, double inaltime) {
    return repo.add(Dreptunghi(coltStangaJos, latime, inaltime));
}

// Remove a rectangle from the repository by index
bool DreptunghiService::remove(int index) {
    return repo.remove(index);
}

// Get the rectangle with the largest area
Dreptunghi DreptunghiService::getMax() const {
    int size = repo.getSize();
    if (size == 0) return Dreptunghi(); // Return an empty rectangle if repository is empty

    Dreptunghi maxDreptunghi = repo.get(0);
    double maxArie = getAria(maxDreptunghi);

    for (int i = 1; i < size; ++i) {
        Dreptunghi current = repo.get(i);
        double currentArie = getAria(current);
        if (currentArie > maxArie) {
            maxDreptunghi = current;
            maxArie = currentArie;
        }
    }

    return maxDreptunghi;
}

// Get all rectangles
Dreptunghi* DreptunghiService::getAll(int& size) const {
    return repo.getAll(size);
}

// Get the longest sequence of rectangles with equal area
Dreptunghi* DreptunghiService::getMaxEqualSequence(int& length) const {
    int size = repo.getSize();
    if (size == 0) {
        length = 0;
        return nullptr;
    }

    Dreptunghi* longestSequence = nullptr;
    Dreptunghi* currentSequence = nullptr;
    int longestSize = 0;
    int currentSize = 0;

    if (size > 0) {
        currentSequence = new Dreptunghi[size];
        currentSequence[currentSize++] = repo.get(0);
        double currentArie = getAria(repo.get(0));

        for (int i = 1; i < size; ++i) {
            if (getAria(repo.get(i)) == currentArie) {
                currentSequence[currentSize++] = repo.get(i);
            }
            else {
                if (currentSize > longestSize) {
                    delete[] longestSequence;
                    longestSequence = currentSequence;
                    longestSize = currentSize;
                }
                currentSequence = new Dreptunghi[size];
                currentSize = 0;
                currentSequence[currentSize++] = repo.get(i);
                currentArie = getAria(repo.get(i));
            }
        }

        // Compare last sequence
        if (currentSize > longestSize) {
            delete[] longestSequence;
            longestSequence = currentSequence;
            longestSize = currentSize;
        }
    }

    length = longestSize;
    return longestSequence;
}

// Function to filter rectangles with bottom-left corner in quadrant I
Repository<Dreptunghi> DreptunghiService::filterByFirstQuadrant() const {
    Repository<Dreptunghi> result;
    int size = repo.getSize();

    for (int i = 0; i < size; ++i) {
        Punct<int> coltStangaJos = repo.get(i).getColtStangaJos();
        if (coltStangaJos.getX() > 0 && coltStangaJos.getY() > 0) {
            result.add(repo.get(i));
        }
    }
    return result;
}

// Helper method to calculate the area of a rectangle
double DreptunghiService::getAria(const Dreptunghi& dreptunghi) const {
    return dreptunghi.getLatime() * dreptunghi.getInaltime();
}
