#ifndef SQSTRING_H
#define SQSTRING_H

#include <stdio.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 255
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char ElemType;
typedef char String[MAXSIZE + 1];

Status StrAssign(String S, const char *chars);
/**
�ж�S�Ƿ�Ϊ�մ�
*/
Status StrEmpty(String S);
/**
�Ƚ�S1 S2��S1>S2����1��S1<S2����2��S1==S2����0
*/
int StrCompare(String S1, String S2);
/**
���ش���
*/
int StrLength(String S);
/**
��մ�
*/
void ClearString(String S);
/**
����S1 S2����T�����´�
*/
Status Concat(String S1, String S2, String T);
/**
��S�в��Ҵ�posλ���𳤶�Ϊlen���Ӵ�����sub����
*/
Status SubString(String S, int pos, int len, String sub);
/**
�����Ӵ�T��S����posλ�ú���ֵĵ�һ��λ�ã��������򷵻�0
*/
int Index_KMP(String S, String T, int pos);
/**
�����Ӵ�T��S����posλ�ú���ֵĵ�һ��λ�ã��������򷵻�0
*/
int Index_BF(String S, String T, int pos);
/**
���´�V�滻����S��������T��Ȳ��ص����Ӵ�
*/
Status Replace(String S, String T, String V);
/**
������S�ĵ�posλ��ǰ����T
*/
Status StrInsert(String S, int pos, String T);
/**
������S��ɾ����pos��λ�ó���Ϊlen���Ӵ�
*/
Status StrDelete(String S, int pos, int len);
/**
���ٴ�
*/
void DestroyString(String S);
/**
�����
*/
void StrPrint(String S);

#endif