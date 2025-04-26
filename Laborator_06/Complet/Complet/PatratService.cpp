#include "PatratService.h"

// Constructor
PatratService::PatratService() {}

// Destructor
PatratService::~PatratService() {}

// Add a square to the repository
bool PatratService::add(Punct<int> coltStangaJos, double latura) {
    return repo.add(Patrat(coltStangaJos, latura));
}

// Remove a square from the repository
bool PatratService::remove(const Patrat& patrat) {
    int size = repo.getSize();
    for (int i = 0; i < size; ++i) {
        if (repo.get(i).getColtStangaJos().getX() == patrat.getColtStangaJos().getX() &&
            repo.get(i).getColtStangaJos().getY() == patrat.getColtStangaJos().getY() &&
            repo.get(i).getLatura() == patrat.getLatura()) {
            return repo.remove(i);
        }
    }
    return false;
}

// Get the square with the largest side length
Patrat PatratService::getMaxElement() const {
    int size = repo.getSize();
    if (size == 0) return Patrat();

    Patrat maxPatrat = repo.get(0);
    double maxLatura = maxPatrat.getLatura();

    for (int i = 1; i < size; ++i) {
        Patrat current = repo.get(i);
        if (current.getLatura() > maxLatura) {
            maxPatrat = current;
            maxLatura = current.getLatura();
        }
    }

    return maxPatrat;
}

// Get all squares
Repository<Patrat> PatratService::getAll() const {
    return repo;
}

// Get the longest sequence of squares with equal side length
Repository<Patrat> PatratService::getMaxEqualSequence() const {
    int size = repo.getSize();
    if (size == 0) return Repository<Patrat>();

    Repository<Patrat> longestSequence;
    Repository<Patrat> currentSequence;

    if (size > 0) {
        currentSequence.add(repo.get(0));
        double currentLatura = repo.get(0).getLatura();

        for (int i = 1; i < size; ++i) {
            if (repo.get(i).getLatura() == currentLatura) {
                currentSequence.add(repo.get(i));
            }
            else {
                if (currentSequence.getSize() > longestSequence.getSize()) {
                    longestSequence = currentSequence;
                }
                currentSequence = Repository<Patrat>();
                currentSequence.add(repo.get(i));
                currentLatura = repo.get(i).getLatura();
            }
        }

        if (currentSequence.getSize() > longestSequence.getSize()) {
            longestSequence = currentSequence;
        }
    }

    return longestSequence;
}

// Function to filter squares where bottom-left corner is in quadrant I (X > 0 && Y > 0)
Repository<Patrat> PatratService::filterByFirstQuadrant() const {
    Repository<Patrat> result;
    int size = repo.getSize();

    for (int i = 0; i < size; ++i) {
        Punct<int> coltStangaJos = repo.get(i).getColtStangaJos();
        if (coltStangaJos.getX() > 0 && coltStangaJos.getY() > 0) {
            result.add(repo.get(i));
        }
    }
    return result;
}
