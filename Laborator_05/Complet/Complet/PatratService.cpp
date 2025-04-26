#include "PatratService.h"

// Constructor
PatratService::PatratService() {}

// Destructor
PatratService::~PatratService() {}

bool PatratService::add(double latura) {
    return repo.add(Patrat(latura));
}

bool PatratService::remove(const Patrat& patrat) {
    int size = repo.getSize();
    for (int i = 0; i < size; ++i) {
        if (repo.get(i).getLatura() == patrat.getLatura()) {
            return repo.remove(i);
        }
    }
    return false; // Dacă nu a fost găsit, returnăm false
}

Patrat PatratService::getMaxElement() const {
    int size = repo.getSize();
    if (size == 0) return Patrat(); // Returnează un pătrat implicit dacă repository-ul e gol

    Patrat maxElement = repo.get(0);
    double maxLatura = maxElement.getLatura();

    for (int i = 1; i < size; ++i) {
        Patrat current = repo.get(i);
        double currentLatura = current.getLatura();
        if (currentLatura > maxLatura) {
            maxElement = current;
            maxLatura = currentLatura;
        }
    }

    return maxElement;
}

Repository<Patrat> PatratService::getAll() const {
    return repo;
}

Repository<Patrat> PatratService::getMaxEqualSequence() const {
    int size = repo.getSize();
    if (size == 0) return Repository<Patrat>(); // Returnează un repository gol dacă lista e goală

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
