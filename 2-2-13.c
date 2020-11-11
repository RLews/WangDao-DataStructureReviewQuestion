#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int FindMinInteger(int a[], int len)
{
    int minInteger = 0;
    int *pBuf = NULL;
    int i = 0;

    pBuf = (int *)malloc(sizeof(int) * len);
    (void)memset(pBuf, 0, sizeof(int) * len);

    for (i = 0; i < len; i++)
    {
        if ((a[i] > 0) && (a[i] <= len))
        {
            pBuf[a[i]- 1] = 1;
        }
    }

    for (i = 0; i < len; i++)
    {
        if (pBuf[i] == 0)
        {
            break;
        }
    }

    minInteger = i+1;

    return minInteger;
}

int main(void)
{
    int a[7] = {1,2,3,4,5,6,7};
    printf("The Min Number == %d\n", FindMinInteger(a, 7));

    int b[7] = {1,1,3,4,1,6,7};
    printf("The Min Number == %d\n", FindMinInteger(b, 7));

    int c[8] = {1,2,2,4,2,7,2,2};
    printf("The Min Number == %d\n", FindMinInteger(c, 8));

    int d[10] = {7,7,37,4,2,7,2,7,7,7};
    printf("The Min Number == %d\n", FindMinInteger(d, 10));

    return 0;
}

