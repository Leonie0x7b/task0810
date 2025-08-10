#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "../inc/queue.h"

void queueInit(queue *q)
{
    q->Front=0;
    q->Rear=0;
    for(int i=0;i<QUEENMAXN;i++){
        q->data[i]=0;
    }
}

bool isEmpty(queue *q){
    return (q->Front==q->Rear);
}

bool isFull(queue *q){
    return(((q->Rear+1)%QUEENMAXN)==q->Front);
}

bool joinQueue(queue *q,int val){
    if(isFull(q)){
        return 0;
    }
    q->data[q->Rear]=val;
    q->Rear=(q->Rear+1)%QUEENMAXN;
    return 1;
}

bool deQueue(queue *q,int *val){
    if(isEmpty(q)){
        return 0;
    }
    *val=q->data[q->Front];
    q->Front=(q->Front+1)%QUEENMAXN;
    return 1;
}

