//{========================================================
//! @file   NoName.cpp
//!
//! @brief  Мультфильм "No name"
//!
//!         Пример создания мультфильма с помощью TXLib.h
//!
//      (c) Романовская Анна Александровна, г. Омск, 2021
//}========================================================

#include "TXLib.h"
#include "DerMeisterLib.h"

const int Sl = 1;

void TitlesBegin ();
void Scena1 ();
void Scena2 ();
void Scena3 ();
void TitlesEnd ();

int main ()
    {
    txCreateWindow (1400, 700);
    txClear ();

    TitlesBegin ();
    Scena1 ();
    Scena2 ();
    Scena3 ();
    TitlesEnd ();
    }

void TitlesBegin ()
    {
    txBegin ();
    for (int time = 0; time <= 300; time++)
        {
        txClear ();
        txSetColor (TX_WHITE);
        txSetFillColor (TX_WHITE);
        txRectangle (0, 0, 1400, 700);

        if (time <= 50)
            {
            txSetColor (TX_BLACK);
            txSelectFont ("Arial Black", 10 + time * 2, 3 + time);
            txTextOut (630 - time * 10, 200, "OMSK PRODUCTION");
            txSelectFont ("Arial", 5 + time * 2, 2 + time);
            txTextOut (680 - time * 5, 300, "presents");
            }
        if (50 < time && time <= 150)
            {
            txSetColor (TX_BLACK);
            txSelectFont ("Arial Black", 110, 53);
            txTextOut (130, 200, "OMSK PRODUCTION");
            txSelectFont ("Arial", 105, 52);
            txTextOut (430, 300, "presents");
            }
        txSleep (Sl);
        }
    txEnd ();
    }

