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

void PrintSortAndDelete(List_t * pList)
{
    List_t *pre = NULL;
    List_t *p = NULL;
    List_t *temp = NULL;

    printf("List = ");
    while (pList->next != NULL)
    {
        pre = pList;
        p = pre->next;
        while (p->next != NULL)
        {
            if (p->next->val < pre->next->val)
            {
                pre = p;
            }
            p = p->next;
        }
        printf(" %d ", pre->next->val);
        temp = pre->next;
        pre->next = temp->next;
        free(temp);
        temp = NULL;
    }
    printf("\n");
    free(pList);
    pList = NULL;
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
	List_t * p = L;

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
    PrintSortAndDelete(TestList);
    return 0;
}
