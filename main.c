#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils/stack.h"

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

void resolveOperand(st_value *operators, st_value *operands)
{
    char *aux = malloc(32 * sizeof(char));

    char *op1 = pull(operands);
    char *op2 = pull(operands);

    sprintf(aux, "%c%s%s", pull(operators)[0], op2, op1);

    push(operands, aux);
}

char *infixToPrefix(const char *infix)
{
    st_value *operators = initStack(32);
    st_value *operands = initStack(64);

    int len = strlen(infix);

    for (int i = 0; i < len; i++)
    {
        if (infix[i] == '(')
        {
            char *aux = malloc(2 * sizeof(char));
            aux[0] = infix[i];
            aux[1] = '\0';
            push(operators, aux);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(operators) &&
                   top(operators)[0] != '(')
            {
                resolveOperand(operators, operands);
            }

            pop(operators);
        }
        else if (!isOperator(infix[i]))
        {
            char *aux = malloc(2 * sizeof(char));
            aux[0] = infix[i];
            aux[1] = '\0';
            push(operands, aux);
        }
        else
        {
            while (!isEmpty(operators) &&
                   getOperatorPriority(infix[i]) <=
                       getOperatorPriority(top(operators)[0]))
            {
                resolveOperand(operators, operands);
            }
            char *aux = malloc(2 * sizeof(char));
            aux[0] = infix[i];
            aux[1] = '\0';
            push(operators, aux);
        }
    }

    while (!isEmpty(operators))
    {
        resolveOperand(operators, operands);
    }

    return pull(operands);
}

int main()
{
    const char *infix = "(3-4/2)/(9/3+5)\0"; // /-3/42+/935

    char *prefix = infixToPrefix(infix);

    printf("Infix: %s || Prefix: %s", infix, prefix);

    return 0;
}
