#ifndef STACK_H
#define STACK_H

typedef struct
{
    int size;   // Size of stack
    int header; // Index of stack header
    char **val; // Pointer of value, acceptable digit up to 20 characters
} st_value;

st_value *initStack(int t);
char *pull(st_value *stack);
void push(st_value *stack, char *val);
char isEmpty(st_value *stack);
char *top(st_value *stack);
void pop(st_value *stack);
int height(st_value *stack);
char *dump(st_value *stack);

#endif