#include "utils/doubleStack.h"
#include "evaluatePrefix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char isOperand(char val)
{
    if (val >= '0' && val <= '9')
        return 1;
    return 0;
}

double evaluatePrefix(char *prefix)
{
    DoubleStack *stack = db_initStack(64);
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
            db_push(stack, prefix[i] - '0');
        else
        {
            double num1 = db_pull(stack);
            double num2 = db_pull(stack);

            switch (prefix[i])
            {
            case '+':
                db_push(stack, num1 + num2);
                break;
            case '-':
                db_push(stack, num1 - num2);
                break;
            case '*':
                db_push(stack, num1 * num2);
                break;
            case '/':
                db_push(stack, num1 / num2);
                break;
            }
        }
    }

    return db_pull(stack);
}
