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

void DeleteRangeValue(int min, int max)
{
    int i = 0;
    int cnt = 0;

    if (min >= max)
    {
        printf("\ninput min max value error.\n");
        return;
    }

    if (LineTable.LineTableLen == 0)
    {
        printf("\nline table length is zero.\n");
        return;
    }

    for (i = 0; i < LineTable.LineTableLen; i++)
    {
        if ((LineTable.LineBuffer[i] < min)
            || (LineTable.LineBuffer[i] > max))
        {
            LineTable.LineBuffer[cnt] = LineTable.LineBuffer[i];
            cnt++;
        }
    }
    LineTable.LineTableLen = cnt;
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
    DeleteRangeValue(3,3);
    DeleteRangeValue(3,1);
    DeleteRangeValue(2,3);

    LineTable.LineTableLen = 5;
    LineTable.LineBuffer[0] = 1;
    LineTable.LineBuffer[1] = 2;
    LineTable.LineBuffer[2] = 3;
    LineTable.LineBuffer[3] = 4;
    LineTable.LineBuffer[4] = 5;

    DeleteRangeValue(3,2);
    PrintLineTable();

    DeleteRangeValue(1,2);
    PrintLineTable();

    DeleteRangeValue(1,9);
    PrintLineTable();

    return 0;
}
