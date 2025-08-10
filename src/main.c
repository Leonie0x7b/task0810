#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "../inc/queue.h"
#include "../inc/stack.h"

int main(){
    queue q1;
    queueInit(&q1);
    stack s1;
    stackInit(&s1,50);
    int res=0;
    for(int i=0;i<QUEENMAXN;i++){
    joinQueue(&q1,i+1);
    }
    deQueue(&q1,&res);
    printf("queue result:\n");
    printf("%d\n",res);
    deQueue(&q1,&res);
    printf("%d\n",res);


    float val1=2.5f;
    stackPush(&s1,sizeof(float),&val1);
    uint8_t val2=12;
    stackPush(&s1,sizeof(uint8_t),&val2);
    uint8_t res2=0;
    stackPop(&s1,sizeof(uint8_t),&res2);
    float res1=0;
    stackPop(&s1,sizeof(float),&res1);
    printf("stack result:\n");
    printf("%d\n",res2);
    printf("%f\n",res1);

    stackFree(&s1);
    return 0;
}