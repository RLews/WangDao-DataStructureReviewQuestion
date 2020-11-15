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

List_t * FindSameNode(List_t * A, List_t * B)
{
    int ALen = length_list(A);
    int BLen = length_list(B);
    List_t *pLongList = NULL;
    List_t *pShortList = NULL;
    int dist = 0;

    if (ALen > BLen)
    {
        pLongList = A->next;
        pShortList = B->next;
        dist = ALen - BLen;
    }
    else
    {
        pLongList = B->next;
        pShortList = A->next;
        dist = BLen - ALen;
    }

    if (pLongList == pShortList)
    {
        return pLongList;
    }

    while (dist != 0)
    {
        dist --;
        pLongList = pLongList->next;
    }
    
    while (pLongList != NULL)
    {
        if (pLongList == pShortList)
        {
            return pLongList;
        }
        else
        {
            pLongList = pLongList->next;
            pShortList = pShortList->next;
        }
        
    }
    
    return NULL;
}

void DeleteRange(List_t *pHead, int min, int max)
{
    List_t * q = pHead->next;
    List_t * del = NULL;
    List_t * pre = pHead;

    while (q != NULL)
    {
        if (q->val > min && q->val < max)
        {
            del = q;
            pre->next = q->next;
            q = q->next;
            del = NULL;
            free(del);
        }
        else
        {
            pre = q;
            q = q->next;
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
    List_t Node5 = {1, NULL};
    List_t Node4 = {1, &Node5};
    List_t Node3 = {1, &Node4};
    List_t Node2 = {1, &Node3};
    List_t Node1 = {1, &Node2};
    List_t ADiff1 = {99, &Node1};
    List_t ADiff2 = {99, &ADiff1};
    List_t BDiff1 = {99, &Node1};
    List_t Head1 = {-1, &Node1};
    List_t Head2 = {-1, &Node1};

    List_t *pRes = NULL;

    ListPrint(&Head1);
    ListPrint(&Head2);
    pRes = FindSameNode(&Head1, &Head2);
    ListPrint(pRes);
    return 0;
}
