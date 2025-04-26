#include "Tests.h"
#include "Produs.h"
#include "Repo.h"
#include <cassert>
#include <iostream>

void testProdus() {
    Produs p1("A1", "Croissant", 5.5);
    assert(p1.getCod() == "A1");
    assert(p1.getNume() == "Croissant");
    assert(p1.getPret() == 5.5);

    p1.setCod("B2");
    p1.setNume("Ciocolata");
    p1.setPret(6.0);

    assert(p1.getCod() == "B2");
    assert(p1.getNume() == "Ciocolata");
    assert(p1.getPret() == 6.0);

    Produs p2 = p1;
    assert(p2 == p1);
}

void testRepo() {
    Repo repo;
    assert(repo.size() == 0);

    Produs p1("C1", "Apa", 3.0);
    Produs p2("D2", "Suc", 4.5);
    repo.addItem(p1);
    repo.addItem(p2);

    assert(repo.size() == 2);

    std::vector<Produs> all = repo.getAll();
    assert(all[0] == p1);
    assert(all[1] == p2);
}

void runAllTests() {
    testProdus();
    testRepo();
    std::cout << "Toate testele au trecut cu succes!\n";
}
