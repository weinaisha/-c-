#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Elem;
typedef int Status;
typedef struct PNode {
    float coef; //系数
    int expn;   //指数
    struct PNode *next;
}PNode, *Polynomial;

/**
案例分析与实现
稀疏多项式的运算
A(x)=7+3x(1)+9x(8)+5x(17)
B(x)=8x(1)+22x(7)-9x(8)
*/

int PolynomialLength(Polynomial P) {
    int i = 0;
    Polynomial q = P->next;
    while(q) {
        q = q->next;
        i++;
    }
    return i;
}

PNode *GetElem(Polynomial P, int i) {
    int j = 1;
    Polynomial q = P->next;
    while(q && j < i) {
        q = q->next;
        j++;
    }
    return q;
}

Status PolyDelete(Polynomial *P, int i) {
    Polynomial p = *P;
    Polynomial q;
    int j = 0;
    while(p && j < i - 1) {
        p = p->next;
        j++;
    }
    if(!p || j>i-1) return ERROR;
    q = p->next;
    p->next = q->next;
    printf("delete: coef=%f, expn=%d\n", q->coef, q->expn);
    free(q);
    return OK;
}

void CreatePoly(Polynomial *P, int n) {
    *P = (Polynomial)malloc(sizeof(struct PNode));
    (*P)->next = NULL;
    for(int i = 1; i <= n; i++) {
        Polynomial s = (Polynomial)malloc(sizeof(struct PNode));
        printf("输入第%d项系数和指数：", i);
        scanf("%f%d", &(s->coef), &(s->expn));
        Polynomial pre = *P;                    // pre用于保存q的前驱,初值为头结点
        Polynomial q = (*P)->next;              // 通过比较指数找到第一个大于输入项指数的项*q
        while(q && (q->expn < s->expn)) {
            pre = q;
            q = q->next;
        }
        pre->next = s;
        s->next = q;                            // 将输入项s插入到q和其前驱结点pre之间
    }
}

void addPoly(Polynomial *Pa, Polynomial *Pb) {
    Polynomial p1, p2, p3;
    p1 = (*Pa)->next;
    p2 = (*Pb)->next;
    p3 = *Pa;
    int sum = 0;
    int p1_i = 1;
    int p2_i = 1;

    while(p1 && p2) {
        printf("每次比较: p1->expn=%d, p2->expn=%d\n", p1->expn, p2->expn);
        printf("P1_i=%d, P2_i=%d\n", p1_i, p2_i);
        if(p1->expn == p2->expn) {
            sum = p1->coef + p2->coef;
            if(sum == 0) {
                printf("相加等于0\n");
                p1 = p1->next;
                p2 = p2->next;
                PolyDelete(Pa, p1_i);
                PolyDelete(Pb, p2_i);
            }else {
                p1->coef = sum;
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
                p2 = p2->next;
                p1_i++;
                PolyDelete(Pb, p2_i);
                printf("相加不等于0，p3->expn=%d, p3->next->expn=%d\n", p3->expn, p3->next->expn);
            }
        } else if(p1->expn < p2->expn) {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
            p1_i++;
            printf("p1->expn < p2->expn，p3->expn=%d, p3->next->expn=%d\n", p3->expn, p3->next->expn);
        } else {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
            p2_i++;
            printf("p1->expn > p2->expn，p3->expn=%d, p3->next->expn=%d\n", p3->expn, p3->next->expn);
        }
    }
    p3->next = p1 ? p1 : p2;
    free(Pb);
}

int main() {
    Polynomial Pa, Pb;
    PNode Pa_elem, Pb_elem;
    int Pa_len = 0;
    int Pb_len = 0;
    CreatePoly(&Pa, 4);
    Pa_len = PolynomialLength(Pa);
    printf("创建多项式Pa.length=%d\n", Pa_len);
    for(int i = 1; i < Pa_len+1; i++) {
        Pa_elem = *GetElem(Pa, i);
        printf("%f * x ^ %d", Pa_elem.coef, Pa_elem.expn);
        if(i == Pa_len) {
            printf("\n");
        } else {
            printf(" + ");
        }     
    }
    printf("创建多项式Pb:");
    CreatePoly(&Pb, 3);
    Pb_len = PolynomialLength(Pb);
    for(int j = 1; j < Pb_len+1; j++) {
        Pb_elem = *GetElem(Pb, j);
        printf("%f * x ^ %d", Pb_elem.coef, Pb_elem.expn);
        if(j == Pb_len) {
            printf("\n");
        } else {
            printf(" + ");
        }
    }
    printf("多项式Pa,Pb相加:\n");
    addPoly(&Pa, &Pb);
    printf("多项式Pa,Pb相加结果 Pa:\n");
    Pa_len = PolynomialLength(Pa);
    for(int i = 1; i < Pa_len+1; i++) {
        Pa_elem = *GetElem(Pa, i);
        printf("%f * x ^ %d", Pa_elem.coef, Pa_elem.expn);
        if(i == Pa_len) {
            printf("\n");
        } else {
            printf(" + ");
        }     
    }
    printf("多项式Pa,Pb相加结果 Pb:\n");
    Pb_len = PolynomialLength(Pb);
    for(int j = 1; j < Pb_len+1; j++) {
        Pb_elem = *GetElem(Pb, j);
        printf("%f * x ^ %d", Pb_elem.coef, Pb_elem.expn);
        if(j == Pb_len) {
            printf("\n");
        } else {
            printf(" + ");
        }
    }
    return 0;
}
