#include <stdio.h>
#include <stdlib.h>

int main() {
    int kind, vexnum, *arcnum, *IncInfo;
    char buff[255];
    char StrLine[1024];
    FILE* fp = NULL;
    fp = fopen("TestData_DG.txt", "a+");
    if(fp) {
        fscanf(fp, "%d\n", &kind);
        printf("ͼ����=%d\n", kind);
        // fscanf(fp, "%d", vexnum);
        // printf("������=%d\n", vexnum);
        // fscanf(fp, "%d", arcnum);
        // printf("����%d\n", *arcnum);
        // fscanf(fp, "%d", IncInfo);
        // printf("���Ƿ����������Ϣ%d\n", *IncInfo);
    }
    fclose(fp);
    // fp = NULL;
    
    return 0;
}