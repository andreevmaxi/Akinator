#include <dos.h>
#include "dzon.h"

void SayKot(char* text, int SizeOfChar)
    {
    clock_t t0 = clock();
    clock_t t1 = clock();

    int NowChar = 0;
    int NowKotik = 0;

    while ( NowChar < 0 )
        {
            system("cls");
            sleep(0.1);
            ++NowChar

            for(int i = 0; i < NowChar; ++i)
                {
                printf("%c", *(text + i));
                }
            switch(*(text + NowChar - 1))
                {


                default:
                    {

                    }
                    break;
                }
        }
    }