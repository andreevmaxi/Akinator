#include <stdio.h>
#include <cstdlib>

struct kot
    {
    int SizeOfKot;

    char* KotOpened;

    char* KotClosed;

    kot();

    ~kot();

    bool PrintKot(int mode);
    };

kot::kot()
    {
    FILE* fo = fopen("dzon_opened_ascii.txt", "r");
    FILE* fc = fopen("dzon_closed_ascii.txt", "r");


    fseek(fo, 0, SEEK_END);
    SizeOfKot = ftell(fo);
    rewind(fo);
    KotOpened = (char*) calloc(SizeOfKot, sizeof(char));
    fread(KotOpened, sizeof(char), SizeOfKot, fo);

    KotClosed = (char*) calloc(SizeOfKot, sizeof(char));
    fread(KotClosed, sizeof(char), SizeOfKot, fc);
    return;
    }

kot::~kot()
    {
    free(KotOpened);
    free(KotClosed);
    return;
    }

bool kot::PrintKot(int mode)
    {
    char* NowPrint;

    switch(mode)
        {
        case 1:
            {
            NowPrint = KotOpened;
            }
            break;

        case 2:
            {
            NowPrint = KotClosed;
            }
            break;
        }

    printf("%s\n", NowPrint);
    return 1;
    }
