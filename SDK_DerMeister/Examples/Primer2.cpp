#include "TXLib.h"
#include "..\DerMeisterLib.h"

int main ()
    {
    txCreateWindow (1000, 700);
    txClear ();

    txBegin ();
    for (int time = 0; time <= 150; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        Background ();

        if ((time / 40) % 2 < 1)
            {
            SolnceDraw (900, 80, 1 + time % 40);
            }
        else
            {
            SolnceDraw (900, 80, 39 - time % 40);
            }

        Oblaka (time);
        RazmetkaDraw (510, 0);
        Lesopolosa (0);
        SemerkaDraw (100, 570);
        MadamDrawProfil (0 + time * 2, 490, TX_BLUE, 0, 0,
                         0 + (time / 10) % 2, 1 - (time / 10) % 2, 1.1, 1);

        txSleep (1);
        }
    for (int time = 0; time <= 140; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        Background ();

        if ((time / 40) % 2 < 1)
            {
            SolnceDraw (900, 80, 1 + time % 40);
            }
        else
            {
            SolnceDraw (900, 80, 39 - time % 40);
            }

        Oblaka (150 + time);
        RazmetkaDraw (510, 0);
        Lesopolosa (0);
        SemerkaDraw (100 + time * 15, 570);

        txSleep (1);
        }
    txEnd ();
    }
