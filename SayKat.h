#include <windows.h>
#include <clocale>
#include <locale>
#include "ShellAPI.h";

#include "dzon.h"


double IsItLoud(char OurChar)
    {
    double NowKotik = 80;

    switch(OurChar)
        {
        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case 'w':
            NowKotik = 120;
            break;

        case 'e':
            NowKotik = 120;
            break;

        case 'y':
            NowKotik = 120;
            break;

        case 'u':
            NowKotik = 120;
            break;

        case 'i':
            NowKotik = 120;
            break;

        case 'o':
            NowKotik = 120;
            break;

        case 'a':
            NowKotik = 120;
            break;

        case 'j':
            NowKotik = 120;
            break;

        case 'x':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case '�':
            NowKotik = 120;
            break;

        case 'Q':
            NowKotik = 120;
            break;

        case 'E':
            NowKotik = 120;
            break;

        case 'Y':
            NowKotik = 120;
            break;

        case 'U':
            NowKotik = 120;
            break;

        case 'I':
            NowKotik = 120;
            break;

        case 'O':
            NowKotik = 120;
            break;

        case 'A':
            NowKotik = 120;
            break;

        case 'J':
            NowKotik = 120;
            break;

        case 'X':
            NowKotik = 120;
            break;
        }
    return NowKotik;
    }


void SayKot(char* text, int SizeOfChar)
    {
    kot Akinator;

    int NowChar = 0;
    double NowDelay = 0.0;

    system("cls");
    Akinator.PrintKot(1);
    Sleep(400);
    std::string TmpStr = " -n \"TC Sergy_Ukrainian\" -s \"-10\" -t \"";
    TmpStr += text;
    TmpStr += "\"";
    //system(TmpStr.c_str());
    HWND hwnd;
    ShellExecute(hwnd,"open","balcon\\balcon.exe", TmpStr.c_str(),NULL, SW_HIDE);
    //ShellExecuteEx

    system("cls");
    Akinator.PrintKot(2);
    printf("\n  ");
    while ( NowChar < SizeOfChar )
        {
        NowDelay = IsItLoud(*(text + NowChar));

        if(*(text + NowChar) == '\n')
            {
            printf("%c  ", *(text + NowChar));
            }
        else
            {
            printf("%c", *(text + NowChar));
            }

        if(*(text + NowChar) == '\0')
            {
            NowChar = SizeOfChar;
            }
        Sleep(NowDelay);

        ++NowChar;
        }
    system("cls");
    Akinator.PrintKot(1);
    NowChar = 0;
    printf("\n  ");
    while ( NowChar < SizeOfChar )
        {
        if(*(text + NowChar) == '\n')
            {
            printf("%c ", *(text + NowChar));
            }
        else
            {
            printf("%c", *(text + NowChar));
            }

        if(*(text + NowChar) == '\0')
            {
            NowChar = SizeOfChar;
            }
        ++NowChar;
        }

    Sleep(100);
    free(text);
    }
