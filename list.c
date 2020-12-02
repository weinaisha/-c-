#include <stdio.h>
#define MAXSIZE 20
#define FALSE 0
#define ERROR 0
#define OK 1
#define TRUE 1
typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
}List;

// ADT 线性表（List）
// Data
//     {a1, a2, ..., an}
// Operation
//     initList(*L) 初始化线性表L
//     ListEmpty(L) L是否为空
//     ClearList(*L) 清空L
//     getElem(L, i, *e) 返回L中i位置的元素并用*e返回
//     LocateElem(L, e) 查找L中和e相等的元素并返回下标
//     ListInsert(*L, i, e) 在L中下标为i的位置插入元素e
//     ListDelete(*L, i, *e) 删除L中下标为i的元素并用*e返回
//     ListLength(L) 返回L的长度
// endADT

Status initList(List *L) {
    L->length = 0;
    return OK;
}

Status ListEmpty(List L) {
    if(L.length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int ListLength(List L) {
    return L.length;
}

Status ClearList(*L) {
    // 把每个指针指向NULL 成为空指针
    L->length = 0;
    return OK;
}

Status ListInsert(List *L, int i, ElemType e) {
    if(L->length == MAXSIZE) {
        return ERROR;
    }
    if(i < 1 || i > L->length + 1) return ERROR;
    // ElemType next = 0;
    // ElemType pref = e;
    // for(int j = i - 1; j < L->length + 1; j++) {
    //     next = L->data[j];
    //     L->data[j] = pref;
    //     pref = next;
    //     printf("next=%d ele=%d pref=%d\n", next, L->data[j], pref);
    // }
    for(int j = L->length - 1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete(List *L, int i, ElemType *e) {
    if(L->length == 0) return ERROR;
    *e = L->data[i - 1];
    for(int j = i - 1; j < L->length; j++ ) {
        L->data[j] = L->data[j + 1];
    }
    return OK;
}

ElemType getElem(List L, int i, ElemType *e) {
    if(L.length==0 || i<1 || i>L.length) {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

int locateElem(List L, ElemType e) {
    int i;
    if(L.length == 0) {
        return 0;
    }
    for(i = 0; i < L.length; i++) {
        if(L.data[i] == e) {
            break;
        }
    }
    if(i >= L.length) return 0;
    return i + 1;
}

int main() {
    List L;
    ElemType a;
    ElemType b;
    Status status;
    status = initList(&L);
    int index;
    printf("初始化线性表%d,L.length=%d\n", status, L.length);
    for(int i = 1; i < 6; i++) {
        ListInsert(&L, 1, i);
    }
    for(int i = 0; i < 5; i++) {
        printf("List ele=%d\n", L.data[i]);
    }
    getElem(L, 3, &a);
    printf("test getElem(L, 1, &a): result=%d\n", a);
    index = locateElem(L, 2);
    printf("test locateElem(L, 2): result=%d\n", index);
    ListDelete(&L, 3, &b);
    printf("test listDelete(&L, 3, &b)：删除的第三个元素=%d\n", b);
    for(int i = 0; i < 5; i++) {
        printf("List ele=%d\n", L.data[i]);
    }
    return 0;
}