#include <iostream>
using namespace std;

void citire(int* x, int n) {
    cout << "Introdu " << n << " numere:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
}

void afisare(int* x, int n) {
    cout << "Elementele sirului: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << "\n";
}
