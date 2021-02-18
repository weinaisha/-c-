#include "AMGraph.h"

static FILE* fp = NULL;
Boolean IncInfo = FALSE;
int LocateVex(AMGraph *G, VerTexType vex) {
    for(int i = 0; i < G->vexnum; i++) {
        if((G->vexs)[i] == vex) return i;
    }
    return '\0';
}

Status CreateGraph(AMGraph *G, char* path[]) {
    int readFromConsole; //是否从控制台读取数据
    int kind; 
    
    printf("输入图的类型(0-有向图 │ 1-有向网 │ 2-无向图 │ 3-无向网)：");
    scanf("%d", &kind);
    // 类型不合规
    if(kind < 0 || kind > 3) {
        return ERROR;
    }
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = (path == NULL) || strcmp(path[kind], "") == 0;
    if(readFromConsole) {
        CreateGraphByConsole(G, kind);
    } else {
        fp = fopen(path[kind], "r");
        if(fp == NULL) return ERROR;
        fscanf(fp, "%d", &((*G).kind));
        CreateGraphByFile(G);
    }

    return OK;
}

static Status CreateGraphByConsole(AMGraph *G, int kind) {
    VerTexType v1, v2;
    ArcType w;
    int i, j, k;
    if(kind == 0 || kind == 2) {
        ArcCell arcs = {0, NULL};   // 有向/无向图每条边的初始值
    }else {
        ArcCell arcs = {INFINITE, NULL};   // 有向/无向网每条边的初始值
    }
    (*G).kind = kind;
    printf("输入图的当前顶点数:");
    scanf("%d", &((*G).vexnum));
    printf("\n输入图的当前弧数:");
    scanf("%d", &((*G).arcnum));
    printf("\n该有向图的弧上是否包含其他附加信息(0-不包含│1-包含)：");
    scanf("%d", &IncInfo);
    printf("\n输入图的%d个顶点,不同顶点之间用空格隔开:", &(*G).vexnum);
    // 录入顶点集
    for(i = 0; i < (*G).vexnum; i++) {
        scanf("%d", &((*G).vexs[i]));
    }
    // 初始化邻接矩阵
    for(i = 0; i < (*G).vexnum; i++) {
        for(j = 0; j < (*G).vexnum; j++) {
            (*G).arcs[i][j] = arcs;
        }
    }
    printf("\n依次录入 %d 条弧的信息，顶点之间用空格隔开：\n", (*G).arcnum);
    for(k = 0; k < arcnum; k++) {
        scanf("%c", &v1);
        scanf("%c", &v2);
        scanf("%d", &w);
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        if(kind == 1 || kind == 3) {
            (*G).vexs[i][j].w = w; //当为有向网/无向网时存在权值执行
        }else {
            (*G).vexs[i][j].w = 1;
        }
        if(kind == 2 || kind == 3) {
            (*G).vexs[j][i] = (*G).vexs[i][j]; //当为无向图/网时执行
        }
    }
    return OK;
}

static Status CreateGraphByFile(AMGraph *G, int kind) {
    return OK;
}

int main() {
    AMGraph G;
    CreateGraph(&G);
    return 0;
}