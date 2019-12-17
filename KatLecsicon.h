#include "MTree.h"
#include "SayKat.h"

struct CatPhases
    {
    char* HelloBuff;
     int  HelloSize;
    char* WinBuff;
     int  WinSize;
    char* LoseBuff;
     int  LoseSize;
    char* AddBuff;
     int  AddSize;
    char* MenuBuff;
     int  MenuSize;
    char* CompBuff;
     int  CompSize;
    char* FindBuff;
     int  FindSize;
    char* GoodByeBuff;
     int  GoodByeSize;
    char* NAnsBuff;
     int  NAnsSize;
    char* BNewBuff;
     int  BNewSize;
    char* UserAddAnsBuff;
     int  UserAddAnsSize;
    char* IGuideBuff;
     int  IGuideSize;
    char* PervoeBuff;
     int  PervoeSize;
    char* SpaciboBuff;
     int  SpaciboSize;

    char* GiveW(std::string Name, char* a = NULL, char* b = NULL, char* c = NULL);

    CatPhases();

    ~CatPhases();
    };

CatPhases::CatPhases()
    {
    FILE* fp = fopen("systemfiles\\hello.txt", "rb");
    fseek(fp, 0, SEEK_END);
    HelloSize = ftell(fp);
    rewind(fp);
    HelloBuff = (char*) calloc(HelloSize, sizeof(char));
    fread(HelloBuff, sizeof(char), HelloSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\win.txt", "rb");
    fseek(fp, 0, SEEK_END);
    WinSize = ftell(fp);
    rewind(fp);
    WinBuff = (char*) calloc(WinSize, sizeof(char));
    fread(WinBuff, sizeof(char), WinSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\lose.txt", "rb");
    fseek(fp, 0, SEEK_END);
    LoseSize = ftell(fp);
    rewind(fp);
    LoseBuff = (char*) calloc(LoseSize, sizeof(char));
    fread(LoseBuff, sizeof(char), LoseSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\adding.txt", "rb");
    fseek(fp, 0, SEEK_END);
    AddSize = ftell(fp);
    rewind(fp);
    AddBuff = (char*) calloc(AddSize, sizeof(char));
    fread(AddBuff, sizeof(char), AddSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\noans.txt", "rb");
    fseek(fp, 0, SEEK_END);
    NAnsSize = ftell(fp);
    rewind(fp);
    NAnsBuff = (char*) calloc(NAnsSize, sizeof(char));
    fread(NAnsBuff, sizeof(char), NAnsSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\menu.txt", "rb");
    fseek(fp, 0, SEEK_END);
    MenuSize = ftell(fp);
    rewind(fp);
    MenuBuff = (char*) calloc(MenuSize, sizeof(char));
    fread(MenuBuff, sizeof(char), MenuSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\compare.txt", "rb");
    fseek(fp, 0, SEEK_END);
    CompSize = ftell(fp);
    rewind(fp);
    CompBuff = (char*) calloc(CompSize, sizeof(char));
    fread(CompBuff, sizeof(char), CompSize, fp);
    fclose(fp);



    fp = fopen("systemfiles\\find.txt", "rb");
    fseek(fp, 0, SEEK_END);
    FindSize = ftell(fp);
    rewind(fp);
    FindBuff = (char*) calloc(FindSize, sizeof(char));
    fread(FindBuff, sizeof(char), FindSize, fp);
    fclose(fp);



    fp = fopen("systemfiles\\goodbye.txt", "rb");
    fseek(fp, 0, SEEK_END);
    GoodByeSize = ftell(fp);
    rewind(fp);
    GoodByeBuff = (char*) calloc(GoodByeSize, sizeof(char));
    fread(GoodByeBuff, sizeof(char), GoodByeSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\badnew.txt", "rb");
    fseek(fp, 0, SEEK_END);
    BNewSize = ftell(fp);
    rewind(fp);
    BNewBuff = (char*) calloc(BNewSize, sizeof(char));
    fread(BNewBuff, sizeof(char), BNewSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\UserAddAns.txt", "rb");
    fseek(fp, 0, SEEK_END);
    UserAddAnsSize = ftell(fp);
    rewind(fp);
    UserAddAnsBuff = (char*) calloc(UserAddAnsSize, sizeof(char));
    fread(UserAddAnsBuff, sizeof(char), UserAddAnsSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\AddingGuide.txt", "rb");
    fseek(fp, 0, SEEK_END);
    IGuideSize = ftell(fp);
    rewind(fp);
    IGuideBuff = (char*) calloc(IGuideSize, sizeof(char));
    fread(IGuideBuff, sizeof(char), IGuideSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\Pervoe.txt", "rb");
    fseek(fp, 0, SEEK_END);
    PervoeSize = ftell(fp);
    rewind(fp);
    PervoeBuff = (char*) calloc(PervoeSize, sizeof(char));
    fread(PervoeBuff, sizeof(char), PervoeSize, fp);
    fclose(fp);


    fp = fopen("systemfiles\\Spacibo.txt", "rb");
    fseek(fp, 0, SEEK_END);
    SpaciboSize = ftell(fp);
    rewind(fp);
    SpaciboBuff = (char*) calloc(SpaciboSize, sizeof(char));
    fread(SpaciboBuff, sizeof(char), SpaciboSize, fp);
    fclose(fp);
    return;
    }

CatPhases::~CatPhases()
    {
    free(HelloBuff);
    HelloSize = 0;
    free(WinBuff);
    WinSize = 0;
    free(LoseBuff);
    LoseSize = 0;
    free(AddBuff);
    AddSize = 0;
    free(NAnsBuff);
    NAnsSize = 0;
    free(BNewBuff);
    BNewSize = 0;
    free(MenuBuff);
    MenuSize = 0;
    free(CompBuff);
    CompSize = 0;
    free(FindBuff);
    FindSize = 0;
    free(GoodByeBuff);
    GoodByeSize = 0;
    free(UserAddAnsBuff);
    UserAddAnsSize = 0;
    free(IGuideBuff);
    IGuideSize = 0;
    free(PervoeBuff);
    PervoeSize = 0;
    free(SpaciboBuff);
    SpaciboSize = 0;

    return;
    }


long ReverseLong(long a)
    {
    long b = 0;
    printf("%d %d %d %d", (int)*((char*)(&a) + 3), (int)*((char*)(&a) + 2), (int)*((char*)(&a) + 1), (int)*((char*)(&a) + 0));
    *((char*)(&b) + 0) = *((char*)(&a) + 3);
    *((char*)(&b) + 1) = *((char*)(&a) + 2);
    *((char*)(&b) + 2) = *((char*)(&a) + 1);
    *((char*)(&b) + 3) = *((char*)(&a) + 0);

    return b;
    }

char* CatPhases::GiveW(std::string Name, char* a, char* b, char* c)
    {
    srand(time(NULL));

    char* buff;
    int sizebuff = 0;

    switch(*(Name.c_str()))
        {
        case('H'):
            buff = HelloBuff;
            sizebuff = HelloSize;
            break;

        case('W'):
            buff = WinBuff;
            sizebuff = WinSize;
            break;

        case('L'):
            buff = LoseBuff;
            sizebuff = LoseSize;
            break;

        case('A'):
            buff = AddBuff;
            sizebuff = AddSize;
            break;

        case('M'):
            buff = MenuBuff;
            sizebuff = MenuSize;
            break;

        case('C'):
            buff = CompBuff;
            sizebuff = CompSize;
            break;

        case('F'):
            buff = FindBuff;
            sizebuff = FindSize;
            break;

        case('G'):
            buff = GoodByeBuff;
            sizebuff = GoodByeSize;
            break;

        case('N'):
            buff = NAnsBuff;
            sizebuff = NAnsSize;
            break;

        case('B'):
            buff = BNewBuff;
            sizebuff = BNewSize;
            break;

        case('U'):
            buff = UserAddAnsBuff;
            sizebuff = UserAddAnsSize;
            break;

        case('I'):
            buff = IGuideBuff;
            sizebuff = IGuideSize;
            break;

        case('S'):
            buff = SpaciboBuff;
            sizebuff = SpaciboSize;

        case('P'):
            buff = PervoeBuff;
            sizebuff = PervoeSize;
        }
    int RandomPhraze = rand() % 7 - 1;

    char* tmp = buff;
    long  TmpSizeNise = 0;
    for(int i = 0; i < RandomPhraze; ++i)
        {
        TmpSizeNise = (*((long*)tmp));
        if(TmpSizeNise + (tmp - buff) + 4 < (sizebuff - 5))
            {
            tmp += *((long*)tmp) + sizeof(long);
            }
        else
            {
            tmp = buff;
            }
        }
    TmpSizeNise = (*((long*)tmp));
    tmp += sizeof(long);
    buff = tmp;
    if(a != NULL)
        {
        ++TmpSizeNise;
        TmpSizeNise += strlen(a);
        }
    if(b != NULL)
        {
        ++TmpSizeNise;
        TmpSizeNise += strlen(b);
        }
    if(c != NULL)
        {
        ++TmpSizeNise;
        TmpSizeNise += strlen(c);
        }
    ++TmpSizeNise;
    buff = (char*) calloc(TmpSizeNise + 1, sizeof(char));
    for(long i = 0; i < *(long*)(tmp - sizeof(long)); ++i)
        {
        *(buff + i) = *(tmp + i);
        }
    if(a != NULL)
        {
        *(*(long*)(tmp - sizeof(long)) + strlen(a) + buff) = ' ';
        strcpy((*(long*)(tmp - sizeof(long)) + strlen(a) + buff + 1), a);
        if(b != NULL)
            {
            *(*(long*)(tmp - sizeof(long)) + strlen(a) + strlen(b) + buff) = ' ';
            strcpy((*(long*)(tmp - sizeof(long)) + strlen(a) + strlen(b) + 1 + buff), b);
            if(c != NULL)
                {
                *(*(long*)(tmp - sizeof(long)) + strlen(a) + strlen(b) + strlen(c) + buff) = ' ';
                strcpy((*(long*)(tmp - sizeof(long)) + strlen(a) + strlen(b) + 1 + strlen(c) + buff), c);
                }
            }
        }
    *(buff + TmpSizeNise) = '\0';
    *(buff + TmpSizeNise - 1) = '\n';
    return buff;
    }
