#include <conio.h>

#include "SayKat.h"
#include "MTree.h"
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

int main()
    {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,".1251");
    /*
    char* text = (char*) calloc(100, sizeof(char));

    text = "Вітаю тебе, друже мій милий, не бажаєш зіграти?";
    long SizeOfBase = 0;
    while(*(text + SizeOfBase) != '\0')
        {
        ++SizeOfBase;
        }


    FILE* Base = fopen("base.txt", "wb");
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

    text = "Як скажеш, ну тоді\nДо побачення, друже, ти заходь,\nякщо що, разом поугадивать що-небудь...";
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
    NewAns = "Лукашов(Ліктор по матану)";

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
            }

        FILE* fp = fopen(openfile.c_str(), "rb");
        fseek(fp, 0, SEEK_END);
        int RealSizeOfBuffer = ftell(fp);
        rewind(fp);
        int SizeOfBuffer = 0;
        int NowPhraze    = 2;
        char* buffer     = (char*) calloc(SizeOfBuffer, sizeof(char));
        int* SizeArray   = (int*)  calloc(NowPhraze, sizeof(int));

        while(SizeOfBuffer < RealSizeOfBuffer)
            {
            RealSizeOfBuffer        -= sizeof(long);
            long TmpLong             = 0;
            fread(&TmpLong, sizeof(long), 1, fp);
            SizeOfBuffer            += TmpLong;
            buffer                   = (char*) realloc(buffer, SizeOfBuffer * sizeof(char));
            SizeArray                = (int*)  realloc(SizeArray, NowPhraze * sizeof(int));
            *(SizeArray + NowPhraze) = TmpLong;
            fread((buffer + SizeOfBuffer), sizeof(char), SizeOfBuffer, fp);
            ++NowPhraze;
            }
        *(SizeArray + NowPhraze) = 0;

        fclose(fp);
        fp = fopen(openfile.c_str(), "wb");

        long NowPrinted = 1;
        while(*(SizeArray + NowPrinted) != 0)
            {
            fwrite((SizeArray + NowPrinted), sizeof(long), 1, fp);
            fwrite((buffer + *(SizeArray + NowPrinted - 1)), sizeof(char), *(SizeArray + NowPrinted), fp);
            }
        fwrite(&SizeOfText, sizeof(long), 1, fp);
        fwrite(text, sizeof(char), SizeOfText, fp);

        fclose(fp);
        return 1;
        }
#endif

bool AddingNewNode(MBinaryTree_t* Akin, MNode_Binar_t* ToThatNode, char* NewAns)
    {
    MNode_Binar_t* NewQuas = new MNode_Binar_t('C', ToThatNode->Parent);
    printf("(Kak pravilno stroit vopros)\nand napishite entot vopros\n");
    //Обїяснение от кота как правильно строить вопрос(тип без усяких не и тд)
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
    //дальше кіт спрашивает тип правильно ли, шо ответ на NewQuastion является НьюАнс, или поменять?
    //по ответу дальше строится меняется ли та и та местами или нет
    printf("Правильно ли, шо ответ на вопрос:\"%s?\" є ", (char*)ToThatNode->data);
    printf("\"%s\"\n", (char*)(ToThatNode->Left)->data);
    int AnsSize2 = 0;
    char* UserAns2 = EnterUntilEnter(&AnsSize2);
    *UserAns2 = tolower(*UserAns2);

    while(*UserAns2 != 'д' && *UserAns2 != 'y' && *UserAns2 != 'n' && *UserAns2 != 'н')
        {
        printf("Ti ne ponial, na atot vopros nyzhno otvetit da ili net!\n");
        AnsSize2 = 0;
        free(UserAns2);
        UserAns2 = EnterUntilEnter(&AnsSize2);
        *UserAns2 = tolower(*UserAns2);
        }

    if(*UserAns2 != 'д' && *UserAns2 != 'y')
        {
        MNode_Binar_t* Tmp = ToThatNode->Right;
        ToThatNode->Right = ToThatNode->Left;
        ToThatNode->Left = Tmp;
        }
    // i pod konec govorit sps za infy
    printf("Spasibo za infy\n");
    printf("nazhmite probel, chtobi prodolzhit");
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

        printf("Прівіт!\nСыграем?\n");
        int AnsSize = 0;
        char* UserAns = EnterUntilEnter(&AnsSize);
        *UserAns = tolower(*UserAns);
        while(*UserAns != 'д' && *UserAns != 'y' && *UserAns != 'n' && *UserAns != 'н')
            {
            printf("Ti ne ponial, na atot vopros nyzhno otvetit da ili net!\n");
            AnsSize = 0;
            free(UserAns);
            UserAns = EnterUntilEnter(&AnsSize);
            *UserAns = tolower(*UserAns);
            }

        if(*UserAns != 'д' && *UserAns != 'y')
            {
            printf("А что тогда хочешь делать?\n 1 Выйти(не в окно) \n 2 вывести всё дерево \n 3 сравнить два слова \n 4 получить хар-ку слова\n");
            int AnsSize = 0;
            char* UserAns = EnterUntilEnter(&AnsSize);
            *UserAns = tolower(*UserAns);
            while(*UserAns < '1' || *UserAns > '4')
                {
                printf("Ti ne ponial, na atot vopros nyzhno otvetit da ili net!\n");
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
                    printf("nazhmite probel, chtobi prodolzhit");
                    scanf("%*c");
                    break;

                case 3:
                    CompareWord(&AkinatorTree);
                    break;

                case 4:
                    printf("Vvedite slovo\n");
                    int AnsSize2 = 0;
                    char* UserAns2 = EnterUntilEnter(&AnsSize2);
                    while(!IsCharInTree(&AkinatorTree, UserAns2))
                        {
                        printf("Takogo slova ia ne znayu, hvatit vidumivat(pro otseystvie)\ndavay zanovo!(zanovo)");
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
    printf("Загадай слово, а я его легчайше отгадаю");
    //wait
    MNode_Binar_t* NowNode = AkinatorTree->root;
    while(NowNode->Left != 0)
        {
        printf("Vopros: %s?", (char*)NowNode->data);
        int AnsSize = 0;
        char* UserAns = EnterUntilEnter(&AnsSize);
        *UserAns = tolower(*UserAns);
        while(*UserAns != 'д' && *UserAns != 'y' && *UserAns != 'n' && *UserAns != 'н')
            {
            printf("Ti ne ponial, na atot vopros nyzhno otvetit da ili net!\n");
            AnsSize = 0;
            free(UserAns);
            UserAns = EnterUntilEnter(&AnsSize);
            *UserAns = tolower(*UserAns);
            }
        if(*UserAns != 'д' && *UserAns != 'y')
            {
            NowNode = (MNode_Binar_t*)NowNode->Right;
            }
        else
            {
            NowNode = (MNode_Binar_t*)NowNode->Left;
            }
        printf("Okey, chto tam dalshe...(v pary variaciah)");
        }

    printf("Vash otvet: %s\nNe tak li?", (char*)NowNode->data);
    int AnsSize = 0;
    char* UserAns = EnterUntilEnter(&AnsSize);
    *UserAns = tolower(*UserAns);
    while(*UserAns != 'д' && *UserAns != 'y' && *UserAns != 'n' && *UserAns != 'н')
        {
        printf("Ti ne ponial, na atot vopros nyzhno otvetit da ili net!\n");
        AnsSize = 0;
        free(UserAns);
        UserAns = EnterUntilEnter(&AnsSize);
        *UserAns = tolower(*UserAns);
        }
    if(*UserAns != 'д' && *UserAns != 'y')
        {
        printf("Okey, a chto zhe ato togda?");
        CheckIfAlreadyDone(AkinatorTree, NowNode); // tam prov est li, esli net, to AddingNewNode, esli est, to govotit
        //sho ti debil blyat i posle CharacterWord(&AkinatorTree);
        }
    else
        {
        printf("Legchayshe otgadano, luchsheb po-slozhnee pridumal b(v varuaciah)");
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
        printf("Дядь тут такое слово уже есть кек б вот какая его характеристика:\n");
        CharacterWord(AkinatorTree, UserAns);
        }
    else
        {
        printf("Ты хош его добавить в базу?");
        int AddSize = 0;
        char* AddAns = EnterUntilEnter(&AddSize);
        *AddAns = tolower(*AddAns);
        while(*AddAns != 'д' && *AddAns != 'y' && *AddAns != 'n' && *AddAns != 'н')
            {
            AddSize = 0;
            free(AddAns);
            printf("Ti ne ponial, na atot vopros nyzhno otvetit da ili net!\n");
            AddAns = EnterUntilEnter(&AddSize);
            *AddAns = tolower(*AddAns);
            }
        if(*UserAns != 'n' && *UserAns != 'н')
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
    printf("Ny Chtozh solnyshko, vot tebe i har-ka tvoego slova:\n");

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
    printf("Dannoe slovo imeet takyu har-ky:\n");
    while(!NodesToGo.empty())
        {
        NowNode = NodesToGo.top();
        NodesToGo.pop();

        if(!NodesToGo.empty())
            {
            if((NodesToGo.top()) == NowNode->Right)
                {
                printf("це %s\n", (char*)((NodesToGo.top())->data));
                }
            else
                {
                printf("це НЕ %s\n", (char*)((NodesToGo.top())->data));
                }
            }
        }
    printf("nazhmite probel, chtobi prodolzhit");
    scanf("%*c");
    return;
    }

void CompareWord(MBinaryTree_t* AkinatorTree)
    {
    printf("Vvedite pershoe slovo\n");
    int Ans1Size = 0;
    char* UserAns1 = EnterUntilEnter(&Ans1Size);
    while(!IsCharInTree(AkinatorTree, UserAns1))
        {
        printf("Takogo slova ia ne znayu, hvatit vidumivat(pro otseystvie)\ndavay zanovo!(zanovo)");
        int Ans1Size = 0;
        free(UserAns1);
        UserAns1 = EnterUntilEnter(&Ans1Size);
        }

    MNode_Binar_t* First = SearchInTree(AkinatorTree, UserAns1);
    printf("Vvedite второе slovo\n");
    int Ans2Size = 0;
    char* UserAns2 = EnterUntilEnter(&Ans2Size);
    while(!IsCharInTree(AkinatorTree, UserAns2))
        {
        printf("Takogo slova ia ne znayu, hvatit vidumivat(pro otseystvie)\ndavay zanovo!(zanovo)");
        int Ans2Size = 0;
        free(UserAns2);
        UserAns2 = EnterUntilEnter(&Ans2Size);
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

    MNode_Binar_t* NowNode;
    printf("Obshie svoyctva:\n\n");
    while(flag && !NodesFirst.empty() && !NodesSecond.empty())
        {
        NowNode = NodesFirst.top();
        NodesFirst.pop();
        NodesSecond.pop();
        if(NodesFirst.top() != NodesSecond.top() || NodesFirst.empty() || NodesSecond.empty())
            {
            flag = 0;
            printf("\n");
            NodesFirst.push(NowNode);
            NodesSecond.push(NowNode);
            }
        else
            {
            if(NodesFirst.top() == NowNode->Left)
                {
                printf("вони %s\n", (char*)NowNode->data);
                }
            else
                {
                printf("вони НЕ %s\n", (char*)NowNode->data);
                }
            }
        }
    if(!NodesFirst.empty())
        {
        printf("Haracteristika %s:\n\n",UserAns1);
        }
    while(!NodesFirst.empty())
        {
        NowNode = NodesFirst.top();
        NodesFirst.pop();
        if(!NodesFirst.empty())
            {
            if(NodesFirst.top() == NowNode->Left)
                {
                printf("це %s\n", (char*)NowNode->data);
                }
            else
                {
                printf("це НЕ %s\n", (char*)NowNode->data);
                }
            }
        else
            {
            printf("\n");
            }
        }
    if(!NodesSecond.empty())
        {
        printf("Haracteristika %s:\n\n",UserAns2);
        }
    while(!NodesSecond.empty())
        {
        NowNode = NodesSecond.top();
        NodesSecond.pop();
        if(!NodesSecond.empty())
            {
            if(NodesSecond.top() == NowNode->Left)
                {
                printf("це %s\n", (char*)NowNode->data);
                }
            else
                {
                printf("це НЕ %s\n", (char*)NowNode->data);
                }
            }
        else
            {
            printf("\nVots, nazhmite enter dlya prodolzhenia");
            }
        }
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
