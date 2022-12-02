#include "doubleStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

DoubleStack *db_initStack(int size)
{
    DoubleStack *tmp = malloc(sizeof(DoubleStack));
    tmp->size = size;
    tmp->header = -1;
    tmp->val = malloc(size * sizeof(double));
    return tmp;
}

double db_pull(DoubleStack *stack)
{
    double ret;
    if (stack->header == -1)
        printf("Empty stack!\n");
    else
    {
        ret = stack->val[stack->header];
        stack->header--;
    }
    return ret;
}

void db_push(DoubleStack *stack, double val)
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

char db_isEmpty(DoubleStack *stack)
{
    if (stack->header == -1)
        return 1;
    return 0;
}

double db_top(DoubleStack *stack)
{
    if (stack->header == -1)
    {
        printf("Empty stack!\n");
        return 0;
    }

    return stack->val[stack->header];
}

void db_pop(DoubleStack *stack)
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

int db_height(DoubleStack *stack)
{
    return stack->header;
}
