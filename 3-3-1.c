#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define D_MAX_SIZE      10000

typedef int StackType_t;

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
        printf("stack is full.\n");
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
        printf("stack is empty.\n");
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

bool BracketsCheck(char *str)
{
    StackInit();
    int i = 0;
    StackType_t e = 0;

    while (str[i] != '\0')
    {
        switch(str[i])
        {
            case '(':
            case '[':
            case '{':
                Push(str[i]);
                break;
                
            case ')':
                Pop(&e);
                if (e != '(')
                {
                    printf("string not match.\n");
                    return false;
                }
                break;
            case ']':
                Pop(&e);
                if (e != '[')
                {
                    printf("string not match.\n");
                    return false;
                }
                break;
            case '}':
                Pop(&e);
                if (e != '{')
                {
                    printf("string not match.\n");
                    return false;
                }
                break;
            default:
                break;
        }
        i++;
    }

    if (StackIsEmpty() == true)
    {
        printf("string is match.\n");
        return true;
    }
    else
    {
        printf("string not match.\n");
        return false;
    }
    
}

int main(void)
{
    char str1[] = "{{{[()]}}}";
    char str2[] = "{[{{[()]}}}";

    BracketsCheck(str1);
    BracketsCheck(str2);

    return 0;
}