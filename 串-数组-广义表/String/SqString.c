#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 255
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char ElemType;
// typedef char String[MAXSIZE + 1];
typedef struct {
    char *ch;
} String;

Status StrInit(String *S) {
    S->ch = (char*)malloc(sizeof(char) * MAXSIZE);
    if(!S) exit(ERROR);
    return OK;
}

/**
 * 生成一个其值等于chars的串S
*/
Status StrAssign(String *S, const char *chars) {
    int i, len;
    len = (int)strlen(chars);
    if(len > MAXSIZE) return ERROR;
    (S->ch)[0] = len;
    for (i = 1; i <= len; i++)
    {
        (S->ch)[i] = chars[i - 1];
    }
    return OK;
}

/**
 * 复制操作 由串T复制得到串S
*/
Status StrCopy(String S, String T);

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
在S中查找从pos位置起长度为len的子串并用sub返回
*/
Status SubString(String S, int pos, int len, String sub);

/**
连接S1 S2并用T返回新串
*/
Status Concat(String S1, String S2, String T);

/**
查找子串T在S主串pos位置后出现的第一个位置，不存在则返回0
*/
int Index_KMP(String S, String T, int pos) {
    int i = pos, j = 1, m = S.ch[0], n = T.ch[0];
    while (i <= m && j <= n)
    {
        if(j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else
        {
            // j = next[j];
        }
    }
    if(j > n) return i - n;
    return 0;
}

void get_next(String T, int *next) {}

/**
查找子串T在S主串pos位置后出现的第一个位置，不存在则返回0
*/
int Index_BF(String S, String T, int pos) {
    int i = pos, j = 1, m = S.ch[0], n = T.ch[0];
    while (i <= m && j <= n)
    {
        if(S.ch[i] == T.ch[j]) { // 继续比较后续字符
            i++;
            j++;
        } else // 指针后退重新比较
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if(j >= n) return i - n; // 匹配成功
    return 0; // 匹配失败
}


/**
清空串
*/
void ClearString(String S);

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
void StrPrint(String S) {
    int i;
    for (i = 1; i <= S.ch[0]; i++)
    {
        printf("%c", S.ch[i]);
    }
    printf("\n");
};

int main() {
    String S;
    String T;
    int position;
    char* chars = "helloworld";
    char* s1 = "worod";
    StrInit(&S);
    StrAssign(&S, chars);
    printf("输出主串：");
    StrPrint(S);
    
    StrInit(&T);
    StrAssign(&T, s1);
    printf("输出子串：");
    StrPrint(T);
    position = Index_BF(S, T, 1);
    printf("BF：从第一个位置匹配,匹配结果%d\n", position);
    return 0;
}
