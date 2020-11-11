#include <stdio.h>
#include <stdbool.h>

#define D_SEQUENCE_LIST_MAX_LENGTH              20

static const int ErrorType = -1;

static int SequenceList[D_SEQUENCE_LIST_MAX_LENGTH] = {0};
static int SequenceListLen = 0;

int DelListMinElement(void)
{
    int tMin = 0;
    int minIndex = 0;
    int i = 0;

    if (SequenceListLen == 0)
    {
        return ErrorType;
    }

    tMin = SequenceList[0];

    for (i = 1; i < SequenceListLen; i++)
    {
        if (tMin > SequenceList[i])
        {
            tMin = SequenceList[i];
            minIndex = i;
        }
    }

    SequenceList[minIndex] = SequenceList[SequenceListLen - 1];
    SequenceListLen --;

    return tMin;
}

void PrintfTestRes(bool testFailInd, int testRes)
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
    printf("\n\tTest Result = %d\n", testRes);
}

int main(void)
{
    int TestRes = 0;
    // test 1
    printf("Test 1 Running...\n");
    SequenceListLen = 4;
    SequenceList[0] = 12;
    SequenceList[1] = 2;
    SequenceList[2] = 45;
    SequenceList[3] = 22;
    TestRes = DelListMinElement();
    PrintfTestRes((TestRes != 2)
                || (SequenceList[0] != 12)
                || (SequenceList[1] != 22)
                || (SequenceList[2] != 45)
                || (SequenceListLen != 3),
                 TestRes);

    // test 2
    printf("Test 2 Running...\n");
    TestRes = DelListMinElement();
    PrintfTestRes((TestRes != 12)
                || (SequenceList[0] != 45)
                || (SequenceList[1] != 22)
                || (SequenceListLen != 2),
                 TestRes);

    // test 3
    printf("Test 3 Running...\n");
    TestRes = DelListMinElement();
    PrintfTestRes((TestRes != 22)
                || (SequenceList[0] != 45)
                || (SequenceListLen != 1),
                 TestRes);

    // test 4
    printf("Test 4 Running...\n");
    TestRes = DelListMinElement();
    PrintfTestRes((TestRes != 45)
                || (SequenceListLen != 0),
                 TestRes);

    // test 5
    printf("Test 5 Running...\n");
    TestRes = DelListMinElement();
    PrintfTestRes((TestRes != ErrorType)
                || (SequenceListLen != 0),
                 TestRes);

    return 0;
}