void Scena1 ()
    {
    txBegin ();
    txPlaySound ("Bus.wav");

    for (int time = 0; time < 320; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        Background ();

        ZadniiPlan (time);

        for (int x = -1400; x <= 2800; x += 120)
            {
            CvetokDraw (-1460 + x * 2 + time / 2, 260,    1, TX_WHITE, TX_ORANGE);
            DerevoDraw (-1400 + x * 2 + time / 2, 120, 1.25, 1);
            DerevoDraw (-1520 + x * 2 + time / 2, 170, 1.5, -1);
            CvetokDraw (-1580 + x * 2 + time / 2, 290,    1, TX_WHITE, TX_ORANGE);
            CvetokDraw (-1660 + x * 2 + time / 2, 335, 1.25, TX_ORANGE, TX_WHITE);
            }

        RazmetkaDraw (time * 4, 510);
        BusLDraw (1400 - time * 6, 450, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                  0 + (time / 20) % 4, 0 + (time % 15) * 2, 1.25);
        SemerkaDraw (-1000 + time * 20, 570);

        txSleep (Sl);
        }

    for (int time = 0; time < 340; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        BackgroundSize ();

        for (int x = -1400; x <= 2800; x += 140)
            {
            CvetokDraw (-1460 + x * 2 - time,  260,    1, TX_WHITE, TX_ORANGE);
            DerevoDraw (-1400 + x * 2 - time, -150,  1.5,  1);
            DerevoDraw (-1520 + x * 2 - time,  -50,    2, -1);
            CvetokDraw (-1580 + x * 2 - time,  260,    1, TX_WHITE, TX_ORANGE);
            CvetokDraw (-1660 + x * 2 - time,  200, 1.25, TX_ORANGE, TX_WHITE);
            }

        RazmetkaDraw (time * -4, 480);

        if (time <= 100)
            {
            MoskvichDraw  (1400 - time * 4, 400, -60, 0, 0, (time / 15) % 2, 1);
            MisterZadDraw (1376 - time * 4, 320, 1);
            MadamBokDraw  (1309 - time * 4, 300, 0 + (time / 20) % 2, 1 - (time / 20) % 2, 0, 0, 1, 1);
            }

        if (100 < time && time <= 150 )
            {
            MoskvichDraw  (1400 - time * 4, 400, -60, 0, 0, (time / 15) % 2, 1);
            MisterBokDraw (1376 - time * 4, 320, 0, 0, 1);
            MadamBokDraw  (1309 - time * 4, 300, 0, 0, 0, 0, 1, 1);
            Serdechko     (1342 - time * 4, 310 - (time - 100) * 2, 0.1 + (time - 100) / 20);
            }

        if (150 < time && time <=200)
            {
            MoskvichDraw  (1400 - time * 4, 400, 0, 0, 0, (time / 15) % 2, 1);
            }

        if (time > 200)
            {
            MoskvichDraw  (600 - (time - 200) * 15, 400, 0, -40, 10, 0, 1);
            }

        BusRDraw (0 + time * 6, 550, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                  0 + (time / 20) % 4, 0 + (time / 3) % 10, 1.5, 0, 0);

        txSleep (Sl);
        }

    for (int time = 0; time < 200; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        Background ();

        ZadniiPlan (time + 319);

        if (time <= 100)
            {
            for (int x = -1400; x <= 2800; x += 120)
                {
                CvetokDraw (-1460 + x * 2 + time, 260,    1, TX_WHITE, TX_ORANGE);
                DerevoDraw (-1400 + x * 2 + time, 120, 1.25, 1);
                DerevoDraw (-1520 + x * 2 + time, 170, 1.5, -1);
                CvetokDraw (-1580 + x * 2 + time, 290,    1, TX_WHITE, TX_ORANGE);
                CvetokDraw (-1660 + x * 2 + time, 335, 1.25, TX_ORANGE, TX_WHITE);
                }

            OstanovkaDraw (-40 + time, 370, 1);
            RazmetkaDraw (time * 4, 510);
            BusLDraw (1400 - time * 7, 450, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                      0 + (time / 20) % 4, 0 + (time % 15) * 2, 1.25);
            }

        else
            {
            for (int x = -1400; x <= 2800; x += 120)
                {
                CvetokDraw (-1360 + x * 2 + (time - 100) / 2, 260,    1, TX_WHITE, TX_ORANGE);
                DerevoDraw (-1300 + x * 2 + (time - 100) / 2, 120, 1.25, 1);
                DerevoDraw (-1420 + x * 2 + (time - 100) / 2, 170, 1.5, -1);
                CvetokDraw (-1480 + x * 2 + (time - 100) / 2, 290,    1, TX_WHITE, TX_ORANGE);
                CvetokDraw (-1560 + x * 2 + (time - 100) / 2, 335, 1.25, TX_ORANGE, TX_WHITE);
                }

            OstanovkaDraw (60 + (time - 100) / 2, 370, 1);
            RazmetkaDraw ((time + 400) * 2, 510);
            BusLDraw (700 - (time - 100) * 4, 450, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                      0 + (time / 20) % 4, 0 + (time % 15) * 2, 1.25);
            }

        txSleep (Sl);
        }

    for (int time = 0; time < 100; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        BackgroundSize ();

        for (int x = -1400; x <= 2800; x += 140)
            {
            CvetokDraw (-1460 + x * 2, 260,    1, TX_WHITE, TX_ORANGE);
            DerevoDraw (-1400 + x * 2, -150, 1.5,  1);
            DerevoDraw (-1520 + x * 2,  -50,   2, -1);
            CvetokDraw (-1580 + x * 2, 260,    1, TX_WHITE, TX_ORANGE);
            CvetokDraw (-1660 + x * 2, 200, 1.25, TX_ORANGE, TX_WHITE);
            }

        RazmetkaDraw (0, 480);

        if (time <= 50)
            {
            BusRDraw (1000 + time * 4, 600, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                          0 + (time / 20) % 4, 0 + (time % 15) * 2, 1.5, 0, 0);
            }

        else
            {
            BusRDraw (1200, 600, 0, TX_DARKGRAY, 0, 0, 0, 1.5, 0, 0);
            }

        txSetColor (TX_MYBROWN, 2);
        txSetFillColor (TX_CHOKOLATE);
        txRectangle (1100, 450, 1400, 510);
        txRectangle (1140, 510, 1400, 700);

        txSleep (Sl);
        }

    txPlaySound (NULL);
    txEnd ();
    }

