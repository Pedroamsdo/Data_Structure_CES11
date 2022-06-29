/* Faça aqui sua solução. */

#include "stack_extra.h"
#include <stdio.h>
#include <stdlib.h>
void stack_printBottomUp(STACK *stack)
{
    if (stack_isEmpty(stack) == true)
    {
        printf(" \n  ");
    }
    else
    {
        STACK *l;
        l = stack_reverse(stack);
        while (stack_isEmpty(l) == false)
        {
            printf("%d ", stack_top(l));
            stack_pop(l);
        }
        printf("\n");
        stack_destroy(l);
    }
}
void stack_printTopDown(STACK *stack)
{
    if (stack_isEmpty(stack) == true)
    {
        printf("0\n");
    }
    else
    {
        STACK *n;
        n = stack_create();
        while (stack_isEmpty(stack) == false)
        {
            printf("%d ", stack_top(stack));
            stack_push(n, stack_top(stack));
            stack_pop(stack);
        }
        printf("\n");
        while (stack_isEmpty(n) == false)
        {
            stack_push(stack, stack_top(n));
            stack_pop(n);
        }
        stack_destroy(n);
    }
}
STACK *stack_reverse(STACK *stack)
{
    STACK *r, *o;
    r = stack_create();
    o = stack_create();
    while (stack_isEmpty(stack) == false)
    {
        stack_push(o, stack_top(stack));
        stack_push(r, stack_top(stack));
        stack_pop(stack);
    }
    while (stack_isEmpty(o) == false)
    {
        stack_push(stack, stack_top(o));
        stack_pop(o);
    }
    stack_destroy(o);
    return r;
}
void stack_stack(STACK *a, STACK *b)
{
    STACK *p;
    p = stack_reverse(b);
    while (stack_isEmpty(p) == false)
    {
        stack_push(a, stack_top(p));
        stack_pop(p);
    }
    while (stack_isEmpty(b) == false)
    {
        stack_pop(b);
    }
}