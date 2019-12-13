#include <cstdio>

#include "MTree.h"

int main()
{
    DEBMTree_t( TestTreee );
    FILE* fp = fopen("testtree.txt", "r");

    char tmp;
    int StrSize = 0;
    tmp = (char)fgetc(fp);
    while((tmp != EOF))
        {
        ++StrSize;
        tmp = (char)fgetc(fp);
        }
    rewind(fp);

    char* buffer = (char*)calloc(StrSize + 1, sizeof(char));
    for(int i = 0; i < StrSize; ++i)
        {
        *(buffer + i) = (char)fgetc(fp);
        }
    *(buffer + StrSize) = '\0';

    TestTreee.ReadTree(buffer);
    TestTreee.TDUMP(9);
    free(buffer);
    buffer = (char*)calloc(1, sizeof(char));

    int BufferSize = 1;
    TestTreee.PrintTree(&buffer, &BufferSize);
    fclose(fp);
    fp = fopen("outputtree.txt", "w");
    fprintf(fp, "%s", buffer);
    return 0;
}
