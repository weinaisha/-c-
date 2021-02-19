#ifndef AMGRAPH_H
#define AMGRAPH_H

#include <stdio.h>
#include <limits.h> //�ṩ��INT_MAX
#include <string.h> //�ṩmemset strcmpԭ��
#include <stdarg.h> 
/**
* stdarg.h ͷ�ļ�������һ���������� va_list ��������va_start va_arg va_end��
* ��������������ڲ�������δ֪�������������ɱ䣩ʱ��ȡ�����еĲ�
*/

/**
�ڽӾ����ʾ
*/
#define MAX_VERTEX_NUM 26
#define INFINITE INT_MAX
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef char VerTexType; //���趥�����������Ϊ�ַ���
/*
 * �����ϵ����
 *
 * ����Ȩͼ�У���ֵͨ��Ϊ0��1����ʾ�������Ƿ�ֱ����ͨ��
 * ����Ȩͼ�У���ֵͨ��ΪȨֵ��
 */
typedef int ArcType;

// ͼ������
typedef enum {
    DG,     // 0-����ͼ
    DN,     // 1-������(��Ȩֵ)
    UDG,    // 2-����ͼ
    UDN     // 3-������(��Ȩֵ)
} GraphKind;

// �ߵ���ظ�����Ϣ
typedef struct {
    // ����еĻ��������������Ӧ������
    void* v; // ���һ��������ı�����ռλ������ṹ��Ϊ�յĻ�����VC++�лᱨ��
} InfoType;

// �ߵ����ͣ�ÿ�����Ͽ����и�����Ϣinfo
typedef struct ArcCell {
    ArcType w;  // �����ϵ������Ȩͼ����Ȩͼ�еĺ��岻ͬ
    InfoType* info; // �ߵĸ�����Ϣ��ͨ������
} ArcCell;

typedef struct {
    VerTexType vexs[MAX_VERTEX_NUM]; //�����
    ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //�ڽӾ���
    int vexnum, arcnum; //ͼ�ĵ�ǰ�����ͱ���
    GraphKind kind;
} AMGraph;

Status CreateGraph(AMGraph *G, char *path[]);

int LocateVex(AMGraph G, VerTexType vex);

/*
 * �׸��ڽӵ�
 *
 * ���ض���v���׸��ڽӵ�
 */
int FirstAdjVex(AMGraph G, VerTexType v);

/*
 * ��һ���ڽӵ�
 *
 * ���ض���v��(�����w��)��һ���ڽӵ�
 */
int NextAdjVex(AMGraph G, VerTexType v, VerTexType w);

Status DestroyGraph(AMGraph *G);

// GetVex();

// PutVex();

// InsetVex();

// DeleteVex();

// InsertVrc();

// DeleteVrc();

void DFSTraverse(AMGraph G);

// ������ȱ���
void DFS(AMGraph G, int v);

void BFSTraverse(AMGraph G);

#endif