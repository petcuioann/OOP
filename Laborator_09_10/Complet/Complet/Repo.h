#ifndef REPO_H
#define REPO_H

#include "Produs.h"
#include <vector>
#include <string>

class Repo {
protected:
    std::vector<Produs> produse;

public:
    Repo() = default;
    virtual ~Repo() = default;  // Destructor virtual

    virtual void addItem(const Produs& p);
    virtual bool update(const std::string& cod, const Produs& pNou);
    virtual bool remove(const std::string& cod);

    std::vector<Produs> getAll() const;
    int size() const;
    Produs getByCod(const std::string& cod) const;
    int find(const std::string& cod) const;
    bool exists(const std::string& cod) const;
};

#endif // REPO_H
