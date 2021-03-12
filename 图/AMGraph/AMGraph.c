#include "AMGraph.h"
#include "Queue.c"

static FILE* fp = NULL;
int IncInfo = FALSE;
static int visited[MAX_VERTEX_NUM]; //���ʱ�־���飬��¼���ʹ��Ķ���

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
        arc.w = INFINITE; // stuct�ṹ���ʼ�������¸�ֵ
    }

    (*G).kind = kind;
    printf("����ͼ�ĵ�ǰ������:");
    scanf("%d", &((*G).vexnum));
    printf("\n����ͼ�ĵ�ǰ����:");
    scanf("%d", &((*G).arcnum));
    printf("\n������ͼ�Ļ����Ƿ��������������Ϣ(0-��������1-����)��");
    scanf("%d", &IncInfo);
    printf("\n����ͼ��%d������,��ͬ����֮���ÿո����:", (*G).vexnum);
    // ¼�붥�㼯
    for(i = 0; i < (*G).vexnum; i++) {
        scanf(" %c", &((*G).vexs[i])); // �ӵ�һ���ǿ��ַ���ʼ����
    }
    // ��ʼ���ڽӾ���
    for(i = 0; i < (*G).vexnum; i++) {
        for(j = 0; j < (*G).vexnum; j++) {
            (*G).arcs[i][j] = arc;
        }
    }
    printf("\n����¼�� %d ��������Ϣ������֮���ÿո����,����#���� ", (*G).arcnum);
    for(k = 0; k < (*G).arcnum; k++) {
        scanf(" %c", &v1);
        scanf(" %c", &v2);
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        if(kind == DN || kind == UDN) {
            scanf("%d", &w);
            (*G).arcs[i][j].w = w; //��Ϊ������/������ʱ����Ȩִֵ��
        }else if(kind == DG || kind == UDG) {
            (*G).arcs[i][j].w = 1;
        }
        if(kind == UDN || kind == UDG) {
            (*G).arcs[j][i] = (*G).arcs[i][j]; //��Ϊ����ͼ/��ʱִ��
        }
    }
    return OK;
}

static Status CreateGraphByFile(AMGraph *G, int kind) {
    return OK;
}

Status CreateGraph(AMGraph *G, char* path[]) {
    int readFromConsole; //�Ƿ�ӿ���̨��ȡ����
    int kind; 
    
    printf("����ͼ������(0-����ͼ �� 1-������ �� 2-����ͼ �� 3-������)��");
    scanf("%d", &kind);
    // ���Ͳ��Ϲ�
    if(kind < 0 || kind > 3) {
        return ERROR;
    }
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
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
        w = 0; //ͼ
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
        return -1;    // ָ���Ķ��㲻����
    }
    
    kw = LocateVex(G, w);
    if(kw == -1) {
        return -1;    // ָ���Ķ��㲻����
    }
    
    // ȷ��һ������ͨ���
    if(G.kind == DG || G.kind == UDG) {
        adj = 0;        // ͼ
    } else if(G.kind == DN || G.kind == UDN) {
        adj = INFINITE; // ��
    } else {
        return -1;
    }
    
    // �Ӷ���w��ʼ����
    for(j = kw + 1; j < G.vexnum; j++) {
        // �ҵ���vֱ�����ӵĶ���
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
    // �ÿո�������
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
 * ��ͼ�λ���ʽ�����ǰ�ṹ
 *
 * ע����ͼ/���У�ʹ��"-"����ʾ�����㲻ֱ����ͨ
 */
void PrintGraph(AMGraph G) {
    int i, j;
    
    if(G.vexnum == 0) {
        printf("��ͼ�������ӡ��\n");
        return;
    }
    
    printf("��ǰͼ/������ %d �����㣬 %d ����/��...\n", G.vexnum, G.arcnum);
    
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
    printf("��ȱ���ͼ��");
    DFSTraverse(G);
    printf("\n��ȱ���ͼ��");
    BFSTraverse(G);
    return 0;
}