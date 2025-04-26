#include <iostream>
#include "NumarComplex.h"
using namespace std;

int main() {
    // Creare obiecte
    NumarComplex n1(3.0, 4.0), n2(1.0, 2.0);

    // Afisare numere complexe
    cout << "Numar complex 1: ";
    n1.afiseaza();
    cout << "Numar complex 2: ";
    n2.afiseaza();

    // Adunare
    NumarComplex n3 = n1.aduna(n2);
    cout << "Suma: ";
    n3.afiseaza();

    return 0;
}
