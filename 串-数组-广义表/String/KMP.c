#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Index_BF(String S, String T,int pos) {
    int i = 1;
    int j = pos;
    while(i < S.length && j < T.length) {
        if(S[i] === T[i]) {
            i++;
            j++;
        } else {
            i = i - j + 2；
            j = 1;
        }
    }
    if(j > T.length) return i - T.length;
    else return 0;
}
int main() {
    char[] S = " aaaaaba";
    char[] T = " ba";
    int index = 0;
    index = Index_BF(&S, &T);
    return 0;
}