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

void MergeLineTable(LineTable_t a, LineTable_t b, LineTable_t *c)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    int len = 0;

    for (i = 0, j = 0; (j < b.LineTableLen) && (i < a.LineTableLen); )
    {
        if (a.LineBuffer[i] > b.LineBuffer[j])
        {
            c->LineBuffer[cnt] = b.LineBuffer[j];
            cnt++;
            j++;
        }
        else
        {
            c->LineBuffer[cnt] = a.LineBuffer[i];
            cnt++;
            i++;
        }
    }

    for ( ; j < b.LineTableLen; j++)
    {
        c->LineBuffer[cnt] = b.LineBuffer[j];
        cnt++;
    }

    for ( ; i < a.LineTableLen; i++)
    {
        c->LineBuffer[cnt] = a.LineBuffer[i];
        cnt++;
    }

    c->LineTableLen = cnt;
}

int main (void)
{
    LineTable_t a = {0};
    LineTable_t b = {0};

    a.LineTableLen = 5;
    a.LineBuffer[0] = 1;
    a.LineBuffer[1] = 10;
    a.LineBuffer[2] = 12;
    a.LineBuffer[3] = 13;
    a.LineBuffer[4] = 20;

    b.LineTableLen = 5;
    b.LineBuffer[0] = 10;
    b.LineBuffer[1] = 11;
    b.LineBuffer[2] = 15;
    b.LineBuffer[3] = 19;
    b.LineBuffer[4] = 29;

    MergeLineTable(a, b, &LineTable);
    PrintLineTable();

    a.LineTableLen = 5;
    a.LineBuffer[0] = 1;
    a.LineBuffer[1] = 10;
    a.LineBuffer[2] = 12;
    a.LineBuffer[3] = 13;
    a.LineBuffer[4] = 20;

    b.LineTableLen = 7;
    b.LineBuffer[0] = 7;
    b.LineBuffer[1] = 17;
    b.LineBuffer[2] = 18;
    b.LineBuffer[3] = 18;
    b.LineBuffer[4] = 19;
    b.LineBuffer[5] = 22;
    b.LineBuffer[6] = 29;

    MergeLineTable(a, b, &LineTable);
    PrintLineTable();

    a.LineTableLen = 7;
    a.LineBuffer[0] = 1;
    a.LineBuffer[1] = 10;
    a.LineBuffer[2] = 12;
    a.LineBuffer[3] = 13;
    a.LineBuffer[4] = 20;
    a.LineBuffer[5] = 22;
    a.LineBuffer[6] = 29;

    b.LineTableLen = 5;
    b.LineBuffer[0] = 7;
    b.LineBuffer[1] = 17;
    b.LineBuffer[2] = 18;
    b.LineBuffer[3] = 18;
    b.LineBuffer[4] = 19;

    MergeLineTable(a, b, &LineTable);
    PrintLineTable();

    a.LineTableLen = 7;
    a.LineBuffer[0] = 1;
    a.LineBuffer[1] = 10;
    a.LineBuffer[2] = 12;
    a.LineBuffer[3] = 13;
    a.LineBuffer[4] = 20;
    a.LineBuffer[5] = 22;
    a.LineBuffer[6] = 29;

    b.LineTableLen = 5;
    b.LineBuffer[0] = 1;
    b.LineBuffer[1] = 10;
    b.LineBuffer[2] = 12;
    b.LineBuffer[3] = 13;
    b.LineBuffer[4] = 20;

    MergeLineTable(a, b, &LineTable);
    PrintLineTable();

    return 0;
}
