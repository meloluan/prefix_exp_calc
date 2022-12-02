#include "utils/strStack.h"
#include "mountPrefix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char isOperator(char val)
{
    switch (val)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
    }
    return 0;
}

int getOperatorPriority(char operator)
{
    if (operator== '-' || operator== '+')
        return 1;
    else if (operator== '*' || operator== '/')
        return 2;
    return 0;
}


void resolveOperand(StrStack *operators, StrStack *operands)
{
    char *aux = malloc(32 * sizeof(char));

    char *op1 = str_pull(operands);
    char *op2 = str_pull(operands);

    sprintf(aux, "%c%s%s", str_pull(operators)[0], op2, op1);

    str_push(operands, aux);
}

char *convert(const char *infix)
{
    StrStack *operators = str_initStack(32);
    StrStack *operands = str_initStack(64);

    int len = strlen(infix);

    for (int i = 0; i < len; i++)
    {
        if (infix[i] == '(')
        {
            char *aux = malloc(2 * sizeof(char));
            aux[0] = infix[i];
            aux[1] = '\0';
            str_push(operators, aux);
        }
        else if (infix[i] == ')')
        {
            while (!str_isEmpty(operators) &&
                   str_top(operators)[0] != '(')
            {
                resolveOperand(operators, operands);
            }

            str_pop(operators);
        }
        else if (!isOperator(infix[i]))
        {
            char *aux = malloc(2 * sizeof(char));
            aux[0] = infix[i];
            aux[1] = '\0';
            str_push(operands, aux);
        }
        else
        {
            while (!str_isEmpty(operators) &&
                   getOperatorPriority(infix[i]) <=
                       getOperatorPriority(str_top(operators)[0]))
            {
                resolveOperand(operators, operands);
            }
            char *aux = malloc(2 * sizeof(char));
            aux[0] = infix[i];
            aux[1] = '\0';
            str_push(operators, aux);
        }
    }

    while (!str_isEmpty(operators))
    {
        resolveOperand(operators, operands);
    }

    return str_pull(operands);
}
