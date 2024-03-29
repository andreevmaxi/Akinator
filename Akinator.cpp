#include <conio.h>

#include "KatLecsicon.h"
#ifdef _DEBUG
    #define DEB( code ) code

    bool NewPhrase(int file, char* text, int SizeOfText);
#endif

bool AddingNewNode(MBinaryTree_t* Akin, MNode_Binar_t* ToThatNode, char* NewAns);

char* EnterUntilEnter(int* AnsSize);

bool AkinatorMenu();

void GuessSth(MBinaryTree_t* AkinatorTree);

void CheckIfAlreadyDone(MBinaryTree_t* AkinatorTree, MNode_Binar_t* NonCorrectNode);

void CompareWord(MBinaryTree_t* AkinatorTree);

void CharacterWord(MBinaryTree_t* AkinatorTree, char* UserAns);

bool IsCharInTree(const MBinaryTree_t* AkinatorTree, char* UserAns);

void CharacterWord(MBinaryTree_t* AkinatorTree, char* UserAns);

void CompareWord(MBinaryTree_t* AkinatorTree);

MNode_Binar_t* SearchInTree(MBinaryTree_t* AkinatorTree, char* UserAns);

CatPhases dzonik;

int main()
    {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,".1251");
    /*
    char* text = (char*) calloc(100, sizeof(char));

    text = "� ����� ���� ������, ��� �� ������� ���� �� ���, ������������ ��-������ ...";
    long SizeOfBase = 0;
    while(*(text + SizeOfBase) != '\0')
        {
        ++SizeOfBase;
        }
    NewPhrase(13, text, SizeOfBase);
    */
    /*
    char* text = (char*) calloc(100, sizeof(char));

    text = "�������� �� ��? ���� ������ � ��������?";
    long SizeOfBase = 0;
    while(*(text + SizeOfBase) != '\0')
        {
        ++SizeOfBase;
        }


    FILE* Base = fopen("systemfiles\\hello.txt", "wb");
    fwrite(&SizeOfBase, sizeof(long), 1, Base);
    fwrite(text, sizeof(char), SizeOfBase, Base);
    */

    /*
    FILE* Base = fopen("systemfiles\\hello.txt", "rb");
    long SizeOfBase = 0;
    int FirstPos = ftell(Base);
    fread(&SizeOfBase, sizeof(long), 1, Base);
    char* text = (char*) calloc(SizeOfBase, sizeof(char));
    int NowPos = ftell(Base);
    fread(text, sizeof(char), SizeOfBase, Base);
    SayKot(text, SizeOfBase);
    */
    /*
    DEBMTree_t(AkinatorTree);
    FILE* akinator = fopen("systemfiles\\akinator.txt", "rb");

    char* text = (char*) calloc(100, sizeof(char));

    text = "�� ������, �� ���\n�� ���������, �����, �� ������,\n���� ��, ����� ����������� ��-������...";
    long SizeOfText = 0;
    while(*(text + SizeOfText) != '\0')
        {
        ++SizeOfText;
        }
    NewPhrase(7, text, SizeOfText);
    fclose(akinator);
    */
    /*
    DEBMTree_t(AkinatorTree);
    FILE* akinator = fopen("systemfiles\\akinator.txt", "rb");
    fseek(akinator, 0, SEEK_END);
    long SizeTree = ftell(akinator);
    rewind(akinator);
    char* AkinatorBuffer = (char*) calloc(SizeTree, sizeof(char));
    int i = 0;
    while(i < SizeTree)
        {
        *(AkinatorBuffer + i) = fgetc(akinator);
        ++i;
        }
    printf("%s", AkinatorBuffer);
    AkinatorTree.ReadTree(AkinatorBuffer);

    char* NewAns = (char*) calloc(100, sizeof(char));
    NewAns = "�������(˳���� �� ������)";

    printf("Iz root now: %x\n", AkinatorTree.root);
    AddingNewNode(&AkinatorTree, (*(AkinatorTree.root)).Left, NewAns);
    printf("Ak root now: %x\n", AkinatorTree.root);
    AkinatorTree.TDUMP(9);
    char* buffer = (char*)calloc(1, sizeof(char));

    int BufferSize = 1;
    AkinatorTree.PrintTree(&buffer, &BufferSize);
    fclose(akinator);
    akinator = fopen("systemfiles\\akinator.txt", "wb");
    fwrite(buffer, BufferSize, sizeof(char), akinator);
    fclose(akinator);
    */
    AkinatorMenu();
    return 0;
    }

