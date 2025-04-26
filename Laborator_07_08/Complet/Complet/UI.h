#ifndef UI_H
#define UI_H

#include "CheltuialaService.h"
#include "TranzactieService.h"
#include "CheltuialaApartamentService.h"

class UI {
private:
    CheltuialaService& cheltuialaService;
    TranzactieService& tranzactieService;
    CheltuialaApartamentService& cheltuialaApartamentService;

public:
    // Constructor
    UI(CheltuialaService& s, TranzactieService& t, CheltuialaApartamentService& u);


    // Meniu principal
    void start();

    // Submeniuri
    void runCheltuieli();       // Submeniu pentru problema 1: Cheltuieli Familie
    void runTranzactii();       // Submeniu pentru problema 2: Gestiune Conturi Bancare
	void runApartamente();      // Submeniu pentru problema 3: Gestiune cheltuieli apartamente

    // ======================= CHELTUIELI ===========================
    void CheltuialaAddUI();                         // 1. Adauga o cheltuiala pentru ziua curenta
    void CheltuialaInsertUI();                      // 2. Insereaza cheltuiala cu zi specificata
    void CheltuialaDeleteUI();                      // 3. Sterge cheltuiala dupa index
    void CheltuialaRemoveByDayUI();                 // 4. Sterge dupa zi
    void CheltuialaRemoveByIntervalUI();            // 5. Sterge pe interval
    void CheltuialaRemoveByTipUI();                 // 6. Sterge dupa tip
    void CheltuialaListUI() const;                  // 7. Afiseaza toate cheltuielile
    void CheltuialaListByTipUI();                   // 8. Afiseaza dupa tip
    void CheltuialaListByTipAndSumUI();             // 9. Afiseaza dupa tip si suma cu comparatie
    void CheltuialaSumByTipUI();                    // 10. Suma cheltuieli pentru un tip
    void CheltuialaZiMaxUI();                       // 11. Ziua cu cele mai mari cheltuieli
    void CheltuialaSortByZiDescUI();                // 12. Sorteaza descrescator dupa zi
    void CheltuialaSortByTipAndSumAscUI();          // 13. Sorteaza crescator dupa suma pentru un tip
    void CheltuialaFilterByTipUI();                 // 14. Filtrare pe tip
    void CheltuialaFilterByTipAndSumUI();           // 15. Filtrare pe tip si suma
    void CheltuialaUndoUI();                        // 16. Undo

    // ======================= TRANZACTII ===========================
    void TranzactieAddUI();                         // 1. Adauga tranzactie pentru ziua curenta
    void TranzactieInsertUI();                      // 2. Insereaza tranzactie pentru o zi specificata
    void TranzactieDeleteZiUI();                    // 3. Sterge toate tranzactiile dintr-o zi
    void TranzactieDeleteIntervalUI();              // 4. Sterge tranzactii dintr-un interval de zile
    void TranzactieDeleteTipUI();                   // 5. Sterge tranzactii dupa tip (in/out)
    void TranzactieUpdateUI();                      // 6. Inlocuieste suma unei tranzactii (dupa zi, tip, descriere)
    void TranzactieListUI();                        // 7. Afiseaza toate tranzactiile
    void TranzactieListByTipUI();                   // 8. Afiseaza tranzactii dupa tip
    void TranzactieListBySumCmpUI();                // 9. Afiseaza tranzactii cu comparatie pe suma (< = >)
    void TranzactieSoldZiUI();                      // 10. Afiseaza soldul (in - out) intr-o zi
    void TranzactieSumaTipUI();                     // 11. Afiseaza suma totala pentru un tip (in/out)
    void TranzactieMaxOutZiUI();                    // 12. Cea mai valoroasa tranzactie out intr-o zi
    void TranzactieFilterTipUI();                   // 13. Filtrare - pastreaza doar tranzactiile de un tip
    void TranzactieFilterTipValLessUI();            // 14. Filtrare - pastreaza doar tranzactii sub o valoare pentru un tip
    void TranzactieUndoUI();                        // 15. Undo (revine la starea anterioara)

   // ======================= APARTAMENTE ===========================

    void ApartamentAddUI();                  // 1. Adauga o cheltuiala pentru un apartament
    void ApartamentUpdateUI();               // 2. Inlocuieste suma unei cheltuieli existente (cautata dupa numar apartament + tip)
    void ApartamentRemoveByIndexUI();        // 3. Sterge o cheltuiala dupa indexul din lista
    void ApartamentRemoveByNumarUI();        // 4. Sterge toate cheltuielile apartamentului specificat
    void ApartamentRemoveByIntervalUI();     // 5. Sterge cheltuieli pentru apartamente dintr-un interval [a, b]
    void ApartamentRemoveByTipUI();          // 6. Sterge toate cheltuielile pentru un anumit tip (ex: gaz)
    void ApartamentListUI();                 // 7. Afiseaza toate cheltuielile
    void ApartamentListByNumarUI();          // 8. Afiseaza cheltuielile pentru un anumit apartament
    void ApartamentListBySumaCmpUI();        // 9. Afiseaza cheltuieli dupa comparatie pe suma (<, =, >)
    void ApartamentSumaByTipUI();            // 10. Afiseaza suma totala a cheltuielilor pentru un anumit tip
    void ApartamentMaxInApUI();              // 11. Afiseaza cheltuiala cu valoarea maxima dintr-un apartament
    void ApartamentSortByTipDescUI();        // 12. Sorteaza descrescator cheltuielile pentru un tip (in functie de suma)
    void ApartamentFilterByTipUI();          // 13. Filtrare: pastreaza doar cheltuielile pentru un anumit tip
    void ApartamentFilterByValLessUI();      // 14. Filtrare: pastreaza doar cheltuielile mai mici decat o valoare data
    void ApartamentUndoUI();                 // 15. Undo: revine la starea anterioara

};

#endif // UI_H
