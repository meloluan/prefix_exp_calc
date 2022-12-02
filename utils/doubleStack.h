#ifndef DOUBLE_STACK_H
#define DOUBLE_STACK_H

typedef struct
{
    int size;   // Size of stack
    int header; // Index of stack header
    double *val;
} DoubleStack;

DoubleStack *db_initStack(int t);
double db_pull(DoubleStack *stack);
void db_push(DoubleStack *stack, double val);
char db_isEmpty(DoubleStack *stack);
double db_top(DoubleStack *stack);
void db_pop(DoubleStack *stack);
int db_height(DoubleStack *stack);

#endif