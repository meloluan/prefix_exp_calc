#include "strStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

StrStack *str_initStack(int size)
{
    StrStack *tmp = malloc(sizeof(StrStack));
    tmp->size = size;
    tmp->header = -1;
    tmp->val = malloc(size * sizeof(char *));
    return tmp;
}

char *str_pull(StrStack *stack)
{
    char *ret;
    if (stack->header == -1)
        printf("Empty stack!\n");
    else
    {
        ret = stack->val[stack->header];
        stack->header--;
    }
    return ret;
}

void str_push(StrStack *stack, char *val)
{
    if (stack->header == stack->size - 1)
    {
        printf("Empty stack!\n");
    }
    else
    {
        stack->header++;
        stack->val[stack->header] = val;
    }
}

char str_isEmpty(StrStack *stack)
{
    if (stack->header == -1)
        return 1;
    return 0;
}

char *str_top(StrStack *stack)
{
    if (stack->header == -1)
    {
        printf("Empty stack!\n");
        return 0;
    }

    return stack->val[stack->header];
}

void str_pop(StrStack *stack)
{
    if (stack->header == -1)
    {
        printf("Empty stack!\n");
    }
    else
    {
        stack->header--;
    }
}

int str_height(StrStack *stack)
{
    return stack->header;
}
