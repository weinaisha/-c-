#ifndef SQSTRING_C
#define SQSTRING_C

#include "SqString.h"

Status StrAssign(String S, const char *chars) {
    int i, len;
    len = strlen(chars);
    if(len > MAXSIZE) {
        return ERROR;
    } else {
        S[0] = len;
        for(int i = 1; i < len; i++) {
            S[i] = chars[i-1];
        }
    }
    return OK;
}

Status StrEmpty(String S) {
    if(strlen(S) == 0) {
        return TRUE;
    }else {
        return FALSE;
    }
}

void StrPrint(String S) {
    int i;
    for(i = 1; i <= S[0]; i++) {
        printf("%c", S[i]);
    }
}

Status SubString(String S, int pos, int len, String sub) {
    int i = 1;
    sub[0] = len;
    for(int j = pos+i; i<=len; i++ ) {
        sub[i] = S[j];
    }
    return OK;
}

#endif