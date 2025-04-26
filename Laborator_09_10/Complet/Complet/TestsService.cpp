#include "TestsService.h"
#include "Service.h"
#include "Repo.h"
#include <cassert>
#include <iostream>

void testCumparaProdus() {
    Repo r;
    Service s(r);
    s.addProdus("A1", "Baton", 3.99);
    s.setMonedeDisponibile({ {500, 1}, {100, 2}, {1, 1} });
    std::map<int, int> rest = s.cumparaProdus("A1", 10.0);
    assert(rest[500] == 1);
    assert(rest[100] == 1);  // <- fix corect
    assert(rest[1] == 1);
    std::cout << "testCumparaProdus passed.\n";
}

void testCumparaCuRestImposibil() {
    Repo r;
    Service s(r);
    s.addProdus("P1", "Suc", 2.00);
    s.setMonedeDisponibile({ {100, 0}, {50, 0}, {10, 0}, {1, 0} });
    try {
        s.cumparaProdus("P1", 5.00);
        assert(false);
    }
    catch (const std::exception& e) {
        assert(std::string(e.what()) == "Nu se poate oferi restul in monedele disponibile.");
        std::cout << "testCumparaCuRestImposibil passed.\n";
    }
}

void testCumparaFonduriInsuficiente() {
    Repo r;
    Service s(r);
    s.addProdus("X", "Chips", 6.50);
    s.setMonedeDisponibile({ {100, 10} });
    try {
        s.cumparaProdus("X", 5.00);
        assert(false);
    }
    catch (const std::exception& e) {
        assert(std::string(e.what()) == "Fonduri insuficiente pentru achizitie!");
        std::cout << "testCumparaFonduriInsuficiente passed.\n";
    }
}

void testCumparaProdusInexistent() {
    Repo r;
    Service s(r);
    try {
        s.cumparaProdus("NOPE", 10);
        assert(false);
    }
    catch (const std::exception& e) {
        assert(std::string(e.what()) == "Produsul nu exista!");
        std::cout << "testCumparaProdusInexistent passed.\n";
    }
}
