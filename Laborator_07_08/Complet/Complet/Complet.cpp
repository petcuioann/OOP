#include "CheltuialaService.h"
#include "UI.h"

int main() {
    Repository<Cheltuiala> repoCheltuieli;
	Repository<Tranzactie> repoTranzactii;
	Repository<CheltuialaApartament> repoApartamente;
    CheltuialaService cheltuialaService(repoCheltuieli);
	TranzactieService tranzactieService(repoTranzactii);
	CheltuialaApartamentService cheltuialaApartamentService(repoApartamente);
    UI ui(cheltuialaService, tranzactieService, cheltuialaApartamentService);
    ui.start();

    return 0;
}
