#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "../inc/stack.h"
 
void stackInit(stack *s,uint32_t sz){
    s->mem=(char *)malloc(sz*sizeof(char));//low address
    s->base=s->mem+sz-1;//Adjust the stack base and stack top to high addresses
    s->top=s->base;
    s->size=sz;
}

bool stackIsEmpty(stack *s){//Determine if it is empty
    return (s->base==s->top);
}

bool stackIsFull(stack *s){//Determine if it is full
    return((s->base-s->top)>=s->size);
}

bool stackPush(stack *s,uint32_t sz,void *value){
    // if((s->top-sz)<=(s->base-s->size+1)){
    //     return 0;
    // }
    if(stackIsFull(s)){
        return 0;
    }
    s->top -= sz;//First make room for the value
    memcpy(s->top,value,sz);
    return 1;
}

bool stackPop(stack *s,uint32_t sz,void *value){
    if((s->top+sz)>(s->base)){
        return 0;
    }
    memcpy(value,s->top,sz);//First copy the current value directly to the value
    s->top+=sz;//then move the pointer position
    return 1;
}

void stackFree(stack *s){
    free(s->mem);//Free the original pointer
    s->mem=NULL;
    s->base=NULL;
    s->top=NULL;
    s->size=0;
}