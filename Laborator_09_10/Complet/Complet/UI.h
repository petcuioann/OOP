#ifndef UI_H
#define UI_H

#include "Service.h"

class UI {
private:
    Service& service;

public:
    UI(Service& s);

    void start();               // Meniu principal

    void addUI();               // 1. Adaugă produs
    void removeUI();            // 2. Șterge produs
    void updateUI();            // 3. Modifică produs
    void listUI();              // 4. Listează produse
    void cumparaProdusUI();     // 5. Cumpără produs
    void setMonedeUI();         // 6. Setează monede disponibile
};

#endif // UI_H
