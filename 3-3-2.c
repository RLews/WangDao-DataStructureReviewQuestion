#include "common.h"


#define D_MAX_SIZE      10000

typedef char StackType_t;

typedef struct 
{
    StackType_t stack[D_MAX_SIZE];
    int top;
}Stack_t;

static Stack_t Stack;

void StackInit(void)
{
    Stack.top = -1;
}

bool Push(StackType_t x)
{
    if (Stack.top >= D_MAX_SIZE)
    {
        TRACE_INFO("stack is full.\n");
        return false;
    }

    Stack.top++;
    Stack.stack[Stack.top] = x;
    return true;
}

bool Pop(StackType_t *pData)
{
    if (Stack.top < 0)
    {
        TRACE_INFO("stack is empty.\n");
        return false;
    }

    *pData = Stack.stack[Stack.top];
    Stack.top--;
    return true;
}

bool StackIsEmpty(void)
{
    if (Stack.top < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void TrainArrage(char *train)
{
    char *p = train;
    char *q = train;
    char c = 0;
    StackInit();

    while (*p)
    {
        if (*p == 'H')
        {
            Push (*p);
        }
        else
        {
            *(q++) = *p;
        }
        p++;
    }

    while (StackIsEmpty() != true)
    {
        Pop(&c);
        *(q++) = c;
    }
}

int main(void)
{
    char str1[] = "SHHHSHSHSHS";
    char str2[] = "HHHSSSHSHSHS";

    TrainArrage(str1);
    TRACE_INFO("%s\n", str1);
    TrainArrage(str2);
    TRACE_INFO("%s\n", str2);

    return 0;
}
