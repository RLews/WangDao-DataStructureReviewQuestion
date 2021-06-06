#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


bool JudgeStack(char A[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (A[i] != '\0')
    {
        switch (A[i])
        {
            case 'I':
                j++;
                break;
            case 'O':
                k++;
                if (k > j)
                {
                    printf("序列非法.\n");
                    return false;
                }
                break;
            defualt:
                break;
        }
        i++;
    }

    if (k != j)
    {
        printf("序列非法.\n");
        return false;
    }
    else
    {
        printf("序列合法.\n");
        return true;
    }

}

int main(void)
{
    char stack1[] = "IOIOIOOIOIOIOI";
    char stack2[] = "IIIOOOIO";

    JudgeStack(stack1);
    JudgeStack(stack2);

    return 0;
}