#ifdef _DEBUG
    bool NewPhrase(int file, char* text, int SizeOfText)
        {
        std::string openfile;

        switch(file)
            {
            case(0):
                {
                openfile = "systemfiles\\hello.txt";
                }
                break;
            case(1):
                {
                openfile = "systemfiles\\win.txt";
                }
                break;
            case(2):
                {
                openfile = "systemfiles\\lose.txt";
                }
                break;
            case(3):
                {
                openfile = "systemfiles\\adding.txt";
                }
                break;
            case(4):
                {
                openfile = "systemfiles\\menu.txt";
                }
                break;
            case(5):
                {
                openfile = "systemfiles\\compare.txt";
                }
                break;
            case(6):
                {
                openfile = "systemfiles\\find.txt";
                }
                break;
            case(7):
                {
                openfile = "systemfiles\\goodbye.txt";
                }
                break;
            case(8):
                {
                openfile = "systemfiles\\noans.txt";
                }
                break;
            case(9):
                {
                openfile = "systemfiles\\badnew.txt";
                }
                break;
            case(10):
                {
                openfile = "systemfiles\\UserAddAns.txt";
                }
                break;
            case(11):
                {
                openfile = "systemfiles\\AddingGuide.txt";
                }
                break;
            case(12):
                {
                openfile = "systemfiles\\Pervoe.txt";
                }
                break;
            case(13):
                {
                openfile = "systemfiles\\Spacibo.txt";
                }
                break;
            }

        FILE* fp = fopen(openfile.c_str(), "rb");
        fseek(fp, 0, SEEK_END);
        int RealSizeOfBuffer = ftell(fp);
        rewind(fp);
        char* buffer     = (char*) calloc(RealSizeOfBuffer, sizeof(char));

        fread(buffer, sizeof(char), RealSizeOfBuffer, fp);

        fclose(fp);
        fp = fopen(openfile.c_str(), "wb");
        fwrite(buffer, sizeof(char), RealSizeOfBuffer, fp);
        fwrite(&SizeOfText, sizeof(long), 1, fp);
        fwrite(text, sizeof(char), SizeOfText, fp);

        fclose(fp);
        return 1;
        }
#endif

bool AddingNewNode(MBinaryTree_t* Akin, MNode_Binar_t* ToThatNode, char* NewAns)
    {
    MNode_Binar_t* NewQuas = new MNode_Binar_t('C', ToThatNode->Parent);
    SayKot(dzonik.GiveW("IGuide"), dzonik.IGuideSize);
    //��������� �� ���� ��� ��������� ������� ������(��� ��� ������ �� � ��)
    int UserAnsSize = 0;
    char* UserAns = 0;
    UserAns = EnterUntilEnter(&UserAnsSize);
    //Proverka pravil

    free(NewQuas->data);
    NewQuas->data = (void*) UserAns;
    NewQuas->Right = ToThatNode;
    if((ToThatNode->Parent)->Left == ToThatNode)
        {
        (ToThatNode->Parent)->Left  = NewQuas;
        }
    else
        {
        (ToThatNode->Parent)->Right = NewQuas;
        }
    ToThatNode->Parent = NewQuas;
    MNode_Binar_t* SecAns = new MNode_Binar_t('C', NewQuas);
    free(SecAns->data);
    NewQuas->Left = SecAns;
    SecAns->data = (void*) NewAns;
    DEB(++Akin->TreeSize);
    DEB(++Akin->TreeSize);
    ToThatNode = NewQuas;
    UserAns = 0;
    NewAns = 0;
    //������ �� ���������� ��� ��������� ��, �� ����� �� NewQuastion �������� ������, ��� ��������?
    //�� ������ ������ �������� �������� �� �� � �� ������� ��� ���

    char vop[450] = "��������� ��, �� ����� �� ������:\"";
    int i = 0;
    while(*((char*)ToThatNode->data + i) != '\0')
        {
        *(vop + i + 34) += *((char*)ToThatNode->data + i);
        ++i;
        }
    *(vop + i + 34) = '\"';
    *(vop + i + 35) = ' ';
    *(vop + i + 36) = '�';
    *(vop + i + 37) = ' ';
    *(vop + i + 38) = '\"';
    int j = 0;
    while(*((char*)(ToThatNode->Left)->data + j) != '\0')
        {
        *(vop + i + 39) += *((char*)(ToThatNode->Left)->data + j);
        ++i;
        ++j;
        }
    *(vop + i + 39) = '\"';
    *(vop + i + 40) = '\0';

    SayKot(vop, 450);
    int AnsSize2 = 0;
    char* UserAns2 = EnterUntilEnter(&AnsSize2);
    *UserAns2 = tolower(*UserAns2);

    while(*UserAns2 != '�' && *UserAns2 != 'y' && *UserAns2 != 'n' && *UserAns2 != '�')
        {
        SayKot(dzonik.GiveW("NAns"), dzonik.NAnsSize);
        AnsSize2 = 0;
        free(UserAns2);
        UserAns2 = EnterUntilEnter(&AnsSize2);
        *UserAns2 = tolower(*UserAns2);
        }

    if(*UserAns2 != '�' && *UserAns2 != 'y')
        {
        MNode_Binar_t* Tmp = ToThatNode->Right;
        ToThatNode->Right = ToThatNode->Left;
        ToThatNode->Left = Tmp;
        }
    // i pod konec govorit sps za infy

    SayKot(dzonik.GiveW("GoodBye"), dzonik.GoodByeSize);
    scanf("%*c");
    return 1;
    }

