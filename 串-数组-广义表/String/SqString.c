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
 * ����һ����ֵ����chars�Ĵ�S
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
 * ���Ʋ��� �ɴ�T���Ƶõ���S
*/
Status StrCopy(String S, String T);

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
��S�в��Ҵ�posλ���𳤶�Ϊlen���Ӵ�����sub����
*/
Status SubString(String S, int pos, int len, String sub);

/**
����S1 S2����T�����´�
*/
Status Concat(String S1, String S2, String T);

/**
�����Ӵ�T��S����posλ�ú���ֵĵ�һ��λ�ã��������򷵻�0
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
�����Ӵ�T��S����posλ�ú���ֵĵ�һ��λ�ã��������򷵻�0
*/
int Index_BF(String S, String T, int pos) {
    int i = pos, j = 1, m = S.ch[0], n = T.ch[0];
    while (i <= m && j <= n)
    {
        if(S.ch[i] == T.ch[j]) { // �����ȽϺ����ַ�
            i++;
            j++;
        } else // ָ��������±Ƚ�
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if(j >= n) return i - n; // ƥ��ɹ�
    return 0; // ƥ��ʧ��
}


/**
��մ�
*/
void ClearString(String S);

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
    printf("���������");
    StrPrint(S);
    
    StrInit(&T);
    StrAssign(&T, s1);
    printf("����Ӵ���");
    StrPrint(T);
    position = Index_BF(S, T, 1);
    printf("BF���ӵ�һ��λ��ƥ��,ƥ����%d\n", position);
    return 0;
}
