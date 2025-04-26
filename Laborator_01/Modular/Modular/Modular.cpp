#include <iostream>
#include <cctype> // Pentru funcția tolower()
#include "probleme.h"

using namespace std;

void meniu_A() {
    int optiune;
    do {
        cout << "\nMeniu A:\n";
        cout << "1. Problema A1\n";
        cout << "2. Problema A2\n";
        cout << "3. Problema A3\n";
        cout << "4. Problema A4\n";
        cout << "5. Problema A5\n";
        cout << "6. Problema A6\n";
        cout << "7. Problema A7\n";
        cout << "8. Problema A8\n";
        cout << "0. Inapoi la Meniul Principal\n";
        cout << "Alegeti o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1: ProblemaA1(); break;
        case 2: ProblemaA2(); break;
        case 3: ProblemaA3(); break;
        case 4: ProblemaA4(); break;
        case 5: ProblemaA5(); break;
        case 6: ProblemaA6(); break;
        case 7: ProblemaA7(); break;
        case 8: ProblemaA8(); break;
        case 0: break;
        default: cout << "Optiune invalida! Incercati din nou.\n"; break;
        }
    } while (optiune != 0);
}

void meniu_B() {
    int optiune;
    do {
        cout << "\nMeniu B:\n";
        cout << "1. Problema B1\n";
        cout << "2. Problema B2\n";
        cout << "3. Problema B3\n";
        cout << "4. Problema B4\n";
        cout << "0. Inapoi la Meniul Principal\n";
        cout << "Alegeti o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1: ProblemaB1(); break;
        case 2: ProblemaB2(); break;
        case 3: ProblemaB3(); break;
        case 4: ProblemaB4(); break;
        case 0: break;
        default: cout << "Optiune invalida! Incercati din nou.\n"; break;
        }
    } while (optiune != 0);
}

int main() {
    char optiune;
    do {
        cout << "\nMeniu Principal:\n";
        cout << "A. Probleme A\n";
        cout << "B. Probleme B\n";
        cout << "0. Iesire\n";
        cout << "Alegeti o optiune: ";
        cin >> optiune;

        // Convertim optiunea in litera mica folosind tolower()
        optiune = tolower(optiune);

        switch (optiune) {
        case 'a': meniu_A(); break;
        case 'b': meniu_B(); break;
        case '0': cout << "Iesire...\n"; break;
        default: cout << "Optiune invalida! Incercati din nou.\n"; break;
        }
    } while (optiune != '0');

    return 0;
}
