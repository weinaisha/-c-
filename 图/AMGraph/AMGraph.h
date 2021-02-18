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
#define MVNum 26
#define MaxInt INT_MAX
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef char VerTexType; //假设顶点的数据类型为字符型

// 图的类型
typedef enum {
    DG,     // 0-有向图
    DN,     // 1-有向网(带权值)
    UDG,    // 2-无向图
    UDN     // 3-无向网(带权值)
} GraphKind;

/*
 * 顶点关系类型
 *
 * 在无权图中，该值通常为0或1，表示两顶点是否直接连通；
 * 在有权图中，该值通常为权值。
 */
typedef int ArcType;

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
    VerTexType vexs[MVNum]; //顶点表
    ArcCell arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum, arcnum; //图的当前点数和边数
    GraphKind kind;
} AMGraph;

// 边/弧上是否存在附加信息
extern Boolean IncInfo;

Status CreateGraph(AMGraph *G, char *path[]);

/*
 * 构造有向图
 */
static Status CreateDG(AMGraph *G);

/*
 * 构造有向网
 */
static Status CreateDN(AMGraph *G);

/*
 * 构造无向图
 */
static Status CreateUDG(AMGraph *G);

/*
 * 构造无向网
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