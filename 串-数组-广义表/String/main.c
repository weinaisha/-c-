#include <stdio.h>
#include "SqString.c"

int main() {
    String S;
    String sub;
    Status status;
    char *chars = "acabaabaabcacaabc";
    printf("���� StrAssign ����...\n");
    {
        printf("Ϊ˳�� S ��ֵ...\n");
        StrAssign(S, chars);
        printf("\n");
    }
    printf("���� StrEmpty ����...\n");
    {
        status = StrEmpty(S);
        printf("˳�� S Ϊ��=%d...\n", status);
    }
    printf("���� StrPrint ����...\n");
    {
        StrPrint(S);
        printf("\n");
    }
    printf("���� SubString ����...\n");
    {
        StrPrint(S);

        printf("\n");
    }
    return 0;
}