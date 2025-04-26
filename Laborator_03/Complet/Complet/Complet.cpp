#include <iostream>
#include <cctype>
#include "io.h"  // Schimbăm include-ul aici
#include "utils.h"
#include "probleme.h"

using namespace std;

int main() {
    int* x = nullptr;
    int n = 0;
    bool ruleaza = true;

    while (ruleaza) {
        cout << "\n==== MENIU PRINCIPAL ====\n";
        cout << "1. Citire sir de numere intregi\n";
        cout << "2. Afisare sir\n";
        cout << "3. Cea mai lunga secventa strict crescatoare\n";
        cout << "4. Cea mai lunga secventa cu cel mult 3 valori distincte\n";
        cout << "5. Cea mai lunga secventa cu numere prime\n";
        cout << "6. Cea mai lunga secventa cu elemente distincte\n";
        cout << "7. Cea mai lunga secventa unde diferentele consecutive sunt prime\n";
        cout << "8. Cea mai lunga secventa in intervalul [a, b] (introdus de la tastatura)\n";
        cout << "9. Cea mai lunga secventa cu diferente de semn opuse intre perechi\n";
        cout << "10. Cea mai lunga secventa cu semne opuse intre elemente consecutive\n";
        cout << "11. Cea mai lunga secventa cu suma egala cu o valoare data\n";
        cout << "12. Cea mai lunga secventa in care elementele consecutive au 2 cifre comune\n";
        cout << "13. Cea mai lunga secventa in forma de munte\n";
        cout << "x. Iesire\n";

        cout << "\nOptiune: ";
        int opt;  // Modificăm opt la int
        cin >> opt;

        switch (opt) {
        case 1:
            if (x != nullptr) delete[] x;
            cout << "Numar elemente: ";
            cin >> n;
            x = new int[n];
            citire(x, n);
            break;

        case 2:
            if (x == nullptr) cout << "Sirul nu a fost citit!\n";
            else afisare(x, n);
            break;

        case 3: {
            int lung;
            int* r = problema1(x, n, lung);
            cout << "Secventa strict crescatoare: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 4: {
            int lung;
            int* r = problema2(x, n, lung);
            cout << "Secventa cu cel mult 3 valori distincte: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 5: {
            int lung;
            int* r = problema3(x, n, lung);
            cout << "Secventa cu numere prime: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 6: {
            int lung;
            int* r = problema4(x, n, lung);
            cout << "Secventa cu elemente distincte: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 7: {
            int lung;
            int* r = problema5(x, n, lung);
            cout << "Secventa cu diferente consecutive prime: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 8: {
            int a, b;
            cout << "Introdu intervalul [a, b]: ";
            cin >> a >> b;
            int lung;
            int* r = problema6(x, n, lung, a, b);
            cout << "Secventa in intervalul [" << a << ", " << b << "]: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 9: {
            int lung;
            int* r = problema7(x, n, lung);
            cout << "Secventa cu diferente de semn opuse intre perechi: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 10: {
            int lung;
            int* r = problema8(x, n, lung);
            cout << "Secventa cu semne opuse intre elemente consecutive: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 11: {
            int suma;
            cout << "Introdu suma dorita: ";
            cin >> suma;
            int lung;
            int* r = problema9(x, n, lung, suma);
            cout << "Secventa cu suma egala cu " << suma << ": ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 12: {
            int lung;
            int* r = problema10(x, n, lung);
            cout << "Secventa in care elementele consecutive au 2 cifre comune: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 13: {
            int lung;
            int* r = problema11(x, n, lung);
            cout << "Secventa in forma de munte: ";
            afisare(r, lung);
            delete[] r;
            break;
        }

        case 'x':  // Modificăm 'x' pentru a corespunde la ieșire
            ruleaza = false;
            break;

        default:
            cout << "Optiune invalida!\n";
        }
    }

    if (x != nullptr) delete[] x;
    return 0;
}
