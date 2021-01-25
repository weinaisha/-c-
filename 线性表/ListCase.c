#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Elem;
typedef int Status;
typedef struct PNode {
    float coef; //???
    int expn;   //???
    struct PNode *next;
}PNode, *Polynomial;

/**
?????????????
?????????????
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
        printf("?????%d????????????", i);
        scanf("%f%d", &(s->coef), &(s->expn));
        Polynomial pre = *P;                    // pre???????q?????,????????
        Polynomial q = (*P)->next;              // ??????????????????????????????????*q
        while(q && (q->expn < s->expn)) {
            pre = q;
            q = q->next;
        }
        pre->next = s;
        s->next = q;                            // ????????s????q??????????pre???
    }
}

void addPoly(Polynomial *Pa, Polynomial *Pb) {
    Polynomial p1, p2, p3, r;
    p1 = (*Pa)->next;
    p2 = (*Pb)->next;
    p3 = *Pa;
    int sum = 0;
    int p1_i = 1;
    int p2_i = 1;

    while(p1 && p2) {
        printf("??¦Á??: p1->expn=%d, p2->expn=%d\n", p1->expn, p2->expn);
//        printf("P1_i=%d, P2_i=%d\n", p1_i, p2_i);
        if(p1->expn == p2->expn) {
            sum = p1->coef + p2->coef;
            if(sum == 0) {
                printf("??????0\n");
                r = p1;
                p1 = p1->next;
                free(r);
                r = p2;
                p2 = p2->next;
                free(r);
//                PolyDelete(Pa, p1_i);
//                PolyDelete(Pb, p2_i);
            }else {
                p1->coef = sum;
                p3->next = p1;
                p3 = p1;
                r = p2;
                p1 = p1->next;
                p2 = p2->next;
//                p1_i++;
                free(r);
//                PolyDelete(Pb, p2_i);
                printf("????????0??p3->expn=%d, p3->next->expn=%d\n", p3->expn, p3->next->expn);
            }
        } else if(p1->expn < p2->expn) {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
//            p1_i++;
            printf("p1->expn < p2->expn??p3->expn=%d, p3->next->expn=%d\n", p3->expn, p3->next->expn);
        } else {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
//            p2_i++;
            printf("p1->expn > p2->expn??p3->expn=%d, p3->next->expn=%d\n", p3->expn, p3->next->expn);
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
    printf("?????????Pa.length=%d\n", Pa_len);
    for(int i = 1; i < Pa_len+1; i++) {
        Pa_elem = *GetElem(Pa, i);
        printf("%f * x ^ %d", Pa_elem.coef, Pa_elem.expn);
        if(i == Pa_len) {
            printf("\n");
        } else {
            printf(" + ");
        }     
    }
    printf("?????????Pb:");
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
    printf("?????Pa,Pb???:\n");
    addPoly(&Pa, &Pb);
    printf("?????Pa,Pb????? Pa:\n");
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
    printf("?????Pa,Pb????? Pb:\n");
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
