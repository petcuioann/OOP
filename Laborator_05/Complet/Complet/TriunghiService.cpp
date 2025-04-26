#include "TriunghiService.h"

// Constructor
TriunghiService::TriunghiService() {}

// Destructor
TriunghiService::~TriunghiService() {}

bool TriunghiService::add(double a, double b, double c) {
    return repo.add(Triunghi(a, b, c));
}

bool TriunghiService::remove(const Triunghi& triunghi) {
    int size = repo.getSize();
    for (int i = 0; i < size; ++i) {
        if (repo.get(i).getLatura1() == triunghi.getLatura1() &&
            repo.get(i).getLatura2() == triunghi.getLatura2() &&
            repo.get(i).getLatura3() == triunghi.getLatura3()) {
            return repo.remove(i);
        }
    }
    return false; // Dacă nu a fost găsit, returnăm false
}

Triunghi TriunghiService::getMaxElement() const {
    int size = repo.getSize();
    if (size == 0) return Triunghi(); // Returnează un triunghi implicit dacă repository-ul e gol

    Triunghi maxElement = repo.get(0);
    double maxPerimetru = maxElement.getLatura1() + maxElement.getLatura2() + maxElement.getLatura3();

    for (int i = 1; i < size; ++i) {
        Triunghi current = repo.get(i);
        double currentPerimetru = current.getLatura1() + current.getLatura2() + current.getLatura3();
        if (currentPerimetru > maxPerimetru) {
            maxElement = current;
            maxPerimetru = currentPerimetru;
        }
    }

    return maxElement;
}

Repository<Triunghi> TriunghiService::getAll() const {
    return repo;
}

Repository<Triunghi> TriunghiService::getMaxEqualSequence() const {
    int size = repo.getSize();
    if (size == 0) return Repository<Triunghi>(); // Returnează un repository gol dacă lista e goală

    Repository<Triunghi> longestSequence;
    Repository<Triunghi> currentSequence;

    if (size > 0) {
        currentSequence.add(repo.get(0));
        double currentPerimetru = repo.get(0).getLatura1() + repo.get(0).getLatura2() + repo.get(0).getLatura3();

        for (int i = 1; i < size; ++i) {
            double perimetruTriunghi = repo.get(i).getLatura1() + repo.get(i).getLatura2() + repo.get(i).getLatura3();
            if (perimetruTriunghi == currentPerimetru) {
                currentSequence.add(repo.get(i));
            }
            else {
                if (currentSequence.getSize() > longestSequence.getSize()) {
                    longestSequence = currentSequence;
                }
                currentSequence = Repository<Triunghi>();
                currentSequence.add(repo.get(i));
                currentPerimetru = perimetruTriunghi;
            }
        }

        if (currentSequence.getSize() > longestSequence.getSize()) {
            longestSequence = currentSequence;
        }
    }

    return longestSequence;
}
