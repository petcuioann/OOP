#include "probleme.h"
#include "utils.h"

void citire(int& n, int x[]) {
    cout << "Introduceti numarul de elemente: ";
    cin >> n;
    cout << "Introduceti elementele: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
}

void afisareSecventaMaxima(int x[], int start, int end) {
    cout << "Cea mai lunga secventa care respecta proprietatea este: ";
    for (int i = start; i <= end; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void Problema1(int n, int x[]) {
    cout << "Verificam daca secventa este strict crescatoare...\n";

    int maxStart = 0, maxLen = 1, curStart = 0, curLen = 1;

    for (int i = 1; i < n; i++) {
        if (x[i] > x[i - 1]) {
            curLen++;
        }
        else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema2(int n, int x[]) {
    cout << "Verificam daca secventa are cel mult 3 valori distincte...\n";

    int maxStart = 0, maxLen = 0, curStart = 0, curLen = 0, distincte[3] = { 0 }, nr_distincte = 0;

    for (int i = 0; i < n; i++) {
        bool gasit = false;
        for (int j = 0; j < nr_distincte; j++) {
            if (x[i] == distincte[j]) {
                gasit = true;
                break;
            }
        }
        if (!gasit) {
            if (nr_distincte < 3) {
                distincte[nr_distincte++] = x[i];
            }
            else {
                if (curLen > maxLen) {
                    maxLen = curLen;
                    maxStart = curStart;
                }
                curStart = i;
                curLen = 1;
                distincte[0] = x[i];
                nr_distincte = 1;
            }
        }
        else {
            curLen++;
        }
    }

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema3(int n, int x[]) {
    cout << "Verificam daca secventa contine doar numere prime...\n";

    int maxStart = 0, maxLen = 0, curStart = -1, curLen = 0;

    for (int i = 0; i < n; i++) {
        if (estePrim(x[i])) {
            if (curLen == 0) curStart = i;
            curLen++;
        }
        else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curLen = 0;
        }
    }

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema4(int n, int x[]) {
    cout << "Verificam daca secventa contine doar numere distincte...\n";

    int maxStart = 0, maxLen = 0, curStart = 0, curLen = 1;

    for (int i = 1; i < n; i++) {
        bool distinct = true;
        for (int j = curStart; j < i; j++) {
            if (x[i] == x[j]) {
                distinct = false;
                break;
            }
        }

        if (distinct) {
            curLen++;
        }
        else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema5(int n, int x[]) {
    cout << "Verificam daca diferentele dintre elemente consecutive sunt numere prime...\n";

    int maxStart = 0, maxLen = 0, curStart = 0, curLen = 1;

    for (int i = 1; i < n; i++) {
        if (estePrim(abs(x[i] - x[i - 1]))) {
            curLen++;
        }
        else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema6(int n, int x[]) {
    int a, b;
    cout << "Introduceti intervalul [a, b]: "; cin >> a >> b;
	cout << "Verificam daca toate elementele sunt in intervalul [" << a << ", " << b << "]\n";

    int maxStart = 0, maxLen = 0, curStart = 0, curLen = 0;

    for (int i = 0; i < n; i++) {
        if (x[i] >= a && x[i] <= b) {
            if (curLen == 0) curStart = i;
            curLen++;
        }
        else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curLen = 0;
        }
    }

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema7(int n, int x[]) {
    cout << "Verificam daca diferentele dintre elementele consecutive au semne contrare...\n";

    int maxStart = 0, maxLen = 0, curStart = 0, curLen = 1;

    for (int i = 1; i < n; i++) {
        if ((x[i] - x[i - 1]) * (x[i - 1] - x[i - 2]) < 0) {
            curLen++;
        }
        else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema8(int n, int x[]) {
    cout << "Verificam daca elementele de pe pozitii consecutive au semne contrare...\n";

    int maxStart = 0, maxLen = 0, curStart = 0, curLen = 1;

    for (int i = 1; i < n; i++) {
        if ((x[i] > 0 && x[i - 1] < 0) || (x[i] < 0 && x[i - 1] > 0)) {
            curLen++;
        }
        else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema9(int n, int x[]) {
    int suma;
    cout << "Verificam daca suma elementelor este egala cu (introduceti suma) ..."; cin >> suma;

    int maxStart = 0, maxLen = 0, curStart = 0, curLen = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += x[i];
        curLen++;

        if (sum > suma) {
            sum = x[i];
            curLen = 1;
            curStart = i;
        }
        else if (sum == suma) {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
        }
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema10(int n, int x[]) {
    cout << "Verificam daca elementele consecutive au cel putin 2 cifre comune...\n";

    int maxStart = 0, maxLen = 0, curStart = 0, curLen = 1;

    for (int i = 1; i < n; i++) {
        if (auCifreComune(x[i], x[i - 1])) {
            curLen++;
        }
        else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}

void Problema11(int n, int x[]) {
    cout << "Verificam daca secventa este in forma de munte...\n";

    int maxStart = 0, maxLen = 0, curStart = 0, curLen = 0, i = 0;

    while (i < n - 1 && x[i] < x[i + 1]) {
        curLen++;
        i++;
    }

    if (i == 0 || i == n - 1) {
        cout << "Secventa nu respecta conditia de munte.\n";
        return;
    }

    while (i < n - 1 && x[i] > x[i + 1]) {
        curLen++;
        i++;
    }

    if (i == n - 1 && curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    afisareSecventaMaxima(x, maxStart, maxStart + maxLen - 1);
}


