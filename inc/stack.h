#ifndef __STACK_H__
#define __STACK_H__

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

typedef struct Stack{
    char *top;
    char *base;
    int size;
    char *mem;
}stack;

void stackInit(stack *s,uint32_t sz);
bool stackIsEmpty(stack *s);
bool stackIsFull(stack*s);
bool stackPush(stack *s,uint32_t sz,void *value);
bool stackPop(stack *s,uint32_t sz,void *value);
void stackFree(stack *s);
#endif