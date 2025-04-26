#include <iostream>
using namespace std;

int parteaIntreaga(double x) {
    int i = 0;

    if (x >= 0) {
        while (i <= x) {
            i++;
        }
        return i - 1;
    }
    else {
        while (i > x) {
            i--;
        }
        return i;
    }
}

int main() {
    double x;
    cout << "Introduceti un numar real: ";
    cin >> x;

    int rezultat = parteaIntreaga(x);
    cout << "Partea intreaga a lui " << x << " este: " << rezultat << endl;

    return 0;
}
