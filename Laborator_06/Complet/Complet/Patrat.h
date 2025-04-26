#pragma once

#include "Punct.h"

class Patrat {
private:
    Punct<int> coltStangaJos; // Bottom-left corner
    double latura;

public:
    // Constructor
    Patrat(Punct<int> colt = Punct<int>(0, 0), double l = 0);

    // Destructor
    ~Patrat();

    // Getter methods
    Punct<int> getColtStangaJos() const;
    double getLatura() const;

    // Setter methods
    void setColtStangaJos(Punct<int> colt);
    void setLatura(double l);
};
