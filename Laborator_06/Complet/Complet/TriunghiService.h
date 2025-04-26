#ifndef TRIUNGHI_SERVICE_H
#define TRIUNGHI_SERVICE_H

#include "Triunghi.h"
#include "Repository.h"

class TriunghiService {
private:
    Repository<Triunghi> repo;

    // Compute the perimeter of a triangle (internal function)
    double getPerimeter(const Triunghi& triunghi) const;

public:
    // Constructor
    TriunghiService();

    // Destructor
    ~TriunghiService();

    // Add a triangle with three points
    bool add(Punct<int> p1, Punct<int> p2, Punct<int> p3);

    // Remove a triangle
    bool remove(const Triunghi& triunghi);

    // Return the triangle with the largest perimeter
    Triunghi getMaxElement() const;

    // Return all triangles
    Repository<Triunghi> getAll() const;

    // Return the longest sequence of triangles with equal perimeter
    Repository<Triunghi> getMaxEqualSequence() const;

    // Filter triangles where all points are in quadrant I (X > 0 && Y > 0)
    Repository<Triunghi> filterByFirstQuadrant() const;
};

#endif
