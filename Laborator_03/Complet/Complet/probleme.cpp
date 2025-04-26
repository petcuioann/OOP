#include "probleme.h"
#include "utils.h"
#include <set>
#include <cmath>

int* problema1(int* x, int n, int& lungime) {
    int maxStart = 0, maxLen = 1, currStart = 0, currLen = 1;
    for (int i = 1; i < n; ++i) {
        if (x[i] > x[i - 1]) currLen++;
        else {
            if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
            currStart = i, currLen = 1;
        }
    }
    if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema2(int* x, int n, int& lungime) {
    int maxStart = 0, maxLen = 0;
    for (int i = 0; i < n; ++i) {
        std::set<int> s;
        int j = i;
        while (j < n && s.size() <= 3) {
            s.insert(x[j]);
            if (s.size() > 3) break;
            j++;
        }
        if (j - i > maxLen) maxStart = i, maxLen = j - i;
    }
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema3(int* x, int n, int& lungime) {
    int maxStart = 0, maxLen = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n && estePrim(x[j])) j++;
        if (j - i > maxLen) maxStart = i, maxLen = j - i;
        i = j - 1; // Mergem la indexul final al secventei
    }
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema4(int* x, int n, int& lungime) {
    int maxStart = 0, maxLen = 0;
    for (int i = 0; i < n; ++i) {
        std::set<int> s;
        int j = i;
        while (j < n && !s.count(x[j])) {
            s.insert(x[j]);
            j++;
        }
        if (j - i > maxLen) maxStart = i, maxLen = j - i;
    }
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema5(int* x, int n, int& lungime) {
    int maxStart = 0, maxLen = 1, currStart = 0, currLen = 1;
    for (int i = 1; i < n; ++i) {
        if (estePrim(abs(x[i] - x[i - 1]))) currLen++;
        else {
            if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
            currStart = i, currLen = 1;
        }
    }
    if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema6(int* x, int n, int& lungime, int a, int b) {
    int maxStart = 0, maxLen = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n && x[j] >= a && x[j] <= b) j++;
        if (j - i > maxLen) maxStart = i, maxLen = j - i;
        i = j - 1; // Mergem la indexul final al secventei
    }
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema7(int* x, int n, int& lungime) {
    int maxStart = 0, maxLen = 1, currStart = 0, currLen = 1;
    for (int i = 1; i < n; ++i) {
        int d1 = x[i - 1] - (i >= 2 ? x[i - 2] : x[i - 1]);
        int d2 = x[i] - x[i - 1];
        if (semneOpuse(d1, d2)) currLen++;
        else {
            if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
            currStart = i - 1, currLen = 2;
        }
    }
    if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema8(int* x, int n, int& lungime) {
    int maxStart = 0, maxLen = 1, currStart = 0, currLen = 1;
    for (int i = 1; i < n; ++i) {
        if (semneOpuse(x[i], x[i - 1])) currLen++;
        else {
            if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
            currStart = i, currLen = 1;
        }
    }
    if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema9(int* x, int n, int& lungime, int sumaDorita) {
    int maxStart = 0, maxLen = 0;
    for (int i = 0; i < n; ++i) {
        int suma = 0;
        for (int j = i; j < n; ++j) {
            suma += x[j];
            if (suma == sumaDorita && j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                maxStart = i;
            }
        }
    }
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema10(int* x, int n, int& lungime) {
    int maxStart = 0, maxLen = 1, currStart = 0, currLen = 1;
    for (int i = 1; i < n; ++i) {
        if (areCifreComune(x[i], x[i - 1])) currLen++;
        else {
            if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
            currStart = i, currLen = 1;
        }
    }
    if (currLen > maxLen) maxStart = currStart, maxLen = currLen;
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}

int* problema11(int* x, int n, int& lungime) {
    int maxLen = 0, maxStart = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j + 1 < n && x[j + 1] > x[j]) j++;
        int peak = j;
        while (j + 1 < n && x[j + 1] < x[j]) j++;
        if (peak > i && j > peak && j - i + 1 > maxLen) {
            maxLen = j - i + 1;
            maxStart = i;
        }
    }
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i) rez[i] = x[maxStart + i];
    return rez;
}
