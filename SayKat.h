#include <windows.h>
#include <clocale>
#include <locale>
#include "ShellAPI.h";

#include "dzon.h"


int IsItLoud(char OurChar)
    {
    int NowKotik = 1;

    switch(OurChar)
        {
        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case 'w':
            NowKotik = 2;
            break;

        case 'e':
            NowKotik = 2;
            break;

        case 'y':
            NowKotik = 2;
            break;

        case 'u':
            NowKotik = 2;
            break;

        case 'i':
            NowKotik = 2;
            break;

        case 'o':
            NowKotik = 2;
            break;

        case 'a':
            NowKotik = 2;
            break;

        case 'j':
            NowKotik = 2;
            break;

        case 'x':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case '�':
            NowKotik = 2;
            break;

        case 'Q':
            NowKotik = 2;
            break;

        case 'E':
            NowKotik = 2;
            break;

        case 'Y':
            NowKotik = 2;
            break;

        case 'U':
            NowKotik = 2;
            break;

        case 'I':
            NowKotik = 2;
            break;

        case 'O':
            NowKotik = 2;
            break;

        case 'A':
            NowKotik = 2;
            break;

        case 'J':
            NowKotik = 2;
            break;

        case 'X':
            NowKotik = 2;
            break;
        }
    return NowKotik;
    }


void SayKot(const char* text, int SizeOfChar)
    {
    kot Akinator;

    int NowChar = 0;
    int NowKotik = 1;
    std::string TmpStr = " -n \"TC Sergy_Ukrainian\" -s \"-10\" -t \"";
    TmpStr += text;
    TmpStr += "\"";
    //system(TmpStr.c_str());
    HWND hwnd;
    ShellExecute(hwnd,"open","balcon\\balcon.exe", TmpStr.c_str(),NULL, SW_HIDE);
    //ShellExecuteEx
    while ( NowChar < SizeOfChar )
        {
        system("cls");
        ++NowChar;
        NowKotik = IsItLoud(*(text + NowChar - 1));
        Akinator.PrintKot(NowKotik);
        printf("\n");
        for(int i = 0; i < NowChar; ++i)
            {
            printf("%c", *(text + i));
            }

        if(*(text + NowChar) == '\0')
            {
            NowChar = SizeOfChar;
            }
        Sleep(0.001);
        }

    }
