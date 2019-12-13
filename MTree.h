#include <algorithm>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <stack>

#include "RecursiveEnter.h"

#ifdef _DEBUG
    #define DEBMTree_t( tree ) MBinaryTree_t tree( #tree )

    #define DEB( code ) code
#else
    #define DEB( code )

    #define DEBMTree_t( tree )
#endif

const std::string DotPath = "\"C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe\"";
const std::string AkinatorPath = "C:\\Users\\MI Pro-15\\Documents\\GitHub\\Akinator\\";

struct MBinaryTree_t
    {
    DEB(int NumOfDumps);
    DEB(int TreeSize);
    DEB(std::string TreeName);
    MNode_Binar_t* root;
    #ifdef _DEBUG
    MBinaryTree_t(std::string Name);
    #else
    MBinaryTree_t();
    #endif

    bool ReadTree(char* buffer);

    bool NewNode(MNode_Binar_t* Parnt, bool IsRight);

    bool DeleteNode(MNode_Binar_t* DelNode, MNode_Binar_t** LeftSubTree = (MNode_Binar_t**)3, MNode_Binar_t** RightSubTree = (MNode_Binar_t**)3);

    DEB(bool Verify());

    DEB(void TDUMP(int err));

    int PrintTree(char** buffer, int* BuffSize, MNode_Binar_t* NowNode = (MNode_Binar_t*)3, int BShift = 0);

    void BuffCheck(char** buffer, int* BuffSize, int BShift);

    ~MBinaryTree_t();
    };

#ifdef _DEBUG
MBinaryTree_t::MBinaryTree_t( std::string Name )
    {
    TreeName = Name;
    TreeSize = 0;
    NumOfDumps = 0;

    root = 0;
    return;
    }
#else
MBinaryTree_t::MBinaryTree_t()
    {
    root = 0;

    return;
    }
#endif

MBinaryTree_t::~MBinaryTree_t()
    {
    DEB(MBinaryTree_t::Verify());

    if(root != 0)
        {
        delete root;
        }

    DEB(TreeSize = -1); // it's like it's dead, like destructed you knawww
    return;
    }

bool MBinaryTree_t::ReadTree(char* buffer)
    {
    MBinaryTree_t::NewNode((MNode_Binar_t*)0, 1);
    int TmpSize = MBT_r::RecursRead(root, buffer);
    DEB(TreeSize = TmpSize);
    return 1;
    }

