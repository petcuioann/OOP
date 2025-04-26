#include <iostream>
#include "probleme.h"

using namespace std;

int main() {
    int x[100], n = 0;
    int opt;

    do {
        cout << "\n=== Meniu Principal ===\n";
        cout << "1. Citire lista de numere intregi\n";
        cout << "2. Afisare lista\n";
        cout << "3. Cea mai lunga secventa cu proprietatea 1 (strict crescatoare)\n";
        cout << "4. Cea mai lunga secventa cu proprietatea 3 (doar numere prime)\n";
        cout << "0. Iesire\n";
        cout << "Optiune: ";
        cin >> opt;

        switch (opt) {
        case 1: citire(x, n); break;
        case 2: afisare(x, n); break;
        case 3: secventaCrescatoare(x, n); break;
        case 4: secventaPrime(x, n); break;
        case 0: cout << "Iesire...\n"; break;
        default: cout << "Optiune invalida!\n";
        }
    } while (opt != 0);

    return 0;
}
