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

// Caută primele două numere prime gemene mai mari decât n
void primeGemene(int n, int& p, int& q) {
    int x = n + 1;
    while (true) {
        if (estePrim(x) && estePrim(x + 2)) {
            p = x;
            q = x + 2;
            return;
        }
        x++;
    }
}

int main() {
    int n;
    cout << "Introduceti un numar natural: ";
    cin >> n;

    if (n < 0) {
        cout << "Numarul trebuie sa fie natural (>= 0)." << endl;
        return 1;
    }

    int p, q;
    primeGemene(n, p, q);
    cout << "Primele doua numere prime gemene mai mari decat " << n << " sunt: "
        << p << " si " << q << endl;

    return 0;
}