void Scena2 ()
    {
    txBegin ();
    txPlaySound ("Dveri.wav");

    for (int time = 0; time < 250; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        BackgroundSize ();

        for (int x = -1400; x <= 2800; x += 140)
            {
            CvetokDraw (-1460 + x * 2,  260,    1, TX_WHITE, TX_ORANGE);
            DerevoDraw (-1400 + x * 2, -150,  1.5,  1);
            DerevoDraw (-1520 + x * 2,  -50,    2, -1);
            CvetokDraw (-1580 + x * 2,  260,    1, TX_WHITE, TX_ORANGE);
            CvetokDraw (-1660 + x * 2,  200, 1.25, TX_ORANGE, TX_WHITE);
            }

        RazmetkaDraw (0, 480);

        if (time <= 50)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 0 + (time / 5) % 11, 0);
            }

        if (50 < time && time <= 100)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 10, 0 + ((time - 50) / 2) % 26);
            }

        if (100 < time && time <= 120)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 10, 25);
            }

        if (120 < time && time <= 200)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 10, 25);
            MadamDraw (950, 550, 2, TX_BLUE, 1, 0, 0, 0, 0, 0, 0, 1.1);
            }

        if (time > 200)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 10, 25);
            MadamDraw (950, 550, 2, TX_BLUE, 1, 0, 0, 0, 0, 1, 1, 1.1);
            }

        txSetColor (TX_MYBROWN, 2);
        txSetFillColor (TX_CHOKOLATE);
        txRectangle (1100, 450, 1400, 510);
        txRectangle (1140, 510, 1400, 700);

        txSleep (Sl);
        }

    txPlaySound (NULL);
    txPlaySound ("Sea.wav");

    for (int time = 0; time < 300; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();

        if ((time / 80) % 2 < 1)
            {
            BackgroundMore (720, 400, 1 + (time / 2) %40);
            }

        else
            {
            BackgroundMore (720, 400, 40 - (time / 2) % 40);
            }

        Obloka (time);
        MadamDraw (1100 - time / 2, 180 + time, 2, TX_BLUE, 1, 0, 0, 0 + (time / 20) % 2,
                   1 - (time / 20) % 2, 1, 1, 1.1 + 0.002 * time);

        txSleep (Sl);
        }

    for (int time = 0; time <= 1100; time ++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();

        if ((time / 80) % 2 < 1)
            {
            BackgroundBeach (1 + (time / 2) %40);
            }

        else
            {
            BackgroundBeach (40 - (time / 2) % 40);
            }

        ZadniiPlan (time);

        if (time <= 100)
            {
            Rybak (0 + time * 2, 210, 1, 1);
            }

        if (time > 100)
            {
            Rybak (200, 210, 0 + (time / 100) % 2, 1);
            }

        if (time <= 340)
            {
            MadamBokDraw (1340 - time * 2, 300 + time / 2, 0, 0, 0 + (time / 20) % 2, 1 - (time / 20) % 2, 1.5, -1);
            }

        if (340 < time && time <= 1100)
            {
            MadamZadDraw (660, 500, 0, 0, 0, 0, 1.5);
            }

        int y = 480;
        for (int x = 40; x < 450; x += 120)
            {
            Trava (x, y, 0 + time / 80 % 2, 1);
            Trava (1400 - x, y, 0 + time / 80 % 2, 1);
            Trava (x + 60, y + 80, 0 + time / 80 % 2, 1);
            Trava (1400 - x - 60, y + 80, 0 + time / 80 % 2, 1);
            y += 40;
            }

        if (400 < time && time <= 740)
            {
            CatDraw (1400 - (time - 400) * 2, 400 + (time - 400) / 2, 0.75, 1 + (time / 20 / 3) % 2,
                     0 +((time + 2) / 5 / 3) % 2, 0 + ((time + 1) / 10 / 3) % 2, 0 + (time / 15) % 2,
                     0 + (time / 20) % 2, 0);
            }

        if (740 < time && time <= 790)
            {
            CatDraw (720, 570, 0.75, 1 + (time / 20 / 3) % 2, 0 + ((time + 2) / 5 / 3) % 2,
                     0 + ((time + 1) / 10 / 3) % 2, 0 + (time / 15) % 2, 0, 1);
            }

        if (790 < time && time <= 840)
            {
            CatZadDraw (720, 570, 0.75, 1 + (time / 20 / 3) % 2, 0 + ((time + 2) / 5 / 3) % 2,
                        0 + ((time + 1) / 10 / 3) % 2, 0 + (time / 30) % 2);
            Serdechko (740, 500 - (time - 790), 0.1 + (time - 790) / 20);
            }

        if (time > 840)
            {
            CatZadDraw (720, 570, 0.75, 1 + (time / 20 / 3) % 2, 0 + ((time + 2) / 5 / 3) % 2,
                        0 + ((time + 1) / 10 / 3) % 2, 0 + (time / 30) % 2);
            }

        txSleep (Sl);
        }

    txPlaySound (NULL);
    txEnd ();
    }

