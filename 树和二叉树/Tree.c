#include <stdio.h>

#define MAXSIZE 100
typedef char ElemType;

// ����˫�ױ�ʾ��
typedef struct
{
    ElemType data;
    int parent; //˫��λ����
} PTNode;

typedef struct
{
    PTNode node[MAXSIZE]; // ˫�ױ�ʾ
    int n; // �����
} PTree;

// ���ӱ�ʾ������ÿ�����ĺ��Ӷ��õ��������������γ�һ�����Խṹ

// �����ֵܱ�ʾ��
