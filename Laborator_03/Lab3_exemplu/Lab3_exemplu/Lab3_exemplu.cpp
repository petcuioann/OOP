#include <iostream>
#include <cctype>
#include "utils.h"
#include "probleme.h"

using namespace std;

int main() {
    int* x = nullptr;
    int n = 0;
    bool running = true;

    while (running) {
        cout << "\n--- Meniu Principal ---\n";
        cout << "1. Citire vector\n";
        cout << "2. Afisare vector\n";
        cout << "3. Problema 1: Afisarea celei mai lungi secvente strict crescatoare\n";
        cout << "4. Problema 6: Afisarea celei mai lungi secvente cu toate elementele intr-un interval [a, b] dat\n";
        cout << "X. Iesire\n";
        cout << "Alege optiunea: ";

        char opt;
        cin >> opt;
        opt = tolower(opt);

        switch (opt) {
        case '1':
            delete[] x;
            citireVector(x, n);
            break;
        case '2':
            afisareVector(x, n);
            break;
        case '3': {
            int lungime;
            int* rez = ceaMaiLungaSecventaCrescatoare(x, n, lungime);
            cout << "Secventa cea mai lunga strict crescatoare: ";
            for (int i = 0; i < lungime; ++i)
                cout << rez[i] << " ";
            cout << "\n";
            delete[] rez;
            break;
        }
        case '4': {
            int a, b;
            cout << "Introdu intervalul [a, b]: ";
            cin >> a >> b;
            int lungime;
            int* rez = ceaMaiLungaSecventaInInterval(x, n, a, b, lungime);
            cout << "Secventa cea mai lunga in intervalul [" << a << ", " << b << "]: ";
            for (int i = 0; i < lungime; ++i)
                cout << rez[i] << " ";
            cout << "\n";
            delete[] rez;
            break;
        }
        case 'x':
            running = false;
            break;
        default:
            cout << "Optiune invalida!\n";
        }
    }

    delete[] x;
    return 0;
}
