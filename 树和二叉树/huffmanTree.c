#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 255
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int TElemType;

typedef struct TNode {
    int weight;
    struct TNode *lchild, *rchild, *parent;
} TNode, *HFTree;

/**
 * ����n��Ȩֵ�ֱ�Ϊw1,w2,...,wn�Ľ�㹹���������
 * 1��n�����ֱ���Ϊn�ý���һ�����Ķ�����������ɭ��F
 * 2����F��ѡ��Ȩֵ��С����������Ϊ���ҽ�㣬����һ�������������������ȨֵΪѡ����������Ȩֵ֮��
 * 3����F��ɾ��ѡ�е������������µõ���������F��
 * 4���ظ�2��3����ֱ��F��ֻʣһ����Ϊֹ
*/