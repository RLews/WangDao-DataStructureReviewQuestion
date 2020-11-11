#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct LINE_LIST_T
{
    int data;
    struct LINE_LIST_T *nextPtr;
    struct LINE_LIST_T *prevPtr;
}LineList_t;

static LineList_t *LineList = NULL;

void DeleteListValue(int x)
{
    LineList_t *pNode = NULL;
    LineList_t *pHead = LineList;

    while (pHead != NULL)
    {
        if (pHead->data == x)
        {
            pNode = pHead;

            if (pHead->prevPtr != NULL)
            {
                pHead->prevPtr->nextPtr = pHead->nextPtr;
            }
            else
            {
                LineList = pHead->nextPtr;// 第一个节点更新
            }
            if (pHead->nextPtr != NULL)
            {
                pHead->nextPtr->prevPtr = pHead->prevPtr;
            }
            pHead = pHead->nextPtr;
            free(pNode);
            pNode = NULL;
        }
        else
        {
            pHead = pHead->nextPtr;
        }

    }
}

void CreateList(int x)
{
    LineList_t *pNode = NULL;
    LineList_t *s = NULL;
    int i = 0;
    int val = 0;

    LineList = (LineList_t *)malloc(sizeof(LineList_t));
    LineList->prevPtr = NULL;
    LineList->nextPtr = NULL;
    pNode = LineList;

    for (i = 0; i < x; i++)
    {
        printf("\nPlease input the data value : ");
        scanf("%d", &val);

        s = (LineList_t *)malloc(sizeof(LineList_t));
        s->data = val;
        s->prevPtr = pNode;
        s->nextPtr = NULL;
        pNode->nextPtr = s;
        pNode = s;
    }
    LineList = LineList->nextPtr;
    LineList->prevPtr = NULL;
}

void DisplayListValue(void)
{
    LineList_t *pNode = NULL;
    LineList_t *sNode = NULL;

    pNode = LineList;
    printf("The List Value : \n");
    while (pNode != NULL)
    {
        printf("%d\t", pNode->data);
        printf("prev addr = %d\t", pNode->prevPtr);
        printf("this addr = %d\t", pNode);
        printf("next addr = %d\t", pNode->nextPtr);
        sNode = pNode;
        pNode = pNode->nextPtr;
        printf("\n");
    }
    printf("The Reverse List Value : \n");
    while (sNode != NULL)
    {
        printf("%d\t", sNode->data);
        printf("prev addr = %d\t", sNode->prevPtr);
        printf("this addr = %d\t", sNode);
        printf("next addr = %d\t", sNode->nextPtr);
        sNode = sNode->prevPtr;
        printf("\n");
    }
}

int main(void)
{
    int x = 0;

    printf("Please input number for create max list.\n");
    scanf("%d", &x);
    CreateList(x);
    DisplayListValue();

    printf("\nPlease input delete number :");
    scanf("%d", &x);
    DeleteListValue(x);
    DisplayListValue();

    return 0;
}

