#include <iostream>
using namespace std;

// Verifică dacă un număr este prim
bool isPrime(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    }
    return true;
}

// Caută două numere prime care adunate dau n
void findPrimePair(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            cout << "Numerele sunt: " << i << " + " << (n - i) << " = " << n << endl;
            return;
        }
    }
    cout << "Nu exista doua numere prime care sa dea suma " << n << endl;
}

int main() {
    int n;
    cout << "Introduceti un numar natural n: ";
    cin >> n;

    if (n < 4) {
        cout << "Numarul trebuie sa fie >= 4 pentru a avea o suma de doua numere prime.\n";
    }
    else {
        findPrimePair(n);
    }

    return 0;
}
