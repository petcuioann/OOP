#include <iostream>
using namespace std;

// Calculeaza factorial iterativ (pentru valori relativ mici)
long long factorial(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

// Suma finita: de la i = 1 la n
double sumaFinita(int n, double x) {
    double suma = 0;

    for (int i = 1; i <= n; i++) {
        int putere = 2 * i;
        long long fact = factorial(putere);
        double termen = pow(x, putere) / fact;

        if (i % 2 == 1) termen *= -1;

        suma += termen;
    }

    return suma;
}

// Suma infinita: calcul aproximativ cu eroare < ε
double sumaInfinita(double x, double epsilon) {
    double suma = 0;
    double termen;
    int i = 1;

    do {
        int putere = 2 * i;
        long long fact = factorial(putere);
        termen = pow(x, putere) / fact;
        if (i % 2 == 1) termen *= -1;
        suma += termen;
        i++;
    } while (fabs(termen) >= epsilon);

    return suma;
}

int main() {
    int n;
    double x, epsilon;

    cout << "Introduceti un numar natural n: ";
    cin >> n;
    cout << "Introduceti x ∈ (0, 1): ";
    cin >> x;
    cout << "Introduceti epsilon > 0: ";
    cin >> epsilon;

    if (x <= 0 || x >= 1 || epsilon <= 0 || n < 1) {
        cout << "Date invalide!" << endl;
        return 1;
    }

    double sFinita = sumaFinita(n, x);
    double sInfinita = sumaInfinita(x, epsilon);

    cout << "\nSuma finita Sn = ";
    cout << sFinita << endl;

    cout << "Suma infinita (cu precizie epsilon) = ";
    cout << sInfinita << endl;

    return 0;
}
