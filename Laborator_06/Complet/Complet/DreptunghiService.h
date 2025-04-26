#ifndef DREPTUNGHI_SERVICE_H
#define DREPTUNGHI_SERVICE_H

#include "Dreptunghi.h"
#include "Repository.h"

class DreptunghiService {
private:
    Repository<Dreptunghi> repo;

    double getAria(const Dreptunghi& dreptunghi) const;

public:
    // Constructor
    DreptunghiService();

    // Destructor
    ~DreptunghiService();

    // Add a rectangle using its bottom-left corner, width, and height
    bool add(Punct<int> coltStangaJos, double latime, double inaltime);

    // Remove a rectangle at a given index
    bool remove(int index);

    // Get the rectangle with the largest area
    Dreptunghi getMax() const;

    // Retrieve all rectangles
    Dreptunghi* getAll(int& size) const;

    // Retrieve the longest sequence of rectangles with equal area
    Dreptunghi* getMaxEqualSequence(int& length) const;

    // Filter rectangles where the bottom-left corner is in the first quadrant
    Repository<Dreptunghi> filterByFirstQuadrant() const;
};

#endif
