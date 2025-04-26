#ifndef PUNCT_H
#define PUNCT_H

#include <cmath>

template <class U>
class Punct {
private:
    U coordX;
    U coordY;

public:
    // Constructor
    Punct(U x = 0, U y = 0) : coordX(x), coordY(y) {}

    // Getter methods
    U getX() const { return coordX; }
    U getY() const { return coordY; }

    // Setter methods
    void setX(U x) { coordX = x; }
    void setY(U y) { coordY = y; }

    // Method to calculate the distance between two points
    double getDistance(const Punct<U>& other) const {
        return std::sqrt(std::pow(coordX - other.coordX, 2) + std::pow(coordY - other.coordY, 2));
    }
};

#endif // PUNCT_H