int MBinaryTree_t::PrintTree(char** buffer, int* BuffSize, MNode_Binar_t* NowNode, int BShift)
    {
    if(*buffer == 0)
        {
        *buffer = (char*) calloc(1, sizeof(char));
        *BuffSize = 1;
        }
    if(NowNode == (MNode_Binar_t*)3)
        {
        NowNode = root;
        }
    bool IsPrintOk = 1;

    BuffCheck(buffer, BuffSize, BShift);
    *(*buffer + BShift) = '{';
    ++BShift;
    BuffCheck(buffer, BuffSize, BShift);
    *(*buffer + BShift) = ' ';
    ++BShift;
    BuffCheck(buffer, BuffSize, BShift);
    *(*buffer + BShift) = '\"';
    ++BShift;
    char* NowByteOfData = (char*)NowNode->data;
    while(*NowByteOfData != '\0')
        {
        BuffCheck(buffer, BuffSize, BShift);
        *(*buffer + BShift) = *NowByteOfData;
        ++BShift;
        ++NowByteOfData;
        }
    BuffCheck(buffer, BuffSize, BShift);
    *(*buffer + BShift) = (char)'\"';
    ++BShift;

    if(NowNode->Left == (MNode_Binar_t*)0 && NowNode->Right == (MNode_Binar_t*)0)
        {
        BuffCheck(buffer, BuffSize, BShift);
        *(*buffer + BShift) = ' ';
        ++BShift;
        BuffCheck(buffer, BuffSize, BShift);
        *(*buffer + BShift) = '}';
        ++BShift;
        return BShift;
        } else
        {
        BuffCheck(buffer, BuffSize, BShift);
        *(*buffer + BShift) = ' ';
        ++BShift;
        if(NowNode->Left == (MNode_Binar_t*)0)
            {
            BuffCheck(buffer, BuffSize, BShift);
            *(*buffer + BShift) = '$';
            ++BShift;
            } else
            {
            BShift = MBinaryTree_t::PrintTree(buffer, BuffSize, NowNode->Left, BShift);
            }
        BuffCheck(buffer, BuffSize, BShift);
        *(*buffer + BShift) = ' ';
        ++BShift;
        if(NowNode->Right == (MNode_Binar_t*)0)
            {
            BuffCheck(buffer, BuffSize, BShift);
            *(*buffer + BShift) = '$';
            ++BShift;
            } else
            {
            BShift = MBinaryTree_t::PrintTree(buffer, BuffSize, NowNode->Right, BShift);
            }
        BuffCheck(buffer, BuffSize, BShift);
        *(*buffer + BShift) = ' ';
        ++BShift;
        }
    BuffCheck(buffer, BuffSize, BShift);
    *(*buffer + BShift) = '}';
    ++BShift;
    if(NowNode == root)
        {
        BuffCheck(buffer, BuffSize, BShift);
        *(*buffer + BShift) = '\0';
        ++BShift;
        *BuffSize = BShift;
        *buffer = (char*) realloc(*buffer, *BuffSize * sizeof(char));
        }
    return BShift;
    }

bool MBinaryTree_t::NewNode(MNode_Binar_t* Parnt, bool IsRight)
    {
    if(root == 0)
        {
        DEB(++TreeSize);
        root = new MNode_Binar_t('C', 0);
        } else
        {
        if(IsRight)
            {
            if(Parnt->Right == 0)
                {
                Parnt->Right = new MNode_Binar_t('C', Parnt);
                DEB(++TreeSize);
                } else
                {
                return 0;
                }
            } else
            {
            if(Parnt->Left == 0)
                {
                Parnt->Left = new MNode_Binar_t('C', Parnt);
                DEB(++TreeSize);
                } else
                {
                return 0;
                }
            }
        }
    return 1;
    }

bool MBinaryTree_t::DeleteNode(MNode_Binar_t* DelNode, MNode_Binar_t** LeftSubTree, MNode_Binar_t** RightSubTree)
    {
    if(LeftSubTree != (MNode_Binar_t**)3)
        {
        *LeftSubTree = DelNode->Left;
        DelNode->Left = 0;
        }
    if(RightSubTree != (MNode_Binar_t**)3)
        {
        *RightSubTree = DelNode->Right;
        DelNode->Right = 0;
        }
    delete DelNode;
    return 1;
    }

#ifdef _DEBUG
    bool MBinaryTree_t::Verify()
        {
        std::stack<MNode_Binar_t*> NodesToGo;
        MNode_Binar_t* NowNode = root;
        int NowSize = 0;
        if(root != 0)
            {
            NodesToGo.push(root);
            }

        while(!NodesToGo.empty())
            {
            ++NowSize;
            NowNode = NodesToGo.top();
            NodesToGo.pop();

            if(NowNode->Left != 0)
                {
                NodesToGo.push(NowNode->Left);
                }
            if(NowNode->Right != 0)
                {
                NodesToGo.push(NowNode->Right);
                }
            }

        if(NowSize < TreeSize)
            {
            MBinaryTree_t::TDUMP(1); // Tree lost some nodes
            }

        if(NowSize > TreeSize)
            {
            MBinaryTree_t::TDUMP(2); // Tree have some extra nodes
            }


        return 1; // if err 9 :: it's just printing the list
        }
#endif


