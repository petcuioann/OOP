#ifndef UI_H
#define UI_H

#include "CercService.h"
#include "DreptunghiService.h"
#include "NumarComplexService.h"
#include "PatratService.h"
#include "TriunghiService.h"

class UI {
private:
    CercService cercService;
    DreptunghiService dreptunghiService;
    NumarComplexService complexService;
	PatratService patratService;
	TriunghiService triunghiService;

public:
    void start();
    void manageCerc();
	void manageDreptunghi();
    void manageNumarComplex();
	void managePatrat();
	void manageTriunghi();
};

#endif
