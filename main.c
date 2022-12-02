#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "evaluatePrefix.h"
#include "mountPrefix.h"

int main()
{
    const char *infix = "(3-4/2)/(9/3+5)\0"; // /-3/42+/935

    char *prefix = convert(infix);

    printf("Infix: %s || Prefix: %s\r\n", infix, prefix);

    double result = evaluatePrefix(prefix);

    printf("Result: %lf\r\n", result);

    return 0;
}
