#pragma once

#include "Punct.h"

class Dreptunghi {
private:
    Punct<int> coltStangaJos; // Bottom-left corner
    double latime, inaltime;

public:
    // Constructor
    Dreptunghi(Punct<int> colt = Punct<int>(0, 0), double latime = 0, double inaltime = 0);

    // Destructor
    ~Dreptunghi();

    // Getter methods
    Punct<int> getColtStangaJos() const;
    double getLatime() const;
    double getInaltime() const;

    // Setter methods
    void setColtStangaJos(Punct<int> colt);
    void setLatime(double latime);
    void setInaltime(double inaltime);
};
