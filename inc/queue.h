#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

#define QUEENMAXN 20
typedef struct Queue
{
    uint8_t Front;
    uint8_t Rear;
    int data[QUEENMAXN];
}queue;

void queueInit(queue *q);
bool isEmpty(queue *q);
bool isFull(queue *q);
bool joinQueue(queue *q,int val);
bool deQueue(queue *q,int *val);

#endif