#include <stdio.h>
#include <stdlib.h>

/**
 * 线索二叉树
*/

#define OK 1;
#define ERROR 0;
typedef char ElemType;
typedef int Status;

/**
 * LTag=0,LChild指向结点左孩子，LTag=1,LChild指向结点前驱
 * RTag=0,RChild指向结点右孩子，RTag=1,RChild指向结点后继
*/
typedef struct ThrNode {
    ElemType data;
    struct ThrNode *LChild, *RChild;
    int LTag, RTag;
} ThrNode, *BiThrTree;

BiThrTree pre;

// 杩斿洖鎸囧悜浜屽弶鏍戠粨鐐筫鐨勬寚閽?
static BiThrTree EPtr(BiThrTree T, ElemType e) {
    BiThrTree p;
    p = T->LChild;
    while(p != T) {
        while(p->LTag == 0) p = p->LChild; // 左孩子
        if(p->data == e) return p;
        while(p->RTag == 1 && p->RChild != T) {
            p = p->RChild; // 后继
            if(p->data == e) return p;
        }
        p = p->RChild;
    }
    return NULL;
}

Status CreateBiTree(BiThrTree *T) {
    char ch;
    scanf("%c", &ch);
    if(ch == '#') *T = NULL;
    else {
        *T = (BiThrTree)malloc(sizeof(struct ThrNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->LChild));
        CreateBiTree(&((*T)->RChild));
    }
    return OK;
}

//中序遍历对二叉树线索化
void InThreading(BiThrTree *p) {
    if(*p) {
        InThreading(&((*p)->LChild));
        if(!(*p)->LChild) {
            (*p)->LTag = 1;     // 前驱
            (*p)->LChild = pre; // 左指针为空指向p的前驱pre
        } else {
            (*p)->LTag = 0;
        }
        if(!(pre->RChild)) {
            pre->RChild = *p; // pre右指针为空指向p
            pre->RTag = 1;   // 标志为后继
        }
        else (*p)->RTag = 0;
        pre = *p;
        InThreading(&((*p)->RChild));
    }
}

// 通过中序遍历建立中序线索二叉树
void InOrderThreading(BiThrTree *Thrt, BiThrTree *T) {
    *Thrt = (BiThrTree)malloc(sizeof(ThrNode));
    (*Thrt)->LTag = 0;
    (*Thrt)->RTag = 1;
    (*Thrt)->RChild = (*Thrt);
    if(!(*T)) (*Thrt)->LChild = *Thrt;
    else {
        (*Thrt)->LChild = *T;
        pre = *Thrt;
        InThreading(&(*T));
        pre->RChild = (*Thrt); // 处理遍历的最后一个结点
        pre->RTag = 1;
        (*Thrt)->RChild = pre;
    }
}

// 閬嶅巻涓簭绾跨储浜屽弶鏍?
void InOrderTraverse_Thr(BiThrTree T) {
    BiThrTree p;
    p = T->LChild;
    while(p != T) {
        while(p->LTag == 0) p = p->LChild; // 娌垮乏瀛╁瓙鍚戜笅
        printf("%c", p->data);
        while(p->RTag == 1 && p->RChild != T) {
            p = p->RChild; // 娌垮彸绾跨储璁块棶鍚庣户缁撶偣
            printf("%c", p->data);
        }
        p = p->RChild;
    }
}

ElemType ValuePre(BiThrTree T) {
    BiThrTree p;
    if(!T) return '\0';
    if(T->LTag == 1) return T->LChild->data;
    else {
        p = T->LChild;
        while(p->LTag == 0) p = p->LChild;
        return p->data;
    }
}

ElemType ValueNext(BiThrTree T) {
    BiThrTree p;
    if(!T) return '\0';
    if(T->RTag == 1) return T->RChild->data;
    else {
        p = T->RChild;
        while(p->LTag == 0) p = p->LChild;
        return p->data;
    }
}

void InOrderTraverse(BiThrTree T) {
    if(T) {
        InOrderTraverse(T->LChild);
        printf("%c", T->data);
        InOrderTraverse(T->RChild);
    }
}

int main() {
    BiThrTree T;
    BiThrTree ThrTree;
    BiThrTree p1; 
    BiThrTree p2;
    Status status;
    status = CreateBiTree(&T);
    printf("鍒涘缓浜屽弶鏍? status=%d\n", status);
    InOrderTraverse(T);
    printf("閬嶅巻涓簭浜屽弶鏍慭n");
    InOrderThreading(&ThrTree, &T);
    InOrderTraverse_Thr(ThrTree);
    printf("閬嶅巻涓簭绾跨储浜屽弶鏍慭n");
    p1 = EPtr(ThrTree, 'A');
    printf("鏌ユ壘A缁撶偣鐨勬寚閽?=%c\n", p1->data);
    printf("A鐨勫墠椹?=%c\n", ValuePre(p1));
    printf("A鐨勫悗椹?=%c\n", ValueNext(p1));
    p2 = EPtr(ThrTree, 'C');
    printf("鏌ユ壘C缁撶偣鐨勬寚閽?=%c\n", p2->data);
    printf("C鐨勫墠椹?=%c\n", ValuePre(p2));
    printf("C鐨勫悗椹?=%c\n", ValueNext(p2));
    return 0;
}
