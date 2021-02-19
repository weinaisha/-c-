#ifndef AMGRAPH_H
#define AMGRAPH_H

#include <stdio.h>
#include <limits.h> //提供宏INT_MAX
#include <string.h> //提供memset strcmp原型
#include <stdarg.h> 
/**
* stdarg.h 头文件定义了一个变量类型 va_list 和三个宏va_start va_arg va_end，
* 这三个宏可用于在参数个数未知（即参数个数可变）时获取函数中的参
*/

/**
邻接矩阵表示
*/
#define MAX_VERTEX_NUM 26
#define INFINITE INT_MAX
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef char VerTexType; //假设顶点的数据类型为字符型
/*
 * 顶点关系类型
 *
 * 在无权图中，该值通常为0或1，表示两顶点是否直接连通；
 * 在有权图中，该值通常为权值。
 */
typedef int ArcType;

// 图的类型
typedef enum {
    DG,     // 0-有向图
    DN,     // 1-有向网(带权值)
    UDG,    // 2-无向图
    UDN     // 3-无向网(带权值)
} GraphKind;

// 边的相关附加信息
typedef struct {
    // 如果有的话，后续会添加相应的属性
    void* v; // 添加一个无意义的变量来占位，如果结构体为空的话，在VC++中会报错
} InfoType;

// 边的类型，每条边上可能有附加信息info
typedef struct ArcCell {
    ArcType w;  // 顶点关系，在有权图跟无权图中的含义不同
    InfoType* info; // 边的附加信息，通常忽略
} ArcCell;

typedef struct {
    VerTexType vexs[MAX_VERTEX_NUM]; //顶点表
    ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    int vexnum, arcnum; //图的当前点数和边数
    GraphKind kind;
} AMGraph;

Status CreateGraph(AMGraph *G, char *path[]);

int LocateVex(AMGraph G, VerTexType vex);

/*
 * 首个邻接点
 *
 * 返回顶点v的首个邻接点
 */
int FirstAdjVex(AMGraph G, VerTexType v);

/*
 * 下一个邻接点
 *
 * 返回顶点v的(相对于w的)下一个邻接点
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

// 深度优先遍历
void DFS(AMGraph G, int v);

void BFSTraverse(AMGraph G);

#endif