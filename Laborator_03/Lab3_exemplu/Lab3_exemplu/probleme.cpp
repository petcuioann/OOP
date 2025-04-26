#include "probleme.h"

int* ceaMaiLungaSecventaCrescatoare(int* x, int n, int& lungime) {
    int maxStart = 0, maxLen = 0;
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && x[j - 1] < x[j]) j++;
        if (j - i > maxLen) {
            maxLen = j - i;
            maxStart = i;
        }
        i = j;
    }
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i)
        rez[i] = x[maxStart + i];
    return rez;
}

int* ceaMaiLungaSecventaInInterval(int* x, int n, int a, int b, int& lungime) {
    int maxStart = 0, maxLen = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && x[j] >= a && x[j] <= b) j++;
        if (j - i > maxLen) {
            maxLen = j - i;
            maxStart = i;
        }
        i = (j == i) ? j + 1 : j;  // evitam bucla infinita
    }
    lungime = maxLen;
    int* rez = new int[lungime];
    for (int i = 0; i < lungime; ++i)
        rez[i] = x[maxStart + i];
    return rez;
}
