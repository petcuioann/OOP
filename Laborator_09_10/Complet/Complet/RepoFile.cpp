#include "RepoFile.h"
#include <fstream>
#include <sstream>

RepoFile::RepoFile(const std::string& fileName) : fileName(fileName) {
    loadFromFile();
}

void RepoFile::loadFromFile() {
    this->produse.clear();
    std::ifstream fin(fileName);
    std::string linie;
    while (getline(fin, linie)) {
        std::stringstream ss(linie);
        std::string cod, nume;
        double pret;
        ss >> cod >> nume >> pret;
        this->produse.push_back(Produs(cod, nume, pret));
    }
    fin.close();
}

void RepoFile::saveToFile() const {
    std::ofstream fout(fileName);
    for (const auto& p : produse) {
        fout << p.getCod() << " " << p.getNume() << " " << p.getPret() << "\n";
    }
    fout.close();
}

void RepoFile::addItem(const Produs& p) {
    Repo::addItem(p);
    saveToFile();
}

bool RepoFile::update(const std::string& cod, const Produs& pNou) {
    bool success = Repo::update(cod, pNou);
    if (success)
        saveToFile();
    return success;
}

bool RepoFile::remove(const std::string& cod) {
    bool success = Repo::remove(cod);
    if (success)
        saveToFile();
    return success;
}
