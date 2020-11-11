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

int length_list(List_t * pHead)
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

void SortList(List_t *pHead)
{
    int i,j,k;
    int len = length_list(pHead);
    List_t * p = NULL;
    List_t * q = NULL;

    for (i = 0, p = pHead->next; i < len-1; i++, p = p->next)
    {
        for (j = i+1, q = p->next; j < len; j++, q = q->next)
        {
            if (p->val > q->val)
            {
                k = q->val;
                q->val = p->val;
                p->val = k;
            }
        }
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
    SortList(TestList);
    ListPrint(TestList);
    return 0;
}
