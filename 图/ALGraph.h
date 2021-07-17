#include <stdio.h>

#define MaxVertexNum 100

typedef char ElemType;

// 边表结点
typedef struct {
    int adjvex; // 该弧所指向的弧的顶点位置
    struct ArcNode *next;  //指向下一条弧的指针
} ArcNode;

// 顶点表结点
typedef struct {
    ElemType data;  // 顶点信息
    ArcNode *first;  // 指向第一条衣服该顶点的弧的指针
} VexNode, AdjList[MaxVertexNum];

// 邻接表
typedef struct {
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
} ALGraph;

// 判断图G是否存在边<x, y>或(x, y)
int Adjacent(ALGraph G, ElemType x, ElemType y);

// 列出图G中与结点x邻接的边
void Neighbors(ALGraph G, ElemType x);

// 在图G中插入顶点x
void InsetVex(ALGraph *G, ElemType x);

// 在图G中删除顶点x, 顶点表删除，边表中和顶点x有关的边
void DeleteVex(ALGraph *G, ElemType x);

// 若无向边(x, y)或有向边<x, y>不存在，则向图G中添加边
void InsertVrc(ALGraph *G, ElemType x, ElemType y);

// 若无向边(x, y)或有向边<x, y>存在，则向图G中删除边
void DeleteVrc(ALGraph *G, ElemType x, ElemType y);

// 求图中顶点x的第一个邻接点，若有返回顶点号，若没有邻接点或图中不存在x返回-1
int FirstAdjVex(ALGraph G, ElemType x);

// 若图G中顶点y是顶点x的一个邻接点，返回除y以外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1
int NextAdjVex(ALGraph G, ElemType x, ElemType y);

void CreateGraph();

void DestroyGraph();

void LocateGraph();

void GetVex();

void PutVex();

void DFSTraverse();

void BFSTraverse();

