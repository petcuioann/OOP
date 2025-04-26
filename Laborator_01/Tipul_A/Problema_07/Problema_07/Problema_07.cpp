#include <iostream>
using namespace std;

// Calculează produsul factorilor proprii ai lui n
int produsFactoriProprii(int n) {
    int produs = 1;
    bool areFactori = false;

    for (int d = 1; d < n; d++) {
        if (n % d == 0) {
            produs *= d;
            areFactori = true;
        }
    }

    return areFactori ? produs : 0;
}

int main() {
    int n;
    cout << "Introduceti un numar natural: ";
    cin >> n;

    if (n <= 1) {
        cout << "Numarul " << n << " nu are factori proprii." << endl;
    }
    else {
        int rezultat = produsFactoriProprii(n);
        cout << "Produsul factorilor proprii ai lui " << n << " este: " << rezultat << endl;
    }

    return 0;
}