char* EnterUntilEnter(int* AnsSize)
    {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,".1251");

    fflush(stdin);
    int SizeOfTmp    = 1;
    int ReservedChar = 0;
    char* tmp = (char*) calloc(SizeOfTmp, sizeof(char));
    char TmpToBuff;
    while(*(tmp + ReservedChar - 1) != '\n' && *(tmp + ReservedChar - 1) != '?')
        {
        (TmpToBuff = getchar());
        *(tmp + ReservedChar) = TmpToBuff;
        ++ReservedChar;
        if(ReservedChar >= SizeOfTmp)
            {
            SizeOfTmp *= 2;
            tmp = (char*) realloc(tmp, SizeOfTmp * sizeof(char));
            }
        }
    --ReservedChar;
    *(tmp + ReservedChar) = '\0';
    tmp = (char*) realloc(tmp, (ReservedChar + 1) * sizeof(char));

    *AnsSize = ReservedChar;
    return tmp;
    }

bool AkinatorMenu()
    {
    int Ans = 0;

    while(Ans != 1)
        {

        DEBMTree_t(AkinatorTree);
        FILE* akinator = fopen("systemfiles\\akinator.txt", "rb");
        fseek(akinator, 0, SEEK_END);
        long SizeTree = ftell(akinator);
        rewind(akinator);
        char* AkinatorBuffer = (char*) calloc(SizeTree, sizeof(char));
        int i = 0;
        while(i < SizeTree)
            {
            *(AkinatorBuffer + i) = fgetc(akinator);
            ++i;
            }
        AkinatorTree.ReadTree(AkinatorBuffer);
        fclose(akinator);

        SayKot(dzonik.GiveW("Hello"), dzonik.HelloSize);
        printf("\n\n  ");
        int AnsSize = 0;
        char* UserAns = EnterUntilEnter(&AnsSize);
        *UserAns = tolower(*UserAns);
        while(*UserAns != '�' && *UserAns != 'y' && *UserAns != 'n' && *UserAns != '�')
            {
            SayKot(dzonik.GiveW("NAns"), dzonik.NAnsSize);
            AnsSize = 0;
            free(UserAns);
            UserAns = EnterUntilEnter(&AnsSize);
            *UserAns = tolower(*UserAns);
            }

        if(*UserAns != '�' && *UserAns != 'y')
            {
            SayKot(dzonik.GiveW("Menu"), dzonik.MenuSize);
            int AnsSize = 0;
            char* UserAns = EnterUntilEnter(&AnsSize);
            *UserAns = tolower(*UserAns);
            while(*UserAns < '1' || *UserAns > '4')
                {
                char a[40] = "���� ����� ������ ����� �� 1 �� 4\n\n";
                SayKot(&a[0], 70);
                AnsSize = 0;
                free(UserAns);
                UserAns = EnterUntilEnter(&AnsSize);
                *UserAns = tolower(*UserAns);
                }
            Ans = *UserAns - '0';

            switch(Ans)
                {
                case 1:
                    break;

                case 2:
                    AkinatorTree.TDUMP(8);
                    SayKot(dzonik.GiveW("GoodBye"), dzonik.GoodByeSize);
                    scanf("%*c");
                    break;

                case 3:
                    CompareWord(&AkinatorTree);
                    break;

                case 4:
                    SayKot(dzonik.GiveW("Pervoe"), dzonik.PervoeSize);
                    int AnsSize2 = 0;
                    char* UserAns2 = EnterUntilEnter(&AnsSize2);
                    while(!IsCharInTree(&AkinatorTree, UserAns2))
                        {
                        SayKot(dzonik.GiveW("Badnew"), dzonik.BNewSize);
                        AnsSize2 = 0;
                        free(UserAns2);
                        char* UserAns2 = EnterUntilEnter(&AnsSize2);
                        }

                    CharacterWord(&AkinatorTree, UserAns2);
                    break;
                }
            }
        else
            {
            GuessSth(&AkinatorTree);
            }

        char* buffer = (char*)calloc(1, sizeof(char));

        int BufferSize = 1;
        AkinatorTree.PrintTree(&buffer, &BufferSize);
        akinator = fopen("systemfiles\\akinator.txt", "wb");
        fwrite(buffer, BufferSize, sizeof(char), akinator);
        fclose(akinator);
        }
    return 1;
    }

