#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 255
typedef struct
{
    char *rear;
    char *front;
} Stack;

void InitStack(Stack *S) {
    S->rear = (char)malloc(sizeof(char) * MAXSIZE);
    S->front = S->rear;
}

char popStack(Stack *S) {
    if(S->front == S->front) return;
    return *(S->rear--);
}

void pushStack(Stack *S, char e) {
    if(S->rear - S->front >= MAXSIZE) return;
    *(S->rear) = e;
    S->rear++;
}


