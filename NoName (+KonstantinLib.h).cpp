//{===================================================================
//! @file   NoName.cpp
//!
//! @brief  Cartoon "No name"
//!
//!         An example of creating a cartoon using the library TXLib.h
//!
//      (c) Romanovskaia Anna Aleksandrovna, g. Omsk, 2021
//}===================================================================

#include "TXLib.h"
#include "SDK_DerMeister/DerMeisterLib.h"
#include "include/KonstantinLib.h"

const int SleepTime = 1;

void ZaKadrom ();
void TitlesBegin ();
void Scena1 ();
void Scena2 ();
void Scena3 ();
void TitlesEnd ();

int main ()
    {
    txCreateWindow (1400, 700);
    txClear ();

    ZaKadrom ();
    TitlesBegin ();
    Scena1 ();
    Scena2 ();
    Scena3 ();
    TitlesEnd ();
    }

void ZaKadrom ()
    {
    txBegin ();
    txPlaySound ("Soundtrack/Groza.wav");

    for (int time = 0; time <= 45; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        Konstantin::drawBackground ();

        Konstantin::drawPuddle (5 * time, 10);
        Konstantin::drawRocket (1200, -500, 0.7, 1, TX_WHITE, 0 - time * 20);
        Konstantin::drawHouses ();

        Konstantin::drawCloud (  50,  60 + time % 10, 60);
        Konstantin::drawCloud ( 260, 160 - time % 10, 50);
        Konstantin::drawCloud ( 450,  60 + time % 10, 60);
        Konstantin::drawCloud ( 660, 160 - time % 10, 50);
        Konstantin::drawCloud ( 850,  60 + time % 10, 60);
        Konstantin::drawCloud (1060, 160 - time % 10, 50);
        Konstantin::drawCloud (1250,  60 + time % 10, 60);

        if (time % 20 <= 5)
            {
            Konstantin::drawLightning (100, 175, 1, 1, TX_WHITE);
            Konstantin::drawLightning (500, 175, 1, 1, TX_WHITE);
            Konstantin::drawLightning (900, 175, 1, 1, TX_WHITE);
            }

        Konstantin::drawRain (0, -50, 10);

        txSleep (SleepTime);
        }

    txPlaySound (NULL);
    txPlaySound ("Soundtrack/ZaKadrom.wav");

    for (int time = 0; time <= 550; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        Konstantin::drawBackground ();

        if (time < 100)
            {
            Konstantin::drawPuddle (-5 * time, 225);
            }

        Konstantin::drawRocket (1200, 400, 0.7, 1, TX_WHITE, 0);
        Konstantin::drawHouses ();

        Konstantin::drawCloud (  50 + time * 10,  60 + time % 10, 60);
        Konstantin::drawCloud ( 260 - time * 10, 160 - time % 10, 50);
        Konstantin::drawCloud ( 450 + time * 10,  60 + time % 10, 60);
        Konstantin::drawCloud ( 660 - time * 10, 160 - time % 10, 50);
        Konstantin::drawCloud ( 850 + time * 10,  60 + time % 10, 60);
        Konstantin::drawCloud (1060 - time * 10, 160 - time % 10, 50);
        Konstantin::drawCloud (1250 + time * 10,  60 + time % 10, 60);

        if (time > 125)
            {
            Konstantin::drawSun (1200,  70, 0 + time / 10, 5, 0, 2);
            }

        if (150 <= time && time < 250)
            {
            CatDraw (1200, 600, 0.75, 1 + (time / 20 / 3) % 2, 0 +((time + 2) / 5 / 3) % 2,
                     0 + ((time + 1) / 10 / 3) % 2, 0, 0, 1);
            }

        if (time >= 250)
            {
            CatDraw (1200 - (time-249) * 5, 600, 0.75, 1 + (time / 20 / 3) % 2,
                     0 + ((time + 2) / 5 / 3) % 2, 0 + ((time + 1) / 10 / 3) % 2, 0 + (time / 15) % 2,
                     0 + (time / 20) % 2, 0);
            }

        txSleep (SleepTime);
        }

    txEnd ();
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

        txSleep (SleepTime);
        }
    txEnd ();
    }

