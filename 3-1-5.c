#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define D_MAX_SIZE      100

typedef int StackType_t;

typedef struct 
{
    StackType_t stack[D_MAX_SIZE];
    int top[2];
}Stack_t;

static Stack_t Stack;

void StackInit(void)
{
    Stack.top[0] = -1;
    Stack.top[1] = D_MAX_SIZE;
}

bool push (int id, StackType_t x)
{
    if ((id < 0) || (id > 1))
    { // 0 = s1  1 = s2
        printf("stack id error.\n");
        return false;
    }

    if (Stack.top[1] - Stack.top[0] == 1)
    {
        printf("stack is full \n");
        return false;
    }

    switch (id)
    {
        case 0:
            Stack.top[0]++;
            Stack.stack[Stack.top[0]] = x;
            return true;
        case 1:
            Stack.top[1]--;
            Stack.stack[Stack.top[1]] = x;
            return true;
        defualt:
            return false;
    }
}

bool pop(int id, StackType_t *pData)
{
    if ((id < 0) || (id > 1))
    { // 0 = s1  1 = s2
        printf("stack id error.\n");
        return false;
    }

    switch (id)
    {
        case 0:
            if (Stack.top[0] == -1)
            {
                printf("stack 0 is empty.\n");
                return false;
            }
            else
            {
                *pData = Stack.stack[Stack.top[0]];
                Stack.top[0]--;
                printf("stack 0 pop value = %d\n", *pData);
                return true;
            }
            break;

        case 1:
            if (Stack.top[1] == D_MAX_SIZE)
            {
                printf("stack 1 is empty.\n");
                return false;
            }
            else
            {
                *pData = Stack.stack[Stack.top[1]];
                Stack.top[1]++;
                printf("stack 1 pop value = %d\n", *pData);
                return true;
            }
            break;

        default:
            return false;
    }
}

int main(void)
{
    StackType_t val = 0;

    StackInit();
    (void)push(0, 10);
    (void)push(0, 0);
    (void)push(0, 9);
    (void)push(1, 9);
    (void)push(1, 19);
    (void)push(1, 92);
    (void)push(1, 99);
    (void)push(1, 90);
    (void)pop(0, &val);
    (void)pop(0, &val);
    (void)pop(0, &val);
    (void)pop(0, &val);
    (void)pop(1, &val);
    (void)pop(1, &val);
    (void)pop(1, &val);
    (void)pop(1, &val);
    (void)pop(1, &val);
    return 0;
}
