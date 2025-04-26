#include "utils.h"
#include <cmath>
#include <unordered_set>

bool estePrim(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

bool haveCommonDigits(int a, int b) {
    std::unordered_set<int> digitsA;
    a = std::abs(a);
    b = std::abs(b);
    while (a > 0) {
        digitsA.insert(a % 10);
        a /= 10;
    }
    while (b > 0) {
        if (digitsA.find(b % 10) != digitsA.end()) {
            return true;
        }
        b /= 10;
    }
    return false;
}

bool areCifreComune(int a, int b) {
    // Wrapper pentru nume clar în limba română
    return haveCommonDigits(a, b);
}

bool semneOpuse(int a, int b) {
    return (a < 0 && b > 0) || (a > 0 && b < 0);
}

bool auSemneConsecutive(int a, int b) {
    // Adică diferențele au semne opuse, folosit la problema 7
    return semneOpuse(a - b, b - a);
}
