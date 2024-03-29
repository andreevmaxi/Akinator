#include <cstdlib>

#include "maks_node.h"

namespace MBT_r //MaxBinaryTree_read
    {
    int RecursRead(MNode_Binar_t* root, char* buffer);

    int NewLevel(MNode_Binar_t* NowNode, char** buffer, char NowPath);
    // 'f' - first(root) path
    // 'r' - right path
    // 'l' - left path

    bool Quotes(MNode_Binar_t* NowNode, char** buffer);

    bool DataRead(MNode_Binar_t* NowNode, char** buffer);

    bool BackLevel(MNode_Binar_t* NowNode, char** buffer);

    bool SpaceEater(char** buffer);

    bool PlusNode(MNode_Binar_t* Parnt, bool IsRight);
    }

int MBT_r::RecursRead(MNode_Binar_t* root, char* buffer)
    {
    int TreeSize = 0;

    while(*buffer != '\0')
        {
        SpaceEater(&buffer);
        TreeSize = NewLevel(root, &buffer, ('f'));
        }

    ++buffer;
    return TreeSize;
    }

bool MBT_r::SpaceEater(char** buffer)
    {
    while(**buffer == ' ')
        {
        ++(*buffer);
        }

    return 1;
    }

int MBT_r::NewLevel(MNode_Binar_t* NowNode, char** buffer, char NowPath)
    {
    int TreeSize = 1;

    SpaceEater(buffer);
    switch(**buffer)
        {
        case('{'):
            {
            ++(*buffer);
            SpaceEater(buffer);
            if(Quotes(NowNode, buffer))
                {
                int TmpSize = TreeSize;
                MBT_r::PlusNode(NowNode, 0);
                TreeSize += NewLevel((MNode_Binar_t*)NowNode->Left, buffer, 'l');
                if(TmpSize == TreeSize)
                    {
                    delete NowNode->Left;
                    NowNode->Left = 0;
                    }

                TmpSize = TreeSize;
                MBT_r::PlusNode(NowNode, 1);
                TreeSize += NewLevel((MNode_Binar_t*)NowNode->Right, buffer, 'r');
                if(TmpSize == TreeSize)
                    {
                    delete NowNode->Right;
                    NowNode->Right = 0;
                    }
                }
            BackLevel(NowNode, buffer);
            }
            break;

        case('$'):
            {
            ++(*buffer);
            SpaceEater(buffer);
            --TreeSize;
            }
            break;

        default:
            {
            SpaceEater(buffer);
            --TreeSize;
            }
            break;
        }
    return TreeSize;
    }

bool MBT_r::BackLevel(MNode_Binar_t* NowNode, char** buffer)
    {
    if(**buffer == '}')
        {
        ++(*buffer);
        SpaceEater(buffer);
        return 1;
        }
    else
        {
        return 0;
        }
    }

bool MBT_r::Quotes(MNode_Binar_t* NowNode, char** buffer)
    {
    assert(NowNode != 0);

    if(**buffer == *"\"")
        {
        ++(*buffer);
        DataRead(NowNode, buffer);
        if(**buffer == *"\"")
            {
            ++(*buffer);
            SpaceEater(buffer);
            return 1;
            }
        }
    return 0;
    }

bool MBT_r::DataRead(MNode_Binar_t* NowNode, char** buffer)
    {
    int DataSize = 0;
    int NowSize  = 1;
    char* TmpData = (char*)0;

    switch(NowNode->type)
        {
        case 'C': // it's char*
            {
            NowSize  = 1;
            DataSize = 0;
            TmpData = (char*)NowNode->data;
            while(**buffer != *"\"")
                {
                *TmpData = **buffer;
                ++DataSize;
                if(NowSize <= DataSize)
                    {
                    NowSize *= 2;
                    NowNode->data = realloc(NowNode->data, sizeof(char) * NowSize);
                    TmpData = (char*)NowNode->data + DataSize - 1;
                    }
                ++(*buffer);
                ++TmpData;
                }
            *TmpData = '\0';
            ++DataSize;
            if(NowSize <= DataSize)
                {
                NowSize *= 2;
                NowNode->data = realloc(NowNode->data, sizeof(char) * NowSize);
                }
            ++TmpData;
            NowNode->data = realloc(NowNode->data, sizeof(char) * DataSize);
            break;
            }
        default:
            {
            return 0;
            break;
            }
        }
    return 1;
    }

bool MBT_r::PlusNode(MNode_Binar_t* Parnt, bool IsRight)
    {
    if(IsRight)
        {
        if(Parnt->Right == 0)
            {
            Parnt->Right = new MNode_Binar_t('C', Parnt);
            } else
            {
            return 0;
            }
        } else
        {
        if(Parnt->Left == 0)
            {
            Parnt->Left = new MNode_Binar_t('C', Parnt);
            } else
            {
            return 0;
            }
        }
    return 1;
    }
