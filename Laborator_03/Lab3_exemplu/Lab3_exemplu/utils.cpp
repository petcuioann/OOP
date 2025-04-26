#include <iostream>
#include "utils.h"

using namespace std;

void citireVector(int*& x, int& n) {
    cout << "Introduceti numarul de elemente: ";
    cin >> n;
    x = new int[n];
    cout << "Introduceti elementele:\n";
    for (int i = 0; i < n; ++i)
        cin >> x[i];
}

void afisareVector(int* x, int n) {
    if (!x || n == 0) {
        cout << "Vectorul este gol.\n";
        return;
    }
    cout << "Vectorul: ";
    for (int i = 0; i < n; ++i)
        cout << x[i] << " ";
    cout << "\n";
}