void GuessSth(MBinaryTree_t* AkinatorTree)
    {
    char a[100] = "������� ���: �� �������� �����,\n � � ����� �������, � ���� �������.";
    SayKot(&a[0], 100);
    //wait
    MNode_Binar_t* NowNode = AkinatorTree->root;
    while(NowNode->Left != 0)
        {
        char vop[450] = "����, ";
        int i = 0;
        while(*((char*)NowNode->data + i) != '\0')
            {
            *(vop + i + 6) += *((char*)NowNode->data + i);
            ++i;
            }
        *(vop + i + 6) = '?';
        *(vop + i + 7) = '\0';
        SayKot(vop, 450);
        int AnsSize = 0;
        char* UserAns = EnterUntilEnter(&AnsSize);
        *UserAns = tolower(*UserAns);
        while(*UserAns != '�' && *UserAns != 'y' && *UserAns != 'n' && *UserAns != '�')
            {
            SayKot(dzonik.GiveW("NAns"), dzonik.NAnsSize);
            AnsSize = 0;
            free(UserAns);
            UserAns = EnterUntilEnter(&AnsSize);
            *UserAns = tolower(*UserAns);
            }
        if(*UserAns != '�' && *UserAns != 'y')
            {
            NowNode = (MNode_Binar_t*)NowNode->Right;
            }
        else
            {
            NowNode = (MNode_Binar_t*)NowNode->Left;
            }
        }

    char ok[30] = "����, �� ��� ��� ...";
    SayKot(ok, 30);

    char ot[450] = "����, �������� �: ";
    int j = 0;
    while(*((char*)NowNode->data + j) != '\0')
        {
        *(ot + j + 20) += *((char*)NowNode->data + j);
        ++j;
        }
    *(ot + j + 20) = '?';
    *(ot + j + 21) = '\0';
    SayKot(ot, 450);

    int AnsSize = 0;
    char* UserAns = EnterUntilEnter(&AnsSize);
    *UserAns = tolower(*UserAns);
    while(*UserAns != '�' && *UserAns != 'y' && *UserAns != 'n' && *UserAns != '�')
        {
        SayKot(dzonik.GiveW("NAns"), dzonik.NAnsSize);
        AnsSize = 0;
        free(UserAns);
        UserAns = EnterUntilEnter(&AnsSize);
        *UserAns = tolower(*UserAns);
        }
    if(*UserAns != '�' && *UserAns != 'y')
        {
        SayKot(dzonik.GiveW("Lose"), dzonik.LoseSize);
        CheckIfAlreadyDone(AkinatorTree, NowNode); // tam prov est li, esli net, to AddingNewNode, esli est, to govotit
        //sho ti ����� i posle CharacterWord(&AkinatorTree);
        }
    else
        {
        SayKot(dzonik.GiveW("Win"), dzonik.WinSize);
        }
    return;
    }

