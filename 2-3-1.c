#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct NODE_T
{
    int val;
    struct NODE_T * next;
}List_t;

static List_t * TestList;

/*
    1 2 ÌâÀàËÆ
*/
void DeleteValue(List_t * pList, int dat)
{
    List_t *p = NULL;

    if (pList->next == NULL)
    {
        return;
    }

    if (pList->next->val == dat)
    {
        p = pList->next;
        pList->next = pList->next->next;
        free(p);
        DeleteValue(pList, dat);
    }
    else
    {
        DeleteValue(pList->next, dat);
    }
}

List_t * CreateList(void)
{
    int n;
    int val;

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
        pNew->val = val;
        pTail->next = pNew;
        pNew->next = NULL;
        pTail = pNew;
    }

    return pHead;
}

void ListPrint( List_t * L )
{
	List_t * p = L->next;

	if (p == NULL)
    {
        printf("NULL");
    }

	while(p)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

int main(void)
{
    TestList = CreateList();
    ListPrint(TestList);
    DeleteValue(TestList, 2);
    ListPrint(TestList);

    return 0;
}
