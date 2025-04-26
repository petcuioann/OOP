#include "TestsRepoFile.h"
#include "RepoFile.h"
#include <cassert>
#include <fstream>

void testRepoFile() {
    const std::string filename = "test_file.txt";

    // Scriem manual produse inițiale
    std::ofstream fout(filename);
    fout << "C1 Cola 5.0\n";
    fout << "C2 Fanta 4.5\n";
    fout.close();

    RepoFile repoFile(filename);
    assert(repoFile.size() == 2);

    Produs p("C3", "Sprite", 4.0);
    repoFile.addItem(p);
    assert(repoFile.size() == 3);

    assert(repoFile.remove("C1") == true);
    assert(repoFile.update("C2", Produs("C2", "FantaZero", 4.7)) == true);

    // Reload pentru verificare persistenta
    RepoFile reloadRepo(filename);
    assert(reloadRepo.size() == 2);
    Produs p2 = reloadRepo.getByCod("C2");
    assert(p2.getNume() == "FantaZero");
    assert(p2.getPret() == 4.7);
}
