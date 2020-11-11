#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int FindMasterData(int a[], int len)
{
    int i = 0;
    int master = 0;
    int cnt = 0;

    master = a[0];
    cnt = 1;
    for (i = 1; i < len; i++)
    {
        if (master == a[i])
        {
            cnt++;
        }
        else
        {
            if (cnt > 0)
            {
                cnt--;
            }
            else
            {
                cnt = 1;
                master = a[i];
            }
        }

    }

    if (cnt > 0)
    {
        cnt = 0;
        for (i = 0; i < len; i++)
        {
            if (master == a[i])
            {
                cnt++;
            }
        }
    }

    if (cnt <= (len / 2))
    {
        master = -1;
    }
    return master;
}

int main(void)
{
    int a[7] = {1,2,3,4,5,6,7};
    printf("The Master Number == %d\n", FindMasterData(a, 7));

    int b[7] = {1,1,3,4,1,6,7};
    printf("The Master Number == %d\n", FindMasterData(b, 7));

    int c[8] = {1,2,2,4,2,7,2,2};
    printf("The Master Number == %d\n", FindMasterData(c, 8));

    int d[10] = {7,7,37,4,2,7,2,7,7,7};
    printf("The Master Number == %d\n", FindMasterData(d, 10));
}
