#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int elementType;

typedef struct SqList
{
    elementType *data;
    int length;
} SqList;

void InitSqList(SqList *s) {
    s->data = (elementType*)malloc(sizeof(elementType) * MAXSIZE);
    s->length = 0;
}

int Insert(SqList *s, int i, elementType e) {
    int j;
    if(i<1 || i>(s->length + 1)) return 0;
    for (j = s->length; j >= i; j--)
    {
        (s->data)[j] = (s->data)[j - 1];
    }
    (s->data)[i - 1] = e;
    s->length++;
    return 1;
}

