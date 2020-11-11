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

void FindInsertData(int x)
{
    int i = 0;
    int indexRecord = 65535;
    int j = 0;

    for (i = 0; i < LineTable.LineTableLen; i++)
    {
        if (x == LineTable.LineBuffer[i])
        {
            if ((i + 1) < LineTable.LineTableLen)
            {
                LineTable.LineBuffer[i] = LineTable.LineBuffer[i+1];
            }

            LineTable.LineBuffer[i+1] = x;
            return;
        }

        if (x < LineTable.LineBuffer[i])
        {
            for (j = LineTable.LineTableLen; j > i; j--)
            {
                LineTable.LineBuffer[j] = LineTable.LineBuffer[j-1];
            }
            break;
        }
    }

    if (indexRecord == 65535)
    {
        indexRecord = i;
    }
    LineTable.LineBuffer[indexRecord] = x;
    LineTable.LineTableLen++;
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

    FindInsertData(5);
    PrintLineTable();

    FindInsertData(1);
    PrintLineTable();

    FindInsertData(55);
    PrintLineTable();

    FindInsertData(51);
    PrintLineTable();

    FindInsertData(-1);
    PrintLineTable();

    FindInsertData(91);
    PrintLineTable();

    return 0;
}



