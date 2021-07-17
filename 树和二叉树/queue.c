#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    queueNode *rear;
    queueNode *front;
} queueNode, *Q;
