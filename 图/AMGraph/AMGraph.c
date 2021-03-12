#include "AMGraph.h"
#include "Queue.c"

static FILE* fp = NULL;
int IncInfo = FALSE;
static int visited[MAX_VERTEX_NUM]; //访问标志数组，记录访问过的顶点

int LocateVex(AMGraph G, VerTexType vex) {
    for(int i = 0; i < G.vexnum; i++) {
        if(G.vexs[i] == vex) return i;
    }
    return -1;
}

static Status CreateGraphByConsole(AMGraph *G, int kind) {
    VerTexType v1, v2;
    ArcType w;
    int i, j, k;
    ArcCell arc = {0, NULL};
    if(kind == DN || kind == UDN) {
        arc.w = INFINITE; // stuct结构体初始化和重新赋值
    }

    (*G).kind = kind;
    printf("输入图的当前顶点数:");
    scanf("%d", &((*G).vexnum));
    printf("\n输入图的当前弧数:");
    scanf("%d", &((*G).arcnum));
    printf("\n该有向图的弧上是否包含其他附加信息(0-不包含│1-包含)：");
    scanf("%d", &IncInfo);
    printf("\n输入图的%d个顶点,不同顶点之间用空格隔开:", (*G).vexnum);
    // 录入顶点集
    for(i = 0; i < (*G).vexnum; i++) {
        scanf(" %c", &((*G).vexs[i])); // 从第一个非空字符开始保存
    }
    // 初始化邻接矩阵
    for(i = 0; i < (*G).vexnum; i++) {
        for(j = 0; j < (*G).vexnum; j++) {
            (*G).arcs[i][j] = arc;
        }
    }
    printf("\n依次录入 %d 条弧的信息，顶点之间用空格隔开,输入#结束 ", (*G).arcnum);
    for(k = 0; k < (*G).arcnum; k++) {
        scanf(" %c", &v1);
        scanf(" %c", &v2);
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        if(kind == DN || kind == UDN) {
            scanf("%d", &w);
            (*G).arcs[i][j].w = w; //当为有向网/无向网时存在权值执行
        }else if(kind == DG || kind == UDG) {
            (*G).arcs[i][j].w = 1;
        }
        if(kind == UDN || kind == UDG) {
            (*G).arcs[j][i] = (*G).arcs[i][j]; //当为无向图/网时执行
        }
    }
    return OK;
}

static Status CreateGraphByFile(AMGraph *G, int kind) {
    return OK;
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
        // fp = fopen(path[kind], "r");
        // if(fp == NULL) return ERROR;
        // fscanf(fp, "%d", &((*G).kind));
        CreateGraphByFile(G, kind);
    }

    return OK;
}

Status DestroyGraph(AMGraph *G) {
    (*G).vexnum = 0;
    (*G).arcnum = 0;
    return OK;
}

int FirstAdjVex(AMGraph G, VerTexType v) {
    int kv, j;
    ArcType w;
    kv = LocateVex(G, v);
    if(kv == -1) return -1;
    if(G.kind == DG || G.kind == UDG) {
        w = 0; //图
    }else if(G.kind == DN || G.kind == UDN) {
        w = INFINITE;
    }else {
        return -1;
    }
    for(j = 0; j < G.vexnum; j++) {
        if(G.arcs[kv][j].w != w) {
            return j;
        }
    }
    return -1;
}

int NextAdjVex(AMGraph G, VerTexType v, VerTexType w) {
    int kv, kw, j;
    ArcType adj;
    
    kv = LocateVex(G, v);
    if(kv == -1) {
        return -1;    // 指定的顶点不存在
    }
    
    kw = LocateVex(G, w);
    if(kw == -1) {
        return -1;    // 指定的顶点不存在
    }
    
    // 确定一个非连通标记
    if(G.kind == DG || G.kind == UDG) {
        adj = 0;        // 图
    } else if(G.kind == DN || G.kind == UDN) {
        adj = INFINITE; // 网
    } else {
        return -1;
    }
    
    // 从顶点w后开始查找
    for(j = kw + 1; j < G.vexnum; j++) {
        // 找到与v直接连接的顶点
        if(G.arcs[kv][j].w != adj) {
            return j;
        }
    }
    
    return -1;
}

void DFS(AMGraph G, int v) {
    int w;
    visited[v] = TRUE;
    printf("%c->", G.vexs[v]);
    for(w = FirstAdjVex(G, G.vexs[v]);
        w >= 0;
        w = NextAdjVex(G, G.vexs[v], G.vexs[w])) {
            if(!visited[w]) DFS(G, w);
    }
}

void DFSTraverse(AMGraph G) {
    int i, j;
    for(j = 0; j < G.vexnum; j++) {
        visited[j] = FALSE;
    }
    for(i = 0; i < G.vexnum; i++) {
        if(!visited[i]) DFS(G, i);
    }
}

void BFSTraverse(AMGraph G) {
    int i, j;
    int w;
    LinkQueue Q;
    for(i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }
    // 置空辅助队列
    InitQueue(&Q);

    for(i = 0; i < G.vexnum; i++) {
        if(!visited[i]) {
            visited[i] = TRUE;
            printf("%c->", G.vexs[i]);
            EnQueue(&Q, i);
            while(!QueueEmpty(Q)) {
                DeQueue(&Q, &w);
                for(j = FirstAdjVex(G, G.vexs[w]);
                    j >= 0;
                    j = NextAdjVex(G, G.vexs[w], G.vexs[j])) {
                    if(!visited[j]) {
                        printf("%c->", G.vexs[j]);
                        visited[j] = TRUE;
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}

/*
 * 以图形化形式输出当前结构
 *
 * 注：在图/网中，使用"-"来表示两顶点不直接连通
 */
void PrintGraph(AMGraph G) {
    int i, j;
    
    if(G.vexnum == 0) {
        printf("空图，无需打印！\n");
        return;
    }
    
    printf("当前图/网包含 %d 个顶点， %d 条边/弧...\n", G.vexnum, G.arcnum);
    
    printf("  ");
    for(i = 0; i < G.vexnum; i++) {
        printf("  %c", G.vexs[i]);
    }
    printf("\n");
    
    for(i = 0; i < G.vexnum; i++) {
        printf("%c ", G.vexs[i]);
        
        for(j = 0; j < G.vexnum; j++) {
            if(((G.kind == DG || G.kind == UDG) && G.arcs[i][j].w == 0) || ((G.kind == DN || G.kind == UDN) && G.arcs[i][j].w == INFINITE)) {
                printf("  -");
            } else {
                printf("%3d", G.arcs[i][j].w);
            }
        }
        
        printf("\n");
    }
}

int main() {
    AMGraph G;
    CreateGraph(&G, NULL);
    PrintGraph(G);
    printf("深度遍历图：");
    DFSTraverse(G);
    printf("\n广度遍历图：");
    BFSTraverse(G);
    return 0;
}