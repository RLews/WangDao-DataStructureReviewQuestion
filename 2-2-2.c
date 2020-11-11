#include <stdio.h>
#include <stdbool.h>

#define D_SEQUENCE_LIST_MAX_LENGTH              20

static int SequenceList[D_SEQUENCE_LIST_MAX_LENGTH] = {0};
static int SequenceListLen = 0;

void SwapData(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}

void ReverseList(void)
{
    int i = 0;

    for (i = 0; i < SequenceListLen / 2; i++)
    {
        SwapData(&SequenceList[i], &SequenceList[SequenceListLen-1-i]);
    }
}

void PrintfTestRes(bool testFailInd)
{
    int i = 0;

    if (testFailInd == true)
    {
        printf("Test Fail!");
    }
    else
    {
        printf("Test Pass!");
    }

    printf("\n\tList Length = %d", SequenceListLen);
    for (i = 0; i < SequenceListLen; i++)
    {
        printf("\n\tList %d Data = %d", i, SequenceList[i]);
    }
    printf("\n");
}

int main(void)
{
    // test 1
    printf("Test 1 Running...\n");
    SequenceListLen = 4;
    SequenceList[0] = 12;
    SequenceList[1] = 2;
    SequenceList[2] = 45;
    SequenceList[3] = 22;
    ReverseList();
    PrintfTestRes((SequenceList[0] != 22)
                || (SequenceList[1] != 45)
                || (SequenceList[2] != 2)
                || (SequenceList[3] != 12));

    // test 2
    printf("Test 2 Running...\n");
    SequenceListLen = 5;
    SequenceList[0] = 12;
    SequenceList[1] = 22;
    SequenceList[2] = 45;
    SequenceList[3] = 22;
    SequenceList[4] = 6;
    ReverseList();
    PrintfTestRes((SequenceList[0] != 6)
                || (SequenceList[1] != 22)
                || (SequenceList[2] != 45)
                || (SequenceList[3] != 22)
                || (SequenceList[4] != 12));

    return 0;
}