void Scena1 ()
    {
    txBegin ();
    txPlaySound ("Soundtrack/Bus.wav");

    for (int time = 0; time < 320; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        Background ();

        ZadniiPlan (time);
        JuravleiKosyak (-180, 50, time);
        Lesopolosa (time/2);
        RazmetkaDraw (510, time * 4);

        BusLDraw (1400 - time * 6, 450, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                  0 + (time / 20) % 4, 0 + (time % 15) * 2, 1.25);
        SemerkaDraw (-1000 + time * 20, 570);

        txSleep (SleepTime);
        }

    for (int time = 0; time < 340; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        BackgroundSize ();

        LesopolosaSize (time * -1);
        RazmetkaDraw (480, time * -4);

        if (time <= 100)
            {
            MoskvichDraw (1400 - time * 4, 400, -60, 0, 0, (time / 15) % 2, 1);
            MisterDraw (1376 - time * 4, 320, 0, 2, TX_BROWN, 1, 0, 0, 0, 0, 1);
            MadamDrawProfil (1309 - time * 4, 300, TX_BLUE, 0 + (time / 20) % 2, 1 - (time / 20) % 2, 0, 0, 1, 1);
            }

        if (100 < time && time <= 150)
            {
            MoskvichDraw (1400 - time * 4, 400, -60, 0, 0, (time / 15) % 2, 1);
            MisterDrawProfil (1376 - time * 4, 320, TX_BROWN, 0, 0, 1, 1);
            MadamDrawProfil (1309 - time * 4, 300, TX_BLUE, 0, 0, 0, 0, 1, 1);
            Serdechko (1342 - time * 4, 310 - (time - 100) * 2, 0.1 + (time - 100) / 20);
            }

        if (150 < time && time <= 200)
            {
            MoskvichDraw  (1400 - time * 4, 400, 0, 0, 0, (time / 15) % 2, 1);
            }

        if (time > 200)
            {
            MoskvichDraw  (600 - (time - 200) * 15, 400, 0, -40, 10, 0, 1);
            }

        BusRDraw (0 + time * 6, 550, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                  0 + (time / 20) % 4, 0 + (time / 3) % 10, 1.5, 0, 0);

        txSleep (SleepTime);
        }

    for (int time = 0; time < 200; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        Background ();

        ZadniiPlan (time + 319);
        JuravleiKosyak (-180, 50, time + 319);

        if (time <= 100)
            {
            Lesopolosa (time);
            OstanovkaDraw (-40 + time, 370, 1);
            RazmetkaDraw (510, time * 4);
            BusLDraw (1400 - time * 7, 450, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                      0 + (time / 20) % 4, 0 + (time % 15) * 2, 1.25);
            }
        else
            {
            Lesopolosa (100 + (time - 100) / 2);
            OstanovkaDraw (60 + (time - 100) / 2, 370, 1);
            RazmetkaDraw (510, (time + 400) * 2);
            BusLDraw (700 - (time - 100) * 4, 450, 1, TX_DARKGRAY, 0 + ((time / 20) % 4) * 2,
                      0 + (time / 20) % 4, 0 + (time % 15) * 2, 1.25);
            }

        txSleep (SleepTime);
        }

    for (int time = 0; time < 100; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        BackgroundSize ();

        LesopolosaSize (0);
        RazmetkaDraw (480, 0);

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

        txSleep (SleepTime);
        }

    txPlaySound (NULL);
    txEnd ();
    }

void Scena2 ()
    {
    txBegin ();
    txPlaySound ("Soundtrack/Dveri.wav");

    for (int time = 0; time < 250; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        BackgroundSize ();

        LesopolosaSize (0);
        RazmetkaDraw (480, 0);

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
            MadamDraw (950, 550, 1, 1, 2, TX_BLUE, 1, 0, 0, 1, 1, 0, 0, 1.1);
            }

        if (time > 200)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 10, 25);
            MadamDraw (950, 550, 1, 1, 2, TX_BLUE, 1, 0, 0, 1, 1, 1, 1, 1.1);
            }

        txSetColor (TX_MYBROWN, 2);
        txSetFillColor (TX_CHOKOLATE);
        txRectangle (1100, 450, 1400, 510);
        txRectangle (1140, 510, 1400, 700);

        txSleep (SleepTime);
        }

    txPlaySound (NULL);
    txPlaySound ("Soundtrack/Sea.wav");

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

        Oblaka(time);
        MadamDraw (1100 - time / 2, 180 + time, 1, 1, 2, TX_BLUE, 1, 0, 0, 0 + (time / 20) % 2,
                   1 - (time / 20) % 2, 1, 1, 1.1 + 0.002 * time);

        txSleep (SleepTime);
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
        JuravleiKosyak (-180, 50, time);

        if (time <= 200)
            {
            Rybak (0 + time, 210, 1, 1);
            }

        if (time > 200)
            {
            Rybak (200, 210, 0 + (time / 100) % 2, 1);
            }

        if (time <= 340)
            {
            MadamDrawProfil (1340 - time * 2, 300 + time / 2, TX_BLUE, 0, 0, 0 + (time / 20) % 2, 1 - (time / 20) % 2, 1.5, -1);
            }

        if (340 < time && time <= 1100)
            {
            MadamDraw (660, 500, 0, 0, 2, TX_BLUE, 1, 0, 0, 0, 0, 0, 1, 1.5);
            }

        MnogoTravi (480, time);

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

        txSleep (SleepTime);
        }

    txPlaySound (NULL);
    txEnd ();
    }

void Scena3 ()
    {
    txBegin ();

    for (int time = 0; time <= 75; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();

        txSleep (SleepTime);
        }

    txPlaySound ("Soundtrack/End.wav");

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

        ZadniiPlan (time);

        Rybak (200, 210, 0 + (time / 100) % 2, 1);
        MnogoTravi (480, time);

        MadamDrawProfil (660 - time * 2, 500 - time / 3, TX_BLUE, 0, 0, 0 + (time / 20) % 2, 1 - (time / 20) % 2, 1.5, -1);
        CatDraw (720 - time * 2, 570 - time / 3, 0.75, 1 + (time / 20 / 3) % 2,
                 0 +((time + 2) / 5 / 3) % 2, 0 + ((time + 1) / 10 / 3) % 2, 0 + (time / 15) % 2,
                 0 + (time / 20) % 2, 0);

        txSleep (SleepTime);
        }

    for (int time = 0; time < 400; time++)
        {
        txSetFillColor (TX_WHITE);
        txClear ();
        BackgroundSize ();

        LesopolosaSize (0);
        RazmetkaDraw (480, 0);

        if (time <= 100)
            {
            BusRDraw (1200, 600, 0, TX_MYRED, 0, 0, 0, 1.5, 10, 25);
            MadamDraw (950, 550, 0, 1, 2, TX_BLUE, 1, 0, 0, 1, 1, 0, 0, 1.1);
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
                      0 + (time / 20) % 4, 0 + ((time - 250) % 15) * 2, 1.5, 0, 0);
            }

        txSetColor (TX_MYBROWN, 2);
        txSetFillColor (TX_CHOKOLATE);
        txRectangle (1100, 450, 1400, 510);
        txRectangle (1140, 510, 1400, 700);

        txSleep (SleepTime);
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
        txSleep (SleepTime);
        }
    txEnd ();
    }
