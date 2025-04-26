#include <iostream>
#include <cctype>
#include "probleme.h"

using namespace std;

void meniu() {
    int optiune, n, x[100];
    do {
        cout << "\nMeniu Principal:\n";
        cout << "1. Secventa strict crescatoare\n";
        cout << "2. Secventa cu max 3 valori distincte\n";
        cout << "3. Secventa doar cu numere prime\n";
        cout << "4. Secventa cu numere distincte\n";
        cout << "5. Secventa cu diferente prime\n";
        cout << "6. Secventa in interval [a, b]\n";
        cout << "7. Secventa cu diferente alternante\n";
        cout << "8. Secventa cu semne alternante\n";
        cout << "9. Secventa cu suma constanta\n";
        cout << "10. Secventa cu 2 cifre comune\n";
        cout << "11. Secventa in forma de munte\n";
        cout << "0. Iesire\n";
        cout << "Alegeti o optiune: ";
        cin >> optiune;

        if (optiune >= 1 && optiune <= 11) {
            citire(n, x);
        }

        switch (optiune) {
        case 1: Problema1(n, x); break;
        case 2: Problema2(n, x); break;
        case 3: Problema3(n, x); break;
        case 4: Problema4(n, x); break;
        case 5: Problema5(n, x); break;
        case 6: Problema6(n, x); break;
        case 7: Problema7(n, x); break;
        case 8: Problema8(n, x); break;
        case 9: Problema9(n, x); break;
        case 10: Problema10(n, x); break;
        case 11: Problema11(n, x); break;
        case 0: cout << "Iesire...\n"; break;
        default: cout << "Optiune invalida!\n"; break;
        }
    } while (optiune != 0);
}

int main() {
    meniu();
    return 0;
}
