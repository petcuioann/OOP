#include "Tests.h"
#include "UI.h"

int main() {
    testAdaugareCerc();
    testStergereCerc();
    testGetCelMaiMareCerc();
    testGolireRepository();

    UI ui;
    ui.start();

    return 0;
}
