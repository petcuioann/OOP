#include "utils.h"
#include <cmath>  // pentru fabs() si pow()

bool estePrim(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) return false;
    }
    return true;
}

int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

int invers(int n) {
    int inv = 0;
    while (n > 0) {
        inv = inv * 10 + n % 10;
        n /= 10;
    }
    return inv;
}

int fibonacci(int n) {
    if (n == 0 || n == 1) return 1;
    int f1 = 1, f2 = 1;
    for (int i = 2; i <= n; i++) {
        int next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
    return f2;
}

// verifică dacă două numere au aceleași cifre (ex: 123, 321, 231)
bool auAcelasiSetDeCifre(int a, int b) {
    int f1[10] = { 0 }, f2[10] = { 0 };
    while (a > 0) {
        f1[a % 10]++;
        a /= 10;
    }
    while (b > 0) {
        f2[b % 10]++;
        b /= 10;
    }
    for (int i = 0; i < 10; i++)
        if (f1[i] != f2[i]) return false;
    return true;
}

// functie pentru inmultirea rusa
int inmultireRusa(int a, int b) {
    int produs = 0;

    while (a > 0) {
        if (a % 2 == 1) {
            produs += b;
        }
        a /= 2;
        b *= 2;
    }

    return produs;
}

// functie pentru a calcula partea intreaga a unui numar real
int parteaIntreaga(double x) {
    return static_cast<int>(x);  // conversie directă la int
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

// (a) x_n = (1 + 1/n)^n
double sir_a(int N, double epsilon) {
    double prev = 0, curr = 0;

    // Calculează termenii și ține minte valoarea ultimului termen
    for (int n = 1; n <= N; n++) {
        curr = pow(1.0 + 1.0 / n, n);
    }

    // Calculează aproximarea limitei cu precizia epsilon
    int n = 1;
    do {
        prev = curr;
        curr = pow(1.0 + 1.0 / n, n);
        n++;
    } while (fabs(curr - prev) >= epsilon);

    return curr; // returnează ultima valoare calculată
}

// (b) x1 = a > 0, x_n = (x_{n-1} + a/x_{n-1}) / 2
double sir_b(int N, double epsilon, double a) {
    double x = a;

    // Calculează termenii secvenței
    for (int i = 1; i <= N; i++) {
        x = (x + a / x) / 2;
    }

    double prev = a, curr = a;
    int n = 1;
    do {
        prev = curr;
        curr = (curr + a / curr) / 2;
        n++;
    } while (fabs(curr - prev) >= epsilon);

    return curr; // returnează ultima valoare calculată
}

// (c) x_n = f_{n+1} / f_n (fibonacci)
double sir_c(int N, double epsilon) {
    long long f1 = 1, f2 = 1;
    double prev = 0, curr = 0;

    // Calculează termenii secvenței
    for (int i = 1; i <= N; i++) {
        long long next = f1 + f2;
        curr = (double)f2 / f1;
        f1 = f2;
        f2 = next;
    }

    // Calculează aproximarea limitei cu precizia epsilon
    f1 = 1; f2 = 1;
    int n = 1;
    do {
        long long next = f1 + f2;
        prev = curr;
        curr = (double)f2 / f1;
        f1 = f2;
        f2 = next;
        n++;
    } while (fabs(curr - prev) >= epsilon);

    return curr; // returnează ultima valoare calculată
}