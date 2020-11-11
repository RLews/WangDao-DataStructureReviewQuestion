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

int FindMedian( LineTable_t a, LineTable_t b )
{
    int i = 0;
    int aindex = 0;
    int bindex = 0;
    int median = 0;
    int findLen = (a.LineTableLen + b.LineTableLen) / 2;

    for (i = 0; i < findLen; i++)
    {
        if (a.LineBuffer[aindex] > b.LineBuffer[bindex])
        {
            median = b.LineBuffer[bindex];
            bindex++;
        }
        else
        {
            median = a.LineBuffer[aindex];
            aindex++;
        }
    }

    return median;
}

int main(void)
{
    LineTable_t a;
    LineTable_t b;

    a.LineTableLen = 5;
    a.LineBuffer[0] = 2;
    a.LineBuffer[1] = 6;
    a.LineBuffer[2] = 7;
    a.LineBuffer[3] = 10;
    a.LineBuffer[4] = 12;
    b.LineTableLen = 5;
    b.LineBuffer[0] = 12;
    b.LineBuffer[1] = 26;
    b.LineBuffer[2] = 37;
    b.LineBuffer[3] = 39;
    b.LineBuffer[4] = 42;
    printf("Median Value == %d\n", FindMedian(a,b));

    a.LineTableLen = 5;
    a.LineBuffer[0] = 92;
    a.LineBuffer[1] = 96;
    a.LineBuffer[2] = 97;
    a.LineBuffer[3] = 100;
    a.LineBuffer[4] = 102;
    b.LineTableLen = 5;
    b.LineBuffer[0] = 12;
    b.LineBuffer[1] = 26;
    b.LineBuffer[2] = 37;
    b.LineBuffer[3] = 39;
    b.LineBuffer[4] = 42;
    printf("Median Value == %d\n", FindMedian(a,b));

    a.LineTableLen = 5;
    a.LineBuffer[0] = 92;
    a.LineBuffer[1] = 96;
    a.LineBuffer[2] = 97;
    a.LineBuffer[3] = 100;
    a.LineBuffer[4] = 102;
    b.LineTableLen = 5;
    b.LineBuffer[0] = 92;
    b.LineBuffer[1] = 93;
    b.LineBuffer[2] = 97;
    b.LineBuffer[3] = 99;
    b.LineBuffer[4] = 102;
    printf("Median Value == %d\n", FindMedian(a,b));

    a.LineTableLen = 5;
    a.LineBuffer[0] = 92;
    a.LineBuffer[1] = 96;
    a.LineBuffer[2] = 97;
    a.LineBuffer[3] = 100;
    a.LineBuffer[4] = 102;
    b.LineTableLen = 5;
    b.LineBuffer[0] = 92;
    b.LineBuffer[1] = 96;
    b.LineBuffer[2] = 97;
    b.LineBuffer[3] = 100;
    b.LineBuffer[4] = 102;
    printf("Median Value == %d\n", FindMedian(a,b));


    return 0;
}
