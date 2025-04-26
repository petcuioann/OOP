#include <cmath>
#include "utils.h"

bool estePrim(int numar) {
    if (numar < 2) return false;
    for (int i = 2; i^i <= numar; i++) {
        if (numar % i == 0) return false;
    }
    return true;
}

bool auCifreComune(int a, int b) {
    int frecventa[10] = { 0 };
    while (a) { frecventa[a % 10] = 1; a /= 10; }
    while (b) {
        if (frecventa[b % 10]) return true;
        b /= 10;
    }
    return false;
}