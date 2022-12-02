#ifndef STR_STACK_H
#define STR_STACK_H

typedef struct
{
    int size;   // Size of stack
    int header; // Index of stack header
    char **val; // Pointer of value, acceptable digit up to 20 characters
} StrStack;

StrStack *str_initStack(int t);
char *str_pull(StrStack *stack);
void str_push(StrStack *stack, char *val);
char str_isEmpty(StrStack *stack);
char *str_top(StrStack *stack);
void str_pop(StrStack *stack);
int str_height(StrStack *stack);

#endif