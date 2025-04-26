#include <iostream>
#include <cmath>
using namespace std;

// (a) x_n = (1 + 1/n)^n
void sir_a(int N, double epsilon) {
    cout << "\n(a) x_n = (1 + 1/n)^n" << endl;
    double prev = 0, curr = 0;
    for (int n = 1; n <= N; n++) {
        curr = pow(1.0 + 1.0 / n, n);
        cout << "x_" << n << " = " << curr << endl;
    }

    int n = 1;
    do {
        prev = curr;
        curr = pow(1.0 + 1.0 / n, n);
        n++;
    } while (fabs(curr - prev) >= epsilon);

    cout << "Aproximare limita (epsilon=" << epsilon << "): " << curr << " (la n=" << n << ")\n";
}

// (b) x1 = a > 0, x_n = (x_{n-1} + a/x_{n-1}) / 2
void sir_b(int N, double epsilon, double a) {
    cout << "\n(b) x_1 = a > 0, x_n = (x_{n-1} + a/x_{n-1}) / 2" << endl;
    double x = a;

    for (int i = 1; i <= N; i++) {
        cout << "x_" << i << " = " << x << endl;
        x = (x + a / x) / 2;
    }

    double prev, curr = a;
    int n = 1;
    do {
        prev = curr;
        curr = (curr + a / curr) / 2;
        n++;
    } while (fabs(curr - prev) >= epsilon);

    cout << "Aproximare limita (epsilon=" << epsilon << "): " << curr << " (la n=" << n << ")\n";
}

// (c) x_n = f_{n+1} / f_n (fibonacci)
void sir_c(int N, double epsilon) {
    cout << "\n(c) x_n = f_{n+1} / f_n (fibonacci)" << endl;
    long long f1 = 1, f2 = 1;
    double prev = 0, curr = 0;

    for (int i = 1; i <= N; i++) {
        long long next = f1 + f2;
        curr = (double)f2 / f1;
        cout << "x_" << i << " = " << curr << endl;
        f1 = f2;
        f2 = next;
    }

    // reset for epsilon
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

    cout << "Aproximare limita (epsilon=" << epsilon << "): " << curr << " (la n=" << n << ")\n";
}

int main() {
    int N;
    double epsilon, a;

    cout << "Introduceti numarul de termeni N: ";
    cin >> N;

    cout << "Introduceti precizia epsilon (>0): ";
    cin >> epsilon;

    cout << "Introduceti a > 0 pentru sirul (b): ";
    cin >> a;

    if (N <= 0 || epsilon <= 0 || a <= 0) {
        cout << "Valori invalide!" << endl;
        return 1;
    }

    sir_a(N, epsilon);
    sir_b(N, epsilon, a);
    sir_c(N, epsilon);

    return 0;
}
