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

void PrintLineTable(void)
{
    printf("\nTable value :\t");
    for (int i = 0; i < LineTable.LineTableLen; i++)
    {
        printf("%d\t", LineTable.LineBuffer[i]);
    }
    printf("\n");
}

void SwapLineTableData(int m, int n)
{
    int i = 0;
    int temp = 0;
    int swapTemp = 0;

    temp = (m + n) / 2;
    for (i = 0; i < temp; i++)
    {
        swapTemp = LineTable.LineBuffer[i];
        LineTable.LineBuffer[i] = LineTable.LineBuffer[LineTable.LineTableLen - i - 1];
        LineTable.LineBuffer[LineTable.LineTableLen - i - 1] = swapTemp;
    }

    for (i = 0; i < n / 2; i++)
    {
        swapTemp = LineTable.LineBuffer[i];
        LineTable.LineBuffer[i] = LineTable.LineBuffer[n - i - 1];
        LineTable.LineBuffer[n - i - 1] = swapTemp;
    }

    for (i = 0; i < m / 2; i++)
    {
        swapTemp = LineTable.LineBuffer[LineTable.LineTableLen - m + i];
        LineTable.LineBuffer[LineTable.LineTableLen - m + i] = LineTable.LineBuffer[LineTable.LineTableLen - i - 1];
        LineTable.LineBuffer[LineTable.LineTableLen - i - 1] = swapTemp;
    }
}


int main(void)
{
    LineTable.LineTableLen = 10;
    LineTable.LineBuffer[0] = 1;
    LineTable.LineBuffer[1] = 2;
    LineTable.LineBuffer[2] = 3;
    LineTable.LineBuffer[3] = 4;
    LineTable.LineBuffer[4] = 5;
    LineTable.LineBuffer[5] = 11;
    LineTable.LineBuffer[6] = 22;
    LineTable.LineBuffer[7] = 33;
    LineTable.LineBuffer[8] = 44;
    LineTable.LineBuffer[9] = 55;

    SwapLineTableData(5,5);
    PrintLineTable();

    LineTable.LineTableLen = 10;
    LineTable.LineBuffer[0] = 1;
    LineTable.LineBuffer[1] = 2;
    LineTable.LineBuffer[2] = 3;
    LineTable.LineBuffer[3] = 4;
    LineTable.LineBuffer[4] = 15;
    LineTable.LineBuffer[5] = 16;
    LineTable.LineBuffer[6] = 22;
    LineTable.LineBuffer[7] = 33;
    LineTable.LineBuffer[8] = 44;
    LineTable.LineBuffer[9] = 55;

    SwapLineTableData(4,6);
    PrintLineTable();

    LineTable.LineTableLen = 10;
    LineTable.LineBuffer[0] = 1;
    LineTable.LineBuffer[1] = 2;
    LineTable.LineBuffer[2] = 3;
    LineTable.LineBuffer[3] = 4;
    LineTable.LineBuffer[4] = 15;
    LineTable.LineBuffer[5] = 16;
    LineTable.LineBuffer[6] = 22;
    LineTable.LineBuffer[7] = 13;
    LineTable.LineBuffer[8] = 14;
    LineTable.LineBuffer[9] = 15;

    SwapLineTableData(7,3);
    PrintLineTable();

    return 0;
}