void Scena3 ()
    {
    txBegin ();

    for (int time = 0; time <= 100; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();

        txSleep (Sl);
        }

    txPlaySound ("End.wav");

    for (int time = 0; time <= 400; time ++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();

        if ((time / 80) % 2 < 1)
            {
            BackgroundBeach (1 + (time / 2) %40);
            }

        else
            {
            BackgroundBeach (40 - (time / 2) % 40);
            }

        SolncaSvet (time);
        Obloka (time);
        Rybak (200, 210, 0 + (time / 100) % 2, 1);

        int y = 480;
        for (int x = 40; x < 450; x += 120)
            {
            Trava (x, y, 0 + time / 80 % 2, 1);
            Trava (1400 - x, y, 0 + time / 80 % 2, 1);
            Trava (x + 60, y + 80, 0 + time / 80 % 2, 1);
            Trava (1400 - x - 60, y + 80, 0 + time / 80 % 2, 1);
            y += 40;
            }

        CatDraw (720 - time * 2, 570 - time / 3, 0.75, 1 + (time / 20 / 3) % 2,
                 0 +((time + 2) / 5 / 3) % 2, 0 + ((time + 1) / 10 / 3) % 2, 0 + (time / 15) % 2,
                 0 + (time / 20) % 2, 0);
        MadamBokDraw (660 - time * 2, 500 - time / 3, 0, 0, 0 + (time / 20) % 2, 1 - (time / 20) % 2, 1.5, -1);

        txSleep (Sl);
        }

    for (int time = 0; time < 400; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        BackgroundSize ();

        for (int x = -1400; x <= 2800; x += 140)
            {
            CvetokDraw (-1460 + x * 2,  260,    1, TX_WHITE, TX_ORANGE);
            DerevoDraw (-1400 + x * 2, -150,  1.5,  1);
            DerevoDraw (-1520 + x * 2,  -50,    2, -1);
            CvetokDraw (-1580 + x * 2,  260,    1, TX_WHITE, TX_ORANGE);
            CvetokDraw (-1660 + x * 2,  200, 1.25, TX_ORANGE, TX_WHITE);
            }

        RazmetkaDraw (0, 480);

        if (time <= 100)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 10, 25);
            MadamZadDraw (950, 550, 0, 0, 1, 1, 1.1);
            CatZadDraw (1000, 620, 0.7, 1 + (time / 20 / 3) % 2, 0 +((time + 2) / 5 / 3) % 2,
                        0 + ((time + 1) / 10 / 3) % 2, 0 + (time / 15) % 2);
            }

        if (100 < time && time <= 150)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 10, 25 - ((time - 100) / 2) % 26);
            }

        if (150 < time && time <= 200)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 10 - ((time - 150) / 5) % 11, 0);
            }

        if (200 < time && time <= 250)
            {
            BusRDraw (1200, 600, 0, TX_DARKGRAY, 0, 0, 0, 1.5, 0, 0);
            }

        if (time > 250)
            {
            BusRDraw (1200 + (time - 250) * 6, 600, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                      0 + (time / 20) % 4, 0 + (time / 3) % 10, 1.5, 0, 0);
            }

        txSetColor (TX_MYBROWN, 2);
        txSetFillColor (TX_CHOKOLATE);
        txRectangle (1100, 450, 1400, 510);
        txRectangle (1140, 510, 1400, 700);

        txSleep (Sl);
        }

    txEnd ();
    }

void TitlesEnd ()
    {
    txBegin ();
    for (int time = 0; time <= 300; time++)
        {
        txClear ();
        txSetColor (TX_WHITE);
        txSetFillColor (TX_WHITE);
        txRectangle (0, 0, 1400, 700);

        txSetColor (TX_BLACK);
        txSelectFont ("Arial Black", 90);
        txTextOut (300, 750 - time * 5, "ANIMATOR:");
        txSelectFont ("Arial", 70);
        txTextOut (300, 850 - time * 5, "Romanovskaia Anna Aleksandrovna");
        txSelectFont ("Arial Black", 130);
        txTextOut (100, 1250 - time * 5, "THANKS FOR ATTENTION!!!");
        txSleep (Sl);
        }
    txEnd ();
    }
