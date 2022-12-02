#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "evaluatePrefix.h"
#include "mountPrefix.h"

int main(int argc, char *argv[])
{
    if (argv[1] == 0)
    {
        printf("Adds a infixed expression. Example: math_calc \"3*(5+4/2)\"\r\n");
    }
    else
    {
        const char *infix = argv[1];

        char *prefix = convert(infix);

        printf("Infix: %s || Prefix: %s\r\n", infix, prefix);

        double result = evaluatePrefix(prefix);

        printf("Result : %lf\r\n", result);
    }

    return 0;
}
