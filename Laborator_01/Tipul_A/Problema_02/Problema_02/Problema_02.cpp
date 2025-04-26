#include <iostream>
using namespace std;

// Sortează crescător (bubble sort)
void sorteazaCrescator(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

// Construieste cel mai mic numar din cifrele lui n
int numarMinimDinCifre(int n) {
    int cifre[10], k = 0;

    if (n == 0) return 0;

    // Extragem cifrele
    while (n > 0) {
        cifre[k++] = n % 10;
        n /= 10;
    }

    // Sortam crescator
    sorteazaCrescator(cifre, k);

    // Evitam 0 la inceput: mutam prima cifra nenula pe pozitia 0
    if (cifre[0] == 0) {
        for (int i = 1; i < k; i++) {
            if (cifre[i] != 0) {
                int aux = cifre[0];
                cifre[0] = cifre[i];
                cifre[i] = aux;
                break;
            }
        }
    }

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
        cout << "Numarul trebuie sa fie >= 0." << endl;
        return 1;
    }

    int rezultat = numarMinimDinCifre(n);
    cout << "Cel mai mic numar format din aceleasi cifre este: " << rezultat << endl;

    return 0;
}
