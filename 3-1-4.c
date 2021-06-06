#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NODE_T
{
    int data;
    struct NODE_T *next;
}List_t;

static List_t * TestList;

static List_t * CreateList(void)
{
    int n = 0;
    int val = 0;

    printf("please input n node is :");
    scanf("%d",&n);

    List_t * pHead = (List_t *)malloc(sizeof(struct NODE_T));
    if (pHead == NULL)
    {
        printf("malloc error!\n");
        exit(-1);
    }
    List_t * pTail = pHead;
    pTail->next = NULL;

    for (int i = 0; i < n; i++)
    {
        printf("input %d node value is :", i+1);
        scanf("%d",&val);
        List_t * pNew = (List_t *)malloc(sizeof(struct NODE_T));
        if (pNew == NULL)
        {
            printf("malloc error!\n");
            exit(-1);
        }
        pNew->data = val;
        pTail->next = pNew;
        pNew->next = NULL;
        pTail = pNew;
    }

    return pHead;
}

static int LengthList(List_t * pHead)
{
    int n = 0;
    List_t * p = pHead->next;
    while (p != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}


bool ListJudge(List_t *L, int n)
{
    int i = 0;
    char s[n/2];
    List_t *p = NULL;

    p = L->next;
    for (i = 0; i < n/2; i++)
    {
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if (n%2 == 1)
    {
        p = p->next;
    }

    while ((p != NULL) && (s[i] == p->data))
    {
        i--;
        p = p->next;
    }

    if (i == -1)
    {
        printf("list is symmetrical.\n");
        return true;
    }
    else
    {
        printf("list is asymmetric.\n");
        return false;
    }
    
}

int main(void)
{

    TestList = CreateList();
    ListJudge(TestList, LengthList(TestList));

    return 0;
}