void CheckIfAlreadyDone(MBinaryTree_t* AkinatorTree, MNode_Binar_t* NonCorrectNode)
    {
    int AnsSize = 0;
    char* UserAns = EnterUntilEnter(&AnsSize);
    bool AlreadyInTree = IsCharInTree(AkinatorTree, UserAns);

    if(AlreadyInTree)
        {
        char a[40] = "������, ��� �����, ��� ���� ����� ��� �";
        SayKot(&a[0], 40);
        CharacterWord(AkinatorTree, UserAns);
        }
    else
        {
        SayKot(dzonik.GiveW("Add"), dzonik.AddSize);
        int AddSize = 0;
        char* AddAns = EnterUntilEnter(&AddSize);
        *AddAns = tolower(*AddAns);
        while(*AddAns != '�' && *AddAns != 'y' && *AddAns != 'n' && *AddAns != '�')
            {
            AddSize = 0;
            free(AddAns);
            SayKot(dzonik.GiveW("NAns"), dzonik.NAnsSize);
            AddAns = EnterUntilEnter(&AddSize);
            *AddAns = tolower(*AddAns);
            }
        if(*UserAns != 'n' && *UserAns != '�')
            {
            AddingNewNode(AkinatorTree, NonCorrectNode, UserAns);
            }
        }
    return;
    }

bool IsCharInTree(const MBinaryTree_t* AkinatorTree, char* UserAns)
    {
    bool AlreadyInTree = 0;

    MNode_Binar_t* NowNode;
    std::stack<MNode_Binar_t*> NodesToGo;
    NodesToGo.push(AkinatorTree->root);
    while(!NodesToGo.empty() && !AlreadyInTree)
        {
        NowNode = NodesToGo.top();
        NodesToGo.pop();
        if(NowNode->Left == (MNode_Binar_t*)0 && NowNode->Right == (MNode_Binar_t*)0)
            {
            char* TmpAns = UserAns;
            char* TmpData = (char*)NowNode->data;
            while(*TmpAns != '\0' && *TmpData != '\0' && tolower(*TmpAns) == tolower(*TmpData))
                {
                ++TmpAns;
                ++TmpData;
                }
            if(tolower(*TmpData) == tolower(*TmpAns))
                {
                //printf("1kontr:%s userans:%s %d %d %d %d %d\n", TmpData, UserAns, *TmpAns != '\0', *TmpData != '\0', tolower(*TmpAns) == tolower(*TmpData), tolower(*TmpAns), tolower(*TmpData));
                AlreadyInTree = 1;
                }
            } else
            {
            if(NowNode->Left != (MNode_Binar_t*)0)
                {
                NodesToGo.push(NowNode->Left);
                }
            if(NowNode->Right != (MNode_Binar_t*)0)
                {
                NodesToGo.push(NowNode->Right);
                }
            }
        }

    return AlreadyInTree;
    }

void CharacterWord(MBinaryTree_t* AkinatorTree, char* UserAns)
    {

    MNode_Binar_t* SearchedNode = 0;

    SearchedNode = SearchInTree(AkinatorTree, UserAns);

    assert(SearchedNode != NULL);
    MNode_Binar_t* NowNode = SearchedNode;

    std::stack<MNode_Binar_t*> NodesToGo;
    NodesToGo.push(NowNode);
    while(NowNode != AkinatorTree->root)
        {
        NodesToGo.push((MNode_Binar_t*)NowNode->Parent);
        NowNode = (MNode_Binar_t*)NowNode->Parent;
        }

    char ot[450] = "���� ����� �� ������������:\n";

    int j = 31;

    while(!NodesToGo.empty())
        {
        NowNode = NodesToGo.top();
        NodesToGo.pop();

        if(!NodesToGo.empty())
            {
            if((NodesToGo.top()) == NowNode->Left)
                {
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = ' ';
                ++j;
                int i = 0;
                while(*((char*)((NodesToGo.top())->Parent->data) + i) != '\0')
                    {
                    *(ot + j) += *((char*)((NodesToGo.top())->Parent->data) + i);
                    ++j;
                    ++i;
                    }
                *(ot + j) = '\n';
                ++j;
                }
            else
                {
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = ' ';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = ' ';
                ++j;
                int i = 0;
                while(*((char*)((NodesToGo.top())->Parent->data) + i) != '\0')
                    {
                    *(ot + j) += *((char*)((NodesToGo.top())->Parent->data) + i);
                    ++j;
                    ++i;
                    }
                *(ot + j) = '\n';
                ++j;
                }
            }
        }


    *(ot + j) = '\0';
    SayKot(ot, 450);

    Sleep(5000);
    SayKot(dzonik.GiveW("GoodBye"), dzonik.GoodByeSize);
    scanf("%*c");
    return;
    }

