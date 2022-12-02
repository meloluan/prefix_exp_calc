#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

st_value *initStack(int size)
{
    st_value *tmp = malloc(sizeof(st_value));
    tmp->size = size;
    tmp->header = -1;
    tmp->val = malloc(size * sizeof(char *));
    return tmp;
}

char *pull(st_value *stack)
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

void push(st_value *stack, char *val)
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

char isEmpty(st_value *stack)
{
    if (stack->header == -1)
        return 1;
    return 0;
}

char *top(st_value *stack)
{
    if (stack->header == -1)
    {
        printf("Empty stack!\n");
        return 0;
    }

    return stack->val[stack->header];
}

void pop(st_value *stack)
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

int height(st_value *stack)
{
    return stack->header;
}

char *dump(st_value *stack)
{
    // char *ret = malloc(height(stack) * sizeof(char));

    // for (int i = 0; i < height(stack); i++)
    // {
    //     ret[i] = pull(stack);
    // }
    // return ret;
    return 0;
}
