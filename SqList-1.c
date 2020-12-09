#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
#define OVERFLOW 0

typedef int Status;
typedef int ElementType;
typedef struct
{
    ElementType *elem;
    int length;
} SqList;

Status InitList(SqList *L) {
    L->elem = (ElementType*)malloc(MAXSIZE * sizeof(ElementType));
    if(!L->elem) exit(OVERFLOW);
    L->length = 0;
    return OK;
}

Status ListInsert(SqList *L, int i, ElementType e) {
    if(i < 1 || i > L->length + 1) return ERROR; // 判断插入位置是否合法
    if(L->length == MAXSIZE) return ERROR; // 判断顺序表的存储空间是否已满
    for (int j = L->length -1; j >= i - 1; j--)
    {
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i - 1] = e;
    ++L->length;
    return OK;
}

Status GetElem(SqList *L, int i, ElementType *e) {
    if(i<1 || i>L->length) return ERROR;
    *e = L->elem[i - 1];
    return OK;
}

int LocateElem(SqList *L, ElementType e) {
    for (int i = 0; i < L->length; i++)
    {
        if(L->elem[i] == e) return i+1;
    }
    return 0;
}

Status ListDelete(SqList *L, int i) {
    if(i<1 || i > L->length + 1) return ERROR;
    ElementType e = L->elem[i - 1];
    for (int j = i - 1; j < L->length; j++)
    {
       L->elem[j] = L->elem[j + 1];
    }
    -- L->length;
    return OK;
}

int main() {
    SqList L;
    InitList(&L);
    ElementType e;
    printf("test InitList: L.length=%d\n", L.length);
    for (int i = 1; i < 6; i++)
    {
        ListInsert(&L, 1, i);
    }
    printf("test ListInsert: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("L[%d]=%d\t", i, L.elem[i]);
    }
    printf("\ntest ListInsert end \n");
    GetElem(&L, 2, &e);
    printf("test GetElem: The value is %d of order 2 \n", e);
    printf("test LocateElem: The order of 2 is %d\n", LocateElem(&L, 2));
    printf("test ListDelete order 1: \n");
    ListDelete(&L, 1);
    for (int i = 0; i < 5; i++)
    {
        printf("L[%d]=%d\t", i, L.elem[i]);
    }
    printf("\ntest ListDelete end \n");
    return 0;
}