void CompareWord(MBinaryTree_t* AkinatorTree)
    {
    SayKot(dzonik.GiveW("Comp"), dzonik.CompSize);
    int Ans1Size = 0;
    char* UserAns1 = EnterUntilEnter(&Ans1Size);
    while(!IsCharInTree(AkinatorTree, UserAns1))
        {
        SayKot(dzonik.GiveW("Badnew"), dzonik.BNewSize);
        int Ans1Size = 0;
        free(UserAns1);
        UserAns1 = EnterUntilEnter(&Ans1Size);
        }

    MNode_Binar_t* First = SearchInTree(AkinatorTree, UserAns1);
    char vtor[50] = "�����, � ����� ������ ���?";
    SayKot(vtor, 50);
    int Ans2Size = 0;
    char UserAns2[30];
    scanf("%s", UserAns2);
    //char* UserAns2 = EnterUntilEnter(&Ans2Size);

    while(!IsCharInTree(AkinatorTree, UserAns2))
        {
        SayKot(dzonik.GiveW("Badnew"), dzonik.BNewSize);
        int Ans2Size = 0;
        scanf("%s", UserAns2);
        //free(UserAns2);
        //UserAns2 = EnterUntilEnter(&Ans2Size);
        }

    MNode_Binar_t* Second = SearchInTree(AkinatorTree, UserAns2);



    std::stack<MNode_Binar_t*> NodesFirst;
    NodesFirst.push(First);
    while(First != AkinatorTree->root)
        {
        NodesFirst.push((MNode_Binar_t*)First->Parent);
        First = (MNode_Binar_t*)First->Parent;
        }

    std::stack<MNode_Binar_t*> NodesSecond;
    NodesSecond.push(Second);

    while(Second != AkinatorTree->root)
        {
        NodesSecond.push((MNode_Binar_t*)Second->Parent);
        Second = (MNode_Binar_t*)Second->Parent;
        }

    bool flag = 1;
    bool IfHaveQual = 0;
    MNode_Binar_t* NowNode;
    char ot[650] = "�������� ����������:\n\n";

    int j = 23;

    while(flag && !NodesFirst.empty() && !NodesSecond.empty())
        {
        NowNode = NodesFirst.top();
        NodesFirst.pop();
        NodesSecond.pop();
        if(NodesFirst.top() != NodesSecond.top() || NodesFirst.empty() || NodesSecond.empty())
            {
            flag = 0;
            NodesFirst.push(NowNode);
            NodesSecond.push(NowNode);
            }
        else
            {
            IfHaveQual = 1;
            if(NodesFirst.top() == NowNode->Left)
                {
                int i = 0;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = ' ';
                ++j;
                while(*((char*)NowNode->Parent->data + i) != '\0')
                    {
                    *(ot + j) += *((char*)NowNode->Parent->data + i);
                    ++j;
                    ++i;
                    }
                *(ot + j) = '\n';
                ++j;
                }
            else
                {
                int i = 0;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = ' ';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = '�';
                ++j;
                *(ot + j) = ' ';
                ++j;
                while(*((char*)NowNode->Parent->data + i) != '\0')
                    {
                    *(ot + j) += *((char*)NowNode->Parent->data + i);
                    ++j;
                    ++i;
                    }
                *(ot + j) = '\n';
                ++j;
                }
            }
        }
    *(ot + j) = '\0';
    if(IfHaveQual)
        {
        SayKot(ot, 650);
        Sleep(6000);
        }

    char per[450] = "�������������� ";

    int p = 15;

    if(!NodesFirst.empty())
        {
        int i = 0;
        while(*(UserAns1 + i) != '\0')
            {
            *(per + p) = *(UserAns1 + i);
            ++p;
            ++i;
            }
        *(per + p) = '\n';
        ++p;
        *(per + p) = '\n';
        ++p;
        }

    while(!NodesFirst.empty())
        {
        NowNode = NodesFirst.top();
        NodesFirst.pop();
        if(!NodesFirst.empty())
            {
            if(NodesFirst.top() == NowNode->Left)
                {
                int i = 0;
                *(per + p) = '�';
                ++p;
                *(per + p) = '�';
                ++p;
                *(per + p) = ' ';
                ++p;
                while(*((char*)NowNode->Parent->data + i) != '\0')
                    {
                    *(per + p) += *((char*)NowNode->Parent->data + i);
                    ++p;
                    ++i;
                    }
                *(per + p) = '\n';
                ++p;
                }
            else
                {
                int i = 0;
                *(per + p) = '�';
                ++p;
                *(per + p) = '�';
                ++p;
                *(per + p) = ' ';
                ++p;
                *(per + p) = '�';
                ++p;
                *(per + p) = '�';
                ++p;
                *(per + p) = ' ';
                ++p;
                while(*((char*)NowNode->Parent->data + i) != '\0')
                    {
                    *(per + p) += *((char*)NowNode->Parent->data + i);
                    ++p;
                    ++i;
                    }
                *(per + p) = '\n';
                ++p;
                }
            }
        }
    *(per + p) = '\0';
    ++p;
    SayKot(per, 450);
    Sleep(6000);
    char vtors[450] = "�������������� ";

    p = 15;

    if(!NodesSecond.empty())
        {
        int i = 0;
        while(*(UserAns2 + i) != '\0')
            {
            *(vtors + p) = *(UserAns2 + i);
            ++p;
            ++i;
            }
        *(vtors + p) = '\n';
        ++p;
        *(vtors + p) = '\n';
        ++p;
        }
    while(!NodesSecond.empty())
        {
        NowNode = NodesSecond.top();
        NodesSecond.pop();
        if(!NodesSecond.empty())
            {
            if(NodesSecond.top() == NowNode->Left)
                {
                int i = 0;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = ' ';
                ++p;
                while(*((char*)NowNode->Parent->data + i) != '\0')
                    {
                    *(vtors + p) += *((char*)NowNode->Parent->data + i);
                    ++p;
                    ++i;
                    }
                *(vtors + p) = '\n';
                ++p;
                }
            else
                {
                int i = 0;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = ' ';
                ++p;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = '�';
                ++p;
                *(vtors + p) = ' ';
                ++p;
                while(*((char*)NowNode->Parent->data + i) != '\0')
                    {
                    *(vtors + p) += *((char*)NowNode->Parent->data + i);
                    ++p;
                    ++i;
                    }
                *(vtors + p) = '\n';
                ++p;
                }
            }
        }

    *(vtor + p) = '\0';
    ++p;
    SayKot(vtor, 450);
    Sleep(6000);
    SayKot(dzonik.GiveW("GoodBye"), dzonik.GoodByeSize);
    scanf("%*c");
    return;
    }

