#include <cassert>
#include <iostream>
#include <cstring>
#include "Cheltuiala.h"
#include "Repository.h"
#include "CheltuialaService.h"

// ENTITATE
void testConstructori() {
    Cheltuiala c(1, 100, "mancare");
    assert(c.getZi() == 1);
    assert(strcmp(c.getTip(), "mancare") == 0);
}

void testSetteri() {
    Cheltuiala c;
    c.setZi(10); c.setSuma(50); c.setTip("internet");
    assert(c.getZi() == 10);
    assert(strcmp(c.getTip(), "internet") == 0);
}

void testCopiere() {
    Cheltuiala a(5, 200, "gaz");
    Cheltuiala b = a;
    assert(strcmp(a.getTip(), b.getTip()) == 0);
    b.setTip("electricitate");
    assert(strcmp(a.getTip(), "gaz") == 0);
}

void testOperatorEgal() {
    Cheltuiala a(3, 99, "apa"), b;
    b = a;
    assert(strcmp(b.getTip(), "apa") == 0);
}

void runAllEntityTests() {
    testConstructori();
    testSetteri();
    testCopiere();
    testOperatorEgal();
    std::cout << "Testele pentru entitate au trecut cu succes.\n";
}

// REPO TEMPLATE
void testRepoTemplate() {
    Repository<Cheltuiala> repo;
    Cheltuiala c1(1, 50, "apa");
    Cheltuiala c2(2, 100, "gaz");
    repo.add(c1); repo.add(c2);
    assert(repo.getSize() == 2);
    assert(repo.get(1).getSuma() == 100);
}

void testUndo() {
    Repository<Cheltuiala> repo;
    CheltuialaService s(repo);
    s.add(1, 100, "apa");
    s.add(2, 200, "gaz");
    s.undo(); assert(s.getSize() == 1);
    s.undo(); assert(s.getSize() == 0);
    assert(!s.undo());
}

void runAllTemplateRepoTests() {
    testRepoTemplate();
    testUndo();
    std::cout << "Testele pentru repo templetizat + undo au trecut cu succes.\n";
}
