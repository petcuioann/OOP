#include <iostream>
using namespace std;

// Găsește primul termen din șirul lui Fibonacci strict mai mare decât n
int fibonacciMaiMareDecat(int n) {
    int a = 1, b = 1;

    while (b <= n) {
        int next = a + b;
        a = b;
        b = next;
    }

    return b;
}

int main() {
    int n;
    cout << "Introduceti un numar natural: ";
    cin >> n;

    if (n < 0) {
        cout << "Numarul trebuie sa fie natural (>= 0)." << endl;
        return 1;
    }

    int rezultat = fibonacciMaiMareDecat(n);
    cout << "Cel mai mic numar din sirul lui Fibonacci mai mare decat " << n << " este: " << rezultat << endl;

    return 0;
}