#ifdef _DEBUG
    void MBinaryTree_t::TDUMP(int err)
        {
        FILE* LDot;
        std::string DTime;
        std::string NewPath;

        time_t now = std::chrono::system_clock::to_time_t ( std::chrono::system_clock::now() );

        if(err == 8)
            {
            DTime = "Print_Of_Akinator_Tree";
            }
        else
            {
            if(err == 9)
                {
                DTime = "debug_tree";
                }
            else
                {
                std::string CritStr = "crit_err_tree_";
                char ErrStr[17];
                itoa(err, ErrStr, 10);
                CritStr += ErrStr;
                DTime += CritStr;
                }
            DTime += "_";
            DTime += TreeName;
            DTime += "_";
            DTime += ctime(&now);
            DTime += "#";
            char HashStr[17];
            ++NumOfDumps;
            itoa(NumOfDumps, HashStr, 10);
            DTime += HashStr;
            }
        DTime += ".dot";
        while(DTime.find('\n') != std::string::npos)
            {
            DTime.erase(DTime.find('\n'), 1);
            }
        int tmp = DTime.find(' ');
        while(tmp != std::string::npos)
            {
            //DTime.erase(DTime.find(' '), 1);
            DTime[DTime.find(' ')] = '_';
            tmp = DTime.find(' ');
            }
        tmp = DTime.find(':');
        while(tmp != std::string::npos)
            {
            //DTime.erase(DTime.find(   ':'), 1);
            DTime[DTime.find(':')] = '_';
            tmp = DTime.find(':');
            }

        DTime.erase(DTime.find(".dot"));
        std::string MKDIR = "mkdir " + DTime;
        std::system(MKDIR.c_str());
        NewPath = DTime;
        NewPath += "\\TMP";
        DTime += ".dot";
        NewPath += DTime;

        LDot = fopen(NewPath.c_str(), "w");
        assert(LDot != NULL);

        fprintf(LDot, "digraph G{\nnode [fontname=\"Lobster\", fontsize=25];\n");

        MNode_Binar_t* NowNode = root;
        fprintf(LDot, "rankdir=HR;\n");

        fprintf(LDot, "subgraph clusterlist {\nstyle=filled;\ncolor=lightgrey;\n");
        fprintf(LDot, "%d [shape=record, label=\"{Number of tree nodes: | %d} | {NodePointer:  | %x} | {ParentPointer: | %x} | {data: | %s} | {Left: | Right:} | {%x | %x}\",style=\"filled\",fillcolor=\"orange\"];\n", NowNode, TreeSize, NowNode, NowNode->Parent, (char*)NowNode->data, NowNode->Left, NowNode->Right);

        std::stack<MNode_Binar_t*> NodesToGo;
        if(root != 0)
            {
            if(root->Left != (MNode_Binar_t*)0)
                {
                NodesToGo.push(root->Left);
                fprintf(LDot, "%d->%d[dir=\"both\";style=\"bold\"];\n", NowNode, NowNode->Left);
                }
            if(root->Right != (MNode_Binar_t*)0)
                {
                NodesToGo.push(root->Right);
                fprintf(LDot, "%d->%d[dir=\"both\";style=\"bold\"];\n", NowNode, NowNode->Right);
                }
            }

        while(!NodesToGo.empty())
            {
            NowNode = NodesToGo.top();
            NodesToGo.pop();
            if(NowNode->Left == (MNode_Binar_t*)0 && NowNode->Right == (MNode_Binar_t*)0)
                {
                if(NowNode->Parent->Left == NowNode)
                    {
                    fprintf(LDot, "%d [shape=record, label=\"{NodePointer:  | %x} | {ParentPointer: | %x} | {data: | %s} | {Left: | Right:} | {%x | %x}\",style=\"filled\",fillcolor=\"seagreen2\"];\n", NowNode, NowNode, NowNode->Parent, (char*)NowNode->data, NowNode->Left, NowNode->Right);
                    } else
                    {
                    fprintf(LDot, "%d [shape=record, label=\"{NodePointer:  | %x} | {ParentPointer: | %x} | {data: | %s} | {Left: | Right:} | {%x | %x}\",style=\"filled\",fillcolor=\"salmon2\"];\n", NowNode, NowNode, NowNode->Parent, (char*)NowNode->data, NowNode->Left, NowNode->Right);
                    }
                } else
                {
                if(NowNode->Parent->Left == NowNode)
                    {
                    fprintf(LDot, "%d [shape=record, label=\"{NodePointer:  | %x} | {ParentPointer: | %x} | {data: | %s} | {Left: | Right:} | {%x | %x}\",style=\"filled\",fillcolor=\"springgreen3\"];\n", NowNode, NowNode, NowNode->Parent, (char*)NowNode->data, NowNode->Left, NowNode->Right);
                    } else
                    {
                    fprintf(LDot, "%d [shape=record, label=\"{NodePointer:  | %x} | {ParentPointer: | %x} | {data: | %s} | {Left: | Right:} | {%x | %x}\",style=\"filled\",fillcolor=\"tomato3\"];\n", NowNode, NowNode, NowNode->Parent, (char*)NowNode->data, NowNode->Left, NowNode->Right);
                    }

                if(NowNode->Left != (MNode_Binar_t*)0)
                    {
                    NodesToGo.push(NowNode->Left);
                    fprintf(LDot, "%d->%d[dir=\"both\";style=\"bold\"];\n", NowNode, NowNode->Left);
                    }
                if(NowNode->Right != (MNode_Binar_t*)0)
                    {
                    NodesToGo.push(NowNode->Right);
                    fprintf(LDot, "%d->%d[dir=\"both\";style=\"bold\"];\n", NowNode, NowNode->Right);
                    }
                }
            }
        fprintf(LDot, "label = \"Tree with name: %s\"}\n", TreeName.c_str());
        fprintf(LDot, "}\n");
        fclose(LDot);

        std::string ConvertDot;
        ConvertDot += " powershell -command \"get-content -path ";
        ConvertDot += NewPath;
        ConvertDot += " | out-file ";
        NewPath.erase(NewPath.rfind("TMP"), 3);
        ConvertDot += NewPath;
        ConvertDot += " -encoding utf8\"";
        HWND hwnd;
        //ShellExecute(hwnd, "open", "cmd", ConvertDot.c_str(), NULL, SW_HIDE);
        std::system(ConvertDot.c_str());

        std::string* TmpStrS = new std::string;
        *TmpStrS = AkinatorPath + NewPath;
        FILE* TmpFile = fopen((*TmpStrS).c_str(), "rb");
        int FSize = 0;
        fseek(TmpFile, 0, SEEK_END);
        FSize = ftell(TmpFile);
        rewind(TmpFile);
        char* buff = (char*) calloc(FSize, sizeof(char));
        fread(buff, sizeof(char), FSize, TmpFile);
        fclose(TmpFile);
        TmpFile = fopen((*TmpStrS).c_str(), "wb");
        fwrite((buff + 3), sizeof(char), (FSize - 3), TmpFile);
        fclose(TmpFile);
        delete(TmpStrS);

        std::string DotDoDot;
        DotDoDot += DotPath;
        DotDoDot += " -Tpng ";
        DotDoDot += NewPath;
        DotDoDot += " -o ";
        NewPath.erase(NewPath.rfind(".dot"));
        DotDoDot += NewPath;
        DotDoDot += ".png";
        std::system(DotDoDot.c_str());
        return;
        }
#endif

void MBinaryTree_t::BuffCheck(char** buffer, int* BuffSize, int BShift)
    {
    if(*BuffSize <= BShift)
        {
        *BuffSize *= 2;
        *buffer = (char*) realloc(*buffer, sizeof(char) * *BuffSize);
        }
    return;
    }
