#include "TriunghiService.h"
#include <cmath>

// Constructor
TriunghiService::TriunghiService() {}

// Destructor
TriunghiService::~TriunghiService() {}

// Compute the perimeter of a triangle
double TriunghiService::getPerimeter(const Triunghi& triunghi) const {
    auto dist = [](const Punct<int>& a, const Punct<int>& b) {
        return std::sqrt(std::pow(b.getX() - a.getX(), 2) + std::pow(b.getY() - a.getY(), 2));
        };

    return dist(triunghi.getPunct1(), triunghi.getPunct2()) +
        dist(triunghi.getPunct2(), triunghi.getPunct3()) +
        dist(triunghi.getPunct3(), triunghi.getPunct1());
}

// Add a triangle with three points
bool TriunghiService::add(Punct<int> p1, Punct<int> p2, Punct<int> p3) {
    return repo.add(Triunghi(p1, p2, p3));
}

// Remove a triangle from the repository
bool TriunghiService::remove(const Triunghi& triunghi) {
    int size = repo.getSize();
    for (int i = 0; i < size; ++i) {
        if (repo.get(i).getPunct1().getX() == triunghi.getPunct1().getX() &&
            repo.get(i).getPunct1().getY() == triunghi.getPunct1().getY() &&
            repo.get(i).getPunct2().getX() == triunghi.getPunct2().getX() &&
            repo.get(i).getPunct2().getY() == triunghi.getPunct2().getY() &&
            repo.get(i).getPunct3().getX() == triunghi.getPunct3().getX() &&
            repo.get(i).getPunct3().getY() == triunghi.getPunct3().getY()) {
            return repo.remove(i);
        }
    }
    return false;
}

// Get the triangle with the largest perimeter
Triunghi TriunghiService::getMaxElement() const {
    int size = repo.getSize();
    if (size == 0) return Triunghi();

    Triunghi maxTriunghi = repo.get(0);
    double maxPerimeter = getPerimeter(maxTriunghi);

    for (int i = 1; i < size; ++i) {
        Triunghi current = repo.get(i);
        double currentPerimeter = getPerimeter(current);
        if (currentPerimeter > maxPerimeter) {
            maxTriunghi = current;
            maxPerimeter = currentPerimeter;
        }
    }

    return maxTriunghi;
}

// Get all triangles
Repository<Triunghi> TriunghiService::getAll() const {
    return repo;
}

// Get the longest sequence of triangles with equal perimeter
Repository<Triunghi> TriunghiService::getMaxEqualSequence() const {
    Repository<Triunghi> longestSequence;
    Repository<Triunghi> currentSequence;
    int size = repo.getSize();

    if (size > 0) {
        currentSequence.add(repo.get(0));
        double currentPerimeter = getPerimeter(repo.get(0));

        for (int i = 1; i < size; ++i) {
            if (getPerimeter(repo.get(i)) == currentPerimeter) {
                currentSequence.add(repo.get(i));
            }
            else {
                if (currentSequence.getSize() > longestSequence.getSize()) {
                    longestSequence = currentSequence;
                }
                currentSequence = Repository<Triunghi>();
                currentSequence.add(repo.get(i));
                currentPerimeter = getPerimeter(repo.get(i));
            }
        }

        if (currentSequence.getSize() > longestSequence.getSize()) {
            longestSequence = currentSequence;
        }
    }

    return longestSequence;
}

// Function to filter triangles where all points are in quadrant I (X > 0 && Y > 0)
Repository<Triunghi> TriunghiService::filterByFirstQuadrant() const {
    Repository<Triunghi> result;
    int size = repo.getSize();

    for (int i = 0; i < size; ++i) {
        Triunghi triunghi = repo.get(i);
        Punct<int> p1 = triunghi.getPunct1();
        Punct<int> p2 = triunghi.getPunct2();
        Punct<int> p3 = triunghi.getPunct3();

        if (p1.getX() > 0 && p1.getY() > 0 &&
            p2.getX() > 0 && p2.getY() > 0 &&
            p3.getX() > 0 && p3.getY() > 0) {
            result.add(triunghi);
        }
    }
    return result;
}
