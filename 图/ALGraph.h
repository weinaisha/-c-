#include <stdio.h>

#define MaxVertexNum 100

typedef char ElemType;

// �߱���
typedef struct {
    int adjvex; // �û���ָ��Ļ��Ķ���λ��
    struct ArcNode *next;  //ָ����һ������ָ��
} ArcNode;

// �������
typedef struct {
    ElemType data;  // ������Ϣ
    ArcNode *first;  // ָ���һ���·��ö���Ļ���ָ��
} VexNode, AdjList[MaxVertexNum];

// �ڽӱ�
typedef struct {
    AdjList vertices;   // �ڽӱ�
    int vexnum, arcnum; // ͼ�Ķ������ͻ���
} ALGraph;

// �ж�ͼG�Ƿ���ڱ�<x, y>��(x, y)
int Adjacent(ALGraph G, ElemType x, ElemType y);

// �г�ͼG������x�ڽӵı�
void Neighbors(ALGraph G, ElemType x);

// ��ͼG�в��붥��x
void InsetVex(ALGraph *G, ElemType x);

// ��ͼG��ɾ������x, �����ɾ�����߱��кͶ���x�йصı�
void DeleteVex(ALGraph *G, ElemType x);

// �������(x, y)�������<x, y>�����ڣ�����ͼG����ӱ�
void InsertVrc(ALGraph *G, ElemType x, ElemType y);

// �������(x, y)�������<x, y>���ڣ�����ͼG��ɾ����
void DeleteVrc(ALGraph *G, ElemType x, ElemType y);

// ��ͼ�ж���x�ĵ�һ���ڽӵ㣬���з��ض���ţ���û���ڽӵ��ͼ�в�����x����-1
int FirstAdjVex(ALGraph G, ElemType x);

// ��ͼG�ж���y�Ƕ���x��һ���ڽӵ㣬���س�y���ⶥ��x����һ���ڽӵ�Ķ���ţ���y��x�����һ���ڽӵ㣬�򷵻�-1
int NextAdjVex(ALGraph G, ElemType x, ElemType y);

void CreateGraph();

void DestroyGraph();

void LocateGraph();

void GetVex();

void PutVex();

void DFSTraverse();

void BFSTraverse();

