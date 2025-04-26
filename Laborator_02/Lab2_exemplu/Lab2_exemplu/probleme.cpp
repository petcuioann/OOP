#include <iostream>
#include "probleme.h"
#include "utils.h"

using namespace std;

void citire(int x[], int& n) {
    cout << "Cate elemente? ";
    cin >> n;
    cout << "Introduceti " << n << " numere:\n";
    for (int i = 0; i < n; ++i) cin >> x[i];
}

void afisare(int x[], int n) {
    cout << "Lista: ";
    for (int i = 0; i < n; ++i) cout << x[i] << " ";
    cout << endl;
}

void secventaCrescatoare(int x[], int n) {
    int maxStart = 0, maxLen = 1, start = 0, len = 1;

    for (int i = 1; i < n; ++i) {
        if (x[i] > x[i - 1]) {
            len++;
        }
        else {
            if (len > maxLen) {
                maxLen = len;
                maxStart = start;
            }
            start = i;
            len = 1;
        }
    }
    if (len > maxLen) {
        maxLen = len;
        maxStart = start;
    }

    cout << "Cea mai lunga secventa strict crescatoare: ";
    for (int i = maxStart; i < maxStart + maxLen; ++i) cout << x[i] << " ";
    cout << endl;
}

void secventaPrime(int x[], int n) {
    int maxStart = 0, maxLen = 0, start = 0;

    while (start < n) {
        if (!estePrim(x[start])) {
            start++;
            continue;
        }

        int i = start;
        while (i < n && estePrim(x[i])) i++;

        int len = i - start;
        if (len > maxLen) {
            maxLen = len;
            maxStart = start;
        }
        start = i;
    }

    cout << "Cea mai lunga secventa de numere prime: ";
    for (int i = maxStart; i < maxStart + maxLen; ++i) cout << x[i] << " ";
    cout << endl;
}
