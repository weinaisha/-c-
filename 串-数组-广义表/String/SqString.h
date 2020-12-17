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
判断S是否为空串
*/
Status StrEmpty(String S);
/**
比较S1 S2，S1>S2返回1，S1<S2返回2，S1==S2返回0
*/
int StrCompare(String S1, String S2);
/**
返回串长
*/
int StrLength(String S);
/**
清空串
*/
void ClearString(String S);
/**
连接S1 S2并用T返回新串
*/
Status Concat(String S1, String S2, String T);
/**
在S中查找从pos位置起长度为len的子串并用sub返回
*/
Status SubString(String S, int pos, int len, String sub);
/**
查找子串T在S主串pos位置后出现的第一个位置，不存在则返回0
*/
int Index_KMP(String S, String T, int pos);
/**
查找子串T在S主串pos位置后出现的第一个位置，不存在则返回0
*/
int Index_BF(String S, String T, int pos);
/**
用新串V替换主串S中所有与T相等不重叠的子串
*/
Status Replace(String S, String T, String V);
/**
在主串S的第pos位置前插入T
*/
Status StrInsert(String S, int pos, String T);
/**
在主串S中删除第pos个位置长度为len的子串
*/
Status StrDelete(String S, int pos, int len);
/**
销毁串
*/
void DestroyString(String S);
/**
输出串
*/
void StrPrint(String S);

#endif