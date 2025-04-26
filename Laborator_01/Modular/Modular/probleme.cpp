#include <iostream>
#include <cmath>
#include "utils.h"
#include "probleme.h"

using namespace std;

// ======================== PROBLEME A ========================

void ProblemaA1() {
    cout << "[A1] n = p1 + p2, unde p1 si p2 sunt prime.\n";
    int n;
    cout << "Introduceti n: ";
    cin >> n;

    for (int p1 = 2; p1 <= n / 2; p1++) {
        int p2 = n - p1;
        if (estePrim(p1) && estePrim(p2)) {
            cout << "Solutie: " << p1 << " + " << p2 << " = " << n << endl;
            return;
        }
    }
    cout << "Nu exista doua numere prime care sa satisfaca conditia.\n";
}

void ProblemaA2() {
    cout << "[A2] Cel mai mic numar cu aceleasi cifre ca n.\n";
    int n;
    cout << "Introduceti n: ";
    cin >> n;

    int f[10] = {};
    int copie = n;
    while (copie) {
        f[copie % 10]++;
        copie /= 10;
    }

    // gasim prima cifra nenula pentru inceputul numarului
    int rezultat = 0;
    for (int i = 1; i < 10; i++) {
        if (f[i]) {
            rezultat = i;
            f[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        while (f[i]--) rezultat = rezultat * 10 + i;
    }

    cout << "Numarul minim format este: " << rezultat << endl;
}

void ProblemaA3() {
    cout << "[A3] Cel mai mare numar cu aceleasi cifre ca n.\n";
    int n;
    cout << "Introduceti n: ";
    cin >> n;

    int f[10] = {};
    while (n) {
        f[n % 10]++;
        n /= 10;
    }

    int rezultat = 0;
    for (int i = 9; i >= 0; i--) {
        while (f[i]--) rezultat = rezultat * 10 + i;
    }
    cout << "Numarul maxim format este: " << rezultat << endl;
}

void ProblemaA4() {
    cout << "[A4] Cel mai mare prim mai mic decat n.\n";
    int n;
    cout << "Introduceti n: ";
    cin >> n;

    for (int i = n - 1; i >= 2; i--) {
        if (estePrim(i)) {
            cout << "Rezultat: " << i << endl;
            return;
        }
    }
    cout << "Nu exista numar prim mai mic decat " << n << ".\n";
}

void ProblemaA5() {
    cout << "[A5] Primele doua numere prime gemene > n.\n";
    int n;
    cout << "Introduceti n: ";
    cin >> n;

    int i = n + 1;
    while (true) {
        if (estePrim(i) && estePrim(i + 2)) {
            cout << "Gemene: " << i << " si " << i + 2 << endl;
            return;
        }
        i++;
    }
}

void ProblemaA6() {
    cout << "[A6] Primul numar Fibonacci > n.\n";
    int n;
    cout << "Introduceti n: ";
    cin >> n;

    int f1 = 1, f2 = 1;
    while (f2 <= n) {
        int next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
    cout << "Rezultat: " << f2 << endl;
}

void ProblemaA7() {
    cout << "[A7] Produsul factorilor proprii ai lui n.\n";
    int n;
    cout << "Introduceti n: ";
    cin >> n;

    int produs = 1;
    bool are = false;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            produs *= i;
            are = true;
        }
    }
    if (are) cout << "Produsul factorilor proprii: " << produs << endl;
    else cout << "Nu exista factori proprii.\n";
}

void ProblemaA8() {
    cout << "[A8] Palindromul lui n.\n";
    int n;
    cout << "Introduceti n: ";
    cin >> n;

    cout << "Palindromul: " << invers(n) << endl;
}
// ======================== PROBLEME B ========================

void ProblemaB1() {
    cout << "[B1] Inmulțirea á la russe a două numere naturale n.\n";
    int a, b;
    cout << "Introduceti doua numere naturale:\n";
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    if (a < 0 || b < 0) {
        cout << "Numerele trebuie sa fie naturale (>= 0)." << endl;
        return;
    }

    int rezultat = inmultireRusa(a, b);
    cout << "Produsul lui " << a << " * " << b << " (prin metoda rusa) este: " << rezultat << endl;

}

void ProblemaB2() {
    cout << "[B2] Functie pentru a calcula partea intreaga a unui numar real.\n";
    double x;
    cout << "Introduceti un numar real: ";
    cin >> x;

    int rezultat = parteaIntreaga(x);
    cout << "Partea intreaga a lui " << x << " este: " << rezultat << endl;
}

void ProblemaB3() {
    cout << "[B3] Calcul unei sume.\n";
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
        return;
    }

    double sFinita = sumaFinita(n, x);
    double sInfinita = sumaInfinita(x, epsilon);

    cout << "\nSuma finita Sn = ";
    cout << sFinita << endl;

    cout << "Suma infinita (cu precizie epsilon) = ";
    cout << sInfinita << endl;
}

void ProblemaB4() {
    cout << "[B4] Ss se afiseze primele N elemente si sa se aproximeze (cu precizia epsilon).\n";

    int N;
    double epsilon, a;

    // Citire date de la utilizator
    cout << "Introduceti numarul de termeni N: ";
    cin >> N;

    cout << "Introduceti precizia epsilon (> 0): ";
    cin >> epsilon;

    cout << "Introduceti valoarea a pentru sirul (b): ";
    cin >> a;

    // Validare intrare
    if (N <= 0 || epsilon <= 0) {
        cout << "Valori invalide! N trebuie sa fie > 0 si epsilon > 0.\n";
        return;
    }

    // Apelarea funcțiilor cu valorile introduse
    double result_a = sir_a(N, epsilon);
    double result_b = sir_b(N, epsilon, a);
    double result_c = sir_c(N, epsilon);

    // Afișarea rezultatelor
    cout << "\nAproximare limita pentru (a): " << result_a << endl;
    cout << "Aproximare limita pentru (b): " << result_b << endl;
    cout << "Aproximare limita pentru (c): " << result_c << endl;
}

