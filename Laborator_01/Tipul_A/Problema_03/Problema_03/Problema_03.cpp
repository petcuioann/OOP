#include <iostream>
using namespace std;

// Bubble sort descrescator
void sorteazaDescrescator(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] < v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

// Construieste numarul maxim cu aceleasi cifre
int numarMaximDinCifre(int n) {
    int cifre[10], k = 0;

    if (n == 0) return 0;

    // Extragem cifrele
    while (n > 0) {
        cifre[k++] = n % 10;
        n /= 10;
    }

    // Sortam descrescator
    sorteazaDescrescator(cifre, k);

    // Reconstruim numarul
    int rezultat = 0;
    for (int i = 0; i < k; i++) {
        rezultat = rezultat * 10 + cifre[i];
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

    int rezultat = numarMaximDinCifre(n);
    cout << "Cel mai mare numar format din aceleasi cifre este: " << rezultat << endl;

    return 0;
}
