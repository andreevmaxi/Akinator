#include "SayKat.h"

int main()
    {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,".1251");
    /*
    char* text = (char*) calloc(100, sizeof(char));

    text = "³��� ����, ����� �� �����, �� ����� ������?";
    long SizeOfBase = 0;
    while(*(text + SizeOfBase) != '\0')
        {
        ++SizeOfBase;
        }


    FILE* Base = fopen("base.txt", "wb");
    fwrite(&SizeOfBase, sizeof(long), 1, Base);
    fwrite(text, sizeof(char), SizeOfBase, Base);

    */
    FILE* Base = fopen("base.txt", "rb");
    long SizeOfBase = 0;
    int FirstPos = ftell(Base);
    fread(&SizeOfBase, sizeof(long), 1, Base);
    char* text = (char*) calloc(SizeOfBase, sizeof(char));
    int NowPos = ftell(Base);
    fread(text, sizeof(char), SizeOfBase, Base);
    SayKot(text, SizeOfBase);
    return 0;
    }
