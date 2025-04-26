#include <iostream>
using namespace std;

// Construieste palindromul (inversul cifrelor)
int palindrom(int n) {
    int rezultat = 0;
    while (n > 0) {
        rezultat = rezultat * 10 + n % 10;
        n /= 10;
    }
    return rezultat;
}

int main() {
    int n;
    cout << "Introduceti un numar natural: ";
    cin >> n;

    if (n < 0) {
        cout << "Numarul trebuie sa fie natural (>= 0)." << endl;
        return 1;
    }

    int rezultat = palindrom(n);
    cout << "Palindromul lui " << n << " este: " << rezultat << endl;

    return 0;
}
