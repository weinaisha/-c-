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
#define MVNum 26
#define MaxInt INT_MAX
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef char VerTexType; //���趥�����������Ϊ�ַ���

// ͼ������
typedef enum {
    DG,     // 0-����ͼ
    DN,     // 1-������(��Ȩֵ)
    UDG,    // 2-����ͼ
    UDN     // 3-������(��Ȩֵ)
} GraphKind;

/*
 * �����ϵ����
 *
 * ����Ȩͼ�У���ֵͨ��Ϊ0��1����ʾ�������Ƿ�ֱ����ͨ��
 * ����Ȩͼ�У���ֵͨ��ΪȨֵ��
 */
typedef int ArcType;

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
    VerTexType vexs[MVNum]; //�����
    ArcCell arcs[MVNum][MVNum]; //�ڽӾ���
    int vexnum, arcnum; //ͼ�ĵ�ǰ�����ͱ���
    GraphKind kind;
} AMGraph;

// ��/�����Ƿ���ڸ�����Ϣ
extern Boolean IncInfo;

Status CreateGraph(AMGraph *G, char *path[]);

/*
 * ��������ͼ
 */
static Status CreateDG(AMGraph *G);

/*
 * ����������
 */
static Status CreateDN(AMGraph *G);

/*
 * ��������ͼ
 */
static Status CreateUDG(AMGraph *G);

/*
 * ����������
 */
static Status CreateUDG(AMGraph *G);

int LocateVex(AMGraph *G, VerTexType vex);

FirstAdjVex();

NextAdjVex();

DestroyGraph();

GetVex();

PutVex();

InsetVex();

DeleteVex();

InsertVrc();

DeleteVrc();

DFSTraverse();

BFSTraverse();

#endif