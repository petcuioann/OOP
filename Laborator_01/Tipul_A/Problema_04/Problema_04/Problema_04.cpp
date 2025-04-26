#include <iostream>
using namespace std;

// Verifică dacă un număr este prim
bool estePrim(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    }
    return true;
}

// Găsește cel mai mare prim mai mic decât n
int celMaiMarePrimSub(int n) {
    for (int x = n - 1; x >= 2; x--) {
        if (estePrim(x)) return x;
    }
    return -1; // nu există
}

int main() {
    int n;
    cout << "Introduceti un numar natural: ";
    cin >> n;

    int rezultat = celMaiMarePrimSub(n);

    if (rezultat == -1) {
        cout << "Nu exista niciun numar prim mai mic decat " << n << "." << endl;
    }
    else {
        cout << "Cel mai mare numar prim mai mic decat " << n << " este: " << rezultat << endl;
    }

    return 0;
}