MNode_Binar_t* SearchInTree(MBinaryTree_t* AkinatorTree, char* UserAns)
    {
    MNode_Binar_t* NowNode;
    MNode_Binar_t* SearchedNode = 0;
    std::stack<MNode_Binar_t*> NodesToGo;
    NodesToGo.push(AkinatorTree->root);
    while(!NodesToGo.empty())
        {
        NowNode = NodesToGo.top();
        NodesToGo.pop();
        if(NowNode->Left == (MNode_Binar_t*)0 && NowNode->Right == (MNode_Binar_t*)0)
            {
            char* TmpAns = UserAns;
            char* TmpData = (char*)NowNode->data;
            while(*TmpAns != '\0' && *TmpData != '\0' && tolower(*TmpAns) == tolower(*TmpData))
                {
                ++TmpAns;
                ++TmpData;
                }
            if(tolower(*TmpData) == tolower(*TmpAns))
                {
                SearchedNode = NowNode;
                }
            } else
            {
            if(NowNode->Left != (MNode_Binar_t*)0)
                {
                NodesToGo.push(NowNode->Left);
                }
            if(NowNode->Right != (MNode_Binar_t*)0)
                {
                NodesToGo.push(NowNode->Right);
                }
            }
        }

    return SearchedNode;
    }
