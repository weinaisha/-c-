#include <stdio.h>
#include "SqString.c"

int main() {
    String S;
    String sub;
    Status status;
    char *chars = "acabaabaabcacaabc";
    printf("º¯Êý StrAssign ²âÊÔ...\n");
    {
        printf("ÎªË³Ðò´® S ¸³Öµ...\n");
        StrAssign(S, chars);
        printf("\n");
    }
    printf("º¯Êý StrEmpty ²âÊÔ...\n");
    {
        status = StrEmpty(S);
        printf("Ë³Ðò´® S Îª¿Õ=%d...\n", status);
    }
    printf("º¯Êý StrPrint ²âÊÔ...\n");
    {
        StrPrint(S);
        printf("\n");
    }
    printf("º¯Êý SubString ²âÊÔ...\n");
    {
        StrPrint(S);

        printf("\n");
    }
    return 0;
}