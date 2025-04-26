#include <iostream>
#include "NumarComplex.h"
#include "Patrat.h"
#include "Triunghi.h"
#include "Cerc.h"
#include "Dreptunghi.h"

using namespace std;

int main() {
    // Testarea clasei NumarComplex
    NumarComplex n1(3.0, 4.0), n2(1.0, 2.0);
    cout << "Numar complex 1: ";
    n1.afiseaza();
    cout << "Numar complex 2: ";
    n2.afiseaza();

    NumarComplex n3 = n1.aduna(n2);
    cout << "Suma numerelor complexe: ";
    n3.afiseaza();
    cout << endl;

    // Testarea clasei Patrat
    Patrat p1(5.0);
    cout << "Patrat cu latura " << p1.getLatura() << ": " << endl;
    cout << "Aria: " << p1.aria() << endl;
    cout << "Perimetrul: " << p1.perimetru() << endl;
    cout << endl;

    // Testarea clasei Triunghi
    Triunghi t1(4.0, 6.0);  // Baza 4 și înălțimea 6
    cout << "Triunghi cu baza " << t1.getBaza() << " si inaltimea " << t1.getInaltime() << ": " << endl;
    cout << "Aria: " << t1.aria() << endl;
    cout << "Perimetrul (presupunem triunghi dreptunghic): "
        << t1.perimetru(4.0, 5.0) << endl;  // Exemplu pentru triunghi dreptunghic
    cout << endl;

    // Testarea clasei Cerc
    Cerc c1(7.0);
    cout << "Cerc cu raza " << c1.getRaza() << ": " << endl;
    cout << "Aria: " << c1.aria() << endl;
    cout << "Circumferinta: " << c1.circumferinta() << endl;
    cout << endl;

    // Testarea clasei Dreptunghi
    Dreptunghi d1(8.0, 4.0);
    cout << "Dreptunghi cu lungimea " << d1.getLungime() << " si latimea " << d1.getLatime() << ": " << endl;
    cout << "Aria: " << d1.aria() << endl;
    cout << "Perimetrul: " << d1.perimetru() << endl;
    cout << endl;

    return 0;
}
