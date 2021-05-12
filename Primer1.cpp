#include "TXLib.h"
#include "DerMeisterLib.h"

int main ()
    {
    txCreateWindow (1400, 700);
    txClear ();

    Background ();
    Oblaka (0);
    RazmetkaDraw (510, 0);
    SemerkaDraw (100, 570);
    Lesopolosa (0);
    }
