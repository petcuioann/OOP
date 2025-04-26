#include "RepoFile.h"
#include "Service.h"
#include "UI.h"

int main() {
    RepoFile repoFile("produse.txt");  // fișierul cu produse
    Service service(repoFile);         // service legat de repo-ul pe fișier
    UI ui(service);                    // UI legat de service
    ui.start();
    return 0;
}
