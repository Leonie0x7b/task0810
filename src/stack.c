#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "../inc/stack.h"
 
void stackInit(stack *s,uint32_t sz){
    // char *ptr=(char *)malloc(sz*sizeof(char));
    // s->a = ptr;
    // s->base=ptr+sz-1;
    // s->top=s->base;
    s->mem=(char *)malloc(sz*sizeof(char));
    s->base=s->mem+sz-1;
    s->top=s->base;
    s->size=sz;
}

bool stackIsEmpty(stack *s){
    return (s->base==s->top);
}

bool stackIsFull(stack *s){
    return((s->base-s->top)>=s->size);
}

bool stackPush(stack *s,uint32_t sz,void *value){
    // if((s->top-sz)<=(s->base-s->size+1)){
    //     return 0;
    // }
    if(stackIsFull(s)){
        return 0;
    }
    s->top -= sz;
    memcpy(s->top,value,sz);
    return 1;
}

bool stackPop(stack *s,uint32_t sz,void *value){
    if((s->top+sz)>(s->base)){
        return 0;
    }
    memcpy(value,s->top,sz);
    s->top+=sz;
    return 1;
}

void stackFree(stack *s){
    free(s->mem);
    s->mem=NULL;
    s->base=NULL;
    s->top=NULL;
    s->size=0;
}