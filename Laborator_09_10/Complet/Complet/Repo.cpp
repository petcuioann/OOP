#include "Repo.h"

void Repo::addItem(const Produs& p) {
    produse.push_back(p);
}

std::vector<Produs> Repo::getAll() const {
    return produse;
}

int Repo::size() const {
    return produse.size();
}

bool Repo::update(const std::string& cod, const Produs& pNou) {
    for (auto& p : produse) {
        if (p.getCod() == cod) {
            p = pNou;
            return true;
        }
    }
    return false;
}

bool Repo::remove(const std::string& cod) {
    for (auto it = produse.begin(); it != produse.end(); ++it) {
        if (it->getCod() == cod) {
            produse.erase(it);
            return true;
        }
    }
    return false;
}

Produs Repo::getByCod(const std::string& cod) const {
    for (const auto& p : produse) {
        if (p.getCod() == cod)
            return p;
    }
    return Produs(); // implicit
}

int Repo::find(const std::string& cod) const {
    for (int i = 0; i < produse.size(); ++i) {
        if (produse[i].getCod() == cod)
            return i;
    }
    return -1;
}

bool Repo::exists(const std::string& cod) const {
    return find(cod) != -1;
}
