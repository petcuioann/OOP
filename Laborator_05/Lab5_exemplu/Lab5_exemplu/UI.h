#ifndef UI_H
#define UI_H

#include "CercService.h"

class UI {
private:
    Service service;

public:
    UI(); // Constructor

    void start(); // Pornirea aplicației
    void afisareMeniu() const; // Afișarea opțiunilor
    void adaugareCerc(); // Adăugarea unui cerc nou
    void stergereCerc(); // Ștergerea unui cerc
    void afisareCercuri(); // Afișarea cercurilor existente
    void afisareCelMaiMareCerc(); // Afișarea celui mai mare cerc
    void stergereToateCercurile(); // Ștergerea tuturor cercurilor
};

#endif // UI_H
