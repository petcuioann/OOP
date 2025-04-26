#include "Tests.h"
#include "CercService.h"
#include <iostream>

using namespace std;

void testAdaugareCerc() {
    Service service;
    service.adaugaCerc(5.0);
    service.adaugaCerc(10.0);

    if (service.getCelMaiMareCerc().getRaza() == 10.0) {
        cout << "Test Adaugare Cerc -> PASSED\n";
    }
    else {
        cout << "Test Adaugare Cerc -> FAILED\n";
    }
}

void testStergereCerc() {
    Service service;
    service.adaugaCerc(5.0);
    service.adaugaCerc(10.0);
    service.stergeCerc(0); // Ștergem primul cerc

    if (service.getCelMaiMareCerc().getRaza() == 10.0) {
        cout << "Test Stergere Cerc -> PASSED\n";
    }
    else {
        cout << "Test Stergere Cerc -> FAILED\n";
    }
}

void testGetCelMaiMareCerc() {
    Service service;
    service.adaugaCerc(3.0);
    service.adaugaCerc(7.0);
    service.adaugaCerc(2.0);

    if (service.getCelMaiMareCerc().getRaza() == 7.0) {
        cout << "Test Get Cel Mai Mare Cerc -> PASSED\n";
    }
    else {
        cout << "Test Get Cel Mai Mare Cerc -> FAILED\n";
    }
}

void testGolireRepository() {
    Service service;
    service.adaugaCerc(4.0);
    service.adaugaCerc(8.0);
    service.golesteRepository();

    try {
        service.getCelMaiMareCerc();
        cout << "Test Golire Repository -> FAILED\n";
    }
    catch (const exception&) {
        cout << "Test Golire Repository -> PASSED\n";
    }
}
