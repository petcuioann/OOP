#ifndef REPOFILE_H
#define REPOFILE_H

#include "Repo.h"
#include <string>

class RepoFile : public Repo {
private:
    std::string fileName;

public:
    RepoFile(const std::string& fileName);

    // Suprascrieri CRUD cu salvare automată
    void addItem(const Produs& p) override;
    bool update(const std::string& cod, const Produs& pNou) override;
    bool remove(const std::string& cod) override;

    // Operatii fișier
    void loadFromFile();
    void saveToFile() const;
};

#endif // REPOFILE_H
