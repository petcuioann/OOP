#include <iostream>
using namespace std;

int inmultireRusa(int a, int b) {
    int produs = 0;

    while (a > 0) {
        if (a % 2 == 1) {
            produs += b;
        }
        a /= 2;
        b *= 2;
    }

    return produs;
}

int main() {
    int a, b;
    cout << "Introduceti doua numere naturale:\n";
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    if (a < 0 || b < 0) {
        cout << "Numerele trebuie sa fie naturale (>= 0)." << endl;
        return 1;
    }

    int rezultat = inmultireRusa(a, b);
    cout << "Produsul lui " << a << " * " << b << " (prin metoda rusa) este: " << rezultat << endl;

    return 0;
}
