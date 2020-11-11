#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define D_LINE_TABLE_MAX                20

typedef struct LINE_TABLE_T
{
    int LineBuffer[D_LINE_TABLE_MAX];
    int LineTableLen;
}LineTable_t;

static LineTable_t LineTable = {{0}, 0};

void DeleteRepeatValue(void)
{
    int i = 0;
    int j = 0;
    int compareValue = 0;
    int cnt = 1;

    if ((LineTable.LineTableLen == 0) || (LineTable.LineTableLen == 1))
    {
        return;
    }

    for (j = 0; j < LineTable.LineTableLen; j++)
    {
        cnt = j + 1;
        compareValue = LineTable.LineBuffer[j];
        for (i = cnt; i < LineTable.LineTableLen; i++)
        {
            if (LineTable.LineBuffer[i] != compareValue)
            {
                LineTable.LineBuffer[cnt] = LineTable.LineBuffer[i];
                cnt++;
            }
        }
        LineTable.LineTableLen = cnt;
    }

}

void PrintLineTable(void)
{
    printf("\nTable value :\t");
    for (int i = 0; i < LineTable.LineTableLen; i++)
    {
        printf("%d\t", LineTable.LineBuffer[i]);
    }
    printf("\n");
}


int main(void)
{
    LineTable.LineTableLen = 5;
    LineTable.LineBuffer[0] = 1;
    LineTable.LineBuffer[1] = 2;
    LineTable.LineBuffer[2] = 3;
    LineTable.LineBuffer[3] = 4;
    LineTable.LineBuffer[4] = 5;

    DeleteRepeatValue();
    PrintLineTable();

    LineTable.LineTableLen = 5;
    LineTable.LineBuffer[0] = 1;
    LineTable.LineBuffer[1] = 1;
    LineTable.LineBuffer[2] = 1;
    LineTable.LineBuffer[3] = 1;
    LineTable.LineBuffer[4] = 6;

    DeleteRepeatValue();
    PrintLineTable();

    LineTable.LineTableLen = 2;
    LineTable.LineBuffer[0] = 3;
    LineTable.LineBuffer[1] = 2;
    LineTable.LineBuffer[2] = 1;
    LineTable.LineBuffer[3] = 4;
    LineTable.LineBuffer[4] = 5;

    DeleteRepeatValue();
    PrintLineTable();

    return 0;
}

